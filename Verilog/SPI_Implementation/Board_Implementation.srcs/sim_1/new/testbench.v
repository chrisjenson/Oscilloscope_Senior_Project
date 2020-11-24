`timescale 1ns / 1ps

module testbench();

    reg clk;
    reg rst;
    reg SCLK;
    reg [1:0] SCLKCount;
    
    reg MISO;
    reg MOSI;
    reg SlaveSel;

    wire [15:0] command;
    reg [3:0] index;
    reg commandDone;
    reg [5:0] commandNum;
    reg [15:0] commandArray[3:0];
    initial
    begin
        commandNum <= 0;
        rst <= 1;
        SlaveSel <= 1;
        clk = 0;
        SCLK = 1;
        SCLKCount = 0;
        index = 15;
        while (1)
            #5 clk = ~clk;  // toggle clk each 5 ns (100 MHz clock frequency)
    end
    
    initial
    begin  
        commandArray[1] = 16'b0010010011111111; //cmd = Read, params = 4, data = x
        commandArray[0] = 16'b0100010011111111; //cmd = write, params = 4, data = 8'hFF
        commandArray[2] = 16'b0100010011110000; //cmd = write, params = 4, data = 8'hF0
        commandArray[3] = 16'b0010010011111111; //cmd = Read, params = 4, data = x
    end
    
    always @(posedge clk) //Generate Slave Clock
    begin
        if (!SlaveSel)
        begin
            SCLKCount <= SCLKCount + 1;
            if (SCLKCount == 2'b01)
            begin
                #1 SCLK = ~SCLK;
            end
        end
    end
    initial 
    begin
        #210
        SlaveSel <=0;
        rst <= 0;
    end
    
    always @(posedge clk)
    begin
        if (commandDone)
        begin
            //#25
            SlaveSel <= 0;
        end
    end
    
    assign command = commandArray[commandNum];
    
    always @(posedge SCLK)
    begin
        if (!SlaveSel)
        begin
            MOSI <= command[index];
            index <= index - 1;
            if (index == 0)
            begin
                #40 
                SlaveSel <= 1;
                commandNum <= commandNum + 1;
                commandDone <= 1;
            end
        end
        else
        begin
            MOSI <= 0;
            index <= 15;
        end
    end
    
    Top u_Top(
        .rst_(rst),
        .MOSI_Raw(MOSI),
        .SlaveSel(SlaveSel),
        .clk(clk),
        .SCLK_Raw(SCLK)
    );
endmodule
