# Session 01 figure regeneration record

Classification: `EMPIRICAL_ONLY_SINGLE_SESSION`

Command:

```powershell
py -3.11 -B artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/final_research_verification_20261128/plot_primary_session01.py
```

The script first ran `audit_primary.audit_run` against the saved session 01 physical run, then paired 3,813 fixed2/adaptive result rows by input ID. It emitted two SVG figures and `paired_values.csv`. The CSV contains one row per distinct input ID and carries the teacher label, each mode's measured mcycle delta, adaptive executed exit, and per-mode correctness indicators.

Input evidence is under `artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/external_validation_20261122/build/physical_primary_3session_20261128/session_01/`: `run/physical_results.csv`, `run/raw_jtag.log`, `run/cases.csv`, `run/run_status.json`, and `analysis_single/analysis.json`. The figure metadata records the CSV and analysis SHA-256 plus the audit result's raw-log and case hashes.

The plotted measurement interval is the 64-bit Ibex mcycle start/end interval around inference; host/JTAG scan and wait time is excluded. The scatter is colored by adaptive executed exit. The second figure shows the paired adaptive-minus-fixed2 cycle delta grouped by that exit. The 95% interval annotation on the scatter is the existing input-level bootstrap for session 01; it does not estimate writer-cluster or between-session variation.

Validation: both SVG files parse as XML; the source CSV has 3,813 complete pairs; metadata classification and unresolved cold-boot status match the campaign; generated-output hashes match `SHA256SUMS.txt`. No board or JTAG operation was performed.

These files do not establish independent cold boots, population generalization, calibrated elapsed time, formal timing sign-off, or WCET.
