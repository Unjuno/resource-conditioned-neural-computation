# C3 v2 KEY[0] reset replay RUN5 — 2026-11-15

## 結果

- Experiment ID: `C3V2_TENINPUT_KEY_RESET_REPLAY_20261115_RUN5`
- Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`
- Branch / HEAD: `codex/stage-c3-jtag-pilot-20261114` / `b332ba02ab992227140998a1d67513c690ae17cf`
- Quartus Prime Lite Signal Tap Tcl: `25.1std.0 Build 1129`
- Target: Terasic DE0-CV / Cyclone V `5CEBA4F23C7N`, USB-Blaster USB-0, JTAG IDCODE `0x02B050DD`
- Loaded build: `43334531`, READY `0x08`; SOF SHA-256 `85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d`
- SOF SHA is the locally bound programmed artifact identity; it is not read back from the FPGA. The device check reads the design build ID and READY status.
- KEY[0] press/release: operator attested before this run. The read-only build/READY check was performed immediately before sending the 20 requests; the report does not claim electrical reset-pin telemetry.
- Frozen subset: `primary_01`, sequence IDs `49,50,141,142,209,210,277,278,325,326,379,380,431,432,487,488,559,560,719,720`, covering input IDs 1–10 in fixed-2/adaptive modes.
- Physical result: **PASS 20/20**. Frozen Q15 prediction, reference, admitted/executed Exit, cap, CRC, request/response identity, status, and 64-bit `mcycle` interval checks had zero violations.
- Cycle delta range: `565,954`–`2,082,594` cycles. No absolute time/frequency conversion is claimed.
- Power cycle, SOF reconfiguration, Flash/CFM write, wiring change, and clock change: none.
- Reset replay gate SHA-256: `c562fb9dfd40b41b532541794bba7104e791e67ac6884c1008f72bc508780a27`.

## Commands and execution context

Windows host. Inputs and output were staged in the new ASCII directory:
`C:\Users\junny\AppData\Local\Temp\rtnn-c3v2-key-reset-20261115-run5`.
Quartus executable: `C:\altera_lite\25.1std\quartus\bin64\quartus_stp_tcl.exe`.

1. Read-only identity check, CWD `C:\altera_lite\25.1std\quartus\bin64`:

   `quartus_stp_tcl.exe -t <stage>\check_c3_v2_loaded_build.tcl` — exit 0, USB-Blaster / JTAG IDCODE / build ID / READY all matched. Log: `RUN5_identity_readonly.log`.

2. Physical replay, CWD `<stage>`:

   `quartus_stp_tcl.exe -t <stage>\run_c3_measurement_v2.tcl <stage>\cases.csv <stage>\binding.json <stage>\C3V2_TENINPUT_KEY_RESET_REPLAY_20261115_RUN5 85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d C3V2_TENINPUT_KEY_RESET_REPLAY_20261115_RUN5 49,50,141,142,209,210,277,278,325,326,379,380,431,432,487,488,559,560,719,720`

   Exit 0; `C3_JTAG_PILOT_PASS count=20`; Quartus reported 0 errors and 0 warnings. Raw JTAG log and JSON/CSV are preserved here.

3. Independent PowerShell audit:

   `powershell.exe -NoProfile -ExecutionPolicy Bypass -File <stage>\audit_c3_v2_jtag_results.ps1 -RunDirectory <stage>\C3V2_TENINPUT_KEY_RESET_REPLAY_20261115_RUN5 -ExpectedRows 20 -ExpectedSofSha256 85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d -ExpectedBuildId 43334531 -ExpectedModelId 52544e4e -ExpectedSequenceCsv 49,50,141,142,209,210,277,278,325,326,379,380,431,432,487,488,559,560,719,720 -ExpectedScope subset`

   Exit 0, status `PASS`, 20 responses, no bad identity/CRC/cycle/prediction/Exit/scope fields.

4. Strict saved-evidence audit:

   `python C3/source/audit_saved_c3_v2_runs.py --result-json <evidence>\c2_jtag_results.json --result-csv <evidence>\c2_jtag_results.csv --cases-csv <evidence>\cases.csv --binding-json <evidence>\binding.json --raw-log <evidence>\c2_jtag_raw.log --expected-experiment C3V2_TENINPUT_KEY_RESET_REPLAY_20261115_RUN5 --output-json <evidence>\python_independent_audit.json`

   Exit 0, status `PASS_SAVED_PHYSICAL_EVIDENCE_AUDIT`.

5. The first gate-creation invocation using the Unicode OneDrive repository path failed to open its result path; no gate was produced. The next attempt from the ASCII stage directory failed closed because result and audit paths were in different directories. The final attempt copied the actual PowerShell audit beside the result, then passed from the ASCII stage directory with the operator-confirmation flag. The failure notes/logs and exit codes are preserved.

## SHA-256

| File | SHA-256 |
|---|---|
| `c2_jtag_results.json` | `9296dacdcc7cf3ed4b6a9a3bbcdb3442227b007c2c3020dfab63c2652be6488f` |
| `c2_jtag_results.csv` | `81bb113e6ebc602feb846788be4f2f1bde5a62b618daa31be7c1f3cd3024c5ec` |
| `c2_jtag_raw.log` | `b0190357f0f9a9a51ba23732179f076f95d6cb077ba2d9d41faf1dafe5718a92` |
| `cases.csv` | `e9639c0fea350e813b3d8c04ed3cc7c814fd6efacdc930e6c12f14ddf5b1becd` |
| `binding.json` | `bab047cc34dfb059e5647d0a88af9906510b9c45b31300d009d459e06d6f4d44` |
| `key_reset_replay_gate.json` | `c562fb9dfd40b41b532541794bba7104e791e67ac6884c1008f72bc508780a27` |

`SHA256SUMS.txt` covers every file in this run directory except itself. This extra reset replay is kept separate from the frozen 24,840-row campaign. It supports an operator-attested KEY[0] replay only; it does not establish external JTAG timing, cold-boot independence, WCET, hard deadlines, speed superiority, or accuracy non-inferiority.
