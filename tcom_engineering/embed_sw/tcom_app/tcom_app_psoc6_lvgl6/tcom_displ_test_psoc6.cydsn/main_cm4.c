#include "project.h"
#include "lvgl.h"

#include "stdio.h"
#include "math.h"

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
    
    lv_theme_t *th = lv_theme_material_init(30, &lv_font_roboto_16);       //Set a HUE value and a Font for the Night Theme
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
    
    Cy_GPIO_Write(SEL_PIN_PORT, SEL_PIN_NUM, 1);
    
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
    cm4.HoriScale = 0b00000111;//default 7 for 280/40 
    cm4.VertScale = 0b00000101;//default 5 for 200/40
    cm4.onBit = 0b00000000;
    cm4.windowPos = 1024;
    
    
    //if(cm4.onBit == 0b00000001)
    //{
        //construct write commmand for updating offset in register 11
        cm4.TxBuffer[0] = 0b0100101100000000 | cm4.Offset;     //010 01011 00000000
        
        //construct write commmand for updating trigger in register 4
        cm4.TxBuffer[1] = 0b0100010000000000 | cm4.Trigger;     //010 00100 00000000
        
        //construct write commmand for updating gain in register 14
        cm4.TxBuffer[2] = 0b0100111000000000 | cm4.Gain;     //010 01110 00000000
        
        //construct read RAM command, or with HoriScale to determine the sample size
        //cm4.TxBuffer[3] = 0b0110000000000000 | cm4.HoriScale;     //011 00000 00000000
        
        //construct write commmand for updating on-bit in register 9
        cm4.TxBuffer[2] = 0b0100100100000000;     //010 01001 00000000
        
        //Send a read ram command to read 1024x2 samples 
        //cm4.TxBuffer[0] = 0b011000000000000; //| cm4.HoriScale;     //011 01001 00000000
        cm4.TxBuffer[0] = 0b0110100000000000;  //011 01001 00000000
        
        
        //write reg 4 all zeroes
        //cm4.TxBuffer[0] = 0b0100010000000000;  //011 01001 00000000
        
        CyDelay(3000);
        
        uint32_t NUM_TO_WRITE = 8; 
        int ss_state = 1;
        uint16_t bufferIndex = 0; 
        
        //loop to send each command in the txBuffer
        for(int i = 0; i < 1; ++i){
            //Set slave select low for the commands
            ss_state = !ss_state;  Cy_GPIO_Write(SEL_PIN_PORT, SEL_PIN_NUM, ss_state);

            Cy_SCB_SPI_ClearSlaveMasterStatus(SPIM_HW, CY_SCB_SPI_MASTER_DONE);
            Cy_SCB_SPI_Write(SPIM_HW, cm4.TxBuffer[i]);
            while(!(Cy_SCB_SPI_GetTxFifoStatus(SPIM_HW) & CY_SCB_SPI_TX_EMPTY)){}
            while(!(Cy_SCB_SPI_GetSlaveMasterStatus(SPIM_HW) & CY_SCB_SPI_MASTER_DONE)){}

            // Clear out the RX FIFO
            while((Cy_SCB_SPI_GetNumInRxFifo(SPIM_HW) != 1)){}
            Cy_SCB_SPI_ReadArray(SPIM_HW, cm4.RxBuffer, 1);

            /*
            These two lines work for reading the registers
            if((cm4.TxBuffer[i] >> 13) == 0b0000000000000001 || (cm4.TxBuffer[i] >> 13) == 0b0000000000000010){
               while(!(Cy_SCB_SPI_GetRxFifoStatus(SPIM_HW) & CY_SCB_SPI_RX_NOT_EMPTY)){}
                cm4.RxBuffer[0] = Cy_SCB_SPI_Read(SPIM_HW);
            }
            */
            
            //else{
            //1024/8, total number of samples divided by the size of bursts
            //512 because we are reading in  2 samples every time
            for(uint32_t burst = 0; burst < 1024/NUM_TO_WRITE; burst++){

                // Dummy write, to read data from FPGA
                Cy_SCB_SPI_ClearSlaveMasterStatus(SPIM_HW, CY_SCB_SPI_MASTER_DONE);
                Cy_SCB_SPI_WriteArray(SPIM_HW, cm4.TxBuffer, NUM_TO_WRITE);
                while(!(Cy_SCB_SPI_GetTxFifoStatus(SPIM_HW) & CY_SCB_SPI_TX_EMPTY)){}
                while(!(Cy_SCB_SPI_GetSlaveMasterStatus(SPIM_HW) & CY_SCB_SPI_MASTER_DONE)){}
                
                //read in bursts of NUM_TO_WRITE size
                while((Cy_SCB_SPI_GetNumInRxFifo(SPIM_HW) != NUM_TO_WRITE)){}
                Cy_SCB_SPI_ReadArray(SPIM_HW, cm4.RxBuffer, NUM_TO_WRITE);
                
                //Check if a ram read was performed so we can check if data has to be parsed
                if((cm4.TxBuffer[i] >> 13) == 0b011){
                    //for loop to split the read in data and then store appropriately in cm4.RamReadBuffer
                    //NUM_TO_WRITE*2 because we are actually reading in 2 data points per buffer space
                    for(uint16_t count = 0; count < NUM_TO_WRITE; count++){
                        //spilt the data, dont need variables here but are helpful
                        uint8_t firstSample = cm4.RxBuffer[count] >> 8; //right shift 8 to remove the second value
                        uint8_t secondSample = cm4.RxBuffer[count] & 0b0000000011111111; //AND with 1's to only get the first 8 digits
                        
                        cm4.RamReadBuffer[bufferIndex] = firstSample;
                        cm4.RamReadBuffer[bufferIndex + 1] = secondSample;
                        
                        bufferIndex += 2;
                    }
                }
                else{
                    //carry on as usual.... however that may be
                }
            }
            //Reassert slave select
            Cy_GPIO_Write(SEL_PIN_PORT, SEL_PIN_NUM, 1);
        }
        
        //Reset to avoid an infinite loop
        cm4.onBit = 0b00000000;
    //}
    // END SPI CODE //
    
    
        
        
        
        
       
    
     home_screen();
    
    while (1)
    {
        lv_task_handler();
        //btn_anime();
        
        CyDelay(5);
    }
}
