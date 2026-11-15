# C3 v2 frozen-schedule Quartus STP runner

This is a new full-schedule runner. The already used 42-case and ten-input pilot runner is preserved unchanged in `measurement_protocol_v2_43334531_20261115/`.

## Full-schedule invocation

From an ASCII-only working/staging path (Quartus STP previously failed to load `fil_test` from the Unicode OneDrive path):

```text
quartus_stp_tcl.exe -t run_c3_campaign_v2.tcl CASES.csv BINDING.json OUT_DIR SOF_SHA256 EXPERIMENT_ID ALL [KEY_RESET_GATE.json]
```

`ALL` is accepted only when the versioned binding says `FULL_FROZEN_SCHEDULE`, its row count equals its frozen full-schedule count, and its selected sequences are exactly `1..N`. The runner checks that the case CSV has the same row count and exact sequence order as the binding before it opens the USB-Blaster. For a frozen subset binding, supply its exact explicit sequence list; `ALL` is rejected. It writes `scope=full_schedule` or `scope=frozen_schedule_subset` into result JSON.

Every complete frozen schedule binding, including all three diagnostic and ten primary schedules, also requires a seventh argument: a completed `rtnn-c3-key-reset-replay-gate-v1` JSON file. Pilot subset runs remain possible before and after the KEY reset. Required scalar fields are `status=PASS`, `audit_status=PASS`, `reset_action=KEY0_PRESS_RELEASE`, `user_attested=true`, `sof_sha256`, `build_id=43334531`, `response_count=20`, and a `C3V2_TENINPUT_KEY_RESET_REPLAY_...` experiment ID. It also names `result_json_path` and `audit_report_path`, their `result_json_sha256` and `audit_report_sha256`, and the exact 20 frozen pilot sequences. The runner re-hashes both files and checks the reset result and independent report identity/status before it opens JTAG. This is an operator/evidence gate, not proof that the reset event was electrically observed by software; the KEY action must be recorded truthfully. The gate file must use portable relative result/audit filenames beside itself; the runner resolves these against the gate directory before checking SHA-256. Full frozen schedules remain blocked if that evidence check fails.

The runner independently checks the SOF/build/model/campaign/schedule/case-file identities and retains raw request/response bytes. It validates response identity, CRC, prediction, reference label, admitted/executed Exit, cap, counter status, and nonzero increasing 64-bit mcycle values. It has no Programmer, Flash, erase, or device-configuration command; it uses Virtual-JTAG only.

## Offline Tcl checks

The test extracts the pure Tcl protocol functions and checks counter/CRC/JSON behavior, full and subset binding scopes, negative sequence cases, and all 13 actual SOF-bound campaign CSV/binding pairs (24,840 rows total). It does not access JTAG hardware.

```text
quartus_stp_tcl.exe -t test_c3_campaign_runner.tcl run_c3_campaign_v2.tcl run_c3_campaign_v2.tcl ASCII_BINDING_ROOT
```

Use the independent PowerShell result auditor after each physical session, with `-ExpectedScope full_schedule` for these full schedules. Keep every failed output folder and its raw log. Do not start the 24,840-row physical campaign until the ten-input KEY-reset replay has an independent PASS audit and its evidence-backed gate JSON. All physical results remain `EMPIRICAL_ONLY`; this runner does not change B-SIGNOFF or permit WCET/hard-deadline claims.
