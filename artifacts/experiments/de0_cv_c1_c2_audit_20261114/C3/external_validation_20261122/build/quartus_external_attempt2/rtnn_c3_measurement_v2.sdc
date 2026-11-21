create_clock -name CLOCK_50 -period 20.000 [get_ports {CLOCK_50}]
derive_clock_uncertainty
# KEY asynchronously asserts external reset and is synchronized on release.
set_false_path -from [get_ports {KEY[0]}] -to [get_registers {*rst_pipe_q*}]
# KEY asynchronously asserts the TCK reset chain; only its two first-stage reset pins are excepted.
set_false_path -from [get_ports {KEY[0]}] -to [get_registers {*tck_reset_release_q*}]
# No blanket false path for Virtual-JTAG TCK crossings. Review generated clocks,
# CDC synchronizers, bundled-data max delays and unconstrained paths before signoff.
# Empirical-only bundled-data routing screen. Both constraints end at the first
# payload synchronizer stage and bound the routed interconnect to 16 ns. The value
# is a declared screening threshold, not a Terasic/USB-Blaster timing specification.
# The handshake RTL holds each source payload until the synchronized acknowledgement
# or consume toggle. These checks supplement structural CDC review; they do not
# establish external JTAG timing, metastability MTBF, or formal timing signoff.
set_net_delay -from [get_registers {*rtnn_c2_vjtag_mailbox:u_mailbox|req_hold_tck_q[*]}] -to [get_registers {*rtnn_c2_vjtag_mailbox:u_mailbox|req_bus_sync1_sys_q[*]}] -max 16.000
set_net_delay -from [get_registers {*rtnn_de0_cv_soc_c2:u_soc|response_words_q[*][*]}] -to [get_registers {*rtnn_c2_vjtag_mailbox:u_mailbox|rsp_bus_sync1_tck_q[*]}] -max 16.000
