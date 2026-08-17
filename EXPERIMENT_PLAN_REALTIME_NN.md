# Experiment plan: direct Real-Time NN mechanism

## Objective

Test the intended mechanism directly:

> With one fixed neural network and the same task input, changing only an admitted compute/time/resource budget changes which internal computation is physically executed, and this changes measured inference latency in a predictable direction.

A gate/controller is an implementation mechanism, not the research target.

## Progress

- **Phase 1 — budget-conditioned physical block execution:** PASS on the current toy.
- **Phase 2 — finer-grained physical activation:** OPEN.
- **Phase 3 — deadline-to-budget runtime:** PARTIAL PASS as an empirical P95 soft/weakly-hard prototype.
- **Phase 4 — hard timing guarantee / WCET:** OPEN; not established.
- **Learned budget-conditioned activation under a hard admitted budget:** OPEN and now the next primary experiment.

See `notes/realtime_nn_budget_execution.md`.

## Phase 1 — Budget-conditioned block execution — PASS

The current experiment uses one fixed network with eight optional blocks. Budget levels activate `0 / 2 / 4 / 6 / 8` blocks.

The implementation uses control flow so inactive blocks are not called.

Required measurements are now present:

- budget;
- same-input counterfactuals;
- active block trace;
- forward-hook execution audit;
- executed block/MAC proxy;
- end-to-end latency;
- task quality.

Across three seeds, hard-skip median latency is strictly monotonic with executed depth and the quality/latency trade-off is reproducible.

The matched dense-mask control calls all eight blocks at every logical budget and does not obtain the hard-skip latency reduction.

## Phase 2 — Finer activation granularity — OPEN

Test whether the same principle survives finer-grained conditional execution:

- groups of channels;
- structured neuron groups;
- residual sub-blocks;
- optional module groups.

Do **not** use zero masks that leave the dense kernel unchanged. Inactive structure must correspond to skipped physical work.

Measure:

- controller/gating overhead;
- achieved work reduction;
- measured latency reduction;
- quality;
- timing variance.

The goal is not maximum routing sophistication. The goal is the finest useful activation granularity that still creates predictable physical timing classes.

## Phase 3 — Deadline-to-budget runtime — PARTIAL PASS

The current toy runtime calibrates empirical execution classes and maps deadline to the largest admitted budget.

The current version uses P95 plus a monotone conservative envelope and is explicitly **soft/weakly-hard**.

It demonstrates that hard physical skipping can reduce misses under tight deadlines compared with:

- always-full execution;
- a dense-mask implementation that logically selects a smaller budget but still performs all block computation.

Next runtime work should add machine state:

```text
deadline D
machine state S
calibrated timing model
      ↓
admitted budget B
      ↓
same NN
```

Record deadline, admitted budget, activation trace, predicted latency, actual latency, hit/miss, and quality.

## Phase 4 — Timing guarantee boundary — OPEN

Ordinary Linux/PyTorch timing is not WCET.

The current experiment deliberately retains a negative result: raw empirical q99 timing is not strictly monotonic in any of the three calibration seeds.

A stronger hard-real-time experiment requires at least one of:

- statically analyzable generated inference code;
- a time-predictable embedded target;
- controlled RTOS scheduling/interference assumptions;
- formal/static WCET or an accepted equivalent.

Do not infer WCET from median/P95/P99 Linux measurements.

## Next primary experiment — learned budget-conditioned activation

Replace the deliberately fixed budget→depth mapping with a learned activation mechanism while maintaining a **hard runtime-admitted budget cap**.

The learned controller may decide *which* admissible blocks/groups are useful, but it may not execute more work than the runtime admitted.

Required controls:

1. same fixed weights across inference budgets;
2. physical-skip hook audit;
3. explicit executed-work accounting;
4. controller overhead included in end-to-end latency;
5. matched fixed-prefix budget baseline;
6. budget-blind controller baseline;
7. dense-mask negative control;
8. quality and miss-rate comparison at matched budget/deadline.

The learned controller is useful only if it improves quality or flexibility **without destroying the budget→actual-time relationship**.

## Baselines

Main-line baselines now are:

- fixed smallest execution level;
- fixed largest execution level;
- fixed-prefix same-network budget execution;
- learned budget-conditioned same-network execution;
- budget-blind matched controller;
- dense-mask control that executes all work;
- external execution-class scheduler where applicable.

Router architecture comparisons are secondary unless controller overhead or stability materially changes actual latency/deadline behavior.

## Primary plots / tables

1. budget vs physically executed compute;
2. budget vs measured latency distribution;
3. executed compute vs latency;
4. budget vs quality;
5. deadline vs miss rate / quality;
6. same-input activation traces at low/mid/high budget;
7. hard-skip vs dense-mask latency.

## Falsification criteria

The Real-Time NN interpretation is weakened if:

- budget changes masks but not actual executed work;
- physical work changes but latency does not because control overhead dominates;
- latency classes overlap too strongly for useful admission;
- learned gating violates the admitted budget;
- learned gating improves a routing proxy but not measured quality/latency/deadline behavior;
- only separate model instances, rather than one parameter set, achieve the trade-off.

Negative results should remain public.

## Direction rule

Do not expand router/NAS experiments unless they answer a concrete failure in the direct chain:

```text
budget → physical activation → work → latency → deadline
```
