# Session 02 offline preflight re-verification

Status: `PASS_OFFLINE_ONLY`; the physical session was not started.

The saved preflight record was independently checked against the current files: 7,626 cases, sequence range 7648–15273, binding schedule and case SHA, host runner SHA, and the RUN4 pilot-gate SHA. The existing `verify_binding` validator accepted the primary binding. Build/Binding/Model IDs, SOF SHA, and ELF SHA match the campaign identity.

The saved record says `PREFLIGHT_ONLY`, `physical_jtag_started=false`, `quartus_started=false`, `output_directory_created=false`, `sof_programming_performed=false`, and `flash_written=false`. This check did not contact the DE0-CV and does not establish its current loaded SOF, READY state, or power history.

Reproduction command:

```powershell
py -3.11 -B artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/final_research_verification_20261128/verify_session02_preflight.py `
  --package artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/external_validation_20261122 `
  --session-dir artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/external_validation_20261122/build/physical_primary_3session_20261128/session_02 `
  --output artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/final_research_verification_20261128/session02_preflight_reverification_RUN1.json
```

The first attempt to write the report into the longer nested `session_02` path failed with Windows `FileNotFoundError` during creation; no file was created there. The report was redirected to the shorter `final_research_verification_20261128` path. No campaign data or directory was changed by the failed attempt.

Hashes of the checker, report, saved preflight inputs, current runner, and pilot gate are recorded in `session02_preflight_reverification_SHA256SUMS.txt`.
