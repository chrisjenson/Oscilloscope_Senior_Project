module TriggerManagement(
    input [7:0]     Regs_Trigger,
    input           Regs_TriggerSlope,
    input [7:0]     Buffer_DataIn,
    
    output reg      Trigger_Triggered,
    input           Trigger_LookForTrigger,
    
    input           clk,
    input           reset
);
    reg [7:0] dataIn_previous;
    
    always @(posedge clk) //Needs some work
    begin
        if (reset)
        begin
            dataIn_previous <= 0;
            Trigger_Triggered <= 0;
        end
    
        if (Trigger_LookForTrigger)
        begin
            if (Regs_TriggerSlope) //pos edge
            begin
                if (Buffer_DataIn > Regs_Trigger)
                begin
                    if (Buffer_DataIn > dataIn_previous) //using old values is called hysteresis
                    begin
                        Trigger_Triggered <= 1;
                        //Rising edge, good to increment read
                    end
                end
            end
            else if (!Regs_TriggerSlope) //neg edge
            begin
                if (Buffer_DataIn < Regs_Trigger)
                begin
                    if (Buffer_DataIn < dataIn_previous)
                    begin
                        Trigger_Triggered <= 1;
                        //Falling edge, good to increment read
                    end
                end
            end
            
            dataIn_previous <= Buffer_DataIn; //IS THIS USING OLD VALUE?????
        end 
    end



endmodule