// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2020.1 (win64) Build 2902540 Wed May 27 19:54:49 MDT 2020
// Date        : Sun Oct 15 20:12:00 2023
// Host        : DESKTOP-FT54HI7 running 64-bit major release  (build 9200)
// Command     : write_verilog -mode timesim -nolib -sdf_anno true -force -file
//               D:/Desktop/computer_designer/Add_32bit/Add_32bit.sim/sim_1/impl/timing/xsim/adder_4bits_tb_time_impl.v
// Design      : Add_32bit
// Purpose     : This verilog netlist is a timing simulation representation of the design and should not be modified or
//               synthesized. Please ensure that this netlist is used with the corresponding SDF file.
// Device      : xc7k70tfbv676-1
// --------------------------------------------------------------------------------
`timescale 1 ps / 1 ps
`define XIL_TIMING

(* ECO_CHECKSUM = "1ec7ef17" *) 
(* NotValidForBitStream *)
module Add_32bit
   (a,
    b,
    ci,
    sum,
    c_out);
  input [31:0]a;
  input [31:0]b;
  input ci;
  output [31:0]sum;
  output c_out;

  wire \A40/c_1__1 ;
  wire \AM1/A41/c_2__1 ;
  wire \AM1/A41/sum14_out ;
  wire \AM1/A42/c_2__1 ;
  wire \AM1/c_out1 ;
  wire \AM1/c_out2 ;
  wire \AM2/A41/c_2__1 ;
  wire \AM2/A41/sum14_out ;
  wire \AM2/A42/c_2__1 ;
  wire \AM2/c_out1 ;
  wire \AM2/c_out2 ;
  wire \AM3/A41/c_2__1 ;
  wire \AM3/A41/sum14_out ;
  wire \AM3/A42/c_2__1 ;
  wire \AM3/c_out1 ;
  wire \AM3/c_out2 ;
  wire \AM4/A41/c_2__1 ;
  wire \AM4/A41/sum14_out ;
  wire \AM4/A42/c_2__1 ;
  wire \AM4/c_out1 ;
  wire \AM4/c_out2 ;
  wire \AM5/A41/c_2__1 ;
  wire \AM5/A41/sum14_out ;
  wire \AM5/A42/c_2__1 ;
  wire \AM5/c_out1 ;
  wire \AM5/c_out2 ;
  wire \AM6/A41/c_2__1 ;
  wire \AM6/A41/sum14_out ;
  wire \AM6/A42/c_2__1 ;
  wire \AM6/c_out1 ;
  wire \AM6/c_out2 ;
  wire \AM7/A41/c_1__1 ;
  wire \AM7/A41/c_2__1 ;
  wire \AM7/A41/sum11_out ;
  wire \AM7/A41/sum14_out ;
  wire \AM7/A41/sum16_out ;
  wire \AM7/A41/sum1__0 ;
  wire \AM7/A42/c_1__1 ;
  wire \AM7/A42/c_2__1 ;
  wire \AM7/c_out1 ;
  wire \AM7/c_out2 ;
  wire [31:0]a;
  wire [31:0]a_IBUF;
  wire [31:0]b;
  wire [31:0]b_IBUF;
  wire c1;
  wire c2;
  wire c3;
  wire c4;
  wire c5;
  wire c6;
  wire c_out;
  wire c_out_OBUF;
  wire ci;
  wire ci_IBUF;
  wire [31:0]sum;
  wire [31:0]sum_OBUF;
  wire \sum_OBUF[31]_inst_i_10_n_0 ;

initial begin
 $sdf_annotate("adder_4bits_tb_time_impl.sdf",,,,"tool_control");
end
  IBUF \a_IBUF[0]_inst 
       (.I(a[0]),
        .O(a_IBUF[0]));
  IBUF \a_IBUF[10]_inst 
       (.I(a[10]),
        .O(a_IBUF[10]));
  IBUF \a_IBUF[11]_inst 
       (.I(a[11]),
        .O(a_IBUF[11]));
  IBUF \a_IBUF[12]_inst 
       (.I(a[12]),
        .O(a_IBUF[12]));
  IBUF \a_IBUF[13]_inst 
       (.I(a[13]),
        .O(a_IBUF[13]));
  IBUF \a_IBUF[14]_inst 
       (.I(a[14]),
        .O(a_IBUF[14]));
  IBUF \a_IBUF[15]_inst 
       (.I(a[15]),
        .O(a_IBUF[15]));
  IBUF \a_IBUF[16]_inst 
       (.I(a[16]),
        .O(a_IBUF[16]));
  IBUF \a_IBUF[17]_inst 
       (.I(a[17]),
        .O(a_IBUF[17]));
  IBUF \a_IBUF[18]_inst 
       (.I(a[18]),
        .O(a_IBUF[18]));
  IBUF \a_IBUF[19]_inst 
       (.I(a[19]),
        .O(a_IBUF[19]));
  IBUF \a_IBUF[1]_inst 
       (.I(a[1]),
        .O(a_IBUF[1]));
  IBUF \a_IBUF[20]_inst 
       (.I(a[20]),
        .O(a_IBUF[20]));
  IBUF \a_IBUF[21]_inst 
       (.I(a[21]),
        .O(a_IBUF[21]));
  IBUF \a_IBUF[22]_inst 
       (.I(a[22]),
        .O(a_IBUF[22]));
  IBUF \a_IBUF[23]_inst 
       (.I(a[23]),
        .O(a_IBUF[23]));
  IBUF \a_IBUF[24]_inst 
       (.I(a[24]),
        .O(a_IBUF[24]));
  IBUF \a_IBUF[25]_inst 
       (.I(a[25]),
        .O(a_IBUF[25]));
  IBUF \a_IBUF[26]_inst 
       (.I(a[26]),
        .O(a_IBUF[26]));
  IBUF \a_IBUF[27]_inst 
       (.I(a[27]),
        .O(a_IBUF[27]));
  IBUF \a_IBUF[28]_inst 
       (.I(a[28]),
        .O(a_IBUF[28]));
  IBUF \a_IBUF[29]_inst 
       (.I(a[29]),
        .O(a_IBUF[29]));
  IBUF \a_IBUF[2]_inst 
       (.I(a[2]),
        .O(a_IBUF[2]));
  IBUF \a_IBUF[30]_inst 
       (.I(a[30]),
        .O(a_IBUF[30]));
  IBUF \a_IBUF[31]_inst 
       (.I(a[31]),
        .O(a_IBUF[31]));
  IBUF \a_IBUF[3]_inst 
       (.I(a[3]),
        .O(a_IBUF[3]));
  IBUF \a_IBUF[4]_inst 
       (.I(a[4]),
        .O(a_IBUF[4]));
  IBUF \a_IBUF[5]_inst 
       (.I(a[5]),
        .O(a_IBUF[5]));
  IBUF \a_IBUF[6]_inst 
       (.I(a[6]),
        .O(a_IBUF[6]));
  IBUF \a_IBUF[7]_inst 
       (.I(a[7]),
        .O(a_IBUF[7]));
  IBUF \a_IBUF[8]_inst 
       (.I(a[8]),
        .O(a_IBUF[8]));
  IBUF \a_IBUF[9]_inst 
       (.I(a[9]),
        .O(a_IBUF[9]));
  IBUF \b_IBUF[0]_inst 
       (.I(b[0]),
        .O(b_IBUF[0]));
  IBUF \b_IBUF[10]_inst 
       (.I(b[10]),
        .O(b_IBUF[10]));
  IBUF \b_IBUF[11]_inst 
       (.I(b[11]),
        .O(b_IBUF[11]));
  IBUF \b_IBUF[12]_inst 
       (.I(b[12]),
        .O(b_IBUF[12]));
  IBUF \b_IBUF[13]_inst 
       (.I(b[13]),
        .O(b_IBUF[13]));
  IBUF \b_IBUF[14]_inst 
       (.I(b[14]),
        .O(b_IBUF[14]));
  IBUF \b_IBUF[15]_inst 
       (.I(b[15]),
        .O(b_IBUF[15]));
  IBUF \b_IBUF[16]_inst 
       (.I(b[16]),
        .O(b_IBUF[16]));
  IBUF \b_IBUF[17]_inst 
       (.I(b[17]),
        .O(b_IBUF[17]));
  IBUF \b_IBUF[18]_inst 
       (.I(b[18]),
        .O(b_IBUF[18]));
  IBUF \b_IBUF[19]_inst 
       (.I(b[19]),
        .O(b_IBUF[19]));
  IBUF \b_IBUF[1]_inst 
       (.I(b[1]),
        .O(b_IBUF[1]));
  IBUF \b_IBUF[20]_inst 
       (.I(b[20]),
        .O(b_IBUF[20]));
  IBUF \b_IBUF[21]_inst 
       (.I(b[21]),
        .O(b_IBUF[21]));
  IBUF \b_IBUF[22]_inst 
       (.I(b[22]),
        .O(b_IBUF[22]));
  IBUF \b_IBUF[23]_inst 
       (.I(b[23]),
        .O(b_IBUF[23]));
  IBUF \b_IBUF[24]_inst 
       (.I(b[24]),
        .O(b_IBUF[24]));
  IBUF \b_IBUF[25]_inst 
       (.I(b[25]),
        .O(b_IBUF[25]));
  IBUF \b_IBUF[26]_inst 
       (.I(b[26]),
        .O(b_IBUF[26]));
  IBUF \b_IBUF[27]_inst 
       (.I(b[27]),
        .O(b_IBUF[27]));
  IBUF \b_IBUF[28]_inst 
       (.I(b[28]),
        .O(b_IBUF[28]));
  IBUF \b_IBUF[29]_inst 
       (.I(b[29]),
        .O(b_IBUF[29]));
  IBUF \b_IBUF[2]_inst 
       (.I(b[2]),
        .O(b_IBUF[2]));
  IBUF \b_IBUF[30]_inst 
       (.I(b[30]),
        .O(b_IBUF[30]));
  IBUF \b_IBUF[31]_inst 
       (.I(b[31]),
        .O(b_IBUF[31]));
  IBUF \b_IBUF[3]_inst 
       (.I(b[3]),
        .O(b_IBUF[3]));
  IBUF \b_IBUF[4]_inst 
       (.I(b[4]),
        .O(b_IBUF[4]));
  IBUF \b_IBUF[5]_inst 
       (.I(b[5]),
        .O(b_IBUF[5]));
  IBUF \b_IBUF[6]_inst 
       (.I(b[6]),
        .O(b_IBUF[6]));
  IBUF \b_IBUF[7]_inst 
       (.I(b[7]),
        .O(b_IBUF[7]));
  IBUF \b_IBUF[8]_inst 
       (.I(b[8]),
        .O(b_IBUF[8]));
  IBUF \b_IBUF[9]_inst 
       (.I(b[9]),
        .O(b_IBUF[9]));
  OBUF c_out_OBUF_inst
       (.I(c_out_OBUF),
        .O(c_out));
  LUT5 #(
    .INIT(32'hFFFFAA80)) 
    c_out_OBUF_inst_i_1
       (.I0(\AM7/c_out2 ),
        .I1(\AM6/c_out2 ),
        .I2(c6),
        .I3(\AM6/c_out1 ),
        .I4(\AM7/c_out1 ),
        .O(c_out_OBUF));
  (* SOFT_HLUTNM = "soft_lutpair17" *) 
  LUT3 #(
    .INIT(8'hE8)) 
    c_out_OBUF_inst_i_2
       (.I0(\AM7/A42/c_2__1 ),
        .I1(b_IBUF[31]),
        .I2(a_IBUF[31]),
        .O(\AM7/c_out2 ));
  (* SOFT_HLUTNM = "soft_lutpair17" *) 
  LUT3 #(
    .INIT(8'hE8)) 
    c_out_OBUF_inst_i_3
       (.I0(\AM7/A41/c_2__1 ),
        .I1(b_IBUF[31]),
        .I2(a_IBUF[31]),
        .O(\AM7/c_out1 ));
  IBUF ci_IBUF_inst
       (.I(ci),
        .O(ci_IBUF));
  OBUF \sum_OBUF[0]_inst 
       (.I(sum_OBUF[0]),
        .O(sum[0]));
  LUT3 #(
    .INIT(8'h96)) 
    \sum_OBUF[0]_inst_i_1 
       (.I0(ci_IBUF),
        .I1(a_IBUF[0]),
        .I2(b_IBUF[0]),
        .O(sum_OBUF[0]));
  OBUF \sum_OBUF[10]_inst 
       (.I(sum_OBUF[10]),
        .O(sum[10]));
  LUT6 #(
    .INIT(64'h0317173FFCE8E8C0)) 
    \sum_OBUF[10]_inst_i_1 
       (.I0(c2),
        .I1(a_IBUF[9]),
        .I2(b_IBUF[9]),
        .I3(b_IBUF[8]),
        .I4(a_IBUF[8]),
        .I5(\AM2/A41/sum14_out ),
        .O(sum_OBUF[10]));
  LUT2 #(
    .INIT(4'h6)) 
    \sum_OBUF[10]_inst_i_2 
       (.I0(b_IBUF[10]),
        .I1(a_IBUF[10]),
        .O(\AM2/A41/sum14_out ));
  OBUF \sum_OBUF[11]_inst 
       (.I(sum_OBUF[11]),
        .O(sum[11]));
  (* SOFT_HLUTNM = "soft_lutpair10" *) 
  LUT5 #(
    .INIT(32'hB84747B8)) 
    \sum_OBUF[11]_inst_i_1 
       (.I0(\AM2/A42/c_2__1 ),
        .I1(c2),
        .I2(\AM2/A41/c_2__1 ),
        .I3(a_IBUF[11]),
        .I4(b_IBUF[11]),
        .O(sum_OBUF[11]));
  LUT6 #(
    .INIT(64'hFFFFFEE0FEE00000)) 
    \sum_OBUF[11]_inst_i_2 
       (.I0(a_IBUF[8]),
        .I1(b_IBUF[8]),
        .I2(b_IBUF[9]),
        .I3(a_IBUF[9]),
        .I4(b_IBUF[10]),
        .I5(a_IBUF[10]),
        .O(\AM2/A42/c_2__1 ));
  (* SOFT_HLUTNM = "soft_lutpair11" *) 
  LUT5 #(
    .INIT(32'hFFF0F880)) 
    \sum_OBUF[11]_inst_i_3 
       (.I0(\AM1/A42/c_2__1 ),
        .I1(c1),
        .I2(a_IBUF[7]),
        .I3(b_IBUF[7]),
        .I4(\AM1/A41/c_2__1 ),
        .O(c2));
  LUT6 #(
    .INIT(64'hFFFFF880F8800000)) 
    \sum_OBUF[11]_inst_i_4 
       (.I0(a_IBUF[8]),
        .I1(b_IBUF[8]),
        .I2(b_IBUF[9]),
        .I3(a_IBUF[9]),
        .I4(b_IBUF[10]),
        .I5(a_IBUF[10]),
        .O(\AM2/A41/c_2__1 ));
  OBUF \sum_OBUF[12]_inst 
       (.I(sum_OBUF[12]),
        .O(sum[12]));
  (* SOFT_HLUTNM = "soft_lutpair8" *) 
  LUT3 #(
    .INIT(8'h96)) 
    \sum_OBUF[12]_inst_i_1 
       (.I0(c3),
        .I1(a_IBUF[12]),
        .I2(b_IBUF[12]),
        .O(sum_OBUF[12]));
  OBUF \sum_OBUF[13]_inst 
       (.I(sum_OBUF[13]),
        .O(sum[13]));
  (* SOFT_HLUTNM = "soft_lutpair8" *) 
  LUT5 #(
    .INIT(32'hE81717E8)) 
    \sum_OBUF[13]_inst_i_1 
       (.I0(c3),
        .I1(b_IBUF[12]),
        .I2(a_IBUF[12]),
        .I3(a_IBUF[13]),
        .I4(b_IBUF[13]),
        .O(sum_OBUF[13]));
  OBUF \sum_OBUF[14]_inst 
       (.I(sum_OBUF[14]),
        .O(sum[14]));
  LUT6 #(
    .INIT(64'h0317173FFCE8E8C0)) 
    \sum_OBUF[14]_inst_i_1 
       (.I0(c3),
        .I1(a_IBUF[13]),
        .I2(b_IBUF[13]),
        .I3(b_IBUF[12]),
        .I4(a_IBUF[12]),
        .I5(\AM3/A41/sum14_out ),
        .O(sum_OBUF[14]));
  LUT2 #(
    .INIT(4'h6)) 
    \sum_OBUF[14]_inst_i_2 
       (.I0(b_IBUF[14]),
        .I1(a_IBUF[14]),
        .O(\AM3/A41/sum14_out ));
  OBUF \sum_OBUF[15]_inst 
       (.I(sum_OBUF[15]),
        .O(sum[15]));
  (* SOFT_HLUTNM = "soft_lutpair7" *) 
  LUT5 #(
    .INIT(32'hB84747B8)) 
    \sum_OBUF[15]_inst_i_1 
       (.I0(\AM3/A42/c_2__1 ),
        .I1(c3),
        .I2(\AM3/A41/c_2__1 ),
        .I3(a_IBUF[15]),
        .I4(b_IBUF[15]),
        .O(sum_OBUF[15]));
  LUT6 #(
    .INIT(64'hFFFFFEE0FEE00000)) 
    \sum_OBUF[15]_inst_i_2 
       (.I0(a_IBUF[12]),
        .I1(b_IBUF[12]),
        .I2(b_IBUF[13]),
        .I3(a_IBUF[13]),
        .I4(b_IBUF[14]),
        .I5(a_IBUF[14]),
        .O(\AM3/A42/c_2__1 ));
  LUT5 #(
    .INIT(32'hFFFFAA80)) 
    \sum_OBUF[15]_inst_i_3 
       (.I0(\AM2/c_out2 ),
        .I1(\AM1/c_out2 ),
        .I2(c1),
        .I3(\AM1/c_out1 ),
        .I4(\AM2/c_out1 ),
        .O(c3));
  LUT6 #(
    .INIT(64'hFFFFF880F8800000)) 
    \sum_OBUF[15]_inst_i_4 
       (.I0(a_IBUF[12]),
        .I1(b_IBUF[12]),
        .I2(b_IBUF[13]),
        .I3(a_IBUF[13]),
        .I4(b_IBUF[14]),
        .I5(a_IBUF[14]),
        .O(\AM3/A41/c_2__1 ));
  LUT3 #(
    .INIT(8'hE8)) 
    \sum_OBUF[15]_inst_i_5 
       (.I0(\AM2/A42/c_2__1 ),
        .I1(b_IBUF[11]),
        .I2(a_IBUF[11]),
        .O(\AM2/c_out2 ));
  (* SOFT_HLUTNM = "soft_lutpair15" *) 
  LUT3 #(
    .INIT(8'hE8)) 
    \sum_OBUF[15]_inst_i_6 
       (.I0(\AM1/A42/c_2__1 ),
        .I1(b_IBUF[7]),
        .I2(a_IBUF[7]),
        .O(\AM1/c_out2 ));
  (* SOFT_HLUTNM = "soft_lutpair15" *) 
  LUT3 #(
    .INIT(8'hE8)) 
    \sum_OBUF[15]_inst_i_7 
       (.I0(\AM1/A41/c_2__1 ),
        .I1(b_IBUF[7]),
        .I2(a_IBUF[7]),
        .O(\AM1/c_out1 ));
  (* SOFT_HLUTNM = "soft_lutpair10" *) 
  LUT3 #(
    .INIT(8'hE8)) 
    \sum_OBUF[15]_inst_i_8 
       (.I0(\AM2/A41/c_2__1 ),
        .I1(b_IBUF[11]),
        .I2(a_IBUF[11]),
        .O(\AM2/c_out1 ));
  OBUF \sum_OBUF[16]_inst 
       (.I(sum_OBUF[16]),
        .O(sum[16]));
  (* SOFT_HLUTNM = "soft_lutpair5" *) 
  LUT3 #(
    .INIT(8'h96)) 
    \sum_OBUF[16]_inst_i_1 
       (.I0(c4),
        .I1(a_IBUF[16]),
        .I2(b_IBUF[16]),
        .O(sum_OBUF[16]));
  OBUF \sum_OBUF[17]_inst 
       (.I(sum_OBUF[17]),
        .O(sum[17]));
  (* SOFT_HLUTNM = "soft_lutpair5" *) 
  LUT5 #(
    .INIT(32'hE81717E8)) 
    \sum_OBUF[17]_inst_i_1 
       (.I0(c4),
        .I1(b_IBUF[16]),
        .I2(a_IBUF[16]),
        .I3(a_IBUF[17]),
        .I4(b_IBUF[17]),
        .O(sum_OBUF[17]));
  OBUF \sum_OBUF[18]_inst 
       (.I(sum_OBUF[18]),
        .O(sum[18]));
  LUT6 #(
    .INIT(64'h0317173FFCE8E8C0)) 
    \sum_OBUF[18]_inst_i_1 
       (.I0(c4),
        .I1(a_IBUF[17]),
        .I2(b_IBUF[17]),
        .I3(b_IBUF[16]),
        .I4(a_IBUF[16]),
        .I5(\AM4/A41/sum14_out ),
        .O(sum_OBUF[18]));
  LUT2 #(
    .INIT(4'h6)) 
    \sum_OBUF[18]_inst_i_2 
       (.I0(b_IBUF[18]),
        .I1(a_IBUF[18]),
        .O(\AM4/A41/sum14_out ));
  OBUF \sum_OBUF[19]_inst 
       (.I(sum_OBUF[19]),
        .O(sum[19]));
  (* SOFT_HLUTNM = "soft_lutpair6" *) 
  LUT5 #(
    .INIT(32'hB84747B8)) 
    \sum_OBUF[19]_inst_i_1 
       (.I0(\AM4/A42/c_2__1 ),
        .I1(c4),
        .I2(\AM4/A41/c_2__1 ),
        .I3(a_IBUF[19]),
        .I4(b_IBUF[19]),
        .O(sum_OBUF[19]));
  LUT6 #(
    .INIT(64'hFFFFFEE0FEE00000)) 
    \sum_OBUF[19]_inst_i_2 
       (.I0(a_IBUF[16]),
        .I1(b_IBUF[16]),
        .I2(b_IBUF[17]),
        .I3(a_IBUF[17]),
        .I4(b_IBUF[18]),
        .I5(a_IBUF[18]),
        .O(\AM4/A42/c_2__1 ));
  (* SOFT_HLUTNM = "soft_lutpair7" *) 
  LUT5 #(
    .INIT(32'hFFF0F880)) 
    \sum_OBUF[19]_inst_i_3 
       (.I0(\AM3/A42/c_2__1 ),
        .I1(c3),
        .I2(a_IBUF[15]),
        .I3(b_IBUF[15]),
        .I4(\AM3/A41/c_2__1 ),
        .O(c4));
  LUT6 #(
    .INIT(64'hFFFFF880F8800000)) 
    \sum_OBUF[19]_inst_i_4 
       (.I0(a_IBUF[16]),
        .I1(b_IBUF[16]),
        .I2(b_IBUF[17]),
        .I3(a_IBUF[17]),
        .I4(b_IBUF[18]),
        .I5(a_IBUF[18]),
        .O(\AM4/A41/c_2__1 ));
  OBUF \sum_OBUF[1]_inst 
       (.I(sum_OBUF[1]),
        .O(sum[1]));
  (* SOFT_HLUTNM = "soft_lutpair0" *) 
  LUT5 #(
    .INIT(32'hE81717E8)) 
    \sum_OBUF[1]_inst_i_1 
       (.I0(a_IBUF[0]),
        .I1(b_IBUF[0]),
        .I2(ci_IBUF),
        .I3(a_IBUF[1]),
        .I4(b_IBUF[1]),
        .O(sum_OBUF[1]));
  OBUF \sum_OBUF[20]_inst 
       (.I(sum_OBUF[20]),
        .O(sum[20]));
  (* SOFT_HLUTNM = "soft_lutpair3" *) 
  LUT3 #(
    .INIT(8'h96)) 
    \sum_OBUF[20]_inst_i_1 
       (.I0(c5),
        .I1(a_IBUF[20]),
        .I2(b_IBUF[20]),
        .O(sum_OBUF[20]));
  OBUF \sum_OBUF[21]_inst 
       (.I(sum_OBUF[21]),
        .O(sum[21]));
  (* SOFT_HLUTNM = "soft_lutpair3" *) 
  LUT5 #(
    .INIT(32'hE81717E8)) 
    \sum_OBUF[21]_inst_i_1 
       (.I0(c5),
        .I1(b_IBUF[20]),
        .I2(a_IBUF[20]),
        .I3(a_IBUF[21]),
        .I4(b_IBUF[21]),
        .O(sum_OBUF[21]));
  OBUF \sum_OBUF[22]_inst 
       (.I(sum_OBUF[22]),
        .O(sum[22]));
  LUT6 #(
    .INIT(64'h0317173FFCE8E8C0)) 
    \sum_OBUF[22]_inst_i_1 
       (.I0(c5),
        .I1(a_IBUF[21]),
        .I2(b_IBUF[21]),
        .I3(b_IBUF[20]),
        .I4(a_IBUF[20]),
        .I5(\AM5/A41/sum14_out ),
        .O(sum_OBUF[22]));
  LUT2 #(
    .INIT(4'h6)) 
    \sum_OBUF[22]_inst_i_2 
       (.I0(b_IBUF[22]),
        .I1(a_IBUF[22]),
        .O(\AM5/A41/sum14_out ));
  OBUF \sum_OBUF[23]_inst 
       (.I(sum_OBUF[23]),
        .O(sum[23]));
  (* SOFT_HLUTNM = "soft_lutpair4" *) 
  LUT5 #(
    .INIT(32'hB84747B8)) 
    \sum_OBUF[23]_inst_i_1 
       (.I0(\AM5/A42/c_2__1 ),
        .I1(c5),
        .I2(\AM5/A41/c_2__1 ),
        .I3(a_IBUF[23]),
        .I4(b_IBUF[23]),
        .O(sum_OBUF[23]));
  LUT6 #(
    .INIT(64'hFFFFFEE0FEE00000)) 
    \sum_OBUF[23]_inst_i_2 
       (.I0(a_IBUF[20]),
        .I1(b_IBUF[20]),
        .I2(b_IBUF[21]),
        .I3(a_IBUF[21]),
        .I4(b_IBUF[22]),
        .I5(a_IBUF[22]),
        .O(\AM5/A42/c_2__1 ));
  LUT5 #(
    .INIT(32'hFFFFAA80)) 
    \sum_OBUF[23]_inst_i_3 
       (.I0(\AM4/c_out2 ),
        .I1(\AM3/c_out2 ),
        .I2(c3),
        .I3(\AM3/c_out1 ),
        .I4(\AM4/c_out1 ),
        .O(c5));
  LUT6 #(
    .INIT(64'hFFFFF880F8800000)) 
    \sum_OBUF[23]_inst_i_4 
       (.I0(a_IBUF[20]),
        .I1(b_IBUF[20]),
        .I2(b_IBUF[21]),
        .I3(a_IBUF[21]),
        .I4(b_IBUF[22]),
        .I5(a_IBUF[22]),
        .O(\AM5/A41/c_2__1 ));
  (* SOFT_HLUTNM = "soft_lutpair16" *) 
  LUT3 #(
    .INIT(8'hE8)) 
    \sum_OBUF[23]_inst_i_5 
       (.I0(\AM3/A42/c_2__1 ),
        .I1(b_IBUF[15]),
        .I2(a_IBUF[15]),
        .O(\AM3/c_out2 ));
  OBUF \sum_OBUF[24]_inst 
       (.I(sum_OBUF[24]),
        .O(sum[24]));
  (* SOFT_HLUTNM = "soft_lutpair1" *) 
  LUT3 #(
    .INIT(8'h96)) 
    \sum_OBUF[24]_inst_i_1 
       (.I0(c6),
        .I1(a_IBUF[24]),
        .I2(b_IBUF[24]),
        .O(sum_OBUF[24]));
  OBUF \sum_OBUF[25]_inst 
       (.I(sum_OBUF[25]),
        .O(sum[25]));
  (* SOFT_HLUTNM = "soft_lutpair1" *) 
  LUT5 #(
    .INIT(32'hE81717E8)) 
    \sum_OBUF[25]_inst_i_1 
       (.I0(c6),
        .I1(b_IBUF[24]),
        .I2(a_IBUF[24]),
        .I3(a_IBUF[25]),
        .I4(b_IBUF[25]),
        .O(sum_OBUF[25]));
  OBUF \sum_OBUF[26]_inst 
       (.I(sum_OBUF[26]),
        .O(sum[26]));
  LUT6 #(
    .INIT(64'h0317173FFCE8E8C0)) 
    \sum_OBUF[26]_inst_i_1 
       (.I0(c6),
        .I1(a_IBUF[25]),
        .I2(b_IBUF[25]),
        .I3(b_IBUF[24]),
        .I4(a_IBUF[24]),
        .I5(\AM6/A41/sum14_out ),
        .O(sum_OBUF[26]));
  LUT2 #(
    .INIT(4'h6)) 
    \sum_OBUF[26]_inst_i_2 
       (.I0(b_IBUF[26]),
        .I1(a_IBUF[26]),
        .O(\AM6/A41/sum14_out ));
  OBUF \sum_OBUF[27]_inst 
       (.I(sum_OBUF[27]),
        .O(sum[27]));
  (* SOFT_HLUTNM = "soft_lutpair2" *) 
  LUT5 #(
    .INIT(32'hB84747B8)) 
    \sum_OBUF[27]_inst_i_1 
       (.I0(\AM6/A42/c_2__1 ),
        .I1(c6),
        .I2(\AM6/A41/c_2__1 ),
        .I3(a_IBUF[27]),
        .I4(b_IBUF[27]),
        .O(sum_OBUF[27]));
  OBUF \sum_OBUF[28]_inst 
       (.I(sum_OBUF[28]),
        .O(sum[28]));
  LUT6 #(
    .INIT(64'h03171717FCE8E8E8)) 
    \sum_OBUF[28]_inst_i_1 
       (.I0(\AM6/A41/c_2__1 ),
        .I1(b_IBUF[27]),
        .I2(a_IBUF[27]),
        .I3(c6),
        .I4(\AM6/A42/c_2__1 ),
        .I5(\AM7/A41/sum1__0 ),
        .O(sum_OBUF[28]));
  LUT6 #(
    .INIT(64'hFFFFF880F8800000)) 
    \sum_OBUF[28]_inst_i_2 
       (.I0(a_IBUF[24]),
        .I1(b_IBUF[24]),
        .I2(b_IBUF[25]),
        .I3(a_IBUF[25]),
        .I4(b_IBUF[26]),
        .I5(a_IBUF[26]),
        .O(\AM6/A41/c_2__1 ));
  LUT6 #(
    .INIT(64'hFFFFFEE0FEE00000)) 
    \sum_OBUF[28]_inst_i_3 
       (.I0(a_IBUF[24]),
        .I1(b_IBUF[24]),
        .I2(b_IBUF[25]),
        .I3(a_IBUF[25]),
        .I4(b_IBUF[26]),
        .I5(a_IBUF[26]),
        .O(\AM6/A42/c_2__1 ));
  LUT2 #(
    .INIT(4'h6)) 
    \sum_OBUF[28]_inst_i_4 
       (.I0(b_IBUF[28]),
        .I1(a_IBUF[28]),
        .O(\AM7/A41/sum1__0 ));
  OBUF \sum_OBUF[29]_inst 
       (.I(sum_OBUF[29]),
        .O(sum[29]));
  LUT6 #(
    .INIT(64'h000707FFFFF8F800)) 
    \sum_OBUF[29]_inst_i_1 
       (.I0(\AM6/c_out2 ),
        .I1(c6),
        .I2(\AM6/c_out1 ),
        .I3(b_IBUF[28]),
        .I4(a_IBUF[28]),
        .I5(\AM7/A41/sum11_out ),
        .O(sum_OBUF[29]));
  LUT2 #(
    .INIT(4'h6)) 
    \sum_OBUF[29]_inst_i_2 
       (.I0(b_IBUF[29]),
        .I1(a_IBUF[29]),
        .O(\AM7/A41/sum11_out ));
  OBUF \sum_OBUF[2]_inst 
       (.I(sum_OBUF[2]),
        .O(sum[2]));
  LUT3 #(
    .INIT(8'h96)) 
    \sum_OBUF[2]_inst_i_1 
       (.I0(\A40/c_1__1 ),
        .I1(a_IBUF[2]),
        .I2(b_IBUF[2]),
        .O(sum_OBUF[2]));
  OBUF \sum_OBUF[30]_inst 
       (.I(sum_OBUF[30]),
        .O(sum[30]));
  LUT6 #(
    .INIT(64'h5540557FAABFAA80)) 
    \sum_OBUF[30]_inst_i_1 
       (.I0(\AM7/A42/c_1__1 ),
        .I1(\AM6/c_out2 ),
        .I2(c6),
        .I3(\AM6/c_out1 ),
        .I4(\AM7/A41/c_1__1 ),
        .I5(\AM7/A41/sum14_out ),
        .O(sum_OBUF[30]));
  (* SOFT_HLUTNM = "soft_lutpair14" *) 
  LUT4 #(
    .INIT(16'hFEE0)) 
    \sum_OBUF[30]_inst_i_2 
       (.I0(a_IBUF[28]),
        .I1(b_IBUF[28]),
        .I2(b_IBUF[29]),
        .I3(a_IBUF[29]),
        .O(\AM7/A42/c_1__1 ));
  (* SOFT_HLUTNM = "soft_lutpair14" *) 
  LUT4 #(
    .INIT(16'hF880)) 
    \sum_OBUF[30]_inst_i_3 
       (.I0(a_IBUF[28]),
        .I1(b_IBUF[28]),
        .I2(b_IBUF[29]),
        .I3(a_IBUF[29]),
        .O(\AM7/A41/c_1__1 ));
  LUT2 #(
    .INIT(4'h6)) 
    \sum_OBUF[30]_inst_i_4 
       (.I0(b_IBUF[30]),
        .I1(a_IBUF[30]),
        .O(\AM7/A41/sum14_out ));
  OBUF \sum_OBUF[31]_inst 
       (.I(sum_OBUF[31]),
        .O(sum[31]));
  LUT6 #(
    .INIT(64'h5540557FAABFAA80)) 
    \sum_OBUF[31]_inst_i_1 
       (.I0(\AM7/A42/c_2__1 ),
        .I1(\AM6/c_out2 ),
        .I2(c6),
        .I3(\AM6/c_out1 ),
        .I4(\AM7/A41/c_2__1 ),
        .I5(\AM7/A41/sum16_out ),
        .O(sum_OBUF[31]));
  LUT6 #(
    .INIT(64'hFEEEAAAA00000000)) 
    \sum_OBUF[31]_inst_i_10 
       (.I0(\AM2/c_out1 ),
        .I1(\AM1/c_out1 ),
        .I2(c1),
        .I3(\AM1/c_out2 ),
        .I4(\AM2/c_out2 ),
        .I5(\AM3/c_out2 ),
        .O(\sum_OBUF[31]_inst_i_10_n_0 ));
  (* SOFT_HLUTNM = "soft_lutpair16" *) 
  LUT3 #(
    .INIT(8'hE8)) 
    \sum_OBUF[31]_inst_i_11 
       (.I0(\AM3/A41/c_2__1 ),
        .I1(b_IBUF[15]),
        .I2(a_IBUF[15]),
        .O(\AM3/c_out1 ));
  (* SOFT_HLUTNM = "soft_lutpair6" *) 
  LUT3 #(
    .INIT(8'hE8)) 
    \sum_OBUF[31]_inst_i_12 
       (.I0(\AM4/A41/c_2__1 ),
        .I1(b_IBUF[19]),
        .I2(a_IBUF[19]),
        .O(\AM4/c_out1 ));
  (* SOFT_HLUTNM = "soft_lutpair4" *) 
  LUT3 #(
    .INIT(8'hE8)) 
    \sum_OBUF[31]_inst_i_13 
       (.I0(\AM5/A41/c_2__1 ),
        .I1(b_IBUF[23]),
        .I2(a_IBUF[23]),
        .O(\AM5/c_out1 ));
  LUT6 #(
    .INIT(64'hFFFFFEE0FEE00000)) 
    \sum_OBUF[31]_inst_i_2 
       (.I0(a_IBUF[28]),
        .I1(b_IBUF[28]),
        .I2(b_IBUF[29]),
        .I3(a_IBUF[29]),
        .I4(b_IBUF[30]),
        .I5(a_IBUF[30]),
        .O(\AM7/A42/c_2__1 ));
  LUT3 #(
    .INIT(8'hE8)) 
    \sum_OBUF[31]_inst_i_3 
       (.I0(\AM6/A42/c_2__1 ),
        .I1(b_IBUF[27]),
        .I2(a_IBUF[27]),
        .O(\AM6/c_out2 ));
  LUT6 #(
    .INIT(64'hFFFFFFFFAAAA8880)) 
    \sum_OBUF[31]_inst_i_4 
       (.I0(\AM5/c_out2 ),
        .I1(\AM4/c_out2 ),
        .I2(\sum_OBUF[31]_inst_i_10_n_0 ),
        .I3(\AM3/c_out1 ),
        .I4(\AM4/c_out1 ),
        .I5(\AM5/c_out1 ),
        .O(c6));
  (* SOFT_HLUTNM = "soft_lutpair2" *) 
  LUT3 #(
    .INIT(8'hE8)) 
    \sum_OBUF[31]_inst_i_5 
       (.I0(\AM6/A41/c_2__1 ),
        .I1(b_IBUF[27]),
        .I2(a_IBUF[27]),
        .O(\AM6/c_out1 ));
  LUT6 #(
    .INIT(64'hFFFFF880F8800000)) 
    \sum_OBUF[31]_inst_i_6 
       (.I0(a_IBUF[28]),
        .I1(b_IBUF[28]),
        .I2(b_IBUF[29]),
        .I3(a_IBUF[29]),
        .I4(b_IBUF[30]),
        .I5(a_IBUF[30]),
        .O(\AM7/A41/c_2__1 ));
  LUT2 #(
    .INIT(4'h6)) 
    \sum_OBUF[31]_inst_i_7 
       (.I0(b_IBUF[31]),
        .I1(a_IBUF[31]),
        .O(\AM7/A41/sum16_out ));
  LUT3 #(
    .INIT(8'hE8)) 
    \sum_OBUF[31]_inst_i_8 
       (.I0(\AM5/A42/c_2__1 ),
        .I1(b_IBUF[23]),
        .I2(a_IBUF[23]),
        .O(\AM5/c_out2 ));
  LUT3 #(
    .INIT(8'hE8)) 
    \sum_OBUF[31]_inst_i_9 
       (.I0(\AM4/A42/c_2__1 ),
        .I1(b_IBUF[19]),
        .I2(a_IBUF[19]),
        .O(\AM4/c_out2 ));
  OBUF \sum_OBUF[3]_inst 
       (.I(sum_OBUF[3]),
        .O(sum[3]));
  (* SOFT_HLUTNM = "soft_lutpair13" *) 
  LUT5 #(
    .INIT(32'hE81717E8)) 
    \sum_OBUF[3]_inst_i_1 
       (.I0(a_IBUF[2]),
        .I1(b_IBUF[2]),
        .I2(\A40/c_1__1 ),
        .I3(a_IBUF[3]),
        .I4(b_IBUF[3]),
        .O(sum_OBUF[3]));
  (* SOFT_HLUTNM = "soft_lutpair0" *) 
  LUT5 #(
    .INIT(32'hFFE8E800)) 
    \sum_OBUF[3]_inst_i_2 
       (.I0(ci_IBUF),
        .I1(b_IBUF[0]),
        .I2(a_IBUF[0]),
        .I3(b_IBUF[1]),
        .I4(a_IBUF[1]),
        .O(\A40/c_1__1 ));
  OBUF \sum_OBUF[4]_inst 
       (.I(sum_OBUF[4]),
        .O(sum[4]));
  (* SOFT_HLUTNM = "soft_lutpair12" *) 
  LUT3 #(
    .INIT(8'h96)) 
    \sum_OBUF[4]_inst_i_1 
       (.I0(c1),
        .I1(a_IBUF[4]),
        .I2(b_IBUF[4]),
        .O(sum_OBUF[4]));
  OBUF \sum_OBUF[5]_inst 
       (.I(sum_OBUF[5]),
        .O(sum[5]));
  (* SOFT_HLUTNM = "soft_lutpair12" *) 
  LUT5 #(
    .INIT(32'hE81717E8)) 
    \sum_OBUF[5]_inst_i_1 
       (.I0(c1),
        .I1(b_IBUF[4]),
        .I2(a_IBUF[4]),
        .I3(a_IBUF[5]),
        .I4(b_IBUF[5]),
        .O(sum_OBUF[5]));
  OBUF \sum_OBUF[6]_inst 
       (.I(sum_OBUF[6]),
        .O(sum[6]));
  LUT6 #(
    .INIT(64'h0317173FFCE8E8C0)) 
    \sum_OBUF[6]_inst_i_1 
       (.I0(c1),
        .I1(a_IBUF[5]),
        .I2(b_IBUF[5]),
        .I3(b_IBUF[4]),
        .I4(a_IBUF[4]),
        .I5(\AM1/A41/sum14_out ),
        .O(sum_OBUF[6]));
  LUT2 #(
    .INIT(4'h6)) 
    \sum_OBUF[6]_inst_i_2 
       (.I0(b_IBUF[6]),
        .I1(a_IBUF[6]),
        .O(\AM1/A41/sum14_out ));
  OBUF \sum_OBUF[7]_inst 
       (.I(sum_OBUF[7]),
        .O(sum[7]));
  (* SOFT_HLUTNM = "soft_lutpair11" *) 
  LUT5 #(
    .INIT(32'hB84747B8)) 
    \sum_OBUF[7]_inst_i_1 
       (.I0(\AM1/A42/c_2__1 ),
        .I1(c1),
        .I2(\AM1/A41/c_2__1 ),
        .I3(a_IBUF[7]),
        .I4(b_IBUF[7]),
        .O(sum_OBUF[7]));
  LUT6 #(
    .INIT(64'hFFFFFEE0FEE00000)) 
    \sum_OBUF[7]_inst_i_2 
       (.I0(a_IBUF[4]),
        .I1(b_IBUF[4]),
        .I2(b_IBUF[5]),
        .I3(a_IBUF[5]),
        .I4(b_IBUF[6]),
        .I5(a_IBUF[6]),
        .O(\AM1/A42/c_2__1 ));
  (* SOFT_HLUTNM = "soft_lutpair13" *) 
  LUT5 #(
    .INIT(32'hFFE8E800)) 
    \sum_OBUF[7]_inst_i_3 
       (.I0(\A40/c_1__1 ),
        .I1(b_IBUF[2]),
        .I2(a_IBUF[2]),
        .I3(b_IBUF[3]),
        .I4(a_IBUF[3]),
        .O(c1));
  LUT6 #(
    .INIT(64'hFFFFF880F8800000)) 
    \sum_OBUF[7]_inst_i_4 
       (.I0(a_IBUF[4]),
        .I1(b_IBUF[4]),
        .I2(b_IBUF[5]),
        .I3(a_IBUF[5]),
        .I4(b_IBUF[6]),
        .I5(a_IBUF[6]),
        .O(\AM1/A41/c_2__1 ));
  OBUF \sum_OBUF[8]_inst 
       (.I(sum_OBUF[8]),
        .O(sum[8]));
  (* SOFT_HLUTNM = "soft_lutpair9" *) 
  LUT3 #(
    .INIT(8'h96)) 
    \sum_OBUF[8]_inst_i_1 
       (.I0(c2),
        .I1(a_IBUF[8]),
        .I2(b_IBUF[8]),
        .O(sum_OBUF[8]));
  OBUF \sum_OBUF[9]_inst 
       (.I(sum_OBUF[9]),
        .O(sum[9]));
  (* SOFT_HLUTNM = "soft_lutpair9" *) 
  LUT5 #(
    .INIT(32'hE81717E8)) 
    \sum_OBUF[9]_inst_i_1 
       (.I0(c2),
        .I1(b_IBUF[8]),
        .I2(a_IBUF[8]),
        .I3(a_IBUF[9]),
        .I4(b_IBUF[9]),
        .O(sum_OBUF[9]));
endmodule
`ifndef GLBL
`define GLBL
`timescale  1 ps / 1 ps

module glbl ();

    parameter ROC_WIDTH = 100000;
    parameter TOC_WIDTH = 0;
    parameter GRES_WIDTH = 10000;
    parameter GRES_START = 10000;

//--------   STARTUP Globals --------------
    wire GSR;
    wire GTS;
    wire GWE;
    wire PRLD;
    wire GRESTORE;
    tri1 p_up_tmp;
    tri (weak1, strong0) PLL_LOCKG = p_up_tmp;

    wire PROGB_GLBL;
    wire CCLKO_GLBL;
    wire FCSBO_GLBL;
    wire [3:0] DO_GLBL;
    wire [3:0] DI_GLBL;
   
    reg GSR_int;
    reg GTS_int;
    reg PRLD_int;
    reg GRESTORE_int;

//--------   JTAG Globals --------------
    wire JTAG_TDO_GLBL;
    wire JTAG_TCK_GLBL;
    wire JTAG_TDI_GLBL;
    wire JTAG_TMS_GLBL;
    wire JTAG_TRST_GLBL;

    reg JTAG_CAPTURE_GLBL;
    reg JTAG_RESET_GLBL;
    reg JTAG_SHIFT_GLBL;
    reg JTAG_UPDATE_GLBL;
    reg JTAG_RUNTEST_GLBL;

    reg JTAG_SEL1_GLBL = 0;
    reg JTAG_SEL2_GLBL = 0 ;
    reg JTAG_SEL3_GLBL = 0;
    reg JTAG_SEL4_GLBL = 0;

    reg JTAG_USER_TDO1_GLBL = 1'bz;
    reg JTAG_USER_TDO2_GLBL = 1'bz;
    reg JTAG_USER_TDO3_GLBL = 1'bz;
    reg JTAG_USER_TDO4_GLBL = 1'bz;

    assign (strong1, weak0) GSR = GSR_int;
    assign (strong1, weak0) GTS = GTS_int;
    assign (weak1, weak0) PRLD = PRLD_int;
    assign (strong1, weak0) GRESTORE = GRESTORE_int;

    initial begin
	GSR_int = 1'b1;
	PRLD_int = 1'b1;
	#(ROC_WIDTH)
	GSR_int = 1'b0;
	PRLD_int = 1'b0;
    end

    initial begin
	GTS_int = 1'b1;
	#(TOC_WIDTH)
	GTS_int = 1'b0;
    end

    initial begin 
	GRESTORE_int = 1'b0;
	#(GRES_START);
	GRESTORE_int = 1'b1;
	#(GRES_WIDTH);
	GRESTORE_int = 1'b0;
    end

endmodule
`endif
