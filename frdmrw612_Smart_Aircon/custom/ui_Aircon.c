/*
* Copyright 2023-2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include <ui_Aircon.h>
#include "gui_guider.h"
#include "fsl_debug_console.h"
#include "vit_proc.h"
#include "ui_Animations.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
uint32_t AirconTemp = 25;
uint32_t TimerHour = 0;
int32_t TimerMin = 15;
AIRCON_State_T aircon_state = kAIRCON_On;
AIRCON_Swing_State_T swing_state = kAIRCON_SwingOn;
AIRCON_Mode_T aircon_mode = kAIRCON_ModeCool;
extern VIT_Aircon_Command_t aircon_cmd;

/*******************************************************************************
 * Function
 ******************************************************************************/

void ui_aircon_update_temp (uint32_t temp, AIRCON_Temp_T state)
{
	if(temp)
	{
		AirconTemp = temp;
	}
	else
	{
		switch (state)
		{
		case kAIRCON_TempDown:
			AirconTemp--;
			if(AirconTemp < AIRCON_TEMP_MIN)
			{
				AirconTemp = AIRCON_TEMP_MIN;
			}
			break;
		case kAIRCON_TempUp:
			AirconTemp++;
			if(AirconTemp > AIRCON_TEMP_MAX)
			{
				AirconTemp = AIRCON_TEMP_MAX;
			}
			break;
		}
	}
	lv_label_set_text_fmt(guider_ui.ui_Aircon_Label_Temp, "%02"LV_PRIu32, AirconTemp);

}

void ui_aircon_update_timer (uint32_t hour,  AIRCON_Timer_T state)
{
	if(hour)
	{
		TimerMin = hour;
	}
	else
	{
		switch (state)
		{
		case kAIRCON_TimerDown:
			if(TimerHour <= AIRCON_TIMERHOUR_MIN)
			{
				TimerMin = 0;
			} else {
				TimerMin-=15;
			}
			break;
		case kAIRCON_TimerUp:
			if(TimerHour >= AIRCON_TIMERHOUR_MAX)
			{
				TimerMin = 0;
			} else {
				TimerMin+=15;
			}
			break;
		}
	}

	if(TimerMin < 0)
	{
		TimerMin = 45;
		TimerHour--;
		if(TimerHour < AIRCON_TIMERHOUR_MIN)
		{
			TimerHour = AIRCON_TIMERHOUR_MIN;
		}
	}
	else if (TimerMin == 60)
	{
		TimerMin = 0;
		TimerHour++;
		if(TimerHour > AIRCON_TIMERHOUR_MAX)
		{
			TimerHour = AIRCON_TIMERHOUR_MAX;
		}
	}

	lv_label_set_text_fmt(guider_ui.ui_Aircon_Label_TimerHour, "%02"LV_PRIu32, TimerHour);
	lv_label_set_text_fmt(guider_ui.ui_Aircon_Label_TimerMin, "%02"LV_PRId32, TimerMin);
}

void ui_aricon_set_fan_speed (AIRCON_Fan_Speed_T speed)
{
	uint32_t frame_time = 150;

	switch(speed)
	{
	case kAIRCON_FanLow:
		frame_time = 225;
		lv_label_set_text(guider_ui.ui_Aircon_Label_FanSt, "LOW");
		lv_img_set_src(guider_ui.ui_Aircon_Img_FanSt, &_icn_fan_low_RGB565A8_20x20);
		break;
	case kAIRCON_FanMedium:
		frame_time = 150;
		lv_label_set_text(guider_ui.ui_Aircon_Label_FanSt, "MEDIUM");
		lv_img_set_src(guider_ui.ui_Aircon_Img_FanSt, &_icn_fan_low_RGB565A8_20x20);
		break;
	case kAIRCON_FanHigh:
		frame_time = 75;
		lv_label_set_text(guider_ui.ui_Aircon_Label_FanSt, "HIGH");
		lv_img_set_src(guider_ui.ui_Aircon_Img_FanSt, &_icn_fan_high_RGB565A8_20x20);
		break;
	}

	lv_animimg_delete(guider_ui.ui_Aircon_Aimg_Fan);
	lv_animimg_set_duration(guider_ui.ui_Aircon_Aimg_Fan, frame_time * 6);
	lv_animimg_start(guider_ui.ui_Aircon_Aimg_Fan);

}

void ui_aircon_set_mode (AIRCON_Mode_T mode)
{
	switch(mode)
	{
	case kAIRCON_ModeCool:
		lv_label_set_text(guider_ui.ui_Aircon_Label_CompSt, "ON");
		lv_img_set_src(guider_ui.ui_Aircon_Img_CompSt, &_icn_cool_RGB565A8_20x20);
		lv_obj_fade_in(guider_ui.ui_Aircon_Aimg_Cool, FADE_ANIM_TIME, 0);
		break;
	case kAIRCON_ModeDry:
		lv_label_set_text(guider_ui.ui_Aircon_Label_CompSt, "ON");
		lv_img_set_src(guider_ui.ui_Aircon_Img_CompSt, &_icn_dry_RGB565A8_20x20);
		lv_obj_fade_in(guider_ui.ui_Aircon_Aimg_Cool, FADE_ANIM_TIME, 0);
		break;
	case kAIRCON_ModeFan:
		lv_label_set_text(guider_ui.ui_Aircon_Label_CompSt, "OFF");
		lv_img_set_src(guider_ui.ui_Aircon_Img_CompSt, &_icn_fan_low_RGB565A8_20x20);
		lv_obj_fade_out(guider_ui.ui_Aircon_Aimg_Cool, FADE_ANIM_TIME, 0);
		break;
	}

}

void ui_aircon_process_command (uint16_t aircon_cmd2)
{

    switch (aircon_cmd2)
    {
		case POWER_ON_CMD:
			lv_obj_set_state(guider_ui.ui_Aircon_Btn_Power, LV_STATE_CHECKED, true);
			lv_obj_add_flag(guider_ui.ui_Aircon_Label_Mask, LV_OBJ_FLAG_HIDDEN);
			ui_aircon_swing_anim(true, false);
			lv_obj_fade_in(guider_ui.ui_Aircon_Aimg_Fan, 300, 0);
			if (lv_roller_get_selected(guider_ui.ui_Aircon_Roller_Mode) != 2) {
				lv_obj_fade_in(guider_ui.ui_Aircon_Aimg_Cool, 300, 0);
			}
			aircon_cmd.intent = kVIT_AirconIntent_Power;
			aircon_cmd.enabled = true;
			PRINTF("POWER: %d ", aircon_cmd2);
			break;
		case POWER_OFF_CMD:
			lv_obj_set_state(guider_ui.ui_Aircon_Btn_Power, LV_STATE_CHECKED, false);

            lv_obj_remove_flag(guider_ui.ui_Aircon_Label_Mask, LV_OBJ_FLAG_HIDDEN);
            ui_aircon_swing_anim(false, true);
            lv_obj_fade_out(guider_ui.ui_Aircon_Aimg_Fan, 300, 0);
            lv_obj_fade_out(guider_ui.ui_Aircon_Aimg_Cool, 300, 0);
			if(aircon_state == kAIRCON_On)
			{

			}
			aircon_cmd.intent = kVIT_AirconIntent_Power;
			aircon_cmd.enabled = false;
			break;
		case SPEED_LOW:
			ui_aricon_set_fan_speed(kAIRCON_FanLow);
			lv_slider_set_value(guider_ui.ui_Aircon_Slider_FanMode, kAIRCON_FanLow, true);
			aircon_cmd.intent = kVIT_AirconIntent_FanSpeed;
			aircon_cmd.fanSpeed = kAIRCON_FanLow;
			break;
		case SPEED_MEDIUM:
			ui_aricon_set_fan_speed(kAIRCON_FanMedium);
			lv_slider_set_value(guider_ui.ui_Aircon_Slider_FanMode, kAIRCON_FanMedium, true);
			aircon_cmd.intent = kVIT_AirconIntent_FanSpeed;
			aircon_cmd.fanSpeed = kAIRCON_FanMedium;
			break;
		case SPEED_HIGH:
			ui_aricon_set_fan_speed(kAIRCON_FanHigh);
			lv_slider_set_value(guider_ui.ui_Aircon_Slider_FanMode, kAIRCON_FanHigh, true);
			aircon_cmd.intent = kVIT_AirconIntent_FanSpeed;
			aircon_cmd.fanSpeed = kAIRCON_FanHigh;
			break;
		case COOL_MODE:
			lv_obj_set_state(guider_ui.ui_Aircon_Roller_Mode, kAIRCON_ModeCool, true);
			lv_roller_set_selected(guider_ui.ui_Aircon_Roller_Mode, kAIRCON_ModeCool, true);
			ui_aircon_set_mode(kAIRCON_ModeCool);
			aircon_cmd.intent = kVIT_AirconIntent_Mode;
			aircon_cmd.airconMode = kAIRCON_ModeCool;
			break;
		case DRY_MODE:
			lv_obj_set_state(guider_ui.ui_Aircon_Roller_Mode, kAIRCON_ModeDry, true);
			lv_roller_set_selected(guider_ui.ui_Aircon_Roller_Mode, kAIRCON_ModeDry, true);
			ui_aircon_set_mode(kAIRCON_ModeDry);
			aircon_cmd.intent = kVIT_AirconIntent_Mode;
			aircon_cmd.airconMode = kAIRCON_ModeDry;
			break;
		case SWING_ON:
	        if (lv_obj_has_state(guider_ui.ui_Aircon_Btn_Power, LV_STATE_CHECKED)) {
				lv_obj_set_state(guider_ui.ui_Aircon_Btn_Swing, LV_STATE_CHECKED, true);
	            ui_aircon_swing_anim(false, false);
	            aircon_cmd.intent = kVIT_AirconIntent_Swing;
	            aircon_cmd.enabled = kAIRCON_SwingOn;
	        }
			break;
		case SWING_OFF:
	        if (lv_obj_has_state(guider_ui.ui_Aircon_Btn_Power, LV_STATE_CHECKED)) {
	        	lv_obj_set_state(guider_ui.ui_Aircon_Btn_Swing, LV_STATE_CHECKED, false);
	        	lv_animimg_delete(guider_ui.ui_Aircon_Aimg_Swing);
	        	aircon_cmd.intent = kVIT_AirconIntent_Swing;
				aircon_cmd.enabled = kAIRCON_SwingOff;
	        }
			break;
		case HEAT_UP:
			aircon_cmd.intent = kVIT_AirconIntent_Temperature;
			aircon_cmd.tempUpDown = kAIRCON_TempUp;
            AirconTemp += 2;
            PRINTF("TEMP + 2 \r\n");
            ui_aircon_update_temp(AirconTemp, 0);
			break;
		case COOL_DOWN:
			aircon_cmd.intent = kVIT_AirconIntent_Temperature;
			aircon_cmd.tempUpDown = kAIRCON_TempDown;
            AirconTemp -= 2;
            PRINTF("TEMP - 2 \r\n");
            ui_aircon_update_temp(AirconTemp, 0);
			break;
		case HALF_HOUR_TIMER:
			aircon_cmd.intent = kVIT_AirconIntent_Timer;
			aircon_cmd.timeUpDown = kAIRCON_TimerUp;
	        ui_aircon_update_timer(30, 0);
	        PRINTF("TIMER: %d min\r\n", 30);
			break;
		case QUARTER_HOUR_TIMER:
			aircon_cmd.intent = kVIT_AirconIntent_Timer;
			aircon_cmd.timeUpDown = kAIRCON_TimerDown;
	        ui_aircon_update_timer(15, 0);
	        PRINTF("TIMER: %d min\r\n", 15);
			break;
		default:
			break;
	}
}
