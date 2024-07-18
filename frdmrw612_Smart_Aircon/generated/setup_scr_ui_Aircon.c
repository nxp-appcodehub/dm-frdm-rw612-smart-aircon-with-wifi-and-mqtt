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



void setup_scr_ui_Aircon(lv_ui *ui)
{
    //Write codes ui_Aircon
    ui->ui_Aircon = lv_obj_create(NULL);
    lv_obj_set_size(ui->ui_Aircon, 480, 320);
    lv_obj_set_scrollbar_mode(ui->ui_Aircon, LV_SCROLLBAR_MODE_OFF);

    //Write style for ui_Aircon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_Aircon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_src(ui->ui_Aircon, &_aircon_bg_RGB565A8_480x320, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_opa(ui->ui_Aircon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_image_recolor_opa(ui->ui_Aircon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Aircon_img_1
    ui->ui_Aircon_img_1 = lv_image_create(ui->ui_Aircon);
    lv_obj_set_pos(ui->ui_Aircon_img_1, -52, 169);
    lv_obj_set_size(ui->ui_Aircon_img_1, 20, 20);
    lv_obj_add_flag(ui->ui_Aircon_img_1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->ui_Aircon_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->ui_Aircon_img_1, &_icn_fan_RGB565A8_20x20);
    lv_image_set_pivot(ui->ui_Aircon_img_1, 50,50);
    lv_image_set_rotation(ui->ui_Aircon_img_1, 0);

    //Write style for ui_Aircon_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->ui_Aircon_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->ui_Aircon_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Aircon_img_2
    ui->ui_Aircon_img_2 = lv_image_create(ui->ui_Aircon);
    lv_obj_set_pos(ui->ui_Aircon_img_2, -52, 140);
    lv_obj_set_size(ui->ui_Aircon_img_2, 20, 20);
    lv_obj_add_flag(ui->ui_Aircon_img_2, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->ui_Aircon_img_2, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->ui_Aircon_img_2, &_icn_dry_RGB565A8_20x20);
    lv_image_set_pivot(ui->ui_Aircon_img_2, 50,50);
    lv_image_set_rotation(ui->ui_Aircon_img_2, 0);

    //Write style for ui_Aircon_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->ui_Aircon_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->ui_Aircon_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Aircon_img_3
    ui->ui_Aircon_img_3 = lv_image_create(ui->ui_Aircon);
    lv_obj_set_pos(ui->ui_Aircon_img_3, -52, 207);
    lv_obj_set_size(ui->ui_Aircon_img_3, 20, 20);
    lv_obj_add_flag(ui->ui_Aircon_img_3, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui->ui_Aircon_img_3, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->ui_Aircon_img_3, &_icn_fan_high_RGB565A8_20x20);
    lv_image_set_pivot(ui->ui_Aircon_img_3, 50,50);
    lv_image_set_rotation(ui->ui_Aircon_img_3, 0);

    //Write style for ui_Aircon_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->ui_Aircon_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->ui_Aircon_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Aircon_cont_panel
    ui->ui_Aircon_cont_panel = lv_obj_create(ui->ui_Aircon);
    lv_obj_set_pos(ui->ui_Aircon_cont_panel, 310, 9);
    lv_obj_set_size(ui->ui_Aircon_cont_panel, 170, 305);
    lv_obj_set_scrollbar_mode(ui->ui_Aircon_cont_panel, LV_SCROLLBAR_MODE_OFF);

    //Write style for ui_Aircon_cont_panel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->ui_Aircon_cont_panel, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->ui_Aircon_cont_panel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->ui_Aircon_cont_panel, lv_color_hex(0x4a4c4a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->ui_Aircon_cont_panel, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Aircon_cont_panel, 23, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ui_Aircon_cont_panel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_Aircon_cont_panel, lv_color_hex(0x242424), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_Aircon_cont_panel, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ui_Aircon_cont_panel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ui_Aircon_cont_panel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ui_Aircon_cont_panel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ui_Aircon_cont_panel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Aircon_cont_panel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Aircon_Line_Top
    ui->ui_Aircon_Line_Top = lv_line_create(ui->ui_Aircon_cont_panel);
    lv_obj_set_pos(ui->ui_Aircon_Line_Top, 6, 5);
    lv_obj_set_size(ui->ui_Aircon_Line_Top, 167, 15);
    static lv_point_precise_t ui_Aircon_Line_Top[] = {{0, 0},{150, 0}};
    lv_line_set_points(ui->ui_Aircon_Line_Top, ui_Aircon_Line_Top, 2);

    //Write style for ui_Aircon_Line_Top, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->ui_Aircon_Line_Top, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->ui_Aircon_Line_Top, lv_color_hex(0x52daff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->ui_Aircon_Line_Top, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->ui_Aircon_Line_Top, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Aircon_Line_Div_1
    ui->ui_Aircon_Line_Div_1 = lv_line_create(ui->ui_Aircon_cont_panel);
    lv_obj_set_pos(ui->ui_Aircon_Line_Div_1, 7, 87);
    lv_obj_set_size(ui->ui_Aircon_Line_Div_1, 150, 9);
    static lv_point_precise_t ui_Aircon_Line_Div_1[] = {{0, 0},{149, 0}};
    lv_line_set_points(ui->ui_Aircon_Line_Div_1, ui_Aircon_Line_Div_1, 2);

    //Write style for ui_Aircon_Line_Div_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->ui_Aircon_Line_Div_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->ui_Aircon_Line_Div_1, lv_color_hex(0x656461), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->ui_Aircon_Line_Div_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->ui_Aircon_Line_Div_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Aircon_Line_Div_2
    ui->ui_Aircon_Line_Div_2 = lv_line_create(ui->ui_Aircon_cont_panel);
    lv_obj_set_pos(ui->ui_Aircon_Line_Div_2, 7, 157);
    lv_obj_set_size(ui->ui_Aircon_Line_Div_2, 150, 9);
    static lv_point_precise_t ui_Aircon_Line_Div_2[] = {{0, 0},{149, 0}};
    lv_line_set_points(ui->ui_Aircon_Line_Div_2, ui_Aircon_Line_Div_2, 2);

    //Write style for ui_Aircon_Line_Div_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->ui_Aircon_Line_Div_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->ui_Aircon_Line_Div_2, lv_color_hex(0x656461), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->ui_Aircon_Line_Div_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->ui_Aircon_Line_Div_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Aircon_Line_Div_3
    ui->ui_Aircon_Line_Div_3 = lv_line_create(ui->ui_Aircon_cont_panel);
    lv_obj_set_pos(ui->ui_Aircon_Line_Div_3, 7, 260);
    lv_obj_set_size(ui->ui_Aircon_Line_Div_3, 150, 9);
    static lv_point_precise_t ui_Aircon_Line_Div_3[] = {{0, 0},{149, 0}};
    lv_line_set_points(ui->ui_Aircon_Line_Div_3, ui_Aircon_Line_Div_3, 2);

    //Write style for ui_Aircon_Line_Div_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->ui_Aircon_Line_Div_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->ui_Aircon_Line_Div_3, lv_color_hex(0x656461), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->ui_Aircon_Line_Div_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->ui_Aircon_Line_Div_3, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Aircon_Line_Div_4
    ui->ui_Aircon_Line_Div_4 = lv_line_create(ui->ui_Aircon_cont_panel);
    lv_obj_set_pos(ui->ui_Aircon_Line_Div_4, 78, 188);
    lv_obj_set_size(ui->ui_Aircon_Line_Div_4, 10, 58);
    static lv_point_precise_t ui_Aircon_Line_Div_4[] = {{0, 0},{0, 58}};
    lv_line_set_points(ui->ui_Aircon_Line_Div_4, ui_Aircon_Line_Div_4, 2);

    //Write style for ui_Aircon_Line_Div_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->ui_Aircon_Line_Div_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->ui_Aircon_Line_Div_4, lv_color_hex(0x656461), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->ui_Aircon_Line_Div_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->ui_Aircon_Line_Div_4, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Aircon_Line_Div_5
    ui->ui_Aircon_Line_Div_5 = lv_line_create(ui->ui_Aircon_cont_panel);
    lv_obj_set_pos(ui->ui_Aircon_Line_Div_5, 70, 267);
    lv_obj_set_size(ui->ui_Aircon_Line_Div_5, 10, 28);
    static lv_point_precise_t ui_Aircon_Line_Div_5[] = {{0, 0},{0, 23}};
    lv_line_set_points(ui->ui_Aircon_Line_Div_5, ui_Aircon_Line_Div_5, 2);

    //Write style for ui_Aircon_Line_Div_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_line_width(ui->ui_Aircon_Line_Div_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_color(ui->ui_Aircon_Line_Div_5, lv_color_hex(0x656461), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_opa(ui->ui_Aircon_Line_Div_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_line_rounded(ui->ui_Aircon_Line_Div_5, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Aircon_Label_SetTemp
    ui->ui_Aircon_Label_SetTemp = lv_label_create(ui->ui_Aircon_cont_panel);
    lv_obj_set_pos(ui->ui_Aircon_Label_SetTemp, 24, 16);
    lv_obj_set_size(ui->ui_Aircon_Label_SetTemp, 118, 21);
    lv_label_set_text(ui->ui_Aircon_Label_SetTemp, "SET TEMPERATURE");
    lv_label_set_long_mode(ui->ui_Aircon_Label_SetTemp, LV_LABEL_LONG_WRAP);

    //Write style for ui_Aircon_Label_SetTemp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->ui_Aircon_Label_SetTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Aircon_Label_SetTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Aircon_Label_SetTemp, lv_color_hex(0x52daff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Aircon_Label_SetTemp, &lv_font_Antonio_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Aircon_Label_SetTemp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->ui_Aircon_Label_SetTemp, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->ui_Aircon_Label_SetTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Aircon_Label_SetTemp, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ui_Aircon_Label_SetTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ui_Aircon_Label_SetTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ui_Aircon_Label_SetTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ui_Aircon_Label_SetTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ui_Aircon_Label_SetTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Aircon_Label_SetTemp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Aircon_Btn_TempUp
    ui->ui_Aircon_Btn_TempUp = lv_button_create(ui->ui_Aircon_cont_panel);
    lv_obj_set_pos(ui->ui_Aircon_Btn_TempUp, 12, 40);
    lv_obj_set_size(ui->ui_Aircon_Btn_TempUp, 30, 30);
    ui->ui_Aircon_Btn_TempUp_label = lv_label_create(ui->ui_Aircon_Btn_TempUp);
    lv_label_set_text(ui->ui_Aircon_Btn_TempUp_label, "" LV_SYMBOL_UP "");
    lv_label_set_long_mode(ui->ui_Aircon_Btn_TempUp_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->ui_Aircon_Btn_TempUp_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->ui_Aircon_Btn_TempUp, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->ui_Aircon_Btn_TempUp_label, LV_PCT(100));

    //Write style for ui_Aircon_Btn_TempUp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_Aircon_Btn_TempUp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_Aircon_Btn_TempUp, lv_color_hex(0x52daff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_Aircon_Btn_TempUp, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->ui_Aircon_Btn_TempUp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Aircon_Btn_TempUp, 11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Aircon_Btn_TempUp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Aircon_Btn_TempUp, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Aircon_Btn_TempUp, &lv_font_Antonio_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Aircon_Btn_TempUp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Aircon_Btn_TempUp, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Aircon_Btn_TempDown
    ui->ui_Aircon_Btn_TempDown = lv_button_create(ui->ui_Aircon_cont_panel);
    lv_obj_set_pos(ui->ui_Aircon_Btn_TempDown, 120, 40);
    lv_obj_set_size(ui->ui_Aircon_Btn_TempDown, 30, 30);
    ui->ui_Aircon_Btn_TempDown_label = lv_label_create(ui->ui_Aircon_Btn_TempDown);
    lv_label_set_text(ui->ui_Aircon_Btn_TempDown_label, "" LV_SYMBOL_DOWN "");
    lv_label_set_long_mode(ui->ui_Aircon_Btn_TempDown_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->ui_Aircon_Btn_TempDown_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->ui_Aircon_Btn_TempDown, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->ui_Aircon_Btn_TempDown_label, LV_PCT(100));

    //Write style for ui_Aircon_Btn_TempDown, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_Aircon_Btn_TempDown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_Aircon_Btn_TempDown, lv_color_hex(0x52daff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_Aircon_Btn_TempDown, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->ui_Aircon_Btn_TempDown, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Aircon_Btn_TempDown, 11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Aircon_Btn_TempDown, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Aircon_Btn_TempDown, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Aircon_Btn_TempDown, &lv_font_Alatsi_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Aircon_Btn_TempDown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Aircon_Btn_TempDown, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Aircon_Btn_timerUp
    ui->ui_Aircon_Btn_timerUp = lv_button_create(ui->ui_Aircon_cont_panel);
    lv_obj_set_pos(ui->ui_Aircon_Btn_timerUp, 12, 108);
    lv_obj_set_size(ui->ui_Aircon_Btn_timerUp, 30, 30);
    ui->ui_Aircon_Btn_timerUp_label = lv_label_create(ui->ui_Aircon_Btn_timerUp);
    lv_label_set_text(ui->ui_Aircon_Btn_timerUp_label, "" LV_SYMBOL_UP "");
    lv_label_set_long_mode(ui->ui_Aircon_Btn_timerUp_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->ui_Aircon_Btn_timerUp_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->ui_Aircon_Btn_timerUp, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->ui_Aircon_Btn_timerUp_label, LV_PCT(100));

    //Write style for ui_Aircon_Btn_timerUp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_Aircon_Btn_timerUp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_Aircon_Btn_timerUp, lv_color_hex(0x52daff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_Aircon_Btn_timerUp, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->ui_Aircon_Btn_timerUp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Aircon_Btn_timerUp, 11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Aircon_Btn_timerUp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Aircon_Btn_timerUp, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Aircon_Btn_timerUp, &lv_font_Alatsi_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Aircon_Btn_timerUp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Aircon_Btn_timerUp, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Aircon_Btn_timerDown
    ui->ui_Aircon_Btn_timerDown = lv_button_create(ui->ui_Aircon_cont_panel);
    lv_obj_set_pos(ui->ui_Aircon_Btn_timerDown, 120, 108);
    lv_obj_set_size(ui->ui_Aircon_Btn_timerDown, 30, 30);
    ui->ui_Aircon_Btn_timerDown_label = lv_label_create(ui->ui_Aircon_Btn_timerDown);
    lv_label_set_text(ui->ui_Aircon_Btn_timerDown_label, "" LV_SYMBOL_DOWN "");
    lv_label_set_long_mode(ui->ui_Aircon_Btn_timerDown_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->ui_Aircon_Btn_timerDown_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->ui_Aircon_Btn_timerDown, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->ui_Aircon_Btn_timerDown_label, LV_PCT(100));

    //Write style for ui_Aircon_Btn_timerDown, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_Aircon_Btn_timerDown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_Aircon_Btn_timerDown, lv_color_hex(0x52daff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_Aircon_Btn_timerDown, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->ui_Aircon_Btn_timerDown, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Aircon_Btn_timerDown, 11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Aircon_Btn_timerDown, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Aircon_Btn_timerDown, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Aircon_Btn_timerDown, &lv_font_Alatsi_Regular_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Aircon_Btn_timerDown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Aircon_Btn_timerDown, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Aircon_Label_Temp
    ui->ui_Aircon_Label_Temp = lv_label_create(ui->ui_Aircon_cont_panel);
    lv_obj_set_pos(ui->ui_Aircon_Label_Temp, 49, 37);
    lv_obj_set_size(ui->ui_Aircon_Label_Temp, 56, 54);
    lv_label_set_text(ui->ui_Aircon_Label_Temp, "25");
    lv_label_set_long_mode(ui->ui_Aircon_Label_Temp, LV_LABEL_LONG_WRAP);

    //Write style for ui_Aircon_Label_Temp, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->ui_Aircon_Label_Temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Aircon_Label_Temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Aircon_Label_Temp, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Aircon_Label_Temp, &lv_font_Antonio_Regular_38, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Aircon_Label_Temp, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->ui_Aircon_Label_Temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->ui_Aircon_Label_Temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Aircon_Label_Temp, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ui_Aircon_Label_Temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ui_Aircon_Label_Temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ui_Aircon_Label_Temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ui_Aircon_Label_Temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ui_Aircon_Label_Temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Aircon_Label_Temp, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Aircon_Label_Cen
    ui->ui_Aircon_Label_Cen = lv_label_create(ui->ui_Aircon_cont_panel);
    lv_obj_set_pos(ui->ui_Aircon_Label_Cen, 91, 40);
    lv_obj_set_size(ui->ui_Aircon_Label_Cen, 26, 20);
    lv_label_set_text(ui->ui_Aircon_Label_Cen, "ºC");
    lv_label_set_long_mode(ui->ui_Aircon_Label_Cen, LV_LABEL_LONG_WRAP);

    //Write style for ui_Aircon_Label_Cen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->ui_Aircon_Label_Cen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Aircon_Label_Cen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Aircon_Label_Cen, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Aircon_Label_Cen, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Aircon_Label_Cen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->ui_Aircon_Label_Cen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->ui_Aircon_Label_Cen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Aircon_Label_Cen, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ui_Aircon_Label_Cen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ui_Aircon_Label_Cen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ui_Aircon_Label_Cen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ui_Aircon_Label_Cen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ui_Aircon_Label_Cen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Aircon_Label_Cen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Aircon_Label_SetTimer
    ui->ui_Aircon_Label_SetTimer = lv_label_create(ui->ui_Aircon_cont_panel);
    lv_obj_set_pos(ui->ui_Aircon_Label_SetTimer, 41, 90);
    lv_obj_set_size(ui->ui_Aircon_Label_SetTimer, 81, 22);
    lv_label_set_text(ui->ui_Aircon_Label_SetTimer, "SET TIMER");
    lv_label_set_long_mode(ui->ui_Aircon_Label_SetTimer, LV_LABEL_LONG_WRAP);

    //Write style for ui_Aircon_Label_SetTimer, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->ui_Aircon_Label_SetTimer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Aircon_Label_SetTimer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Aircon_Label_SetTimer, lv_color_hex(0x52daff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Aircon_Label_SetTimer, &lv_font_Antonio_Regular_15, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Aircon_Label_SetTimer, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->ui_Aircon_Label_SetTimer, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->ui_Aircon_Label_SetTimer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Aircon_Label_SetTimer, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ui_Aircon_Label_SetTimer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ui_Aircon_Label_SetTimer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ui_Aircon_Label_SetTimer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ui_Aircon_Label_SetTimer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ui_Aircon_Label_SetTimer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Aircon_Label_SetTimer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Aircon_Label_TimerHour
    ui->ui_Aircon_Label_TimerHour = lv_label_create(ui->ui_Aircon_cont_panel);
    lv_obj_set_pos(ui->ui_Aircon_Label_TimerHour, 47, 111);
    lv_obj_set_size(ui->ui_Aircon_Label_TimerHour, 30, 40);
    lv_label_set_text(ui->ui_Aircon_Label_TimerHour, "01");
    lv_label_set_long_mode(ui->ui_Aircon_Label_TimerHour, LV_LABEL_LONG_WRAP);

    //Write style for ui_Aircon_Label_TimerHour, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->ui_Aircon_Label_TimerHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Aircon_Label_TimerHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Aircon_Label_TimerHour, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Aircon_Label_TimerHour, &lv_font_Antonio_Regular_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Aircon_Label_TimerHour, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->ui_Aircon_Label_TimerHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->ui_Aircon_Label_TimerHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Aircon_Label_TimerHour, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ui_Aircon_Label_TimerHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ui_Aircon_Label_TimerHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ui_Aircon_Label_TimerHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ui_Aircon_Label_TimerHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ui_Aircon_Label_TimerHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Aircon_Label_TimerHour, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Aircon_Label_TimerMin
    ui->ui_Aircon_Label_TimerMin = lv_label_create(ui->ui_Aircon_cont_panel);
    lv_obj_set_pos(ui->ui_Aircon_Label_TimerMin, 87, 111);
    lv_obj_set_size(ui->ui_Aircon_Label_TimerMin, 30, 40);
    lv_label_set_text(ui->ui_Aircon_Label_TimerMin, "15");
    lv_label_set_long_mode(ui->ui_Aircon_Label_TimerMin, LV_LABEL_LONG_WRAP);

    //Write style for ui_Aircon_Label_TimerMin, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->ui_Aircon_Label_TimerMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Aircon_Label_TimerMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Aircon_Label_TimerMin, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Aircon_Label_TimerMin, &lv_font_Antonio_Regular_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Aircon_Label_TimerMin, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->ui_Aircon_Label_TimerMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->ui_Aircon_Label_TimerMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Aircon_Label_TimerMin, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ui_Aircon_Label_TimerMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ui_Aircon_Label_TimerMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ui_Aircon_Label_TimerMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ui_Aircon_Label_TimerMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ui_Aircon_Label_TimerMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Aircon_Label_TimerMin, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Aircon_Label_TimerColon
    ui->ui_Aircon_Label_TimerColon = lv_label_create(ui->ui_Aircon_cont_panel);
    lv_obj_set_pos(ui->ui_Aircon_Label_TimerColon, 70, 111);
    lv_obj_set_size(ui->ui_Aircon_Label_TimerColon, 22, 37);
    lv_label_set_text(ui->ui_Aircon_Label_TimerColon, ":");
    lv_label_set_long_mode(ui->ui_Aircon_Label_TimerColon, LV_LABEL_LONG_WRAP);

    //Write style for ui_Aircon_Label_TimerColon, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->ui_Aircon_Label_TimerColon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Aircon_Label_TimerColon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Aircon_Label_TimerColon, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Aircon_Label_TimerColon, &lv_font_Antonio_Regular_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Aircon_Label_TimerColon, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->ui_Aircon_Label_TimerColon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->ui_Aircon_Label_TimerColon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Aircon_Label_TimerColon, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ui_Aircon_Label_TimerColon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ui_Aircon_Label_TimerColon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ui_Aircon_Label_TimerColon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ui_Aircon_Label_TimerColon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ui_Aircon_Label_TimerColon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Aircon_Label_TimerColon, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Aircon_Roller_Mode
    ui->ui_Aircon_Roller_Mode = lv_roller_create(ui->ui_Aircon_cont_panel);
    lv_obj_set_pos(ui->ui_Aircon_Roller_Mode, 4, 158);
    lv_obj_set_width(ui->ui_Aircon_Roller_Mode, 70);
    lv_roller_set_options(ui->ui_Aircon_Roller_Mode, "COOL\nDRY\nFAN", LV_ROLLER_MODE_INFINITE);

    //Write style for ui_Aircon_Roller_Mode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->ui_Aircon_Roller_Mode, 11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ui_Aircon_Roller_Mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_Aircon_Roller_Mode, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_Aircon_Roller_Mode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Aircon_Roller_Mode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Aircon_Roller_Mode, &lv_font_Antonio_Regular_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Aircon_Roller_Mode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Aircon_Roller_Mode, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->ui_Aircon_Roller_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ui_Aircon_Roller_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ui_Aircon_Roller_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Aircon_Roller_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for ui_Aircon_Roller_Mode, Part: LV_PART_SELECTED, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_Aircon_Roller_Mode, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_Aircon_Roller_Mode, lv_color_hex(0x52daff), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_Aircon_Roller_Mode, LV_GRAD_DIR_NONE, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Aircon_Roller_Mode, lv_color_hex(0xFFFFFF), LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Aircon_Roller_Mode, &lv_font_Antonio_Regular_13, LV_PART_SELECTED|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Aircon_Roller_Mode, 255, LV_PART_SELECTED|LV_STATE_DEFAULT);

    lv_roller_set_visible_row_count(ui->ui_Aircon_Roller_Mode, 3);
    //Write codes ui_Aircon_Btn_Swing
    ui->ui_Aircon_Btn_Swing = lv_button_create(ui->ui_Aircon_cont_panel);
    lv_obj_set_pos(ui->ui_Aircon_Btn_Swing, 6, 268);
    lv_obj_set_size(ui->ui_Aircon_Btn_Swing, 60, 23);
    lv_obj_add_flag(ui->ui_Aircon_Btn_Swing, LV_OBJ_FLAG_CHECKABLE);
    ui->ui_Aircon_Btn_Swing_label = lv_label_create(ui->ui_Aircon_Btn_Swing);
    lv_label_set_text(ui->ui_Aircon_Btn_Swing_label, "SWING");
    lv_label_set_long_mode(ui->ui_Aircon_Btn_Swing_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->ui_Aircon_Btn_Swing_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->ui_Aircon_Btn_Swing, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->ui_Aircon_Btn_Swing_label, LV_PCT(100));

    //Write style for ui_Aircon_Btn_Swing, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_Aircon_Btn_Swing, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_Aircon_Btn_Swing, lv_color_hex(0x6a6a6a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_Aircon_Btn_Swing, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->ui_Aircon_Btn_Swing, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Aircon_Btn_Swing, 11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Aircon_Btn_Swing, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Aircon_Btn_Swing, lv_color_hex(0xe2e2e2), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Aircon_Btn_Swing, &lv_font_Antonio_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Aircon_Btn_Swing, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Aircon_Btn_Swing, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for ui_Aircon_Btn_Swing, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->ui_Aircon_Btn_Swing, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui->ui_Aircon_Btn_Swing, lv_color_hex(0x52daff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_bg_grad_dir(ui->ui_Aircon_Btn_Swing, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->ui_Aircon_Btn_Swing, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->ui_Aircon_Btn_Swing, 23, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->ui_Aircon_Btn_Swing, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->ui_Aircon_Btn_Swing, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->ui_Aircon_Btn_Swing, &lv_font_Antonio_Regular_14, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->ui_Aircon_Btn_Swing, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes ui_Aircon_Label_Select
    ui->ui_Aircon_Label_Select = lv_label_create(ui->ui_Aircon_cont_panel);
    lv_obj_set_pos(ui->ui_Aircon_Label_Select, 77, 162);
    lv_obj_set_size(ui->ui_Aircon_Label_Select, 81, 22);
    lv_label_set_text(ui->ui_Aircon_Label_Select, "SELECT MODE");
    lv_label_set_long_mode(ui->ui_Aircon_Label_Select, LV_LABEL_LONG_WRAP);

    //Write style for ui_Aircon_Label_Select, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->ui_Aircon_Label_Select, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Aircon_Label_Select, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Aircon_Label_Select, lv_color_hex(0x52daff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Aircon_Label_Select, &lv_font_Antonio_Regular_13, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Aircon_Label_Select, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->ui_Aircon_Label_Select, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->ui_Aircon_Label_Select, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Aircon_Label_Select, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ui_Aircon_Label_Select, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ui_Aircon_Label_Select, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ui_Aircon_Label_Select, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ui_Aircon_Label_Select, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ui_Aircon_Label_Select, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Aircon_Label_Select, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Aircon_Img_FanSt
    ui->ui_Aircon_Img_FanSt = lv_image_create(ui->ui_Aircon_cont_panel);
    lv_obj_set_pos(ui->ui_Aircon_Img_FanSt, 90, 221);
    lv_obj_set_size(ui->ui_Aircon_Img_FanSt, 20, 20);
    lv_obj_add_flag(ui->ui_Aircon_Img_FanSt, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->ui_Aircon_Img_FanSt, &_icn_fan_low_RGB565A8_20x20);
    lv_image_set_pivot(ui->ui_Aircon_Img_FanSt, 50,50);
    lv_image_set_rotation(ui->ui_Aircon_Img_FanSt, 0);

    //Write style for ui_Aircon_Img_FanSt, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->ui_Aircon_Img_FanSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->ui_Aircon_Img_FanSt, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Aircon_Img_CompSt
    ui->ui_Aircon_Img_CompSt = lv_image_create(ui->ui_Aircon_cont_panel);
    lv_obj_set_pos(ui->ui_Aircon_Img_CompSt, 90, 187);
    lv_obj_set_size(ui->ui_Aircon_Img_CompSt, 20, 20);
    lv_obj_add_flag(ui->ui_Aircon_Img_CompSt, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->ui_Aircon_Img_CompSt, &_icn_cool_RGB565A8_20x20);
    lv_image_set_pivot(ui->ui_Aircon_Img_CompSt, 50,50);
    lv_image_set_rotation(ui->ui_Aircon_Img_CompSt, 0);

    //Write style for ui_Aircon_Img_CompSt, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->ui_Aircon_Img_CompSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->ui_Aircon_Img_CompSt, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Aircon_Label_CompSel
    ui->ui_Aircon_Label_CompSel = lv_label_create(ui->ui_Aircon_cont_panel);
    lv_obj_set_pos(ui->ui_Aircon_Label_CompSel, 114, 185);
    lv_obj_set_size(ui->ui_Aircon_Label_CompSel, 40, 20);
    lv_label_set_text(ui->ui_Aircon_Label_CompSel, "COMP");
    lv_label_set_long_mode(ui->ui_Aircon_Label_CompSel, LV_LABEL_LONG_WRAP);

    //Write style for ui_Aircon_Label_CompSel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->ui_Aircon_Label_CompSel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Aircon_Label_CompSel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Aircon_Label_CompSel, lv_color_hex(0x52daff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Aircon_Label_CompSel, &lv_font_Antonio_Regular_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Aircon_Label_CompSel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->ui_Aircon_Label_CompSel, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->ui_Aircon_Label_CompSel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Aircon_Label_CompSel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ui_Aircon_Label_CompSel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ui_Aircon_Label_CompSel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ui_Aircon_Label_CompSel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ui_Aircon_Label_CompSel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ui_Aircon_Label_CompSel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Aircon_Label_CompSel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Aircon_Label_CompSt
    ui->ui_Aircon_Label_CompSt = lv_label_create(ui->ui_Aircon_cont_panel);
    lv_obj_set_pos(ui->ui_Aircon_Label_CompSt, 122, 201);
    lv_obj_set_size(ui->ui_Aircon_Label_CompSt, 23, 16);
    lv_label_set_text(ui->ui_Aircon_Label_CompSt, "ON");
    lv_label_set_long_mode(ui->ui_Aircon_Label_CompSt, LV_LABEL_LONG_WRAP);

    //Write style for ui_Aircon_Label_CompSt, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->ui_Aircon_Label_CompSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Aircon_Label_CompSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Aircon_Label_CompSt, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Aircon_Label_CompSt, &lv_font_Antonio_Regular_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Aircon_Label_CompSt, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->ui_Aircon_Label_CompSt, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->ui_Aircon_Label_CompSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Aircon_Label_CompSt, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ui_Aircon_Label_CompSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ui_Aircon_Label_CompSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ui_Aircon_Label_CompSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ui_Aircon_Label_CompSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ui_Aircon_Label_CompSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Aircon_Label_CompSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Aircon_Label_FanSt
    ui->ui_Aircon_Label_FanSt = lv_label_create(ui->ui_Aircon_cont_panel);
    lv_obj_set_pos(ui->ui_Aircon_Label_FanSt, 113, 234);
    lv_obj_set_size(ui->ui_Aircon_Label_FanSt, 44, 16);
    lv_label_set_text(ui->ui_Aircon_Label_FanSt, "LOW");
    lv_label_set_long_mode(ui->ui_Aircon_Label_FanSt, LV_LABEL_LONG_WRAP);

    //Write style for ui_Aircon_Label_FanSt, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->ui_Aircon_Label_FanSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Aircon_Label_FanSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Aircon_Label_FanSt, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Aircon_Label_FanSt, &lv_font_Antonio_Regular_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Aircon_Label_FanSt, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->ui_Aircon_Label_FanSt, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->ui_Aircon_Label_FanSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Aircon_Label_FanSt, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ui_Aircon_Label_FanSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ui_Aircon_Label_FanSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ui_Aircon_Label_FanSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ui_Aircon_Label_FanSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ui_Aircon_Label_FanSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Aircon_Label_FanSt, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Aircon_Label_FanSel
    ui->ui_Aircon_Label_FanSel = lv_label_create(ui->ui_Aircon_cont_panel);
    lv_obj_set_pos(ui->ui_Aircon_Label_FanSel, 114, 217);
    lv_obj_set_size(ui->ui_Aircon_Label_FanSel, 40, 20);
    lv_label_set_text(ui->ui_Aircon_Label_FanSel, "FAN");
    lv_label_set_long_mode(ui->ui_Aircon_Label_FanSel, LV_LABEL_LONG_WRAP);

    //Write style for ui_Aircon_Label_FanSel, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->ui_Aircon_Label_FanSel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Aircon_Label_FanSel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Aircon_Label_FanSel, lv_color_hex(0x52daff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Aircon_Label_FanSel, &lv_font_Antonio_Regular_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Aircon_Label_FanSel, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->ui_Aircon_Label_FanSel, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->ui_Aircon_Label_FanSel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Aircon_Label_FanSel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ui_Aircon_Label_FanSel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ui_Aircon_Label_FanSel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ui_Aircon_Label_FanSel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ui_Aircon_Label_FanSel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ui_Aircon_Label_FanSel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Aircon_Label_FanSel, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Aircon_Label_Fan
    ui->ui_Aircon_Label_Fan = lv_label_create(ui->ui_Aircon_cont_panel);
    lv_obj_set_pos(ui->ui_Aircon_Label_Fan, 70, 271);
    lv_obj_set_size(ui->ui_Aircon_Label_Fan, 28, 20);
    lv_label_set_text(ui->ui_Aircon_Label_Fan, "FAN");
    lv_label_set_long_mode(ui->ui_Aircon_Label_Fan, LV_LABEL_LONG_WRAP);

    //Write style for ui_Aircon_Label_Fan, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->ui_Aircon_Label_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Aircon_Label_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Aircon_Label_Fan, lv_color_hex(0x52daff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Aircon_Label_Fan, &lv_font_Antonio_Regular_14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Aircon_Label_Fan, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->ui_Aircon_Label_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->ui_Aircon_Label_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Aircon_Label_Fan, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ui_Aircon_Label_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ui_Aircon_Label_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ui_Aircon_Label_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ui_Aircon_Label_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ui_Aircon_Label_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Aircon_Label_Fan, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Aircon_Slider_FanMode
    ui->ui_Aircon_Slider_FanMode = lv_slider_create(ui->ui_Aircon_cont_panel);
    lv_obj_set_pos(ui->ui_Aircon_Slider_FanMode, 97, 274);
    lv_obj_set_size(ui->ui_Aircon_Slider_FanMode, 63, 2);
    lv_slider_set_range(ui->ui_Aircon_Slider_FanMode, 0, 2);
    lv_slider_set_mode(ui->ui_Aircon_Slider_FanMode, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->ui_Aircon_Slider_FanMode, 1, LV_ANIM_OFF);

    //Write style for ui_Aircon_Slider_FanMode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_Aircon_Slider_FanMode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_Aircon_Slider_FanMode, lv_color_hex(0x6a6a6a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_Aircon_Slider_FanMode, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Aircon_Slider_FanMode, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->ui_Aircon_Slider_FanMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Aircon_Slider_FanMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for ui_Aircon_Slider_FanMode, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_Aircon_Slider_FanMode, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_Aircon_Slider_FanMode, lv_color_hex(0x52daff), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_Aircon_Slider_FanMode, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Aircon_Slider_FanMode, 58, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for ui_Aircon_Slider_FanMode, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_Aircon_Slider_FanMode, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->ui_Aircon_Slider_FanMode, lv_color_hex(0xffffff), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->ui_Aircon_Slider_FanMode, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Aircon_Slider_FanMode, 58, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes ui_Aircon_Label_FanMode
    ui->ui_Aircon_Label_FanMode = lv_label_create(ui->ui_Aircon_cont_panel);
    lv_obj_set_pos(ui->ui_Aircon_Label_FanMode, 96, 270);
    lv_obj_set_size(ui->ui_Aircon_Label_FanMode, 76, 32);
    lv_label_set_text(ui->ui_Aircon_Label_FanMode, "•         •        •\nL         M       H");
    lv_label_set_long_mode(ui->ui_Aircon_Label_FanMode, LV_LABEL_LONG_WRAP);

    //Write style for ui_Aircon_Label_FanMode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->ui_Aircon_Label_FanMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Aircon_Label_FanMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Aircon_Label_FanMode, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Aircon_Label_FanMode, &lv_font_Antonio_Regular_11, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Aircon_Label_FanMode, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->ui_Aircon_Label_FanMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->ui_Aircon_Label_FanMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Aircon_Label_FanMode, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ui_Aircon_Label_FanMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ui_Aircon_Label_FanMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ui_Aircon_Label_FanMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ui_Aircon_Label_FanMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ui_Aircon_Label_FanMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Aircon_Label_FanMode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Aircon_Img_ACBG
    ui->ui_Aircon_Img_ACBG = lv_image_create(ui->ui_Aircon);
    lv_obj_set_pos(ui->ui_Aircon_Img_ACBG, 0, 258);
    lv_obj_set_size(ui->ui_Aircon_Img_ACBG, 298, 56);
    lv_obj_add_flag(ui->ui_Aircon_Img_ACBG, LV_OBJ_FLAG_CLICKABLE);
    lv_image_set_src(ui->ui_Aircon_Img_ACBG, &_title_bg_RGB565A8_298x56);
    lv_image_set_pivot(ui->ui_Aircon_Img_ACBG, 50,50);
    lv_image_set_rotation(ui->ui_Aircon_Img_ACBG, 0);

    //Write style for ui_Aircon_Img_ACBG, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_image_recolor_opa(ui->ui_Aircon_Img_ACBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_image_opa(ui->ui_Aircon_Img_ACBG, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Aircon_Label_AC
    ui->ui_Aircon_Label_AC = lv_label_create(ui->ui_Aircon);
    lv_obj_set_pos(ui->ui_Aircon_Label_AC, 121, 277);
    lv_obj_set_size(ui->ui_Aircon_Label_AC, 153, 23);
    lv_label_set_text(ui->ui_Aircon_Label_AC, "Air Conditioner");
    lv_label_set_long_mode(ui->ui_Aircon_Label_AC, LV_LABEL_LONG_WRAP);

    //Write style for ui_Aircon_Label_AC, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->ui_Aircon_Label_AC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Aircon_Label_AC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Aircon_Label_AC, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Aircon_Label_AC, &lv_font_Antonio_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Aircon_Label_AC, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->ui_Aircon_Label_AC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->ui_Aircon_Label_AC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Aircon_Label_AC, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->ui_Aircon_Label_AC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->ui_Aircon_Label_AC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->ui_Aircon_Label_AC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->ui_Aircon_Label_AC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->ui_Aircon_Label_AC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Aircon_Label_AC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Aircon_Aimg_Swing
    ui->ui_Aircon_Aimg_Swing = lv_animimg_create(ui->ui_Aircon);
    lv_obj_set_pos(ui->ui_Aircon_Aimg_Swing, 42, 169);
    lv_obj_set_size(ui->ui_Aircon_Aimg_Swing, 240, 49);
    lv_animimg_set_src(ui->ui_Aircon_Aimg_Swing, (const void **) ui_Aircon_Aimg_Swing_imgs, 15, false);
    lv_animimg_set_duration(ui->ui_Aircon_Aimg_Swing, 200*15);
    lv_animimg_set_repeat_count(ui->ui_Aircon_Aimg_Swing, LV_ANIM_REPEAT_INFINITE);
    lv_animimg_set_playback_time(ui->ui_Aircon_Aimg_Swing, 3000);
    lv_animimg_set_playback_delay(ui->ui_Aircon_Aimg_Swing, 200);
    lv_image_set_src(ui->ui_Aircon_Aimg_Swing, ui_Aircon_Aimg_Swing_imgs[0]);

    //Write codes ui_Aircon_Aimg_Cool
    ui->ui_Aircon_Aimg_Cool = lv_animimg_create(ui->ui_Aircon);
    lv_obj_set_pos(ui->ui_Aircon_Aimg_Cool, 208, 92);
    lv_obj_set_size(ui->ui_Aircon_Aimg_Cool, 33, 43);
    lv_animimg_set_src(ui->ui_Aircon_Aimg_Cool, (const void **) ui_Aircon_Aimg_Cool_imgs, 6, false);
    lv_animimg_set_duration(ui->ui_Aircon_Aimg_Cool, 150*6);
    lv_animimg_set_repeat_count(ui->ui_Aircon_Aimg_Cool, LV_ANIM_REPEAT_INFINITE);
    lv_animimg_start(ui->ui_Aircon_Aimg_Cool);

    //Write codes ui_Aircon_Aimg_Fan
    ui->ui_Aircon_Aimg_Fan = lv_animimg_create(ui->ui_Aircon);
    lv_obj_set_pos(ui->ui_Aircon_Aimg_Fan, 242, 94);
    lv_obj_set_size(ui->ui_Aircon_Aimg_Fan, 36, 36);
    lv_animimg_set_src(ui->ui_Aircon_Aimg_Fan, (const void **) ui_Aircon_Aimg_Fan_imgs, 6, false);
    lv_animimg_set_duration(ui->ui_Aircon_Aimg_Fan, 150*6);
    lv_animimg_set_repeat_count(ui->ui_Aircon_Aimg_Fan, LV_ANIM_REPEAT_INFINITE);
    lv_animimg_start(ui->ui_Aircon_Aimg_Fan);

    //Write codes ui_Aircon_Label_Mask
    ui->ui_Aircon_Label_Mask = lv_label_create(ui->ui_Aircon);
    lv_obj_set_pos(ui->ui_Aircon_Label_Mask, -5, 0);
    lv_obj_set_size(ui->ui_Aircon_Label_Mask, 480, 320);
    lv_obj_add_flag(ui->ui_Aircon_Label_Mask, LV_OBJ_FLAG_CLICKABLE);
    lv_label_set_text(ui->ui_Aircon_Label_Mask, "");
    lv_label_set_long_mode(ui->ui_Aircon_Label_Mask, LV_LABEL_LONG_WRAP);

    //Write codes ui_Aircon_Btn_Power
    ui->ui_Aircon_Btn_Power = lv_button_create(ui->ui_Aircon);
    lv_obj_set_pos(ui->ui_Aircon_Btn_Power, 0, 0);
    lv_obj_set_size(ui->ui_Aircon_Btn_Power, 50, 50);
    lv_obj_add_flag(ui->ui_Aircon_Btn_Power, LV_OBJ_FLAG_CHECKABLE);
    ui->ui_Aircon_Btn_Power_label = lv_label_create(ui->ui_Aircon_Btn_Power);
    lv_label_set_text(ui->ui_Aircon_Btn_Power_label, "" LV_SYMBOL_POWER "");
    lv_label_set_long_mode(ui->ui_Aircon_Btn_Power_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->ui_Aircon_Btn_Power_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->ui_Aircon_Btn_Power, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->ui_Aircon_Btn_Power_label, LV_PCT(100));

    //Write style for ui_Aircon_Btn_Power, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_Aircon_Btn_Power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->ui_Aircon_Btn_Power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Aircon_Btn_Power, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Aircon_Btn_Power, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Aircon_Btn_Power, lv_color_hex(0xe0e0e0), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Aircon_Btn_Power, &lv_font_Antonio_Regular_40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Aircon_Btn_Power, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Aircon_Btn_Power, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for ui_Aircon_Btn_Power, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->ui_Aircon_Btn_Power, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->ui_Aircon_Btn_Power, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->ui_Aircon_Btn_Power, 5, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->ui_Aircon_Btn_Power, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->ui_Aircon_Btn_Power, lv_color_hex(0x52daff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->ui_Aircon_Btn_Power, &lv_font_Antonio_Regular_40, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->ui_Aircon_Btn_Power, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write codes ui_Aircon_btn_help
    ui->ui_Aircon_btn_help = lv_button_create(ui->ui_Aircon);
    lv_obj_set_pos(ui->ui_Aircon_btn_help, 3, 277);
    lv_obj_set_size(ui->ui_Aircon_btn_help, 40, 39);
    ui->ui_Aircon_btn_help_label = lv_label_create(ui->ui_Aircon_btn_help);
    lv_label_set_text(ui->ui_Aircon_btn_help_label, "?");
    lv_label_set_long_mode(ui->ui_Aircon_btn_help_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->ui_Aircon_btn_help_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->ui_Aircon_btn_help, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->ui_Aircon_btn_help_label, LV_PCT(100));

    //Write style for ui_Aircon_btn_help, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_Aircon_btn_help, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->ui_Aircon_btn_help, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Aircon_btn_help, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Aircon_btn_help, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Aircon_btn_help, lv_color_hex(0xb5b5b5), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Aircon_btn_help, &lv_font_Antonio_Regular_19, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Aircon_btn_help, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Aircon_btn_help, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Aircon_msgbox_help
    ui->ui_Aircon_msgbox_help = lv_msgbox_create(ui->ui_Aircon);
    lv_obj_set_pos(ui->ui_Aircon_msgbox_help, 90, 35);
    lv_obj_set_size(ui->ui_Aircon_msgbox_help, 300, 250);
    lv_obj_add_flag(ui->ui_Aircon_msgbox_help, LV_OBJ_FLAG_HIDDEN);
    lv_msgbox_add_title(ui->ui_Aircon_msgbox_help, "Supported Voice Commands");
    lv_msgbox_add_text(ui->ui_Aircon_msgbox_help, "Hey NXP:\nPOWER ON | POWER OFF\nLOW SPEED | MEDIUM SPEED | HIGH SPEED\nCOOL MODE | DRY MODE\nSWING ON | SWING OFF\nHEAT UP | COOL DOWN\nHALF HOUR TIMER | QUARTER HOUR TIMER");
    lv_obj_align_to(ui->ui_Aircon_msgbox_help, ui->ui_Aircon, LV_ALIGN_TOP_LEFT, 90, 35);

    //Write style state: LV_STATE_DEFAULT for &style_ui_Aircon_msgbox_help_extra_title_main_default
    static lv_style_t style_ui_Aircon_msgbox_help_extra_title_main_default;
    ui_init_style(&style_ui_Aircon_msgbox_help_extra_title_main_default);

    lv_style_set_bg_opa(&style_ui_Aircon_msgbox_help_extra_title_main_default, 255);
    lv_style_set_bg_color(&style_ui_Aircon_msgbox_help_extra_title_main_default, lv_color_hex(0xffffff));
    lv_style_set_bg_grad_dir(&style_ui_Aircon_msgbox_help_extra_title_main_default, LV_GRAD_DIR_NONE);
    lv_style_set_text_color(&style_ui_Aircon_msgbox_help_extra_title_main_default, lv_color_hex(0x4e4e4e));
    lv_style_set_text_font(&style_ui_Aircon_msgbox_help_extra_title_main_default, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_ui_Aircon_msgbox_help_extra_title_main_default, 255);
    lv_style_set_text_letter_space(&style_ui_Aircon_msgbox_help_extra_title_main_default, 0);
    lv_style_set_text_line_space(&style_ui_Aircon_msgbox_help_extra_title_main_default, 15);
    lv_obj_add_style(lv_msgbox_get_header(ui->ui_Aircon_msgbox_help), &style_ui_Aircon_msgbox_help_extra_title_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_ui_Aircon_msgbox_help_extra_content_main_default
    static lv_style_t style_ui_Aircon_msgbox_help_extra_content_main_default;
    ui_init_style(&style_ui_Aircon_msgbox_help_extra_content_main_default);

    lv_style_set_text_color(&style_ui_Aircon_msgbox_help_extra_content_main_default, lv_color_hex(0x4e4e4e));
    lv_style_set_text_font(&style_ui_Aircon_msgbox_help_extra_content_main_default, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_ui_Aircon_msgbox_help_extra_content_main_default, 255);
    lv_style_set_text_letter_space(&style_ui_Aircon_msgbox_help_extra_content_main_default, 0);
    lv_style_set_text_line_space(&style_ui_Aircon_msgbox_help_extra_content_main_default, 10);
    lv_obj_add_style(lv_msgbox_get_content(ui->ui_Aircon_msgbox_help), &style_ui_Aircon_msgbox_help_extra_content_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style state: LV_STATE_DEFAULT for &style_ui_Aircon_msgbox_help_extra_btns_items_default
    static lv_style_t style_ui_Aircon_msgbox_help_extra_btns_items_default;
    ui_init_style(&style_ui_Aircon_msgbox_help_extra_btns_items_default);

    lv_style_set_bg_opa(&style_ui_Aircon_msgbox_help_extra_btns_items_default, 255);
    lv_style_set_bg_color(&style_ui_Aircon_msgbox_help_extra_btns_items_default, lv_color_hex(0xe6e6e6));
    lv_style_set_bg_grad_dir(&style_ui_Aircon_msgbox_help_extra_btns_items_default, LV_GRAD_DIR_NONE);
    lv_style_set_border_width(&style_ui_Aircon_msgbox_help_extra_btns_items_default, 0);
    lv_style_set_radius(&style_ui_Aircon_msgbox_help_extra_btns_items_default, 10);
    lv_style_set_text_color(&style_ui_Aircon_msgbox_help_extra_btns_items_default, lv_color_hex(0x4e4e4e));
    lv_style_set_text_font(&style_ui_Aircon_msgbox_help_extra_btns_items_default, &lv_font_montserratMedium_12);
    lv_style_set_text_opa(&style_ui_Aircon_msgbox_help_extra_btns_items_default, 255);

    //Write codes ui_Aircon_btn_close_help
    ui->ui_Aircon_btn_close_help = lv_button_create(ui->ui_Aircon);
    lv_obj_set_pos(ui->ui_Aircon_btn_close_help, 353, 47);
    lv_obj_set_size(ui->ui_Aircon_btn_close_help, 25, 25);
    lv_obj_add_flag(ui->ui_Aircon_btn_close_help, LV_OBJ_FLAG_HIDDEN);
    ui->ui_Aircon_btn_close_help_label = lv_label_create(ui->ui_Aircon_btn_close_help);
    lv_label_set_text(ui->ui_Aircon_btn_close_help_label, "X");
    lv_label_set_long_mode(ui->ui_Aircon_btn_close_help_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->ui_Aircon_btn_close_help_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->ui_Aircon_btn_close_help, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->ui_Aircon_btn_close_help_label, LV_PCT(100));

    //Write style for ui_Aircon_btn_close_help, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_Aircon_btn_close_help, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->ui_Aircon_btn_close_help, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Aircon_btn_close_help, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Aircon_btn_close_help, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Aircon_btn_close_help, lv_color_hex(0x090808), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Aircon_btn_close_help, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Aircon_btn_close_help, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Aircon_btn_close_help, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes ui_Aircon_Btn_Wifi
    ui->ui_Aircon_Btn_Wifi = lv_button_create(ui->ui_Aircon);
    lv_obj_set_pos(ui->ui_Aircon_Btn_Wifi, 274, 5);
    lv_obj_set_size(ui->ui_Aircon_Btn_Wifi, 30, 29);
    ui->ui_Aircon_Btn_Wifi_label = lv_label_create(ui->ui_Aircon_Btn_Wifi);
    lv_label_set_text(ui->ui_Aircon_Btn_Wifi_label, "" LV_SYMBOL_WIFI "");
    lv_label_set_long_mode(ui->ui_Aircon_Btn_Wifi_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->ui_Aircon_Btn_Wifi_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->ui_Aircon_Btn_Wifi, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->ui_Aircon_Btn_Wifi_label, LV_PCT(100));

    //Write style for ui_Aircon_Btn_Wifi, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_Aircon_Btn_Wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->ui_Aircon_Btn_Wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Aircon_Btn_Wifi, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Aircon_Btn_Wifi, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Aircon_Btn_Wifi, lv_color_hex(0xe0e0e0), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Aircon_Btn_Wifi, &lv_font_Antonio_Regular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Aircon_Btn_Wifi, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Aircon_Btn_Wifi, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for ui_Aircon_Btn_Wifi, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->ui_Aircon_Btn_Wifi, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->ui_Aircon_Btn_Wifi, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->ui_Aircon_Btn_Wifi, 5, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->ui_Aircon_Btn_Wifi, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->ui_Aircon_Btn_Wifi, lv_color_hex(0x52daff), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->ui_Aircon_Btn_Wifi, &lv_font_Antonio_Regular_20, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->ui_Aircon_Btn_Wifi, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for ui_Aircon_Btn_Wifi, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_bg_opa(ui->ui_Aircon_Btn_Wifi, 255, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui->ui_Aircon_Btn_Wifi, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_bg_grad_dir(ui->ui_Aircon_Btn_Wifi, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->ui_Aircon_Btn_Wifi, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->ui_Aircon_Btn_Wifi, 5, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->ui_Aircon_Btn_Wifi, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->ui_Aircon_Btn_Wifi, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->ui_Aircon_Btn_Wifi, &lv_font_Amiko_Regular_12, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->ui_Aircon_Btn_Wifi, 255, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes ui_Aircon_Btn_Server
    ui->ui_Aircon_Btn_Server = lv_button_create(ui->ui_Aircon);
    lv_obj_set_pos(ui->ui_Aircon_Btn_Server, 237, 5);
    lv_obj_set_size(ui->ui_Aircon_Btn_Server, 32, 30);
    ui->ui_Aircon_Btn_Server_label = lv_label_create(ui->ui_Aircon_Btn_Server);
    lv_label_set_text(ui->ui_Aircon_Btn_Server_label, "" LV_SYMBOL_LIST "");
    lv_label_set_long_mode(ui->ui_Aircon_Btn_Server_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->ui_Aircon_Btn_Server_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->ui_Aircon_Btn_Server, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->ui_Aircon_Btn_Server_label, LV_PCT(100));

    //Write style for ui_Aircon_Btn_Server, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_Aircon_Btn_Server, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->ui_Aircon_Btn_Server, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Aircon_Btn_Server, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Aircon_Btn_Server, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Aircon_Btn_Server, lv_color_hex(0xdfdfdf), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Aircon_Btn_Server, &lv_font_Antonio_Regular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Aircon_Btn_Server, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Aircon_Btn_Server, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for ui_Aircon_Btn_Server, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->ui_Aircon_Btn_Server, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->ui_Aircon_Btn_Server, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->ui_Aircon_Btn_Server, 5, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->ui_Aircon_Btn_Server, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->ui_Aircon_Btn_Server, lv_color_hex(0x24c9ed), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->ui_Aircon_Btn_Server, &lv_font_Antonio_Regular_20, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->ui_Aircon_Btn_Server, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for ui_Aircon_Btn_Server, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_bg_opa(ui->ui_Aircon_Btn_Server, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->ui_Aircon_Btn_Server, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->ui_Aircon_Btn_Server, 5, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->ui_Aircon_Btn_Server, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->ui_Aircon_Btn_Server, lv_color_hex(0xe0e0e0), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->ui_Aircon_Btn_Server, &lv_font_Antonio_Regular_20, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->ui_Aircon_Btn_Server, 255, LV_PART_MAIN|LV_STATE_DISABLED);

    //Write codes ui_Aircon_Btn_Settings
    ui->ui_Aircon_Btn_Settings = lv_button_create(ui->ui_Aircon);
    lv_obj_set_pos(ui->ui_Aircon_Btn_Settings, 205, 5);
    lv_obj_set_size(ui->ui_Aircon_Btn_Settings, 32, 30);
    lv_obj_add_flag(ui->ui_Aircon_Btn_Settings, LV_OBJ_FLAG_CHECKABLE);
    ui->ui_Aircon_Btn_Settings_label = lv_label_create(ui->ui_Aircon_Btn_Settings);
    lv_label_set_text(ui->ui_Aircon_Btn_Settings_label, "" LV_SYMBOL_SETTINGS "");
    lv_label_set_long_mode(ui->ui_Aircon_Btn_Settings_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->ui_Aircon_Btn_Settings_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->ui_Aircon_Btn_Settings, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->ui_Aircon_Btn_Settings_label, LV_PCT(100));

    //Write style for ui_Aircon_Btn_Settings, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->ui_Aircon_Btn_Settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->ui_Aircon_Btn_Settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->ui_Aircon_Btn_Settings, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->ui_Aircon_Btn_Settings, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->ui_Aircon_Btn_Settings, lv_color_hex(0xdfdfdf), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->ui_Aircon_Btn_Settings, &lv_font_Antonio_Regular_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->ui_Aircon_Btn_Settings, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->ui_Aircon_Btn_Settings, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for ui_Aircon_Btn_Settings, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->ui_Aircon_Btn_Settings, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->ui_Aircon_Btn_Settings, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->ui_Aircon_Btn_Settings, 5, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->ui_Aircon_Btn_Settings, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->ui_Aircon_Btn_Settings, lv_color_hex(0x00e1f9), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->ui_Aircon_Btn_Settings, &lv_font_montserratMedium_20, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->ui_Aircon_Btn_Settings, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for ui_Aircon_Btn_Settings, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_bg_opa(ui->ui_Aircon_Btn_Settings, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui->ui_Aircon_Btn_Settings, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_radius(ui->ui_Aircon_Btn_Settings, 5, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->ui_Aircon_Btn_Settings, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->ui_Aircon_Btn_Settings, lv_color_hex(0x24c9ed), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->ui_Aircon_Btn_Settings, &lv_font_Antonio_Regular_20, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->ui_Aircon_Btn_Settings, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for ui_Aircon_Btn_Settings, Part: LV_PART_MAIN, State: LV_STATE_DISABLED.
    lv_obj_set_style_bg_opa(ui->ui_Aircon_Btn_Settings, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui->ui_Aircon_Btn_Settings, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_radius(ui->ui_Aircon_Btn_Settings, 5, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_shadow_width(ui->ui_Aircon_Btn_Settings, 0, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_color(ui->ui_Aircon_Btn_Settings, lv_color_hex(0xe0e0e0), LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_font(ui->ui_Aircon_Btn_Settings, &lv_font_Antonio_Regular_20, LV_PART_MAIN|LV_STATE_DISABLED);
    lv_obj_set_style_text_opa(ui->ui_Aircon_Btn_Settings, 255, LV_PART_MAIN|LV_STATE_DISABLED);

    //The custom code of ui_Aircon.


    //Update current screen layout.
    lv_obj_update_layout(ui->ui_Aircon);

    //Init events for screen.
    events_init_ui_Aircon(ui);
}
