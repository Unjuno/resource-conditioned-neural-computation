# Joint execution-class training audit

## Why this experiment exists

The continuous-budget nested-ordering audit established **execution monotonicity** (zero set-inclusion violations) but falsified a stronger claim: merely adding nested computation did not guarantee monotone task quality. Under the original one-budget-per-update training schedule, strict non-decreasing accuracy failed in 0/3 seeds and the mean `k=4 -> k=8` accuracy drop was 1.88 percentage points.

This experiment tests whether that regression is primarily a training-coverage problem rather than an inherent cost of nested execution.

## Hypothesis

**H.** Training all eight nested physical execution classes on every optimizer update is sufficient to remove most utility regression without an explicit monotonicity penalty.

**T.** Keep the same eight-expert nested architecture, data, hard top-k execution, optimizer, 800-step training budget, and three seeds. Change only the training schedule: every update evaluates `k=1..8` and minimizes the mean task cross-entropy across all eight classes. No relevance labels and no explicit cross-budget monotonicity penalty are used. Re-run the exact nestedness and hard-cap hook audits.

**D. PASS iff:**

- at least 2/3 seeds are strictly non-decreasing in test accuracy across all eight classes;
- mean maximum adjacent-class regression is at most 0.5 percentage points;
- nested path violations are zero;
- all physical hard-cap hook checks pass;
- mean `k=4` accuracy is at least 98%.

**C.** If utility regression remains large, nested execution needs an architectural or loss-level monotonicity mechanism rather than merely balanced class exposure.

**U.** The result is empirical on a finite synthetic test set. It is not a proof that true expected risk is monotone. Training stochasticity and finite optimization remain the main uncertainty sources.

## Result

Three seeds, 800 steps:

| k | joint-training mean accuracy |
|---:|---:|
| 1 | 68.57% |
| 2 | 80.27% |
| 3 | 82.38% |
| 4 | **100.00%** |
| 5 | **100.00%** |
| 6 | **100.00%** |
| 7 | 99.98% |
| 8 | 99.98% |

Per-seed utility audit:

- seed 0: strict non-decreasing **PASS**, maximum adjacent drop 0;
- seed 1: strict non-decreasing **PASS**, maximum adjacent drop 0;
- seed 2: strict non-decreasing **FAIL**, but the only maximum drop is **0.05 pp**;
- strict seeds: **2/3**;
- mean maximum adjacent drop: **0.0167 pp**;
- mean `k=4 -> k=8` drop: **0.0167 pp**;
- nested set-inclusion violations: **0**;
- physical hard-cap hook audit: **PASS** for all tested cases.

**Decision: PASS under the preregistered thresholds.**

The contrast with the previous sampled-budget training is large: mean `k=4 -> k=8` regression falls from **1.88 pp** to **0.0167 pp**, while `k=4` remains 100% accurate.

## Monotonic-penalty negative control

Before adopting joint training, a direct loss penalty was tested that penalized per-example increases in cross-entropy between adjacent classes. At only 300 training steps, a strong penalty (`weight=3`) reduced the maximum regression to about 1 pp, but also reduced `k=4` accuracy from 100% to about 81.8%. Therefore a monotonicity regularizer can obtain a superficially flatter frontier by suppressing useful intermediate capability.

At 800 steps, the **zero-penalty** joint-training condition already solved almost all observed regression. The explicit penalty is therefore not adopted as the primary mechanism in this toy.

## Interpretation

The previous failure should not be attributed directly to nested physical execution. A stronger explanation supported by this intervention is:

> when one execution class is sampled per update, different budgets compete through a shared parameter set and high-work classes can remain under-optimized; balanced simultaneous training across all admissible classes largely removes that interference.

This is analogous to multi-task optimization: each execution class is a related task sharing parameters. Coverage of all tasks per update changes the gradient mixture even though architecture and inference policy are unchanged.

The result still does **not** give a formal utility-monotonicity guarantee. If hard real-time admission requires a strict quality contract, an architectural fallback or certified output-refinement rule would still be needed.

## Reproduction

```bash
docker build -f container/Dockerfile.joint_budget.cpu -t rtnn-joint-budget .
docker run --rm -v "$PWD/results:/workspace/results" rtnn-joint-budget
```

Recorded executions used the available Linux container on x86-64 AMD EPYC 7763 virtual CPUs, Python 3.13.5, PyTorch 2.10.0+cpu, with one PyTorch intra-op thread. The official script was re-run for seeds 0 and 1 until the session command limit, then seed 2 was re-run separately; all three exactly reproduced the earlier zero-penalty joint-training measurements. Docker itself is not installed in the execution environment, so the image could not be built here.

## Nonclaims

No WCET, hard-real-time, RTOS deployment, hardware-portability, energy, or universal utility-monotonicity claim is made.
