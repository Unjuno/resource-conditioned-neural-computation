load_package sta
project_open rtnn_c2
create_timing_netlist
read_sdc
set_input_delay -clock [get_clocks {altera_reserved_tck}] -clock_fall -max 0.0 [get_ports {altera_reserved_tdi}]
set_input_delay -clock [get_clocks {altera_reserved_tck}] -clock_fall -min 0.0 [get_ports {altera_reserved_tdi}]
set_input_delay -clock [get_clocks {altera_reserved_tck}] -clock_fall -max 0.0 [get_ports {altera_reserved_tms}]
set_input_delay -clock [get_clocks {altera_reserved_tck}] -clock_fall -min 0.0 [get_ports {altera_reserved_tms}]
update_timing_netlist
set index 0
foreach op [get_available_operating_conditions] {
  puts "CORNER $index $op"
  set_operating_conditions $op
  update_timing_netlist
  report_timing -setup -from [get_ports {altera_reserved_tdi}] -to [get_registers -nowarn {*req_shift_tck_q*}] -npaths 1000 -file "jtag_tdi_setup_paths_${index}.rpt"
  report_timing -hold -from [get_ports {altera_reserved_tdi}] -to [get_registers -nowarn {*req_shift_tck_q*}] -npaths 1000 -file "jtag_tdi_hold_paths_${index}.rpt"
  report_timing -setup -from [get_ports {altera_reserved_tms}] -npaths 1000 -file "jtag_tms_setup_paths_${index}.rpt"
  report_timing -hold -from [get_ports {altera_reserved_tms}] -npaths 1000 -file "jtag_tms_hold_paths_${index}.rpt"
  incr index
}
delete_timing_netlist
project_close
