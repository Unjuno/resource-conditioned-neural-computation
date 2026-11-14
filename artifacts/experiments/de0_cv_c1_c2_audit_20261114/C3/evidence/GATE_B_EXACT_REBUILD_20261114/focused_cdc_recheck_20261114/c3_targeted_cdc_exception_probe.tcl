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
foreach pair $scalar_pairs {
  lassign $pair src dst
  set srcs [get_registers "${prefix}${src}"]
  set dsts [get_registers "${prefix}${dst}"]
  set ns [get_collection_size $srcs]
  set nd [get_collection_size $dsts]
  puts "SCALAR $src -> $dst source_count=$ns destination_count=$nd"
  if {$ns != 1 || $nd != 1} { error "unexpected scalar endpoint cardinality" }
  set_false_path -from $srcs -to $dsts
}
set reqsrc [get_registers {*rtnn_c2_vjtag_mailbox:u_mailbox|req_hold_tck_q[*]}]
set reqdst [get_registers {*rtnn_c2_vjtag_mailbox:u_mailbox|request_data_o[*]}]
set rspsrc [get_registers {*rtnn_de0_cv_soc_c2:u_soc|response_words_q[*][*]}]
set rspdst [get_registers {*rtnn_c2_vjtag_mailbox:u_mailbox|rsp_hold_tck_q[*]}]
puts "BUNDLE request=[get_collection_size $reqsrc]/[get_collection_size $reqdst] response=[get_collection_size $rspsrc]/[get_collection_size $rspdst]"
set_max_delay -from $reqsrc -to $reqdst 40.000
set_max_delay -from $rspsrc -to $rspdst 60.000
update_timing_netlist
report_timing -setup -from [get_clocks {altera_reserved_tck}] -to [get_clocks {CLOCK_50}] -npaths 5000 -detail summary -file c3_targeted_tck_to_sys_allpaths.rpt
report_timing -setup -from [get_clocks {CLOCK_50}] -to [get_clocks {altera_reserved_tck}] -npaths 5000 -detail summary -file c3_targeted_sys_to_tck_allpaths.rpt
report_timing -setup -from $reqsrc -to $reqdst -npaths 800 -detail full_path -file c3_targeted_request_800.rpt
report_timing -setup -from $rspsrc -to $rspdst -npaths 384 -detail full_path -file c3_targeted_response_384.rpt
project_close
