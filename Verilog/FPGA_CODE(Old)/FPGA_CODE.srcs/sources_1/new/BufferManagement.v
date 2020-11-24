`timescale 1ns / 1ps

module BufferManagement(
    input           ADC_XFC,

    input [7:0]     Buffer_DataIn,
    
    input [7:0]     RAMR_ReadData,
    input [18:0]    RAMR_ReadAddr,
    
    input [1:0]     Regs_SampleRate,
    input [7:0]     Regs_Trigger,
    input           Regs_TriggerSlope,
    
    output [7:0]    RAMW_WriteData,
    output          RAMW_WriteEn,
    input [18:0]    RAMW_WriteAddr,

    input           Trigger_Triggered,
    output reg      Trigger_LookForTrigger,
    input           clk,
    input           reset
    );
    integer         halfCount = 262144;
    reg [18:0]      preTriggerCount;
    reg [18:0]      postTriggerCount;
    
    always @(posedge clk)
    begin
        if (reset)
        begin
            preTriggerCount <= 0;
            postTriggerCount <= 0;
            Trigger_LookForTrigger <= 0;
        end
        else
        begin
            if (Trigger_Triggered)
            begin
                postTriggerCount <= postTriggerCount + 1;
                //send data to spi
            end
            if (ADC_XFC)
            begin
                preTriggerCount <= preTriggerCount + 1;
            end
            if (preTriggerCount >= halfCount)
            begin
                Trigger_LookForTrigger <= 1;
            end
        //In wait- just keep writing to ring buffer. Get trigger. Only write a defined amount more
            
        end
        
        
       
    end
    
    
    blk_mem_gen_0 mem_gen (
        .clka (clk),
        .wea (RAMW_WriteEn),
        .addra (RAMW_WriteAddr),
        .dina (RAMW_WriteData),
        .clkb (clk),
        .addrb (RAMR_ReadAddr),
        .doutb (RAMR_ReadData)
    );
    
    AddrGen addrgen(
        .RAMR_ReadAddr (RAMR_ReadAddr),
        
        .RAMW_WriteAddr (RAMW_WriteAddr),
        .RAMW_WriteEn (RAMW_WriteEn),
        
        .clk (clk),
        .reset (reset)
    );
    
    TriggerManagement tgrmgmt (
        .Regs_Trigger(Regs_Trigger),
        .Regs_TriggerSlope(Regs_TriggerSlope),
        .Buffer_DataIn(Buffer_DataIn),
        
        .Trigger_Triggered(Trigger_Triggered),
        .Trigger_LookForTrigger(Trigger_LookForTrigger),
        
        .clk(clk),
        .reset(reset)
    );
    
    
endmodule




