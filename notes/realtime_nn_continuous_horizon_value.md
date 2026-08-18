# Continuous normalized budget + horizon value of computation

## Question

The external RTNN control variable should be usable as a percentage rather than an implementation-specific integer block count. This experiment therefore defines the runtime budget as

\[
b \in [0,1],
\]

where `0` is 0% of maximum admitted neural work and `1` is 100%.

The external interface is continuous. The analyzable physical backend remains finite: the supplied six-block sequence model exposes certified work fractions

`0%, 16.67%, 33.33%, 50%, 66.67%, 83.33%, 100%`.

For any continuous `b`, the runtime admits the largest physical class not exceeding `b`. This is deliberately fail-closed. A continuous control contract does **not** imply continuously interpolated machine instructions.

## Why one-step stopping was rejected

A preliminary seed-0 audit predicted only the immediate loss improvement from the next execution class. It failed because an intermediate class can temporarily worsen task loss even when a later class is strongly beneficial. Therefore a local rule can stop before reaching useful future computation.

The corrected target is a horizon value:

\[
V_k(x)=L_k(x)-\min_{j>k}L_j(x),
\]

where `L_k` is the counterfactual teacher-forced task loss after normalized compute state `k/6`. Continue if the predicted horizon value is positive; otherwise stop. Runtime budget then truncates this preferred compute level.

## Protocol

- Same causal two-mode sequence task as the prior nested-routing/cap experiments.
- Seven finite physical classes, normalized to `[0,1]`.
- Five model seeds, 400 joint all-class capability steps.
- Existing post-trained preferred-compute policy retained as the matched baseline.
- Value predictor is trained only after the capability frontier is stable.
- Main state feature: current prompt hidden state (last-token state + mean prompt state) and normalized current compute.
- 21 external budgets `b = 0, 0.05, ..., 1.0`.
- Structural audits at every budget: physical call count, `effective_compute <= b`, non-decreasing effective work, and nested active sets.
- A 4-fold held-out-prompt cross-fit is kept as a stronger generalization test.

PASS boundary versus the post-trained baseline at `b=1`:

- token gap >= -1 pp;
- exact-sequence gap >= -2 pp;
- mean compute increase <= 4.167 percentage points (0.25 of six blocks);
- zero nested/cap violations;
- physical hard-cap audit PASS.

## Main result: mechanism PASS

Five-seed mean at 100% admitted budget:

| policy | token | exact | mean effective compute |
|---|---:|---:|---:|
| existing post-trained preferred compute | 98.125% | 93.75% | 78.958% |
| hidden-state horizon value, full fit | **99.531%** | **98.125%** | **75.625%** |

Difference versus baseline:

- token: **+1.406 pp**;
- exact sequence: **+4.375 pp**;
- mean compute: **-3.333 percentage points**.

Across all five seeds and all 21 continuous budget points:

- nested violations: **0**;
- cap/count violations: **0**;
- physical hard-cap checks: **PASS**.

The main mechanism hypothesis therefore **PASSes on the supplied exhaustive toy**.

Representative mean frontier points for the hidden-state policy:

| external budget | admitted physical ceiling | token | exact | mean effective compute |
|---:|---:|---:|---:|---:|
| 0% | 0% | 56.25% | 11.875% | 0% |
| 20% | 16.67% | 69.688% | 30.0% | 16.67% |
| 35% | 33.33% | 77.031% | 46.25% | 33.33% |
| 50% | 50% | 86.406% | 68.75% | 49.58% |
| 70% | 66.67% | 94.375% | 86.875% | 62.60% |
| 85% | 83.33% | 98.281% | 95.0% | 71.77% |
| 100% | 100% | 99.531% | 98.125% | 75.625% |

This demonstrates the intended semantic separation:

```text
continuous external budget b in [0,1]
    -> finite maximum admitted physical class
    -> input/state-specific preferred compute
    -> cap truncation
    -> nested physical execution
```

## Stronger held-out-prompt result: FAIL

The same hidden-state predictor under 4-fold held-out-prompt cross-fitting reaches only:

- token: **90.0%**;
- exact: **73.75%**;
- mean compute: **64.063%**.

Relative to the post-trained baseline this is -8.125 pp token and -20.0 pp exact, so the held-out-prompt hypothesis **FAILs**.

This is an important boundary: the mechanism can fit the stable value frontier on the supplied exhaustive task, but value-of-computation generalization to unseen prompt groups is not established.

## Prompt-only control

Under the matched 250-step predictor fit, prompt-only horizon prediction is weaker than the hidden-state fit. However a longer seed-0 prompt-only control also reaches 100% token/exact quality. Therefore this experiment does **not** establish that hidden state is uniquely necessary. The supported statement is narrower: the tested hidden-state representation provides a strong deployable fit to the stable frontier; representation/generalization remains open.

## Interpretation

The direct concurrent stopping-policy experiment failed because capability learning and stopping co-adapted or collapsed. This experiment supports a different decomposition:

```text
learn a stable nested capability frontier
    -> learn value of additional computation
    -> expose normalized preferred compute
    -> truncate by continuous RTOS budget
```

The useful research change is not merely replacing integer notation with percentages. It makes the external RTOS/NN boundary hardware-independent and compositional: the RTOS can reason in a normalized `[0,1]` budget while the backend retains a finite certifiable implementation.

## Next falsification target

The immediate unresolved issue is held-out value prediction. The next experiment should move this mechanism to a real temporal dataset and train the value predictor on a genuine train split, then evaluate unseen sequences. Only after that should the latest continuous-budget policy be lowered to the freestanding execution manifest.

## Nonclaims

- No continuously variable machine instruction count; physical work is finite-class internally.
- No proof that hidden state is uniquely better than input-only prediction.
- No held-out-prompt or real-data generalization.
- No WCET, RTOS deployment, or hard-real-time guarantee.
