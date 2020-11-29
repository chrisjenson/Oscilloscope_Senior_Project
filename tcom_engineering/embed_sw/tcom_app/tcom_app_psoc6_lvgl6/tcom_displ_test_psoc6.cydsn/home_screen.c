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

int SPIflag = 0;        //If you want to send a command, set the flag high

static void sw_event_handler(lv_obj_t * obj, lv_event_t event)
{
    if(event == LV_EVENT_CLICKED) {
        printf("State: %s\n", lv_sw_get_state(obj) ? "On" : "Off");
        //lv_sw_toggle(obj, LV_ANIM_ON);
        //SPIflag = !SPIflag;
    }
}

static void slider_event_cb(lv_obj_t * slider, lv_event_t event)
{
    if(event == LV_EVENT_VALUE_CHANGED) {
        static char buf[4]; /* max 3 bytes for number plus 1 null terminating byte */
        snprintf(buf, 4, "%u", lv_slider_get_value(slider));
        //lv_label_set_text(slider_label, buf);
    }
}


void home_screen()
{
    const int chart_width = 280;
    const int chart_heigth = 200;
    const int chart_vertPos = 20;
    const int chart_horiPos = 20;      
    
    char read_test[] = "0000000000000000";
    
    static lv_obj_t *my_label;
    static lv_style_t *lbl_style;
    
    static lv_obj_t *chart1;        //declaring the chart
    
    // SPI TEST CODE //
   
    //uunt16 because of the command size
    //uint16_t txBuffer[BUFFER_SIZE];
    uint16_t txBuffer[3];
    uint8_t RxBuffer[3];
    //int SPIflag = 0;        //If you want to send a command, set the flag high
    int readArray_SIZE = 16;
    
    /* Initialize txBuffer with command to transfer */
    //txBuffer[0] = CMD_START_TRANSFER;
    RxBuffer[0] = 0b11111111; //Junk value 100 01001 11111111
    txBuffer[0] = 0b0100010000000000; //010 00100 1111111 command to write 11111111 to reg 4
    //txBuffer[1] = 0b0100010011111111; //010 00001 01010101 command to write 01010101 to reg 1
    txBuffer[1] = 0b0010001100000000; //001 00011 00000000 command to read reg 4
    txBuffer[2] = 0b0010010011111111; //010 00001 01010101 command to read 01010101 to reg 1
    
    // Command to be sent
    //if(SPIflag){
        /* Master: start a transfer. Slave: prepare for a transfer. */
        //for(int i = 0; i < 1; ++i){
        //    while(!(Cy_SCB_SPI_GetTxFifoStatus(SPIM_HW) & CY_SCB_SPI_TX_EMPTY)){}
        //    Cy_SCB_SPI_Write(SPIM_HW, txBuffer[1]);

        //    CyDelay(1);

        //    while(!(Cy_SCB_SPI_GetRxFifoStatus(SPIM_HW) & CY_SCB_SPI_RX_NOT_EMPTY)){}
        //    RxBuffer[0] = Cy_SCB_SPI_Read(SPIM_HW);
        //}
        //SPIflag = 0;
    //}
    
    //uint8_t spi_dat = RxBuffer[0];
    //char my_str[256];
    //sprintf(my_str, 'Received %02X', spi_dat);
    /* Handle results of a transfer */    
    
    //Create a label to display the value read in
    lv_obj_t* readLabel = lv_label_create(lv_scr_act(), NULL);
	lv_obj_set_drag(readLabel, false);
	//lv_label_set_text(readLabel, my_str);
    lv_label_set_text(readLabel, read_test);
    lv_obj_set_pos(readLabel, 115, 430);                         /*Set its position*/
    
   
    // END SPI TEST CODE //
    
    
    /*===========LEGACY CODE==============//
    static lv_obj_t *btn1;
    static lv_obj_t *btn2;
    static lv_obj_t *btn3;
    static lv_obj_t *btn4;
    static lv_obj_t *btn_dat;
    static lv_obj_t *btn_tim;
    
    static lv_style_t btn_style1;
    static lv_style_t btn_style2;
    static lv_style_t btn_style3;
    static lv_style_t btn_style4;
    static lv_style_t btn_style_tim_dat;
    
    static lv_obj_t *label1;
    static lv_obj_t *label2;
    static lv_obj_t *label3;
    static lv_obj_t *label4;
    
    static lv_obj_t *label_dat;
    static lv_obj_t *label_tim;
     //=========END LEGACY CODE==========*/
    
    
    //TRY A DROP DOWN LIST FOR SOME OF THESE
    // https://docs.lvgl.io/v6/en/html/object-types/ddlist.html
    
    
    //static lv_style_t style_test;
    //style_test.text.font = &lv_font_roboto_22;
    
    //lbl_style = lv_label_get_style(my_label, LV_LABEL_STYLE_MAIN);
    //lbl_style->text.color.full = 0x000000;
    
    /* First Slider: Offset */
    lv_obj_t * offsetSlider = lv_slider_create(lv_scr_act(), NULL);
    lv_obj_set_pos(offsetSlider, 20, 270);                         /*Set its position*/
    lv_obj_set_size(offsetSlider, 130, 35);                        /*Set its size*/
    lv_slider_set_value(offsetSlider, 50, LV_ANIM_ON);
    lv_obj_set_event_cb(offsetSlider, slider_event_cb);
    lv_slider_set_range(offsetSlider, 0, 100);
    
    /* Create a label below the slider */
    lv_obj_t * offsetLabel = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_text(offsetLabel, "0");
    lv_obj_set_auto_realign(offsetLabel, true);
    lv_obj_align(offsetLabel, offsetSlider, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
    
    /* Create a label above the slider */
	lv_obj_t* offsetLabel2 = lv_label_create(lv_scr_act(), NULL);
	lv_obj_set_drag(offsetLabel2, false);
    lv_label_set_text(offsetLabel2, "Offset");
    lv_obj_set_pos(offsetLabel2, 20, 240);                         /*Set its position*/
    
    
    /* Second Slider: Gain */
    lv_obj_t * gainSlider = lv_slider_create(lv_scr_act(), NULL);
    lv_obj_set_pos(gainSlider, 170, 270);                         /*Set its position*/
    lv_obj_set_size(gainSlider, 130, 35);                        /*Set its size*/
    lv_slider_set_value(gainSlider, 50, LV_ANIM_ON);
    lv_obj_set_event_cb(gainSlider, slider_event_cb);
    lv_slider_set_range(gainSlider, 0, 100);
    
    /* Create a label below the slider */
    lv_obj_t * gainLabel = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_text(gainLabel, "0");
    lv_obj_set_auto_realign(gainLabel, true);
    lv_obj_align(gainLabel, gainSlider, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
    
	lv_obj_t* gainLabel2 = lv_label_create(lv_scr_act(), NULL);
	lv_obj_set_drag(gainLabel2, false);
    lv_label_set_text(gainLabel2, "Gain");
    lv_obj_set_pos(gainLabel2, 170, 240); 

    
    /* Third Slider: Hori. Scale */
    lv_obj_t * horiSlider = lv_slider_create(lv_scr_act(), NULL);
    lv_obj_set_pos(horiSlider, 20, 360);                         /*Set its position*/
    lv_obj_set_size(horiSlider, 130, 35);                        /*Set its size*/
    lv_slider_set_value(horiSlider, 50, LV_ANIM_ON);
    lv_obj_set_event_cb(horiSlider, slider_event_cb);
    lv_slider_set_range(horiSlider, 0, 100);
    
    /* Create a label below the slider */
    lv_obj_t * horiLabel1 = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_text(horiLabel1, "0");
    lv_obj_set_auto_realign(horiLabel1, true);
    lv_obj_align(horiLabel1, horiSlider, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
    
	lv_obj_t* horiLabel2 = lv_label_create(lv_scr_act(), NULL);
	lv_obj_set_drag(horiLabel2, false);
    lv_label_set_text(horiLabel2, "Hori. Scale");
    lv_obj_set_pos(horiLabel2, 20, 340);                         /*Set its position*/

    
    /* Fourth Slider: Vert. Scale */
    lv_obj_t * vertSlider = lv_slider_create(lv_scr_act(), NULL);
    lv_obj_set_pos(vertSlider, 170, 360);                         /*Set its position*/
    lv_obj_set_size(vertSlider, 130, 35);                        /*Set its size*/
    lv_slider_set_value(vertSlider, 50, LV_ANIM_ON);
    lv_obj_set_event_cb(vertSlider, slider_event_cb);
    lv_slider_set_range(vertSlider, 0, 100);
    
    /* Create a label below the slider */
    lv_obj_t * vertLabel1 = lv_label_create(lv_scr_act(), NULL);
    lv_label_set_text(vertLabel1, "0");
    lv_obj_set_auto_realign(vertLabel1, true);
    lv_obj_align(vertLabel1, vertSlider, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
    
	lv_obj_t* vertLabel2 = lv_label_create(lv_scr_act(), NULL);
	lv_obj_set_drag(vertLabel2, false);
    lv_label_set_text(vertLabel2, "Vert. Scale");
    lv_obj_set_pos(vertLabel2, 170, 340); 
    
    
    
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
    lv_obj_t *sw1 = lv_sw_create(lv_scr_act(), NULL);
    lv_obj_align(sw1, NULL, LV_ALIGN_CENTER, 0, -50);
    lv_obj_set_event_cb(sw1, sw_event_handler);
    //lv_obj_set_event_cb(sw1,  breath_activity_action);             /*Assign a callback to the button*/
    lv_obj_set_pos(sw1, 20, 430);                         /*Set its position*/
    lv_obj_set_size(sw1, 90, 35);               /*Set its size*/ 
    
    
    //=======================LEGACY CODE==========================================//
    
    //btn1 = lv_btn_create(lv_scr_act(), NULL);                       /*Add a button the current screen*/
    //lv_obj_set_pos(btn1, h_lab_1, v_lab_1);                         /*Set its position*/
    //lv_obj_set_size(btn1, btn_wid, btn_hgt);                        /*Set its size*/
    //lv_obj_set_event_cb(btn1,  breath_activity_action);             /*Assign a callback to the button*/
    //label1 = lv_label_create(btn1, NULL);                           /*Add a label to the button*/
    //my_label = label1;                                              /*Gets the value of label1*/
    //lv_label_set_text(my_label, co_btn_txt);                        /*Set the label's text string*/
    //lv_label_set_align(my_label, LV_LABEL_ALIGN_CENTER );           /*Set the label's alignment*/

    //lbl_style = lv_label_get_style(my_label, LV_LABEL_STYLE_MAIN);  /*Get a pointer to label1's style.  Since the label's style was NULL, it
      //                                                                actually returns the parent's style (i.e. the active screen!)*/
    //lbl_style->text.color.full = 0x000000;                          /*Set label1's text color to black*/
    
    //btn2 = lv_btn_create(lv_scr_act(), NULL);                       /*Add a button the current screen*/
    //lv_obj_set_pos(btn2, h_lab_2, v_lab_1);                         /*Set its position*/
    //lv_obj_set_size(btn2, btn_wid, btn_hgt);                        /*Set its size*/
    //lv_obj_set_event_cb(btn2,  breath_activity_action);             /*Assign a callback to the button*/
    //label2 = lv_label_create(btn2, NULL);                           /*Add a label to the button*/
    //my_label = label2;
    //lv_label_set_text(my_label, gam_btn_txt);                       /*Set the label's text*/
    //lv_label_set_align(my_label, LV_LABEL_ALIGN_CENTER );

    //btn3 = lv_btn_create(lv_scr_act(), NULL);                       /*Add a button the current screen*/
    //lv_obj_set_pos(btn3, h_lab_1, v_lab_2);                         /*Set its position*/
    //lv_obj_set_size(btn3, btn_wid, btn_hgt);                        /*Set its size*/
    //lv_obj_set_event_cb(btn3,  breath_activity_action);             /*Assign a callback to the button*/
    //label3 = lv_label_create(btn3, NULL);                           /*Add a label to the button*/
    //my_label = label3;
    //lv_label_set_text(my_label, msg_btn_txt);                       /*Set the label's text*/
    //lv_label_set_align(my_label, LV_LABEL_ALIGN_CENTER );

    //btn4 = lv_btn_create(lv_scr_act(), NULL);                       /*Add a button the current screen*/
    //lv_obj_set_pos(btn4, h_lab_2, v_lab_2);                         /*Set its position*/
    //lv_obj_set_size(btn4, btn_wid, btn_hgt);                        /*Set its size*/
    //lv_obj_set_event_cb(btn4,  breath_activity_action);             /*Assign a callback to the button*/
    //label4 = lv_label_create(btn4, NULL);                           /*Add a label to the button*/
    //my_label = label4;
    //lv_label_set_text(my_label, ci_btn_txt);                        /*Set the label's text*/
    //lv_label_set_align(my_label, LV_LABEL_ALIGN_CENTER );

    //lv_style_copy(&btn_style1, lv_obj_get_style(btn1));
    //lv_style_copy(&btn_style2, lv_obj_get_style(btn2));
    //lv_style_copy(&btn_style3, lv_obj_get_style(btn3));
    //lv_style_copy(&btn_style4, lv_obj_get_style(btn4));
    
    //btn_style1.body.main_color.full = 0x0040C0;
    //btn_style1.body.grad_color.full = btn_style1.body.main_color.full;
    //lv_btn_set_style( btn1, LV_BTN_STATE_REL, &btn_style1 );
    
    //btn_style2.body.main_color.full = 0xC04000;
    //btn_style2.body.grad_color.full = btn_style2.body.main_color.full;
    //lv_btn_set_style( btn2, LV_BTN_STATE_REL, &btn_style2 );
    
    //btn_style3.body.main_color.full = 0x00C040;
    //btn_style3.body.grad_color.full = btn_style3.body.main_color.full;
    //lv_btn_set_style( btn3, LV_BTN_STATE_REL, &btn_style3 );
    
    //btn_style4.body.main_color.full = 0x40C000;
    //btn_style4.body.grad_color.full = btn_style4.body.main_color.full;
    //lv_btn_set_style( btn4, LV_BTN_STATE_REL, &btn_style4 );

    //btn_dat = lv_btn_create(lv_scr_act(), NULL);                        /*Add a button the current screen*/
    //lv_obj_set_pos(btn_dat, h_ban_1, v_ban_1);                          /*Set its position*/
    //lv_obj_set_size(btn_dat, ban_wid, ban_hgt);                         /*Set its size*/
    //lv_obj_set_event_cb(btn_dat,  date_activity_action);                /*Assign a callback to the button*/
    //label_dat = lv_label_create(btn_dat, NULL);
    //lv_label_set_text( label_dat, "Wednesday, January 20  2021" );
    //lv_obj_align( label_dat, NULL, LV_ALIGN_IN_TOP_MID, 0,0 );
    //set_label_dat(label_dat);
    //lv_label_set_long_mode(label_dat, LV_LABEL_LONG_EXPAND);
    
    //btn_tim = lv_btn_create(lv_scr_act(), NULL);                        /*Add a button the current screen*/
    //lv_obj_set_pos(btn_tim, h_ban_1, v_ban_2);                          /*Set its position*/
    //lv_obj_set_size(btn_tim, ban_wid, ban_hgt);                         /*Set its size*/
    //lv_obj_set_event_cb(btn_tim,  time_activity_action);                /*Assign a callback to the button*/
    //label_tim = lv_label_create(btn_tim, NULL);
    //lv_label_set_static_text( label_tim, "12:00 AM" );
    //lv_obj_align( label_tim, NULL, LV_ALIGN_IN_TOP_MID, 0,0 );
    //set_label_tim(label_tim);
    
    
    //lv_style_copy(&btn_style_tim_dat, lv_obj_get_style(btn_dat));
    //btn_style_tim_dat.text.font = &lv_font_roboto_16;
    //btn_style_tim_dat.body.main_color.full = 0xFFFFFF;
    //btn_style_tim_dat.body.grad_color.full = 0xFFFFFF;
    //lv_btn_set_style( btn_dat, LV_BTN_STATE_REL, &btn_style_tim_dat );
    //lv_btn_set_style( btn_tim, LV_BTN_STATE_REL, &btn_style_tim_dat );
    
    //=======================LEGACY CODE==========================================//    
}