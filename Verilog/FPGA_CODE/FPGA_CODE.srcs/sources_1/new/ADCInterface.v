`timescale 1ns / 1ps

module ADCInterface(
    input               ADC_XFC,
    input [9:0]         ADC_DataIn,
    input               ADC_Sampleclock,
    
    output reg [7:0]    Buffer_DataIn
    );
    
    reg signed [7:0] min = 8'h80; //-128
    reg signed [7:0] max = 8'h7F; //127;
    
    //Saturate max and min, otherwise get 8 MSb from ADC_DataIn, if ADC is RTS
    always @(posedge ADC_Sampleclock)
    begin
        if (ADC_XFC)
        begin
            if (ADC_DataIn > max) 
            begin
                Buffer_DataIn <= max;
            end
            
            else if (ADC_DataIn < min)
            begin
                Buffer_DataIn <= min;
            end
            
            else
            begin
                Buffer_DataIn <= ADC_DataIn[9:1];
            end
        end
    end
    
endmodule
