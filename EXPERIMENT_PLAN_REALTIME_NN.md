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
- **Execution-class granularity / capability co-design:** PASS as a toy audit; post-hoc intermediate classes can be invalid, while jointly trained classes preserve capability.
- **Less analytically exposed useful-computation task:** OPEN.
- **Channel/neuron/sub-block physical activation:** OPEN.

### Runtime side

- **Empirical central-latency execution classes on ordinary Linux:** usable as a toy soft/weakly-hard mechanism.
- **Coarse machine-state → empirical P95 timing table:** FAIL / unstable under uncontrolled same-core Linux interference.
- **Generated plain-C++ conditional execution:** PASS as an implementation bridge; central work/latency ordering survives framework removal.
- **Controlled RTOS/interference-aware admission:** NEXT PRIMARY RUNTIME MILESTONE.
- **Hard timing guarantee / WCET:** OPEN.

## Execution-class granularity rule

A runtime-admissible class is not automatically valid just because its work count lies between two working classes.

On the direct 9-bit-majority model, the original network was trained only at depths `0 / 2 / 4 / 6 / 8`. Post-hoc evaluation at untrained depths `1 / 3 / 5 / 7` can lose substantial task capability.

When all depths `0..8` are included in the joint task objective from the start, all three tested seeds recover non-decreasing accuracy and strictly increasing median latency across depth. However, several intermediate classes are dominated: they have the same quality as a cheaper shallower class.

Therefore the runtime contract should expose only classes that are both:

1. **capability-validated** under training/evaluation; and
2. **Pareto-useful** on the quality/work/timing frontier.

See `notes/realtime_nn_execution_class_granularity.md`.

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

1. use the generated small fixed conditional-execution implementation with explicit finite block classes;
2. run it under isolated/reserved CPU scheduling or an available RTOS/time-predictable environment;
3. define explicit interference assumptions;
4. obtain per-budget timing bounds under those assumptions;
5. let the runtime admit the largest validated Pareto execution class whose bound fits the deadline;
6. verify that NN learned selection remains inside the admitted work cap.

Target chain:

```text
deadline + bounded interference
       ↓
defensible execution-time bound by validated budget class
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

## Finer physical activation — still open below block granularity

The execution-depth granularity audit is complete for the supplied block architecture. Channel/neuron/sub-block groups remain open and count only if inactive computation is physically skipped. Dense zero masks do not count as work reduction.

## Hard timing boundary

Ordinary Linux/PyTorch empirical percentiles are not WCET. The machine-state audit makes that boundary stronger: even P95 can become discontinuous when scheduler-preemption probability crosses the selected quantile.

A hard-real-time result requires controlled scheduling plus a defensible static/formal/probabilistic timing argument with explicit assumptions.

## Direction rule

Do not return to route-score/NAS optimization unless it fixes a concrete problem in:

```text
budget → physical activation → work → timing bound → deadline
```
