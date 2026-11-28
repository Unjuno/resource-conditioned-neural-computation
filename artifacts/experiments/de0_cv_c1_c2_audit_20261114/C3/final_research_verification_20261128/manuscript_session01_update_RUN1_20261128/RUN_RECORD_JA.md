# English manuscript session-01 update — 2026-11-28

## Scope and preservation

Created `MANUSCRIPT_EN_DRAFT_20261128C.md` from the pre-session-01 version B, preserving B unchanged. Version C reports session 01 as a single-session empirical observation and explicitly leaves sessions 02/03, cold-boot verification, population inference, and formal board timing unresolved.

## Data and edits

* Added session 01 identity and measured results: 3,813 paired images; 7,626/7,626 oracle-consistent requests; fixed2/adaptive teacher-label correctness 3,482/3,813 and 3,485/3,813; mean cycles 943,905.78 and 759,704.67; paired mean saving 19.515%; input-bootstrap interval 18.106%–20.871%; adaptive slower on 929 inputs.
* Recorded the session-only paired accuracy lower bound −0.639 pp against the −1 pp numerical margin, without treating it as population noninferiority.
* Separated the new build/session from the historical C3 v2 campaign; retained `EMPIRICAL_ONLY` and all data-exposure, writer-cluster, preregistration, cold-boot, and timing caveats.
* Updated `FINAL_RESEARCH_STATUS_JA.md` to link this revision. No prior manuscript or experimental record was overwritten.

## Verification

* Recomputed request count, paired input count, teacher-label correct counts, mean/median cycles, and adaptive-slower count directly from session 01 `physical_results.csv`. Values match `analysis_single/analysis.json` and the manuscript.
* Checked 12 backticked internal file references in version C: 12 resolved, 0 missing.
* Searched version C for stale pre-session-01 `primary NOT_RUN`/unrun wording: none found.
* This draft update does not validate physical acquisition beyond the separately preserved raw-log audit, and it is not a peer-reviewed or submission-ready paper.
