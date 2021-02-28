`timescale 1ns / 1ps
/*
Tasks to do:
    -Output test to MCU
    -Input test with DAB
    -All control value form regsiters need to be assigned
    -Trigger logic needs to be implemented
    -Debug improvements
    -Bit selection
*/

module Top(
    input clk,
    input rst_, //HIGH BY DEFAULT ON HARDWARE
    //Frontend
    //input [9:0] ADC_InData, //Uncomment this for TB
    output ADC_SampleClock,
    //SPI
    input MOSI_Raw, //C17
    input SlaveSel,
    input SCLK_Raw, 
    output MISO,    //D18
    //For Debug
    input [7:0] DebugWriteRegister, //Switches
    output [7:0] DebugLEDRegister,
    output DebugRamReading, //Debug Are we reading from the RAM? Triggered and on bit and read addr < Read qty
    output DebugRAMFullFlag,
    output DebugRAMReadRecieved, //Debug was a ram read command recieved
    output DebugTriggered,
    output DebugFIFOInXFC,
    output DebugFIFOOutXFC,
    output DebugNotSlaveSel,
    output DebugMOSI,
    output DebugSCLK,
    output DebugOnBit,
    output DebugMISO,
    output DebugSlaveSel,
    output reg reset //For debug
    );
    
    //////////////////////////
    //To comment this out, uncomment input [9:0] ADC_InData and comment everything below
    //Also uncomment in constraints
    //Uncomment in TB
    
    //Simulate data input on hardware
    wire [9:0] ADC_InData;
    
    DataSimulation u_DataSimulation(
        .ADC_SampleClock(ADC_SampleClock),
        .clk(clk),
        .reset(reset),
        .SimData(ADC_InData)
    );
    /////////////////////
    
    wire onBit;
    //assign onBit = 1'b1;
    reg reset_p1;
    //reg reset;
    always @(posedge clk)
    begin
        reset_p1 <= ~rst_; //Get the opposite of reset here
        reset <= reset_p1;
    end    
    
    wire ADC_SampleClock_posedge_pulse;
    wire ADC_SampleClock_negedge_pulse;
    
    TimingGen u_TimingGen(
        .clk(clk),
        .reset(reset),
        .ADC_SampleClock(ADC_SampleClock),
        .ADC_SampleClock_posedge_pulse(ADC_SampleClock_posedge_pulse),
        .ADC_SampleClock_negedge_pulse(ADC_SampleClock_negedge_pulse)
    );
    
   // wire [15:0] Buffer_DataIn;
    wire [15:0] RAMW_Data;
    wire [1:0] ADC_BitSelect;
    
    assign ADC_BitSelect = 1;
    ADCInterface u_ADCInterface(
        .clk(clk),
        .reset(reset),      
        .ADC_DataIn(ADC_InData), 
        .ADC_SampleClock(ADC_SampleClock),
        .ADC_BitSelect(ADC_BitSelect),
        .RAMW_Data(RAMW_Data)
    );
    
    wire [17:0] RAMW_WriteAddr;
    wire RAMW_En;
    wire [7:0] TriggerType;
    wire [7:0] TriggerThreshold;
    
    wire triggered; //From triggermanagement
    
    assign triggered = 1;
    assign DebugTriggered = triggered;
   // assign RAMR_Quantity = 4096; //DEBUG: FROM SPI COMMAND
    TriggerLogic u_TriggerLogic(
        .clk(clk),
        .reset(reset),
        .TriggerType(TriggerType), //From Regs
        .TriggerThreshold(TriggerThreshold), //From Regs
        //.triggered(triggered),
        .onBit(onBit), 
        
        //.ADC_SampleClock(ADC_SampleClock),
        //.RAMW_En(RAMW_En), //High when writing data to RAM
        .ADC_SampleClock_posedge_pulse(ADC_SampleClock_posedge_pulse),
        .ADC_InData(ADC_InData) //10 bits input- pre bit selection
    );
    
    RAM_WriteEngine u_RAM_WriteEngine(
        .clk(clk),
        .reset(reset),
        .ADC_SampleClock(ADC_SampleClock),
        .RAMW_WriteAddr(RAMW_WriteAddr), //Port A on RAM
        .RAMW_En(RAMW_En),
        .DebugRAMFullFlag(DebugRAMFullFlag),
        .onBit(onBit) //Use this to gate everything, should come from regs
    );
    
    wire [17:0] RAMR_ReadAddr;
    wire [15:0] RAMR_Data;
    wire SPI_ReadCommand; //from spi
    wire [17:0] RAMR_Quantity;
    wire FIFO_InRTS;
    wire FIFO_InRTR;
    
    
    
    RAM_ReadEngine u_RAM_ReadEngine(
        .clk(clk),
        .reset(reset),
        //Ram Read
        .DEBUGreading(DebugRamReading),
        .triggered(triggered), //input, gates read
        .RAMR_ReadAddr(RAMR_ReadAddr), //Port B on RAM, current read location
        .RAMW_WriteAddr(RAMW_WriteAddr), //Know where writing vurrently to read half below half above
        .RAMR_Quantity(RAMR_Quantity), //output from spi, gates read
        .SPI_ReadCommand(SPI_ReadCommand), //Input, gates read
        .SlaveSel(SlaveSel),
        //FIFO
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
    
    assign DebugMISO = MISO;
    SPI u_SPI(
        .MISO(MISO),
        .MOSI_Raw(MOSI_Raw),
        .SlaveSel(SlaveSel),
        .clk(clk),
        .reset(reset),
        .SCLK_Raw(SCLK_Raw),
        //Debug
        .DebugRAMReadRecieved(DebugRAMReadRecieved),
        .DebugNotSlaveSel(DebugNotSlaveSel),  
        .DebugSlaveSel(DebugSlaveSel),    
        .DebugMOSI(DebugMOSI),          
        .DebugSCLK(DebugSCLK),
        //.DebugSPI_Ins(DebugSPI_Ins),         
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
        .DebugLEDRegister(DebugLEDRegister), //Output
        .TriggerType(TriggerType),
        .TriggerThreshold(TriggerThreshold),
        .onBit(onBit)
    );
    
    
    Buffer_FIFO u_Buffer_FIFO(
        .FIFO_OutRTR(FIFO_OutRTR), //Input from SPI
        
        .FIFO_InRTS(FIFO_InRTS), //Input from RamRdEngine
        .FIFO_InRTR(FIFO_InRTR), //Output to RamRdEngine to know fifo to increment address
        .FIFO_InData(RAMR_Data),//RAMR_Data), //Input from RAM 16'b1010101010101010
        .FIFO_OutData(FIFO_OutData), //Output to SPI
        
        .DebugFIFOInXFC(DebugFIFOInXFC),
        .DebugFIFOOutXFC(DebugFIFOOutXFC),
        
        .clk(clk),
        .reset(reset)
    );

endmodule
