module TriggerManagement(
    input [7:0]     Regs_Trigger,
    input           Regs_TriggerSlope,
    input [7:0]     Buffer_DataIn,
    
    output          RAMW_WriteEn,
    output          triggered,
    
    input           ADC_Sampleclock,
    input           reset
);

    always @(posedge ADC_Sampleclock) //Needs some work
    begin
        if (Regs_TriggerSlope) //pos edge
        begin
            if (Buffer_DataIn > Regs_Trigger)
            begin
            
            end
        end
        else if (!Regs_TriggerSlope) //neg edge
        begin
            
        end
    end

endmodule