# Machine-state timing stability audit

## Question

Can an ordinary Linux runtime treat a coarse machine-state label such as `idle` or `loaded` as a stable mapping to empirical P95 execution-class timing, then safely change the admitted Real-Time NN budget when the state changes?

This is a runtime-side falsification experiment. The neural model is the already-established fixed-depth Real-Time NN; only the timing environment changes.

## Why this audit was needed

An initial three-seed experiment appeared encouraging: under one periodic same-core load run, re-calibrating P95 timings under load often reduced deadline misses by admitting a smaller budget.

However, an independent repeat contradicted that result: the same load condition sometimes produced much lower P95 estimates and allowed equal or larger budgets.

That initial positive result is therefore **not promoted**.

The follow-up asks whether the empirical timing table itself is stable.

## Setup

One inference process and one competitor process are pinned to the same CPU.

Three states are measured:

1. `idle` — no competitor;
2. `periodic` — competitor is busy for 0.35 ms then sleeps for 1.65 ms;
3. `busy` — competitor continuously consumes the same CPU.

Within every calibration repetition, budget levels are randomly interleaved to reduce simple phase-locking between a budget class and the periodic competitor.

For two independently trained model seeds, each state is calibrated **six times**, with 160 measurements per budget per repetition.

The statistic under audit is empirical P95 latency.

## Repeated P95 result

The P95 coefficient of variation is not uniformly small even when the coarse machine-state label is unchanged.

### Seed 0

Maximum CV by state:

- idle: **0.321**;
- periodic: **0.092**;
- continuous busy: **0.808**.

Under continuous busy load, `B=.5` P95 ranges from **551 us to 4.30 ms** across nominally identical repeated calibrations.

### Seed 1

Maximum CV by state:

- idle: **0.255**;
- periodic: **0.089**;
- continuous busy: **0.990**.

Under continuous busy load:

- `B=.25` P95 ranges from **233 us to 4.16 ms**;
- `B=.5` ranges from **561 us to 4.29 ms**.

The instability is therefore not attributable to one model seed.

## Quantile-cliff diagnostic

A larger seed-0 probe collects 1,800 latency samples per budget under continuous same-core contention.

| budget | median | P95 | P99 | fraction > 4 ms |
|---:|---:|---:|---:|---:|
| .25 | 103 us | 381 us | 8.36 ms | 3.00% |
| .50 | 189 us | **8.38 ms** | 9.13 ms | **6.94%** |
| .75 | 279 us | 8.49 ms | 9.49 ms | 9.22% |
| 1.00 | 378 us | 8.63 ms | 10.16 ms | 11.72% |

This exposes the mechanism behind the unstable P95.

At `B=.25`, scheduler-preempted samples occur in only about 3% of requests, so P95 remains in the fast mode.

At `B=.5`, the probability of a >4 ms stall rises to roughly 7%, crossing the 5% quantile boundary. P95 therefore jumps from the normal sub-millisecond execution mode into the scheduler-preempted mode.

Small run-to-run changes in preemption probability around 5% can consequently move P95 by several milliseconds even though the neural execution class itself has not changed.

The probability of a >4 ms stall also increases with the median neural execution duration in this probe:

- .25: 3.00%;
- .50: 6.94%;
- .75: 9.22%;
- 1.00: 11.72%.

This is consistent with a simple exposure interpretation: a longer-running NN request has a larger window in which external scheduler interference can occur. It is descriptive evidence, not a formal stochastic schedulability model.

## Main conclusion

The tested runtime abstraction is **not supported** on ordinary Linux:

> `coarse machine state -> one empirical P95 timing table -> admitted budget`

is not a stable enough contract when scheduler/preemption effects create a mixture distribution near the chosen quantile.

This is stronger than merely saying “Linux has jitter.” The experiment shows a specific failure mode: **quantile cliffs** can make a high-percentile execution-class boundary discontinuous and run-to-run unstable.

## Real-Time NN implication

The neural budget mechanism itself still matters. Lower budgets shorten nominal physical execution and, in the continuous-busy probe, reduce the observed probability of encountering a long preemption stall.

But the NN cannot solve scheduler interference by itself.

For a genuine Real-Time NN system, the runtime/RTOS must control or account for interference through mechanisms such as:

- CPU reservation / scheduling isolation;
- bounded-priority interference analysis;
- time-predictable execution;
- statically analyzable generated inference code;
- formal/static WCET or an accepted probabilistic real-time model with explicit assumptions.

Simply re-measuring P95 after observing a categorical `loaded` state is not sufficient evidence.

## What this changes

The previous next-step idea — “state-aware P95 recalibration under load” — is narrowed.

The runtime research question is now:

> Under a controlled scheduling substrate, can deadline + bounded interference information be converted into a safe admitted neural work budget?

On ordinary Linux, categorical state-aware recalibration remains a negative diagnostic rather than a supported solution.

## What this does not claim

- that all statistical timing methods are invalid;
- that probabilistic real-time analysis is impossible;
- that lower neural budgets do not help under interference;
- that the observed 8 ms stall mode is universal across machines;
- WCET/hard-real-time behavior on Linux/PyTorch.

The result is specifically about the instability of an empirical P95 execution-class table under uncontrolled same-core Linux interference.
