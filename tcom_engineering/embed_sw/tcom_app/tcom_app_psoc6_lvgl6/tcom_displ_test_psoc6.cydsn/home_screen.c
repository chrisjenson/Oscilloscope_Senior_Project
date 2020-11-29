#include <stdio.h>

#include "project.h"
#include "lvgl.h"
#include "home_screen.h"
#include "breath_activity.h"
#include "time_date_activity.h"
#include "slider_activity.h"

//static lv_obj_t * slider_label;

const uint8_t tcnj_blue[] = { 41, 63, 111 };
const uint8_t tcnj_gold[] = { 166, 122, 0 };

char offset_str[3];
//Linkning this to the structure in main_cm4.c
//extern struct SPI_parameters cm4;
static lv_obj_t * offsetLabel;
static lv_obj_t * triggerLabel;
static lv_obj_t * horiLabel1;
static lv_obj_t * vertLabel1;

uint8_t zeros = 0b00000000;

//int SPIflag = 0;        //If you want to send a command, set the flag high

static void sw_event_handler(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_CLICKED) {
        printf("State: %s\n", lv_sw_get_state(obj) ? "On" : "Off");
        //lv_sw_toggle(obj, LV_ANIM_ON);
        cm4.onBit = !cm4.onBit;
    }
}

static void offset_slider_event_cb(lv_obj_t * slider, lv_event_t event)
{
    if(event == LV_EVENT_VALUE_CHANGED) {
        static char buf[4]; /* max 3 bytes for number plus 1 null terminating byte */
        snprintf(buf, 4, "%u", lv_slider_get_value(slider));
        lv_label_set_text(offsetLabel, buf);
        int temp = (int)(buf);          //type cast the new slider value to an integer
        cm4.Offset = (zeros | temp);    //stores the new slider value in the global structure
    }
}
static void trigger_slider_event_cb(lv_obj_t * slider, lv_event_t event)
{
    if(event == LV_EVENT_VALUE_CHANGED) {
        static char buf[4]; /* max 3 bytes for number plus 1 null terminating byte */
        snprintf(buf, 4, "%u", lv_slider_get_value(slider));
        lv_label_set_text(triggerLabel, buf);
        int temp = (int)(buf);          //type cast the new slider value to an integer
        cm4.Gain = (zeros | temp);    //stores the new slider value in the global structure
    }
}
static void hori_slider_event_cb(lv_obj_t * slider, lv_event_t event)
{
    if(event == LV_EVENT_VALUE_CHANGED) {
        static char buf[4]; /* max 3 bytes for number plus 1 null terminating byte */
        snprintf(buf, 4, "%u", lv_slider_get_value(slider));
        lv_label_set_text(horiLabel1, buf);
        int temp = (int)(buf);          //type cast the new slider value to an integer
        cm4.HoriSCale = (zeros | temp);    //stores the new slider value in the global structure
    }
}
static void verti_slider_event_cb(lv_obj_t * slider, lv_event_t event)
{
    if(event == LV_EVENT_VALUE_CHANGED) {
        static char buf[4]; /* max 3 bytes for number plus 1 null terminating byte */
        snprintf(buf, 4, "%u", lv_slider_get_value(slider));
        lv_label_set_text(vertLabel1, buf);
        int temp = (int)(buf);          //type cast the new slider value to an integer
        cm4.VertScale = (zeros | temp);    //stores the new slider value in the global structure
    }
}

void home_screen()
{

    const int chart_width = 280;
    const int chart_heigth = 200;
    const int chart_vertPos = 20;
    const int chart_horiPos = 20;      
    
    //char read_test[] = "0000000000000000";
    
    static lv_obj_t *my_label;
    static lv_style_t *lbl_style;
    
    static lv_obj_t *chart1;        //declaring the chart
    
    //char gain_str[3];
    //sprintf(gain_str, "%02X", cm4.gain_label);
    
    /* First Slider: Offset */
    lv_obj_t * offsetSlider = lv_slider_create(lv_scr_act(), NULL);
    lv_obj_set_pos(offsetSlider, 20, 260);                         /*Set its position*/
    lv_obj_set_size(offsetSlider, 130, 35);                        /*Set its size*/
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
    lv_obj_set_pos(offsetLabel2, 20, 230);                         /*Set its position*/
    
    
    /* Second Slider: Trigger */
    lv_obj_t * triggerSlider = lv_slider_create(lv_scr_act(), NULL);
    lv_obj_set_pos(triggerSlider, 170, 260);                         /*Set its position*/
    lv_obj_set_size(triggerSlider, 130, 35);                        /*Set its size*/
    lv_slider_set_value(triggerSlider, 5, LV_ANIM_ON);
    lv_obj_set_event_cb(triggerSlider, trigger_slider_event_cb);
    lv_slider_set_range(triggerSlider, 0, 10);
    
    /* Create a label below the slider */
    triggerLabel = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_text(triggerLabel, "5");
    lv_obj_set_auto_realign(triggerLabel, true);
    lv_obj_align(triggerLabel, triggerSlider, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
    
	lv_obj_t* gainLabel2 = lv_label_create(lv_scr_act(), NULL);
	lv_obj_set_drag(gainLabel2, false);
    lv_label_set_text(gainLabel2, "Trigger");
    lv_obj_set_pos(gainLabel2, 170, 230); 

    
    /* Third Slider: Hori. Scale */
    lv_obj_t * horiSlider = lv_slider_create(lv_scr_act(), NULL);
    lv_obj_set_pos(horiSlider, 20, 360);                         /*Set its position*/
    lv_obj_set_size(horiSlider, 130, 35);                        /*Set its size*/
    lv_slider_set_value(horiSlider, 5, LV_ANIM_ON);
    lv_obj_set_event_cb(horiSlider, hori_slider_event_cb);
    lv_slider_set_range(horiSlider, 0, 10);
    
    /* Create a label below the slider */
    horiLabel1 = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_text(horiLabel1, "5");
    lv_obj_set_auto_realign(horiLabel1, true);
    lv_obj_align(horiLabel1, horiSlider, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
    
	lv_obj_t* horiLabel2 = lv_label_create(lv_scr_act(), NULL);
	lv_obj_set_drag(horiLabel2, false);
    lv_label_set_text(horiLabel2, "Hori. Scale :");
    lv_obj_set_pos(horiLabel2, 20, 330);                         /*Set its position*/

    
    /* Fourth Slider: Vert. Scale */
    lv_obj_t * vertSlider = lv_slider_create(lv_scr_act(), NULL);
    lv_obj_set_pos(vertSlider, 170, 360);                         /*Set its position*/
    lv_obj_set_size(vertSlider, 130, 35);                        /*Set its size*/
    lv_slider_set_value(vertSlider, 5, LV_ANIM_ON);
    lv_obj_set_event_cb(vertSlider, verti_slider_event_cb);
    lv_slider_set_range(vertSlider, 0, 10);
    
    /* Create a label below the slider */
    vertLabel1 = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_text(vertLabel1, "5");
    lv_obj_set_auto_realign(vertLabel1, true);
    lv_obj_align(vertLabel1, vertSlider, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
    
	lv_obj_t* vertLabel2 = lv_label_create(lv_scr_act(), NULL);
	lv_obj_set_drag(vertLabel2, false);
    lv_label_set_text(vertLabel2, "Vert. Scale :");
    lv_obj_set_pos(vertLabel2, 170, 330); 
    
    
    
    chart1 = lv_chart_create(lv_scr_act(), NULL);                     //Add a chart to the current screen
    //lv_obj_set_style(chart1, &style_box);                           //sets the style
    lv_obj_set_pos(chart1, chart_horiPos, chart_vertPos);                         /*Set its position*/
    lv_obj_set_size(chart1, chart_width, chart_heigth);               /*Set its size*/   
    lv_chart_set_div_line_count(chart1, 3, 0);                        //LOOK INTO ME
    lv_chart_set_point_count(chart1, 8);                              //setting the number of points on the chart
    lv_chart_set_type(chart1, LV_CHART_TYPE_LINE);                    //set the points to be connected by lines
                                                                      //CHANGE TO POINT ONCE MORE SAMPLES                                                                  

    lv_chart_series_t * s1 = lv_chart_add_series(chart1, lv_color_hex(0x01a2b1));
    //arbitary plot points that will eventually be set by info coming from the FPGA
    
    //temp sent to 8 to limit the number of points on screen. Will actually be somewhere in the hundreds
    
    //CHANGE ME ONCE IMPLEMENTED
    uint8 elementsRead = 8;
    
    int points[8] = {25, 50, 75, 50, 25, 50, 75, 50};
    for(int i = 0; i < elementsRead; ++i){
        lv_chart_set_next(chart1, s1, points[i]);
    }
    
    
    //Adding an on/off switch
	lv_obj_t* switchLabel = lv_label_create(lv_scr_act(), NULL);
	lv_obj_set_drag(switchLabel, false);
    lv_label_set_text(switchLabel, "on\\off");
    lv_obj_set_pos(switchLabel, 85, 430);
    
    lv_obj_t *sw1 = lv_sw_create(lv_scr_act(), NULL);
    lv_obj_align(sw1, NULL, LV_ALIGN_CENTER, 0, -50);
    lv_obj_set_event_cb(sw1, sw_event_handler);
    //lv_obj_set_event_cb(sw1,  breath_activity_action);             /*Assign a callback to the button*/
    lv_obj_set_pos(sw1, 170, 430);                         /*Set its position*/
    lv_obj_set_size(sw1, 90, 35);               /*Set its size*/ 
}