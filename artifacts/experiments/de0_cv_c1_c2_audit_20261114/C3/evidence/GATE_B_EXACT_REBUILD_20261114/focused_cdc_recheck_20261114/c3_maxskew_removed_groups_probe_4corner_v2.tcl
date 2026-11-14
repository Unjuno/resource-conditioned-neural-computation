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
puts "ENDPOINT request=[get_collection_size $reqsrc]/[get_collection_size $reqdst] response=[get_collection_size $rspsrc]/[get_collection_size $rspdst]"
set_max_skew -from $reqsrc -to $reqdst 40.000
set_max_skew -from $rspsrc -to $rspdst 60.000
set i 0
foreach op [get_available_operating_conditions] {
 puts "CORNER $i $op"
 set_operating_conditions $op
 update_timing_netlist
 report_max_skew -npaths 8 -file "c3_skew_removed_groups_corner_${i}.rpt"
 
 incr i
}
project_close



