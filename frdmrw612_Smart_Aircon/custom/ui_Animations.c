/*
* Copyright 2023-2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "ui_Animations.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void swing_anim_cb(void * var, int32_t v);

static void swing_anim_restart_cb(void * var);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Function
 ******************************************************************************/
void ui_aircon_swing_anim(bool isPowerOn, bool isPowerOff)
{
	lv_animimg_delete(guider_ui.ui_Aircon_Aimg_Swing);
	bool isSwing = lv_obj_has_state(guider_ui.ui_Aircon_Btn_Swing, LV_STATE_CHECKED);
	lv_anim_t a;
	lv_anim_init(&a);
	lv_anim_set_exec_cb(&a, swing_anim_cb);
	lv_anim_set_var(&a, guider_ui.ui_Aircon_Aimg_Swing);

	for (uint32_t cur_img_id = 0; cur_img_id < 15; cur_img_id++) {
		if (lv_image_get_src(guider_ui.ui_Aircon_Aimg_Swing) == ui_Aircon_Aimg_Swing_imgs[cur_img_id]) {
			if (cur_img_id != 0) {
				lv_anim_set_values(&a, cur_img_id, isPowerOn ? 9 : 0);
				if (!isPowerOff && !isPowerOn) {
					lv_anim_set_completed_cb(&a, (lv_anim_completed_cb_t)swing_anim_restart_cb);
				}
				lv_anim_set_duration(&a, isPowerOn ? ((9 - cur_img_id) * 200) : (cur_img_id * 200));
				lv_anim_start(&a);
			} else if (isPowerOn && !isSwing) {
				lv_anim_set_values(&a, 0, 9);
				lv_anim_set_duration(&a, 9 * 200);
				lv_anim_start(&a);
			} else {
				lv_animimg_start(guider_ui.ui_Aircon_Aimg_Swing);
			}
			break;
		}
	}
}
/*******************************************************************************
 * Static function
 ******************************************************************************/

static void swing_anim_cb(void * var, int32_t v)
{
	lv_obj_t * obj = var;

	lv_image_set_src(obj, ui_Aircon_Aimg_Swing_imgs[v]);
}

static void swing_anim_restart_cb(void * var)
{
	LV_UNUSED(var); 

	lv_animimg_start(guider_ui.ui_Aircon_Aimg_Swing);
}
