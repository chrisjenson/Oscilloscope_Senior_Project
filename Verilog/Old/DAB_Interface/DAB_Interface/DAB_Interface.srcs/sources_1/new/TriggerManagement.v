module TriggerManagement(
    input ADC_SampleClock,

    input [7:0]     Regs_TriggerValue,
    input           Regs_TriggerSlope, //1 for rising, 0 for falling
    input [7:0]     Buffer_DataPoint,
    
    output reg      Trigger_Triggered,
    input           Trigger_LookForTrigger,
    
    input           clk,
    input           reset
);
    /////////////////////////////////////////////////
    //Get negedge and posedge pulses
    wire ADC_SampleClock_posedge_pulse;
    wire ADC_SampleClock_negedge_pulse;
    
    reg ADC_SampleClock_p1;
    
    always @(posedge clk)
    begin
        ADC_SampleClock_p1 <= ADC_SampleClock;
    end
    
    assign ADC_SampleClock_posedge_pulse = ADC_SampleClock & ~ADC_SampleClock_p1;
    assign ADC_SampleClock_negedge_pulse = ~ADC_SampleClock & ADC_SampleClock_p1;
    //End section
    //////////////////////////////////////////////////////////////    

    reg [7:0] dataIn_previous;
    
    always @(posedge clk)
    //Based on trigger slope and trigger value, check current input compared to previous input and set triggered flag
    //Inputs
        //ADC_SampleClock_posedge_pulse
        //reset
        //Trigger_LookForTrigger //If the code should be looking for a trigger
        //Regs_TriggerSlope
        //Buffer_DataIn
    //Outputs
        //Trigger_Triggered
    begin
        if (reset)
        begin
            dataIn_previous <= 0;
            Trigger_Triggered <= 0;
        end
        if (ADC_SampleClock_posedge_pulse)
        begin
            if (Trigger_LookForTrigger)
            begin
                if (Regs_TriggerSlope) //pos edge
                begin
                    if (Buffer_DataPoint > Regs_TriggerValue)
                    begin
                        if (Buffer_DataPoint > dataIn_previous) //using old values is called hysteresis
                        begin
                            Trigger_Triggered <= 1;
                            //Rising edge, good to increment read
                        end
                    end
                end
                else if (!Regs_TriggerSlope) //neg edge
                begin
                    if (Buffer_DataPoint < Regs_TriggerValue)
                    begin
                        if (Buffer_DataPoint < dataIn_previous)
                        begin
                            Trigger_Triggered <= 1;
                            //Falling edge, good to increment read
                        end
                    end
                end            
            end 
        end
    end
    
    always @(posedge clk)
    begin
        if (ADC_SampleClock_posedge_pulse)
        begin
            dataIn_previous <= Buffer_DataPoint; 
        end
    end



endmodule