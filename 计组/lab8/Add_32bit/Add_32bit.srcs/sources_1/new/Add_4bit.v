`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/10/10 08:42:00
// Design Name: 
// Module Name: Add_4bit
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


module Add_4bit(
  input[3:0] a,
  input[3:0] b,
  input c_in,
  
  output[3:0] sum,
  output c_out
  );
    wire[3:0] g,p,c;
  
    assign p=a^b;
    assign g=a&b;
    assign c[0]=g[0]|(p[0]&c_in);
    assign c[1]=g[1]|(p[1]&(g[0]|(p[0]&c_in)));
    assign c[2]=g[2]|(p[2]&(g[1]|(p[1]&(g[0]|(p[0]&c_in)))));
    assign c[3]=g[3]|(p[3]&(g[2]|(p[2]&(g[1]|(p[1]&(g[0]|(p[0]&c_in)))))));
    assign c_out=c[3];
    
    assign sum[0]=p[0]&(!g[0])^c_in;
    assign sum[1]=p[1]&(!g[1])^c[0];
    assign sum[2]=p[2]&(!g[2])^c[1];
    assign sum[3]=p[3]&(!g[3])^c[2];

endmodule
