/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"


typedef struct
{
  
	lv_obj_t *ui_Aircon;
	bool ui_Aircon_del;
	lv_obj_t *ui_Aircon_img_1;
	lv_obj_t *ui_Aircon_img_2;
	lv_obj_t *ui_Aircon_img_3;
	lv_obj_t *ui_Aircon_cont_panel;
	lv_obj_t *ui_Aircon_Line_Top;
	lv_obj_t *ui_Aircon_Line_Div_1;
	lv_obj_t *ui_Aircon_Line_Div_2;
	lv_obj_t *ui_Aircon_Line_Div_3;
	lv_obj_t *ui_Aircon_Line_Div_4;
	lv_obj_t *ui_Aircon_Line_Div_5;
	lv_obj_t *ui_Aircon_Label_SetTemp;
	lv_obj_t *ui_Aircon_Btn_TempUp;
	lv_obj_t *ui_Aircon_Btn_TempUp_label;
	lv_obj_t *ui_Aircon_Btn_TempDown;
	lv_obj_t *ui_Aircon_Btn_TempDown_label;
	lv_obj_t *ui_Aircon_Btn_timerUp;
	lv_obj_t *ui_Aircon_Btn_timerUp_label;
	lv_obj_t *ui_Aircon_Btn_timerDown;
	lv_obj_t *ui_Aircon_Btn_timerDown_label;
	lv_obj_t *ui_Aircon_Label_Temp;
	lv_obj_t *ui_Aircon_Label_Cen;
	lv_obj_t *ui_Aircon_Label_SetTimer;
	lv_obj_t *ui_Aircon_Label_TimerHour;
	lv_obj_t *ui_Aircon_Label_TimerMin;
	lv_obj_t *ui_Aircon_Label_TimerColon;
	lv_obj_t *ui_Aircon_Roller_Mode;
	lv_obj_t *ui_Aircon_Btn_Swing;
	lv_obj_t *ui_Aircon_Btn_Swing_label;
	lv_obj_t *ui_Aircon_Label_Select;
	lv_obj_t *ui_Aircon_Img_FanSt;
	lv_obj_t *ui_Aircon_Img_CompSt;
	lv_obj_t *ui_Aircon_Label_CompSel;
	lv_obj_t *ui_Aircon_Label_CompSt;
	lv_obj_t *ui_Aircon_Label_FanSt;
	lv_obj_t *ui_Aircon_Label_FanSel;
	lv_obj_t *ui_Aircon_Label_Fan;
	lv_obj_t *ui_Aircon_Slider_FanMode;
	lv_obj_t *ui_Aircon_Label_FanMode;
	lv_obj_t *ui_Aircon_Img_ACBG;
	lv_obj_t *ui_Aircon_Label_AC;
	lv_obj_t *ui_Aircon_Aimg_Swing;
	lv_obj_t *ui_Aircon_Aimg_Cool;
	lv_obj_t *ui_Aircon_Aimg_Fan;
	lv_obj_t *ui_Aircon_Label_Mask;
	lv_obj_t *ui_Aircon_Btn_Power;
	lv_obj_t *ui_Aircon_Btn_Power_label;
	lv_obj_t *ui_Aircon_btn_help;
	lv_obj_t *ui_Aircon_btn_help_label;
	lv_obj_t *ui_Aircon_msgbox_help;
	lv_obj_t *ui_Aircon_btn_close_help;
	lv_obj_t *ui_Aircon_btn_close_help_label;
	lv_obj_t *ui_Aircon_Btn_Wifi;
	lv_obj_t *ui_Aircon_Btn_Wifi_label;
	lv_obj_t *ui_Aircon_Btn_Server;
	lv_obj_t *ui_Aircon_Btn_Server_label;
	lv_obj_t *ui_Aircon_Btn_Settings;
	lv_obj_t *ui_Aircon_Btn_Settings_label;
	lv_obj_t *ui_Settings;
	bool ui_Settings_del;
	lv_obj_t *ui_Settings_cont_1;
	lv_obj_t *ui_Settings_label_Network;
	lv_obj_t *ui_Settings_ta_Password;
	lv_obj_t *ui_Settings_label_Password;
	lv_obj_t *ui_Settings_roller_Wifi;
	lv_obj_t *ui_Settings_btn_Scan_Wifi;
	lv_obj_t *ui_Settings_btn_Scan_Wifi_label;
	lv_obj_t *ui_Settings_label_URL;
	lv_obj_t *ui_Settings_ta_URL;
	lv_obj_t *ui_Settings_ta_User;
	lv_obj_t *ui_Settings_label_User;
	lv_obj_t *ui_Settings_ta_C_Password;
	lv_obj_t *ui_Settings_label_C_Pass;
	lv_obj_t *ui_Settings_btn_Close;
	lv_obj_t *ui_Settings_btn_Close_label;
	lv_obj_t *ui_Settings_label_Settings;
	lv_obj_t *ui_Settings_btn_Connect;
	lv_obj_t *ui_Settings_btn_Connect_label;
	lv_obj_t *ui_Settings_ta_Network;
	lv_obj_t *ui_Settings_btn_Show_Networks;
	lv_obj_t *ui_Settings_btn_Show_Networks_label;
	lv_obj_t *ui_Settings_btn_close_roller;
	lv_obj_t *ui_Settings_btn_close_roller_label;
	lv_obj_t *g_kb_top_layer;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_screen_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, uint32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                  uint32_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                  lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_completed_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_bottom_layer(void);

void setup_ui(lv_ui *ui);

void video_play(lv_ui *ui);

void init_keyboard(lv_ui *ui);

extern lv_ui guider_ui;


void setup_scr_ui_Aircon(lv_ui *ui);
void setup_scr_ui_Settings(lv_ui *ui);

LV_IMAGE_DECLARE(_aircon_bg_RGB565A8_480x320);
LV_IMAGE_DECLARE(_icn_fan_RGB565A8_20x20);
LV_IMAGE_DECLARE(_icn_dry_RGB565A8_20x20);
LV_IMAGE_DECLARE(_icn_fan_high_RGB565A8_20x20);
LV_IMAGE_DECLARE(_icn_fan_low_RGB565A8_20x20);
LV_IMAGE_DECLARE(_icn_cool_RGB565A8_20x20);
LV_IMAGE_DECLARE(_title_bg_RGB565A8_298x56);
LV_IMAGE_DECLARE(ui_Aircon_Aimg_Swingaircon_swing_0);
LV_IMAGE_DECLARE(ui_Aircon_Aimg_Swingaircon_swing_1);
LV_IMAGE_DECLARE(ui_Aircon_Aimg_Swingaircon_swing_2);
LV_IMAGE_DECLARE(ui_Aircon_Aimg_Swingaircon_swing_3);
LV_IMAGE_DECLARE(ui_Aircon_Aimg_Swingaircon_swing_4);
LV_IMAGE_DECLARE(ui_Aircon_Aimg_Swingaircon_swing_5);
LV_IMAGE_DECLARE(ui_Aircon_Aimg_Swingaircon_swing_6);
LV_IMAGE_DECLARE(ui_Aircon_Aimg_Swingaircon_swing_7);
LV_IMAGE_DECLARE(ui_Aircon_Aimg_Swingaircon_swing_8);
LV_IMAGE_DECLARE(ui_Aircon_Aimg_Swingaircon_swing_9);
LV_IMAGE_DECLARE(ui_Aircon_Aimg_Swingaircon_swing_10);
LV_IMAGE_DECLARE(ui_Aircon_Aimg_Swingaircon_swing_11);
LV_IMAGE_DECLARE(ui_Aircon_Aimg_Swingaircon_swing_12);
LV_IMAGE_DECLARE(ui_Aircon_Aimg_Swingaircon_swing_13);
LV_IMAGE_DECLARE(ui_Aircon_Aimg_Swingaircon_swing_14);
LV_IMAGE_DECLARE(ui_Aircon_Aimg_Coolaircon_cool_0);
LV_IMAGE_DECLARE(ui_Aircon_Aimg_Coolaircon_cool_1);
LV_IMAGE_DECLARE(ui_Aircon_Aimg_Coolaircon_cool_2);
LV_IMAGE_DECLARE(ui_Aircon_Aimg_Coolaircon_cool_3);
LV_IMAGE_DECLARE(ui_Aircon_Aimg_Coolaircon_cool_4);
LV_IMAGE_DECLARE(ui_Aircon_Aimg_Coolaircon_cool_5);
LV_IMAGE_DECLARE(ui_Aircon_Aimg_Fanaircon_fan_0);
LV_IMAGE_DECLARE(ui_Aircon_Aimg_Fanaircon_fan_1);
LV_IMAGE_DECLARE(ui_Aircon_Aimg_Fanaircon_fan_2);
LV_IMAGE_DECLARE(ui_Aircon_Aimg_Fanaircon_fan_3);
LV_IMAGE_DECLARE(ui_Aircon_Aimg_Fanaircon_fan_4);
LV_IMAGE_DECLARE(ui_Aircon_Aimg_Fanaircon_fan_5);

LV_FONT_DECLARE(lv_font_Antonio_Regular_15)
LV_FONT_DECLARE(lv_font_Amiko_Regular_16)
LV_FONT_DECLARE(lv_font_Antonio_Regular_25)
LV_FONT_DECLARE(lv_font_Amiko_Regular_12)
LV_FONT_DECLARE(lv_font_Alatsi_Regular_25)
LV_FONT_DECLARE(lv_font_Antonio_Regular_38)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_Antonio_Regular_28)
LV_FONT_DECLARE(lv_font_Antonio_Regular_12)
LV_FONT_DECLARE(lv_font_Antonio_Regular_13)
LV_FONT_DECLARE(lv_font_Antonio_Regular_14)
LV_FONT_DECLARE(lv_font_Antonio_Regular_11)
LV_FONT_DECLARE(lv_font_Antonio_Regular_16)
LV_FONT_DECLARE(lv_font_Antonio_Regular_40)
LV_FONT_DECLARE(lv_font_Antonio_Regular_19)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_Antonio_Regular_20)
LV_FONT_DECLARE(lv_font_montserratMedium_20)
LV_FONT_DECLARE(lv_font_Poppins_SemiBold_20)
LV_FONT_DECLARE(lv_font_Poppins_Regular_17)
LV_FONT_DECLARE(lv_font_Poppins_SemiBold_25)
LV_FONT_DECLARE(lv_font_Antonio_Regular_18)


#ifdef __cplusplus
}
#endif
#endif
