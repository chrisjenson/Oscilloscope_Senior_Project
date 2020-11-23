`timescale 1ns / 1ps


module Top(
    input clk,
    input reset,
    input onBit,
    input [9:0] stimInData,
    output ADC_SampleClock
    );
        
    TimingGen u_TimingGen(
        .clk(clk),
        .reset(reset),
        .ADC_SampleClock(ADC_SampleClock)
    );
    
    wire [15:0] Buffer_DataIn;
    
    ADCInterface u_ADCInterface(
        .clk(clk),
        .reset(reset),      
        .ADC_DataIn(stimInData), 
        .ADC_SampleClock(ADC_SampleClock),
        .Buffer_DataIn(Buffer_DataIn)
    );
    
    wire [18:0] RAMW_WriteAddr;
    wire [15:0] RAMW_Data;
    wire RAMW_En;
    
    RAM_WriteEngine u_RAM_WriteEngine(
        .clk(clk),
        .reset(reset),
        .ADC_SampleClock(ADC_SampleClock),
        .Buffer_DataIn(Buffer_DataIn),
        .RAMW_WriteAddr(RAMW_WriteAddr), //Port A on RAM
        .RAMW_Data(RAMW_Data), 
        .onBit(onBit) //Use this to gate everything
    );
    
    wire [18:0] RAMW_ReadAddr;
    wire [15:0] RAMR_Data;
    wire SPI_ReadCommand; //from spi
    wire triggered; //From triggermanagement
    wire [18:0] RAMR_Quantity;
    wire [15:0] RAMData;
    wire FIFO_InRTS;
    wire FIFO_InRTR;
    
    Ram_ReadEngine u_Ram_ReadEngine(
        .clk(clk),
        .reset(reset),
        .ADC_SampleClock(ADC_SampleClock),
        //Ram Read
        .triggered(1), //DEBUG FROM TRIGGERMANAGEMENT
        .SPI_ReadCommand(SPI_ReadCommand),
        .RAMR_ReadAddr(RAMW_ReadAddr), //Port B on RAM, current read location
        .RAMR_Quantity(4196), //DEBUG: FROM SPI COMMAND
        .RAMR_Data(RAMR_Data),
        //FIFO
        .RAMData(RAMData),
        .FIFO_InRTS(FIFO_InRTS),
        .FIFO_InRTR(FIFO_InRTR)
    );
    
   
    /*
    BlockRam_blk_mem_gen_0_0 blk_mem_gen_0(
        //PORT A
        .addra(RAMW_WriteAddr),
        .clka(clk), 
        .dina(RAMW_Data), 
        .wea(RAMW_En), 
        //PORT B
        .clkb(clk), 
        .doutb(),
        .addrb()
    );
    */
    /*
    BlockRam u_BlockRam(
        //PORT A
        .addra(RAMW_WriteAddr),
        .clka(clk), 
        .dina(RAMW_Data), 
        .wea(RAMW_En), 
        //PORT B
        .clkb(clk), 
        .doutb(),
        .addrb()
    );*/
    
endmodule
