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
set_net_delay -from [get_registers {*rtnn_c2_vjtag_mailbox:u_mailbox|req_hold_tck_q[*]}] -to [get_registers {*rtnn_c2_vjtag_mailbox:u_mailbox|req_bus_sync1_sys_q[*]}] -max 16.000
set_net_delay -from [get_registers {*rtnn_de0_cv_soc_c2:u_soc|response_words_q[*][*]}] -to [get_registers {*rtnn_c2_vjtag_mailbox:u_mailbox|rsp_bus_sync1_tck_q[*]}] -max 24.000
