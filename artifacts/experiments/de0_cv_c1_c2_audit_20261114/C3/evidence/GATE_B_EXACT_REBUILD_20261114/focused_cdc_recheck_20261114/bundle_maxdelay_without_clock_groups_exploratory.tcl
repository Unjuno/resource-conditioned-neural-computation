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
puts "COVERAGE reqsrc=[get_collection_size $reqsrc] reqdst=[get_collection_size $reqdst] rspsrc=[get_collection_size $rspsrc] rspdst=[get_collection_size $rspdst]"
set_max_delay -from $reqsrc -to $reqdst 40.000
set_max_delay -from $rspsrc -to $rspdst 60.000
update_timing_netlist
report_timing -setup -from $reqsrc -to $reqdst -npaths 10 -detail full_path -file c3_bundled_req_maxdelay_removed_groups.rpt
report_timing -setup -from $rspsrc -to $rspdst -npaths 10 -detail full_path -file c3_bundled_rsp_maxdelay_removed_groups.rpt
report_ucp -file c3_bundled_maxdelay_removed_groups_ucp.rpt
project_close
