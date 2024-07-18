/*
 * Copyright 2020, 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "FreeRTOS.h"
#include "task.h"
#include "event_groups.h"

#include "fsl_debug_console.h"
#include "lvgl_support.h"
#include "board.h"
#include "app.h"

#include "fsl_inputmux.h"
#include "fsl_dma.h"
#include "fsl_gpio.h"


#include "lvgl.h"
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"
#include "ui_Aircon.h"
#include "lvgl_demo_utils.h"

#include "vit_proc.h"
#include "RGB.h"

//Includes from our end
#include "wifi_mqtt.h"
#include "lwip/tcpip.h"
#include "board.h"
#include "app.h"
#include "wpl.h"
#include "timers.h"
#include "wifi_mqtt.h"
#include "cred_flash_storage.h"

#include "fsl_debug_console.h"
#include "mqtt_freertos.h"

#include <stdio.h>


/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define AIRCON_PUBLISHER_VIT 1
/*******************************************************************************
 * Variables
 ******************************************************************************/
static volatile bool s_lvgl_initialized = false;
lv_ui guider_ui;

EventGroupHandle_t GPH_Process = NULL;
extern VIT_Aircon_Command_t aircon_cmd;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void print_cb(lv_log_level_t level, const char * buf);

#if LV_USE_LOG
void print_cb(lv_log_level_t level, const char * buf)
{
    LV_UNUSED(level);

    PRINTF("\r%s\n", buf);
}
#endif


static void Graphics_Process (void *pvParameters)
{
    EventBits_t event_bits;
    RGB_LED_Init();
    /* Startup LED animation */
    for(int i = 0; i < 5; i++)
    {
    	RGB_LED_On(kRGB_BLUE);
        vTaskDelay(pdMS_TO_TICKS(50));
        RGB_LED_Off(kRGB_BLUE);
        vTaskDelay(pdMS_TO_TICKS(50));
    }

    for(;;)
    {
        //event_bits = xEventGroupWaitBits(GPH_Process, VIT_WW_DETECT | VIT_CMD_DETECT, pdTRUE, pdFALSE, portMAX_DELAY);
    	event_bits = xEventGroupWaitBits(GPH_Process, VIT_WW_DETECT | VIT_CMD_DETECT | VIT_PUBLISH, pdTRUE, pdFALSE, portMAX_DELAY);
        /* Turn on LEDs on WW detection */
		if((event_bits & VIT_WW_DETECT) == VIT_WW_DETECT)
		{
			RGB_LED_On(kRGB_BLUE);
		}
        if(((event_bits & VIT_CMD_DETECT) == VIT_CMD_DETECT) || ((event_bits & VIT_PUBLISH) == VIT_PUBLISH))
        {
            if (s_lvgl_initialized && (lv_scr_act()== guider_ui.ui_Aircon) )
            {
                ui_aircon_process_command(get_cmd_id_value());
            }

            if(((event_bits & VIT_PUBLISH) == VIT_PUBLISH) && (WiFiConnected() && mqtt_freertos_connected()))
            {
            	char topic2[24] = {0};
            	char payload2[24] = {0};

                switch (aircon_cmd.intent)
                {
                case kVIT_AirconIntent_Power:
                	sprintf(topic2, "%s", "aircon/power");
                	sprintf(payload2, "%s", aircon_cmd.enabled?"On":"Off");
                	break;
                case kVIT_AirconIntent_Temperature:
                	sprintf(topic2, "%s", "aircon/temperature");
                    switch (aircon_cmd.tempUpDown)
                    {
                    case kAIRCON_TempDown:
                    	sprintf(payload2, "%s", "Down");
                        break;
                    case kAIRCON_TempUp:
                    	sprintf(payload2, "%s", "Up");
                    	break;
                    }
                    break;
                case kVIT_AirconIntent_FanSpeed:
                	sprintf(topic2, "%s", "aircon/fan_speed");
                    switch (aircon_cmd.fanSpeed)
                    {
                    case kAIRCON_FanLow:
                    	sprintf(payload2, "%s" "Low");
                        break;
                    case kAIRCON_FanMedium:
                    	sprintf(payload2, "%s", "Medium");
                        break;
                    case kAIRCON_FanHigh:
                    	sprintf(payload2, "%s", "High");
                        break;
                    }
                    break;
                case kVIT_AirconIntent_Mode:
                	sprintf(topic2, "%s", "aircon/mode");
                    switch (aircon_cmd.airconMode)
                    {
                    case kAIRCON_ModeCool:
                        sprintf(payload2, "%s", "Cool");
                        break;
                    case kAIRCON_ModeDry:
                    	sprintf(payload2, "%s", "Dry");
                        break;
                    default:
                        break;
                    }
                    break;
				case kVIT_AirconIntent_Swing:
					sprintf(topic2, "%s", "aircon/swing");
					sprintf(payload2, "%s", aircon_cmd.enabled?"On":"Off");
                break;
                case kVIT_AirconIntent_Timer:
                	sprintf(topic2, "%s", "aircon/timer");
                    switch (aircon_cmd.timeUpDown)
                    {
                    case kAIRCON_TimerUp:
                        sprintf(payload2, "%s", "Up");
                        break;
                    case kAIRCON_TimerDown:
                        sprintf(payload2, "%s", "Down");
                        break;
                    default:
                        break;
                    }
                    break;
                 case kVIT_AirconIntent_Unknown:
                    break;
                 default:
                	break;
                }

                mqtt_freertos_publish(topic2, payload2, strlen(payload2), 1, 0);
            }

//            if ( (WiFiConnected() && mqtt_freertos_connected()) && (get_ext_cmd_flag() == 1) && (lv_scr_act()== guider_ui.ui_Aircon) && (Get_Mic_status()!= true) )
//            {
//                switch (aircon_cmd.intent)
//                {
//                case kVIT_AirconIntent_Power:
//                	if(aircon_cmd.enabled==true)
//                	{
//                    	ui_aircon_process_command(POWER_ON_CMD);
//                	}
//                	else{
//                		ui_aircon_process_command(POWER_OFF_CMD);
//                	}
//                    break;
//                case kVIT_AirconIntent_Temperature:
//                    switch (aircon_cmd.tempUpDown)
//                    {
//                    case kAIRCON_TempDown:
//                    	ui_aircon_process_command(COOL_DOWN);
//                        break;
//                    case kAIRCON_TempUp:
//                    	ui_aircon_process_command(HEAT_UP);
//                        break;
//                    }
//                    break;
//                case kVIT_AirconIntent_FanSpeed:
//                    switch (aircon_cmd.fanSpeed)
//                    {
//                    case kAIRCON_FanLow:
//                    	ui_aircon_process_command(SPEED_LOW);
//                        break;
//                    case kAIRCON_FanMedium:
//                    	ui_aircon_process_command(SPEED_MEDIUM);
//                        break;
//                    case kAIRCON_FanHigh:
//                    	ui_aircon_process_command(SPEED_HIGH);
//                        break;
//                    }
//                    break;
//                case kVIT_AirconIntent_Mode:
//                    switch (aircon_cmd.airconMode)
//                    {
//                    case kAIRCON_ModeCool:
//                    	ui_aircon_process_command(COOL_MODE);
//                    	break;
//                    case kAIRCON_ModeDry:
//                    	ui_aircon_process_command(DRY_MODE);
//                    	break;
//                    default:
//                    	break;
//                    }
//                    break;
//                case kVIT_AirconIntent_Timer:
//                    switch (aircon_cmd.timeUpDown)
//                    {
//                    case kAIRCON_TimerUp:
//                    	ui_aircon_process_command(HALF_HOUR_TIMER);
//                    	break;
//                    case kAIRCON_TimerDown:
//                    	ui_aircon_process_command(QUARTER_HOUR_TIMER);
//                    	break;
//                    default:
//                    	break;
//                    }
//                    break;
//                case kVIT_AirconIntent_Unknown:
//                	break;
//
//                default:
//                	break;
//                }
//
//            }

            //clear_ext_cmd_flag();

            /* Turn off LEDs on command detection */
			RGB_LED_Off(kRGB_BLUE);
        }
        clear_ext_cmd_flag();
    }
}


static void Lvgl_Task(void *param)
{
    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();

#if LV_USE_LOG
    lv_log_register_print_cb(print_cb);
#endif

    LV_LOG("lvgl guider demo started\r\n");

    s_lvgl_initialized = true;

    setup_ui(&guider_ui);
    events_init(&guider_ui);
    custom_init(&guider_ui);

    for (;;)
    {
        vTaskDelay(lv_timer_handler());
    }
}

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Main function
 */
int main(void)
{
    BaseType_t stat;

    /* Init board hardware. */
    BOARD_InitHardware();
    init_flash_storage(CONNECTION_INFO_FILENAME);
    DEMO_InitUsTimer();

    /* Use 16 MHz clock for the FLEXCOMM2 */
	CLOCK_AttachClk(kSFRO_to_FLEXCOMM2);

	/* LCDIC clock. */
	CLOCK_AttachClk(kMAIN_CLK_to_LCD_CLK);
	/* 260 MHz divided by 9 = ~28.8 MHz*/
	CLOCK_SetClkDiv(kCLOCK_DivLcdClk, 9);
	RESET_PeripheralReset(kLCDIC_RST_SHIFT_RSTn); //kDMIC_RST_SHIFT_RSTn


	/* DMIC source from audio pll, divider 12, 12.288M/12=1.024MHZ */
	CLOCK_AttachClk(kAUDIO_PLL_to_DMIC_CLK);
	CLOCK_SetClkDiv(kCLOCK_DivDmicClk, 12);

	/* DMA */
	DMA_Init(DMA0);
	NVIC_SetPriority(DMA0_IRQn, 3);
	/* inputmux */
	INPUTMUX_Init(INPUTMUX);
	RESET_PeripheralReset(kINPUTMUX_RST_SHIFT_RSTn);

	PRINTF("\r\n");
	PRINTF("****************************************\r\n");
	PRINTF("**      RW612 Smart AirCon Demo       **\r\n");
	PRINTF("****************************************\r\n");
	PRINTF("\r\n");

	GPH_Process = xEventGroupCreate();

	stat = xTaskCreate(Lvgl_Task, "Lvgl_Task", configMINIMAL_STACK_SIZE + 800, NULL, configMAX_PRIORITIES - 6, NULL);

	if (pdPASS != stat)
	{
		PRINTF("Failed to create lvgl task");
		while (1)
			;
	}
#if AIRCON_PUBLISHER_VIT
	if (xTaskCreate(VIT_Task, "VIT_Task", 200 + 1024, NULL, configMAX_PRIORITIES - 4, NULL) !=
			pdPASS)
	{
		PRINTF("\r\nFailed to create VIT task\r\n");
		while (1)
			;
	}
#endif

	if (xTaskCreate(Graphics_Process, "Graphics_Process", configMINIMAL_STACK_SIZE + 600, NULL, configMAX_PRIORITIES - 5, NULL) !=
			pdPASS)
	{
		PRINTF("\r\nFailed to create application task\r\n");
		while (1)
			;
	}

	mqqt_principal_function();

    vTaskStartScheduler();

    for (;;)
    {
    } /* should never get here */
}

/*!
 * @brief Malloc failed hook.
 */
void vApplicationMallocFailedHook(void)
{
    PRINTF("Malloc failed. Increase the heap size.");

    for (;;)
        ;
}

/*!
 * @brief FreeRTOS tick hook.
 */
void vApplicationTickHook(void)
{
    if (s_lvgl_initialized)
    {
        lv_tick_inc(1);
    }
}

/*!
 * @brief Stack overflow hook.
 */
void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName)
{
    (void)pcTaskName;
    (void)xTask;

    for (;;)
        ;
}
