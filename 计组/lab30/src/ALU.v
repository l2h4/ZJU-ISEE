//******************************************************************************
// MIPS verilog model
//
// ALU.v
//******************************************************************************

module ALU (
	// Outputs
	   ALUResult,
	// Inputs
	   ALUCode, A, B);
	input [3:0]	ALUCode;				// Operation select
	input [31:0]	A, B;
	output reg [31:0]	ALUResult;
	
// Decoded ALU operation select (ALUsel) signals
   parameter	 alu_add=  4'b0000;
   parameter	 alu_sub=  4'b0001;
   parameter	 alu_lui=  4'b0010;
   parameter	 alu_and=  4'b0011;
   parameter	 alu_xor=  4'b0100;
   parameter	 alu_or =  4'b0101;
   parameter 	 alu_sll=  4'b0110;
   parameter	 alu_srl=  4'b0111;
   parameter	 alu_sra=  4'b1000;
   parameter	 alu_slt=  4'b1001;
   parameter	 alu_sltu= 4'b1010; 	
   
   wire c1, c2;
   wire [31:0]result_add, result_sub, result_slt, result_sltu;
   wire [31:0]B_sub;
   wire signed [31:0] A_sign;
   assign A_sign=A;
   
    assign B_sub=~B;
    Add_32bit ADD_alu1(.a(A), .b(B), .ci(0), .sum(result_add), .c_out(c1));
    Add_32bit ADD_alu2(.a(A), .b(B_sub), .ci(1), .sum(result_sub), .c_out(c2));
    
    always@(*) begin
        case(ALUCode)
            alu_add: ALUResult=result_add;
            alu_sub: ALUResult=result_sub;
            alu_lui: ALUResult=B;
            alu_and: ALUResult=A&B;
            alu_xor: ALUResult=A^B;
            alu_or:  ALUResult=A|B;
            alu_sll: ALUResult=A<<B;
            alu_srl: ALUResult=A>>B;
            alu_sra: ALUResult=A_sign>>>B;
            alu_slt: ALUResult= (c2==1)? 1:0;
            alu_sltu:
            begin
                if(A<B) ALUResult=1;
                else ALUResult=0;
            end
            default: ALUResult=result_add;
        endcase
    end
endmodule