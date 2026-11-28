# Formal claim-evidence audit RUN2 — 2026-11-28

- Repository branch: `codex/external-validation-20261122`
- HEAD at audit start: `06241007895fd35d38ed03248208b67b0536f220`
- Scope: resolve all 11 claim-matrix evidence paths within repository; run negative/positive matrix-validator tests.
- Command 1: `py -3.11 -B artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/final_research_verification_20261128/verify_claim_evidence_matrix.py`
- Result: PASS, 11 claims; evidence entries resolve within repository.
- Command 2: `py -3.11 -B artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/final_research_verification_20261128/test_verify_claim_evidence_matrix.py -v`
- Result: PASS, 5/5 tests (valid repository-relative evidence, missing file, prose-as-path, repository traversal, bounded statuses).
- The formal evidence map distinguishes bounded CBMC/BINSEC/Ibex claims from DE0-CV timing, external JTAG timing and WCET; formal timing remains blocked.
- Physical session 02 was not run during this audit. The untracked `build/physical_pilot_RUN2_preparation/` directory was not read or changed.
