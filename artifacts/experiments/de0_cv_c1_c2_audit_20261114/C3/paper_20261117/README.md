# C3 v2 exact-artifact paper evidence package (2026-11-17)

This is a separate **offline paper-audit snapshot** derived from preserved experimental evidence. It does not contain a new JTAG/Quartus/FPGA measurement and does not alter frozen models, inputs, schedules, or historical outputs.

## Outputs

- [English manuscript draft](MANUSCRIPT_DRAFT_EN.md) — empirical case study, limitations and primary literature.
- [Japanese evidence and next-gates report](RESEARCH_DECISION_JA.md).
- [Independent stdlib-only analyzer](reanalyze_c3v2_primary.py), [11 focused tests](test_reanalyze_c3v2_primary.py).
- [Machine-readable analysis](generated_run1/analysis.json), [360-row input-level table](generated_run1/input_level.csv), [10 schedule summary](generated_run1/primary_sessions.csv).
- [Paired saving figure](generated_run1/figure_01_paired_cycle_saving.svg), [executed-exit figure](generated_run1/figure_02_exit_cycles.svg).
- [Output SHA manifest](generated_run1/SHA256SUMS.txt).

## Reproduce from repository root

```bash
python3 -m unittest discover -s artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/paper_20261117 -p test_reanalyze_c3v2_primary.py -v
python3 artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/paper_20261117/reanalyze_c3v2_primary.py --out-dir /tmp/rtnn-c3v2-paper-independent-new
```

Requirements: Python 3.10+ standard library; published repository checkout containing original C3 archived physical primary CSV files and the C2J2 historical primary CSVs. No device, administrator rights, statistics service or network access is needed after checkout. The analyzer refuses to overwrite its destination.

For a reproducibility comparison, compute SHA-256 hashes of all generated outputs against `generated_run1/SHA256SUMS.txt`. An independent second run produced byte-identical outputs and matching SHA manifest.

## Claim boundaries

The input bootstrap (5000 repeats, seed 63) resamples **360 distinct input IDs**, not the ten schedules as independent experimental units. All ten schedule repetitions showed identical cycle deltas for every input/mode. Independent cold boots were *not* verified. No formal board-level JTAG timing signoff, calibrated latency, WCET or one-point accuracy noninferiority is claimed. The observed five-cycle shift from C2J2 to C3 v2 is an association across two specific builds and requires compiler/instrumentation analysis for causal attribution.

The source CSVs remain in their original locations:
- `../evidence/PHYSICAL_C3_V2_20261115/FROZEN_CAMPAIGN/C3V2_PRIMARYnn_FULL720_RUN1_20261115/results/c2_jtag_results.csv`
- `../campaign/results/C3_PRIMARYnn_FULL720_RUN1_20261114/{c2_jtag_results.csv|merged/c2_jtag_results.csv}`

**Research gate:** data integrity PASS; cycle reduction descriptive only; cold-boot dependence UNCERTAIN; accuracy noninferiority INCONCLUSIVE; board-wide timing signoff BLOCKED.
