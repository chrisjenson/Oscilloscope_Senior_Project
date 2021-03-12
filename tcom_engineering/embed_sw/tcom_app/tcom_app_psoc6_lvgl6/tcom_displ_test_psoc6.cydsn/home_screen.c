#include <stdio.h>

#include "project.h"
#include "globalStruct.h"
#include "lvgl.h"
#include "home_screen.h"
#include "slider_activity.h"
#include "math.h"

const uint8_t tcnj_blue[] = { 41, 63, 111 };
const uint8_t tcnj_gold[] = { 166, 122, 0 };

static lv_obj_t * offsetLabel;
static lv_obj_t * triggerLabel;
static lv_obj_t * horiLabel1;
static lv_obj_t * vertLabel1;
static lv_obj_t * windowLabel;

int startup = 0;

static void chart_actions()
{    
    const int chart_width = 280;
    const int chart_heigth = 200;
    const int chart_vertPos = 20;
    const int chart_horiPos = 20;  
    

    static lv_obj_t *chart1;        //declaring the chart
    if(startup == 1){
        lv_obj_del(chart1);
    }   
    
    /* Display chart                         */        
    chart1 = lv_chart_create(lv_scr_act(), NULL);                     //Add a chart to the current screen
    lv_obj_set_pos(chart1, chart_horiPos, chart_vertPos);             /*Set its position*/
    lv_obj_set_size(chart1, chart_width, chart_heigth);               /*Set its size*/ 
    
    //GIVE IMPACT BASED ON THE VERT AND HORI SCALE
    lv_chart_set_div_line_count(chart1, cm4.HoriScale+2, cm4.VertScale+2);  //sets the grid lines, hori, verti
    
    //GIVE IMPACT BASED ON THE VERT AND HORI SCALE
    lv_chart_set_point_count(chart1, cm4.windowSize);                              //setting the number of points on the chart
    lv_chart_set_type(chart1, LV_CHART_TYPE_POINT);                    //set graph to points, as opposed to lines    
    
    //Have the chart only display the current serie
    lv_chart_series_t * s1 = lv_chart_add_series(chart1, lv_color_hex(0x01a2b1));
    
    lv_chart_clear_serie(chart1, s1);
    lv_chart_refresh(chart1);
    
    
    // Need to calculate the desired indexes in RxBuffer, Based on HoriScale
    int windowMin = cm4.windowPos - 64;
    int windowMax = cm4.windowPos + 64;
    
    if(windowMin < 0){
        windowMax = (windowMin * -1) + windowMax;
        windowMin = 0;
    }
    //if(windowMax + 100 > pow(2, cm4.HoriScale + 6)){
    if(windowMax > 1024){
        //windowMin = windowMin - (windowMax - pow(2, cm4.HoriScale + 6)); 
        windowMin = windowMin - (windowMax - 1024); 
        //windowMax = pow(2, cm4.HoriScale + 6); 
        windowMax = 1024; 
    }

    //draw the series
    for(int i = windowMin; i < windowMax; ++i){
        lv_chart_set_next(chart1, s1, cm4.RamReadBuffer[i] + cm4.Offset);
    }   
    startup = 1;
}

static void roller_event(lv_obj_t * obj, lv_event_t event)
{
    if(event == (LV_EVENT_VALUE_CHANGED)) {
        char buf[32];
        lv_roller_get_selected_str(obj, buf, sizeof(buf));
    }
}
static void sw_event_handler(lv_obj_t * obj, lv_event_t event)
{
    if(event == (LV_EVENT_VALUE_CHANGED)) {
        printf("State: %s\n", lv_sw_get_state(obj) ? "On" : "Off");
        //cm4.onBit = !cm4.onBit;
    }
}
static void offset_slider_event_cb(lv_obj_t * slider, lv_event_t event)
{
    if(event == (LV_EVENT_VALUE_CHANGED)) {
        static char buf[4]; /* max 3 bytes for number plus 1 null terminating byte */
        snprintf(buf, 4, "%u", lv_slider_get_value(slider));
        lv_label_set_text(offsetLabel, buf);
        cm4.Offset = lv_slider_get_value(slider);
        chart_actions();    //call to update the chart
    }
}
static void trigger_slider_event_cb(lv_obj_t * slider, lv_event_t event)
{
    if(event == (LV_EVENT_VALUE_CHANGED)) {
        static char buf[4]; /* max 3 bytes for number plus 1 null terminating byte */
        snprintf(buf, 4, "%u", lv_slider_get_value(slider));
        lv_label_set_text(triggerLabel, buf);
        cm4.Trigger = lv_slider_get_value(slider);
        chart_actions();    //call to update the chart
    }
}
static void hori_slider_event_cb(lv_obj_t * slider, lv_event_t event)
{
    if(event == (LV_EVENT_VALUE_CHANGED)) {
        static char buf[4]; /* max 3 bytes for number plus 1 null terminating byte */
        snprintf(buf, 4, "%u", lv_slider_get_value(slider));
        lv_label_set_text(horiLabel1, buf);
        cm4.HoriScale = lv_slider_get_value(slider);
        chart_actions();    //call to update the chart
    }
}
static void verti_slider_event_cb(lv_obj_t * slider, lv_event_t event)
{
    if(event == (LV_EVENT_VALUE_CHANGED)) {
        static char buf[4]; /* max 3 bytes for number plus 1 null terminating byte */
        snprintf(buf, 4, "%u", lv_slider_get_value(slider));
        lv_label_set_text(vertLabel1, buf);
        cm4.VertScale = lv_slider_get_value(slider);
        chart_actions();    //call to update the chart
    }
}
static void window_slider_event_cb(lv_obj_t * slider, lv_event_t event)
{
    if(event == (LV_EVENT_VALUE_CHANGED)) {
        static char buf[6]; /* max 3 bytes for number plus 1 null terminating byte */
        snprintf(buf, 6, "%u", lv_slider_get_value(slider));
        lv_label_set_text(windowLabel, buf);
        cm4.windowPos = lv_slider_get_value(slider);
        chart_actions();    //call to update the chart
    }
}

void home_screen()
{    
    /* First Slider: Offset */
    lv_obj_t * offsetSlider = lv_slider_create(lv_scr_act(), NULL);
    lv_obj_set_pos(offsetSlider, 20, 295);                         /*Set its position*/
    lv_obj_set_size(offsetSlider, 130, 30);                        /*Set its size*/
    lv_slider_set_value(offsetSlider, 0, LV_ANIM_ON);
    lv_obj_set_event_cb(offsetSlider, offset_slider_event_cb);
    lv_slider_set_range(offsetSlider, 0, 10);
        
            /* Create a label below the slider */
            offsetLabel = lv_label_create(lv_scr_act(), NULL);
            lv_label_set_text(offsetLabel, "0");
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
    lv_slider_set_range(horiSlider, 0, 8);                      // 11 options for the 11 different data size posibilites
    
            /* Create a label below the slider */
            horiLabel1 = lv_label_create(lv_scr_act(), NULL);
            lv_label_set_text(horiLabel1, "4");
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
    lv_slider_set_value(vertSlider, 2, LV_ANIM_ON);
    lv_obj_set_event_cb(vertSlider, verti_slider_event_cb);
    lv_slider_set_range(vertSlider, 0, 4);
    
            /* Create a label below the slider */
            vertLabel1 = lv_label_create(lv_scr_act(), NULL);
            lv_label_set_text(vertLabel1, "2");
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
            
            
    //Draw the ogriginal chart... should be empty or zeroes
    cm4.windowSize = 128;
    chart_actions();
            
    
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
    
    
    
    //Adding a drop down menu for the trigger slope
    lv_obj_t * roller1 = lv_roller_create(lv_scr_act(),NULL);
    lv_roller_set_options(roller1, "Rising\n"
                                  "Falling\n"
                                  "Threshold",
                                  LV_ROLLER_MODE_INIFINITE);
    lv_roller_set_visible_row_count(roller1, 3);
    lv_obj_set_pos(roller1, 170, 440);                         /*Set its position*/
    lv_obj_set_event_cb(roller1, roller_event);
   
}