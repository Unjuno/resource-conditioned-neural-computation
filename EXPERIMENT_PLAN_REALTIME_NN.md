# Experiment plan: direct Real-Time NN mechanism

## Objective

Test the intended system directly:

> A runtime admits a bounded amount of neural work; one fixed NN physically executes only admissible computation and may learn which admissible computation is useful; the runtime must derive that budget from a defensible timing/interference model.

## Progress

### Model side

- **Physical budget-conditioned execution:** PASS.
- **Learned selection under a hard runtime cap:** PASS.
- **Task-loss-only useful-computation selection:** PASS in the supplied toy search space.
- **Learned selection + empirical soft deadline admission:** PASS with caveats.
- **Less analytically exposed useful-computation task:** OPEN.
- **Finer structured physical activation:** OPEN.

### Runtime side

- **Empirical central-latency execution classes on ordinary Linux:** usable as a toy soft/weakly-hard mechanism.
- **Coarse machine-state → empirical P95 timing table:** FAIL / unstable under uncontrolled same-core Linux interference.
- **Controlled RTOS/interference-aware admission:** NEXT PRIMARY RUNTIME MILESTONE.
- **Hard timing guarantee / WCET:** OPEN.

## Why simple machine-state recalibration failed

The tested idea was:

```text
state ∈ {idle, loaded}
      ↓
empirical P95 table
      ↓
admitted budget
```

An initial run appeared positive but did not reproduce.

Repeated interleaved calibration showed that the same categorical state can produce P95 estimates that jump between a normal execution mode and a scheduler-preempted mode.

Under continuous same-core load, a high-sample probe gives:

| budget | median | P95 | >4 ms fraction |
|---:|---:|---:|---:|
| .25 | 103 us | 381 us | 3.00% |
| .50 | 189 us | **8.38 ms** | **6.94%** |
| .75 | 279 us | 8.49 ms | 9.22% |
| 1.00 | 378 us | 8.63 ms | 11.72% |

The `B=.5` class crosses the 5% preemption-frequency threshold, so P95 moves discontinuously into the preempted mode. This is a **quantile-cliff** failure, not a neural routing failure.

## Next primary runtime experiment

Stop trying to rescue uncontrolled Linux P95 with more calibration.

Use a **controlled scheduling/interference substrate**. Preferred sequence:

1. generate a small fixed conditional-execution inference implementation with analyzable block classes;
2. run it under isolated/reserved CPU scheduling or an available RTOS/time-predictable environment;
3. define explicit interference assumptions;
4. obtain per-budget timing bounds under those assumptions;
5. let the runtime admit the largest budget whose bound fits the deadline;
6. verify that NN learned selection remains inside the admitted work cap.

Target chain:

```text
deadline + bounded interference
       ↓
defensible execution-time bound by budget
       ↓
admitted work budget
       ↓
same NN physical execution
```

If an RTOS target is unavailable, the next-best experiment is generated single-thread C/C++ inference under isolated CPU scheduling, with explicit acknowledgement that this is still not formal WCET.

## Next model-side falsification

In parallel, make useful internal computation less analytically exposed than the current key/query toy while retaining:

- task-loss-only selection;
- hard physical work cap;
- physical skip audit;
- measured controller overhead;
- strong fixed/external baselines.

Do not increase model scale unless the mechanism requires it.

## Finer physical activation — OPEN

Test channel/neuron/sub-block groups only where inactive computation is physically skipped. Dense zero masks do not count as work reduction.

## Hard timing boundary

Ordinary Linux/PyTorch empirical percentiles are not WCET. The new machine-state audit makes that boundary stronger: even P95 can become discontinuous when scheduler-preemption probability crosses the selected quantile.

A hard-real-time result requires controlled scheduling plus a defensible static/formal/probabilistic timing argument with explicit assumptions.

## Direction rule

Do not return to route-score/NAS optimization unless it fixes a concrete problem in:

```text
budget → physical activation → work → timing bound → deadline
```
