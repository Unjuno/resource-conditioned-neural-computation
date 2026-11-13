load_package sta
load_package report
project_open rtnn_c2
create_timing_netlist
read_sdc
update_timing_netlist
report_clocks -file c2_allcorners_clocks.rpt
report_ucp -panel_name {Unconstrained Paths} -file c2_allcorners_ucp.rpt
set reqsrc [get_registers {*req_hold_tck_q*}]
set reqdst [get_registers {*request_data_o*}]
set rspsrc [get_registers {*response_words_q*}]
set rspdst [get_registers {*rsp_hold_tck_q*}]
set f [open c2_allcorners_coverage.txt w]
puts $f "request_source=[get_collection_size $reqsrc] request_destination=[get_collection_size $reqdst] response_source=[get_collection_size $rspsrc] response_destination=[get_collection_size $rspdst]"
close $f
set index 0
foreach op [get_available_operating_conditions] {
  puts "CORNER $index $op"
  set_operating_conditions $op
  update_timing_netlist
  report_net_delay -nworst 2 -file "c2_allcorners_netdelay_${index}.rpt"
  report_max_skew -npaths 8 -file "c2_allcorners_maxskew_${index}.rpt"
  report_path -from $reqsrc -to $reqdst -npaths 800 -nworst 1 -summary -file "c2_allcorners_path_req_${index}.rpt"
  report_path -from $rspsrc -to $rspdst -npaths 384 -nworst 1 -summary -file "c2_allcorners_path_rsp_${index}.rpt"
  incr index
}
set f [open c2_allcorners_count.txt w]
puts $f "corner_count=$index"
close $f
delete_timing_netlist
project_close
