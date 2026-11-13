create_clock -name CLOCK_50 -period 20.000 [get_ports {CLOCK_50}]
derive_clock_uncertainty
# KEY[0] asynchronously asserts the reset synchronizer. Its release is gated through rst_pipe_q.
# The KEY input is asynchronous to CLOCK_50 and has no synchronous input-delay requirement.
set_false_path -from [get_ports {KEY[0]}] -to [get_registers {*rst_pipe_q*}]
# UART RX is asynchronous; cut only its first metastability capture stage.
# None is synchronously captured by an external CLOCK_50 device, so no output-delay constraint is defined.

# Diagnostic only: bound register-to-pin propagation to one CLOCK_50 cycle; not external receiver setup/hold.



# Autonomous self-test outputs only; internal propagation checks, not external timing signoff.
set_max_delay 20.000 -from [get_registers {*} ] -to [get_ports {LEDR[0] LEDR[1] LEDR[2] LEDR[3]}]
set_min_delay 0.000 -from [get_registers {*} ] -to [get_ports {LEDR[0] LEDR[1] LEDR[2] LEDR[3]}]
