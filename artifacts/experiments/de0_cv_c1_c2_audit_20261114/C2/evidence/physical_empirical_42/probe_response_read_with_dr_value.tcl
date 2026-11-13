package require ::quartus::jtag
set hw [lindex [get_hardware_names] 0]
set dev [lindex [get_device_names -hardware_name $hw] 0]
open_device -hardware_name $hw -device_name $dev
device_lock -timeout 10000
device_virtual_ir_shift -instance_index 0 -ir_value 2 -no_captured_ir_value
set response [device_virtual_dr_shift -instance_index 0 -length 384 -dr_value 000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 -value_in_hex]
puts "RESPONSE=$response"
after 20
device_virtual_ir_shift -instance_index 0 -ir_value 3 -no_captured_ir_value
set status [device_virtual_dr_shift -instance_index 0 -length 8 -value_in_hex]
puts "STATUS_AFTER_WRITE_READ=$status"
device_unlock
close_device
exit 0
