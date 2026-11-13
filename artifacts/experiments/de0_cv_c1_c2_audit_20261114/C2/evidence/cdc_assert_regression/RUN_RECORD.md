# C2J2 CDC assertion regression and Quartus gate snapshot (2026-11-13)

## RTL regression

- Native fixed-Ibex SoC: PASS. Verilator 5.020, 146 fixed Ibex/FuseSoC graph sources, `--binary --timing -Wall -Wno-fatal`, build ID `43324a32`. Testbench includes simulation-only stability assertions for the bundled request/response CDC payloads.
- Results: 42 frozen C2J2 cases, two reset replays, and seven negative/reset conditions PASS. Audit status is `PASS_RTL_SIMULATION_ONLY`.
- Native simulated `mcycle` is an RTL simulation observation only. It is not a physical FPGA cycle measurement.
- sv2v-converted fixed-Ibex SoC: PASS. sv2v flat hash is recorded in `sv2v/input_hashes.txt`; Verilator 5.020 compile and run exit codes are both 0; same 42 + reset + negative audit PASS.
- Warnings: native compile has 137 Verilator warnings; sv2v compile has 209. `-Wno-fatal` allowed compilation to continue; warnings remain preserved in the full logs and are not claimed to be clean.
- Failed attempts preserved: initial WSL launch quoting error, native audit with the wrong non-case CSV, and initial sv2v testbench build-ID mismatch. Corrected final attempts passed without editing expected outputs.

## Inputs and hashes

- Frozen C2J2 case table: `references/c2_cases.csv`, SHA-256 `52b7fdae7c465fd4b6409876e258e00fbaad5656e93ad3b9fb79f2f8741aec5d`.
- C2J2 manifest: `references/C2J2_RUN_MANIFEST.json`; source/memory hashes are recorded there.
- Native run log SHA-256: `4034e04493031be38892c72611e2f723b40b0594bc2e8794aa7749b1ef522ad5`.
- Native and sv2v audited results CSV SHA-256: `dd15b0f87e059c7279392ae4e59a647c63f78db5a278572ae34d8046d9cd002e`.
- sv2v flat SHA-256: `F8994351DE4A20E74BD8726F48BB94E759F9B7A142C100A66CF73392F5D4ADF2`.
- Latest simulation testbench SHA-256: `3AAAACB7218899AC461330068314E97F9A422429034B36C6DA8BD56D55E54060`.

## Quartus snapshot (not signoff)

- Quartus Prime Lite 25.1std.0 Build 1129, Cyclone V `5CEBA4F23C7`.
- Full compile/Assembler succeeded with exit 0 and 392 warnings. Fitter completed, but post-fit Design Assistant reports 1 HIGH C105 (internal JTAG TCK not routed globally) and 801 HIGH D101 bundled CDC data-bit structures. These are open findings, not suppressed.
- All-corner setup/hold values are positive in the saved report (worst slow-corner setup +1.400 ns, hold +0.103 ns); however STA still reports 3 unconstrained input ports / 43 paths and 4 unconstrained outputs / 8 paths. The vendor asynchronous clock-group cuts payload path setup/hold checks. Positive slack is therefore not timing signoff.
- Generated SOF is saved for evidence only and was not programmed to the board.
- A separate global-clock assignment experiment is running; no conclusion is included here until its compiled Fitter report is inspected. A later SDC candidate will add only targeted net-delay/skew checks on the identified bundled payload registers; it must be compiled and reported before adoption.

## Reproduction commands

- Native cwd: `D:\rtnn_c2_soc_resetfix_native_cdcassert_20261113`; command: `bash run.sh` under WSL Ubuntu-24.04.
- sv2v cwd: `D:\rtnn_c2_soc_resetfix_sv2v_cdcassert_20261113`; command: `bash run.sh` under WSL Ubuntu-24.04.
- Both scripts and exact inputs are copied into their respective evidence subdirectories. Source paths and fixed dependency graph are recorded alongside run logs.

## Physical test status

- No C2 SOF was programmed. No Flash/CFM operation occurred. No FPGA hardware cycle values were collected. Device programming remains gated on closing the Quartus/CDC/STA findings and verifying the final SOF build identity.