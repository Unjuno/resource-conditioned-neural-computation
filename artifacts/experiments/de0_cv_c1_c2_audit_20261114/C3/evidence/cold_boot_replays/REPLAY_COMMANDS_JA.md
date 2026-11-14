# Cold-boot replay command record

Repository/cwd: `C:\Users\junny\OneDrive\ドキュメント\ChatGPT\resource-conditioned-neural-computation-audit-20261114`
Quartus: Prime Lite 25.1std.0 Build 1129. Board: USB-Blaster [USB-0], JTAG IDCODE `02B050DD`, target FPGA 5CEBA4F23C7N.

Each run used the same prepared frozen `primary_01` cases (`cases.csv` SHA-256 `25754b7adf5704df8267bdfa38d6a5ed39dad360e88b0266ce4bbc8ed483f701`), binding (`d602f5f403431df2d0c8e3fc7d24cb0991129e99d92e7898ee10f1ee6dc4943c`), schedule (`73d37a9bf03a263a01663f5bf2d74695b93493c0660309ac39ad9dba97b414c9`) and C2J2 SOF (`5aa5be2e7387e22e43db6a322e1572cceacd3266231af4dbc2de01ee649c37e6`). Before each replay, `jtagconfig -n` identified the board; `quartus_pgm.exe -c "USB-Blaster [USB-0]" -m JTAG -o "p;C:\rtnn_c3_pilot_20261114\artifacts\experiments\de0_cv_c1_c2_audit_20261114\C2\evidence\quartus_d101\rtnn_c2.sof"` loaded FPGA SRAM only; post-load JTAG design hash was `DF2731CF973C3275CFE6`. No Flash/CFM programming.

The common session command was:

```powershell
& 'artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/source/host/Invoke-C3JtagCampaignSession.ps1' `
  -CasesPath 'artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/campaign/prepared/primary_01/cases.csv' `
  -BindingPath 'artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/campaign/prepared/primary_01/binding.json' `
  -SofPath 'artifacts/experiments/de0_cv_c1_c2_audit_20261114/C2/evidence/quartus_d101/rtnn_c2.sof' `
  -ExperimentId '<EXPERIMENT_ID>' `
  -OutputDirectory 'artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/campaign/results/<EXPERIMENT_ID>' `
  -BoardPowerSessionId '<BOARD_POWER_SESSION_ID>' -ColdBootConfirmed
```

Substitutions and result:

| Replay | Experiment ID | Board power session ID | Exit/result |
|---|---|---|---|
| 1 | `C3_PRIMARY01_COLD_BOOT_REPLAY01_20261114` | `C3_BOOT01_20261114` | 0; PASS_EMPIRICAL_SESSION; 720 rows |
| 2 | `C3_PRIMARY01_COLD_BOOT_REPLAY02_20261114` | `C3_BOOT02_20261114` | 0; PASS_EMPIRICAL_SESSION; 720 rows |
| 3 | `C3_PRIMARY01_COLD_BOOT_REPLAY03_20261114` | `C3_BOOT03_20261114` | 0; PASS_EMPIRICAL_SESSION; 720 rows |

The run manifests, raw JTAG logs, audits and per-run checksums are stored in their result directories. The user confirmed DC power off/on and LED extinction; off-time was not independently timed. **USB-Blaster USB-B remained connected as requested.** The DE0-CV power schematic shows `VCC5_USB` entering the board's 5V power network, so LED extinction during DC interruption alone does not prove all FPGA rails were unpowered. A later read-only JTAG query after another user-confirmed DC cycle, without any SOF write in that check, found the same design hash and Virtual JTAG node; the source of that configuration is unresolved. Preserve the 2,160 measured rows and their per-session audits, but classify the sessions as confirmed DC power cycles, not confirmed independent cold boots. The crossed-bootstrap values remain descriptive for those sessions; cold-boot independence is UNCERTAIN. UART was unused. The replay rows are supplemental and do not alter the frozen campaign's 24,840 planned rows. See `../physical_post_coldboot3_readonly_20261114/RUN_RECORD_JA.md` and `C3/C3_FULL_CAMPAIGN_RUN_RECORD_JA.md` for the correction.
