load_package sta
project_open rtnn_c2
create_timing_netlist
read_sdc
set_input_delay -clock [get_clocks {altera_reserved_tck}] -clock_fall -max 0.0 [get_ports {altera_reserved_tdi}]
set_input_delay -clock [get_clocks {altera_reserved_tck}] -clock_fall -min 0.0 [get_ports {altera_reserved_tdi}]
set_input_delay -clock [get_clocks {altera_reserved_tck}] -clock_fall -max 0.0 [get_ports {altera_reserved_tms}]
set_input_delay -clock [get_clocks {altera_reserved_tck}] -clock_fall -min 0.0 [get_ports {altera_reserved_tms}]
update_timing_netlist
set tdi [get_ports {altera_reserved_tdi}]
set tms [get_ports {altera_reserved_tms}]
set reqregs [get_registers -nowarn {*req_shift_tck_q*}]
set index 0
foreach op [get_available_operating_conditions] {
  puts "CORNER $index $op"
  set_operating_conditions $op
  update_timing_netlist
  report_timing -setup -from $tdi -to $reqregs -npaths 5 -detail full_path -file "jtag_tdi_setup_zeroext_${index}.rpt"
  report_timing -hold -from $tdi -to $reqregs -npaths 5 -detail full_path -file "jtag_tdi_hold_zeroext_${index}.rpt"
  report_timing -setup -from $tms -npaths 5 -detail full_path -file "jtag_tms_setup_zeroext_${index}.rpt"
  report_timing -hold -from $tms -npaths 5 -detail full_path -file "jtag_tms_hold_zeroext_${index}.rpt"
  incr index
}
set f [open jtag_zero_external_input_corner_count.txt w]
puts $f "corner_count=$index"
close $f
delete_timing_netlist
project_close
