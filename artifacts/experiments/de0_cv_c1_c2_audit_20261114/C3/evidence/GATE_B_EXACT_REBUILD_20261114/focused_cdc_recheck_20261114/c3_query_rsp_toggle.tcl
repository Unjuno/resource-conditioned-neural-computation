load_package sta
project_open rtnn_c2
create_timing_netlist
set c [get_registers {*rtnn_c2_vjtag_mailbox:u_mailbox|rsp_toggle_sys_q}]
puts "COUNT=[get_collection_size $c]"
foreach_in_collection x $c { puts "NODE=[get_node_info -name $x]" }
project_close
