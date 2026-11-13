load_package jtag
set hw [lindex [get_hardware_names] 0]
set dev [lindex [get_device_names -hardware_name $hw] 0]
puts "HW=$hw DEV=$dev"
open_device -hardware_name $hw -device_name $dev
puts "OPENED"
device_lock -timeout 10000
puts "LOCKED"
device_unlock
close_device
puts "CLOSED"
exit 0
