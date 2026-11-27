# Claim-evidence matrix audit — RUN1 (2026-11-28)

## Result

`CLAIM_EVIDENCE_MATRIX.csv` now uses file references in the `evidence` column for all 11 claims. The previous C6, C7, and C8 cells contained descriptive prose instead of auditable references. Those cells now point to the repository status, data-history, dataset, and timing-gate records. The recorded gate states remain `C6=NOT_RUN`, `C7=INELIGIBLE`, and `C8=BLOCKED`.

The new validator resolves repository-root, C3-root, and matrix-directory-relative references, rejects traversal outside the repository, rejects missing evidence, and guards the three unresolved statuses above. It does not claim that a referenced document proves more than its stated scope.

## Verification

Commands run from the repository root:

```text
python artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/final_research_verification_20261128/verify_claim_evidence_matrix.py
python artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/final_research_verification_20261128/test_verify_claim_evidence_matrix.py -v
python -m py_compile artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/final_research_verification_20261128/verify_claim_evidence_matrix.py artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/final_research_verification_20261128/test_verify_claim_evidence_matrix.py
```

Results: all 11 matrix claims resolve to files; five validator tests pass, including missing path, prose-as-path, traversal, and status-tampering rejection; Python syntax check passes. Logs are `validator.log` and `tests.log` beside this report.

## RUN2 preparation-folder observation

Read-only inspection found a nested candidate file at `artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/external_validation_20261122/build/physical_pilot_RUN2_preparation/cases.csv/cases.csv`. It contains 20 candidate rows for experiment `C3_EXTVAL_PILOT_20261126_RUN2`, session `PILOT_SESSION_20261126_RUN2`, sequence 1–20. SHA-256 is `5f7bece95b30620eaf70e53d21bcdc087baa4b10116f591461c714b9a5bbcc8f`. No `raw_jtag.log`, `run_status.json`, or independent audit JSON exists beside it. It is preparation data, not a completed physical experiment, and was not changed or staged in the prior commit.

The saved RUN4 case file SHA-256 is `fb37097914916ad41a18e9c13e476216f66335e91973aff6b333e62546529093`; the RUN2 candidate CSV is a distinct file. Neither candidate nor historical pilot data are promoted by this audit.

## Scope

No JTAG, SOF, board, power, KEY, or wiring operation was performed. External primary remains `NOT_RUN`. `DATA_EXPOSURE_UNCERTAIN`, `WRITER_CLUSTER_UNKNOWN`, `PREREGISTRATION_TIMELINE_UNVERIFIED`, `COLD_BOOT_UNVERIFIED`, and `FORMAL_TIMING_SIGNOFF_BLOCKED` remain unresolved.
