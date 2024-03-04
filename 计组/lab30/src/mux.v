`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/12/05 08:08:52
// Design Name: 
// Module Name: mux
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


module mux(
    input[31:0] a,
    input[31:0] b,
    input[31:0] c,
    input[1:0] select,
    
    output reg[31:0] result
    );
    
    always@(*) begin
        case(select)
            0: result=a;
            1: result=b;
            2: result=c;
            default: result=a;
        endcase
    end
    
endmodule
