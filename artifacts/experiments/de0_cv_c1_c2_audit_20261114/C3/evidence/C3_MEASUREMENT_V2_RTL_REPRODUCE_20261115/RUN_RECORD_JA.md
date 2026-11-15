# C3 v2 native SystemVerilog graph reproduction — 2026-11-15

- Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`; branch `codex/stage-c3-jtag-pilot-20261114`; HEAD `b332ba02ab992227140998a1d67513c690ae17cf`.
- Build: C3 v2 `43334531`; model `52544e4e`; source list SHA-256 `4bddc5bd5e37cbd24015189d49e4a21677d570e5cb1c0a7c9dd503da30e6bfba`.
- Ibex: `lowRISC/ibex` commit `7b5df75a041affe56e8c235260f98a09b3319008`, clean worktree in WSL Ubuntu-24.04. The graph contains 146 SV sources; all 146 existed and were hashed in `ibex_source_manifest.sha256`. The source-list paths resolve partly under `/opt/rtnn-tools/ibex` and partly into the repository's C2/C3 source snapshots; these dependencies are not fully vendored into a clean repository checkout.
- Command: `bash ./run_native_v2_regression.sh` from this evidence directory in WSL Ubuntu-24.04, with the pinned 146-source list and copied request/reference/RAM image/testbench inputs.
- Toolchain: Verilator 5.020; GCC/G++ 13.3.0; glibc 2.39. Verilator used `--binary --build-jobs 2 --timing -Wall -Wno-fatal`.
- Results: source presence 146/146; SoC compile/run exit 0; 42 fixed Q15 requests pass, reset recovery pass, seven negative classes pass; response-write guard compile/run exit 0.
- Warnings remain visible and are classified in `WARNING_REVIEW_JA.md`; no warning is interpreted as fixed merely because the command returned 0.
- A fresh compile and simulation were run in this directory. Existing RETRY06 artifacts and earlier RETRY01–06 outcomes remain preserved.
- This reproduction does not close B-SIGNOFF: JTAG external timing and unconstrained TDI/TMS/TDO remain unresolved. No Quartus, board, JTAG, SOF, Flash/CFM, or power action was performed in this RTL-only run.
- `launch.exitcode` records the outer WSL command exit code 0. Per-step exit codes and full compiler/runtime logs are separately saved.
