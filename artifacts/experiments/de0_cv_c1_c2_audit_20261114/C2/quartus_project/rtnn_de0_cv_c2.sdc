create_clock -name CLOCK_50 -period 20.000 [get_ports {CLOCK_50}]
derive_clock_uncertainty
# KEY asynchronously asserts external reset and is synchronized on release.
set_false_path -from [get_ports {KEY[0]}] -to [get_registers {*rst_pipe_q*}]
# The Virtual-JTAG TCK reset has its own two-register asynchronous-assert,
# clock-synchronous-release chain. Constrain only the external reset inputs to
# those synchronizer flops; keep the internal stage-to-stage paths timed.
set_false_path -from [get_ports {KEY[0]}] -to [get_registers {*tck_reset_release_q*}]
# No blanket false path for Virtual-JTAG TCK crossings. Review generated clocks,
# CDC synchronizers, bundled-data max delays and unconstrained paths before signoff.
