load_package sta
load_package report
project_open rtnn_c2
create_timing_netlist
read_sdc
set reqsrc [get_registers {*rtnn_c2_vjtag_mailbox:u_mailbox|req_hold_tck_q[*]}]
set reqdst [get_registers {*rtnn_c2_vjtag_mailbox:u_mailbox|request_data_o[*]}]
set rspsrc [get_registers {*rtnn_de0_cv_soc_c2:u_soc|response_words_q[*][*]}]
set rspdst [get_registers {*rtnn_c2_vjtag_mailbox:u_mailbox|rsp_hold_tck_q[*]}]
puts "ENDPOINT_COVERAGE request_src=[get_collection_size $reqsrc] request_dst=[get_collection_size $reqdst] response_src=[get_collection_size $rspsrc] response_dst=[get_collection_size $rspdst]"
set_max_skew -from $reqsrc -to $reqdst 20.000
set_max_skew -from $rspsrc -to $rspdst 20.000
set i 0
foreach op [get_available_operating_conditions] {
  puts "CORNER $i $op"
  set_operating_conditions $op
  update_timing_netlist
  report_max_skew -npaths 8 -file "c3_bundled_maxskew_corner_${i}.rpt"
  incr i
}
set f [open c3_bundled_maxskew_corner_count.txt w]
puts $f "corner_count=$i"
close $f
project_close
