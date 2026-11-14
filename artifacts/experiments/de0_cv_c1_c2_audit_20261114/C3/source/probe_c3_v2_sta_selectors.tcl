load_package sta
project_open rtnn_c3_measurement_v2
create_timing_netlist
read_sdc
update_timing_netlist
set f [open c3_v2_sta_selector_probe.txt w]
foreach pattern {\
  {*req_hold_tck_q*} \
  {*u_mailbox|req_hold_tck_q[*]} \
  {*rtnn_c2_vjtag_mailbox:u_mailbox|req_hold_tck_q[*]} \
  {*request_data_o*} \
  {*u_mailbox|request_data_o[*]} \
  {*rtnn_c2_vjtag_mailbox:u_mailbox|request_data_o[*]} \
  {*response_words_q*} \
  {*u_soc|response_words_q[*][*]} \
  {*rtnn_de0_cv_soc_c2:u_soc|response_words_q[*][*]} \
  {*rsp_hold_tck_q*} \
  {*u_mailbox|rsp_hold_tck_q[*]} \
  {*rtnn_c2_vjtag_mailbox:u_mailbox|rsp_hold_tck_q[*]}} {
  set c [get_registers $pattern]
  puts $f "$pattern count=[get_collection_size $c]"
  set n 0
  foreach_in_collection r $c {
    if {$n >= 3} break
    if {![catch {get_register_info -name $r} name]} {puts $f "  name=$name"} else {puts $f "  name_error=$name"}
    incr n
  }
}
close $f
delete_timing_netlist
project_close
