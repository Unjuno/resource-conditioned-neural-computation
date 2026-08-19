# Resource-Conditioned Neural Computation

A falsification-oriented research prototype toward a **Real-Time Neural Network (RTNN)**: one fixed neural parameter set whose **physically executed internal computation changes under a runtime-admitted resource/deadline contract**.

The research target is not router accuracy. It is the complete system chain:

```text
remaining deadline / target state
    -> normalized admitted budget b in [0,1]
    -> finite maximum-work class
    -> same NN parameters
    -> preferred useful compute p(x,s)
    -> effective execution e = min(b,p)
    -> physically executed neural work
    -> target/build-specific timing bound
    -> deadline admission
```

The public budget is continuous (`b ∈ [0,1]`), but the analyzable backend lowers it fail-closed to finite physical classes. A budget is a **maximum permission**, not a requirement to consume all available compute.

## Current evidence snapshot

The current main line has progressed from mechanism toys to a same-model real-data/Q15/freestanding/RTL/formal chain.

### Goal A — physical budget-conditioned computation: PASS

Across multiple experiments, one fixed NN physically changes optional depth, structured width, expert count, or block execution under resource conditions. Hard hooks verify that inactive work is not executed.

### Goal B — held-out adaptive computation: PASS with a temporal-shift boundary

On independent held-out handwritten-digit row sequences, formal seeds 60--64 reach:

- **93.56%** adaptive test accuracy;
- **20.23%** mean physical compute;
- **5/5** seeds passing the preregistered boundary;
- **0** cap/count violations.

A separate chronological weekly-CO2 experiment remains a negative result: later-time depth utility shifts relative to validation. Temporal/nonstationary robustness is not established.

### Goal C — software/formal integration substantially closed; physical target remains

Current same-model chain:

```text
held-out real-sequence model
    -> Q15 fixed-iteration model/policy
    -> freestanding integer C
    -> continuous b in [0,1]
    -> seven finite maximum-work classes
    -> budget/deadline ceiling + preferred stopping
    -> maximum-work manifest
    -> pinned Ibex RTL timing binding
    -> exact-RV32 custom noninterference audit
    -> independent BINSEC fixed-class control-flow audit
    -> pinned Simple-System deterministic LUT-memory timing audit
    -> CBMC finite runtime-contract proof
    -> CBMC proof of mechanically extracted deployed control
    -> deadline admission interface
```

This is strong research-prototype evidence. It is **not yet an FPGA/ASIC/silicon production WCET certificate**.

## Key current results

### Same-model Q15 / freestanding preservation

Five-seed Q15 reference evidence:

- finite-exit mismatch versus float: **0 / 12,600**;
- preferred-exit mismatch versus float: **1 / 1,800**.

Representative seed 63 integer C:

- exit-prediction mismatch: **0 / 2,520**;
- preferred-exit mismatch: **0 / 360**;
- caller-owned workspace: **4,608 bytes**.

The audited fixed-class neural numeric path removes unresolved arithmetic helpers, floating-point operations, and hardware DIV/REM.

### Pinned Ibex exact-build RTL timing

For the exact frozen RV32 artifact on pinned upstream Ibex commit `7b5df75a041affe56e8c235260f98a09b3319008`, all seven fixed classes were run on three held-out inputs with preferred exits 1, 3, and 5.

- fixed-class prediction mismatches: **0 / 21**;
- input-to-input cycle range inside every fixed class: **0**.

Measured fixed-class cycles:

| normalized class | cycles |
|---:|---:|
| 0% | 29,620 |
| 16.7% | 615,569 |
| 33.3% | 1,201,521 |
| 50% | 1,787,473 |
| 66.7% | 2,373,425 |
| 83.3% | 2,959,377 |
| 100% | 2,959,381 |

These are **exact-build RTL measurements**, not a universal timing formula.

### Compiled control-flow evidence

The exact RTL-tested fixed-class ELF has zero neural-input-dependent conditional branches or indirect-control targets according to a custom RV32 taint audit.

Independent pinned BINSEC analysis then completes all seven fixed classes as `secure`:

- control-flow checks: **933,653 / 933,653**;
- pending paths: **0**;
- leak sites: **0**;
- unrolled instructions explored: **9,176,039**.

The adaptive path intentionally contains neural-input-dependent early-stop control; the fixed-class claim is not applied to that branch.

### Target-specific LUT-memory timing

Four input-dependent load-address sites remain in exp/GELU LUT interpolation. For the pinned one-host Ibex Simple System, the repository now checks the actual memory integration:

- both LUTs are wholly inside the 1 MiB RAM window;
- all **12,290** legal LUT word addresses decode uniquely to RAM;
- all four sites remain aligned RV32 `LW` instructions;
- Yosys synthesis shows `a_rvalid_o` is one request-register stage with **zero address fan-in**.

Thus varying legal LUT addresses change data but not response latency in this exact Simple-System memory model. This result does **not** transfer automatically to cache, SDRAM, arbitration, another RAM, or FPGA memory.

### CBMC finite/deployed control proofs

CBMC 6.10.0 proves the finite runtime contract over complete represented integer domains, including:

- Q0.16 continuous-budget lowering;
- actual deadline admission;
- partial-certification fail-closed behavior;
- effective execution ceilings;
- exp/GELU LUT index bounds.

A second proof mechanically extracts the deployed bodies of `rtnn_fixed_budget_ceiling_q16()`, `rtnn_fixed_infer_budget()`, and `rtnn_fixed_certify_class()`. With entropy abstracted nondeterministically, every possible early-stop outcome is covered and physical optional-block calls never exceed the effective cap.

### Durable certification artifact

The exact package used by the Ibex timing/binary/memory evidence is frozen under:

`artifacts/certification/ibex_simple_system/`

Identity:

- frozen ZIP SHA-256: `9150b0763e5d7b7c305441befdb4161ccf95612edd924b525f8388e06d9a86b0`;
- ELF SHA-256: `234a7f46cf227a11f5d97f3c778cbb0c4ed4f7067f8994bcca86c4b08ff4e742`;
- BIN SHA-256: `266ecb70c723b2164f6fe9039f27d4cb49c4d7271d4aca0cf69f2692cdfdf7a1`.

CI rechecks the frozen package and derives the board-free preflight reference from it. The current formal memory workflow no longer relies on the retention lifetime of the original Actions artifact.

## Next physical stage — DE0-CV

**DE0-CV has not yet been tested.** Hardware work is intentionally deferred.

The preregistered next physical experiment is:

> Run the **same seed-63 Q15/freestanding seven-class RTNN contract** on **DE0-CV**, initially with an **Ibex softcore + controlled on-chip RAM + fixed clock**, derive a **new FPGA-specific timing table**, and then test deadline admission.

The Simple-System cycle table is not copied to the FPGA. The DE0-CV build must get its own processor/memory/configuration identity, static timing result, cycle/time binding, and build/bitstream identity.

Board-free vectors are already frozen in:

`artifacts/certification/de0_cv_preflight_vectors.json`

Detailed plan:

[`notes/realtime_nn_de0_cv_next_stage.md`](notes/realtime_nn_de0_cv_next_stage.md)

## Important negative results retained

The repository intentionally keeps falsifications rather than rewriting history:

- ordinary Linux P95/P99 and observed-max × arbitrary margin are not hard WCET evidence;
- the old arithmetic `RTNN-IBEX-DIT-v1` cycle formula is falsified by actual Ibex RTL;
- a training seed is not a bitwise certification identity;
- generic BINSEC full relational-memory analysis of a LUT-heavy class exceeds the supplied runner resources;
- nominal MAC reduction does not guarantee latency reduction on every backend;
- forced extra compute can reduce quality;
- concurrent preferred-compute training did not match the stable post-trained frontier;
- held-out horizon-value prediction failed on the toy cross-fit audit;
- chronological temporal distribution shift remains unresolved.

## Repository map

- [`REALTIME_NN_DIRECTION.md`](REALTIME_NN_DIRECTION.md) — current research direction and evidence hierarchy.
- [`CLAIMS_AND_LIMITS.md`](CLAIMS_AND_LIMITS.md) — strongest supported claims and explicit nonclaims.
- [`EXPERIMENT_INDEX.md`](EXPERIMENT_INDEX.md) — experiment-by-experiment result index, including negative results.
- [`EXPERIMENT_PLAN_REALTIME_NN.md`](EXPERIMENT_PLAN_REALTIME_NN.md) — current plan from software/formal closure to physical target validation.
- [`notes/`](notes/) — detailed experiment notes.
- [`results/`](results/) — machine-readable result records.
- [`experiments/`](experiments/) — experiment/audit code.
- [`artifacts/certification/`](artifacts/certification/) — frozen certification identity and board-free reference material.

## Explicit nonclaims

Current work does not establish:

- a universal Ibex WCET theorem;
- generic constant-time behavior for arbitrary memory systems;
- DE0-CV timing results;
- an FPGA/ASIC/silicon production WCET guarantee;
- cache/SDRAM/DMA/multi-master/interrupt timing portability;
- compiler/whole-processor equivalence from source-level CBMC alone;
- temporal distribution-shift robustness;
- LLM-scale real-time generalization.

## Direction rule

New main-line work should answer:

> Does this move the **same neural model** closer to controllable physical execution under `b ∈ [0,1]`, a finite maximum-work envelope, and a defensible deadline guarantee?

If not, it is secondary diagnostics.
