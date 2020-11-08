`timescale 1ns / 1ps

module SPI(
        output reg MISO,
        input MOSI_Raw,
        input SlaveSel,
        input clk,
        input SCLK_Raw,
        
        //For RAM
        input [7:0] Buffer_DataIn, 
        output FIFO_OutRTR
    );
    
    reg Reg_WrEn;
    reg Reg_RdEn;
    reg Buffer_RdEn;
    
    reg [3:0] SPI_OutSixteenCount;
    reg [3:0] SPI_InSixteenCount;
    
    reg [2:0] SPI_OutEightCount;
    
    wire [2:0] SPI_Cmd;
    wire [4:0] SPI_Params;
    wire [7:0] SPI_Data;
    
    reg [15:0] SPIWord; //spiword is valid on the last possckposedgepulse of the word
    reg [15:0] SPI_DataIn;
    assign SPI_Cmd = SPIWord[15:13];
    assign SPI_Params = SPIWord[12:8];
    assign SPI_Data = SPIWord[7:0];
        
    wire [7:0] Reg_DataOut;//Wires between modules are always modules
    reg [7:0] Reg_DataIn;
    
    reg sck;
    reg sck_p1;
    reg sck_raw_p1;
    reg MOSI_raw_p1;
    reg MOSI;
    wire sck_posedge_pulse;
    wire sck_negedge_pulse;
    
    
    reg new_word_strobe;
     
    always @(*)
    begin
        case (SPI_Cmd)
            3'b001: //ReadReg- MISO //32 bits
            begin
                Reg_RdEn = 1;
                Reg_WrEn = 0;
                Buffer_RdEn = 0;
            end
            3'b010: //Write- MOSI 16bits
            begin
                Reg_RdEn = 0;
                Reg_WrEn = 1;
                Buffer_RdEn = 0;
            end
            3'b011: //ReadData- MISO RAM Read- this is default mode //8 bits
            begin
                Reg_RdEn = 0;
                Reg_WrEn = 0;
                Buffer_RdEn = 1;
            end
        endcase
    end
    
    always @(posedge clk)
    begin
        sck_p1 <= sck; 
    end
    
    always @(posedge clk) //Avoid metastability for digital input
    begin 
        sck_raw_p1 <= SCLK_Raw;
        sck <= sck_raw_p1;
        
        MOSI_raw_p1 <= MOSI_Raw;
        MOSI <= MOSI_raw_p1; //one cycle delay
    end
    
    assign sck_posedge_pulse = sck & ~sck_p1;
    assign sck_negedge_pulse = ~sck & sck_p1;
    
    always @(posedge clk) //Read from reg
    begin
        new_word_strobe <= 0;
        if (SlaveSel) //Do not read on high/ SPI done transferring word
        begin
            SPI_InSixteenCount <= 4'hF;
            SPI_OutSixteenCount <= 4'hF;
            SPI_DataIn <= 16'h0000;
            SPIWord <= 16'h0000;

            Reg_RdEn <= 0;//DEBUG should these go here?
            Reg_WrEn <= 0;
        end
        else
        begin
            if (sck_posedge_pulse)
            begin
                if (!SlaveSel)
                begin
                    //Read 1 bit at a time
                    if (!Reg_RdEn)
                    begin
                        SPI_DataIn[SPI_InSixteenCount] <= MOSI;
                        if (SPI_InSixteenCount == 4'h0)
                        begin
                            new_word_strobe <= 1;
                            SPIWord <= {SPI_DataIn[15:1], MOSI}; //Valid word including 0th bit
                        end
                        
                        SPI_InSixteenCount <= SPI_InSixteenCount - 1;
                    end
                end
            end
            //Drive on negedge and sample on pos edge so need opposite of negative edge here
            if (sck_negedge_pulse)
            begin
                if (Reg_RdEn)
                begin
                    if (SPI_OutSixteenCount > 7)
                    begin
                        MISO <= 0;
                    end
                    else
                    begin
                        MISO <= Reg_DataOut[SPI_OutSixteenCount];
                        if (SPI_OutSixteenCount == 4'h0) //MSB first and not LSB
                        begin
                            Reg_RdEn <= 0;
                        end
                    end
                    SPI_OutSixteenCount <= SPI_OutSixteenCount - 1;
                end
            end
        end
    end
    
    reg [3:0] SPI_RamReadOutSixteenCount;
    
    always @(posedge clk) //RAM Read
    begin
        if (SlaveSel) //SS active low, reset if high
        begin
            Buffer_RdEn <= 0;
            SPI_OutEightCount <= 7;
            SPI_RamReadOutSixteenCount <= 0;
        end
        else
        begin
            if (sck_negedge_pulse) //Put data into FIFO? Read data and keep it full. Need to use internal clock for ram read, not sclk
            begin
                if (Buffer_RdEn) //DEBUG: Should we have a counter here from 0 to Params? so params = 1111 send 15 data values then wait?
                begin
                    MISO <= Buffer_DataIn[SPI_OutEightCount];
                    if (SPI_OutEightCount == 0) //One spi transfer is two bytes so need 2 eight counts or 1 16 count
                    begin//Check with chris if can handle slave select low for long time
                    //Need a ready to recieve from fifo between ram and SPI.
                    //Going to need diagram to show state machine - send them to pearlstein for verifacation
                        //DEBUG: Get next word here by sending a flag back (Will lose a clock cycle) or auto send by outputting sck to buffer?
                        if (SPI_RamReadOutSixteenCount == 16)
                        begin
                            //RTR
                        end
                        else
                        begin
                            SPI_OutEightCount <= 7;
                        end
                    end
                    SPI_OutEightCount <= SPI_OutEightCount - 1;
                    SPI_RamReadOutSixteenCount <= SPI_RamReadOutSixteenCount + 1;
                    
                end
            end
        end
    
    end
    
    
     
    Regs u_REGS(
        .Write_Data(SPI_Data),
        .Regs_Addr(SPI_Params),
        .WrEn(Reg_WrEn & new_word_strobe),
        .RdEn(Reg_RdEn),
        .Read_Data(Reg_DataOut)
    );
endmodule
