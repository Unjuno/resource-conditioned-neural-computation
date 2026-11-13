load_package sta
project_open rtnn_c2
create_timing_netlist
read_sdc
update_timing_netlist
set reqsrc [get_registers {*rtnn_c2_vjtag_mailbox:u_mailbox|req_hold_tck_q[*]}]
set reqdst [get_registers {*rtnn_c2_vjtag_mailbox:u_mailbox|request_data_o[*]}]
set rspsrc [get_registers {*rtnn_de0_cv_soc_c2:u_soc|response_words_q[*][*]}]
set rspdst [get_registers {*rtnn_c2_vjtag_mailbox:u_mailbox|rsp_hold_tck_q[*]}]
report_net_delay -nworst 1 -file bundled_capture_netdelay.rpt
report_path -from $reqsrc -to $reqdst -npaths 800 -nworst 1 -summary -file bundled_capture_req_maxpaths.rpt
report_path -from $rspsrc -to $rspdst -npaths 384 -nworst 1 -summary -file bundled_capture_rsp_maxpaths.rpt
set f [open "bundled_capture_collection_counts.txt" w]
puts $f "req=[get_collection_size $reqsrc]->[get_collection_size $reqdst]"
puts $f "rsp=[get_collection_size $rspsrc]->[get_collection_size $rspdst]"
close $f
project_close