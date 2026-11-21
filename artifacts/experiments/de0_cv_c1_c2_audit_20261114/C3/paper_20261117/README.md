# C3 v2 exact-artifact paper evidence package (2026-11-17)

This is a separate **offline paper-audit snapshot** derived from preserved experimental evidence. It does not contain a new JTAG/Quartus/FPGA measurement and does not alter frozen models, inputs, schedules, or historical outputs.

## Outputs

- [English manuscript draft](MANUSCRIPT_DRAFT_EN.md) — empirical case study, limitations and primary literature.
- [Japanese evidence and next-gates report](RESEARCH_DECISION_JA.md).
- [Independent primary analyzer](reanalyze_c3v2_primary.py), [11 primary tests](test_reanalyze_c3v2_primary.py).
- [Input-level Pareto v2 output integrity tests](test_pareto_frontier_v2_outputs.py).
- [Independent frozen diagnostic budget analyzer](analyze_budget_diagnostics.py), [4 diagnostic tests](test_budget_diagnostics.py); 17,640 diagnostic rows, 21 budget classes each for adaptive and capped, seven fixed classes.
- [Input-level Pareto v2 analyzer](analyze_pareto_frontier_v2.py) and its [Japanese interpretation](PARETO_INTERPRETATION_JA.md); outputs include 17,640 input-condition rows, 7,560 fixed2 pairs, and budget nonmonotonicity diagnostics.
- [Secondary diagnostic budget table](diagnostic_run1/budget_summary.csv), [budget-cycle figure](diagnostic_run1/figure_03_budget_vs_cycles.svg), [diagnostic analysis JSON](diagnostic_run1/analysis.json), [SHA manifest](diagnostic_run1/SHA256SUMS.txt).
- [Publication-readiness audit](PUBLICATION_READINESS_AUDIT_JA.md), [review execution record](REVIEW_RUN_RECORD_JA.md).
- [Current review SHA manifest](SHA256SUMS_PAPER_REVIEW.txt), which supersedes the archived original SHA256SUMS_PAPER.txt after the reviewer amendments.
- [Pinned Ibex/project source-hash checker](audit_native_source_portability.py), its [historical 145/146 result](NATIVE_SOURCE_PORTABILITY_AUDIT.json), and the original [source reproducibility gap](SOURCE_REPRO_GAP_JA.md). The newer mapped recovery result is described below; the historical audit remains unchanged.
- [2026-11-22 source recovery addendum](SOURCE_RECOVERY_ADDENDUM_20261122_JA.md): the exact 146-entry native source graph is now hash-verified using five archived project-source byte variants and the pinned Ibex checkout; native Verilator regressions pass. This supersedes the older 145/146 result only for the explicit recovered source map. It does not prove clean-checkout availability, Quartus/SOF identity, or hardware timing signoff.
- [Clean-clone regression preparation script](prepare_native_regression.py): validates the frozen source graph and prepares a fresh native Verilator run from a repository checkout plus the pinned external Ibex tree. It refuses to overwrite an existing output directory; a clean-clone run record is maintained separately.
- [Latest status (2026-11-22)](PAPER_REVIEW_STATUS_20261122_JA.md) and [source recovery evidence SHA manifest](SHA256SUMS_SOURCE_RECOVERY_20261122.txt).
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
- `PREPUBLICATION_CHECKLIST_JA.md` and `FINAL_REVIEW_ADDENDUM_20261121_V2_JA.md`: limited technical-review status, remaining author/editor checks, and this continuation's run record.
- `pareto_final_run1/`–`pareto_final_run3/` are the v1 deterministic Pareto runs. `analyze_pareto_frontier_v2.py` adds input-level condition records, fixed2 pairing, and budget nonmonotonicity; final identical outputs are in `pareto_input_audit_run3/` and `run4/`. `run1/2` are retained intermediate outputs from before the slow-case-by-exit summary was added.
- `generated_final_20261121_run1/` is a fresh full primary-data reanalysis (24,840 rows, 13/13 schedules, 7,200 old/new build pairs); outputs are LF-normalized and byte-identical to `generated_run1/`.
- `SHA256SUMS_PAPER_REVIEW_20261121.txt`: dated manifest for this review package; the historical `SHA256SUMS_PAPER_REVIEW.txt` is not overwritten.
- `SHA256SUMS_PAPER_REVIEW_20261121_V2.txt`: manifest for the subsequent input-level Pareto and provenance additions; earlier manifests remain unchanged.

The Pareto scripts use only the Python standard library. They read immutable saved CSVs and refuse to overwrite an existing output directory. Current review disposition: **REVIEW_READY_LIMITED** for technical peer review only; this is not a publication/submission approval. The dated 2026-11-22 status supersedes the 2026-11-21 source-graph summary while preserving the earlier logs. See the checklist and addenda for remaining human review and exact boundaries.
