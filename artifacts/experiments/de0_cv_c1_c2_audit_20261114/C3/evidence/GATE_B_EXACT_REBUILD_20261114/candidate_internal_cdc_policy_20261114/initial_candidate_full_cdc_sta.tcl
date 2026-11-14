load_package sta
load_package report
project_open rtnn_c2
create_timing_netlist
read_sdc
update_timing_netlist
set out {D:/rtnn_c3_gateb_exact_rebuild_20261114_internal_cdc_sdc_candidate/candidate_full_cdc_sta}
set pairs {
 {req_sync1_sys_q req_sync2_sys_q}
 {rsp_consume_sync1_sys_q rsp_consume_sync2_sys_q}
 {req_ack_sync1_tck_q req_ack_sync2_tck_q}
 {rsp_sync1_tck_q rsp_sync2_tck_q}
 {busy_sync1_tck_q busy_sync2_tck_q}
 {error_sync1_tck_q error_sync2_tck_q}
 {done_sync1_tck_q done_sync2_tck_q}
}
set prefix {*rtnn_c2_vjtag_mailbox:u_mailbox|}
set f [open "$out/counts.txt" w]
set ci 0
foreach op [get_available_operating_conditions] {
 set_operating_conditions $op
 update_timing_netlist
 foreach pair $pairs {
  lassign $pair src dst
  set ss [get_registers "${prefix}${src}"]
  set ds [get_registers "${prefix}${dst}"]
  if {[get_collection_size $ss] != 1 || [get_collection_size $ds] != 1} {error "Bad synchronizer endpoints $src->$dst"}
  set sp [get_timing_paths -setup -from $ss -to $ds -npaths 1]
  set hp [get_timing_paths -hold -from $ss -to $ds -npaths 1]
  set ns [get_collection_size $sp]; set nh [get_collection_size $hp]
  puts $f "corner=$ci op=$op pair=$src->$dst setup=$ns hold=$nh"
  if {$ns != 1 || $nh != 1} {error "Missing setup/hold path $src->$dst at $op"}
  report_timing -setup -from $ss -to $ds -npaths 1 -detail summary -file "$out/c${ci}_${src}_to_${dst}_setup.rpt"
  report_timing -hold -from $ss -to $ds -npaths 1 -detail summary -file "$out/c${ci}_${src}_to_${dst}_hold.rpt"
 }
 set a [get_timing_paths -setup -from [get_clocks {altera_reserved_tck}] -to [get_clocks {CLOCK_50}] -npaths 5000]
 set b [get_timing_paths -setup -from [get_clocks {CLOCK_50}] -to [get_clocks {altera_reserved_tck}] -npaths 5000]
 puts $f "corner=$ci op=$op all_tck_to_sys_setup=[get_collection_size $a] all_sys_to_tck_setup=[get_collection_size $b]"
 if {[get_collection_size $a] != 800 || [get_collection_size $b] != 384} {error "Crossing inventory changed at $op"}
 incr ci
}
close $f
if {$ci != 4} {error "Expected four corners"}
project_close
