create_clock -name CLOCK_50 -period 20.000 [get_ports {CLOCK_50}]
derive_clock_uncertainty
# KEY asynchronously asserts external reset and is synchronized on release.
set_false_path -from [get_ports {KEY[0]}] -to [get_registers {*rst_pipe_q*}]
# KEY asynchronously asserts the TCK reset chain; only its two first-stage reset pins are excepted.
set_false_path -from [get_ports {KEY[0]}] -to [get_registers {*tck_reset_release_q*}]
# No blanket false path for Virtual-JTAG TCK crossings. Review generated clocks,
# CDC synchronizers, bundled-data max delays and unconstrained paths before signoff.
# Supplementary bundled-data net-delay bounds derived from the toggle-handshake RTL.
# The source holds each payload stable until the synchronized acknowledgement/consume
# toggle. Quartus reports these path checks across its generated asynchronous group;
# they supplement but do not replace CDC protocol analysis or a valid skew/signoff check.
# Fixed max net delays are checked to the first payload synchronizer stage. They are not false paths.
# Request target is 0.8 * 20 ns CLOCK_50; response target is 0.8 * the 30 ns minimum JTAG TCK period.
set_net_delay -from [get_registers {*rtnn_c2_vjtag_mailbox:u_mailbox|req_hold_tck_q[*]}] -to [get_registers {*rtnn_c2_vjtag_mailbox:u_mailbox|request_data_o[*]}] -max 16.000
set_net_delay -from [get_registers {*rtnn_de0_cv_soc_c2:u_soc|response_words_q[*][*]}] -to [get_registers {*rtnn_c2_vjtag_mailbox:u_mailbox|rsp_hold_tck_q[*]}] -max 24.000
# C3 candidate internal CDC policy; this file is loaded after the SLD hub HDL-embedded SDC.
# Remove the vendor's broad TCK-vs-all clock group, then enumerate every crossing below.
remove_clock_groups -all
set p {*rtnn_c2_vjtag_mailbox:u_mailbox|}
set_false_path -from [get_registers "${p}req_toggle_tck_q"] -to [get_registers "${p}req_sync1_sys_q"]
set_false_path -from [get_registers "${p}rsp_consume_toggle_tck_q"] -to [get_registers "${p}rsp_consume_sync1_sys_q"]
set_false_path -from [get_registers "${p}req_ack_toggle_sys_q"] -to [get_registers "${p}req_ack_sync1_tck_q"]
set_false_path -from [get_registers "${p}rsp_toggle_sys_q"] -to [get_registers "${p}rsp_sync1_tck_q"]
set_false_path -from [get_registers "${p}busy_sys_q"] -to [get_registers "${p}busy_sync1_tck_q"]
set_false_path -from [get_registers "${p}error_sys_q"] -to [get_registers "${p}error_sync1_tck_q"]
set_false_path -from [get_registers "${p}done_sys_q"] -to [get_registers "${p}done_sync1_tck_q"]
set req_src [get_registers {*rtnn_c2_vjtag_mailbox:u_mailbox|req_hold_tck_q[*]}]
set req_dst [get_registers {*rtnn_c2_vjtag_mailbox:u_mailbox|request_data_o[*]}]
set rsp_src [get_registers {*rtnn_de0_cv_soc_c2:u_soc|response_words_q[*][*]}]
set rsp_dst [get_registers {*rtnn_c2_vjtag_mailbox:u_mailbox|rsp_hold_tck_q[*]}]
set_max_delay -from $req_src -to $req_dst 40.000
set_max_delay -from $rsp_src -to $rsp_dst 60.000
set_max_skew -from $req_src -to $req_dst 40.000
set_max_skew -from $rsp_src -to $rsp_dst 60.000
# Board schematic shows these ports drive only LED indicators through series resistors.
set_false_path -to [get_ports {LEDR[0] LEDR[1] LEDR[3]}]
