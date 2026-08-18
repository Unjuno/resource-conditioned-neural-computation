# Real-Time NN experiment index

This index separates the main physical-computation chain from secondary router/topology diagnostics. The research target is not router accuracy; it is a neural network whose runtime-admitted resource budget changes **physical internal execution** while remaining compatible with finite execution classes and later timing certification.

The preferred external control variable is a normalized continuous budget `b in [0,1]` (0% to 100%). This is an interface/contract coordinate, not a claim of continuously variable machine instructions: an analyzable backend lowers `b` fail-closed to a finite certified maximum-work class.

## Main-line mechanism experiments

| Experiment | Current result | Evidence |
|---|---|---|
| Budget → physical depth | PASS | one fixed NN executes `0/2/4/6/8` optional blocks with ordered work/central latency |
| Structured active width | PASS with backend boundary | C++ slim execution becomes cheaper; PyTorch provides a negative control where MAC reduction alone does not |
| Hard-cap learned selection | PASS | task-loss-only learned selection beats fixed prefix at intermediate work while respecting exact call caps |
| Price-conditioned expert width | PASS as soft mechanism | one fixed sparse NN moves across physical expert widths; price is not a hard timing guarantee |
| Hard cap + price sequence depth | PASS | transformer-like local attention+MLP stack traverses finite physical depths under cap/price |
| Attention/MLP suboperation selection | qualified PASS | separately skippable suboperations work, with seed/capability and oracle-tracking limits retained |
| Autoregressive generation bridge | qualified | hard cap + price changes physical per-token depth; equal-token-NLL frontier exposes a negative boundary |
| Continuous budget + nested ordering | PASS | continuous control maps to finite classes; nested learned ordering loses ~0.06 pp vs free routing and strongly beats prefix at `k=4` |
| Joint all-class training | PASS | reduces sampled-budget high-class regression from ~1.88 pp to ~0.017 pp in the original 3-seed audit |
| Additive logit refinement | **FAIL / no advantage** | 10-seed matched audit: shared and additive are both 9/10 monotonic; additive residual regression is slightly worse |
| Minibatch-order robustness | PASS on supplied task | 3 initialization × 3 batch streams: 9/9 strict monotonic, zero observed adjacent regression |
| Sequence nested non-prefix routing | PASS + negative boundary | 5-seed causal generation: input-dependent routing beats prefix by +14.38 pp token at `k=2` and +11.25 pp at `k=4`; forcing exact work is quality-monotone in only 3/5 seeds |
| Budget-as-cap + preferred compute | PASS | 5/5 token/exact monotonic; full cap improves +2.50 pp token and +9.375 pp exact vs forced `k=6` while saving 0.9875 blocks on average |
| Fine-grained sequence caps | PASS under tradeoff bound | `0..6` finite caps remain 5/5 monotonic; full-cap mean work falls another 0.275 blocks for -0.469 pp token / -1.25 pp exact vs coarse caps |
| Concurrent preferred-compute training | **FAIL / credit-assignment boundary** | 5-seed ST, relaxed-soft, and online-decoupled audits all preserve hard caps but miss the post-trained frontier; best online-decoupled result is -3.44 pp token / -8.13 pp exact at nearly identical mean work |
| Continuous normalized budget + horizon value | PASS + held-out boundary | supplied exhaustive sequence toy: state horizon value reaches 99.53% token / 98.13% exact at 75.63% mean compute; four-fold held-out-prompt cross-fit FAILS at 90.0% / 73.75% |
| **Real independent-sequence generalization** | **PASS** | held-out handwritten-digit row sequences, formal seeds 60--64: adaptive policy 93.56% accuracy at 20.23% mean compute, +43.83 pp capability gain from 0% exit, 5/5 seeds pass, cap violations 0 |
| **Chronological temporal distribution shift** | **FAIL / unresolved** | weekly CO2 future-change task: 69.08% adaptive vs 70.11% full-depth, -1.03 pp, only 3/5 seeds pass; validation/test depth utility shifts over time |
| **Continuous freestanding runtime contract** | **PASS** | exhaustive 65,536 Q0.16 budgets, 16,777,216 budget×preferred cases, and 655,360 deadline-composition cases all pass; invalid preferred class fails closed |
| **Continuous maximum-work manifest** | **PASS** | 0/25/50/75/100% finite ceilings expose max blocks/MACs/LUT calls/workspace and allowed nested block IDs; target timing bounds remain null |
| **Controlled Linux timing as hard bound** | **FAIL / hard timing UNCERTAIN** | affinity-pinned exact binary has class-ordered medians but multi-million-cycle preemption maxima; calibration maxima and even arbitrary 2x/4x factors can be exceeded later |
| Deadline + budget + preferred-class admission | PASS as interface / empirical demo | explicit timing bindings compose correctly, build/manifest mismatch rejects, partial certification never admits uncertified classes; no hard-RT timing claim |

## RTOS / analyzable implementation bridge

The repository contains generated C/C++, freestanding integer/float cores, fixed work manifests, LUT/numeric-range audits, cross-ISA compile/link audits, build-bound execution contracts, and now a continuous Q0.16 budget lowering contract. These establish an analyzable implementation boundary but **not WCET**.

The latest external/runtime contract is:

```text
continuous normalized budget b in [0,1]
    -> largest finite maximum-work class <= b
    -> preferred maximum useful compute
    -> deadline-certified class
    -> min of all three ceilings
    -> nested physical execution
```

The latest real-data generalization model and the existing freestanding core are still separate artifacts; lowering the exact real-sequence model is an integration task, not something inferred from the generic runtime-contract PASS.

## Timing boundary

Ordinary Linux percentile timing was already falsified as a stable hard-admission contract. The new exact-binary cycle audit strengthens that boundary: observed calibration maxima are not stable upper bounds, and multiplying an observed maximum by an arbitrary safety factor is not certification. A defensible target/compiler/build/RTOS-specific WCET or equivalent upper bound remains required.

## Current research-goal status

- **Goal A — physical budget-conditioned computation:** PASS.
- **Goal B — generalizable adaptive computation:** PASS on independent held-out real sequence samples; chronological temporal nonstationarity remains unresolved.
- **Goal C — hard-real-time RTNN:** interface/max-work/deadline composition PASS, but exact real-data-model lowering is still an integration item and hard target timing certification is **UNCERTAIN**.

## Next falsification priorities

1. Run the finite-class system on a **concrete time-predictable target or defensible WCET/static timing analyzer**; do not substitute more Linux percentile/max timing.
2. Lower the exact held-out-real-sequence model/policy into the freestanding boundary and cross-check predictions, exit decisions, and work classes against Python.
3. Treat chronological/nonstationary temporal generalization as a separate research problem: train/validation/test depth utility drift must be modeled or bounded rather than hidden inside the independent-sample PASS.
4. Once a defensible target timing table exists for the same deployed model/build, run the final RTOS deadline/on-time-correct experiment.
