`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/10/10 09:12:12
// Design Name: 
// Module Name: Add_32bit
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
module Add_middle(
    input [3:0] a,
    input [3:0] b,
    input c_in,
    
    output reg [3:0] sum,
    output c_out
    );
    
    wire [3:0] sum1, sum2;
    wire c_out1, c_out2;
    reg c1=0;
    reg c2=1;
    Add_4bit A41(.a(a), .b(b), .c_in(c1), .sum(sum1), .c_out(c_out1));
    Add_4bit A42(.a(a), .b(b), .c_in(c2), .sum(sum2), .c_out(c_out2));
    assign c_out=c_in & c_out2 | c_out1;
    
   always @(*)begin
    if(c_in == 0) sum=sum1;
    else sum=sum2;
   end
    
endmodule


module Add_32bit(
    input [31:0] a,
    input [31:0] b,
    input ci,
    
    output [31:0]sum,
    output c_out
    );
    wire c1, c2, c3, c4, c5, c6, c7;
    Add_4bit A40(.a(a[3:0]), .b(b[3:0]), .c_in(ci), .sum(sum[3:0]), .c_out(c1));
    Add_middle AM1(.a(a[7:4]), .b(b[7:4]), .c_in(c1), .sum(sum[7:4]), .c_out(c2));
    Add_middle AM2(.a(a[11:8]), .b(b[11:8]), .c_in(c2), .sum(sum[11:8]), .c_out(c3));
    Add_middle AM3(.a(a[15:12]), .b(b[15:12]), .c_in(c3), .sum(sum[15:12]), .c_out(c4));
    Add_middle AM4(.a(a[19:16]), .b(b[19:16]), .c_in(c4), .sum(sum[19:16]), .c_out(c5));
    Add_middle AM5(.a(a[23:20]), .b(b[23:20]), .c_in(c5), .sum(sum[23:20]), .c_out(c6));
    Add_middle AM6(.a(a[27:24]), .b(b[27:24]), .c_in(c6), .sum(sum[27:24]), .c_out(c7));
    Add_middle AM7(.a(a[31:28]), .b(b[31:28]), .c_in(c7), .sum(sum[31:28]), .c_out(c_out));
endmodule
