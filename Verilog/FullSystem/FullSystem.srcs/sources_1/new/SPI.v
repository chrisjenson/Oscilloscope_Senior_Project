`timescale 1ns / 1ps

module SPI(
        output reg MISO,
        input MOSI_Raw,
        input SlaveSel,
        input clk,
        input reset,
        input SCLK_Raw,
        //For debug
        output DebugWriteReceived,
        output DebugSlaveSel,
        output DebugMOSI,
        output DebugSCLK,
        output [7:0] DebugSPI_Ins,
        //For RAM
        output reg [17:0] BUFFER_InAmount,
        input [15:0] Buffer_DataIn, //DEBUG Changed this to 16 bits
        output reg FIFO_OutRTR,
        //Regs
        output reg [7:0] SPI_Data,
        output reg [4:0] SPI_Params,
        output reg Reg_WrEn,
        output reg Reg_RdEn,
        output reg write_data_strobe,
        output reg Buffer_RdEn,
        input [7:0] Reg_DataOut
    );
  //  reg write_data_strobe;
    reg [2:0] SPI_Cmd; 

    
   // reg Reg_WrEn;
    //reg Reg_RdEn;
    //reg Buffer_RdEn;
    
    
    assign DebugSPI_Ins = {SPI_Cmd,SPI_Params};
    assign DebugWriteReceived = Reg_WrEn & write_data_strobe;
    assign DebugSlaveSel = SlaveSel;
    assign DebugMOSI = MOSI_Raw;
    assign DebugSCLK = SCLK_Raw;
    
    //reg [3:0] SPI_OutSixteenCount;
    //reg [3:0] SPI_InSixteenCount;
    //reg [2:0] SPI_InEightCounter;
    
    //reg [2:0] SPI_OutEightCount;
    
//    wire [2:0] SPI_Cmd;
//    wire [4:0] SPI_Params;
//    wire [7:0] SPI_Data;
 //   reg [4:0] SPI_Params;
    
    
    //reg [15:0] SPIWord; //spiword is valid on the last possckposedgepulse of the word
    //reg [15:0] SPI_DataIn;
    
    //assign SPI_Cmd = SPIWord[15:13];
    //assign SPI_Params = SPIWord[12:8];
    //assign SPI_Data = SPIWord[7:0];
        
    //wire [7:0] Reg_DataOut;//Wires between modules are always modules
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
    //reg [18:0] BUFFER_InAmount;// geting sent to RAM_Read_Engine
    
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
                            5'b00000:
                            begin
                                BUFFER_InAmount <= 524288; //2^19 = max ram size
                            end
                            5'b00001:
                            begin
                                BUFFER_InAmount <= 262144; //2^18
                            end
                            5'b00010:
                            begin
                                BUFFER_InAmount <= 131072;
                            end
                            5'b00011:
                            begin
                                BUFFER_InAmount <= 65536;
                            end
                            5'b00100:
                            begin
                                BUFFER_InAmount <= 32768;
                            end
                            5'b00101:
                            begin
                                BUFFER_InAmount <= 16384; //2^14
                            end
                            5'b00110:
                            begin
                                BUFFER_InAmount <= 8192; 
                            end
                            5'b00111:
                            begin
                                BUFFER_InAmount <= 4096;
                            end
                            5'b01000:
                            begin
                                BUFFER_InAmount <= 2048;
                            end
                            5'b01001:
                            begin
                                BUFFER_InAmount <= 1024;
                            end
                            5'b01010:
                            begin
                                BUFFER_InAmount <= 512;
                            end
                            5'b01011:
                            begin
                                BUFFER_InAmount <= 256;
                            end
                            5'b01100:
                            begin
                                BUFFER_InAmount <= 128;
                            end
                            5'b01101:
                            begin
                                BUFFER_InAmount <= 64;
                            end
                            5'b01110:
                            begin
                                BUFFER_InAmount <= 32;
                            end
                            5'b01111:
                            begin
                                BUFFER_InAmount <= 16;
                            end
                            default:
                            begin
                                BUFFER_InAmount <= 0;
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
    //Will stop if Buffer_RdEn or Reg_RdEn are high (MISO is active)
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
               // end
              //  if (sck_negedge_pulse)
              //  begin
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
            SPI_Cmd <= 0;   
            SPI_Params <= 0;
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
    
    //reg write_data_strobe;
    
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
        write_data_strobe <= 0;
        if (SlaveSel)
        begin
        
        end
        else
        begin
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
    

    
    
endmodule
