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
    
    wire [17:0] RAMW_WriteAddr;
    wire [15:0] RAMW_Data;
    wire RAMW_En;
    
    RAM_WriteEngine u_RAM_WriteEngine(
        .clk(clk),
        .reset(reset),
        .ADC_SampleClock(ADC_SampleClock),
        .Buffer_DataIn(Buffer_DataIn),
        .RAMW_WriteAddr(RAMW_WriteAddr), //Port A on RAM
        .RAMW_Data(RAMW_Data), 
        .RAMW_En(RAMW_En),
        .onBit(onBit) //Use this to gate everything
    );
    
    wire [17:0] RAMW_ReadAddr;
    wire [15:0] RAMR_Data;
    wire SPI_ReadCommand; //from spi
    wire triggered; //From triggermanagement
    wire [17:0] RAMR_Quantity;
    wire [15:0] RAMData;
    wire FIFO_InRTS;
    wire FIFO_InRTR;
    
    assign triggered = 1; //DEBUG FROM TRIGGERMANAGEMENT
    assign SPI_ReadCommand = 1;
    assign RAMR_Quantity = 4096; //DEBUG: FROM SPI COMMAND
    
    Ram_ReadEngine u_Ram_ReadEngine(
        .clk(clk),
        .reset(reset),
        .ADC_SampleClock(ADC_SampleClock),
        //Ram Read
        .triggered(triggered), 
        .RAMR_ReadAddr(RAMW_ReadAddr), //Port B on RAM, current read location
        .RAMR_Quantity(RAMR_Quantity), 
        .RAMR_Data(RAMR_Data),
        .SPI_ReadCommand(SPI_ReadCommand),
        //FIFO
        .RAMData(RAMData),
        .FIFO_InRTS(FIFO_InRTS),
        .FIFO_InRTR(FIFO_InRTR)
    );
    
   wire [1:0] wea; //RAM requires 2 bit enable
   assign wea[0] = RAMW_En;
   assign wea[1] = RAMW_En;
    
    blk_mem_gen_0 u_blk_mem_gen_0(
        //PORT A -Write
        .addra(RAMW_WriteAddr),
        .clka(clk), 
        .dina(RAMW_Data), 
        .wea(wea), 
        //PORT B -Read
        .clkb(clk), 
        .doutb(RAMR_Data),
        .addrb(RAMW_ReadAddr)
    );

endmodule
