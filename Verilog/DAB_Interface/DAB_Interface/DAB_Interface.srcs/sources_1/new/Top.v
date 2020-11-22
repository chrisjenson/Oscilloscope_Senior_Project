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
    
    wire [7:0] Buffer_DataIn;
    
    ADCInterface u_ADCInterface(
        .clk(clk),
        .reset(reset),      
        .ADC_DataIn(stimInData), 
        .ADC_SampleClock(ADC_SampleClock),
        .Buffer_DataIn(Buffer_DataIn)
    );
    
    wire [18:0] RAMW_WriteAddr;
    wire [7:0] RAMW_Data;
    wire RAMW_En;
    
    RAM_AddrGen u_RAM_AddrGen(
        .clk(clk),
        .reset(reset),
        .ADC_SampleClock(ADC_SampleClock),
        .Buffer_DataIn(Buffer_DataIn),
        .RAMW_WriteAddr(RAMW_WriteAddr), //Port A on RAM
        .RAMW_Data(RAMW_Data), 
        .onBit(onBit) //Use this to gate everything
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
