############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project FinalProjectVhdl_ArminMashhadiEbrahim
set_top SaveToRamAndOutput
add_files SaveToRamAndOutput.c
add_files comparator.c
add_files generator_2x2.c
add_files window_processor.c
add_files -tb generator_2x2_tb.c
open_solution "solution1"
set_part {xc7z015clg485-1}
create_clock -period 10 -name default
config_sdx -optimization_level none -target none
config_export -vivado_optimization_level 2
source "./FinalProjectVhdl_ArminMashhadiEbrahim/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
