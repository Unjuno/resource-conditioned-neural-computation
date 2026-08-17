# Resource-Conditioned Neural Computation — Readiness Report

## Current status

The repository has now passed two core toy mechanism gates for the intended Real-Time NN direction:

1. **direct budget-conditioned physical execution**;
2. **learned selection of admissible internal work under a hard runtime cap**.

The main chain now demonstrated in toy systems is:

```text
admitted budget
  → physically bounded internal activation
  → executed work
  → measured median latency
  → task-quality trade-off
```

A soft P95 deadline-admission prototype is also demonstrated for the fixed-depth version.

However, **hard-real-time readiness is not reached**. Current timing is ordinary Linux/PyTorch and q99 tails are not stable enough for WCET-style interpretation.

## Milestone 1 — direct physical execution

`experiments/realtime_nn_budget_execution.py` uses one fixed network with eight optional local-information-propagation blocks.

Across three seeds:

- budgets `0 / .25 / .5 / .75 / 1.0` execute `0 / 2 / 4 / 6 / 8` blocks;
- hooks verify inactive blocks are not called;
- dense-mask executes all eight blocks at every logical budget;
- mean accuracy is **63.67% / 71.48% / 78.52% / 86.33% / 100%**;
- mean hard-skip median latency is **10.53 / 98.80 / 185.69 / 280.26 / 375.82 us**;
- median latency is strictly monotonic in **3/3 seeds**;
- full/minimum budget latency ratio averages **35.73x**.

## Milestone 2 — learned activation under a hard cap

`experiments/realtime_nn_learned_budget_gate.py` lets the runtime admit exactly `k ∈ {1,2,4,8}` expert calls. A learned controller chooses which experts to execute, while hard top-k prevents execution beyond the cap.

The controller uses explicit relevance supervision, so this is not claimed as spontaneous self-organization.

Across three seeds:

- hard budget compliance passes at every k;
- learned median latency is strictly monotonic in every seed;
- dense-mask executes all eight experts at every budget;
- learned hard-skip and dense learned outputs match numerically;
- learned accuracy at `k=2` is **81.90%** versus **71.43%** for fixed prefix;
- learned accuracy at `k=4` is **100%** versus **78.18%** for fixed prefix;
- learned median latency at `k=4` is **195.40 us** versus **171.37 us** for fixed prefix, so the measured controller overhead is retained rather than hidden.

This supports the intended responsibility split:

```text
RTOS/runtime: how much work may execute
NN:           which admissible internal work is useful
```

## Runtime integration milestone

The fixed-depth experiment uses empirical P95 execution-class calibration and chooses the largest budget that fits a deadline.

At the tightest class, mean miss rates across three seeds are:

- adaptive hard-skip: **0.13%**;
- adaptive dense-mask: **100%**;
- always full-depth: **100%**.

This is a **soft/weakly-hard statistical demonstration**, not hard real time.

## Negative timing result retained

Raw empirical q99 execution times were not strictly increasing in any of the three fixed-depth calibration seeds.

Therefore:

- median/P95 execution classes are useful for the current toy Linux process;
- far-tail timing remains scheduler/preemption-sensitive;
- empirical high percentiles must not be presented as WCET;
- hard-real-time determinism is not established.

## What is now supported

A short mechanism note can defensibly state:

> In supplied toy networks, an RTOS/runtime can impose a work budget on one fixed neural parameter set; the network can physically execute only budget-compliant internal computation, and a learned controller can choose more useful admissible computation while preserving a reproducible quality/work/median-latency trade-off.

The note must simultaneously state that current timing is empirical and not WCET/hard real time.

## What remains before a stronger Real-Time NN claim

1. integrate the learned controller with deadline admission and compare quality at matched miss rate;
2. remove explicit relevance supervision and test more autonomous learned activation without losing hard budget compliance;
3. adapt admitted budgets to changing machine state;
4. test finer-grained physical activation only where inactive work is truly skipped;
5. move to an RTOS/time-predictable target or obtain a defensible static/formal WCET argument.

## Role of older router/topology experiments

They remain secondary implementation diagnostics for capability forgetting, shortcut collapse, correlated decisions, feasibility-vs-price separation, contract expressiveness, local minima, non-separable costs, and timing-tail instability.

They are not the headline evidence unless they improve or explain the direct budget→work→latency chain.

## Readiness labels

- **Direct Real-Time NN toy physical-execution mechanism:** PASS.
- **Learned budget-compliant physical activation:** PASS with explicit relevance supervision.
- **Soft/weakly-hard deadline-admission prototype:** PASS with empirical-timing caveat.
- **Learned activation + deadline admission:** OPEN.
- **Autonomous/self-organized relevance discovery:** OPEN.
- **Hard real time / WCET:** NOT ESTABLISHED.
- **Real-Time LM / LLM-scale generalization:** NOT TESTED.

## Recommended framing

**Real-Time Neural Computation: Budget-Conditioned Internal Activation for Predictable Inference Time**

The word "predictable" currently refers to observed/calibratable central latency behavior, not a formal WCET guarantee.
