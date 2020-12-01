# 
# Synthesis run script generated by Vivado
# 

set TIME_start [clock seconds] 
proc create_report { reportName command } {
  set status "."
  append status $reportName ".fail"
  if { [file exists $status] } {
    eval file delete [glob $status]
  }
  send_msg_id runtcl-4 info "Executing : $command"
  set retval [eval catch { $command } msg]
  if { $retval != 0 } {
    set fp [open $status w]
    close $fp
    send_msg_id runtcl-5 warning "$msg"
  }
}
set_param chipscope.maxJobs 2
set_param synth.incrementalSynthesisCache D:/SeniorProject/Oscilloscope_Senior_Project/Verilog/FullSystem/.Xil/Vivado-7852-MSI/incrSyn
set_param xicom.use_bs_reader 1
set_msg_config -id {Common 17-41} -limit 10000000
set_msg_config -id {Synth 8-256} -limit 10000
set_msg_config -id {Synth 8-638} -limit 10000
create_project -in_memory -part xc7a100tcsg324-1

set_param project.singleFileAddWarning.threshold 0
set_param project.compositeFile.enableAutoGeneration 0
set_param synth.vivado.isSynthRun true
set_msg_config -source 4 -id {IP_Flow 19-2162} -severity warning -new_severity info
set_property webtalk.parent_dir D:/SeniorProject/Oscilloscope_Senior_Project/Verilog/FullSystem/FullSystem.cache/wt [current_project]
set_property parent.project_path D:/SeniorProject/Oscilloscope_Senior_Project/Verilog/FullSystem/FullSystem.xpr [current_project]
set_property XPM_LIBRARIES XPM_MEMORY [current_project]
set_property default_lib xil_defaultlib [current_project]
set_property target_language Verilog [current_project]
set_property ip_output_repo d:/SeniorProject/Oscilloscope_Senior_Project/Verilog/FullSystem/FullSystem.cache/ip [current_project]
set_property ip_cache_permissions {read write} [current_project]
read_verilog -library xil_defaultlib {
  D:/SeniorProject/Oscilloscope_Senior_Project/Verilog/FullSystem/FullSystem.srcs/sources_1/new/ADCInterface.v
  D:/SeniorProject/Oscilloscope_Senior_Project/Verilog/FullSystem/FullSystem.srcs/sources_1/new/Buffer_FIFO.v
  D:/SeniorProject/Oscilloscope_Senior_Project/Verilog/FullSystem/FullSystem.srcs/sources_1/new/FIFO_RAM.v
  D:/SeniorProject/Oscilloscope_Senior_Project/Verilog/FullSystem/FullSystem.srcs/sources_1/new/RAM_ReadEngine.v
  D:/SeniorProject/Oscilloscope_Senior_Project/Verilog/FullSystem/FullSystem.srcs/sources_1/new/RAM_WriteEngine.v
  D:/SeniorProject/Oscilloscope_Senior_Project/Verilog/FullSystem/FullSystem.srcs/sources_1/new/Regs.v
  D:/SeniorProject/Oscilloscope_Senior_Project/Verilog/FullSystem/FullSystem.srcs/sources_1/new/SPI.v
  D:/SeniorProject/Oscilloscope_Senior_Project/Verilog/FullSystem/FullSystem.srcs/sources_1/new/TimingGen.v
  D:/SeniorProject/Oscilloscope_Senior_Project/Verilog/FullSystem/FullSystem.srcs/sources_1/new/Top.v
}
read_ip -quiet D:/SeniorProject/Oscilloscope_Senior_Project/Verilog/FullSystem/FullSystem.srcs/sources_1/ip/blk_mem_gen_0/blk_mem_gen_0.xci
set_property used_in_implementation false [get_files -all d:/SeniorProject/Oscilloscope_Senior_Project/Verilog/FullSystem/FullSystem.srcs/sources_1/ip/blk_mem_gen_0/blk_mem_gen_0_ooc.xdc]

# Mark all dcp files as not used in implementation to prevent them from being
# stitched into the results of this synthesis run. Any black boxes in the
# design are intentionally left as such for best results. Dcp files will be
# stitched into the design at a later time, either when this synthesis run is
# opened, or when it is stitched into a dependent implementation run.
foreach dcp [get_files -quiet -all -filter file_type=="Design\ Checkpoint"] {
  set_property used_in_implementation false $dcp
}
read_xdc D:/SeniorProject/Oscilloscope_Senior_Project/Verilog/FullSystem/lp_constraints.xdc
set_property used_in_implementation false [get_files D:/SeniorProject/Oscilloscope_Senior_Project/Verilog/FullSystem/lp_constraints.xdc]

set_param ips.enableIPCacheLiteLoad 1
close [open __synthesis_is_running__ w]

synth_design -top Top -part xc7a100tcsg324-1


# disable binary constraint mode for synth run checkpoints
set_param constraints.enableBinaryConstraints false
write_checkpoint -force -noxdef Top.dcp
create_report "synth_1_synth_report_utilization_0" "report_utilization -file Top_utilization_synth.rpt -pb Top_utilization_synth.pb"
file delete __synthesis_is_running__
close [open __synthesis_is_complete__ w]
