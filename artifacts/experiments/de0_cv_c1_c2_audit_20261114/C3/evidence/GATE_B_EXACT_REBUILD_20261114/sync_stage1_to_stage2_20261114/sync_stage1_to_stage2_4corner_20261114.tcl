load_package sta
load_package report
project_open rtnn_c2
create_timing_netlist
read_sdc
update_timing_netlist

set out {D:/rtnn_c3_gateb_exact_rebuild_20261114/sync_stage1_to_stage2_20261114}
file mkdir $out

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

set corner_index 0
set count_file [open "$out/endpoint_and_path_counts.txt" w]
foreach pair $pairs {
  lassign $pair src dst
  set srcs [get_registers "${prefix}${src}"]
  set dsts [get_registers "${prefix}${dst}"]
  set src_count [get_collection_size $srcs]
  set dst_count [get_collection_size $dsts]
  puts "PAIR $src -> $dst source_count=$src_count destination_count=$dst_count"
  puts $count_file "$src -> $dst source_count=$src_count destination_count=$dst_count"
  if {$src_count != 1 || $dst_count != 1} { error "Unexpected synchronizer endpoint cardinality: $src -> $dst" }
}

foreach op [get_available_operating_conditions] {
  puts "CORNER $corner_index $op"
  set_operating_conditions $op
  update_timing_netlist
  foreach pair $pairs {
    lassign $pair src dst
    set srcs [get_registers "${prefix}${src}"]
    set dsts [get_registers "${prefix}${dst}"]
    set paths [get_timing_paths -setup -from $srcs -to $dsts -npaths 1]
    set path_count [get_collection_size $paths]
    puts $count_file "corner=$corner_index pair=$src->$dst setup_path_count=$path_count"
    if {$path_count != 1} { error "Expected exactly one timed setup path for $src -> $dst at corner $corner_index" }
    set report_file "$out/corner_${corner_index}_${src}_to_${dst}.rpt"
    report_timing -setup -from $srcs -to $dsts -npaths 1 -detail summary -file $report_file
  }
  incr corner_index
}
close $count_file
if {$corner_index != 4} { error "Expected four operating conditions, found $corner_index" }

report_exceptions -setup -detail path_summary -npaths 1000 -file "$out/exceptions_original_sdc.rpt"
report_ucp -panel_name {Unconstrained Paths} -file "$out/unconstrained_original_sdc.rpt"
delete_timing_netlist
project_close
