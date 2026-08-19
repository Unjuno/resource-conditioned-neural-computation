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
| **Conditional RV32 static timing envelope** | **PASS under explicit model assumptions** | branchless/fixed-iteration seed-63 core produces identical dynamic instruction-category counts across four distinct inputs for every class; `RTNN-IBEX-DIT-v1` gives total admission+inference envelopes 22,180 → 2,660,140 cycles and a new 52,920-case deadline audit has zero mismatches/violations |
| **Empirical RTOS-style same-model demo** | qualified / diagnostic | empirical P99 deadline admission changes physical compute and on-time-correct trade-offs; timing remains diagnostic rather than hard evidence |

## RTOS / analyzable implementation bridge

The repository contains generated C/C++, freestanding integer/float cores, fixed work manifests, LUT/numeric-range audits, cross-ISA compile/link audits, build-bound execution contracts, a continuous Q0.16 budget lowering contract, and now a fixed-iteration Q15 implementation intended for static timing analysis.

The same-model chain is now:

```text
held-out real-data model
    -> generated Q15 weights / policy / integer LUTs
    -> same-model freestanding fixed-iteration C
    -> continuous b in [0,1]
    -> budget/deadline ceiling
    -> entropy early stopping
    -> nested physical execution
    -> maximum-work manifest
    -> conditional processor-model timing envelope
    -> deadline admission interface
```

For representative seed 63, the final Cortex-M4 soft-float object has zero unresolved external symbols and no floating-point or hardware-divide instructions. The RV32IM analysis build likewise contains no DIV/REM or floating-point instructions.

## Timing boundary

Ordinary Linux percentile/max timing remains falsified as a stable hard-admission contract. The new integer experiment takes a different route: it removes floating-point and variable-iteration arithmetic, forces data-independent numerical control flow, and constructs a finite class cycle envelope under an **explicit conditional processor/memory model** (`RTNN-IBEX-DIT-v1`). This closes a static-analysis design step, but it is not yet a physical-device WCET certificate.

The remaining hard-real-time timing requirement is now narrower: validate or replace the conditional table using the exact exported integer build on matching Ibex RTL/FPGA/ASIC or another accepted time-predictable/WCET target, with memory, interrupts, DMA, and integration assumptions fixed.

## Current research-goal status

- **Goal A — physical budget-conditioned computation:** PASS.
- **Goal B — generalizable adaptive computation:** PASS on independent held-out real sequence samples; chronological temporal nonstationarity remains unresolved.
- **Goal C — hard-real-time RTNN:** same-model real-data lowering, fixed-point time-predictable implementation, maximum-work contract, continuous budget, deadline admission, and a conditional static cycle envelope all PASS. **Physical-target/RTL WCET validation remains UNCERTAIN.**

## Next falsification priorities

1. Run the exact **Q15 RV32IM build** against a matching Ibex configuration (`DataIndTiming`, single-cycle multiplier, controlled SRAM) in RTL/FPGA/ASIC, or use an accepted WCET analyzer, and test whether every observed/analyzed class stays within the conditional envelope.
2. If the conditional envelope survives, bind target-certified `T_j` values to the exact build and run the final certified deadline/on-time-correct experiment. If it does not, identify which memory/pipeline/integration assumption failed and revise the binding rather than adding empirical Linux margin.
3. Extend the integer C/timing audit beyond representative seed 63 if cross-seed deployment robustness is required; the current five-seed Q15 reference has one preferred-exit mismatch in 1,800 test decisions.
4. Treat chronological/nonstationary temporal generalization as a separate research problem.
5. Larger language-model-scale work remains downstream of physical-target timing validation.
