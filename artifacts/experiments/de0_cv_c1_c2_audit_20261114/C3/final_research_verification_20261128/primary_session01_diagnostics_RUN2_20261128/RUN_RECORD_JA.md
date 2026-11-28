# Primary session 01 post-hoc diagnostics — 2026-11-28

## Scope

Added a reproducible descriptive analysis for the saved, independently audited session 01 dataset. The analyzer calls `audit_primary.audit_run` before consuming `physical_results.csv`. It creates no JTAG connection and changes no board state. Output is `../primary_session01_diagnostics_RUN2.json`. The earlier RUN1 summary is retained unchanged; RUN2 adds per-exit cycle deltas and correctness transitions.

## Findings

* Paired correctness: both correct 3,438; fixed2 only correct 44; adaptive only correct 47; both wrong 284. Therefore 91 paired predictions changed correctness, a net +3 adaptive correct outputs against teacher labels.
* Adaptive executed exits: Exit 1: 2,884; Exit 2: 653; Exit 3: 117; Exit 4: 53; Exit 5: 106.
* Exit 1 was faster than fixed2 for all 2,884 inputs. Every adaptive-slower input was in Exit 2–5: 653 + 117 + 53 + 106 = 929.
* Mean adaptive-minus-fixed2 cycle deltas by executed exit: Exit 1 −377,983; Exit 2 +127,563; Exit 3 +633,109; Exit 4 +1,138,655; Exit 5 +1,603,996 cycles (rounded).
* Correct-count differences by teacher label 0–9 (adaptive minus fixed2): 0, +2, +4, 0, +7, −7, +2, +4, −8, −1.
* At Exit 5, 21 cases changed from fixed2-correct to adaptive-wrong and 18 changed from fixed2-wrong to adaptive-correct. Exit-conditioned groups are selected by the stopping policy; they do not establish a causal population effect.

All findings are post-hoc and single-session descriptive. They do not resolve writer dependence, prior data exposure, between-session variability, or the preregistered three-session gates.

## Verification

`py -3.11 -B test_session01_diagnostics.py`: 3/3 PASS (paired transitions, duplicate rejection, incomplete-pair rejection). The first test run exposed that the exact-count guard fired before the more specific incomplete-pair check; validation order was corrected, and the full suite then passed.

The actual-run analyzer independently rechecked the saved run: 7,626 raw request/response pairs, 3,813 primary images, data integrity PASS; Build ID `45585631`; cold boot remains unverified; formal timing remains blocked.
