load_package jtag
set hw [lindex [get_hardware_names] 0]
set dev [lindex [get_device_names -hardware_name $hw] 0]
open_device -hardware_name $hw -device_name $dev
device_lock -timeout 10000
set rc [catch {
  device_virtual_ir_shift -instance_index 0 -ir_value 4 -no_captured_ir_value
  set value [device_virtual_dr_shift -instance_index 0 -length 32 -value_in_hex]
  puts "BUILD_ID_RAW=$value"
} msg opts]
if {$rc} {puts stderr "ERROR=$msg"; if {[dict exists $opts -errorinfo]} {puts stderr [dict get $opts -errorinfo]}}
device_unlock
close_device
if {$rc} {exit 1}
exit 0
