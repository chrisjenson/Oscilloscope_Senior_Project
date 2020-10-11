module AddrGen(
    output reg [18:0]   RAMR_ReadAddr,
    output reg [18:0]   RAMW_WriteAddr,
    
    input               RAMW_WriteEn,
    
    input               ADC_Sampleclock,
    input               reset
);

    always @(posedge ADC_Sampleclock)
    begin
        if (reset)
        begin
            RAMR_ReadAddr <= 0;
            RAMW_WriteAddr <= 0;
        end
        else
        begin
            //If read line, inc addr by 1
            //If wrote line, inc addr by 1
        end
    end

endmodule
