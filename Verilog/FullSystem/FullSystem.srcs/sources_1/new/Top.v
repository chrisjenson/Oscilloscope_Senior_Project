`timescale 1ns / 1ps


module Top(
    input clk,
    input rst_, //HIGH BY DEFAULT ON HARDWARE
    //Frontend
    input [9:0] ADC_InData,
    output ADC_SampleClock,
    //SPI
    input MOSI_Raw, //C17
    input SlaveSel,
    input SCLK_Raw, 
    output MISO,    //D18
    //For Debug
    input [7:0] DebugWriteRegister,
    output [7:0] DebugRegister,
    output DebugFlag,
    output DebugFlag2,
    output DebugFIFOInXFC,
    output DebugFIFOOutXFC,
    output DebugSlaveSel,
    output DebugMOSI,
    output DebugSCLK,
    output [7:0] DebugSPI_Ins,
    output reg reset //For debug
    );
    wire onBit;
    assign onBit = 1'b1;
    reg reset_p1;
    //reg reset;
    always @(posedge clk)
    begin
        reset_p1 <= ~rst_; //Get the opposite of reset here
        reset <= reset_p1;
    end    
    
    TimingGen u_TimingGen(
        .clk(clk),
        .reset(reset),
        .ADC_SampleClock(ADC_SampleClock)
    );
    
   // wire [15:0] Buffer_DataIn;
    wire [15:0] RAMW_Data;

    ADCInterface u_ADCInterface(
        .clk(clk),
        .reset(reset),      
        .ADC_DataIn(ADC_InData), 
        .ADC_SampleClock(ADC_SampleClock),
        .RAMW_Data(RAMW_Data)
    );
    
    wire [17:0] RAMW_WriteAddr;
    wire RAMW_En;
    
    RAM_WriteEngine u_RAM_WriteEngine(
        .clk(clk),
        .reset(reset),
        .ADC_SampleClock(ADC_SampleClock),
        //.Buffer_DataIn(Buffer_DataIn),
        .RAMW_WriteAddr(RAMW_WriteAddr), //Port A on RAM
        //.RAMW_Data(RAMW_Data), 
        .RAMW_En(RAMW_En),
        .onBit(onBit) //Use this to gate everything, should come from regs
    );
    
    wire [17:0] RAMR_ReadAddr;
    wire [15:0] RAMR_Data;
    wire SPI_ReadCommand; //from spi
    wire triggered; //From triggermanagement
    wire [17:0] RAMR_Quantity;
    //wire [15:0] RAMData;
    wire FIFO_InRTS;
    wire FIFO_InRTR;
    
    assign triggered = 1; //DEBUG FROM TRIGGERMANAGEMENT
    //assign SPI_ReadCommand = 1;
   // assign RAMR_Quantity = 4096; //DEBUG: FROM SPI COMMAND
    
    
    RAM_ReadEngine u_RAM_ReadEngine(
        .clk(clk),
        .reset(reset),
        //.ADC_SampleClock(ADC_SampleClock),
        //Ram Read
        .DEBUGreading(DebugFlag),
        .triggered(triggered), //input, gates read
        .RAMR_ReadAddr(RAMR_ReadAddr), //Port B on RAM, current read location
        .RAMR_Quantity(RAMR_Quantity), //output from spi, gates read
        //.RAMR_Data(RAMR_Data),
        .SPI_ReadCommand(SPI_ReadCommand), //Input, gates read
        .SlaveSel(SlaveSel),
        //FIFO
        //.RAMData(RAMData),
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
        .addrb(RAMR_ReadAddr)
    );
    
    wire [7:0] SPI_Data; //last 8 bits of spi command
    wire [4:0] SPI_Params;
    wire Reg_WrEn;
    wire write_data_strobe;
    wire Reg_RdEn;
    wire [7:0] Reg_DataOut;
    
    wire [15:0] FIFO_OutData;
    wire FIFO_OutRTR;
    SPI u_SPI(
        .MISO(MISO),
        .MOSI_Raw(MOSI_Raw),
        .SlaveSel(SlaveSel),
        .clk(clk),
        .reset(reset),
        .SCLK_Raw(SCLK_Raw),
        //debug
        //.DebugFlag(DebugFlag), 
        .DebugFlag2(DebugFlag2),
        .DebugSlaveSel(DebugSlaveSel),      
        .DebugMOSI(DebugMOSI),          
        .DebugSCLK(DebugSCLK),
        .DebugSPI_Ins(DebugSPI_Ins),         
        //For RAM
        .BUFFER_InAmount(RAMR_Quantity), //Output
        .FIFO_OutData(FIFO_OutData),//Input
        .FIFO_OutRTR(FIFO_OutRTR), //Output
        .Buffer_RdEn(SPI_ReadCommand), //Output
        //For Regs
        .Reg_WrEn(Reg_WrEn), //Output
        .Reg_RdEn(Reg_RdEn), //Output
        .write_data_strobe(write_data_strobe), //Output
        .SPI_Data(SPI_Data), //Output
        .SPI_Params(SPI_Params), //Output
        .Reg_DataOut(Reg_DataOut) //Input
    );
    
    Regs u_REGS(
        .clk(clk), //Input
        .reset(reset), //Input
        .Write_Data(SPI_Data), //Input
        .Regs_Addr(SPI_Params), //Input
        .WrEn(Reg_WrEn & write_data_strobe), //Inputs Reg_WrEn & write_data_strobe
        .RdEn(Reg_RdEn), //Input
        .Read_Data(Reg_DataOut), //Output
        .DebugWriteRegister(DebugWriteRegister), //Input- set to DebugWriteRegister for synthesis 8'b00000000
        .DebugRegister(DebugRegister) //Output
    );
    
    
    Buffer_FIFO u_Buffer_FIFO(
        .FIFO_OutRTR(FIFO_OutRTR), //Input from SPI
       // .FIFO_OutRTS(),
        
        .FIFO_InRTS(FIFO_InRTS), //Input from RamRdEngine
        .FIFO_InRTR(FIFO_InRTR), //Output to RamRdEngine to know fifo to increment address
        //DEBUG BELOW SHOULD BE RAMR_DATA
        .FIFO_InData(16'b1010101010101010),//RAMR_Data), //Input from RAM 16'b1010101010101010
        .FIFO_OutData(FIFO_OutData), //Output to SPI
        
        .DebugFIFOInXFC(DebugFIFOInXFC),
        .DebugFIFOOutXFC(DebugFIFOOutXFC),
        
        .clk(clk),
        .reset(reset)
    );

endmodule
