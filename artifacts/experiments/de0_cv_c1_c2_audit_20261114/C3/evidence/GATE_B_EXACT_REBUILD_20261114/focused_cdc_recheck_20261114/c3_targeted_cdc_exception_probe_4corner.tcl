load_package sta
load_package report
project_open rtnn_c2
create_timing_netlist
read_sdc
remove_clock_groups -all
set prefix {*rtnn_c2_vjtag_mailbox:u_mailbox|}
set scalar_pairs {
 {req_toggle_tck_q req_sync1_sys_q}
 {rsp_consume_toggle_tck_q rsp_consume_sync1_sys_q}
 {req_ack_toggle_sys_q req_ack_sync1_tck_q}
 {rsp_toggle_sys_q rsp_sync1_tck_q}
 {busy_sys_q busy_sync1_tck_q}
 {error_sys_q error_sync1_tck_q}
 {done_sys_q done_sync1_tck_q}
}
set scalar_source_count 0
foreach pair $scalar_pairs {
  lassign $pair src dst
  set srcs [get_registers "${prefix}${src}"]
  set dsts [get_registers "${prefix}${dst}"]
  set ns [get_collection_size $srcs]
  set nd [get_collection_size $dsts]
  puts "SCALAR $src -> $dst source_count=$ns destination_count=$nd"
  if {$ns < 1 || $nd != 1} { error "missing scalar endpoint" }
  incr scalar_source_count $ns
  set_false_path -from $srcs -to $dsts
}
set reqsrc [get_registers {*rtnn_c2_vjtag_mailbox:u_mailbox|req_hold_tck_q[*]}]
set reqdst [get_registers {*rtnn_c2_vjtag_mailbox:u_mailbox|request_data_o[*]}]
set rspsrc [get_registers {*rtnn_de0_cv_soc_c2:u_soc|response_words_q[*][*]}]
set rspdst [get_registers {*rtnn_c2_vjtag_mailbox:u_mailbox|rsp_hold_tck_q[*]}]
set reqsrc_n [get_collection_size $reqsrc]
set reqdst_n [get_collection_size $reqdst]
set rspsrc_n [get_collection_size $rspsrc]
set rspdst_n [get_collection_size $rspdst]
puts "SUMMARY scalar_source_nodes=$scalar_source_count scalar_destinations=7 request_src=$reqsrc_n request_dst=$reqdst_n response_src=$rspsrc_n response_dst=$rspdst_n"
if {$reqsrc_n != 800 || $reqdst_n != 800 || $rspsrc_n != 394 || $rspdst_n != 384} { error "unexpected bus endpoint cardinality" }
set_max_delay -from $reqsrc -to $reqdst 40.000
set_max_delay -from $rspsrc -to $rspdst 60.000
set i 0
foreach op [get_available_operating_conditions] {
  puts "CORNER $i $op"
  set_operating_conditions $op
  update_timing_netlist
  report_timing -setup -from $reqsrc -to $reqdst -npaths 800 -detail summary -file "c3_targeted_req_corner_${i}.rpt"
  report_timing -setup -from $rspsrc -to $rspdst -npaths 384 -detail summary -file "c3_targeted_rsp_corner_${i}.rpt"
  incr i
}
set f [open c3_targeted_corner_count.txt w]
puts $f "corner_count=$i"
close $f
project_close
