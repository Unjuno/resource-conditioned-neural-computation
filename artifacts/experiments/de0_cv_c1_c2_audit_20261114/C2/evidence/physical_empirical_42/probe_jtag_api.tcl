load_package jtag
puts "JTAG_PACKAGE_LOADED"
set hw [get_hardware_names]
puts "HARDWARE_NAMES=$hw"
foreach h $hw { puts "DEVICE_NAMES_$h=[get_device_names -hardware_name $h]" }
exit 0
