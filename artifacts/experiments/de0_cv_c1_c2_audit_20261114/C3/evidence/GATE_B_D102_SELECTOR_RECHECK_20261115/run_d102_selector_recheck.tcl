load_package sta
load_package report
project_open rtnn_c3_measurement_v2
create_timing_netlist
read_sdc
update_timing_netlist

set response_sources [get_registers {*response_words_q*}]
set response_destinations [get_registers {*rsp_bus_sync1_tck_q*}]
set source_count [get_collection_size $response_sources]
set destination_count [get_collection_size $response_destinations]
set source_file [open d102_response_source_collection_names.txt w]
puts $source_file "response_source_count=$source_count"
foreach_in_collection node $response_sources {
  puts $source_file [get_register_info -name $node]
}
close $source_file
set destination_file [open d102_response_destination_collection_names.txt w]
puts $destination_file "response_destination_count=$destination_count"
foreach_in_collection node $response_destinations {
  puts $destination_file [get_register_info -name $node]
}
close $destination_file

set index 0
foreach op [get_available_operating_conditions] {
  puts "CORNER $index $op"
  set_operating_conditions $op
  update_timing_netlist
  report_path -from $response_sources -to $response_destinations -npaths 600 -nworst 1 -summary \
    -file "d102_response_paths_${index}.rpt"
  incr index
}
set count_file [open d102_selector_recheck_corner_count.txt w]
puts $count_file "corner_count=$index"
close $count_file
if {$index != 4} { error "Expected four operating corners, got $index" }
delete_timing_netlist
project_close
puts "PASS_D102_RESPONSE_SELECTOR_RECHECK source_count=$source_count destination_count=$destination_count corners=$index"
