# Resource-Conditioned Neural Computation — Readiness Report

## Current status

The repository has now passed three core toy-system gates for the intended Real-Time NN direction:

1. **direct budget-conditioned physical execution**;
2. **learned selection of admissible internal work under a hard runtime cap**;
3. **learned activation integrated with empirical deadline admission**.

The demonstrated toy chain is:

```text
deadline
  → runtime-admitted work budget
  → budget-compliant learned internal activation
  → physically executed work
  → measured latency
  → on-time task quality
```

However, **hard-real-time readiness is not reached**. Current timing is ordinary Linux/PyTorch and remains empirical rather than WCET.

## Milestone 1 — physical budget execution

Across three seeds in `realtime_nn_budget_execution.py`, one fixed network physically executes `0/2/4/6/8` optional blocks at increasing budgets. Hard-skip median latency is strictly monotonic in 3/3 seeds, with a mean full/minimum latency ratio of **35.73x**. Dense logical masking executes all blocks and does not obtain the speedup.

## Milestone 2 — learned selection under a hard cap

Across three seeds in `realtime_nn_learned_budget_gate.py`, the runtime admits exactly `k ∈ {1,2,4,8}` expert calls and hard top-k prevents budget violation.

At `k=4`, learned activation reaches **100%** accuracy versus **78.18%** for fixed prefix, while controller overhead remains visible in end-to-end timing.

The controller currently uses explicit relevance supervision.

## Milestone 3 — learned selection + deadline admission

`realtime_nn_learned_deadline_integration.py` calibrates policy-specific P95 execution classes including controller overhead. All policies see the same absolute deadline within each seed.

Main metric: **on-time & correct rate**.

Three-seed aggregate:

| regime | learned | prefix | external relevance oracle | always full |
|---|---:|---:|---:|---:|
| tightest | 64.50% | **66.00%** | 64.25% | 0.00% |
| around learned `k=2` | **78.08%** | 70.50% | **80.29%** | 2.13% |
| around learned `k=4` | **98.46%** | 76.00% | **98.71%** | 88.29% |
| full-budget | 98.46% | **98.92%** | 97.33% | 98.46% |

At the clean `k≈4` regime, learned and prefix miss rates are close (**1.54% vs 1.21%**) while on-time-correct differs by more than 22 percentage points.

This supports the intended split:

```text
RTOS/runtime: decide how much work is feasible
NN:           decide which feasible internal work is useful
```

## Important negative boundaries

Learned selection is **not universally superior**:

- the tightest deadline favors the simpler prefix policy because controller overhead matters;
- full budget also favors prefix slightly because selection no longer provides a quality benefit;
- an external oracle that directly reads the synthetic relevance mask remains slightly stronger than the learned controller.

Therefore the current learned experiment is a mechanism demonstration, not evidence that neural selection is necessary when equivalent selection information is analytically exposed.

## Timing boundary

The fixed-depth calibration already showed raw q99 execution classes non-monotonic in 3/3 seeds. Learned-policy calibration also contains large high-percentile outliers relative to median latency.

All current deadline claims are **soft/weakly-hard empirical P95** results. WCET/hard real time is not established.

## What remains before a stronger claim

1. remove explicit relevance supervision and learn useful admissible activation from task loss while preserving the hard work cap;
2. use a task where useful internal computation is latent rather than directly exposed as a relevance mask;
3. adapt admitted budgets to machine state;
4. test finer-grained structured physical activation;
5. move to an RTOS/time-predictable target or obtain defensible static/formal WCET.

## Readiness labels

- **Direct physical budget execution:** PASS.
- **Learned budget-compliant physical activation:** PASS with explicit relevance supervision.
- **Learned activation + soft deadline admission:** PASS with empirical-timing caveat.
- **Autonomous/latent useful-computation discovery:** OPEN.
- **Machine-state-aware admission:** OPEN.
- **Hard real time / WCET:** NOT ESTABLISHED.
- **Real-Time LM / LLM-scale generalization:** NOT TESTED.

## Recommended framing

**Real-Time Neural Computation: Budget-Conditioned Internal Activation for Predictable Inference Time**

“Predictable” currently means observed/calibratable central timing behavior, not a formal WCET guarantee.
