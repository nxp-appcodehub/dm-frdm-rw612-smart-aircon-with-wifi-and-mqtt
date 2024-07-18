/*
 * Copyright 2018-2022, 2025 NXP
 * 
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "FreeRTOS.h"
#include "semphr.h"

#include "board.h"
#include "fsl_cache.h"
#include "fsl_dmic.h"
#include "fsl_dmic_dma.h"
#include "fsl_debug_console.h"

#include "mic_proc.h"
#include "vit_proc.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* DMIC */
#define DEMO_DMIC_RX_CHANNEL_0      16
#define DEMO_DMIC_RX_CHANNEL_1      17
#define DEMO_DMIC_RX_CHANNEL_2      18
#define DEMO_DMIC_RX_CHANNEL_3      19
#define DEMO_DMIC_CHANNEL_0         kDMIC_Channel0
#define DEMO_DMIC_CHANNEL_1         kDMIC_Channel1
#define DEMO_DMIC_CHANNEL_2         kDMIC_Channel2
#define DEMO_DMIC_CHANNEL_3         kDMIC_Channel3
#define DEMO_DMIC_CHANNEL_0_ENABLE  DMIC_CHANEN_EN_CH0(1)
#define DEMO_DMIC_CHANNEL_1_ENABLE  DMIC_CHANEN_EN_CH1(1)
#define DEMO_DMIC_CHANNEL_2_ENABLE  DMIC_CHANEN_EN_CH2(1)
#define DEMO_DMIC_CHANNEL_3_ENABLE  DMIC_CHANEN_EN_CH3(1)
#define FIFO_DEPTH   (12U)

/* DMA */
#define DEMO_DMA                (DMA0)

/* DMA/PDM Buffers */
#define RECORD_BUFFER_SIZE          (SAMPLES_PER_FRAME * PDM_BYTE_DEPTH)
#define PLAYBACK_BUFFER_SIZE        (SAMPLES_PER_FRAME * PDM_BYTE_DEPTH * DEMO_CHANNEL_NUM)
#define PLAYBACK_BUFFER_MAX_SIZE    (SAMPLES_PER_FRAME * PDM_BYTE_DEPTH * DEMO_MAX_CHANNEL_NUM)
#define BUFFER_NUM                  (2U)
#define BUFFER_SIZE                 (PLAYBACK_BUFFER_SIZE * BUFFER_NUM)
#define BUFFER_MAX_SIZE             (PLAYBACK_BUFFER_MAX_SIZE * BUFFER_NUM)

/* 5 frames of 30ms 4ch 16bit data */
/* Record buffer is 1ch only */
/* Playback buffer is all channels interleaved */

/*******************************************************************************
 * Variables
 ******************************************************************************/
dmic_dma_handle_t ch0DmicDmaHandle;
dmic_dma_handle_t ch1DmicDmaHandle;
dmic_dma_handle_t ch2DmicDmaHandle;
dmic_dma_handle_t ch3DmicDmaHandle;
dma_handle_t ch0DmicRxDmaHandle;
dma_handle_t ch1DmicRxDmaHandle;
dma_handle_t ch2DmicRxDmaHandle;
dma_handle_t ch3DmicRxDmaHandle;

static uint16_t volatile s_readIndex = 0U;
SDK_ALIGN(static uint8_t s_buffer[BUFFER_MAX_SIZE], 16);

SDK_ALIGN(dma_descriptor_t s_ch0DmaDescriptorPingpong[2], 16);
SDK_ALIGN(dma_descriptor_t s_ch1DmaDescriptorPingpong[2], 16);
SDK_ALIGN(dma_descriptor_t s_ch2DmaDescriptorPingpong[2], 16);
SDK_ALIGN(dma_descriptor_t s_ch3DmaDescriptorPingpong[2], 16);

static dmic_transfer_t s_ch0ReceiveXfer[2U] = {
    /* transfer configurations for channel0 */
    {
        .data                   = &s_buffer[0],
        .dataWidth              = sizeof(uint16_t),
        .dataSize               = RECORD_BUFFER_SIZE,
        .dataAddrInterleaveSize = kDMA_AddressInterleave4xWidth,
        .linkTransfer           = &s_ch0ReceiveXfer[1],
    },

    {
        .data                   = &s_buffer[PLAYBACK_BUFFER_SIZE + 0U],
        .dataWidth              = sizeof(uint16_t),
        .dataSize               = RECORD_BUFFER_SIZE,
        .dataAddrInterleaveSize = kDMA_AddressInterleave4xWidth,
        .linkTransfer           = &s_ch0ReceiveXfer[0],
    },
};

static dmic_transfer_t s_ch1ReceiveXfer[2U] = {
    /* transfer configurations for channel1 */
    {
        .data                   = &s_buffer[2],
        .dataWidth              = sizeof(uint16_t),
        .dataSize               = RECORD_BUFFER_SIZE,
        .dataAddrInterleaveSize = kDMA_AddressInterleave4xWidth,
        .linkTransfer           = &s_ch1ReceiveXfer[1],
    },

    {
        .data                   = &s_buffer[PLAYBACK_BUFFER_SIZE + 2U],
        .dataWidth              = sizeof(uint16_t),
        .dataSize               = RECORD_BUFFER_SIZE,
        .dataAddrInterleaveSize = kDMA_AddressInterleave4xWidth,
        .linkTransfer           = &s_ch1ReceiveXfer[0],
    },
};

static dmic_transfer_t s_ch2ReceiveXfer[2U] = {
    /* transfer configurations for channel2 */
    {
        .data                   = &s_buffer[4],
        .dataWidth              = sizeof(uint16_t),
        .dataSize               = RECORD_BUFFER_SIZE,
        .dataAddrInterleaveSize = kDMA_AddressInterleave4xWidth,
        .linkTransfer           = &s_ch2ReceiveXfer[1],
    },

    {
        .data                   = &s_buffer[PLAYBACK_BUFFER_SIZE + 4U],
        .dataWidth              = sizeof(uint16_t),
        .dataSize               = RECORD_BUFFER_SIZE,
        .dataAddrInterleaveSize = kDMA_AddressInterleave4xWidth,
        .linkTransfer           = &s_ch2ReceiveXfer[0],
    },
};

static dmic_transfer_t s_ch3ReceiveXfer[2U] = {
    /* transfer configurations for channel3 */
    {
        .data                   = &s_buffer[6],
        .dataWidth              = sizeof(uint16_t),
        .dataSize               = RECORD_BUFFER_SIZE,
        .dataAddrInterleaveSize = kDMA_AddressInterleave4xWidth,
        .linkTransfer           = &s_ch3ReceiveXfer[1],
    },

    {
        .data                   = &s_buffer[PLAYBACK_BUFFER_SIZE + 6U],
        .dataWidth              = sizeof(uint16_t),
        .dataSize               = RECORD_BUFFER_SIZE,
        .dataAddrInterleaveSize = kDMA_AddressInterleave4xWidth,
        .linkTransfer           = &s_ch3ReceiveXfer[0],
    },
};

static SemaphoreHandle_t semaphoreRX;
static bool mic_over_flow_flag = false;

static void RxCallback(DMIC_Type *base, dmic_dma_handle_t *handle, status_t status, void *userData)
{
    BaseType_t reschedule = -1;
    if (pdFALSE == xSemaphoreGiveFromISR(semaphoreRX, &reschedule))
    {
        /* Semaphore full, move read index */
        mic_over_flow_flag = true;
        s_readIndex += PLAYBACK_BUFFER_SIZE;
        if (s_readIndex >= BUFFER_SIZE)
            s_readIndex -= BUFFER_SIZE;
    }
    portYIELD_FROM_ISR(reschedule);
}

void MIC_Init(void)
{
    dmic_channel_config_t dmic_channel_cfg;
    DMA_Init(DEMO_DMA);

    DMA_EnableChannel(DEMO_DMA, DEMO_DMIC_RX_CHANNEL_0);
    DMA_SetChannelPriority(DEMO_DMA, DEMO_DMIC_RX_CHANNEL_0, kDMA_ChannelPriority2);
    DMA_CreateHandle(&ch0DmicRxDmaHandle, DEMO_DMA, DEMO_DMIC_RX_CHANNEL_0);

    DMA_EnableChannel(DEMO_DMA, DEMO_DMIC_RX_CHANNEL_1);
    DMA_SetChannelPriority(DEMO_DMA, DEMO_DMIC_RX_CHANNEL_1, kDMA_ChannelPriority2);
    DMA_CreateHandle(&ch1DmicRxDmaHandle, DEMO_DMA, DEMO_DMIC_RX_CHANNEL_1);

    DMA_EnableChannel(DEMO_DMA, DEMO_DMIC_RX_CHANNEL_2);
    DMA_SetChannelPriority(DEMO_DMA, DEMO_DMIC_RX_CHANNEL_2, kDMA_ChannelPriority2);
    DMA_CreateHandle(&ch2DmicRxDmaHandle, DEMO_DMA, DEMO_DMIC_RX_CHANNEL_2);

    DMA_EnableChannel(DEMO_DMA, DEMO_DMIC_RX_CHANNEL_3);
    DMA_SetChannelPriority(DEMO_DMA, DEMO_DMIC_RX_CHANNEL_3, kDMA_ChannelPriority2);
    DMA_CreateHandle(&ch3DmicRxDmaHandle, DEMO_DMA, DEMO_DMIC_RX_CHANNEL_3);

    memset(&dmic_channel_cfg, 0U, sizeof(dmic_channel_config_t));

    dmic_channel_cfg.divhfclk            = kDMIC_PdmDiv1;
    dmic_channel_cfg.osr                 = 32U;
    dmic_channel_cfg.gainshft            = 6U;
    dmic_channel_cfg.preac2coef          = kDMIC_CompValueZero;
    dmic_channel_cfg.preac4coef          = kDMIC_CompValueZero;
    dmic_channel_cfg.dc_cut_level        = kDMIC_DcCut155;
    dmic_channel_cfg.post_dc_gain_reduce = 8U;
    dmic_channel_cfg.saturate16bit       = 1U;
    dmic_channel_cfg.sample_rate         = kDMIC_PhyFullSpeed;
    DMIC_Init(DMIC0); // this line was missing which probably was the reason for the example no working
    RESET_PeripheralReset(kDMIC_RST_SHIFT_RSTn); //kDMIC_RST_SHIFT_RSTn
    DMIC_Use2fs(DMIC0, true);

    DMIC_EnableChannelDma(DMIC0, DEMO_DMIC_CHANNEL_0, true);
    DMIC_ConfigChannel(DMIC0, DEMO_DMIC_CHANNEL_0, kDMIC_Left, &dmic_channel_cfg);
    DMIC_FifoChannel(DMIC0, DEMO_DMIC_CHANNEL_0, FIFO_DEPTH, true, true);

    DMIC_EnableChannelDma(DMIC0, DEMO_DMIC_CHANNEL_1, true);
    DMIC_ConfigChannel(DMIC0, DEMO_DMIC_CHANNEL_1, kDMIC_Right, &dmic_channel_cfg);
    DMIC_FifoChannel(DMIC0, DEMO_DMIC_CHANNEL_1, FIFO_DEPTH, true, true);

    DMIC_EnableChannelDma(DMIC0, DEMO_DMIC_CHANNEL_2, true);
    DMIC_ConfigChannel(DMIC0, DEMO_DMIC_CHANNEL_2, kDMIC_Left, &dmic_channel_cfg);
    DMIC_FifoChannel(DMIC0, DEMO_DMIC_CHANNEL_2, FIFO_DEPTH, true, true);

    DMIC_EnableChannelDma(DMIC0, DEMO_DMIC_CHANNEL_3, true);
    DMIC_ConfigChannel(DMIC0, DEMO_DMIC_CHANNEL_3, kDMIC_Right, &dmic_channel_cfg);
    DMIC_FifoChannel(DMIC0, DEMO_DMIC_CHANNEL_3, FIFO_DEPTH, true, true);

    DMIC_EnableChannnel(DMIC0, DEMO_DMIC_CHANNEL_0_ENABLE | DEMO_DMIC_CHANNEL_1_ENABLE | DEMO_DMIC_CHANNEL_2_ENABLE | DEMO_DMIC_CHANNEL_3_ENABLE);

    DMIC_TransferCreateHandleDMA(DMIC0, &ch0DmicDmaHandle, NULL, NULL, &ch0DmicRxDmaHandle);
    DMIC_InstallDMADescriptorMemory(&ch0DmicDmaHandle, s_ch0DmaDescriptorPingpong, BUFFER_NUM);

    DMIC_TransferCreateHandleDMA(DMIC0, &ch1DmicDmaHandle, NULL, NULL, &ch1DmicRxDmaHandle);
    DMIC_InstallDMADescriptorMemory(&ch1DmicDmaHandle, s_ch1DmaDescriptorPingpong, BUFFER_NUM);

    DMIC_TransferCreateHandleDMA(DMIC0, &ch2DmicDmaHandle, NULL, NULL, &ch2DmicRxDmaHandle);
    DMIC_InstallDMADescriptorMemory(&ch2DmicDmaHandle, s_ch2DmaDescriptorPingpong, BUFFER_NUM);

    DMIC_TransferCreateHandleDMA(DMIC0, &ch3DmicDmaHandle, RxCallback, NULL, &ch3DmicRxDmaHandle);
    DMIC_InstallDMADescriptorMemory(&ch3DmicDmaHandle, s_ch3DmaDescriptorPingpong, BUFFER_NUM);


    /* Wait for mic to stabilize */
    vTaskDelay(pdMS_TO_TICKS(500));


    /* Create semaphore for each buffer, except one that will always be filling by DMA */
    semaphoreRX = xSemaphoreCreateCounting(BUFFER_NUM - 1, 0);
}

void MIC_Start()
{
    /* Clear old samples from FIFOs */
    DMIC_DoFifoReset(DMIC0, DEMO_DMIC_CHANNEL_0);
    DMIC_DoFifoReset(DMIC0, DEMO_DMIC_CHANNEL_1);
    DMIC_DoFifoReset(DMIC0, DEMO_DMIC_CHANNEL_2);
    DMIC_DoFifoReset(DMIC0, DEMO_DMIC_CHANNEL_3);

    /* Start the DMIC transfer */
    DMIC_TransferReceiveDMA(DMIC0, &ch0DmicDmaHandle, s_ch0ReceiveXfer, DEMO_DMIC_CHANNEL_0);
    DMIC_TransferReceiveDMA(DMIC0, &ch1DmicDmaHandle, s_ch1ReceiveXfer, DEMO_DMIC_CHANNEL_1);
    DMIC_TransferReceiveDMA(DMIC0, &ch2DmicDmaHandle, s_ch2ReceiveXfer, DEMO_DMIC_CHANNEL_2);
    DMIC_TransferReceiveDMA(DMIC0, &ch3DmicDmaHandle, s_ch3ReceiveXfer, DEMO_DMIC_CHANNEL_3);
}

void MIC_Close()
{
    /* Abort the DMIC transfer */
    DMIC_TransferAbortReceiveDMA(DMIC0, &ch0DmicDmaHandle);
    DMIC_TransferAbortReceiveDMA(DMIC0, &ch1DmicDmaHandle);
    DMIC_TransferAbortReceiveDMA(DMIC0, &ch2DmicDmaHandle);
    DMIC_TransferAbortReceiveDMA(DMIC0, &ch3DmicDmaHandle);
    vSemaphoreDelete(semaphoreRX);
}

int MIC_Read(uint8_t *data, uint32_t size)
{
    /* Wait 100ms for the previous transfer to finish */
    if (xSemaphoreTake(semaphoreRX, pdMS_TO_TICKS(100)) != pdTRUE)
        return -1;
    /* Copy data from the DMIC buffer */
    memcpy(data, &s_buffer[s_readIndex], size);
    s_readIndex += size;
    if (s_readIndex >= BUFFER_SIZE)
        s_readIndex -= BUFFER_SIZE;

    return 0;
}

int MIC_GetStatus()
{
    int status = mic_over_flow_flag;
    mic_over_flow_flag = false;
    return status;
}
