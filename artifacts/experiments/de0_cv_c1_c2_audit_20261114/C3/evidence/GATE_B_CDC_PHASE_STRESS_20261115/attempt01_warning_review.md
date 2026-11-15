# Attempt 01 warning review

Verilator 5.020 compiled and all 19 phase cases completed with exit 0. The run used `-Wno-fatal`, so exit 0 alone is not treated as warning-free. Warnings were:

- `TIMESCALEMOD`: mailbox RTL had no explicit timescale while the testbench declared one.
- `UNUSEDSIGNAL`: `tdo` was not consumed by the testbench.
- `UNUSEDSIGNAL`: response transform did not use payload bits `[719:400]`.

Attempt 02 addresses these test-harness warnings without modifying the RTL: a timescale wrapper is added, the response scan consumes/checks TDO, the response transform includes all request bits, and `-Wno-fatal` is removed.
