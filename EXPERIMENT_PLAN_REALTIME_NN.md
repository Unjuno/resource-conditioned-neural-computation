# Experiment plan: direct Real-Time NN mechanism

## Objective

Test the intended mechanism directly:

> With one fixed neural network, a runtime-admitted work/time budget constrains physical execution, the NN may choose which admissible internal computation is useful, and the resulting work/quality/latency relation can support deadline-aware admission.

A controller/gate is an implementation mechanism, not the research target.

## Progress

- **Phase 1 — budget-conditioned physical block execution:** PASS.
- **Phase 2a — learned module selection under a hard runtime work cap:** PASS with explicit relevance supervision.
- **Phase 2b — finer-grained channel/neuron/sub-block activation:** OPEN.
- **Phase 3a — fixed execution classes + deadline admission:** PASS as empirical P95 soft/weakly-hard.
- **Phase 3b — learned activation + deadline admission:** PASS as empirical P95 soft/weakly-hard.
- **Phase 3c — learned activation without explicit relevance labels:** NEXT PRIMARY EXPERIMENT.
- **Phase 4 — hard timing guarantee / WCET:** OPEN.

## Phase 1 — physical budget execution — PASS

One fixed network physically executes different numbers of optional blocks as budget changes. Hard-skip timing is monotonic across three seeds; dense masking without physical skipping does not obtain the latency reduction.

## Phase 2a — learned selection inside a hard cap — PASS

The runtime admits exactly `k ∈ {1,2,4,8}` expert calls. A learned controller chooses which experts to execute, while hard top-k prevents execution beyond `k`.

At `k=4`, learned activation reaches **100%** accuracy versus **78.18%** for fixed prefix, with controller overhead included in latency.

The controller currently uses explicit relevance supervision.

## Phase 3a — fixed-class deadline admission — PASS with caveat

Empirical P95 execution classes let a runtime choose the largest fixed execution budget that fits a deadline. Hard physical skipping reduces misses under tight deadlines compared with dense-mask and always-full execution.

This is soft/weakly-hard only.

## Phase 3b — learned activation + deadline admission — PASS with caveat

The runtime calibrates policy-specific P95 timing classes including controller overhead, admits `k`, and the NN chooses which `k` modules to execute.

All policies are tested on the same absolute deadline within each seed. Faster baselines may admit more work.

Three-seed on-time & correct rates:

| regime | learned | prefix | external oracle | always full |
|---|---:|---:|---:|---:|
| tightest | 64.50% | **66.00%** | 64.25% | 0.00% |
| around learned `k=2` | **78.08%** | 70.50% | **80.29%** | 2.13% |
| around learned `k=4` | **98.46%** | 76.00% | **98.71%** | 88.29% |
| full-budget | 98.46% | **98.92%** | 97.33% | 98.46% |

The result is intentionally not presented as universal learned-policy superiority. Controller overhead hurts at the tightest/full regimes, and the analytic relevance oracle remains slightly stronger in the synthetic task.

## Phase 3c — remove explicit relevance supervision — NEXT

The next experiment must preserve the systems contract while making useful internal computation latent:

```text
runtime admits k
NN learns which k modules to execute from task loss
physical execution may not exceed k
```

Required properties:

1. hard runtime work cap remains structural;
2. inactive modules remain physically skipped;
3. controller overhead remains in end-to-end timing;
4. selection is trained primarily from task loss rather than a supplied relevance target;
5. learned policy is compared with fixed-prefix, dense-mask, and an external oracle where one can still be defined;
6. success is judged by quality / on-time-correct / physical budget compliance, not router accuracy.

A negative result is acceptable if task-only learning collapses to a poor selection policy; prior capability-preservation diagnostics may then be used only to explain that concrete failure.

## Phase 2b — finer physical activation — OPEN

After the task-only controller is stable, test structured channel/neuron/sub-block groups only where inactive work is physically skipped. Do not use dense zero masks as evidence of compute reduction.

## Phase 4 — timing guarantee boundary — OPEN

Ordinary Linux/PyTorch timing is not WCET. The fixed-depth experiment already shows non-monotonic q99 classes, and learned-policy timing contains large high-percentile outliers.

A hard-real-time experiment requires statically analyzable code, a time-predictable target, controlled RTOS scheduling/interference assumptions, formal/static WCET, or an accepted equivalent.

## Direction rule

Do not expand router/NAS experiments unless they solve a concrete failure in:

```text
budget → physical activation → work → latency → deadline
```
