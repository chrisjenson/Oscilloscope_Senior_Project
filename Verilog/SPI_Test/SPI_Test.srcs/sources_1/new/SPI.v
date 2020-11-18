`timescale 1ns / 1ps

module SPI(
        output reg MISO,
        input MOSI_Raw,
        input SlaveSel,
        input clk,
        input reset,
        input SCLK_Raw,
        
        //For RAM
        input [15:0] Buffer_DataIn, //DEBUG Changed this to 16 bits
        output reg FIFO_OutRTR
    );
    
    reg Reg_WrEn;
    reg Reg_RdEn;
    reg Buffer_RdEn;
    
    //reg [3:0] SPI_OutSixteenCount;
    //reg [3:0] SPI_InSixteenCount;
    //reg [2:0] SPI_InEightCounter;
    
    //reg [2:0] SPI_OutEightCount;
    
//    wire [2:0] SPI_Cmd;
//    wire [4:0] SPI_Params;
//    wire [7:0] SPI_Data;
    reg [2:0] SPI_Cmd; 
    reg [4:0] SPI_Params;
    reg [7:0] SPI_Data;
    
    
    //reg [15:0] SPIWord; //spiword is valid on the last possckposedgepulse of the word
    //reg [15:0] SPI_DataIn;
    
    //assign SPI_Cmd = SPIWord[15:13];
    //assign SPI_Params = SPIWord[12:8];
    //assign SPI_Data = SPIWord[7:0];
        
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
    
    always @(posedge clk)
    begin
        sck_p1 <= sck; 
    end
    
    always @(posedge clk) 
    //Avoid metastability for digital input
    begin 
        sck_raw_p1 <= SCLK_Raw;
        sck <= sck_raw_p1;
        
        MOSI_raw_p1 <= MOSI_Raw;
        MOSI <= MOSI_raw_p1; //one cycle delay
    end
    
    assign sck_posedge_pulse = sck & ~sck_p1;
    assign sck_negedge_pulse = ~sck & sck_p1;
    /////////////////////////////////////////////
    //reg [7:0] SPI_InInstructionBits; //Constructs incoming MOSI into array
    //reg [7:0] SPI_Instruction; //Set to SPI_InInstructionBits after 8 MOSIs
    //reg [7:0] SPI_InDataBits; //Constructs incoming MOSI into array after 8 MOSIs if first 8 signal write command
    //reg [7:0] SPI_InData; //Bits 7:0 for a read command, set after 8 MOSIs
    //reg [2:0] SPI_InInstructionEightCounter; //Counts to 0 from 7 for SPI_InInstructionBits
    //reg [2:0] SPI_InDataEightCounter; //Counts to 0 from 7 for 
    reg new_instruction_strobe; //High for one clock cycle after 8 MOSIs
    reg new_data_strobe;
    
    always @(posedge clk)
    begin
    //Set the control values
    //Inputs
        //SlaveSel
        //new_instruction_strobe
    //Outputs
        //Reg_RdEn
        //Reg_WrEn
        //Buffer_RdEn
        //BUFFER_InAmount
        if (SlaveSel)
        begin
            Reg_RdEn <= 0;
            Reg_WrEn <= 0;
            Buffer_RdEn <= 0;
            BUFFER_InAmount <= 0;
        end
        else
        begin
            //if (new_instruction_strobe)
            //begin
                case (SPI_Cmd)
                    3'b001: //ReadReg- MISO //32 bits
                    begin
                        Reg_RdEn <= 1;
                        Reg_WrEn <= 0;
                        Buffer_RdEn <= 0;
                        BUFFER_InAmount <= 0;
                    end
                    3'b010: //Write- MOSI 16bits
                    begin
                        Reg_RdEn <= 0;
                        Reg_WrEn <= 1;
                        Buffer_RdEn <= 0;
                        BUFFER_InAmount <= 0;
                    end
                    3'b011: //ReadData- MISO RAM Read- this is default mode //8 bits
                    begin
                        Reg_RdEn <= 0;
                        Reg_WrEn <= 0;
                        Buffer_RdEn <= 1;
                        case (SPI_Params)
                            00000:
                            begin
                                BUFFER_InAmount <= 524288; //2^19 = max ram size
                            end
                            00001:
                            begin
                                BUFFER_InAmount <= 262144; //2^18
                            end
                            00010:
                            begin
                                BUFFER_InAmount <= 131072;
                            end
                            00011:
                            begin
                                BUFFER_InAmount <= 65536;
                            end
                            00100:
                            begin
                                BUFFER_InAmount <= 32768;
                            end
                            00101:
                            begin
                                BUFFER_InAmount <= 16384; //2^14
                            end
                            00110:
                            begin
                                BUFFER_InAmount <= 8192; 
                            end
                            00111:
                            begin
                                BUFFER_InAmount <= 4096;
                            end
                            01000:
                            begin
                                BUFFER_InAmount <= 2048;
                            end
                            01001:
                            begin
                                BUFFER_InAmount <= 1024;
                            end
                            01010:
                            begin
                                BUFFER_InAmount <= 512;
                            end
                            01011:
                            begin
                                BUFFER_InAmount <= 256;
                            end
                            01100:
                            begin
                                BUFFER_InAmount <= 128;
                            end
                            01101:
                            begin
                                BUFFER_InAmount <= 64;
                            end
                            01110:
                            begin
                                BUFFER_InAmount <= 32;
                            end
                            01111:
                            begin
                                BUFFER_InAmount <= 16;
                            end
                        endcase
                    end
                    default:
                    begin
                        Reg_RdEn <= 0;
                        Reg_WrEn <= 0;
                        Buffer_RdEn <= 0;
                        BUFFER_InAmount <= 0;
                    end
                endcase
            //end
        end
    end
    
    reg [3:0] SPI_InInstructionSixteenCounter;
    reg [15:0] SPI_InBits;
    always @(posedge clk) //Get 16 bits for SPI instruction
    //Get sixteen MOSI Bits in
    //Drive on negedge and sample on pos edge so need opposite of negative edge here
    //Will stop if Buffer_RdEn or Reg_RdEn are high
    //Inputs
        //sck
        //MOSI
    //Outputs
        //new_instruction_strobe
        //new_data_strobe
        //SPI_InBits
    begin
        new_instruction_strobe <= 0;
        new_data_strobe <= 0;
        if (SlaveSel) 
        begin //Command reset
            SPI_InInstructionSixteenCounter <= 15;
            SPI_InBits <= 0;
        end
        else
        begin
            if (!Buffer_RdEn && !Reg_RdEn) //This needs to be gated so will not change instruction if performing MISO. DEBUG: DOES THIS MATTER?
            begin
                if (sck_posedge_pulse)
                begin
                    SPI_InBits[SPI_InInstructionSixteenCounter] <= MOSI;
                    
                    if (SPI_InInstructionSixteenCounter != 0)
                    begin
                        SPI_InInstructionSixteenCounter <= SPI_InInstructionSixteenCounter - 1;
                    end
                end
                if (sck_negedge_pulse)
                begin
                    if (SPI_InInstructionSixteenCounter == 8)
                    begin
                        new_instruction_strobe <= 1; //High for one clock cycle //DEBUG: STROBE ON CLK NOT SPICLK
                    end
                    
                    if (SPI_InInstructionSixteenCounter == 0)
                    begin
                        SPI_InBits[SPI_InInstructionSixteenCounter] <= MOSI; //Need this here in order to get 0th value. DEBUG: FIND A BETTER METHOD
                        new_data_strobe <= 1;
                    end
                end
            end
        end
    end
    
    always @(posedge clk) //Interpret Instruction
    begin
    //If a new instruction is recieved, parse instruction
    //Function off system clock so will not cause a delay in SPI
    //Inputs
        //new_instruction_strobe
        //SPI_InBits
        //SlaveSel
    //Outputs
        //SPI_Cmd
        //SPI_Params
        if (SlaveSel)
        begin
        
        end
        else
        begin
            if (new_instruction_strobe) //Will only be high 1 cycle
            begin
               //SPI_Instruction <= SPI_InBits[15:8]; 
               SPI_Cmd <= SPI_InBits[15:13];   
               SPI_Params <= SPI_InBits[12:8];
            end
        end
    end
    
    reg write_data_strobe;
    
    always @(posedge clk) //Write Data
    begin
    //If data bits are recieved (will only happen on a write command), write
    //Function off system clock so will not cause a delay in SPI
    //Inputs
        //new_data_strobe
        //SPI_InBits
        //SlaveSel
    //Outputs
        //SPI_Data
        //write_data_strobe- ANDed with WrEn in u_REGS
        if (SlaveSel)
        begin
        
        end
        else
        begin
            write_data_strobe <= 0;
            if (new_data_strobe) //Will only be high 1 cycle
            begin
                SPI_Data <= SPI_InBits[7:0];
                write_data_strobe <= 1;
            end
        end
    end
    
    reg [2:0] SPI_OutEightCount;
    always @(posedge clk)
    begin
    //Register Read output
    //Input
        //Reg_DataOut
    //Output
        //MISO
        if (SlaveSel)
        begin
            SPI_OutEightCount <= 7;
            MISO <= 0; //DEBUG: Default 0?
        end
        else 
        begin
            if (sck_negedge_pulse) //Drive on neg edge
            begin
                if (Reg_RdEn)
                begin
                    MISO <= Reg_DataOut[SPI_OutEightCount];
                    if (SPI_OutEightCount > 0)
                    begin
                        SPI_OutEightCount <= SPI_OutEightCount - 1;
                    end
                    else
                    begin
                    
                    end
                end
            end
        end
    end
    
    Regs u_REGS(
        .clk(clk),
        .reset(reset),
        .Write_Data(SPI_Data),
        .Regs_Addr(SPI_Params),
        .WrEn(Reg_WrEn & write_data_strobe),
        .RdEn(Reg_RdEn),
        .Read_Data(Reg_DataOut)
    );
    
    /*
    always @(posedge clk) //Get first 8 bits for SPI instruction
    //DEBUG: Split this into 2 processes
    begin
    //Inputs
        //SlaveSel
        //sclk
        //Buffer_RdEn
        //Reg_RdEn
    //Outputs
        //new_data_strobe
        //new_instruction_strobe
        //SPI_InInstructionBits
        //SPI_InDataBits
        
        new_instruction_strobe <= 0;
        new_data_strobe <= 0;
        if (SlaveSel) 
        begin //Command done
            SPI_InInstructionEightCounter <= 7;
            SPI_InDataEightCounter <= 7;
            SPI_InInstructionBits <= 0;
            SPI_InDataBits <= 0;
        end
        else
        begin
            if (!Buffer_RdEn || !Reg_RdEn) //This needs to be gated so will not change instruction if performing MISO
            begin
                if (sck_posedge_pulse)
                begin
                    if (!Reg_WrEn)
                    begin //If write command recieved, do not want this section to keep running
                        SPI_InInstructionBits[SPI_InInstructionEightCounter] <= MOSI;
                        if (SPI_InInstructionEightCounter == 0)
                        begin
                            new_instruction_strobe <= 1; //High for one clock cycle
                        end
                        else
                        begin
                            SPI_InInstructionEightCounter <= SPI_InInstructionEightCounter - 1;
                        end
                    end
                    if (Reg_WrEn) //If write commmand, continue reading 8 more MOSI
                    begin
                        SPI_InDataBits[SPI_InDataEightCounter] <= MOSI;
                        if (SPI_InDataEightCounter == 0)
                        begin
                            new_data_strobe <= 1; //High for one clock cycle
                        end
                        else
                        begin
                            SPI_InDataEightCounter <= SPI_InDataEightCounter - 1;
                        end
                    end
                end
            end
        end
    end
    */
    /*
    always @(posedge clk) //Interpret Instruction
    begin
    //If a new instruction is recieved, parse instruction
    //Function off system clock so will not cause a delay in SPI
    //Inputs
        //new_instruction_strobe
        //SPI_InInstructionBits
    //Outputs
        //SPI_Cmd
        //SPI_Params
        if (new_instruction_strobe) //Will only be high 1 cycle
        begin
            //SPI_Instruction <= SPI_InInstructionBits;
           SPI_Cmd <= SPI_InInstructionBits[7:5];   
           SPI_Params <= SPI_InInstructionBits[4:0];
        end
    end
    */
    /*
    reg write_data_strobe;
    
    always @(posedge clk) //Read Data for a write
    begin
    //If a write instruction is recieved, parse instruction and flag high for write
    //Function off system clock so will not cause a delay in SPI
    //Inputs
        //new_data_strobe
        //SPI_InDataBits
    //Outputs
        //SPI_Data
        //write_data_strobe- ANDed with WrEn in u_REGS
        write_data_strobe <= 0;
        if (new_data_strobe) //Will only be high 1 cycle
        begin
            SPI_Data <= SPI_InDataBits;
            write_data_strobe <= 1;
        end
    end */
    /*
     //The following 2 blocks should be removed because they are introcuding delay
    always @(posedge clk) //Interpret Instruction
    begin
        if (new_instruction_strobe) //Will only be high 1 cycle
        begin
            SPI_Instruction <= SPI_InInstructionBits;
        end
    end
    always @(posedge clk) //Read Data for a write
    begin
        if (new_data_strobe) //Will only be high 1 cycle
        begin
            SPI_InData <= SPI_InDataBits;
        end
    end
    
    assign SPI_Cmd = SPI_Instruction[7:5];
    assign SPI_Params = SPI_Instruction[4:0];
    assign SPI_Data = SPI_InData[7:0]; //Only used for reg write //DEBUG MOVE THIS?
    */
    
    
    
    
    
    /////////////////////////////////////
    /*
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
    always @(*) //Handle Control values //combinational
    begin //DEBUG Can be changed to sequential using new_instruction_strobe?
        //DEBUG if slavesel high, set all to 0?
        if (SlaveSel)
        begin
            Reg_RdEn = 0;
            Reg_WrEn = 0;
            Buffer_RdEn = 0;
            BUFFER_InAmount = 0;
        end
        else
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
                        01000:
                        begin
                            BUFFER_InAmount = 2048;
                        end
                        01001:
                        begin
                            BUFFER_InAmount = 1024;
                        end
                        01010:
                        begin
                            BUFFER_InAmount = 512;
                        end
                        01011:
                        begin
                            BUFFER_InAmount = 256;
                        end
                        01100:
                        begin
                            BUFFER_InAmount = 128;
                        end
                        01101:
                        begin
                            BUFFER_InAmount = 64;
                        end
                        01110:
                        begin
                            BUFFER_InAmount = 32;
                        end
                        01111:
                        begin
                            BUFFER_InAmount = 16;
                        end
                    endcase
                end
                default:
                begin
                    Reg_RdEn = 0;
                    Reg_WrEn = 0;
                    Buffer_RdEn = 0;
                    BUFFER_InAmount = 0;
                end
            endcase
        end
    end
     
    Regs u_REGS(
        .Write_Data(SPI_Data),
        .Regs_Addr(SPI_Params),
        .WrEn(Reg_WrEn & new_data_strobe),
        .RdEn(Reg_RdEn),
        .Read_Data(Reg_DataOut)
    );
    */
     
    
endmodule
