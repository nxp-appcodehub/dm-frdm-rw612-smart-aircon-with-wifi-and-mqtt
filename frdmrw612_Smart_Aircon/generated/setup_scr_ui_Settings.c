/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_ui_Settings(lv_ui *ui)
{
    //Write codes ui_Settings
    ui->ui_Settings = lv_obj_create(NULL);
    lv_obj_set_size(ui->ui_Settings, 480, 320);
    lv_obj_set_scrollbar_mode(ui->ui_Settings, LV_SCROLLBAR_MODE_OFF);
    lv_obj_remove_flag(ui->ui_Settings, LV_OBJ_FLAG_SCROLL_ELASTIC);
    lv_obj_remove_flag(ui->ui_Settings, LV_OBJ_FLAG_SCROLL_MOMENTUM);
    lv_obj_remove_flag(ui->ui_Settings, LV_OBJ_FLAG_SCROLL_ONE);
    lv_obj_remove_flag(ui->ui_Settings, LV_OBJ_FLAG_SCROLL_CHAIN_HOR);
    lv_obj_remove_flag(ui->ui_Settings, LV_OBJ_FLAG_SCROLL_CHAIN_VER);
    lv_obj_remove_flag(ui->ui_Settings, LV_OBJ_FLAG_SCROLL_CHAIN);
    lv_obj_remove_flag(ui->ui_Settings, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_remove_flag(ui->ui_Settings, LV_OBJ_FLAG_SCROLL_WITH_ARROW);

    //Write style for ui_Settings, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_Settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Settings_cont_1
    ui->ui_Settings_cont_1 = lv_obj_create(ui->ui_Settings);
    lv_obj_set_pos(ui->ui_Settings_cont_1, 1, -2);
    lv_obj_set_size(ui->ui_Settings_cont_1, 480, 400);
    lv_obj_set_scrollbar_mode(ui->ui_Settings_cont_1, LV_SCROLLBAR_MODE_OFF);
    lv_obj_remove_flag(ui->ui_Settings_cont_1, LV_OBJ_FLAG_SCROLL_CHAIN_HOR);

    //Write style for ui_Settings_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->ui_Settings_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->ui_Settings_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->ui_Settings_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->ui_Settings_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Settings_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ui_Settings_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_Settings_cont_1, lv_color_hex(0x042c35), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_Settings_cont_1, LV_GRAD_DIR_VER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui->ui_Settings_cont_1, lv_color_hex(0x929292), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui->ui_Settings_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui->ui_Settings_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ui_Settings_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ui_Settings_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ui_Settings_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ui_Settings_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Settings_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Settings_label_Network
    ui->ui_Settings_label_Network = lv_label_create(ui->ui_Settings_cont_1);
    lv_obj_set_pos(ui->ui_Settings_label_Network, 10, 110);
    lv_obj_set_size(ui->ui_Settings_label_Network, 130, 25);
    lv_label_set_text(ui->ui_Settings_label_Network, "NETWORK:");
    lv_label_set_long_mode(ui->ui_Settings_label_Network, LV_LABEL_LONG_WRAP);

    //Write style for ui_Settings_label_Network, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->ui_Settings_label_Network, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Settings_label_Network, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Settings_label_Network, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Settings_label_Network, &lv_font_Poppins_SemiBold_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Settings_label_Network, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->ui_Settings_label_Network, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->ui_Settings_label_Network, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Settings_label_Network, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ui_Settings_label_Network, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ui_Settings_label_Network, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ui_Settings_label_Network, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ui_Settings_label_Network, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ui_Settings_label_Network, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Settings_label_Network, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Settings_ta_Password
    ui->ui_Settings_ta_Password = lv_textarea_create(ui->ui_Settings_cont_1);
    lv_obj_set_pos(ui->ui_Settings_ta_Password, 145, 155);
    lv_obj_set_size(ui->ui_Settings_ta_Password, 220, 35);
    lv_textarea_set_text(ui->ui_Settings_ta_Password, "");
    lv_textarea_set_placeholder_text(ui->ui_Settings_ta_Password, "PASSWORD");
    lv_textarea_set_password_bullet(ui->ui_Settings_ta_Password, "*");
    lv_textarea_set_password_mode(ui->ui_Settings_ta_Password, true);
    lv_textarea_set_one_line(ui->ui_Settings_ta_Password, true);
    lv_textarea_set_accepted_chars(ui->ui_Settings_ta_Password, "");
    lv_textarea_set_max_length(ui->ui_Settings_ta_Password, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->ui_Settings_ta_Password, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for ui_Settings_ta_Password, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->ui_Settings_ta_Password, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Settings_ta_Password, &lv_font_Poppins_Regular_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Settings_ta_Password, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->ui_Settings_ta_Password, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Settings_ta_Password, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ui_Settings_ta_Password, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_Settings_ta_Password, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_Settings_ta_Password, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->ui_Settings_ta_Password, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->ui_Settings_ta_Password, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->ui_Settings_ta_Password, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->ui_Settings_ta_Password, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Settings_ta_Password, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ui_Settings_ta_Password, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ui_Settings_ta_Password, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ui_Settings_ta_Password, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Settings_ta_Password, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for ui_Settings_ta_Password, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_Settings_ta_Password, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_Settings_ta_Password, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_Settings_ta_Password, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Settings_ta_Password, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes ui_Settings_label_Password
    ui->ui_Settings_label_Password = lv_label_create(ui->ui_Settings_cont_1);
    lv_obj_set_pos(ui->ui_Settings_label_Password, 10, 160);
    lv_obj_set_size(ui->ui_Settings_label_Password, 130, 25);
    lv_label_set_text(ui->ui_Settings_label_Password, "PASSWORD:");
    lv_label_set_long_mode(ui->ui_Settings_label_Password, LV_LABEL_LONG_WRAP);

    //Write style for ui_Settings_label_Password, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->ui_Settings_label_Password, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Settings_label_Password, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Settings_label_Password, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Settings_label_Password, &lv_font_Poppins_SemiBold_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Settings_label_Password, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->ui_Settings_label_Password, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->ui_Settings_label_Password, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Settings_label_Password, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ui_Settings_label_Password, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ui_Settings_label_Password, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ui_Settings_label_Password, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ui_Settings_label_Password, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ui_Settings_label_Password, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Settings_label_Password, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Settings_roller_Wifi
    ui->ui_Settings_roller_Wifi = lv_roller_create(ui->ui_Settings_cont_1);
    lv_obj_set_pos(ui->ui_Settings_roller_Wifi, 145, 103);
    lv_obj_set_width(ui->ui_Settings_roller_Wifi, 180);
    lv_obj_add_flag(ui->ui_Settings_roller_Wifi, LV_OBJ_FLAG_HIDDEN);
    lv_roller_set_options(ui->ui_Settings_roller_Wifi, "1\n2\n3\n4\n5", LV_ROLLER_MODE_INFINITE);

    //Write style for ui_Settings_roller_Wifi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->ui_Settings_roller_Wifi, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ui_Settings_roller_Wifi, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_Settings_roller_Wifi, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_Settings_roller_Wifi, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Settings_roller_Wifi, lv_color_hex(0x333333), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Settings_roller_Wifi, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Settings_roller_Wifi, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Settings_roller_Wifi, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->ui_Settings_roller_Wifi, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->ui_Settings_roller_Wifi, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->ui_Settings_roller_Wifi, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->ui_Settings_roller_Wifi, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ui_Settings_roller_Wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ui_Settings_roller_Wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Settings_roller_Wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for ui_Settings_roller_Wifi, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_Settings_roller_Wifi, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_Settings_roller_Wifi, lv_color_hex(0x2195f6), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_Settings_roller_Wifi, LV_GRAD_DIR_NONE, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Settings_roller_Wifi, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Settings_roller_Wifi, &lv_font_montserratMedium_12, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Settings_roller_Wifi, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);

    lv_roller_set_visible_row_count(ui->ui_Settings_roller_Wifi, 5);
    //Write codes ui_Settings_btn_Scan_Wifi
    ui->ui_Settings_btn_Scan_Wifi = lv_button_create(ui->ui_Settings_cont_1);
    lv_obj_set_pos(ui->ui_Settings_btn_Scan_Wifi, 310, 355);
    lv_obj_set_size(ui->ui_Settings_btn_Scan_Wifi, 150, 35);
    ui->ui_Settings_btn_Scan_Wifi_label = lv_label_create(ui->ui_Settings_btn_Scan_Wifi);
    lv_label_set_text(ui->ui_Settings_btn_Scan_Wifi_label, "SCAN WIFI");
    lv_label_set_long_mode(ui->ui_Settings_btn_Scan_Wifi_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->ui_Settings_btn_Scan_Wifi_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->ui_Settings_btn_Scan_Wifi, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->ui_Settings_btn_Scan_Wifi_label, LV_PCT(100));

    //Write style for ui_Settings_btn_Scan_Wifi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_Settings_btn_Scan_Wifi, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_Settings_btn_Scan_Wifi, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_Settings_btn_Scan_Wifi, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->ui_Settings_btn_Scan_Wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Settings_btn_Scan_Wifi, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Settings_btn_Scan_Wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Settings_btn_Scan_Wifi, lv_color_hex(0x919191), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Settings_btn_Scan_Wifi, &lv_font_Poppins_Regular_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Settings_btn_Scan_Wifi, 149, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Settings_btn_Scan_Wifi, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for ui_Settings_btn_Scan_Wifi, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->ui_Settings_btn_Scan_Wifi, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->ui_Settings_btn_Scan_Wifi, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->ui_Settings_btn_Scan_Wifi, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->ui_Settings_btn_Scan_Wifi, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->ui_Settings_btn_Scan_Wifi, 5, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->ui_Settings_btn_Scan_Wifi, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->ui_Settings_btn_Scan_Wifi, lv_color_hex(0x919191), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->ui_Settings_btn_Scan_Wifi, &lv_font_Amiko_Regular_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->ui_Settings_btn_Scan_Wifi, 188, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes ui_Settings_label_URL
    ui->ui_Settings_label_URL = lv_label_create(ui->ui_Settings_cont_1);
    lv_obj_set_pos(ui->ui_Settings_label_URL, 10, 210);
    lv_obj_set_size(ui->ui_Settings_label_URL, 130, 25);
    lv_label_set_text(ui->ui_Settings_label_URL, "MQTT URL:");
    lv_label_set_long_mode(ui->ui_Settings_label_URL, LV_LABEL_LONG_WRAP);

    //Write style for ui_Settings_label_URL, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->ui_Settings_label_URL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Settings_label_URL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Settings_label_URL, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Settings_label_URL, &lv_font_Poppins_SemiBold_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Settings_label_URL, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->ui_Settings_label_URL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->ui_Settings_label_URL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Settings_label_URL, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ui_Settings_label_URL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ui_Settings_label_URL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ui_Settings_label_URL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ui_Settings_label_URL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ui_Settings_label_URL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Settings_label_URL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Settings_ta_URL
    ui->ui_Settings_ta_URL = lv_textarea_create(ui->ui_Settings_cont_1);
    lv_obj_set_pos(ui->ui_Settings_ta_URL, 145, 205);
    lv_obj_set_size(ui->ui_Settings_ta_URL, 220, 35);
    lv_textarea_set_text(ui->ui_Settings_ta_URL, "");
    lv_textarea_set_placeholder_text(ui->ui_Settings_ta_URL, "MQTT URL");
    lv_textarea_set_password_bullet(ui->ui_Settings_ta_URL, "*");
    lv_textarea_set_password_mode(ui->ui_Settings_ta_URL, false);
    lv_textarea_set_one_line(ui->ui_Settings_ta_URL, true);
    lv_textarea_set_accepted_chars(ui->ui_Settings_ta_URL, "");
    lv_textarea_set_max_length(ui->ui_Settings_ta_URL, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->ui_Settings_ta_URL, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for ui_Settings_ta_URL, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->ui_Settings_ta_URL, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Settings_ta_URL, &lv_font_Poppins_Regular_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Settings_ta_URL, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->ui_Settings_ta_URL, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Settings_ta_URL, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ui_Settings_ta_URL, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_Settings_ta_URL, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_Settings_ta_URL, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->ui_Settings_ta_URL, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->ui_Settings_ta_URL, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->ui_Settings_ta_URL, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->ui_Settings_ta_URL, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Settings_ta_URL, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ui_Settings_ta_URL, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ui_Settings_ta_URL, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ui_Settings_ta_URL, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Settings_ta_URL, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for ui_Settings_ta_URL, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_Settings_ta_URL, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_Settings_ta_URL, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_Settings_ta_URL, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Settings_ta_URL, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes ui_Settings_ta_User
    ui->ui_Settings_ta_User = lv_textarea_create(ui->ui_Settings_cont_1);
    lv_obj_set_pos(ui->ui_Settings_ta_User, 145, 255);
    lv_obj_set_size(ui->ui_Settings_ta_User, 220, 35);
    lv_textarea_set_text(ui->ui_Settings_ta_User, "");
    lv_textarea_set_placeholder_text(ui->ui_Settings_ta_User, "USER");
    lv_textarea_set_password_bullet(ui->ui_Settings_ta_User, "*");
    lv_textarea_set_password_mode(ui->ui_Settings_ta_User, false);
    lv_textarea_set_one_line(ui->ui_Settings_ta_User, true);
    lv_textarea_set_accepted_chars(ui->ui_Settings_ta_User, "");
    lv_textarea_set_max_length(ui->ui_Settings_ta_User, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->ui_Settings_ta_User, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for ui_Settings_ta_User, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->ui_Settings_ta_User, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Settings_ta_User, &lv_font_Poppins_Regular_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Settings_ta_User, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->ui_Settings_ta_User, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Settings_ta_User, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ui_Settings_ta_User, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_Settings_ta_User, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_Settings_ta_User, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->ui_Settings_ta_User, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->ui_Settings_ta_User, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->ui_Settings_ta_User, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->ui_Settings_ta_User, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Settings_ta_User, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ui_Settings_ta_User, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ui_Settings_ta_User, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ui_Settings_ta_User, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Settings_ta_User, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for ui_Settings_ta_User, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_Settings_ta_User, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_Settings_ta_User, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_Settings_ta_User, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Settings_ta_User, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes ui_Settings_label_User
    ui->ui_Settings_label_User = lv_label_create(ui->ui_Settings_cont_1);
    lv_obj_set_pos(ui->ui_Settings_label_User, 10, 260);
    lv_obj_set_size(ui->ui_Settings_label_User, 130, 25);
    lv_label_set_text(ui->ui_Settings_label_User, "USER:");
    lv_label_set_long_mode(ui->ui_Settings_label_User, LV_LABEL_LONG_WRAP);

    //Write style for ui_Settings_label_User, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->ui_Settings_label_User, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Settings_label_User, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Settings_label_User, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Settings_label_User, &lv_font_Poppins_SemiBold_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Settings_label_User, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->ui_Settings_label_User, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->ui_Settings_label_User, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Settings_label_User, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ui_Settings_label_User, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ui_Settings_label_User, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ui_Settings_label_User, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ui_Settings_label_User, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ui_Settings_label_User, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Settings_label_User, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Settings_ta_C_Password
    ui->ui_Settings_ta_C_Password = lv_textarea_create(ui->ui_Settings_cont_1);
    lv_obj_set_pos(ui->ui_Settings_ta_C_Password, 145, 305);
    lv_obj_set_size(ui->ui_Settings_ta_C_Password, 220, 35);
    lv_textarea_set_text(ui->ui_Settings_ta_C_Password, "");
    lv_textarea_set_placeholder_text(ui->ui_Settings_ta_C_Password, "Client Password");
    lv_textarea_set_password_bullet(ui->ui_Settings_ta_C_Password, "*");
    lv_textarea_set_password_mode(ui->ui_Settings_ta_C_Password, false);
    lv_textarea_set_one_line(ui->ui_Settings_ta_C_Password, true);
    lv_textarea_set_accepted_chars(ui->ui_Settings_ta_C_Password, "");
    lv_textarea_set_max_length(ui->ui_Settings_ta_C_Password, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->ui_Settings_ta_C_Password, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for ui_Settings_ta_C_Password, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->ui_Settings_ta_C_Password, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Settings_ta_C_Password, &lv_font_Poppins_Regular_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Settings_ta_C_Password, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->ui_Settings_ta_C_Password, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Settings_ta_C_Password, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ui_Settings_ta_C_Password, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_Settings_ta_C_Password, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_Settings_ta_C_Password, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->ui_Settings_ta_C_Password, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->ui_Settings_ta_C_Password, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->ui_Settings_ta_C_Password, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->ui_Settings_ta_C_Password, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Settings_ta_C_Password, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ui_Settings_ta_C_Password, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ui_Settings_ta_C_Password, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ui_Settings_ta_C_Password, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Settings_ta_C_Password, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for ui_Settings_ta_C_Password, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_Settings_ta_C_Password, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_Settings_ta_C_Password, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_Settings_ta_C_Password, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Settings_ta_C_Password, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes ui_Settings_label_C_Pass
    ui->ui_Settings_label_C_Pass = lv_label_create(ui->ui_Settings_cont_1);
    lv_obj_set_pos(ui->ui_Settings_label_C_Pass, 10, 310);
    lv_obj_set_size(ui->ui_Settings_label_C_Pass, 130, 25);
    lv_label_set_text(ui->ui_Settings_label_C_Pass, "CLIENT PASS:");
    lv_label_set_long_mode(ui->ui_Settings_label_C_Pass, LV_LABEL_LONG_WRAP);

    //Write style for ui_Settings_label_C_Pass, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->ui_Settings_label_C_Pass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Settings_label_C_Pass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Settings_label_C_Pass, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Settings_label_C_Pass, &lv_font_Poppins_SemiBold_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Settings_label_C_Pass, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->ui_Settings_label_C_Pass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->ui_Settings_label_C_Pass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Settings_label_C_Pass, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ui_Settings_label_C_Pass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ui_Settings_label_C_Pass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ui_Settings_label_C_Pass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ui_Settings_label_C_Pass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ui_Settings_label_C_Pass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Settings_label_C_Pass, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Settings_btn_Close
    ui->ui_Settings_btn_Close = lv_button_create(ui->ui_Settings_cont_1);
    lv_obj_set_pos(ui->ui_Settings_btn_Close, 436, 2);
    lv_obj_set_size(ui->ui_Settings_btn_Close, 53, 34);
    ui->ui_Settings_btn_Close_label = lv_label_create(ui->ui_Settings_btn_Close);
    lv_label_set_text(ui->ui_Settings_btn_Close_label, "" LV_SYMBOL_CLOSE "");
    lv_label_set_long_mode(ui->ui_Settings_btn_Close_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->ui_Settings_btn_Close_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->ui_Settings_btn_Close, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->ui_Settings_btn_Close_label, LV_PCT(100));

    //Write style for ui_Settings_btn_Close, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_Settings_btn_Close, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->ui_Settings_btn_Close, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Settings_btn_Close, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Settings_btn_Close, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Settings_btn_Close, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Settings_btn_Close, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Settings_btn_Close, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Settings_btn_Close, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Settings_label_Settings
    ui->ui_Settings_label_Settings = lv_label_create(ui->ui_Settings_cont_1);
    lv_obj_set_pos(ui->ui_Settings_label_Settings, 8, 13);
    lv_obj_set_size(ui->ui_Settings_label_Settings, 123, 24);
    lv_label_set_text(ui->ui_Settings_label_Settings, "SETTINGS");
    lv_label_set_long_mode(ui->ui_Settings_label_Settings, LV_LABEL_LONG_WRAP);

    //Write style for ui_Settings_label_Settings, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->ui_Settings_label_Settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Settings_label_Settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Settings_label_Settings, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Settings_label_Settings, &lv_font_Poppins_SemiBold_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Settings_label_Settings, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->ui_Settings_label_Settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->ui_Settings_label_Settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Settings_label_Settings, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ui_Settings_label_Settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ui_Settings_label_Settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ui_Settings_label_Settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ui_Settings_label_Settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ui_Settings_label_Settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Settings_label_Settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Settings_btn_Connect
    ui->ui_Settings_btn_Connect = lv_button_create(ui->ui_Settings_cont_1);
    lv_obj_set_pos(ui->ui_Settings_btn_Connect, 145, 355);
    lv_obj_set_size(ui->ui_Settings_btn_Connect, 150, 35);
    ui->ui_Settings_btn_Connect_label = lv_label_create(ui->ui_Settings_btn_Connect);
    lv_label_set_text(ui->ui_Settings_btn_Connect_label, "CONNECT");
    lv_label_set_long_mode(ui->ui_Settings_btn_Connect_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->ui_Settings_btn_Connect_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->ui_Settings_btn_Connect, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->ui_Settings_btn_Connect_label, LV_PCT(100));

    //Write style for ui_Settings_btn_Connect, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_Settings_btn_Connect, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_Settings_btn_Connect, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_Settings_btn_Connect, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->ui_Settings_btn_Connect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Settings_btn_Connect, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Settings_btn_Connect, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Settings_btn_Connect, lv_color_hex(0x919191), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Settings_btn_Connect, &lv_font_Poppins_Regular_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Settings_btn_Connect, 149, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Settings_btn_Connect, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for ui_Settings_btn_Connect, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->ui_Settings_btn_Connect, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->ui_Settings_btn_Connect, lv_color_hex(0x0ad720), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->ui_Settings_btn_Connect, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->ui_Settings_btn_Connect, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->ui_Settings_btn_Connect, 5, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->ui_Settings_btn_Connect, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->ui_Settings_btn_Connect, lv_color_hex(0x919191), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->ui_Settings_btn_Connect, &lv_font_Antonio_Regular_18, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->ui_Settings_btn_Connect, 188, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes ui_Settings_ta_Network
    ui->ui_Settings_ta_Network = lv_textarea_create(ui->ui_Settings_cont_1);
    lv_obj_set_pos(ui->ui_Settings_ta_Network, 145, 105);
    lv_obj_set_size(ui->ui_Settings_ta_Network, 220, 35);
    lv_textarea_set_text(ui->ui_Settings_ta_Network, "");
    lv_textarea_set_placeholder_text(ui->ui_Settings_ta_Network, "Network");
    lv_textarea_set_password_bullet(ui->ui_Settings_ta_Network, "*");
    lv_textarea_set_password_mode(ui->ui_Settings_ta_Network, false);
    lv_textarea_set_one_line(ui->ui_Settings_ta_Network, true);
    lv_textarea_set_accepted_chars(ui->ui_Settings_ta_Network, "");
    lv_textarea_set_max_length(ui->ui_Settings_ta_Network, 32);
#if LV_USE_KEYBOARD
    lv_obj_add_event_cb(ui->ui_Settings_ta_Network, ta_event_cb, LV_EVENT_ALL, ui->g_kb_top_layer);
#endif

    //Write style for ui_Settings_ta_Network, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->ui_Settings_ta_Network, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Settings_ta_Network, &lv_font_Poppins_Regular_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Settings_ta_Network, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->ui_Settings_ta_Network, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Settings_ta_Network, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ui_Settings_ta_Network, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_Settings_ta_Network, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_Settings_ta_Network, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->ui_Settings_ta_Network, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->ui_Settings_ta_Network, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->ui_Settings_ta_Network, lv_color_hex(0xe6e6e6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->ui_Settings_ta_Network, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Settings_ta_Network, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ui_Settings_ta_Network, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ui_Settings_ta_Network, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ui_Settings_ta_Network, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Settings_ta_Network, 4, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for ui_Settings_ta_Network, Part: LV_PART_SCROLLBAR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_Settings_ta_Network, 255, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_Settings_ta_Network, lv_color_hex(0x2195f6), LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_Settings_ta_Network, LV_GRAD_DIR_NONE, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Settings_ta_Network, 0, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

    //Write codes ui_Settings_btn_Show_Networks
    ui->ui_Settings_btn_Show_Networks = lv_button_create(ui->ui_Settings_cont_1);
    lv_obj_set_pos(ui->ui_Settings_btn_Show_Networks, 145, 55);
    lv_obj_set_size(ui->ui_Settings_btn_Show_Networks, 160, 35);
    ui->ui_Settings_btn_Show_Networks_label = lv_label_create(ui->ui_Settings_btn_Show_Networks);
    lv_label_set_text(ui->ui_Settings_btn_Show_Networks_label, "Show Networks");
    lv_label_set_long_mode(ui->ui_Settings_btn_Show_Networks_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->ui_Settings_btn_Show_Networks_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->ui_Settings_btn_Show_Networks, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->ui_Settings_btn_Show_Networks_label, LV_PCT(100));

    //Write style for ui_Settings_btn_Show_Networks, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_Settings_btn_Show_Networks, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_Settings_btn_Show_Networks, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_Settings_btn_Show_Networks, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->ui_Settings_btn_Show_Networks, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Settings_btn_Show_Networks, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Settings_btn_Show_Networks, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Settings_btn_Show_Networks, lv_color_hex(0x919191), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Settings_btn_Show_Networks, &lv_font_Poppins_Regular_17, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Settings_btn_Show_Networks, 149, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Settings_btn_Show_Networks, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for ui_Settings_btn_Show_Networks, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->ui_Settings_btn_Show_Networks, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->ui_Settings_btn_Show_Networks, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->ui_Settings_btn_Show_Networks, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->ui_Settings_btn_Show_Networks, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->ui_Settings_btn_Show_Networks, 5, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->ui_Settings_btn_Show_Networks, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->ui_Settings_btn_Show_Networks, lv_color_hex(0x919191), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->ui_Settings_btn_Show_Networks, &lv_font_Amiko_Regular_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->ui_Settings_btn_Show_Networks, 188, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes ui_Settings_btn_close_roller
    ui->ui_Settings_btn_close_roller = lv_button_create(ui->ui_Settings_cont_1);
    lv_obj_set_pos(ui->ui_Settings_btn_close_roller, 436, 32);
    lv_obj_set_size(ui->ui_Settings_btn_close_roller, 53, 34);
    lv_obj_add_flag(ui->ui_Settings_btn_close_roller, LV_OBJ_FLAG_HIDDEN);
    ui->ui_Settings_btn_close_roller_label = lv_label_create(ui->ui_Settings_btn_close_roller);
    lv_label_set_text(ui->ui_Settings_btn_close_roller_label, "" LV_SYMBOL_CLOSE "");
    lv_label_set_long_mode(ui->ui_Settings_btn_close_roller_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->ui_Settings_btn_close_roller_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->ui_Settings_btn_close_roller, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->ui_Settings_btn_close_roller_label, LV_PCT(100));

    //Write style for ui_Settings_btn_close_roller, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_Settings_btn_close_roller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->ui_Settings_btn_close_roller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Settings_btn_close_roller, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Settings_btn_close_roller, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Settings_btn_close_roller, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Settings_btn_close_roller, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Settings_btn_close_roller, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Settings_btn_close_roller, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of ui_Settings.


    //Update current screen layout.
    lv_obj_update_layout(ui->ui_Settings);

    //Init events for screen.
    events_init_ui_Settings(ui);
}
