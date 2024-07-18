/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif

#include "ui_Aircon.h"
#include "custom.h"
#include "ui_Animations.h"
#include "wifi_mqtt.h"
#include "mqtt_freertos.h"
#include "wpl.h"
#include "cred_flash_storage.h"
#include "vit_proc.h"

char * text_ui_Settings_ta_Network = NULL;
char * text_ui_Settings_ta_Password = NULL;
char * text_ui_Settings_ta_URL = NULL;
char * text_ui_Settings_ta_User = NULL;
char * text_ui_Settings_ta_C_Password = NULL;

static void ui_Aircon_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        lv_obj_remove_flag(guider_ui.ui_Aircon_cont_panel, LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_set_style_clip_corner(guider_ui.ui_Aircon_cont_panel, true, LV_PART_MAIN);
        lv_obj_set_style_opa(guider_ui.ui_Aircon_Aimg_Fan, LV_OPA_TRANSP, 0);
        lv_obj_set_style_opa(guider_ui.ui_Aircon_Aimg_Cool, LV_OPA_TRANSP, 0);
        break;
    }
    default:
        break;
    }
}

static void ui_Aircon_Btn_TempUp_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_aircon_update_temp(0, kAIRCON_TempUp);
        break;
    }
    default:
        break;
    }
}

static void ui_Aircon_Btn_TempDown_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_aircon_update_temp(0, kAIRCON_TempDown);
        break;
    }
    default:
        break;
    }
}

static void ui_Aircon_Btn_timerUp_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_aircon_update_timer(0,kAIRCON_TimerUp);
        break;
    }
    default:
        break;
    }
}

static void ui_Aircon_Btn_timerDown_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_aircon_update_timer(0,kAIRCON_TimerDown);
        break;
    }
    default:
        break;
    }
}

static void ui_Aircon_Roller_Mode_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        lv_obj_t * obj = lv_event_get_target(e);
        ui_aircon_set_mode(lv_roller_get_selected(obj));
        break;
    }
    default:
        break;
    }
}

static void ui_Aircon_Btn_Swing_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        if (lv_obj_has_state(guider_ui.ui_Aircon_Btn_Swing, LV_STATE_CHECKED)) {
            ui_aircon_swing_anim(false, false);
        } else {
            lv_animimg_delete(guider_ui.ui_Aircon_Aimg_Swing);
        }
        break;
    }
    default:
        break;
    }
}

static void ui_Aircon_Slider_FanMode_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        ui_aricon_set_fan_speed(lv_slider_get_value(guider_ui.ui_Aircon_Slider_FanMode));
        break;
    }
    default:
        break;
    }
}

static void ui_Aircon_Btn_Power_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        if (lv_obj_has_state(guider_ui.ui_Aircon_Btn_Power, LV_STATE_CHECKED)) {
            lv_obj_add_flag(guider_ui.ui_Aircon_Label_Mask, LV_OBJ_FLAG_HIDDEN);
            ui_aircon_swing_anim(true, false);
            lv_obj_fade_in(guider_ui.ui_Aircon_Aimg_Fan, 300, 0);
            if (lv_roller_get_selected(guider_ui.ui_Aircon_Roller_Mode) != 2) {
                lv_obj_fade_in(guider_ui.ui_Aircon_Aimg_Cool, 300, 0);
            }
        } else {
            lv_obj_remove_flag(guider_ui.ui_Aircon_Label_Mask, LV_OBJ_FLAG_HIDDEN);
            ui_aircon_swing_anim(false, true);
            lv_obj_fade_out(guider_ui.ui_Aircon_Aimg_Fan, 300, 0);
            lv_obj_fade_out(guider_ui.ui_Aircon_Aimg_Cool, 300, 0);
        }
        break;
    }
    default:
        break;
    }
}

static void ui_Aircon_btn_help_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        lv_obj_remove_flag(guider_ui.ui_Aircon_msgbox_help, LV_OBJ_FLAG_HIDDEN);
        lv_obj_remove_flag(guider_ui.ui_Aircon_btn_close_help, LV_OBJ_FLAG_HIDDEN);
        break;
    }
    default:
        break;
    }
}

static void ui_Aircon_btn_close_help_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        lv_obj_add_flag(guider_ui.ui_Aircon_btn_close_help, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.ui_Aircon_msgbox_help, LV_OBJ_FLAG_HIDDEN);
        break;
    }
    default:
        break;
    }
}

static void ui_Aircon_Btn_Settings_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    int32_t result;
    char *ssids = NULL;
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.ui_Settings, guider_ui.ui_Settings_del, &guider_ui.ui_Aircon_del, setup_scr_ui_Settings, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        char ssid[MAX_SSID_LENGTH];
        char password[WPL_WIFI_PASSWORD_LENGTH];
        char broker[WIFI_SECURITY_LENGTH];
        result = get_saved_wifi_credentials(CONNECTION_INFO_FILENAME, ssid, password, broker);

        if (result == 0 && strcmp(ssid, "") != 0)
        {
        	lv_textarea_set_text(guider_ui.ui_Settings_ta_Network, ssid);
        	lv_textarea_set_text(guider_ui.ui_Settings_ta_Password, password);
        	lv_textarea_set_text(guider_ui.ui_Settings_ta_URL, broker);

        }
        else
        {
            /* No credentials are stored, the board will start its own AP */
            WC_DEBUG("[i] Nothing stored yet\r\n");
            PRINTF("\r\nScanning WiFi networks...\r\n");
            ssids = WPL_Scan();
            /* Clean up */
            vPortFree(ssids);
            strncpy(ssid, AP_SSID, MAX_SSID_LENGTH);
            ssid[MAX_SSID_LENGTH - 1] = '\0'; // Ensure null termination
            strncpy(password, AP_PASSWORD, WPL_WIFI_PASSWORD_LENGTH);
            password[WPL_WIFI_PASSWORD_LENGTH - 1] = '\0'; // Ensure null termination
        }
        break;
    }
    default:
        break;
    }
}

void events_init_ui_Aircon (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->ui_Aircon, ui_Aircon_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->ui_Aircon_Btn_TempUp, ui_Aircon_Btn_TempUp_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->ui_Aircon_Btn_TempDown, ui_Aircon_Btn_TempDown_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->ui_Aircon_Btn_timerUp, ui_Aircon_Btn_timerUp_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->ui_Aircon_Btn_timerDown, ui_Aircon_Btn_timerDown_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->ui_Aircon_Roller_Mode, ui_Aircon_Roller_Mode_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->ui_Aircon_Btn_Swing, ui_Aircon_Btn_Swing_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->ui_Aircon_Slider_FanMode, ui_Aircon_Slider_FanMode_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->ui_Aircon_Btn_Power, ui_Aircon_Btn_Power_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->ui_Aircon_btn_help, ui_Aircon_btn_help_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->ui_Aircon_btn_close_help, ui_Aircon_btn_close_help_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->ui_Aircon_Btn_Settings, ui_Aircon_Btn_Settings_event_handler, LV_EVENT_ALL, ui);
}

static void ui_Settings_roller_Wifi_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_LEAVE:
    {
        break;
    }
    default:
        break;
    }
}

static void ui_Settings_ta_Network_event_handler (lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_READY) {
    	text_ui_Settings_ta_Network = lv_textarea_get_text(guider_ui.ui_Settings_ta_Network);
    	if ( (text_ui_Settings_ta_Network != NULL && strlen(text_ui_Settings_ta_Network) > 0) &&
    		 (text_ui_Settings_ta_URL != NULL && strlen(text_ui_Settings_ta_URL) > 0) )
    	{
    		lv_obj_set_state(guider_ui.ui_Settings_btn_Connect, LV_STATE_CHECKED, true);
    	}
        PRINTF("Text: %s", text_ui_Settings_ta_Network);
    }
}

static void ui_Settings_ta_Password_event_handler (lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_READY) {
    	text_ui_Settings_ta_Password = lv_textarea_get_text(guider_ui.ui_Settings_ta_Password);
        PRINTF("Text: %s", text_ui_Settings_ta_Password);
    }
}

static void ui_Settings_ta_URL_event_handler (lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_READY) {
    	text_ui_Settings_ta_URL = lv_textarea_get_text(guider_ui.ui_Settings_ta_URL);
    	if ( (text_ui_Settings_ta_Network != NULL && strlen(text_ui_Settings_ta_Network) > 0) &&
    		 (text_ui_Settings_ta_URL != NULL && strlen(text_ui_Settings_ta_URL) > 0) )
    	{
    		lv_obj_set_state(guider_ui.ui_Settings_btn_Connect, LV_STATE_CHECKED, true);
    	}
        PRINTF("Text: %s", text_ui_Settings_ta_URL);
    }
}

static void ui_Settings_ta_User_event_handler (lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_READY) {
    	text_ui_Settings_ta_User = lv_textarea_get_text(guider_ui.ui_Settings_ta_User);
        PRINTF("Text: %s", text_ui_Settings_ta_User);
    }
}

static void ui_Settings_ta_C_Password_event_handler (lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_READY) {
    	text_ui_Settings_ta_C_Password = lv_textarea_get_text(guider_ui.ui_Settings_ta_C_Password);
        PRINTF("Text: %s", text_ui_Settings_ta_C_Password);
    }
}

static void ui_Settings_btn_Connect_event_handler (lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED) {
    	if ( (text_ui_Settings_ta_Network != NULL && strlen(text_ui_Settings_ta_Network) > 0) &&
    		 (text_ui_Settings_ta_URL != NULL && strlen(text_ui_Settings_ta_URL) > 0) )
    	{
    		// Remove previous network configuration (optional, if needed)
    	    WPL_Leave();
    	    WPL_RemoveNetwork(WIFI_NETWORK_LABEL);
    	    if(mqtt_freertos_connected())
    	    {
        	    disconnect_from_mqtt(NULL);
    	    }
    	    reset_saved_wifi_credentials(CONNECTION_INFO_FILENAME);
    		ConnectToManual(text_ui_Settings_ta_Network, text_ui_Settings_ta_Password, text_ui_Settings_ta_URL);
            save_wifi_credentials(CONNECTION_INFO_FILENAME, text_ui_Settings_ta_Network, text_ui_Settings_ta_Password, text_ui_Settings_ta_URL);
        }
    }
}


static void ui_Settings_btn_Scan_Wifi_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    char *ssids = NULL;
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ssids = WPL_Scan();
        /* Clean up */
        vPortFree(ssids);
        break;
    }
    default:
        break;
    }
}

static void ui_Settings_btn_Close_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
    	text_ui_Settings_ta_Network = NULL;
    	text_ui_Settings_ta_Password = NULL;
    	text_ui_Settings_ta_URL = NULL;
    	text_ui_Settings_ta_User = NULL;
    	text_ui_Settings_ta_C_Password = NULL;
    	lv_obj_set_state(guider_ui.ui_Settings_btn_Connect, LV_STATE_DEFAULT, true);
        ui_load_scr_animation(&guider_ui, &guider_ui.ui_Aircon, guider_ui.ui_Aircon_del, &guider_ui.ui_Settings_del, setup_scr_ui_Aircon, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        if(WiFiConnected())
        {
        	lv_obj_set_state(guider_ui.ui_Aircon_Btn_Wifi, LV_STATE_CHECKED, true);
        }
        if(mqtt_freertos_connected())
        {
        	lv_obj_set_state(guider_ui.ui_Aircon_Btn_Server, LV_STATE_CHECKED, true);
        }
        break;
    }
    default:
        break;
    }
}

static void ui_Settings_btn_Show_Networks_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_obj_add_flag(guider_ui.ui_Settings_ta_Network, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.ui_Settings_ta_Password, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.ui_Settings_ta_URL, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.ui_Settings_ta_User, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.ui_Settings_ta_C_Password, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.ui_Settings_label_Network, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.ui_Settings_label_Password, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.ui_Settings_label_URL, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.ui_Settings_label_User, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.ui_Settings_label_C_Pass, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.ui_Settings_btn_Connect, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.ui_Settings_btn_Show_Networks, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.ui_Settings_btn_Close, LV_OBJ_FLAG_HIDDEN);
        lv_obj_remove_flag(guider_ui.ui_Settings_btn_close_roller, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.ui_Settings_btn_Scan_Wifi, LV_OBJ_FLAG_HIDDEN);
        char combined_ssids[MAX_OUTPUT_LENGTH] = {0}; // buffer para la cadena final
    	char **ssids = Get_ssid_list();

    	for (int i = 0; i < MAX_NETWORKS; i++) {
    	    strncat(combined_ssids, ssids[i], MAX_SSID_LENGTH);
    	    strncat(combined_ssids, "\n", 2); // agrega salto de línea
    	}
    	lv_roller_set_options(guider_ui.ui_Settings_roller_Wifi, combined_ssids, LV_ROLLER_MODE_INFINITE);
        lv_obj_remove_flag(guider_ui.ui_Settings_roller_Wifi, LV_OBJ_FLAG_HIDDEN);
        break;
    }
    default:
        break;
    }
}

static void ui_Settings_btn_close_roller_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    char network[ MAX_SSID_LENGTH]={0};
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        lv_obj_remove_flag(guider_ui.ui_Settings_btn_Show_Networks, LV_OBJ_FLAG_HIDDEN);
        lv_obj_remove_flag(guider_ui.ui_Settings_ta_Network, LV_OBJ_FLAG_HIDDEN);
        lv_obj_remove_flag(guider_ui.ui_Settings_ta_Password, LV_OBJ_FLAG_HIDDEN);
        lv_obj_remove_flag(guider_ui.ui_Settings_ta_URL, LV_OBJ_FLAG_HIDDEN);
        lv_obj_remove_flag(guider_ui.ui_Settings_ta_User, LV_OBJ_FLAG_HIDDEN);
        lv_obj_remove_flag(guider_ui.ui_Settings_ta_C_Password, LV_OBJ_FLAG_HIDDEN);
        lv_obj_remove_flag(guider_ui.ui_Settings_btn_Connect, LV_OBJ_FLAG_HIDDEN);
        lv_obj_remove_flag(guider_ui.ui_Settings_btn_Scan_Wifi, LV_OBJ_FLAG_HIDDEN);
        lv_obj_remove_flag(guider_ui.ui_Settings_label_Network, LV_OBJ_FLAG_HIDDEN);
        lv_obj_remove_flag(guider_ui.ui_Settings_label_Password, LV_OBJ_FLAG_HIDDEN);
        lv_obj_remove_flag(guider_ui.ui_Settings_label_URL, LV_OBJ_FLAG_HIDDEN);
        lv_obj_remove_flag(guider_ui.ui_Settings_label_User, LV_OBJ_FLAG_HIDDEN);
        lv_obj_remove_flag(guider_ui.ui_Settings_label_C_Pass, LV_OBJ_FLAG_HIDDEN);
        lv_obj_remove_flag(guider_ui.ui_Settings_btn_Close, LV_OBJ_FLAG_HIDDEN);
        lv_roller_get_selected_str(guider_ui.ui_Settings_roller_Wifi, network, MAX_SSID_LENGTH);
    	lv_textarea_set_text(guider_ui.ui_Settings_ta_Network, network);
        lv_obj_add_flag(guider_ui.ui_Settings_roller_Wifi, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.ui_Settings_btn_close_roller, LV_OBJ_FLAG_HIDDEN);
        lv_obj_remove_flag(guider_ui.ui_Settings_btn_Close, LV_OBJ_FLAG_HIDDEN);
        break;
    }
    default:
        break;
    }
}

void events_init_ui_Settings (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->ui_Settings_roller_Wifi, ui_Settings_roller_Wifi_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->ui_Settings_btn_Scan_Wifi, ui_Settings_btn_Scan_Wifi_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->ui_Settings_btn_Close, ui_Settings_btn_Close_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->ui_Settings_btn_Connect, ui_Settings_btn_Connect_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->ui_Settings_ta_Network, ui_Settings_ta_Network_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->ui_Settings_ta_Password, ui_Settings_ta_Password_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->ui_Settings_ta_URL, ui_Settings_ta_URL_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->ui_Settings_ta_User, ui_Settings_ta_User_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->ui_Settings_ta_C_Password, ui_Settings_ta_C_Password_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->ui_Settings_btn_Show_Networks, ui_Settings_btn_Show_Networks_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->ui_Settings_btn_close_roller, ui_Settings_btn_close_roller_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
