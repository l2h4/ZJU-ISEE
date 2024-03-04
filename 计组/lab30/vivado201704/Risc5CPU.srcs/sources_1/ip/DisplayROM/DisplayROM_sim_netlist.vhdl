-- Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2020.1 (win64) Build 2902540 Wed May 27 19:54:49 MDT 2020
-- Date        : Fri Dec 29 14:54:05 2023
-- Host        : DESKTOP-FT54HI7 running 64-bit major release  (build 9200)
-- Command     : write_vhdl -force -mode funcsim
--               d:/Desktop/lab30_Risc5CPU/vivado201704/Risc5CPU.srcs/sources_1/ip/DisplayROM/DisplayROM_sim_netlist.vhdl
-- Design      : DisplayROM
-- Purpose     : This VHDL netlist is a functional simulation representation of the design and should not be modified or
--               synthesized. This netlist cannot be used for SDF annotated simulation.
-- Device      : xc7a200tfbg484-1
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity DisplayROM_rom is
  port (
    qspo : out STD_LOGIC_VECTOR ( 7 downto 0 );
    a : in STD_LOGIC_VECTOR ( 7 downto 0 );
    clk : in STD_LOGIC
  );
  attribute ORIG_REF_NAME : string;
  attribute ORIG_REF_NAME of DisplayROM_rom : entity is "rom";
end DisplayROM_rom;

architecture STRUCTURE of DisplayROM_rom is
  signal \qspo_int[0]_i_1_n_0\ : STD_LOGIC;
  signal \qspo_int[0]_i_2_n_0\ : STD_LOGIC;
  signal \qspo_int[1]_i_4_n_0\ : STD_LOGIC;
  signal \qspo_int[1]_i_5_n_0\ : STD_LOGIC;
  signal \qspo_int[1]_i_6_n_0\ : STD_LOGIC;
  signal \qspo_int[1]_i_7_n_0\ : STD_LOGIC;
  signal \qspo_int[2]_i_4_n_0\ : STD_LOGIC;
  signal \qspo_int[2]_i_5_n_0\ : STD_LOGIC;
  signal \qspo_int[2]_i_6_n_0\ : STD_LOGIC;
  signal \qspo_int[2]_i_7_n_0\ : STD_LOGIC;
  signal \qspo_int[3]_i_4_n_0\ : STD_LOGIC;
  signal \qspo_int[3]_i_5_n_0\ : STD_LOGIC;
  signal \qspo_int[3]_i_6_n_0\ : STD_LOGIC;
  signal \qspo_int[3]_i_7_n_0\ : STD_LOGIC;
  signal \qspo_int[4]_i_4_n_0\ : STD_LOGIC;
  signal \qspo_int[4]_i_5_n_0\ : STD_LOGIC;
  signal \qspo_int[4]_i_6_n_0\ : STD_LOGIC;
  signal \qspo_int[4]_i_7_n_0\ : STD_LOGIC;
  signal \qspo_int[5]_i_4_n_0\ : STD_LOGIC;
  signal \qspo_int[5]_i_5_n_0\ : STD_LOGIC;
  signal \qspo_int[5]_i_6_n_0\ : STD_LOGIC;
  signal \qspo_int[5]_i_7_n_0\ : STD_LOGIC;
  signal \qspo_int[6]_i_4_n_0\ : STD_LOGIC;
  signal \qspo_int[6]_i_5_n_0\ : STD_LOGIC;
  signal \qspo_int[6]_i_6_n_0\ : STD_LOGIC;
  signal \qspo_int[6]_i_7_n_0\ : STD_LOGIC;
  signal \qspo_int[7]_i_1_n_0\ : STD_LOGIC;
  signal \qspo_int[7]_i_2_n_0\ : STD_LOGIC;
  signal \qspo_int[7]_i_3_n_0\ : STD_LOGIC;
  signal \qspo_int_reg[1]_i_1_n_0\ : STD_LOGIC;
  signal \qspo_int_reg[1]_i_2_n_0\ : STD_LOGIC;
  signal \qspo_int_reg[1]_i_3_n_0\ : STD_LOGIC;
  signal \qspo_int_reg[2]_i_1_n_0\ : STD_LOGIC;
  signal \qspo_int_reg[2]_i_2_n_0\ : STD_LOGIC;
  signal \qspo_int_reg[2]_i_3_n_0\ : STD_LOGIC;
  signal \qspo_int_reg[3]_i_1_n_0\ : STD_LOGIC;
  signal \qspo_int_reg[3]_i_2_n_0\ : STD_LOGIC;
  signal \qspo_int_reg[3]_i_3_n_0\ : STD_LOGIC;
  signal \qspo_int_reg[4]_i_1_n_0\ : STD_LOGIC;
  signal \qspo_int_reg[4]_i_2_n_0\ : STD_LOGIC;
  signal \qspo_int_reg[4]_i_3_n_0\ : STD_LOGIC;
  signal \qspo_int_reg[5]_i_1_n_0\ : STD_LOGIC;
  signal \qspo_int_reg[5]_i_2_n_0\ : STD_LOGIC;
  signal \qspo_int_reg[5]_i_3_n_0\ : STD_LOGIC;
  signal \qspo_int_reg[6]_i_1_n_0\ : STD_LOGIC;
  signal \qspo_int_reg[6]_i_2_n_0\ : STD_LOGIC;
  signal \qspo_int_reg[6]_i_3_n_0\ : STD_LOGIC;
begin
\qspo_int[0]_i_1\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"1000000000000000"
    )
        port map (
      I0 => a(6),
      I1 => a(4),
      I2 => \qspo_int[0]_i_2_n_0\,
      I3 => a(2),
      I4 => a(5),
      I5 => a(7),
      O => \qspo_int[0]_i_1_n_0\
    );
\qspo_int[0]_i_2\: unisim.vcomponents.LUT3
    generic map(
      INIT => X"40"
    )
        port map (
      I0 => a(1),
      I1 => a(3),
      I2 => a(0),
      O => \qspo_int[0]_i_2_n_0\
    );
\qspo_int[1]_i_4\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"0828082014B434A4"
    )
        port map (
      I0 => a(5),
      I1 => a(3),
      I2 => a(2),
      I3 => a(1),
      I4 => a(0),
      I5 => a(4),
      O => \qspo_int[1]_i_4_n_0\
    );
\qspo_int[1]_i_5\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"06160C0007000000"
    )
        port map (
      I0 => a(5),
      I1 => a(4),
      I2 => a(2),
      I3 => a(1),
      I4 => a(3),
      I5 => a(0),
      O => \qspo_int[1]_i_5_n_0\
    );
\qspo_int[1]_i_6\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"00FD450023C45100"
    )
        port map (
      I0 => a(5),
      I1 => a(4),
      I2 => a(0),
      I3 => a(2),
      I4 => a(3),
      I5 => a(1),
      O => \qspo_int[1]_i_6_n_0\
    );
\qspo_int[1]_i_7\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"0471054004402B40"
    )
        port map (
      I0 => a(5),
      I1 => a(4),
      I2 => a(3),
      I3 => a(2),
      I4 => a(1),
      I5 => a(0),
      O => \qspo_int[1]_i_7_n_0\
    );
\qspo_int[2]_i_4\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"0220488522000088"
    )
        port map (
      I0 => a(5),
      I1 => a(3),
      I2 => a(4),
      I3 => a(0),
      I4 => a(1),
      I5 => a(2),
      O => \qspo_int[2]_i_4_n_0\
    );
\qspo_int[2]_i_5\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"011101771F9010B0"
    )
        port map (
      I0 => a(5),
      I1 => a(4),
      I2 => a(2),
      I3 => a(1),
      I4 => a(0),
      I5 => a(3),
      O => \qspo_int[2]_i_5_n_0\
    );
\qspo_int[2]_i_6\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"000F058002F280C0"
    )
        port map (
      I0 => a(5),
      I1 => a(2),
      I2 => a(4),
      I3 => a(1),
      I4 => a(3),
      I5 => a(0),
      O => \qspo_int[2]_i_6_n_0\
    );
\qspo_int[2]_i_7\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"000B200000005040"
    )
        port map (
      I0 => a(5),
      I1 => a(4),
      I2 => a(2),
      I3 => a(3),
      I4 => a(1),
      I5 => a(0),
      O => \qspo_int[2]_i_7_n_0\
    );
\qspo_int[3]_i_4\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"008BF20000000000"
    )
        port map (
      I0 => a(5),
      I1 => a(4),
      I2 => a(2),
      I3 => a(3),
      I4 => a(1),
      I5 => a(0),
      O => \qspo_int[3]_i_4_n_0\
    );
\qspo_int[3]_i_5\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"0070EE0001008010"
    )
        port map (
      I0 => a(5),
      I1 => a(4),
      I2 => a(2),
      I3 => a(1),
      I4 => a(3),
      I5 => a(0),
      O => \qspo_int[3]_i_5_n_0\
    );
\qspo_int[3]_i_6\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"0000AD20D6012000"
    )
        port map (
      I0 => a(5),
      I1 => a(4),
      I2 => a(2),
      I3 => a(0),
      I4 => a(3),
      I5 => a(1),
      O => \qspo_int[3]_i_6_n_0\
    );
\qspo_int[3]_i_7\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"00CF7CC000C00C00"
    )
        port map (
      I0 => a(4),
      I1 => a(5),
      I2 => a(2),
      I3 => a(3),
      I4 => a(1),
      I5 => a(0),
      O => \qspo_int[3]_i_7_n_0\
    );
\qspo_int[4]_i_4\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"04CFF44006404440"
    )
        port map (
      I0 => a(5),
      I1 => a(4),
      I2 => a(2),
      I3 => a(3),
      I4 => a(1),
      I5 => a(0),
      O => \qspo_int[4]_i_4_n_0\
    );
\qspo_int[4]_i_5\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"08F86E1009880000"
    )
        port map (
      I0 => a(5),
      I1 => a(4),
      I2 => a(2),
      I3 => a(1),
      I4 => a(3),
      I5 => a(0),
      O => \qspo_int[4]_i_5_n_0\
    );
\qspo_int[4]_i_6\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"00008F00D6012020"
    )
        port map (
      I0 => a(5),
      I1 => a(4),
      I2 => a(2),
      I3 => a(0),
      I4 => a(3),
      I5 => a(1),
      O => \qspo_int[4]_i_6_n_0\
    );
\qspo_int[4]_i_7\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"00CF700000000000"
    )
        port map (
      I0 => a(4),
      I1 => a(5),
      I2 => a(2),
      I3 => a(3),
      I4 => a(1),
      I5 => a(0),
      O => \qspo_int[4]_i_7_n_0\
    );
\qspo_int[5]_i_4\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"0000C8152A000000"
    )
        port map (
      I0 => a(5),
      I1 => a(3),
      I2 => a(4),
      I3 => a(0),
      I4 => a(1),
      I5 => a(2),
      O => \qspo_int[5]_i_4_n_0\
    );
\qspo_int[5]_i_5\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"00401C0001261020"
    )
        port map (
      I0 => a(5),
      I1 => a(4),
      I2 => a(2),
      I3 => a(1),
      I4 => a(3),
      I5 => a(0),
      O => \qspo_int[5]_i_5_n_0\
    );
\qspo_int[5]_i_6\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"00CFAD0000520840"
    )
        port map (
      I0 => a(5),
      I1 => a(2),
      I2 => a(4),
      I3 => a(1),
      I4 => a(3),
      I5 => a(0),
      O => \qspo_int[5]_i_6_n_0\
    );
\qspo_int[5]_i_7\: unisim.vcomponents.LUT5
    generic map(
      INIT => X"0BC00000"
    )
        port map (
      I0 => a(5),
      I1 => a(2),
      I2 => a(3),
      I3 => a(1),
      I4 => a(0),
      O => \qspo_int[5]_i_7_n_0\
    );
\qspo_int[6]_i_4\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"006A911113BE0000"
    )
        port map (
      I0 => a(5),
      I1 => a(4),
      I2 => a(0),
      I3 => a(1),
      I4 => a(2),
      I5 => a(3),
      O => \qspo_int[6]_i_4_n_0\
    );
\qspo_int[6]_i_5\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"06060E4C6C303070"
    )
        port map (
      I0 => a(5),
      I1 => a(4),
      I2 => a(3),
      I3 => a(0),
      I4 => a(1),
      I5 => a(2),
      O => \qspo_int[6]_i_5_n_0\
    );
\qspo_int[6]_i_6\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"00BBCD80AB88D900"
    )
        port map (
      I0 => a(5),
      I1 => a(4),
      I2 => a(0),
      I3 => a(2),
      I4 => a(3),
      I5 => a(1),
      O => \qspo_int[6]_i_6_n_0\
    );
\qspo_int[6]_i_7\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"0FEEEEF00EFEE0F0"
    )
        port map (
      I0 => a(5),
      I1 => a(4),
      I2 => a(2),
      I3 => a(1),
      I4 => a(3),
      I5 => a(0),
      O => \qspo_int[6]_i_7_n_0\
    );
\qspo_int[7]_i_1\: unisim.vcomponents.LUT4
    generic map(
      INIT => X"E200"
    )
        port map (
      I0 => \qspo_int[7]_i_2_n_0\,
      I1 => a(6),
      I2 => \qspo_int[7]_i_3_n_0\,
      I3 => a(7),
      O => \qspo_int[7]_i_1_n_0\
    );
\qspo_int[7]_i_2\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"2400200000000000"
    )
        port map (
      I0 => a(2),
      I1 => a(1),
      I2 => a(3),
      I3 => a(0),
      I4 => a(4),
      I5 => a(5),
      O => \qspo_int[7]_i_2_n_0\
    );
\qspo_int[7]_i_3\: unisim.vcomponents.LUT6
    generic map(
      INIT => X"00E101011E001000"
    )
        port map (
      I0 => a(5),
      I1 => a(4),
      I2 => a(2),
      I3 => a(1),
      I4 => a(0),
      I5 => a(3),
      O => \qspo_int[7]_i_3_n_0\
    );
\qspo_int_reg[0]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => clk,
      CE => '1',
      D => \qspo_int[0]_i_1_n_0\,
      Q => qspo(0),
      R => '0'
    );
\qspo_int_reg[1]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => clk,
      CE => '1',
      D => \qspo_int_reg[1]_i_1_n_0\,
      Q => qspo(1),
      R => '0'
    );
\qspo_int_reg[1]_i_1\: unisim.vcomponents.MUXF8
     port map (
      I0 => \qspo_int_reg[1]_i_2_n_0\,
      I1 => \qspo_int_reg[1]_i_3_n_0\,
      O => \qspo_int_reg[1]_i_1_n_0\,
      S => a(7)
    );
\qspo_int_reg[1]_i_2\: unisim.vcomponents.MUXF7
     port map (
      I0 => \qspo_int[1]_i_4_n_0\,
      I1 => \qspo_int[1]_i_5_n_0\,
      O => \qspo_int_reg[1]_i_2_n_0\,
      S => a(6)
    );
\qspo_int_reg[1]_i_3\: unisim.vcomponents.MUXF7
     port map (
      I0 => \qspo_int[1]_i_6_n_0\,
      I1 => \qspo_int[1]_i_7_n_0\,
      O => \qspo_int_reg[1]_i_3_n_0\,
      S => a(6)
    );
\qspo_int_reg[2]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => clk,
      CE => '1',
      D => \qspo_int_reg[2]_i_1_n_0\,
      Q => qspo(2),
      R => '0'
    );
\qspo_int_reg[2]_i_1\: unisim.vcomponents.MUXF8
     port map (
      I0 => \qspo_int_reg[2]_i_2_n_0\,
      I1 => \qspo_int_reg[2]_i_3_n_0\,
      O => \qspo_int_reg[2]_i_1_n_0\,
      S => a(7)
    );
\qspo_int_reg[2]_i_2\: unisim.vcomponents.MUXF7
     port map (
      I0 => \qspo_int[2]_i_4_n_0\,
      I1 => \qspo_int[2]_i_5_n_0\,
      O => \qspo_int_reg[2]_i_2_n_0\,
      S => a(6)
    );
\qspo_int_reg[2]_i_3\: unisim.vcomponents.MUXF7
     port map (
      I0 => \qspo_int[2]_i_6_n_0\,
      I1 => \qspo_int[2]_i_7_n_0\,
      O => \qspo_int_reg[2]_i_3_n_0\,
      S => a(6)
    );
\qspo_int_reg[3]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => clk,
      CE => '1',
      D => \qspo_int_reg[3]_i_1_n_0\,
      Q => qspo(3),
      R => '0'
    );
\qspo_int_reg[3]_i_1\: unisim.vcomponents.MUXF8
     port map (
      I0 => \qspo_int_reg[3]_i_2_n_0\,
      I1 => \qspo_int_reg[3]_i_3_n_0\,
      O => \qspo_int_reg[3]_i_1_n_0\,
      S => a(7)
    );
\qspo_int_reg[3]_i_2\: unisim.vcomponents.MUXF7
     port map (
      I0 => \qspo_int[3]_i_4_n_0\,
      I1 => \qspo_int[3]_i_5_n_0\,
      O => \qspo_int_reg[3]_i_2_n_0\,
      S => a(6)
    );
\qspo_int_reg[3]_i_3\: unisim.vcomponents.MUXF7
     port map (
      I0 => \qspo_int[3]_i_6_n_0\,
      I1 => \qspo_int[3]_i_7_n_0\,
      O => \qspo_int_reg[3]_i_3_n_0\,
      S => a(6)
    );
\qspo_int_reg[4]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => clk,
      CE => '1',
      D => \qspo_int_reg[4]_i_1_n_0\,
      Q => qspo(4),
      R => '0'
    );
\qspo_int_reg[4]_i_1\: unisim.vcomponents.MUXF8
     port map (
      I0 => \qspo_int_reg[4]_i_2_n_0\,
      I1 => \qspo_int_reg[4]_i_3_n_0\,
      O => \qspo_int_reg[4]_i_1_n_0\,
      S => a(7)
    );
\qspo_int_reg[4]_i_2\: unisim.vcomponents.MUXF7
     port map (
      I0 => \qspo_int[4]_i_4_n_0\,
      I1 => \qspo_int[4]_i_5_n_0\,
      O => \qspo_int_reg[4]_i_2_n_0\,
      S => a(6)
    );
\qspo_int_reg[4]_i_3\: unisim.vcomponents.MUXF7
     port map (
      I0 => \qspo_int[4]_i_6_n_0\,
      I1 => \qspo_int[4]_i_7_n_0\,
      O => \qspo_int_reg[4]_i_3_n_0\,
      S => a(6)
    );
\qspo_int_reg[5]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => clk,
      CE => '1',
      D => \qspo_int_reg[5]_i_1_n_0\,
      Q => qspo(5),
      R => '0'
    );
\qspo_int_reg[5]_i_1\: unisim.vcomponents.MUXF8
     port map (
      I0 => \qspo_int_reg[5]_i_2_n_0\,
      I1 => \qspo_int_reg[5]_i_3_n_0\,
      O => \qspo_int_reg[5]_i_1_n_0\,
      S => a(7)
    );
\qspo_int_reg[5]_i_2\: unisim.vcomponents.MUXF7
     port map (
      I0 => \qspo_int[5]_i_4_n_0\,
      I1 => \qspo_int[5]_i_5_n_0\,
      O => \qspo_int_reg[5]_i_2_n_0\,
      S => a(6)
    );
\qspo_int_reg[5]_i_3\: unisim.vcomponents.MUXF7
     port map (
      I0 => \qspo_int[5]_i_6_n_0\,
      I1 => \qspo_int[5]_i_7_n_0\,
      O => \qspo_int_reg[5]_i_3_n_0\,
      S => a(6)
    );
\qspo_int_reg[6]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => clk,
      CE => '1',
      D => \qspo_int_reg[6]_i_1_n_0\,
      Q => qspo(6),
      R => '0'
    );
\qspo_int_reg[6]_i_1\: unisim.vcomponents.MUXF8
     port map (
      I0 => \qspo_int_reg[6]_i_2_n_0\,
      I1 => \qspo_int_reg[6]_i_3_n_0\,
      O => \qspo_int_reg[6]_i_1_n_0\,
      S => a(7)
    );
\qspo_int_reg[6]_i_2\: unisim.vcomponents.MUXF7
     port map (
      I0 => \qspo_int[6]_i_4_n_0\,
      I1 => \qspo_int[6]_i_5_n_0\,
      O => \qspo_int_reg[6]_i_2_n_0\,
      S => a(6)
    );
\qspo_int_reg[6]_i_3\: unisim.vcomponents.MUXF7
     port map (
      I0 => \qspo_int[6]_i_6_n_0\,
      I1 => \qspo_int[6]_i_7_n_0\,
      O => \qspo_int_reg[6]_i_3_n_0\,
      S => a(6)
    );
\qspo_int_reg[7]\: unisim.vcomponents.FDRE
    generic map(
      INIT => '0'
    )
        port map (
      C => clk,
      CE => '1',
      D => \qspo_int[7]_i_1_n_0\,
      Q => qspo(7),
      R => '0'
    );
end STRUCTURE;
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity DisplayROM_dist_mem_gen_v8_0_12_synth is
  port (
    qspo : out STD_LOGIC_VECTOR ( 7 downto 0 );
    a : in STD_LOGIC_VECTOR ( 7 downto 0 );
    clk : in STD_LOGIC
  );
  attribute ORIG_REF_NAME : string;
  attribute ORIG_REF_NAME of DisplayROM_dist_mem_gen_v8_0_12_synth : entity is "dist_mem_gen_v8_0_12_synth";
end DisplayROM_dist_mem_gen_v8_0_12_synth;

architecture STRUCTURE of DisplayROM_dist_mem_gen_v8_0_12_synth is
begin
\gen_rom.rom_inst\: entity work.DisplayROM_rom
     port map (
      a(7 downto 0) => a(7 downto 0),
      clk => clk,
      qspo(7 downto 0) => qspo(7 downto 0)
    );
end STRUCTURE;
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity DisplayROM_dist_mem_gen_v8_0_12 is
  port (
    a : in STD_LOGIC_VECTOR ( 7 downto 0 );
    d : in STD_LOGIC_VECTOR ( 7 downto 0 );
    dpra : in STD_LOGIC_VECTOR ( 7 downto 0 );
    clk : in STD_LOGIC;
    we : in STD_LOGIC;
    i_ce : in STD_LOGIC;
    qspo_ce : in STD_LOGIC;
    qdpo_ce : in STD_LOGIC;
    qdpo_clk : in STD_LOGIC;
    qspo_rst : in STD_LOGIC;
    qdpo_rst : in STD_LOGIC;
    qspo_srst : in STD_LOGIC;
    qdpo_srst : in STD_LOGIC;
    spo : out STD_LOGIC_VECTOR ( 7 downto 0 );
    dpo : out STD_LOGIC_VECTOR ( 7 downto 0 );
    qspo : out STD_LOGIC_VECTOR ( 7 downto 0 );
    qdpo : out STD_LOGIC_VECTOR ( 7 downto 0 )
  );
  attribute C_ADDR_WIDTH : integer;
  attribute C_ADDR_WIDTH of DisplayROM_dist_mem_gen_v8_0_12 : entity is 8;
  attribute C_DEFAULT_DATA : string;
  attribute C_DEFAULT_DATA of DisplayROM_dist_mem_gen_v8_0_12 : entity is "0";
  attribute C_DEPTH : integer;
  attribute C_DEPTH of DisplayROM_dist_mem_gen_v8_0_12 : entity is 256;
  attribute C_ELABORATION_DIR : string;
  attribute C_ELABORATION_DIR of DisplayROM_dist_mem_gen_v8_0_12 : entity is "./";
  attribute C_FAMILY : string;
  attribute C_FAMILY of DisplayROM_dist_mem_gen_v8_0_12 : entity is "artix7";
  attribute C_HAS_CLK : integer;
  attribute C_HAS_CLK of DisplayROM_dist_mem_gen_v8_0_12 : entity is 1;
  attribute C_HAS_D : integer;
  attribute C_HAS_D of DisplayROM_dist_mem_gen_v8_0_12 : entity is 0;
  attribute C_HAS_DPO : integer;
  attribute C_HAS_DPO of DisplayROM_dist_mem_gen_v8_0_12 : entity is 0;
  attribute C_HAS_DPRA : integer;
  attribute C_HAS_DPRA of DisplayROM_dist_mem_gen_v8_0_12 : entity is 0;
  attribute C_HAS_I_CE : integer;
  attribute C_HAS_I_CE of DisplayROM_dist_mem_gen_v8_0_12 : entity is 0;
  attribute C_HAS_QDPO : integer;
  attribute C_HAS_QDPO of DisplayROM_dist_mem_gen_v8_0_12 : entity is 0;
  attribute C_HAS_QDPO_CE : integer;
  attribute C_HAS_QDPO_CE of DisplayROM_dist_mem_gen_v8_0_12 : entity is 0;
  attribute C_HAS_QDPO_CLK : integer;
  attribute C_HAS_QDPO_CLK of DisplayROM_dist_mem_gen_v8_0_12 : entity is 0;
  attribute C_HAS_QDPO_RST : integer;
  attribute C_HAS_QDPO_RST of DisplayROM_dist_mem_gen_v8_0_12 : entity is 0;
  attribute C_HAS_QDPO_SRST : integer;
  attribute C_HAS_QDPO_SRST of DisplayROM_dist_mem_gen_v8_0_12 : entity is 0;
  attribute C_HAS_QSPO : integer;
  attribute C_HAS_QSPO of DisplayROM_dist_mem_gen_v8_0_12 : entity is 1;
  attribute C_HAS_QSPO_CE : integer;
  attribute C_HAS_QSPO_CE of DisplayROM_dist_mem_gen_v8_0_12 : entity is 0;
  attribute C_HAS_QSPO_RST : integer;
  attribute C_HAS_QSPO_RST of DisplayROM_dist_mem_gen_v8_0_12 : entity is 0;
  attribute C_HAS_QSPO_SRST : integer;
  attribute C_HAS_QSPO_SRST of DisplayROM_dist_mem_gen_v8_0_12 : entity is 0;
  attribute C_HAS_SPO : integer;
  attribute C_HAS_SPO of DisplayROM_dist_mem_gen_v8_0_12 : entity is 0;
  attribute C_HAS_WE : integer;
  attribute C_HAS_WE of DisplayROM_dist_mem_gen_v8_0_12 : entity is 0;
  attribute C_MEM_INIT_FILE : string;
  attribute C_MEM_INIT_FILE of DisplayROM_dist_mem_gen_v8_0_12 : entity is "DisplayROM.mif";
  attribute C_MEM_TYPE : integer;
  attribute C_MEM_TYPE of DisplayROM_dist_mem_gen_v8_0_12 : entity is 0;
  attribute C_PARSER_TYPE : integer;
  attribute C_PARSER_TYPE of DisplayROM_dist_mem_gen_v8_0_12 : entity is 1;
  attribute C_PIPELINE_STAGES : integer;
  attribute C_PIPELINE_STAGES of DisplayROM_dist_mem_gen_v8_0_12 : entity is 0;
  attribute C_QCE_JOINED : integer;
  attribute C_QCE_JOINED of DisplayROM_dist_mem_gen_v8_0_12 : entity is 0;
  attribute C_QUALIFY_WE : integer;
  attribute C_QUALIFY_WE of DisplayROM_dist_mem_gen_v8_0_12 : entity is 0;
  attribute C_READ_MIF : integer;
  attribute C_READ_MIF of DisplayROM_dist_mem_gen_v8_0_12 : entity is 1;
  attribute C_REG_A_D_INPUTS : integer;
  attribute C_REG_A_D_INPUTS of DisplayROM_dist_mem_gen_v8_0_12 : entity is 0;
  attribute C_REG_DPRA_INPUT : integer;
  attribute C_REG_DPRA_INPUT of DisplayROM_dist_mem_gen_v8_0_12 : entity is 0;
  attribute C_SYNC_ENABLE : integer;
  attribute C_SYNC_ENABLE of DisplayROM_dist_mem_gen_v8_0_12 : entity is 1;
  attribute C_WIDTH : integer;
  attribute C_WIDTH of DisplayROM_dist_mem_gen_v8_0_12 : entity is 8;
  attribute ORIG_REF_NAME : string;
  attribute ORIG_REF_NAME of DisplayROM_dist_mem_gen_v8_0_12 : entity is "dist_mem_gen_v8_0_12";
end DisplayROM_dist_mem_gen_v8_0_12;

architecture STRUCTURE of DisplayROM_dist_mem_gen_v8_0_12 is
  signal \<const0>\ : STD_LOGIC;
begin
  dpo(7) <= \<const0>\;
  dpo(6) <= \<const0>\;
  dpo(5) <= \<const0>\;
  dpo(4) <= \<const0>\;
  dpo(3) <= \<const0>\;
  dpo(2) <= \<const0>\;
  dpo(1) <= \<const0>\;
  dpo(0) <= \<const0>\;
  qdpo(7) <= \<const0>\;
  qdpo(6) <= \<const0>\;
  qdpo(5) <= \<const0>\;
  qdpo(4) <= \<const0>\;
  qdpo(3) <= \<const0>\;
  qdpo(2) <= \<const0>\;
  qdpo(1) <= \<const0>\;
  qdpo(0) <= \<const0>\;
  spo(7) <= \<const0>\;
  spo(6) <= \<const0>\;
  spo(5) <= \<const0>\;
  spo(4) <= \<const0>\;
  spo(3) <= \<const0>\;
  spo(2) <= \<const0>\;
  spo(1) <= \<const0>\;
  spo(0) <= \<const0>\;
GND: unisim.vcomponents.GND
     port map (
      G => \<const0>\
    );
\synth_options.dist_mem_inst\: entity work.DisplayROM_dist_mem_gen_v8_0_12_synth
     port map (
      a(7 downto 0) => a(7 downto 0),
      clk => clk,
      qspo(7 downto 0) => qspo(7 downto 0)
    );
end STRUCTURE;
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity DisplayROM is
  port (
    a : in STD_LOGIC_VECTOR ( 7 downto 0 );
    clk : in STD_LOGIC;
    qspo : out STD_LOGIC_VECTOR ( 7 downto 0 )
  );
  attribute NotValidForBitStream : boolean;
  attribute NotValidForBitStream of DisplayROM : entity is true;
  attribute CHECK_LICENSE_TYPE : string;
  attribute CHECK_LICENSE_TYPE of DisplayROM : entity is "DisplayROM,dist_mem_gen_v8_0_12,{}";
  attribute downgradeipidentifiedwarnings : string;
  attribute downgradeipidentifiedwarnings of DisplayROM : entity is "yes";
  attribute x_core_info : string;
  attribute x_core_info of DisplayROM : entity is "dist_mem_gen_v8_0_12,Vivado 2017.4";
end DisplayROM;

architecture STRUCTURE of DisplayROM is
  signal NLW_U0_dpo_UNCONNECTED : STD_LOGIC_VECTOR ( 7 downto 0 );
  signal NLW_U0_qdpo_UNCONNECTED : STD_LOGIC_VECTOR ( 7 downto 0 );
  signal NLW_U0_spo_UNCONNECTED : STD_LOGIC_VECTOR ( 7 downto 0 );
  attribute C_FAMILY : string;
  attribute C_FAMILY of U0 : label is "artix7";
  attribute C_HAS_D : integer;
  attribute C_HAS_D of U0 : label is 0;
  attribute C_HAS_DPO : integer;
  attribute C_HAS_DPO of U0 : label is 0;
  attribute C_HAS_DPRA : integer;
  attribute C_HAS_DPRA of U0 : label is 0;
  attribute C_HAS_I_CE : integer;
  attribute C_HAS_I_CE of U0 : label is 0;
  attribute C_HAS_QDPO : integer;
  attribute C_HAS_QDPO of U0 : label is 0;
  attribute C_HAS_QDPO_CE : integer;
  attribute C_HAS_QDPO_CE of U0 : label is 0;
  attribute C_HAS_QDPO_CLK : integer;
  attribute C_HAS_QDPO_CLK of U0 : label is 0;
  attribute C_HAS_QDPO_RST : integer;
  attribute C_HAS_QDPO_RST of U0 : label is 0;
  attribute C_HAS_QDPO_SRST : integer;
  attribute C_HAS_QDPO_SRST of U0 : label is 0;
  attribute C_HAS_WE : integer;
  attribute C_HAS_WE of U0 : label is 0;
  attribute C_MEM_TYPE : integer;
  attribute C_MEM_TYPE of U0 : label is 0;
  attribute C_PIPELINE_STAGES : integer;
  attribute C_PIPELINE_STAGES of U0 : label is 0;
  attribute C_QCE_JOINED : integer;
  attribute C_QCE_JOINED of U0 : label is 0;
  attribute C_QUALIFY_WE : integer;
  attribute C_QUALIFY_WE of U0 : label is 0;
  attribute C_REG_DPRA_INPUT : integer;
  attribute C_REG_DPRA_INPUT of U0 : label is 0;
  attribute KEEP_HIERARCHY : string;
  attribute KEEP_HIERARCHY of U0 : label is "soft";
  attribute c_addr_width : integer;
  attribute c_addr_width of U0 : label is 8;
  attribute c_default_data : string;
  attribute c_default_data of U0 : label is "0";
  attribute c_depth : integer;
  attribute c_depth of U0 : label is 256;
  attribute c_elaboration_dir : string;
  attribute c_elaboration_dir of U0 : label is "./";
  attribute c_has_clk : integer;
  attribute c_has_clk of U0 : label is 1;
  attribute c_has_qspo : integer;
  attribute c_has_qspo of U0 : label is 1;
  attribute c_has_qspo_ce : integer;
  attribute c_has_qspo_ce of U0 : label is 0;
  attribute c_has_qspo_rst : integer;
  attribute c_has_qspo_rst of U0 : label is 0;
  attribute c_has_qspo_srst : integer;
  attribute c_has_qspo_srst of U0 : label is 0;
  attribute c_has_spo : integer;
  attribute c_has_spo of U0 : label is 0;
  attribute c_mem_init_file : string;
  attribute c_mem_init_file of U0 : label is "DisplayROM.mif";
  attribute c_parser_type : integer;
  attribute c_parser_type of U0 : label is 1;
  attribute c_read_mif : integer;
  attribute c_read_mif of U0 : label is 1;
  attribute c_reg_a_d_inputs : integer;
  attribute c_reg_a_d_inputs of U0 : label is 0;
  attribute c_sync_enable : integer;
  attribute c_sync_enable of U0 : label is 1;
  attribute c_width : integer;
  attribute c_width of U0 : label is 8;
begin
U0: entity work.DisplayROM_dist_mem_gen_v8_0_12
     port map (
      a(7 downto 0) => a(7 downto 0),
      clk => clk,
      d(7 downto 0) => B"00000000",
      dpo(7 downto 0) => NLW_U0_dpo_UNCONNECTED(7 downto 0),
      dpra(7 downto 0) => B"00000000",
      i_ce => '1',
      qdpo(7 downto 0) => NLW_U0_qdpo_UNCONNECTED(7 downto 0),
      qdpo_ce => '1',
      qdpo_clk => '0',
      qdpo_rst => '0',
      qdpo_srst => '0',
      qspo(7 downto 0) => qspo(7 downto 0),
      qspo_ce => '1',
      qspo_rst => '0',
      qspo_srst => '0',
      spo(7 downto 0) => NLW_U0_spo_UNCONNECTED(7 downto 0),
      we => '0'
    );
end STRUCTURE;
