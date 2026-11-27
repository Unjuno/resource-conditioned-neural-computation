# Literature audit run record

Date: 2026-11-28 (Asia/Tokyo)
Repository branch/HEAD at start: `codex/external-validation-20261122` / `461c8b7393bec299736ebee28f82c1f1fdbaa7e2`.

Actions: checked publisher/conference/institutional/dataset-provider pages for references [1]-[3], [5]-[8], [11]-[12] in the integrated manuscript. Confirmed the scope distinction that ref. [7] concerns entropy-driven video frame processing-rate adaptation, not per-image early exit. The draft now labels it system-level/frame-processing context. UCI reports writer-disjoint train and test pools (30 versus 13 writers), but no row-level writer attribution for the training CSV; `WRITER_CLUSTER_UNKNOWN` remains.

Commands:

- `py -3.11 -B <C3>/verify_claim_evidence_matrix.py` — PASS, 11/11 claims resolve to repository files.
- `py -3.11 -B <C3>/test_verify_claim_evidence_matrix.py -v` — PASS, 5/5 tests.
- `git diff --check` — PASS.

No dataset, model, SOF, ELF, frozen schedule, or physical measurement was changed. The untracked `physical_pilot_RUN2_preparation/` directory was not modified. No JTAG or board operation occurred.

Changed manuscript SHA-256: `441d57cfa679525e847779c1e677ca128e6faf5bcff6878c0e67d2afa14e9356`.
Bibliography scope audit SHA-256: `585915f859d699a724a2763bca2da0d5b96951c4678f6d342542cc13a45ab887`.

Sources and claim-by-claim notes: `../BIBLIOGRAPHY_SCOPE_AUDIT_20261128.md`.
