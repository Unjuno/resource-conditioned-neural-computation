# Initial public review window

The repository is being reviewed first as a falsification/reproduction package before any arXiv submission.

**Initial public review window: 2026-08-17 through 2026-08-31 (JST).**

## Current review target

The active claim is no longer a router/resource-price result by itself. The current RTNN chain is:

```text
continuous normalized budget b in [0,1]
    -> finite maximum-work class
    -> same neural-network parameters
    -> preferred useful compute
    -> physically skipped/active work
    -> same-model Q15 freestanding C
    -> frozen exact RV32 artifact
    -> pinned Ibex RTL timing binding
    -> compiled control-flow evidence
    -> deterministic Simple-System LUT-memory timing evidence
    -> CBMC finite/deployed control proofs
    -> deadline-admission interface
```

The strongest current result is still **research-prototype and target-scoped**. It is not a production FPGA/ASIC/silicon WCET certificate. DE0-CV physical timing is explicitly planned but **not yet executed**.

## Preferred falsification/reproduction feedback

Please prioritize evidence about:

- whether inactive optional neural work is genuinely physically skipped;
- whether continuous budget lowering and deadline admission fail closed;
- whether physical optional-block calls can ever exceed the effective admitted ceiling;
- whether the Q15/freestanding path preserves the same model contract;
- whether the frozen certification ZIP, ELF, and BIN identities match the artifacts used by the RTL/BINSEC/memory evidence;
- whether fixed-class neural input influences compiled branches or indirect control targets contrary to the reported exact-RV32/BINSEC results;
- whether the four remaining input-dependent exp/GELU LUT load addresses can alter response timing in the pinned one-host Simple-System RAM integration;
- whether the CBMC proofs actually cover the mechanically extracted deployed control bodies and all represented budget/deadline/early-stop outcomes;
- whether any documentation accidentally transfers Linux or Simple-System timing claims to DE0-CV or another target;
- data leakage, calibration leakage, or evaluation/accounting errors affecting the held-out adaptive-computation result;
- materially overlapping prior art or stronger matched interpretations that invalidate the narrow mechanism/system claim.

## Negative boundaries that must remain visible

The following are intentionally retained rather than hidden:

- ordinary Linux P95/P99/observed maxima are not hard timing contracts;
- the former arithmetic Ibex cycle model was falsified by pinned RTL;
- forced extra compute can reduce quality;
- concurrent preferred-compute training did not match the stable post-trained frontier;
- toy held-out horizon-value generalization failed;
- chronological/nonstationary temporal robustness remains unresolved;
- generic full relational-memory analysis in BINSEC exceeded the supplied runner resources for a LUT-heavy class;
- the pinned Simple-System timing argument does not transfer automatically to FPGA/cache/SDRAM/arbitrated memory.

The claim should remain narrow during this period. Documentation and reproducibility fixes are welcome; unrelated scaling experiments should not be added merely to improve presentation.

See `PUBLIC_REVIEW_PLAN.md` for the explicit block/delay criteria and `CLAIMS_AND_LIMITS.md` for the current claim boundary.
