load_package sta
project_open rtnn_c2
create_timing_netlist
read_sdc
update_timing_netlist
set tdi [get_ports -nowarn {altera_reserved_tdi}]
set tms [get_ports -nowarn {altera_reserved_tms}]
set tdo [get_ports -nowarn {altera_reserved_tdo}]
set regs [get_registers -nowarn *]
set f [open jtag_interface_object_counts.txt w]
puts $f "TDI_PORTS=[get_collection_size $tdi] TMS_PORTS=[get_collection_size $tms] TDO_PORTS=[get_collection_size $tdo] REGISTERS=[get_collection_size $regs]"
close $f
set index 0
foreach op [get_available_operating_conditions] {
  puts "CORNER $index $op"
  set_operating_conditions $op
  update_timing_netlist
  if {[get_collection_size $tdi] > 0} { report_path -from $tdi -to $regs -npaths 10 -nworst 1 -file "jtag_tdi_to_register_${index}.rpt" }
  if {[get_collection_size $tms] > 0} { report_path -from $tms -to $regs -npaths 10 -nworst 1 -file "jtag_tms_to_register_${index}.rpt" }
  if {[get_collection_size $regs] > 0 && [get_collection_size $tdo] > 0} { report_path -from $regs -to $tdo -npaths 10 -nworst 1 -file "jtag_register_to_tdo_${index}.rpt" }
  incr index
}
set f [open jtag_interface_corner_count.txt w]
puts $f "corner_count=$index"
close $f
delete_timing_netlist
project_close
