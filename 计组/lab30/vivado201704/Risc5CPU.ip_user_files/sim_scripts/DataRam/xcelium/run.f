-makelib xcelium_lib/xpm -sv \
  "D:/Vivado2020/Vivado/2020.1/data/ip/xpm/xpm_cdc/hdl/xpm_cdc.sv" \
-endlib
-makelib xcelium_lib/xpm \
  "D:/Vivado2020/Vivado/2020.1/data/ip/xpm/xpm_VCOMP.vhd" \
-endlib
-makelib xcelium_lib/dist_mem_gen_v8_0_13 \
  "../../../ipstatic/simulation/dist_mem_gen_v8_0.v" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../../Risc5CPU.srcs/sources_1/ip/DataRam/sim/DataRam.v" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  glbl.v
-endlib

