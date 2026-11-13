load_package sta
project_open -revision rtnn_de0_cv rtnn_de0_cv
create_timing_netlist -model slow
read_sdc
update_timing_netlist
report_timing -setup -npaths 20 -detail full_path -show_routing -file critical_setup_paths.rpt
report_timing -hold -npaths 20 -detail full_path -show_routing -file critical_hold_paths.rpt
report_ucp -file unconstrained_paths.rpt
check_timing -file check_timing.rpt
report_sdc -file constraints_review.rpt
report_clocks -file clocks_review.rpt
delete_timing_netlist
project_close
