# Gate B CDC mailbox phase stress — 2026-11-15

## 結果と範囲

- 正しいrepository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`
- branch / HEAD: `codex/stage-c3-jtag-pilot-20261114` / `b332ba02ab992227140998a1d67513c690ae17cf`
- RTL: C3 v2 build `43334531`のnative mailbox (`rtnn_c2_vjtag_mailbox.sv`)と、保存済みQuartus flat RTLから文字列抽出した同名mailbox module。
- Quartus flat全体の入力SHA-256: `7c0675a6b2862c6db68f8ec1c0ceb517161389e0a3a64c7cf3bd10f33c4e9bb1`。native mailbox SHA-256: `7cc0cb69bfddf4309f3b95370ce7c0e06b99e235eb8204b40816f40ff0f719d1`。全入力/テスト/抽出moduleのhashは`INPUT_SHA256.txt`。
- Tool: WSL Ubuntu 24.04、Verilator `5.020 2024-01-01 rev (Debian 5.020-1)`。
- Final run: native 19/19 phase combinations PASS、flat 19/19 PASS。各条件32要求応答、合計1,216取引。Verilator warnings 0、errors 0。`-Wno-fatal`は使っていない。
- `CLOCK_50`は20 ns周期。TCKは30 ns、35 ns、42 ns周期で、各周期内の複数phase offsetを試験。要求payload安定、受信capture一致、response payload保持、TDOでshiftした480-bit応答、consume後idle復帰をチェック。
- Run evidence: `phase_matrix.csv`, `phase_sweep_native_flat.log`, `attempt04_console.log`, per-attempt logs/exit codes, `SHA256SUMS.txt`。

## 実行コマンド

Input preparation and simulation were performed on the local Windows host with WSL Ubuntu 24.04. ASCII staging path: `C:\Users\junny\AppData\Local\Temp\rtnn-c3-cdc-phase-stress-20261115-r4` (WSL: `/mnt/c/Users/junny/AppData/Local/Temp/rtnn-c3-cdc-phase-stress-20261115-r4`). Build products were written to `/tmp/rtnn-c3-cdc-phase-stress-20261115-r4/obj_dir`, not into an existing Quartus project.

```bash
python3 extract_mailbox_from_flat.py \
  --flat-rtl full_quartus_flat.v \
  --output flat/rtnn_c2_vjtag_mailbox.sv
BUILD_DIR=/tmp/rtnn-c3-cdc-phase-stress-20261115-r4/obj_dir \
RUN_LOG=/mnt/c/Users/junny/AppData/Local/Temp/rtnn-c3-cdc-phase-stress-20261115-r4/phase_sweep.log \
bash ./run_phase_sweep.sh
```

The final runner compiles each variant with `verilator --binary --timing --assert -Wall`, then executes the frozen 19-case clock/phase matrix. Quartus was not invoked and no board/JTAG/SOF/Flash action was taken for this simulation.

## 失敗試行とwarning処置

- Attempt 01 (exit 0): native only, 19/19 passed, but `-Wno-fatal` allowed `TIMESCALEMOD` and two `UNUSEDSIGNAL` warnings. The TDO output was not consumed, and part of the request payload did not influence the synthetic response. The log and warning review are retained.
- Attempt 02 (exit 0): native only, 19/19 passed with no warnings after adding a timescale wrapper, consuming/checking TDO, using all request payload bits in the synthetic response, and removing `-Wno-fatal`.
- Attempt 03 (exit 1): native matrix 19/19 passed; flat-module compile stopped on `DECLFILENAME` because the extracted module filename did not match its module name. This warning was not suppressed. The same extracted RTL was emitted under `flat/rtnn_c2_vjtag_mailbox.sv` for the final run.
- Attempt 04 (exit 0): native and flat module variants each passed all 19 conditions; 0 `%Warning`, 0 `%Error`.

## Gate B解釈

This is a finite zero-delay digital RTL protocol stress test. It does **not** model analog metastability, synchronizer MTBF, voltage/temperature, PCB or USB-Blaster propagation delays, nor prove all phases/frequencies or all formal traces. It strengthens the finite CDC payload/handshake evidence only. D102 remains visible and unwaived; the 16 ns `set_net_delay` entries remain declared empirical routing screens, not a vendor timing guarantee. The external TDI/TMS/TDO input/output delays and actual onboard USB-Blaster timing are still unknown. Therefore **B-SIGNOFF remains BLOCKED** and this result does not permit WCET or hard-deadline claims.
