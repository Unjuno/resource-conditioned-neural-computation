# Resource-Conditioned Neural Computation — Readiness Report

## Current status

The repository has now passed the **direct toy mechanism gate** for the intended Real-Time NN direction.

The new experiment measures, in one fixed network:

```text
budget
  → internal activation depth
  → physically executed blocks / work
  → measured end-to-end latency
  → soft deadline behavior
```

This repairs the earlier gap where router-policy scores had been mistaken for the main systems evidence.

However, **hard-real-time readiness is not reached**. The current timing is ordinary Linux/PyTorch and the empirical q99 tail is not stable enough for WCET-style interpretation.

## Direct mechanism result

`experiments/realtime_nn_budget_execution.py` uses one fixed network with eight optional local-information-propagation blocks.

Across three seeds:

- budget `0 / .25 / .5 / .75 / 1.0` executes `0 / 2 / 4 / 6 / 8` blocks;
- hooks verify the hard-skip implementation does not call inactive blocks;
- a matched dense-mask control calls all eight blocks at every budget;
- hard-skip and dense-mask produce identical outputs for the same budget;
- mean accuracy is **63.67% / 71.48% / 78.52% / 86.33% / 100%**;
- mean hard-skip median latency is **10.53 / 98.80 / 185.69 / 280.26 / 375.82 us**;
- hard-skip median latency is strictly monotonic in **3/3 seeds**;
- full/minimum budget median-latency ratio averages **35.73x**;
- the dense-mask control stays near full-compute latency rather than obtaining the hard-skip speedup.

This is the first result in the repository that directly supports the intended physical mechanism rather than only a routing proxy.

## Runtime integration milestone

A simple runtime admission prototype uses empirical P95 execution-class calibration and chooses the largest budget that fits the deadline.

At the tightest deadline class, mean miss rates across three seeds are:

- adaptive hard-skip: **0.13%**;
- adaptive dense-mask: **100%**;
- always full-depth: **100%**.

The adaptive policy trades quality for deadline feasibility using the same network.

This is a **soft/weakly-hard statistical demonstration**, not a hard-real-time guarantee.

## Negative timing result retained

Raw empirical q99 execution times were not strictly increasing in **any of the three seeds** during separate calibration runs.

Therefore:

- median/P95 execution classes are useful for this toy Linux process;
- the far tail remains scheduler/preemption-sensitive;
- empirical high-percentile timing must not be presented as WCET;
- the current experiment does not establish deterministic hard-real-time behavior.

## What is now supported

A short mechanism note can defensibly state:

> In a supplied toy architecture, one fixed neural network can use an admitted budget to change the internal computation it physically executes, producing a reproducible quality/work/median-latency trade-off; a soft statistical runtime can use the resulting execution classes for deadline-aware admission.

The note must simultaneously state that the timing evidence is not WCET/hard real time.

## What remains before a stronger Real-Time NN claim

1. **Learned budget-conditioned activation.** The current budget→depth map is deliberately fixed to isolate the physical mechanism.
2. **Hard budget compliance under learned gating.** A learned controller must not exceed the runtime-admitted work budget.
3. **More predictable timing substrate.** RTOS/time-predictable hardware/compiler/runtime or a defensible static/formal timing model is needed.
4. **Machine-state adaptation.** Runtime calibration must handle DVFS/contention/temperature without relying on unstable Linux tail estimates.
5. **Finer activation granularity.** Block/channel conditional execution should be tested only when physical skipping is preserved.

## Role of the older router/topology experiments

They remain secondary implementation diagnostics for:

- capability forgetting;
- shortcut collapse;
- correlated decisions;
- feasibility-vs-price separation;
- contract expressiveness;
- policy/objective local minima;
- non-separable cost failures.

They are not the headline evidence unless they improve or explain the direct budget→work→latency chain.

## Readiness labels

- **Direct Real-Time NN toy mechanism:** PASS.
- **Soft/weakly-hard deadline-admission prototype:** PASS with explicit empirical-timing caveat.
- **Learned budget-conditioned physical activation:** OPEN.
- **Hard real-time / WCET:** NOT ESTABLISHED.
- **Real-Time LM / LLM-scale generalization:** NOT TESTED.

## Recommended framing

**Real-Time Neural Computation: Budget-Conditioned Internal Activation for Predictable Inference Time**

The word "predictable" must currently refer to the observed/calibratable central latency behavior, not a formal WCET guarantee.
