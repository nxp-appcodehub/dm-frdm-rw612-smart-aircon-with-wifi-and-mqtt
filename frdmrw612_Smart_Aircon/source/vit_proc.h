/*
 * Copyright 2020, 2025 NXP
 * 
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _VIT_PROC_H_
#define _VIT_PROC_H_

#include "mic_proc.h"
#include "PL_platformTypes_CortexM.h"
#include "VIT.h"
#include "stdbool.h"

#define VIT_WW_DETECT       (1 << 0)
#define VIT_CMD_DETECT      (1 << 1)
#define VIT_PUBLISH	        (1 << 2)

#define DEMO_FRAME_MS       (30)    // Only 10 or 30 ms supported by VIT
#define SAMPLES_PER_FRAME   (VIT_SAMPLE_RATE * DEMO_FRAME_MS / 1000U)

#define AFE_VOICESEEKER

/* 1: Use mic distances of 4MicA config of 8CH-DMIC board  */
/* 0: Use mic distances of 2 on-board DMICs of RD-RW61X IPA-2A/V2 */
#define MIC_4CH_CONFIG              1

#ifdef AFE_VOICESEEKER
#define VOICESEEKER_ENABLE          1
#if MIC_4CH_CONFIG
#define NUMBER_OF_CHANNELS          4
#else
#define NUMBER_OF_CHANNELS          2
#endif
#else
#define NUMBER_OF_CHANNELS          1
#endif


#define VIT_CMD_0		0
#define VIT_CMD_1		1
#define VIT_CMD_2		2
#define VIT_CMD_3		3
#define VIT_CMD_4		4
#define VIT_CMD_5		5
#define VIT_CMD_6		6
#define VIT_CMD_7		7
#define VIT_CMD_8		8
#define VIT_CMD_9		9
#define VIT_CMD_10		10
#define VIT_CMD_11		11
#define VIT_CMD_12		12
#define VIT_CMD_13		13
#define VIT_CMD_14		14
#define VIT_CMD_15		15

#define UNKNOWN_CMD				VIT_CMD_0
#define POWER_ON_CMD			VIT_CMD_1
#define POWER_OFF_CMD			VIT_CMD_2
#define	SPEED_LOW				VIT_CMD_3
#define	SPEED_MEDIUM			VIT_CMD_4
#define	SPEED_HIGH				VIT_CMD_5
#define	COOL_MODE				VIT_CMD_6
#define	DRY_MODE				VIT_CMD_7
#define	SWING_ON				VIT_CMD_8
#define	SWING_OFF				VIT_CMD_9
#define	HEAT_UP					VIT_CMD_10
#define COOL_DOWN				VIT_CMD_11
#define	HALF_HOUR_TIMER			VIT_CMD_12
#define QUARTER_HOUR_TIMER		VIT_CMD_13




typedef int (*VIT_Initialize_T)(void *arg);
typedef int (*VIT_Execute_T)(void *arg, void *inputBuffer, int size);
typedef int (*VIT_Deinit_T)(void);

extern VIT_Initialize_T VIT_Initialize_func;
extern VIT_Execute_T VIT_Execute_func;
extern VIT_Deinit_T VIT_Deinit_func;

uint16_t get_cmd_id_value(void);

void set_cmd_id_value(uint16_t val);

void VIT_Task(void *pvParameters);

bool Get_Mic_status(void);

#endif
