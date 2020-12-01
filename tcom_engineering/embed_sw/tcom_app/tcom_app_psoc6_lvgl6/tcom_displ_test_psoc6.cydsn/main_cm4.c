#include "project.h"
#include "lvgl.h"

#include "stdio.h"

#include "globalStruct.h"
#include "touchpad_glue.h"
#include "display_glue.h"
#include "home_screen.h"

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
    
    SPIM_Start();
    LCD_INTERFACE_Start();
    I2C_MASTER_Start();
    DISP_TICK_TIMER_Start();
    
    lv_init();
    ili9488_init();
    
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
    
    // INITIALIZE THE STRUCT VALUES
    //struct SPI_parameters cm4;
    cm4.BrianReg = 0b01000010;
    cm4.ChrisReg = 0b01000011;
    cm4.ShannonReg = 0b01010011;
    cm4.VersionID = 0b00000001;
    cm4.Trigger = 0b00000000;
    cm4.TriggerSlope = 0b00000000;
    cm4.SampleRate = 0b00000000;
    cm4.onBit = 0b00000000;
    cm4.Reset = 0b00000000;
    cm4.IRS = 0b00000000;
    cm4.Offset = 0b00000000;
    cm4.Gain = 0b00000000;       //goes to Shannon
    cm4.HoriSCale = 0b00000000;
    cm4.VertScale = 0b00000000;
    
    
    // START SPI CODE //
    uint16_t txBuffer[13];
    uint16_t RxBuffer[13];
    
    if(cm4.onBit == 00000001)
    {
        //construct write commmand for updating offset in register 11
        txBuffer[0] = 0b0100101100000000 | cm4.Offset;     //010 01011 00000000
        
        //construct write commmand for updating trigger in register 4
        txBuffer[1] = 0b0100010000000000 | cm4.Trigger;     //010 00100 00000000
        
        //construct read RAM command, or with HoriScale to determine the sample size
        txBuffer[2] = 0b0110000000000000 | cm4.HoriSCale;     //011 00000 00000000
        
        //loop to send each command in the txBuffer
        for(int i = 0; i < 3; ++i){
            while(!(Cy_SCB_SPI_GetTxFifoStatus(SPIM_HW) & CY_SCB_SPI_TX_EMPTY)){}
            Cy_SCB_SPI_Write(SPIM_HW, txBuffer[i]);
   
            CyDelay(1);
   
            while(!(Cy_SCB_SPI_GetRxFifoStatus(SPIM_HW) & CY_SCB_SPI_RX_NOT_EMPTY)){}
            RxBuffer[i] = Cy_SCB_SPI_Read(SPIM_HW);
        }
        //Reset to avoid an infinite loop
        cm4.onBit = 0b00000000;
    }
    // END SPI CODE //
    
    
     // SPI TEST CODE //

    //unt16 because of the command size
    //uint16_t txBuffer[BUFFER_SIZE];
    //uint16_t txBuffer[13];
    //uint16_t RxBuffer[13];
   
    /*home_screen(); Initialize txBuffer with command to transfer 
    txBuffer[0] = CMD_START_TRANSFER;
    RxBuffer[0] = 0b1111111111111111; //Junk value
    txBuffer[0] = 0b0100010000000000; //010 00100 00000000 command to write 00000000 to reg 4
    txBuffer[1] = 0b0100010011111111; //010 00100 11111111 command to write 11111111 to reg 4    
    txBuffer[2] = 0b0010010011111111; //001 00100 11111111 command to read reg 4
    txBuffer[2] = 0b0110000000000000; //011 00000 00000000 command to do a RAM READ
    */
    
    /*  Command set to read in a bunch of registers to write to the chart
    txBuffer[0] = 0b0010000000000000; //001 00011 00000000 command to read reg 0
    txBuffer[1] = 0b0010000100000000; //001 00011 00000000 command to read reg 1
    txBuffer[2] = 0b0010001000000000; //001 00011 00000000 command to read reg 2
    txBuffer[3] = 0b0010001100000000; //001 00011 00000000 command to read reg 3
    txBuffer[4] = 0b0010010000000000; //001 00011 00000000 command to read reg 4
    txBuffer[5] = 0b0010010100000000; //001 00011 00000000 command to read reg 5
    txBuffer[6] = 0b0010011000000000; //001 00011 00000000 command to read reg 6
    txBuffer[7] = 0b0010011100000000; //001 00011 00000000 command to read reg 7
    txBuffer[8] = 0b0010100000000000; //001 00011 00000000 command to read reg 8
    txBuffer[9] = 0b0010100100000000; //001 00011 00000000 command to read reg 9
    txBuffer[10] = 0b0010101000000000; //001 00011 00000000 command to read reg 10
    txBuffer[11] = 0b0010101100000000; //001 00011 00000000 command to read reg 10
    txBuffer[12] = 0b0010110000000000; //001 00011 00000000 command to read reg 10
    */

    /*  Command set to write a binary counter
    txBuffer[0] = 0b0100001100000001; //010 00100 00000000 command to write 00000000 to reg 3
    txBuffer[1] = 0b0100001100000010; //010 00100 00000000 command to write 00000000 to reg 3
    txBuffer[2] = 0b0100001100000011; //010 00100 00000000 command to write 00000000 to reg 3
    txBuffer[3] = 0b0100001100000100; //010 00100 00000000 command to write 00000000 to reg 3
    txBuffer[4] = 0b0100001100000101; //010 00100 00000000 command to write 00000000 to reg 3
    txBuffer[5] = 0b0100001100000110; //010 00100 00000000 command to write 00000000 to reg 3
    txBuffer[6] = 0b0100001100000111; //010 00100 00000000 command to write 00000000 to reg 3
    txBuffer[7] = 0b0100001100001000; //010 00100 00000000 command to write 00000000 to reg 3
    txBuffer[8] = 0b0100001100001001; //010 00100 00000000 command to write 00000000 to reg 3
    txBuffer[9] = 0b0100001100001010; //010 00100 00000000 command to write 00000000 to reg 3
    txBuffer[10] = 0b0100001100001011; //010 00100 00000000 command to write 00000000 to reg 3
    txBuffer[11] = 0b0100001100001100; //010 00100 00000000 command to write 00000000 to reg 3
    txBuffer[12] = 0b0100001100001101; //010 00100 00000000 command to write 00000000 to reg 3
    */

    /*  SPI TEST send code
    while(1)
    {
        // Master: start a transfer. Slave: prepare for a transfer.
        for(int i = 0; i < 13; ++i){
            while(!(Cy_SCB_SPI_GetTxFifoStatus(SPIM_HW) & CY_SCB_SPI_TX_EMPTY)){}
            Cy_SCB_SPI_Write(SPIM_HW, txBuffer[i]);
       
            CyDelay(300);
       
            while(!(Cy_SCB_SPI_GetRxFifoStatus(SPIM_HW) & CY_SCB_SPI_RX_NOT_EMPTY)){}
            RxBuffer[i] = Cy_SCB_SPI_Read(SPIM_HW);
        
            //if statement to restart the binary counter
            //if(i == 12){
            //    i = 0;
            //}
        }
    }
    */
        
    /*  Fake RxBuffer values to fill the chart when not connected to the FPGA
    RxBuffer[0] = 0b0000000000010000; //001 00011 00000000 command to read reg 0
    RxBuffer[1] = 0b0000000000100000; //001 00011 00000000 command to read reg 1
    RxBuffer[2] = 0b0000000001000000; //001 00011 00000000 command to read reg 2
    RxBuffer[3] = 0b0000000000100000; //001 00011 00000000 command to read reg 3
    RxBuffer[4] = 0b0000000000010000; //001 00011 00000000 command to read reg 4
    RxBuffer[5] = 0b0000000000001000; //001 00011 00000000 command to read reg 5
    RxBuffer[6] = 0b0000000000010000; //001 00011 00000000 command to read reg 6
    RxBuffer[7] = 0b0000000000100000; //001 00011 00000000 command to read reg 7
    RxBuffer[8] = 0b0000000001000000; //001 00011 00000000 command to read reg 8
    RxBuffer[9] = 0b0000000000100000; //001 00011 00000000 command to read reg 9
    RxBuffer[10] = 0b0000000000010000; //001 00011 00000000 command to read reg 10
    RxBuffer[11] = 0b0000000000001000; //001 00011 00000000 command to read reg 10
    RxBuffer[12] = 0b0000000000010000; //001 00011 00000000 command to read reg 10
    */
        
    /* Handle results of a transfer     
    for(int j = 0; j < 13; ++j)
    {
        cm4.RegBuffer[j] = RxBuffer[j];
    
    }
    */    
    // END SPI TEST CODE //
    
     home_screen();
    
    while (1)
    {
        lv_task_handler();
        //btn_anime();
        
        CyDelay(5);
    }
}
