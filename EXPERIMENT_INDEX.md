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
| **Same-model real-data → freestanding C** | **PASS** | the exact real-sequence models for seeds 60--64 are exported to one generic C core: 12,600 exit predictions and 1,800 preferred-exit decisions have 0 Python/C mismatches; all five freestanding objects have 0 unresolved symbols |
| **Same-model continuous budget execution** | **PASS** | representative seed 63: 7,560 test-sample × 21-budget cases have 0 prediction, executed-exit, or cap mismatches; inference is single-pass and never executes beyond the admitted ceiling |
| **Chronological temporal distribution shift** | **FAIL / unresolved** | weekly CO2 future-change task: 69.08% adaptive vs 70.11% full-depth, -1.03 pp, only 3/5 seeds pass; validation/test depth utility shifts over time |
| **Same-model maximum-work manifest** | **PASS** | seed-63 export exposes seven normalized classes, capability and deployed-policy ceilings, maximum MAC/LUT/rsqrt/head counts, 4,608-byte workspace, build/manifest identity, and null physical-target timing bounds |
| **Same-model deadline + budget + stopping contract** | **PASS as interface/property test** | 52,920 held-out sample × budget × deadline cases: 0 admitted-class, executed-exit, or prediction mismatches; partial certification and wrong build/manifest fail closed |
| **Controlled Linux timing as hard bound** | **FAIL** | same seed-63 adaptive binary, CPU affinity + RDTSCP: held-out observed maxima reach 12.50× the first calibration maximum; even `max×8` is exceeded for multiple classes |
| **Q15 fixed-iteration same-model lowering** | **PASS** | seeds 60--64: 0/12,600 exit-prediction mismatches and 1/1,800 preferred-exit mismatches vs float; seed 63 integer C has 0/2,520 exit and 0/360 preferred mismatches; final Cortex-M4 object has no unresolved, floating-point, or divide instructions |
| **Arithmetic RV32 timing model** | **FAIL / falsified by RTL** | the former `RTNN-IBEX-DIT-v1` instruction-category cycle formula underestimates actual pinned Ibex RTL in every full-work certification class; it is retained only as a negative result and must not drive admission |
| **Pinned Ibex RTL timing binding** | **PASS pending final same-build repeat** | pinned official Ibex Simple System: all 7 fixed classes × 3 held-out inputs have prediction mismatch 0 and exactly identical cycles per class; 21 admission+adaptive cases have prediction/execution mismatch 0 and unsafe admission 0; strengthening the harness shifted all fixed-class counts by exactly +1 cycle, proving build-specific timing identity |
| **Empirical RTOS-style same-model demo** | qualified / diagnostic | empirical P99 deadline admission changes physical compute and on-time-correct trade-offs; timing remains diagnostic rather than hard evidence |

## RTOS / analyzable implementation bridge

The same-model chain now reaches pinned processor RTL:

```text
held-out real-data model
    -> Q15 fixed weights / policy / integer LUTs
    -> same-model freestanding fixed-iteration C
    -> continuous b in [0,1]
    -> budget/deadline ceiling
    -> entropy early stopping
    -> nested physical execution
    -> maximum-work manifest
    -> exact-build pinned Ibex RTL timing binding
    -> deadline admission interface
```

The representative integer core has no unresolved arithmetic helpers, floating-point instructions, or hardware DIV/REM in the neural numeric path. Timing certification identity is separated from training reproducibility: seeds/recipes reproduce experiments statistically, while timing evidence binds the exact frozen Q15 artifact and exact machine image to the pinned RTL/toolchain/configuration.

## Timing boundary

Ordinary Linux percentile/max timing remains falsified as a hard-admission contract. The former custom arithmetic processor model is also now falsified by actual pinned Ibex RTL. The stronger route is an exact-build RTL binding on Ibex commit `7b5df75a041affe56e8c235260f98a09b3319008`, `SecureIbex=1`, `RV32MSingleCycle`, no I-cache/branch predictor, and deterministic one-cycle Simple System RAM with zero additional instruction delay.

The strengthened derivation run gives fixed-class cycles 29,620 / 615,569 / 1,201,521 / 1,787,473 / 2,373,425 / 2,959,377 / 2,959,381, with zero cycle range across all three held-out inputs for every class. The admission+adaptive maximum-work binding is 29,843 / 657,454 / 1,285,058 / 1,912,662 / 2,540,266 / 3,167,870 / 3,167,870 cycles.

This is substantially stronger than a custom instruction-count model, but it remains an **RTL-simulation binding for one exact configuration/build**, not an FPGA/ASIC/silicon production WCET theorem.

## Current research-goal status

- **Goal A — physical budget-conditioned computation:** PASS.
- **Goal B — generalizable adaptive computation:** PASS on independent held-out real sequence samples; chronological temporal nonstationarity remains unresolved.
- **Goal C — hard-real-time RTNN:** same-model lowering, fixed-point time-predictable execution, maximum-work contract, continuous budget, deadline admission, and pinned RTL timing validation are now demonstrated. The remaining boundary for a production hard-real-time claim is physical FPGA/ASIC/silicon or another accepted target-specific WCET certification method.

## Next falsification priorities

1. Complete the final same-build repeat of the committed RTL-derived binding and freeze its workflow/model/header/ELF/binary evidence.
2. For a production deployment claim, validate the same exact artifact on FPGA/ASIC/silicon or with an accepted WCET/static-timing methodology; do not generalize the RTL table to other implementations.
3. Extend integer/timing deployment across additional seeds only if cross-seed compiled deployment robustness is required.
4. Treat chronological/nonstationary temporal generalization as a separate research problem.
5. Larger language-model-scale work remains downstream of the target-certification question.
