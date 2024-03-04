`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/12/16 11:52:00
// Design Name: 
// Module Name: IFID
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module IFID(
    input clk, 
    input en, 
    input reset, 
    input[31:0] PC_if, 
    input[31:0] Instruction_if,
    
    output reg [31:0]PC_id, 
    output reg [31:0]Instruction_id
    );

    always@(posedge clk)
    begin
        if(reset)
        begin
            PC_id <= 0;
            Instruction_id <= 0;
        end
        else if(en)
        begin
            PC_id <= PC_if;
            Instruction_id <= Instruction_if;
        end
        else
        begin
            PC_id <= PC_id;
            Instruction_id <= Instruction_id;
        end
    end
 
endmodule
