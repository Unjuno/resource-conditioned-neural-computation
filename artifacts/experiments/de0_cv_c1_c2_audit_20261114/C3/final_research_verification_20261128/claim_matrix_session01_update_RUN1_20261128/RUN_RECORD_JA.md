# Claim matrix / formal evidence map update — 2026-11-28

## Scope

After primary session 01 was independently audited, the C6 claim matrix still said `NOT_RUN`, and the formal evidence map described primary data as unmeasured. Updated those living summaries to accurately describe the one-session empirical result, while retaining restrictions on population inference, independent power sessions, and formal timing/WCET.

## Files changed

* `../CLAIM_EVIDENCE_MATRIX.csv`: C6 now `OBSERVED_EMPIRICAL_ONLY`, with session 01 report, analysis, and independent audit as evidence.
* `../FORMAL_EVIDENCE_MAP_JA.md`: documents the new-build session 01 observation and its limits.
* `../verify_claim_evidence_matrix.py`: requires C6 empirical-only, C7 ineligible, and C8 blocked states.
* `../test_verify_claim_evidence_matrix.py`: negative test now protects all three bounded statuses.

## Verification

Commands:

```powershell
py -3.11 -B <repo>/artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/final_research_verification_20261128/verify_claim_evidence_matrix.py
py -3.11 -B <repo>/artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/final_research_verification_20261128/test_verify_claim_evidence_matrix.py
```

Results: evidence verifier resolved 11/11 claims. Unit tests passed 5/5, including fail-closed preservation of C6 `OBSERVED_EMPIRICAL_ONLY`, C7 `INELIGIBLE`, and C8 `BLOCKED`.

Session 01 remains one observed board session: 7,626 requests, 3,813 paired images. The 19.515% input-paired mean cycle saving and −0.639 pp numeric lower bound are session-specific empirical/numeric results. They do not establish cross-session reproducibility or population claims. `COLD_BOOT_UNVERIFIED`, `DATA_EXPOSURE_UNCERTAIN`, `WRITER_CLUSTER_UNKNOWN`, `PREREGISTRATION_TIMELINE_UNVERIFIED`, and `FORMAL_TIMING_SIGNOFF_BLOCKED` remain unchanged.
