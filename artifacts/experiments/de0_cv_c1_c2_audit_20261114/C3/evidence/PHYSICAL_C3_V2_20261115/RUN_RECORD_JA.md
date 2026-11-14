# C3 v2 physical replay record — 2026-11-15

Correct repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`
Branch: `codex/stage-c3-jtag-pilot-20261114`
HEAD baseline: `c17c44e5556acc9c9e2d4fdbd114714c9c1ad804` (reported `9af7c44...` is an ancestor). Local edits are uncommitted; no push/PR/merge.

## Hardware identity and programming

- Quartus: Prime Lite 25.1std.0 Build 1129.
- `jtagconfig` (read only): exit 0; `USB-Blaster [USB-0]`, IDCODE `02B050DD`, chain device `5CE(BA4|FA4)`.
- SOF: `85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d`.
- Programmer CWD: `C:\altera_lite\25.1std\quartus\bin64`.
- Command: `quartus_pgm -c "USB-Blaster [USB-0]" -m JTAG -o "p;<SOF>"`; exit 0; Quartus reports one device configured, IDCODE `0x02B050DD`, 0 errors/0 warnings.
- The operation was `p;` of a `.sof`, which loads volatile FPGA SRAM. No `.pof`/`.jic`, Flash/CFM, EPM240, voltage, cabling, or clock-setting operation was used.

## Runs

1. `C2J2_REPLAY_RUN1`: all 42 responses reached CSV and each row matched expected prediction/Exit/CRC/ID/counter checks, but independent strict JSON parsing failed because the serializer emitted hex model/build/binding IDs as unquoted JSON numbers. `FAIL_POSTRUN_JSON_INVALID`; preserved without modification. It is excluded from PASS counts.
2. A first Tcl launch from the Unicode OneDrive path failed before device access with `package "fil_test" isn't loaded statically`, exit 3. Preserved under `QUARTUS_STP_PATH_FAILURE`. Re-running from an ASCII `D:\` staging path loaded the Tcl package correctly.
3. The runner serializer was minimally fixed to emit the three hex IDs as JSON strings (empty error rows serialize as null). Tcl protocol smoke passed, including a new assertion for the three JSON string fields.
4. `C3V2_C2J2_REPLAY_RUN2_20261115`: Quartus STP Tcl exit 0; 42/42. Independent PowerShell strict JSON+CSV/raw-log audit exit 0. ID set `{0,24,57}`, CRC mismatch 0, cycle invalid 0, prediction mismatch 0, Exit mismatch 0, response identity mismatch 0, timeout/trap/error 0. mcycle range 20,151–2,791,490; median 1,031,305.5. This is the C3 v2 build, not the old C2J2 SOF result.
5. 10-input selection was frozen before C3 v2 hardware outcomes: ascending IDs 1–10 from frozen `primary_01`, excluding 0/24/57; for each input, mode 1 fixed Exit 2 plus its same-input mode 3 adaptive row; sequence order is ascending frozen schedule order. SOF is bound in the versioned case binding.
6. `C3V2_TENINPUT_PILOT_SESSION1_20261115`: STP exit 0; 20/20. Independent strict JSON+CSV/raw-log audit exit 0. All 10 inputs have both modes; CRC/identity/prediction/Exit/cycle/status mismatches 0. mcycle range 565,954–2,082,594; median 943,929. This is session 1 only; KEY-reset replay is pending user action.

All outputs are `EMPIRICAL_ONLY`; no WCET, hard deadline, or timing-signoff claim is made. C2J2 42 replay data and pilot data are separate from the 360 campaign. The full 360 campaign has not been run.

## Frozen campaign preparation audit (host only)

The 13 frozen schedules were copied to versioned C3 v2 bindings naming build `43334531`, model `52544e4e`, and SOF SHA `85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d`. An independent audit confirmed 13 schedules / 24,840 rows / 360 unique accuracy inputs, exact byte equality of each copied case CSV to its original host dry-run CSV, and each binding/case SHA. Command:

`python artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/source/audit_c3_v2_campaign_binding.py --bound-root artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/evidence/C3_MEASUREMENT_V2_PHYSICAL_PREP_20261115/campaign_sof_bound_v2 --dryrun-root artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/evidence/C3_MEASUREMENT_V2_CAMPAIGN_HOST_DRYRUN_20261115`

Result: `PASS_HOST_BINDING_AUDIT_NOT_PHYSICAL`, exit 0; 0 physical rows. The start gate remains `WAIT_FOR_TEN_INPUT_KEY_RESET_REPLAY_PASS`. The log and exit code are in `C3_MEASUREMENT_V2_PHYSICAL_PREP_20261115/campaign_binding_audit.exit0.log` and `campaign_binding_audit.exitcode`.

A stricter re-audit also verified the host dry-run report's SHA, its per-session binding/case SHA records, and field-by-field equality between every new binding and its host-only predecessor after applying only the documented C3 v2 SOF/eligibility/gate metadata. It again returned `PASS_HOST_BINDING_AUDIT_NOT_PHYSICAL`, 13 schedules, 24,840 rows, 360 unique inputs, and 0 physical rows. See `C3_MEASUREMENT_V2_PHYSICAL_PREP_20261115/campaign_binding_audit_v2.log` and `.exitcode`.

## Reproduction

`quartus_stp_tcl.exe -t <runner.tcl> <cases.csv> <binding.json> <new-output-dir> 85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d <experiment-id> <explicit-sequence-list>`

Run from Quartus bin64 with ASCII paths. For audit:

`pwsh -NoProfile -File audit_c3_v2_jtag_results.ps1 -RunDirectory <run-dir> -ExpectedRows <N> -ExpectedSofSha256 85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d -ExpectedBuildId 43334531 -ExpectedModelId 52544e4e -ExpectedSequenceCsv <comma-separated-sequences>`

The exact arguments, tool exits, case/binding inputs, raw JTAG transcript, CSV, JSON, audit output, and per-file hashes are in this directory. No run output is overwritten.
