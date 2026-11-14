load_package sta
load_package report
project_open rtnn_c2
create_timing_netlist
read_sdc
remove_clock_groups -all
set reqsrc [get_registers {*rtnn_c2_vjtag_mailbox:u_mailbox|req_hold_tck_q[*]}]
set reqdst [get_registers {*rtnn_c2_vjtag_mailbox:u_mailbox|request_data_o[*]}]
set rspsrc [get_registers {*rtnn_de0_cv_soc_c2:u_soc|response_words_q[*][*]}]
set rspdst [get_registers {*rtnn_c2_vjtag_mailbox:u_mailbox|rsp_hold_tck_q[*]}]
set_max_delay -from $reqsrc -to $reqdst 40.000
set_max_delay -from $rspsrc -to $rspdst 60.000
puts "ENDPOINT_COVERAGE request_src=[get_collection_size $reqsrc] request_dst=[get_collection_size $reqdst] response_src=[get_collection_size $rspsrc] response_dst=[get_collection_size $rspdst]"
set i 0
foreach op [get_available_operating_conditions] {
  puts "CORNER $i $op"
  set_operating_conditions $op
  update_timing_netlist
  report_timing -setup -from $reqsrc -to $reqdst -npaths 800 -detail summary -file "c3_bundled_req_maxdelay_corner_${i}.rpt"
  report_timing -setup -from $rspsrc -to $rspdst -npaths 384 -detail summary -file "c3_bundled_rsp_maxdelay_corner_${i}.rpt"
  incr i
}
set f [open c3_bundled_maxdelay_corner_count.txt w]
puts $f "corner_count=$i"
close $f
project_close
