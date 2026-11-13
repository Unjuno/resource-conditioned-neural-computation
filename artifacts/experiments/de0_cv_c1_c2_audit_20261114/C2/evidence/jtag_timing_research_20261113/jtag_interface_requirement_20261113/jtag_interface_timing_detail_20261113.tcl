load_package sta
project_open rtnn_c2
create_timing_netlist
read_sdc
update_timing_netlist
set tdi [get_ports -nowarn {altera_reserved_tdi}]
set tms [get_ports -nowarn {altera_reserved_tms}]
set tdo [get_ports -nowarn {altera_reserved_tdo}]
set reqregs [get_registers -nowarn {*req_shift_tck_q*}]
set f [open jtag_timing_detail_objects.txt w]
puts $f "TDI=[get_collection_size $tdi] TMS=[get_collection_size $tms] TDO=[get_collection_size $tdo] REQ_REGS=[get_collection_size $reqregs]"
close $f
set index 0
foreach op [get_available_operating_conditions] {
  puts "CORNER $index $op"
  set_operating_conditions $op
  update_timing_netlist
  report_timing -setup -from $tdi -to $reqregs -npaths 4 -detail full_path -file "jtag_tdi_setup_${index}.rpt"
  report_timing -hold -from $tdi -to $reqregs -npaths 4 -detail full_path -file "jtag_tdi_hold_${index}.rpt"
  report_timing -setup -from $tms -npaths 4 -detail full_path -file "jtag_tms_setup_${index}.rpt"
  report_timing -hold -from $tms -npaths 4 -detail full_path -file "jtag_tms_hold_${index}.rpt"
  report_timing -setup -from [get_registers -nowarn *] -to $tdo -npaths 4 -detail full_path -file "jtag_tdo_setup_${index}.rpt"
  incr index
}
set f [open jtag_timing_detail_corner_count.txt w]
puts $f "corner_count=$index"
close $f
delete_timing_netlist
project_close
