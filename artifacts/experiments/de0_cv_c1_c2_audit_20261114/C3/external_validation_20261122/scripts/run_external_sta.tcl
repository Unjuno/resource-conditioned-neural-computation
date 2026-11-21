load_package sta
load_package report
project_open rtnn_c3_measurement_v2
create_timing_netlist
read_sdc
update_timing_netlist
report_clocks -file external_clocks.rpt
report_ucp -panel_name {Unconstrained Paths} -file external_unconstrained_paths.rpt
set reqsrc [get_registers {*req_hold_tck_q*}]
set reqdst [get_registers {*req_bus_sync1_sys_q*}]
set rspsrc [get_registers {*response_words_q*}]
set rspdst [get_registers {*rsp_bus_sync1_tck_q*}]
set f [open external_path_coverage.txt w]
puts $f "request_source=[get_collection_size $reqsrc] request_sync1_destination=[get_collection_size $reqdst] response_source=[get_collection_size $rspsrc] response_sync1_destination=[get_collection_size $rspdst]"
close $f
set index 0
foreach op [get_available_operating_conditions] {
  puts "CORNER $index $op"
  set_operating_conditions $op
  update_timing_netlist
  report_timing -setup -npaths 20 -detail full_path -file "external_setup_${index}.rpt"
  report_timing -hold -npaths 20 -detail full_path -file "external_hold_${index}.rpt"
  report_net_delay -nworst 2 -file "external_netdelay_${index}.rpt"
  report_max_skew -npaths 8 -file "external_maxskew_${index}.rpt"
  report_path -from $reqsrc -to $reqdst -npaths 800 -nworst 1 -summary -file "external_path_req_${index}.rpt"
  report_path -from $rspsrc -to $rspdst -npaths 480 -nworst 1 -summary -file "external_path_rsp_${index}.rpt"
  incr index
}
set f [open external_corner_count.txt w]
puts $f "corner_count=$index"
close $f
delete_timing_netlist
project_close
