# Experiment plan: Real-Time Neural Network

## Objective

The research target is a neural network that can be treated as a deadline-aware software component:

```text
remaining deadline / target state
    -> normalized admitted budget b in [0,1]
    -> finite certified maximum-work class
    -> same NN parameters
    -> preferred useful compute p(x,s)
    -> effective compute e = min(b,p)
    -> physical internal execution
    -> target/build-specific timing bound
    -> deadline admission
```

The runtime owns **what work is admissible**. The NN may choose less work inside that safe envelope. Router/gate design is secondary unless it fixes a concrete failure in this chain.

## Current status

### Goal A — budget changes physical neural computation: PASS

One fixed parameter set has been shown to change physically executed depth/width/expert/block work under runtime resource conditions. Inactive work is structurally skipped. The public resource interface is continuous:

\[
b\in[0,1],
\]

while analyzable backends lower it fail-closed to finite maximum-work classes.

### Goal B — generalizable adaptive computation: PASS with a temporal-shift boundary

On independent held-out handwritten-digit row sequences, formal seeds 60--64 reach 93.56% adaptive test accuracy at 20.23% average physical compute with 5/5 passing seeds and zero cap/count violations.

A separate chronological weekly-CO2 experiment is a negative boundary: later-time depth utility shifts relative to validation. Nonstationary temporal robustness remains unresolved.

### Goal C — hard-real-time integration: software/formal + pinned RTL substantially closed; physical target remains

The current same-model chain is:

```text
held-out real-sequence model
    -> Q15 fixed-iteration model/policy
    -> freestanding integer C
    -> continuous b in [0,1]
    -> budget/deadline ceiling
    -> preferred early stopping
    -> nested physical execution
    -> maximum-work manifest
    -> pinned Ibex RTL timing binding
    -> exact RV32 input/control-flow audit
    -> independent BINSEC fixed-class control-flow audit
    -> pinned Simple-System deterministic LUT-memory timing audit
    -> CBMC finite runtime-contract proof
    -> CBMC proof of mechanically extracted deployed control bodies
    -> deadline admission interface
```

This is not yet an FPGA/ASIC/silicon WCET certificate.

## Completed software/formal evidence

### 1. Exact Q15/freestanding preservation

For seeds 60--64, the Q15 reference preserves finite-exit predictions with 0/12,600 mismatches and preferred exits with 1/1,800 mismatches versus float. Representative seed 63 integer C has 0/2,520 exit mismatches and 0/360 preferred-exit mismatches.

The fixed-class neural numeric path removes floating-point operations, unresolved arithmetic helpers, and hardware DIV/REM.

### 2. Continuous budget and deadline contract

The external budget remains normalized and continuous. The backend uses finite classes:

\[
q_j\in\{0,1/6,2/6,3/6,4/6,5/6,1\}.
\]

For any budget \(b\), lowering is fail-closed to the largest class not exceeding the admitted budget. Effective work is bounded by budget, deadline, preferred compute, and deployed policy ceilings.

### 3. Pinned Ibex RTL timing binding

For the exact frozen seed-63 RV32 artifact on pinned upstream Ibex commit `7b5df75a041affe56e8c235260f98a09b3319008`, all seven fixed classes were executed on three held-out inputs. Prediction mismatch is 0 and input-to-input cycle range is 0 in every fixed class.

Fixed-class measured cycles:

| normalized class | cycles |
|---:|---:|
| 0% | 29,620 |
| 16.7% | 615,569 |
| 33.3% | 1,201,521 |
| 50% | 1,787,473 |
| 66.7% | 2,373,425 |
| 83.3% | 2,959,377 |
| 100% | 2,959,381 |

This is an exact-build RTL binding, not a portable timing formula.

### 4. Exact compiled control-flow evidence

A custom exact-RV32 taint interpreter finds zero neural-input-dependent conditional branches or indirect-control targets in every fixed class. Four input-dependent memory-load sites remain and belong to exp/GELU LUT interpolation.

Independent pinned BINSEC analysis then completes all seven fixed classes as `secure`, with 933,653/933,653 control-flow checks passing, pending paths 0, and leak sites 0.

Generic full relational memory analysis for a LUT-heavy class exceeds the supplied runner resources. This remains a negative/resource boundary rather than being relabeled as a proof.

### 5. Target-specific deterministic LUT-memory timing

The remaining four input-indexed load sites are now bound to the pinned one-host Ibex Simple System memory implementation.

- both LUTs are wholly inside the 1 MiB RAM window;
- all 12,290 legal LUT word addresses decode uniquely to RAM;
- all four exact sites remain aligned RV32 `LW` instructions;
- synthesized `ram_2p` response-valid control is one request-register stage;
- no address signal is in the transitive fan-in of `a_rvalid_o`.

Therefore the varying LUT address changes data but not response latency in this exact Simple-System memory model. This does not transfer to another RAM/cache/SDRAM/bus without new evidence.

### 6. CBMC finite and deployed-control proofs

CBMC 6.10.0 proves the finite runtime contract over complete integer domains, including Q0.16 lowering, actual deadline admission, partial-certification fail-closed behavior, effective ceilings, and LUT-index safety.

A second proof mechanically extracts the deployed bodies of:

- `rtnn_fixed_budget_ceiling_q16()`;
- `rtnn_fixed_infer_budget()`;
- `rtnn_fixed_certify_class()`.

With entropy abstracted nondeterministically, every possible stop/continue sequence is covered. Physical `run_block()` calls remain canonical and never exceed the effective cap.

### 7. Durable certification artifact identity

The exact package used by the Ibex timing/binary/memory evidence is frozen under:

`artifacts/certification/ibex_simple_system/`

Identity includes:

- frozen ZIP SHA-256 `9150b0763e5d7b7c305441befdb4161ccf95612edd924b525f8388e06d9a86b0`;
- ELF SHA-256 `234a7f46cf227a11f5d97f3c778cbb0c4ed4f7067f8994bcca86c4b08ff4e742`;
- BIN SHA-256 `266ecb70c723b2164f6fe9039f27d4cb49c4d7271d4aca0cf69f2692cdfdf7a1`.

The memory-proof workflow consumes this repository-frozen package rather than depending on the retention lifetime of the original Actions artifact.

## Current evidence boundary

At this point the highest-value remaining gap is no longer another router experiment, Linux percentile sweep, or the four LUT addresses in the pinned Simple System.

The remaining hard-real-time boundary is chiefly:

1. whole-target/processor physical certification beyond the current exact-build measured RTL evidence;
2. actual FPGA implementation timing and memory mapping;
3. later interference assumptions if interrupts/DMA/multiple masters/external memory are introduced.

A stronger software-only processor-level formal/WCET method may still be useful, but it should target the **whole processor/memory timing model**, not repeat already-closed finite-control properties.

## Next stage — DE0-CV physical validation

Hardware work is intentionally deferred until the board is available. The planned next physical experiment is explicit:

> Run the **same seed-63 Q15/freestanding seven-class RTNN contract** on **DE0-CV**, initially with an **Ibex softcore + controlled on-chip RAM + fixed clock**, derive a **new FPGA-specific timing table**, and then test deadline admission with that table.

Do **not** copy the Simple-System cycle table to DE0-CV.

Detailed preregistration and failure interpretation are in:

`notes/realtime_nn_de0_cv_next_stage.md`

The physical sequence is:

```text
frozen Q15 reference + vectors
    -> exact DE0-CV build identity
    -> fixed-class prediction/work audit
    -> synthesized on-chip-memory timing audit
    -> fixed clock + static timing closure
    -> per-class cycle/time bound
    -> deadline admission
    -> on-time-correct comparison
```

## Work that can still be done before hardware

1. Keep source, binary, timing, and artifact identities synchronized in CI.
2. Prepare frozen board vectors and a machine-readable result schema so board validation is a direct comparison rather than an ad-hoc demo.
3. If pursuing one additional formal layer, evaluate processor-level WCET/formal methods that model the relevant Ibex pipeline/memory timing rather than host Linux timing.
4. Avoid new model/routing experiments unless they repair a demonstrated failure in the RTNN execution/deadline contract.

## Deferred after controlled DE0-CV validation

Only after the controlled physical target is understood:

- interrupt/interference robustness;
- DMA or multiple-master arbitration;
- external memory/cache behavior;
- mixed-criticality integration;
- broader target portability;
- larger neural/LM-scale experiments.

## Direction rule

New main-line work should answer:

> Does this move the **same neural model** closer to controllable physical execution under `b in [0,1]`, a finite maximum-work envelope, and a defensible deadline guarantee?

If not, it is secondary diagnostics.
