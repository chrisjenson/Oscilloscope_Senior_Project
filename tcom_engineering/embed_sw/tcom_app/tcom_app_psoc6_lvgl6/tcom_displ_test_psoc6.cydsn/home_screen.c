#include <stdio.h>

#include "project.h"
#include "lvgl.h"
#include "home_screen.h"
#include "breath_activity.h"
#include "time_date_activity.h"
#include "slider_activity.h"

//#define DO_IMAGES
#ifdef DO_IMAGES
#include "blow.c"
#include "message.c"
#include "ribbons.c"
#include "team.c"
#endif

const uint8_t tcnj_blue[] = { 41, 63, 111 };
const uint8_t tcnj_gold[] = { 166, 122, 0 };


void home_screen()
{
    const int chart_width = 280;
    const int chart_heigth = 200;
    const int chart_vertPos = 20;
    const int chart_horiPos = 20;    
    
    const int h_lab_1 =  20;
    const int h_lab_2 = 170;
    
    const int v_lab_1 =  280;
    const int v_lab_2 = 370;    
    
#ifdef DO_IMAGES
    const int v_img_1 = 120;
    const int v_img_2 = 330;
#endif
    
    //const char  off_slide_txt[]  = "Offset";
    const char gain_slide_txt[] = "Gain";
    const char vert_slide_txt[] = "Vert. Scale";
    const char hori_slide_txt[]  = "Hori. Scale";
    
    char read_test[] = "0000000000000000";
    
    const int  btn_wid       = 130;
    //const int  btn_hgt       = 50;
    const int  btn_hgt       = 35;
    
    static lv_obj_t *my_label;
    static lv_style_t *lbl_style;
    
    static lv_obj_t *chart1;        //declaring the chart
    
    
    // SPI TEST CODE //
   
    //uunt16 because of the command size
    //uint16_t txBuffer[BUFFER_SIZE];
    uint16_t txBuffer[3];
    uint16_t RxBuffer[3];
    int SPIflag = 1;        //If you want to send a command, set the flag high
    
    /* Initialize txBuffer with command to transfer */
    RxBuffer[0] = 0b1111111111111111; //Junk value
    txBuffer[0] = 0b0100000000000000; //010 00000 00000000 command to write 00 to reg 0
    txBuffer[1] = 0b0010000000000000; //001 00000 00000000 command to read reg 0
    txBuffer[2] = 0b1111111111111111; // JUNK at present
    uint16_t tempRead;
    
    // Command to be sent
    if(SPIflag){
    /* Master: start a transfer. Slave: prepare for a transfer. */
        while(!(Cy_SCB_SPI_GetTxFifoStatus(SPIM_HW) & CY_SCB_SPI_TX_EMPTY)){}
        Cy_SCB_SPI_Write(SPIM_HW, txBuffer[0]);
       
        CyDelay(1);
       
        while(!(Cy_SCB_SPI_GetRxFifoStatus(SPIM_HW) & CY_SCB_SPI_RX_NOT_EMPTY)){}
        RxBuffer[0] = Cy_SCB_SPI_Read(SPIM_HW);
        //RxBuffer[0] = 0b0010111100101111;
        
        //Get the first 3 bits, the CMD, to know what is being done.
        char CMD = (txBuffer[1] >> 13) & 7;

        //Read from reg
        if(CMD == 1){
            tempRead = RxBuffer[0];
        }
        //Write to reg
        else if(CMD == 2){
        
        }
        //Read sample data
        else if(CMD == 3){
        
        }
       
        SPIflag = 0;
    }
    /* Handle results of a transfer */    
    
    //Create a label to display the value read in
    lv_obj_t* readLabel = lv_label_create(lv_scr_act(), NULL);
	lv_obj_set_drag(readLabel, false);
	lv_label_set_text(readLabel, read_test);
    lv_obj_set_pos(readLabel, 115, v_lab_2+40);                         /*Set its position*/
    
   
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
    
    //First Slider
	lv_obj_t* offsetLabel = lv_label_create(lv_scr_act(), NULL);
	lv_obj_set_drag(offsetLabel, false);
	//lv_label_set_text(offsetLabel, off_slide_txt);
    lv_label_set_text(offsetLabel, "Offset");
    lv_obj_set_pos(offsetLabel, h_lab_1, v_lab_1-40);                         /*Set its position*/
    
    lv_obj_t* offsetSlide = lv_slider_create(lv_scr_act(), NULL);
	lv_obj_set_drag(offsetSlide, false);
	lv_slider_set_value(offsetSlide, 50, LV_ANIM_OFF);
    lv_obj_set_pos(offsetSlide, h_lab_1, v_lab_1);                         /*Set its position*/
    lv_obj_set_size(offsetSlide, btn_wid, btn_hgt);                        /*Set its size*/
	//lv_obj_set_event_cb(offsetSlide, slider_action);
   
    //Second Slider
	lv_obj_t* gainLabel = lv_label_create(lv_scr_act(), NULL);
	lv_obj_set_drag(gainLabel, false);
	lv_label_set_text(gainLabel, gain_slide_txt);
    lv_obj_set_pos(gainLabel, h_lab_2, v_lab_1-30);                         /*Set its position*/
    
    lv_obj_t* gainSlide = lv_slider_create(lv_scr_act(), NULL);
	lv_obj_set_drag(gainSlide, false);
	lv_slider_set_value(gainSlide, 50, LV_ANIM_OFF);
    lv_obj_set_pos(gainSlide, h_lab_2, v_lab_1);                         /*Set its position*/
    lv_obj_set_size(gainSlide, btn_wid, btn_hgt);                        /*Set its size*/
	//lv_obj_set_event_cb(gainSlide, slider_action);
    
    //Third Slider
	lv_obj_t* horiLabel = lv_label_create(lv_scr_act(), NULL);
	lv_obj_set_drag(horiLabel, false);
	lv_label_set_text(horiLabel, vert_slide_txt);
    lv_obj_set_pos(horiLabel, h_lab_1, v_lab_2-30);                         /*Set its position*/
    
    lv_obj_t* horiSlide = lv_slider_create(lv_scr_act(), NULL);
	lv_obj_set_drag(horiSlide, false);
	lv_slider_set_value(horiSlide, 50, LV_ANIM_OFF);
    lv_obj_set_pos(horiSlide, h_lab_1, v_lab_2);                         /*Set its position*/
    lv_obj_set_size(horiSlide, btn_wid, btn_hgt);                        /*Set its size*/
	//lv_obj_set_event_cb(offsetSlide, slider_action);
   
    //Fourth Slider
	lv_obj_t* vertLabel = lv_label_create(lv_scr_act(), NULL);
	lv_obj_set_drag(vertLabel, false);
	lv_label_set_text(vertLabel, hori_slide_txt);
    lv_obj_set_pos(vertLabel, h_lab_2, v_lab_2-30);                         /*Set its position*/
    
    lv_obj_t* vertSlide = lv_slider_create(lv_scr_act(), NULL);
	lv_obj_set_drag(vertSlide, false);
	lv_slider_set_value(vertSlide, 50, LV_ANIM_OFF);
    lv_obj_set_pos(vertSlide, h_lab_2, v_lab_2);                         /*Set its position*/
    lv_obj_set_size(vertSlide, btn_wid, btn_hgt);                        /*Set its size*/
	//lv_obj_set_event_cb(gainSlide, slider_action);
    
    
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
    lv_chart_set_next(chart1, s1, 25);
    lv_chart_set_next(chart1, s1, 50);
    lv_chart_set_next(chart1, s1, 75);
    lv_chart_set_next(chart1, s1, 50);
    lv_chart_set_next(chart1, s1, 25);
    lv_chart_set_next(chart1, s1, 50);
    lv_chart_set_next(chart1, s1, 75);
    lv_chart_set_next(chart1, s1, 50);
    lv_chart_set_next(chart1, s1, 25);
    lv_chart_set_next(chart1, s1, 50);
    
    
    
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
    
    
    
    lv_task_t * task = lv_task_create(update_time_task, 1000, LV_TASK_PRIO_MID, NULL);

#ifdef DO_IMAGES

    static lv_obj_t *img1;
    static lv_obj_t *img2;
    static lv_obj_t *img3;
    static lv_obj_t *img4;
    
    img1 = lv_img_create(lv_scr_act(), NULL);
    lv_img_set_src(img1, &blow);
    lv_obj_align(img1, NULL, LV_ALIGN_IN_TOP_LEFT, h_lab_1, v_img_1);
    
    img2 = lv_img_create(lv_scr_act(), NULL);
    lv_img_set_src(img2, &ribbons);
    lv_obj_align(img2, NULL, LV_ALIGN_IN_TOP_LEFT, h_lab_2, v_img_1);
    
    img3 = lv_img_create(lv_scr_act(), NULL);
    lv_img_set_src(img3, &message);
    lv_obj_align(img3, NULL, LV_ALIGN_IN_TOP_LEFT, h_lab_1, v_img_2);
    
    img4 = lv_img_create(lv_scr_act(), NULL);
    lv_img_set_src(img4, &team);
    lv_obj_align(img4, NULL, LV_ALIGN_IN_TOP_LEFT, h_lab_2, v_img_2);

#endif
    
}