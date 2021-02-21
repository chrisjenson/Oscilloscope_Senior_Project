#include <stdio.h>

#include "project.h"
#include "globalStruct.h"
#include "lvgl.h"
#include "home_screen.h"
//#include "breath_activity.h"
//#include "time_date_activity.h"
#include "slider_activity.h"
#include "math.h"

//static lv_obj_t * slider_label;

const uint8_t tcnj_blue[] = { 41, 63, 111 };
const uint8_t tcnj_gold[] = { 166, 122, 0 };

char offset_str[3];

static lv_obj_t * offsetLabel;
static lv_obj_t * triggerLabel;
static lv_obj_t * horiLabel1;
static lv_obj_t * vertLabel1;
static lv_obj_t * windowLabel;

uint8_t zeros = 0b00000000;

static void sw_event_handler(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_VALUE_CHANGED) {
        printf("State: %s\n", lv_sw_get_state(obj) ? "On" : "Off");
        //cm4.onBit = !cm4.onBit;
    }
}

static void offset_slider_event_cb(lv_obj_t * slider, lv_event_t event)
{
    if(event == LV_EVENT_VALUE_CHANGED) {
        static char buf[4]; /* max 3 bytes for number plus 1 null terminating byte */
        snprintf(buf, 4, "%u", lv_slider_get_value(slider));
        lv_label_set_text(offsetLabel, buf);
        //int temp = (int)(buf);          //type cast the new slider value to an integer
        //cm4.Offset = (zeros | temp);    //stores the new slider value in the global structure
        cm4.Offset = lv_slider_get_value(slider);
    }
}
static void trigger_slider_event_cb(lv_obj_t * slider, lv_event_t event)
{
    if(event == LV_EVENT_VALUE_CHANGED) {
        static char buf[4]; /* max 3 bytes for number plus 1 null terminating byte */
        snprintf(buf, 4, "%u", lv_slider_get_value(slider));
        lv_label_set_text(triggerLabel, buf);
        //int temp = (int)(buf);          //type cast the new slider value to an integer
        //cm4.Trigger = (zeros | temp);    //stores the new slider value in the global structure
        cm4.Trigger = lv_slider_get_value(slider);
    }
}
static void hori_slider_event_cb(lv_obj_t * slider, lv_event_t event)
{
    if(event == LV_EVENT_VALUE_CHANGED) {
        static char buf[4]; /* max 3 bytes for number plus 1 null terminating byte */
        snprintf(buf, 4, "%u", lv_slider_get_value(slider));
        lv_label_set_text(horiLabel1, buf);
        //int temp = (int)(buf);          //type cast the new slider value to an integer
        //cm4.HoriScale = (zeros | temp);    //stores the new slider value in the global structure
        cm4.HoriScale = lv_slider_get_value(slider);
    }
}
static void verti_slider_event_cb(lv_obj_t * slider, lv_event_t event)
{
    if(event == LV_EVENT_VALUE_CHANGED) {
        static char buf[4]; /* max 3 bytes for number plus 1 null terminating byte */
        snprintf(buf, 4, "%u", lv_slider_get_value(slider));
        lv_label_set_text(vertLabel1, buf);
        //int temp = (int)(buf);          //type cast the new slider value to an integer
        //cm4.VertScale = (zeros | temp);    //stores the new slider value in the global structure
        cm4.VertScale = lv_slider_get_value(slider);
    }
}
static void window_slider_event_cb(lv_obj_t * slider, lv_event_t event)
{
    if(event == LV_EVENT_VALUE_CHANGED) {
        static char buf[6]; /* max 3 bytes for number plus 1 null terminating byte */
        snprintf(buf, 6, "%u", lv_slider_get_value(slider));
        lv_label_set_text(windowLabel, buf);
        //int temp = (int)(buf);          //type cast the new slider value to an integer
        //cm4.windowPos = (zeros | temp);    //stores the new slider value in the global structure
        cm4.windowPos = lv_slider_get_value(slider);
    }
}

void home_screen()
{
  
    const int chart_width = 280;
    const int chart_heigth = 200;
    const int chart_vertPos = 20;
    const int chart_horiPos = 20;      
    
    //static lv_obj_t *my_label;
    //static lv_style_t *lbl_style;
    
    static lv_obj_t *chart1;        //declaring the chart
    
    /* First Slider: Offset */
    lv_obj_t * offsetSlider = lv_slider_create(lv_scr_act(), NULL);
    lv_obj_set_pos(offsetSlider, 20, 295);                         /*Set its position*/
    lv_obj_set_size(offsetSlider, 130, 30);                        /*Set its size*/
    lv_slider_set_value(offsetSlider, 5, LV_ANIM_ON);
    lv_obj_set_event_cb(offsetSlider, offset_slider_event_cb);
    lv_slider_set_range(offsetSlider, 0, 10);
        
            /* Create a label below the slider */
            offsetLabel = lv_label_create(lv_scr_act(), NULL);
            lv_label_set_text(offsetLabel, "5");
            lv_obj_set_auto_realign(offsetLabel, true);
            lv_obj_align(offsetLabel, offsetSlider, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
        
            /* Create a label above the slider */
        	lv_obj_t* offsetLabel2 = lv_label_create(lv_scr_act(), NULL);
        	lv_obj_set_drag(offsetLabel2, false);
            lv_label_set_text(offsetLabel2, "Offset:");
            lv_label_set_long_mode(offsetLabel2, LV_LABEL_LONG_EXPAND);
            lv_obj_align(offsetLabel2, offsetSlider, LV_ALIGN_OUT_TOP_MID, 0, 0);                         /*Set its position*/
    
            
            
    /* Second Slider: Trigger */
    lv_obj_t * triggerSlider = lv_slider_create(lv_scr_act(), NULL);
    lv_obj_set_pos(triggerSlider, 170, 295);                         /*Set its position*/
    lv_obj_set_size(triggerSlider, 130, 30);                        /*Set its size*/
    lv_slider_set_value(triggerSlider, 5, LV_ANIM_ON);
    lv_obj_set_event_cb(triggerSlider, trigger_slider_event_cb);
    lv_slider_set_range(triggerSlider, 0, 10);
    
            /* Create a label below the slider */
            triggerLabel = lv_label_create(lv_scr_act(), NULL);
            lv_label_set_text(triggerLabel, "5");
            lv_obj_set_auto_realign(triggerLabel, true);
            lv_obj_align(triggerLabel, triggerSlider, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
            
            /* Create a label above the slider */
        	lv_obj_t* triggerLabel2 = lv_label_create(lv_scr_act(), NULL);
        	lv_obj_set_drag(triggerLabel2, false);
            lv_label_set_text(triggerLabel2, "Trigger: ");
            lv_obj_align(triggerLabel2, triggerSlider, LV_ALIGN_OUT_TOP_MID, 0, 0); 

    
            
    /* Third Slider: Hori. Scale */
    lv_obj_t * horiSlider = lv_slider_create(lv_scr_act(), NULL);
    lv_obj_set_pos(horiSlider, 20, 375);                         /*Set its position*/
    lv_obj_set_size(horiSlider, 130, 30);                        /*Set its size*/
    lv_slider_set_value(horiSlider, 4, LV_ANIM_ON);
    lv_obj_set_event_cb(horiSlider, hori_slider_event_cb);
    lv_slider_set_range(horiSlider, 0, 10);                      // 11 options for the 11 different data size posibilites
    
            /* Create a label below the slider */
            horiLabel1 = lv_label_create(lv_scr_act(), NULL);
            lv_label_set_text(horiLabel1, "5");
            lv_obj_set_auto_realign(horiLabel1, true);
            lv_obj_align(horiLabel1, horiSlider, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
            
            /* Create a label above the slider */
        	lv_obj_t* horiLabel2 = lv_label_create(lv_scr_act(), NULL);
        	lv_obj_set_drag(horiLabel2, false);
            lv_label_set_text(horiLabel2, "Hori. Scale: ");
            lv_obj_align(horiLabel2, horiSlider, LV_ALIGN_OUT_TOP_MID, 0, 0);
    
            
            
    /* Fourth Slider: Vert. Scale */
    lv_obj_t * vertSlider = lv_slider_create(lv_scr_act(), NULL);
    lv_obj_set_pos(vertSlider, 170, 375);                         /*Set its position*/
    lv_obj_set_size(vertSlider, 130, 30);                        /*Set its size*/
    lv_slider_set_value(vertSlider, 5, LV_ANIM_ON);
    lv_obj_set_event_cb(vertSlider, verti_slider_event_cb);
    lv_slider_set_range(vertSlider, 0, 10);
    
            /* Create a label below the slider */
            vertLabel1 = lv_label_create(lv_scr_act(), NULL);
            lv_label_set_text(vertLabel1, "5");
            lv_obj_set_auto_realign(vertLabel1, true);
            lv_obj_align(vertLabel1, vertSlider, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
            
            /* Create a label above the slider */
        	lv_obj_t* vertLabel2 = lv_label_create(lv_scr_act(), NULL);
        	lv_obj_set_drag(vertLabel2, false);
            lv_label_set_text(vertLabel2, "Vert. Scale: ");
            lv_obj_align(vertLabel2, vertSlider, LV_ALIGN_OUT_TOP_MID, 0, 0);
    
            
            
    /* Fifth Slider: Horizontal Window      Control Range of Points shown */
    lv_obj_t * windowSlider = lv_slider_create(lv_scr_act(), NULL);
    lv_obj_set_pos(windowSlider, 20, 225);                         /*Set its position*/
    lv_obj_set_size(windowSlider, 280, 30);                        /*Set its size*/
    lv_obj_set_event_cb(windowSlider, window_slider_event_cb);
    //lv_slider_set_range(windowSlider, 0, pow(2, cm4.HoriScale + 6));
    lv_slider_set_range(windowSlider, 0, 1024);        
    lv_slider_set_value(windowSlider, 512, LV_ANIM_ON);
    
            /* Create a label below the slider */
            windowLabel = lv_label_create(lv_scr_act(), NULL);
            lv_label_set_text(windowLabel, "512");
            lv_obj_set_auto_realign(windowLabel, true);
            lv_obj_align(windowLabel, windowSlider, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
    
            
            
    /* Display chart                         */        
    chart1 = lv_chart_create(lv_scr_act(), NULL);                     //Add a chart to the current screen
    //lv_obj_set_style(chart1, &style_box);                           //sets the style
    lv_obj_set_pos(chart1, chart_horiPos, chart_vertPos);             /*Set its position*/
    lv_obj_set_size(chart1, chart_width, chart_heigth);               /*Set its size*/   
    
    //GIVE IMPACT BASED ON THE VERT AND HORI SCALE
    lv_chart_set_div_line_count(chart1, 3, 4);                        //sets the grid lines
    
    lv_chart_set_point_count(chart1, 32);                              //setting the number of points on the chart
    lv_chart_set_type(chart1, LV_CHART_TYPE_POINT);                    //set graph to points, as opposed to lines
                                                                      

    lv_chart_series_t * s1 = lv_chart_add_series(chart1, lv_color_hex(0x01a2b1));
    
    // Need to calculate the desired indexes in RxBuffer, Based on HoriScale
    //always show 200 points, those points based on the window
    cm4.windowMin = cm4.windowPos - 100;
    cm4.windowMax = cm4.windowPos + 100;
    
    if(cm4.windowMin - 100 < 0){
        cm4.windowMax = (cm4.windowMin * -1) + cm4.windowMax;
        cm4.windowMin = 0;
    }
    //if(windowMax + 100 > pow(2, cm4.HoriScale + 6)){
    if(cm4.windowMax + 100 > 1024){
        //windowMin = windowMin - (windowMax - pow(2, cm4.HoriScale + 6)); 
        cm4.windowMin = cm4.windowMin - (cm4.windowMax - 1024); 
        //windowMax = pow(2, cm4.HoriScale + 6); 
        cm4.windowMax = 1024; 
    }
   
    //for(int i = cm4.windowMin; i < cm4.windowMax; ++i){
    for(int i = 0; i < 512; ++i){
        //lv_chart_set_next(chart1, s1, points[i]);
        //lv_chart_set_next(chart1, s1, cm4.RxBuffer[i] + cm4.Offset);
        lv_chart_set_next(chart1, s1, cm4.RxBuffer[i]);
    }
    
    
    
    //Adding an on/off switch 
    lv_obj_t * sw1 = lv_sw_create(lv_scr_act(), NULL);
    lv_obj_align(sw1, NULL, LV_ALIGN_CENTER, 0, -50);
    lv_obj_set_event_cb(sw1, sw_event_handler);
    //lv_obj_set_event_cb(sw1,  breath_activity_action);             /*Assign a callback to the button*/
    lv_obj_set_pos(sw1, 70, 440);                         /*Set its position*/
    lv_obj_set_size(sw1, 90, 30);               /*Set its size*/ 
    
    lv_obj_t * switchLabel = lv_label_create(lv_scr_act(), NULL);
	lv_obj_set_drag(switchLabel, false);
    lv_label_set_text(switchLabel, "On\\Off");
    //lv_obj_set_pos(switchLabel, 15, 445);
    lv_obj_align(switchLabel, sw1, LV_ALIGN_OUT_LEFT_MID, 0, 0);
}