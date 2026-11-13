package require ::quartus::jtag
puts "COMMANDS=[lsort [info commands device_*]]"
puts "HARDWARE=[get_hardware_names]"
foreach h [get_hardware_names] { puts "DEVICES:$h=[get_device_names -hardware_name $h]" }
