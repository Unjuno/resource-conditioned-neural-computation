# C2J2 CDC capture assertion regression (2026-11-13)

Purpose: assert that the response payload snapshot equals the stable SoC response bus at the TCK-domain capture edge. The earlier regression checked response stability from COMMIT through scan/consume and request equality at CLOCK_50 capture; this adds the symmetric TCK capture sample assertion. Only the verification testbench changed. Production RTL, frozen cases, frozen model, firmware, and RAM images were not changed.

## Exact environment and commands

- WSL distro: Ubuntu-22.04, started without elevation. Windows launch command: `wsl.exe -d Ubuntu-22.04 --exec /bin/bash /mnt/d/rtnn_c2_cdc_capture_regression_20261113.sh`.
- Build/output cwd for both targets: `D:\rtnn_c2_cdc_capture_regression_20261113\native` and `...\sv2v`.
- Verilator: `5.020 2024-01-01 rev v5.020`; fixed Ibex source dependency count 146.
- Exact native/sv2v compile invocations and source/include paths: `run_c2_cdc_capture_regression_20261113.sh`; flags include `--binary --timing -Wall -Wno-fatal`, build ID `43324a32`.
- Both raw logs were independently checked with `tools/audit_c2_soc_sim_log.py` against the frozen 42-case `evidence/c2j2_candidate_20261112/host/c2_cases.csv`.

## Results

| Gate | Result | Evidence |
|---|---|---|
| Native fixed-Ibex SoC | PASS, compile/run/audit exit 0 | `native/compile.log`, `native/run.log`, `native/audit_outputs/` |
| sv2v fixed-Ibex SoC | PASS, compile/run/audit exit 0 | `sv2v/compile.log`, `sv2v/run.log`, `sv2v/audit_outputs/` |
| Function coverage | 42/42 frozen requests, two deterministic reset replays, seven negative/reset cases all PASS | Both raw logs and independent audit JSON/CSV |
| CDC response capture assertion | PASS; no `$fatal`; `rsp_hold_tck_q === response_data` at each response-toggle capture | Updated testbench and native/sv2v logs |

Warnings: native 138 (`PINCONNECTEMPTY` 80, `UNUSEDPARAM` 48, `BLKSEQ` 4, `UNUSEDSIGNAL` 3, `SYNCASYNCNET` 2, `DECLFILENAME` 1). sv2v 210 (`WIDTHEXPAND` 91, `PINCONNECTEMPTY` 80, `UNUSEDPARAM` 23, `BLKSEQ` 4, `UNOPTFLAT` 3, `UNUSEDSIGNAL` 3, `SYNCASYNCNET` 2, `WIDTHTRUNC` 2, `ASCRANGE` 1, `DECLFILENAME` 1). Full warnings are preserved and not waived; `-Wno-fatal` only allows the builds to continue.

This is simulation protocol evidence, not post-fit CDC proof. It does not resolve D101=801 or unconstrained JTAG I/O timing. Simulated `mcycle` is not hardware data. No FPGA programming occurred; Flash/CFM untouched.
