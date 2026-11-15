# C3 v2 KEY[0] reset replay — RUN3

- Experiment ID: `C3V2_TENINPUT_KEY_RESET_REPLAY_20261115_RUN3`
- Date/time: 2026-11-15, Asia/Tokyo
- Repository branch/HEAD at start: `codex/stage-c3-jtag-pilot-20261114` / `b332ba02ab992227140998a1d67513c690ae17cf`
- Hardware: Terasic DE0-CV; Cyclone V JTAG IDCODE `0x02B050DD`; USB-Blaster `USB-0`
- Quartus STP: Prime Lite 25.1std.0 Build 1129
- Build/binding ID: `43334531`; model ID: `52544e4e`
- SOF SHA-256: `85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d`
- Frozen case SHA-256: `e9639c0fea350e813b3d8c04ed3cc7c814fd6efacdc930e6c12f14ddf5b1becd`
- Frozen binding SHA-256: `bab047cc34dfb059e5647d0a88af9906510b9c45b31300d009d459e06d6f4d44`

## Actions and results

1. User attested that they pressed and released DE0-CV KEY[0]. No power cycle, SOF reconfiguration, Flash/CFM write, wiring change, or voltage/clock change was performed for this run.
2. Quartus STP read-only identity checker: exit 0; USB-Blaster, IDCODE `0x02B050DD`, build `0x43334531`, mailbox READY `0x08`. It reads the configured build ID; it does not read back or prove the SOF SHA.
3. Ran frozen `primary_01` reset replay sequence `49,50,141,142,209,210,277,278,325,326,379,380,431,432,487,488,559,560,719,720` using the existing C3 v2 runner; Quartus STP exit 0, 20/20 responses.
4. PowerShell post-audit exit 0, status PASS. Response identity, sequence, reference prediction, executed Exit, CRC, counter validity, and case status had zero discrepancies. Observed cycle delta range: 565,954–2,082,594 Ibex cycles.
5. Independent Python saved-evidence audit: `PASS_SAVED_PHYSICAL_EVIDENCE_AUDIT`; 20 responses, 10 unique frozen input IDs.
6. Reset gate generated from the run result, PowerShell audit, their SHA-256 values, and operator attestation. Gate SHA-256: `777e7cd18eca46f381454402993d82806508bee24921c0f9ba7ee275769e087b`.

## Interpretation and limits

This establishes that the saved C3 v2 flow completed the frozen 20-request replay after the operator-attested KEY[0] press/release, on the same identified build. It is not electrical reset-pin telemetry. The cycle values are empirical measurements at the firmware's `mcycle` boundary, not calibrated absolute time or a WCET/deadline guarantee. The separate B-SIGNOFF gate remains BLOCKED because DE0-CV external JTAG path timing and required external I/O timing constraints are not established. This run does not upgrade B-SIGNOFF, accuracy non-inferiority, or population-level performance claims.

## Reproduction

Quartus STP working directory: `C:\altera_lite\25.1std\quartus\bin64`.

Read-only identity command:

```powershell
quartus_stp_tcl.exe -t check_c3_v2_loaded_build.tcl
```

Experiment command used the staged copies of `cases.csv`, `binding.json`, and `run_c3_measurement_v2.tcl`, with the sequence list above, experiment ID above, and SOF SHA above. The exact process invocation is retained in `C3V2_TENINPUT_KEY_RESET_REPLAY_20261115_RUN3.quartus.log`; exit code is in the corresponding `.quartus.exitcode` file.

The Tcl runner unit regression was also rerun after the JSON-escape source repair. Quartus STP 25.1 Build 1129, exit 0, zero Quartus errors/warnings; output `C3_CAMPAIGN_TCL_PROTOCOL_PASS ... frozen_bindings=13 rows=24840 ... reset_gate=valid_invalid_sha ... fail_closed_before_jtag=1`. Attempt13 and attempt14 passed with the correct binding root; attempt14 reran after line-ending cleanup. Final log: `evidence/C3_MEASUREMENT_V2_RUNNER_RESET_GATE_20261115/attempt14_quartus_stp_tcl.log`. Attempt12 is preserved; it used the wrong binding-root argument and failed before exercising the reset-gate test.

No commit or push was performed. No 24,840-row campaign was started in this run; existing campaign evidence is unchanged.