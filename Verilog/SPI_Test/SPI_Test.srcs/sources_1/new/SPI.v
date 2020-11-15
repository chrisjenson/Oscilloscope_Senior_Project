`timescale 1ns / 1ps

module SPI(
        output reg MISO,
        input MOSI_Raw,
        input SlaveSel,
        input clk,
        input SCLK_Raw,
        
        //For RAM
        input [15:0] Buffer_DataIn, //DEBUG Changed this to 16 bits
        output reg FIFO_OutRTR
    );
    
    reg Reg_WrEn;
    reg Reg_RdEn;
    reg Buffer_RdEn;
    
    reg [3:0] SPI_OutSixteenCount;
    reg [3:0] SPI_InSixteenCount;
    reg [2:0] SPI_InEightCounter;
    
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
    
  //  reg [18:0] BUFFER_InCount;
    reg [18:0] BUFFER_InAmount;// geting sent to RAM_Read_Engine
    
         
    always @(*) //Handle Control values
    begin
        case (SPI_Cmd)
            3'b001: //ReadReg- MISO //32 bits
            begin
                Reg_RdEn = 1;
                Reg_WrEn = 0;
                Buffer_RdEn = 0;
                BUFFER_InAmount = 0;
            end
            3'b010: //Write- MOSI 16bits
            begin
                Reg_RdEn = 0;
                Reg_WrEn = 1;
                Buffer_RdEn = 0;
                BUFFER_InAmount = 0;
            end
            3'b011: //ReadData- MISO RAM Read- this is default mode //8 bits
            begin
                Reg_RdEn = 0;
                Reg_WrEn = 0;
                Buffer_RdEn = 1;
                case (SPI_Params)
                    00000:
                    begin
                        BUFFER_InAmount = 524288; //2^19 = max ram size
                    end
                    00001:
                    begin
                        BUFFER_InAmount = 262144; //2^18
                    end
                    00010:
                    begin
                        BUFFER_InAmount = 131072;
                    end
                    00011:
                    begin
                        BUFFER_InAmount = 65536;
                    end
                    00100:
                    begin
                        BUFFER_InAmount = 32768;
                    end
                    00101:
                    begin
                        BUFFER_InAmount = 16384; //2^14
                    end
                    00110:
                    begin
                        BUFFER_InAmount = 8192; 
                    end
                    00111:
                    begin
                        BUFFER_InAmount = 4096;
                    end
                endcase
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
    /////////////////////////////////////////////
    reg [7:0] SPI_InInstructionBits;
    reg [7:0] SPI_Instruction;
    reg new_instruction_strobe;
    
    always @(posedge clk) //Get first 8 bits for SPI instruction
    begin
        new_word_strobe <= 1;
        if (SlaveSel) 
        begin //RESET
            SPI_InEightCounter <= 7;
            SPI_InInstructionBits <= 0;
        end
        else
        begin
            if (sck_posedge_pulse)
            begin
                SPI_InInstructionBits[SPI_InEightCounter] <= MOSI;
                if (SPI_InEightCounter == 0)
                begin
                    new_instruction_strobe <= 1; //High for one clock cycle
                end
            end
        end
    end
    
    always @(posedge clk) //Read Instruction
    begin
        if (new_instruction_strobe) //Will only be high 1 cycle
        begin
            SPI_Instruction <= SPI_InInstructionBits;
        end
    end
    
    
    always @(posedge clk) //Write to reg
    begin
        if (SlaveSel) 
        begin //RESET
            
        end
        else
        begin
            
        end
    end
    
    /////////////////////////////////////
    always @(posedge clk) //Read from reg
    begin
        new_word_strobe <= 0;
        if (SlaveSel) //Do not read on high/ SPI done transferring word
        begin
            SPI_InSixteenCount <= 4'hF;
            SPI_OutSixteenCount <= 4'hF;
            SPI_DataIn <= 16'h0000;
            SPIWord <= 16'h0000;

           // Reg_RdEn <= 0;//DEBUG should these go here?
          //  Reg_WrEn <= 0;
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
                            //Reg_RdEn <= 0; //DONE
                        end
                    end
                    SPI_OutSixteenCount <= SPI_OutSixteenCount - 1;
                end
            end
        end
    end
    
    reg [3:0] SPI_RamReadOutSixteenCount;
    
    always @(posedge clk) //RAM Read
    //input SlaveSel
    //input sck_negedge_pulse
    //input [15:0] Buffer_DataIn
    //input Buffer_RdEn
    begin
        if (SlaveSel) //SS active low, reset if high
        begin
            //BUFFER_InCount <= 0;
            FIFO_OutRTR <= 0;
            //Buffer_RdEn <= 0; //This is asserted elsewhere, should not do here
            SPI_RamReadOutSixteenCount <= 15;
        end
        else
        begin
            if (sck_negedge_pulse)
            begin
                if (Buffer_RdEn)
                begin

                    MISO <= Buffer_DataIn[SPI_RamReadOutSixteenCount]; //Need to pack two bytes per word, can use byte in fifo as 2nd byte
                    //Big endian format, high byte is the lower address (earlier data) byte
                    if (SPI_RamReadOutSixteenCount == 0)
                    begin
                        FIFO_OutRTR <= 1;
                        SPI_RamReadOutSixteenCount <= 15;
                    end
                    else
                    begin
                        FIFO_OutRTR <= 0;
                        SPI_RamReadOutSixteenCount <= SPI_RamReadOutSixteenCount - 1;
                    end
                    //Check with chris if can handle slave select low for long time
                    //Going to need diagram to show state machine
               
                       
                    
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
