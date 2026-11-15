# C3 v2 KEY[0] reset replay RUN4 — 2026-11-15

## 実験結果

- 実験ID: `C3V2_TENINPUT_KEY_RESET_REPLAY_20261115_RUN4`
- Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`
- Branch / HEAD: `codex/stage-c3-jtag-pilot-20261114` / `b332ba02ab992227140998a1d67513c690ae17cf`
- Quartus Prime Lite: `25.1std.0 Build 1129` (`quartus_stp_tcl.exe`)
- Board: Terasic DE0-CV, Cyclone V `5CEBA4F23C7N`; USB-Blaster USB-0; JTAG IDCODE `0x02B050DD`
- Loaded design identity: build `43334531`, READY `0x08`; read-only identity check PASS.
- SOF SHA-256: `85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d`
- Model ID: `52544e4e`; frozen subset: `primary_01`, 10 inputs × fixed/adaptive = 20 requests.
- User attested that KEY[0] was pressed and released. This is operator testimony, not electrical reset-pin telemetry. No full power cycle, SOF reconfiguration, Flash/CFM write, wiring, or clock change was performed in this run.
- Run status: **PASS 20/20**. Prediction, reference, executed Exit, cap, CRC, request/response identity, response status, and 64-bit increasing `mcycle` interval checks had zero violations.
- `mcycle` delta: min `565,954`, median `943,929`, max `2,082,594` cycles. These are cycle counts; no absolute-time or frequency conversion is claimed.
- Reset replay gate: PASS; SHA-256 `7970851b4b8b53723977ddd7eb76d216bc3f364e2c20ba189524e2b404cd1c10`.

## 実行記録

All commands were run on the Windows host. Quartus STP used ASCII CWD `C:\altera_lite\25.1std\quartus\bin64`; staged inputs/results used `C:\Users\junny\AppData\Local\Temp\rtnn-c3v2-key-reset-20261115-run4` to avoid Unicode-path issues in the Quartus/Python handoff.

1. Copied the frozen 20-row `cases.csv`, `binding.json`, Tcl runner, read-only identity checker, PowerShell auditor, and reset-gate creator into a previously nonexistent ASCII staging directory. Frozen input SHA-256 matched: cases `e9639c0fea350e813b3d8c04ed3cc7c814fd6efacdc930e6c12f14ddf5b1becd`; binding `bab047cc34dfb059e5647d0a88af9906510b9c45b31300d009d459e06d6f4d44`.
2. `quartus_stp_tcl.exe -t check_c3_v2_loaded_build.tcl` — exit 0; read-only identity matched USB-Blaster, IDCODE, build and READY.
3. `quartus_stp_tcl.exe -t run_c3_measurement_v2.tcl cases.csv binding.json <new-output> 85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d C3V2_TENINPUT_KEY_RESET_REPLAY_20261115_RUN4 49,50,141,142,209,210,277,278,325,326,379,380,431,432,487,488,559,560,719,720` — exit 0; Quartus reported 0 errors / 0 warnings and `C3_JTAG_PILOT_PASS count=20`.
4. `audit_c3_v2_jtag_results.ps1` with `-ExpectedRows 20`, the pinned SOF/build/model, the explicit frozen sequence list, and `-ExpectedScope subset` — exit 0, `status=PASS`.
5. First Python audit invocation from `%TEMP%` was rejected (exit 1) because the auditor intentionally accepts source data only from the repository's saved physical-evidence tree. The failure was retained as `python_independent_audit_attempt01.*`. The identical audit was rerun against the archived evidence directory — exit 0, `PASS_SAVED_PHYSICAL_EVIDENCE_AUDIT`.
6. First reset-gate invocation through the Unicode OneDrive path could not open the result file because the native Python argument path was mojibaked. It created no gate. The failed attempt is retained as `gate_create_attempt01.*`. The gate creator was rerun using the ASCII stage paths — exit 0; output was copied into this evidence directory and hash-checked.

## 主要SHA-256

| File | SHA-256 |
|---|---|
| `c2_jtag_results.json` | `69695e66cbb512718284534d836a45e4ea4d536a810553cdd7cc4ab9b5e870b1` |
| `c2_jtag_results.csv` | `fa9dbb919c987746ce62346ff194c3aa76dd0d90556db2fa82efb5f15f92270c` |
| `c2_jtag_raw.log` | `37558bb2585b7c8ced4e0528db9dfe811bba71609a752f07e99d0ee75cab369b` |
| `key_reset_replay_gate.json` | `7970851b4b8b53723977ddd7eb76d216bc3f364e2c20ba189524e2b404cd1c10` |
| `cases.csv` | `e9639c0fea350e813b3d8c04ed3cc7c814fd6efacdc930e6c12f14ddf5b1becd` |
| `binding.json` | `bab047cc34dfb059e5647d0a88af9906510b9c45b31300d009d459e06d6f4d44` |

`SHA256SUMS.txt` covers every file in this run directory except itself. Failure-attempt logs are included, not discarded. The result is an additional reset-replay run; it does not replace RUN3 or claim a fresh full-campaign acquisition. The previously completed C3 v2 campaign remains 24,840/24,840 across 13/13 schedules, one board and one continuous power session, **EMPIRICAL_ONLY**. Gate B-SIGNOFF remains BLOCKED; this run does not establish external JTAG timing, WCET, hard deadlines, speed superiority, or accuracy non-inferiority.
