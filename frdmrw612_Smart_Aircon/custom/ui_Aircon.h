/*
* Copyright 2023-2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef UI_AIRCON_H_
#define UI_AIRCON_H_

#include "gui_guider.h"


/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define FADE_ANIM_TIME			300
#define AIRCON_TEMP_MIN         16
#define AIRCON_TEMP_MAX         32
#define AIRCON_TIMERHOUR_MIN    0
#define AIRCON_TIMERHOUR_MAX    24

typedef enum
{
    kAIRCON_Off,
    kAIRCON_On,
} AIRCON_State_T;

typedef enum
{
	kAIRCON_TempDown,
	kAIRCON_TempUp,
} AIRCON_Temp_T;

typedef enum
{
	kAIRCON_TimerDown,
	kAIRCON_TimerUp,
} AIRCON_Timer_T;

typedef enum
{
	kAIRCON_FanLow,
	kAIRCON_FanMedium,
	kAIRCON_FanHigh
} AIRCON_Fan_Speed_T;

typedef enum
{
    kAIRCON_FanNone,
    kAIRCON_FanDown,
    kAIRCON_FanUp,
} AIRCON_Fan_T;

typedef enum
{
    kAIRCON_SwingOff,
    kAIRCON_SwingOn,
} AIRCON_Swing_State_T;
typedef enum
{
    kVIT_AirconIntent_Unknown,
    kVIT_AirconIntent_Power,
    kVIT_AirconIntent_FanSpeed,
    kVIT_AirconIntent_Mode,
    kVIT_AirconIntent_Temperature,
    kVIT_AirconIntent_Timer,
    kVIT_AirconIntent_TempAdjust,
    kVIT_AirconIntent_Swing,
} VIT_Aircon_Intent_t;

typedef enum
{
	kAIRCON_ModeCool,
	kAIRCON_ModeDry,
	kAIRCON_ModeFan
} AIRCON_Mode_T;

typedef struct
{
    VIT_Aircon_Intent_t intent;
    AIRCON_Mode_T airconMode;
    AIRCON_Fan_Speed_T fanSpeed;
    AIRCON_Fan_T fanUpDown;
    AIRCON_Temp_T tempUpDown;
    AIRCON_Timer_T timeUpDown;
    uint16_t temperature;
    uint16_t duration;
    bool enabled;
} VIT_Aircon_Command_t;
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

void ui_aircon_update_temp (uint32_t temp, AIRCON_Temp_T state);

void ui_aircon_update_timer (uint32_t hour, AIRCON_Timer_T state);

void ui_aricon_set_fan_speed (AIRCON_Fan_Speed_T speed);

void ui_aircon_set_mode (AIRCON_Mode_T mode);

void ui_aircon_process_command (uint16_t aircon_cmd2);

#endif /* UI_AIRCON_H_ */
