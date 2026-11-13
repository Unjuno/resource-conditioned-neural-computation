load_package jtag
set hw [lindex [get_hardware_names] 0]
set dev [lindex [get_device_names -hardware_name $hw] 0]
open_device -hardware_name $hw -device_name $dev
device_lock -timeout 10000
puts "BUILD=[device_virtual_ir_shift -instance_index 0 -ir_value 4 -no_captured_ir_value];[device_virtual_dr_shift -instance_index 0 -length 32 -value_in_hex]"
puts "STATUS_IR=[device_virtual_ir_shift -instance_index 0 -ir_value 3 -no_captured_ir_value]"
puts "STATUS_DR=[device_virtual_dr_shift -instance_index 0 -length 8 -value_in_hex]"
device_unlock
close_device
exit 0
