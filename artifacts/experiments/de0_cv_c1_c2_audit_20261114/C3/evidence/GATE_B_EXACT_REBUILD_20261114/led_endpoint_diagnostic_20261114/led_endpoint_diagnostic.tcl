load_package sta
load_package report
project_open rtnn_c2
create_timing_netlist
read_sdc
update_timing_netlist
set out {D:/rtnn_c3_gateb_exact_rebuild_20261114/led_endpoint_diagnostic}
file mkdir $out
set leds [get_ports {LEDR[0] LEDR[1] LEDR[3]}]
set n [get_collection_size $leds]
set f [open "$out/led_path_counts.txt" w]
puts $f "selected_led_port_count=$n"
if {$n != 3} { error "Expected exactly 3 LED ports, got $n" }
foreach op [get_available_operating_conditions] {
  set_operating_conditions $op
  update_timing_netlist
  set before [get_timing_paths -setup -to $leds -npaths 1000]
  puts $f "op=$op before_false_path_setup_paths=[get_collection_size $before]"
  set_false_path -to $leds
  update_timing_netlist
  set after [get_timing_paths -setup -to $leds -npaths 1000]
  puts $f "op=$op after_false_path_setup_paths=[get_collection_size $after]"
  report_ucp -panel_name {Unconstrained Paths} -file "$out/ucp_[get_operating_conditions].rpt"
}
close $f
report_exceptions -setup -detail path_summary -npaths 1000 -file "$out/exceptions.rpt"
delete_timing_netlist
project_close
