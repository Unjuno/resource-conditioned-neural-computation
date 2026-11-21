# C3 v2 exact-artifact paper evidence package (2026-11-17)

This is a separate **offline paper-audit snapshot** derived from preserved experimental evidence. It does not contain a new JTAG/Quartus/FPGA measurement and does not alter frozen models, inputs, schedules, or historical outputs.

## Outputs

- [English manuscript draft](MANUSCRIPT_DRAFT_EN.md) — empirical case study, limitations and primary literature.
- [Japanese evidence and next-gates report](RESEARCH_DECISION_JA.md).
- [Independent primary analyzer](reanalyze_c3v2_primary.py), [11 primary tests](test_reanalyze_c3v2_primary.py).
- [Independent frozen diagnostic budget analyzer](analyze_budget_diagnostics.py), [4 diagnostic tests](test_budget_diagnostics.py); 17,640 diagnostic rows, 21 budget classes each for adaptive and capped, seven fixed classes.
- [Secondary diagnostic budget table](diagnostic_run1/budget_summary.csv), [budget-cycle figure](diagnostic_run1/figure_03_budget_vs_cycles.svg), [diagnostic analysis JSON](diagnostic_run1/analysis.json), [SHA manifest](diagnostic_run1/SHA256SUMS.txt).
- [Publication-readiness audit](PUBLICATION_READINESS_AUDIT_JA.md), [review execution record](REVIEW_RUN_RECORD_JA.md).
- [Current review SHA manifest](SHA256SUMS_PAPER_REVIEW.txt), which supersedes the archived original SHA256SUMS_PAPER.txt after the reviewer amendments.
- [Pinned Ibex/project source-hash checker](audit_native_source_portability.py), [145/146 result](NATIVE_SOURCE_PORTABILITY_AUDIT.json), [source reproducibility gap](SOURCE_REPRO_GAP_JA.md). The checker intentionally reports BLOCKED when any source SHA differs; this is not a successful RTL build.
- [Machine-readable analysis](generated_run1/analysis.json), [360-row input-level table](generated_run1/input_level.csv), [10 schedule summary](generated_run1/primary_sessions.csv).
- [Paired saving figure](generated_run1/figure_01_paired_cycle_saving.svg), [executed-exit figure](generated_run1/figure_02_exit_cycles.svg).
- [Output SHA manifest](generated_run1/SHA256SUMS.txt).

## Reproduce from repository root

```bash
python3 -m unittest discover -s artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/paper_20261117 -p 'test_*.py' -v
python3 artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/paper_20261117/reanalyze_c3v2_primary.py --out-dir /tmp/rtnn-c3v2-paper-independent-new
python3 artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/paper_20261117/analyze_budget_diagnostics.py --out-dir /tmp/rtnn-c3v2-paper-budget-new
```

Requirements: Python 3.10+ standard library; published repository checkout containing original C3 archived physical primary CSV files and the C2J2 historical primary CSVs. No device, administrator rights, statistics service or network access is needed after checkout. The analyzer refuses to overwrite its destination.

For a reproducibility comparison, compute SHA-256 hashes of all generated primary outputs against `generated_run1/SHA256SUMS.txt`, the diagnostic outputs against `diagnostic_run1/SHA256SUMS.txt`, and the **current** manuscript/script files against `SHA256SUMS_PAPER_REVIEW.txt` (the earlier SHA256SUMS_PAPER.txt is historical). An independent second run produced byte-identical outputs and matching SHA manifest.

## Claim boundaries

All primary paired rows use **maximum admitted Q0.16 budget 65535** and no deadline; the 20.934% figure is the full-budget adaptive-versus-fixed-Exit-2 contrast, not a budget-sweep improvement. The baseline fixed Exit 2 was chosen with **prior test results already known** (frozen campaign metadata), so the result is not a new test-blind generalization claim. Budget dependence is separately documented as **secondary diagnostic evidence** in `diagnostic_run1/`.

The input bootstrap (5000 repeats, seed 63) resamples **360 distinct input IDs**, not the ten schedules as independent experimental units. All ten schedule repetitions showed identical cycle deltas for every input/mode. Independent cold boots were *not* verified. No formal board-level JTAG timing signoff, calibrated latency, WCET or one-point accuracy noninferiority is claimed. The observed five-cycle shift from C2J2 to C3 v2 is an association across two specific builds and requires compiler/instrumentation analysis for causal attribution.

The source CSVs remain in their original locations:
- `../evidence/PHYSICAL_C3_V2_20261115/FROZEN_CAMPAIGN/C3V2_PRIMARYnn_FULL720_RUN1_20261115/results/c2_jtag_results.csv`
- `../campaign/results/C3_PRIMARYnn_FULL720_RUN1_20261114/{c2_jtag_results.csv|merged/c2_jtag_results.csv}`

**Research gate:** data integrity PASS; cycle reduction descriptive only; cold-boot dependence UNCERTAIN; accuracy noninferiority INCONCLUSIVE; board-wide timing signoff BLOCKED.
# Additional review artifacts (2026-11-21)

- `PRIOR_ART_COMPARISON.md` and `NOVELTY_VERDICT_JA.md`: targeted primary-source review; early exit, budget-adaptive execution, entropy-based FPGA early exit, and FPGA dynamic inference are prior art.
- `PARETO_INTERPRETATION_JA.md`, `analyze_pareto_frontier.py`, and `pareto_final_run1/`: descriptive secondary Pareto analysis recomputed from the saved diagnostic CSVs. `pareto_final_run2/` is the deterministic duplicate-output check.
- `CYCLE_OFFSET_AUDIT.md`: exact +5-cycle pairwise observation and unresolved causal attribution.
- `SOURCE_RECOVERY_RESULT.md`: the exact 146th RTL source was not recovered; no substitute was created.
- `CLAIM_EVIDENCE_MATRIX.csv` and `CRITICAL_REVIEW_JA.md`: claim limits and reviewer-facing open issues.
- `PAPER_REVIEW_STATUS_20261121_JA.md` and `PAPER_REVIEW_RUN_RECORD_20261121_JA.md`: current disposition and command record.
- `pareto_final_run1/` and `pareto_final_run2/` are the recorded independent deterministic runs; `pareto_final_run3/` is the final repeat. Intermediate `pareto_run1/` and `pareto_run2/` directories are preserved but superseded because their figure annotations were incomplete.
- `generated_final_20261121_run1/` is a fresh full primary-data reanalysis (24,840 rows, 13/13 schedules, 7,200 old/new build pairs); outputs are LF-normalized and byte-identical to `generated_run1/`.
- `SHA256SUMS_PAPER_REVIEW_20261121.txt`: dated manifest for this review package; the historical `SHA256SUMS_PAPER_REVIEW.txt` is not overwritten.

The Pareto script uses only the Python standard library. It reads immutable saved CSVs and refuses to overwrite an existing output directory. See the run record for tool versions and verification.
