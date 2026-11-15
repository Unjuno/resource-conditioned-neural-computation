# C3 v2 frozen campaign physical acquisition — 2026-11-15

- Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`
- Branch/HEAD at start: `codex/stage-c3-jtag-pilot-20261114` / `b332ba02ab992227140998a1d67513c690ae17cf` (no commit or push).
- Board: DE0-CV / Cyclone V `5CEBA4F23C7N`; JTAG: USB-Blaster USB-0; Quartus Prime Lite 25.1std.0 Build 1129.
- Build ID: `43334531`; model ID `52544e4e`; SOF SHA-256 `85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d`.
- Frozen campaign SHA-256: `d6c98f59c0c0afe32d0877c01c8411fba8bf3e2a5c8058c5a85371f7f648a8dc`.
- Result: all 13 schedules and 24,840/24,840 rows passed per-run PowerShell and independent Python evidence audits; the aggregate script independently checked expected counts, identities, SHA manifests, and data file counts.
- Runs: diagnostic fixed 2,520; diagnostic adaptive 7,560; diagnostic capped 7,560; primary_01–primary_10 720 each (7,200 total).
- Reset evidence: operator attested one KEY0 press/release before the 20-request replay. The replay passed 20/20 and its hashed gate was reused for campaign eligibility. No per-schedule physical reset telemetry was captured.
- Power: one continuous board power session; cold boot not confirmed. Treat all values as `EMPIRICAL_ONLY`; do not infer cross-boot variation, speed superiority, accuracy non-inferiority, WCET, hard deadline, or calibrated absolute time from this run.
- No SOF reconfiguration, Flash/CFM write, UART, electrical setting, wiring, or clock change was made during campaign acquisition. Historical C2J2 data are not included.
- Aggregate validator command (from repo root): `python artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/source/summarize_c3v2_campaign_20261115.py --campaign-dir artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/evidence/PHYSICAL_C3_V2_20261115/FROZEN_CAMPAIGN --output-json artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/evidence/PHYSICAL_C3_V2_20261115/FROZEN_CAMPAIGN/C3V2_CAMPAIGN_AGGREGATE_AUDIT_20261115.json`
- Validation output: `PASS schedules=13/13 rows=24840/24840 errors=0`.
- Aggregate audit: `C3V2_CAMPAIGN_AGGREGATE_AUDIT_20261115.json`. Each run directory contains raw JTAG log, CSV/JSON, cases, binding, gate, protocol log, audit reports, run metadata/record, and its own SHA256SUMS.
- Gate B-SIGNOFF remains BLOCKED because external JTAG timing is unresolved; this campaign does not alter that state.
