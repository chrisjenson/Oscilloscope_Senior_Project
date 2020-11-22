-makelib xcelium_lib/xil_defaultlib -sv \
  "D:/Xilinx/Vivado/2019.1/data/ip/xpm/xpm_memory/hdl/xpm_memory.sv" \
-endlib
-makelib xcelium_lib/xpm \
  "D:/Xilinx/Vivado/2019.1/data/ip/xpm/xpm_VCOMP.vhd" \
-endlib
-makelib xcelium_lib/blk_mem_gen_v8_4_3 \
  "../../../../DAB_Interface.srcs/sources_1/bd/BlockRam/ipshared/c001/simulation/blk_mem_gen_v8_4.v" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../bd/BlockRam/ip/BlockRam_blk_mem_gen_0_0/sim/BlockRam_blk_mem_gen_0_0.v" \
  "../../../bd/BlockRam/sim/BlockRam.v" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  glbl.v
-endlib

