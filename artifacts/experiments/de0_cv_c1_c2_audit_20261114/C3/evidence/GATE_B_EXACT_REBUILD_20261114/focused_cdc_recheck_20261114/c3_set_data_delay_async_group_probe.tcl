load_package sta
load_package report
project_open rtnn_c2
create_timing_netlist
read_sdc
set reqsrc [get_registers {*rtnn_c2_vjtag_mailbox:u_mailbox|req_hold_tck_q[*]}]
set reqdst [get_registers {*rtnn_c2_vjtag_mailbox:u_mailbox|request_data_o[*]}]
set rspsrc [get_registers {*rtnn_de0_cv_soc_c2:u_soc|response_words_q[*][*]}]
set rspdst [get_registers {*rtnn_c2_vjtag_mailbox:u_mailbox|rsp_hold_tck_q[*]}]
puts "COVERAGE [get_collection_size $reqsrc] [get_collection_size $reqdst] [get_collection_size $rspsrc] [get_collection_size $rspdst]"
puts "REPORT_DATA_DELAY_COMMANDS=[info commands report_data_delay]"
set rc_req [catch {set_data_delay -from $reqsrc -to $reqdst 40.000} out_req]
puts "REQUEST_SET_DATA_DELAY rc=$rc_req result=$out_req"
set rc_rsp [catch {set_data_delay -from $rspsrc -to $rspdst 60.000} out_rsp]
puts "RESPONSE_SET_DATA_DELAY rc=$rc_rsp result=$out_rsp"
if {$rc_req == 0 && $rc_rsp == 0} {
  catch {report_data_delay -from $reqsrc -to $reqdst -npaths 800 -file c3_set_data_delay_req.rpt} rpt_req
  puts "REQUEST_REPORT=$rpt_req"
  catch {report_data_delay -from $rspsrc -to $rspdst -npaths 384 -file c3_set_data_delay_rsp.rpt} rpt_rsp
  puts "RESPONSE_REPORT=$rpt_rsp"
}
project_close
