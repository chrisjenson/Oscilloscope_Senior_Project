#include <stdio.h>
#include "project.h"
#include "lvgl.h"
#include "slider_activity.h"

//used to trigger whenever a slider is used
/*
static void slider_action(lv_obj_t * slider, lv_event_t e)
{
    if(e == LV_EVENT_VALUE_CHANGED) {
        if(lv_slider_get_type(slider) == LV_SLIDER_TYPE_NORMAL) {
            static char buf[16];
            lv_snprintf(buf, sizeof(buf), "%d", lv_slider_get_value(slider));
            lv_obj_set_style_local_value_str(slider, LV_SLIDER_PART_KNOB, LV_STATE_DEFAULT, buf);
        } else {
            static char buf[32];
            lv_snprintf(buf, sizeof(buf), "%d-%d", lv_slider_get_left_value(slider), lv_slider_get_value(slider));
            lv_obj_set_style_local_value_str(slider, LV_SLIDER_PART_INDIC, LV_STATE_DEFAULT, buf);
        }

    }

}*/