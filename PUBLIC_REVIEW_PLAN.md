# Public review plan

## Purpose

Use GitHub as a short falsification and reproduction window before any arXiv submission. The review target is the **current RTNN evidence chain**, not the older router/resource-price prototypes in isolation.

## Review window

- Public repository release: 2026-08-17.
- Initial review window: 2026-08-17 through 2026-08-31 (JST).
- Earliest arXiv decision point: 2026-08-31, provided no unresolved core objection remains.

The repository may continue to fix documentation, reproducibility, or certification-identity problems during the window. Do not add unrelated scale experiments merely to improve presentation.

## Current claim under review

The strongest current research-prototype statement is:

> One fixed neural-network parameter set can accept a normalized runtime compute budget `b ∈ [0,1]`, lower that interface fail-closed to finite maximum-work execution classes, physically skip inactive computation, and preserve that contract through a same-model Q15/freestanding implementation. For one exact frozen RV32 artifact on one pinned Ibex Simple-System configuration, the repository provides an exact-build measured RTL cycle binding, compiled control-flow evidence, a target-specific deterministic LUT-memory timing argument, and CBMC proofs of the finite/deployed source control contract.

The claim remains target-scoped. It is **not** a production FPGA/ASIC/silicon WCET certificate, and DE0-CV timing has not yet been measured.

## Evidence that should block or delay arXiv submission

Any of the following should be treated as a core objection until resolved:

- a materially identical prior method establishing the same narrow RTNN mechanism/system claim;
- a clean reproduction failure in the physical-skip, hard-cap, same-model lowering, or finite-class behavior that cannot be explained by an explicitly documented environment difference;
- data leakage or evaluation contamination affecting the held-out real-sequence result;
- a mismatch between the repository-frozen certification artifact and the ELF/BIN identities used by the Ibex/BINSEC/memory evidence;
- evidence that a fixed class can execute optional work beyond its admitted ceiling;
- evidence that neural input changes fixed-class compiled control flow in the exact certified binary contrary to the reported audit;
- evidence that legal exp/GELU LUT addresses can select a different response-latency path in the pinned Simple-System memory configuration;
- a flaw in the reported pinned Ibex cycle binding that invalidates the exact-build timing table;
- a flaw in the CBMC harness/extraction that means the deployed budget/admission/control bodies are not the bodies actually proved;
- an undocumented portability assumption that transfers Simple-System timing to another target, memory, compiler artifact, or FPGA build;
- a stronger matched baseline or interpretation showing that the claimed adaptive quality/work result is an artifact of evaluation or accounting rather than actual physically skipped computation.

## Evidence that should not automatically block submission

The following are limitations or downstream work, not automatic falsifications of the current scoped claim:

- lack of LLM-scale experiments;
- lack of production silicon/FPGA WCET certification;
- DE0-CV not yet being executed, provided no FPGA timing claim is made;
- generic BINSEC relational-memory analysis exceeding the supplied runner resources, because the accepted memory claim is target-specific and independently scoped;
- chronological/nonstationary temporal generalization remaining unresolved, provided that negative result remains explicit;
- different absolute timing on another target, because timing must be rebound to that target rather than assumed portable;
- requests for energy/Joule measurements or broader embedded benchmarks.

## Highest-value review questions

Please challenge or reproduce the chain at its actual boundaries:

1. Does continuous `b ∈ [0,1]` lower fail-closed to the intended finite maximum-work class?
2. Does the same NN physically execute no optional work beyond the effective budget/deadline/preference ceiling?
3. Is the Q15/freestanding implementation genuinely the same deployed model contract rather than a separately tuned surrogate?
4. Do the frozen artifact hashes bind the exact ELF/BIN used by the compiled and RTL evidence?
5. Is fixed-class input-dependent control flow absent in the exact RV32 artifact as reported?
6. Are the remaining input-dependent LUT addresses bounded to deterministic, address-independent response timing in the pinned Simple-System RAM integration?
7. Do the CBMC proofs cover the actual extracted deployed control bodies and all represented budget/deadline/stop outcomes?
8. Are the scope boundaries clear enough that Linux, Simple-System RTL, and future DE0-CV timing cannot be conflated?

## Decision after the review window

If no unresolved core objection remains after 2026-08-31 (JST), freeze the exact submission revision/tag and use that revision as the reproducibility reference for the technical note. If a core objection remains, delay submission and preserve the failure as part of the evidence history rather than weakening the audit trail.
