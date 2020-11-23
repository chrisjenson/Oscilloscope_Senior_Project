#include "project.h"
#include "lvgl.h"

#include "stdio.h"

#include "touchpad_glue.h"
#include "display_glue.h"
#include "home_screen.h"

//#include "yolo_tengo_310x480.h" 
//#include "swirly_80x120.h"

#define LED_ON              (0)
#define LED_OFF             (1)

uint32 msec_cnt = 0;


void Interrupt_Handler_DISP_TICK(void)
{
    lv_tick_inc(1);
    
    ++msec_cnt;
    if (msec_cnt == 1000)
    {
        msec_cnt = 0;
    }
    
    DISP_TICK_TIMER_GetStatus();
    /* Clear the interrupt */
    DISP_TICK_TIMER_ClearInterrupt(CY_TCPWM_INT_ON_TC);
}

extern cy_stc_scb_i2c_context_t I2C_MASTER_context;


int
main( void )
{
    GPIO_PRT_Type   *port_addr;
    
    lv_disp_drv_t   disp_drv;
    lv_disp_buf_t   disp_buf;
    lv_disp_t       *disp;
    lv_color_t      buf_rendering[LV_HOR_RES_MAX * 48];

    lv_indev_drv_t  indev_drv;
    lv_indev_t      *my_indev;
    
    __enable_irq(); /* Enable global interrupts. */

    /* Initialize the interrupt with vector at Interrupt_Handler_Port0() */
    Cy_SysInt_Init(&DISP_TICK_ISR_cfg, &Interrupt_Handler_DISP_TICK);
    /* Enable the interrupt */
    NVIC_EnableIRQ(DISP_TICK_ISR_cfg.intrSrc);
    
//    CLOCK_2_Enable();
    SPIM_Start();
    LCD_INTERFACE_Start();
    I2C_MASTER_Start();
    DISP_TICK_TIMER_Start();
//    UART_KITPROG_USB_Start();    
    
    lv_init();
    ili9488_init();
    
//    UART_KITPROG_USB_PutString( "Hello, world!\r\n" );

    //Cy_GPIO_Write(USER_LED_GRN_PORT, USER_LED_GRN_NUM, LED_ON);
    //Cy_GPIO_Write(USER_LED_RED_PORT, USER_LED_RED_NUM, LED_ON);
    
    lv_theme_t *th = lv_theme_material_init(30, &lv_font_roboto_22);       //Set a HUE value and a Font for the Night Theme
    lv_theme_set_current(th);                                               //Apply the theme

    lv_disp_buf_init(&disp_buf, buf_rendering, NULL, LV_HOR_RES_MAX * 48);

    lv_disp_drv_init(&disp_drv); /*Basic initialization*/
    disp_drv.buffer = &disp_buf; /*Set an initialized buffer*/
    disp_drv.flush_cb = my_flush_cb; /*Set a flush callback to draw to the display*/
    disp = lv_disp_drv_register(&disp_drv); /*Register the driver and save the created display objects*/
    
    lv_indev_drv_init(&indev_drv);                  // Descriptor of a input device driver
    indev_drv.type      = LV_INDEV_TYPE_POINTER;    /*Touch pad is a pointer-like device*/
    indev_drv.read_cb   = touchpad_read;            /*Set your driver function*/
    my_indev            = lv_indev_drv_register(&indev_drv);         /*Finally register the driver*/
    lv_indev_init();
    
    /* Set the port address */
    port_addr = GPIO_PRT6;

    // P6_2 (Backlight control)
    CY_SET_REG32(&port_addr->OUT, _CLR_SET_FLD32U(port_addr->OUT, GPIO_PRT_OUT_OUT2, 1u));
    
    home_screen();
    
    
    
     // SPI TEST CODE //
   
    //uunt16 because of the command size
    //uint16_t txBuffer[BUFFER_SIZE];
    //uint16_t txBuffer[3];
    //uint16_t RxBuffer[3];
   
    /* Initialize txBuffer with command to transfer */
    //txBuffer[0] = CMD_START_TRANSFER;
    //RxBuffer[0] = 0x200U; //Junk value
    //txBuffer[0] = 0x200U; //001 00000 00000000 command to write 00 to reg 0
    //txBuffer[1] = 0x100U; //000 10000 00000000 command to read reg 0
    //txBuffer[2] = 0x001U; // JUNK at present
   
    //while(1)
    //{
    /* Master: start a transfer. Slave: prepare for a transfer. */
    //    while(!(Cy_SCB_SPI_GetTxFifoStatus(SPIM_HW) & CY_SCB_SPI_TX_EMPTY)){}
    //    Cy_SCB_SPI_Write(SPIM_HW, txBuffer[0]);
       
    //    CyDelay(1);
       
    //    while(!(Cy_SCB_SPI_GetRxFifoStatus(SPIM_HW) & CY_SCB_SPI_RX_NOT_EMPTY)){}
    //    RxBuffer[0] = Cy_SCB_SPI_Read(SPIM_HW);
   
   
    //}
    /* Handle results of a transfer */    
   
   
    // END SPI TEST CODE //
    
    
    
    while (1)
    {
        lv_task_handler();
        //btn_anime();
        
        CyDelay(5);
    }
}
