# Session 02 physical attempt 01 — tool startup failure and diagnosis

Date: 2026-11-28 JST. Experiment: `C3_EXTVAL_PRIMARY_20261128_S02`; intended schedule: 7,626 requests, sequences 7648–15273.

## Pre-run evidence

- Read-only JTAG IDCODE `02B050DD`, Build ID `45585631`, mailbox READY=1, BUSY=0, ERROR=0.
- Host SOF SHA matched the frozen binding. The runner would not program the SOF; Flash/CFM/CPLD changes were not requested.
- Frozen binding, case count and pilot gate passed preflight. No run output directory existed before launch.

## Attempt and result

`host_v2_20261126/Invoke-ExternalValidation.ps1` was invoked with `-ExecutePhysical`, using the frozen session02 cases/binding and a unique ASCII Temp output directory. PowerShell returned 1 because Quartus STP Tcl returned 3. The launch log reports `package "fil_test" isn't loaded statically`. No output directory, `raw_jtag.log`, `physical_results.csv`, or `run_status.json` was created. Completed requests: 0/7,626. No retry was made.

The production Tcl source calls the pilot-binding verifier and `package require ::quartus::jtag` before `get_hardware_names`, `open_device`, or any request scan. Thus this attempt did not reach device discovery/open or transfer a request. The prior read-only identity observation is separate and remains valid only for its observation time.

## Offline diagnosis

A no-device Tcl probe passed the Unicode repository verifier/case/binding paths to Python through Quartus Tcl. Its log shows the `OneDrive\\ドキュメント` path component corrupted to replacement characters, and Python could not open the verifier. In an ASCII-only staged copy, PowerShell preflight returned `PREFLIGHT_ONLY` for 7,626 cases; Tcl pilot-gate verification and `package require ::quartus::jtag` both passed. A copy of the production Tcl stopped immediately after package initialization with exit 0; it did not call device discovery and created no output. These probes establish that ASCII staging avoids the demonstrated path-marshalling failure; they do not establish a complete physical runner pass. The exact cause of the original `fil_test` console text remains unproven.

## Classification

This is a failed host/tool-start attempt, not a physical measurement session and contributes zero rows. Power history was not confirmed: `POWER_SESSION_UNKNOWN / COLD_BOOT_UNVERIFIED`. Any retry must preserve this failure, use a new experiment/attempt identity and a fresh output path, and retain the same frozen input/mode/order schedule.

A preliminary copy to `C:\rtnn_s02_readonly_20261128.tcl` was denied by Windows permissions before any executable launched; the subsequent read-only identity check from `%TEMP%` succeeded.
