# Verilator warning review — fresh native C3 v2 rebuild

Build command: the preserved `run_native_v2_regression.sh`, using `verilator --binary --build-jobs 2 --timing -Wall -Wno-fatal` for the SoC test and response-write guard. `-Wno-fatal` allowed the run to complete; every warning remained in the saved compiler logs and was counted below.

| Warning | SoC compile | Guard compile | Review |
|---|---:|---:|---|
| PINCONNECTEMPTY | 80 | 80 | Optional ECC/syndrome and error output pins are left open in the selected Ibex/prim configurations. Kept visible; not treated as a timing or CDC waiver. |
| UNUSEDPARAM | 48 | 48 | Constants from imported lowRISC primitive packages are unused by this configuration. Kept visible. |
| BLKSEQ | 4 | 4 | Blocking assignments in the byte-lane RAM's sequential write model. This model is shared with the tested SoC configuration; semantics were not changed in this run. |
| SYNCASYNCNET | 2 | 0 | Testbench observes reset nets both as asynchronous reset and in synchronous capture assertions. Kept visible; assertions are finite simulation checks. |
| DECLFILENAME | 1 | 1 | `ibex_top_gate_bypass.sv` intentionally declares module `ibex_top` for this fixed integration. Kept visible. |
| UNUSEDSIGNAL | 3 | 6 | Testbench/SoC signals not used by selected test points. Kept visible; not automatically classed as harmless design logic. |

No warning class was suppressed in the source. The stored run logs remain the authority for full warning text.
