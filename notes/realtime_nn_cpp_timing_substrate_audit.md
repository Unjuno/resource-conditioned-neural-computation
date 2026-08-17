# C++ timing-substrate audit: memory residency vs scheduler preemption

## Question

The generated C++ implementation still shows millisecond-scale latency tails. Are those tails primarily caused by weight paging / page faults, or do they remain after the model data is resident and point instead toward scheduler interference?

This audit stays on ordinary Linux and therefore does **not** attempt to prove WCET.

## Environment constraint

The container has an 8 MiB `RLIMIT_MEMLOCK`. Locking the entire Python/process address space with `mlockall()` is unavailable (`ENOMEM`).

The generated C++ model weight buffer is only about **335 KiB**, so the audit locks that buffer directly with `mlock()` after loading it.

The C++ timing loop also records `getrusage()` deltas for:

- minor page faults;
- major page faults;
- voluntary context switches;
- involuntary context switches.

The inference CPU is pinned to one allowed CPU and each execution class is warmed before measurement.

## Three-repeat result

Each condition uses 3 repeats × 800 inferences per execution depth.

### Without weight mlock

| depth | median P50 | median P99 | total minor faults | total major faults | total involuntary context switches |
|---:|---:|---:|---:|---:|---:|
| 2 | 71.41 us | 4.12 ms | 0 | 0 | 45 |
| 4 | 143.18 us | 4.17 ms | 0 | 0 | 96 |
| 6 | 217.23 us | 4.32 ms | 0 | 0 | 140 |
| 8 | 293.24 us | 5.04 ms | 0 | 0 | 190 |

### Weight buffer locked with `mlock()`

| depth | median P50 | median P99 | total minor faults | total major faults | total involuntary context switches |
|---:|---:|---:|---:|---:|---:|
| 2 | 71.46 us | 4.10 ms | 0 | 0 | 47 |
| 4 | 143.24 us | 4.19 ms | 0 | 0 | 98 |
| 6 | 217.13 us | 4.25 ms | 0 | 0 | 141 |
| 8 | 292.57 us | 4.40 ms | 0 | 0 | 188 |

The weight lock succeeds, central timing is essentially unchanged, and the multi-millisecond P99 tail remains.

Measured page faults are zero in the depth-2/4/6/8 timing regions for both locked and unlocked conditions.

## Interpretation

This rules out a simple explanation that the observed tail is primarily caused by the model weights being paged in during the measured inference region.

The measurements instead remain consistent with scheduler/preemption interference:

- involuntary context switches remain present with and without `mlock()`;
- their total count increases with longer execution classes in this run;
- the millisecond tail persists while page-fault counters remain zero.

This is **not a formal causal proof** that every outlier is one particular context switch. The important systems conclusion is narrower:

> memory-locking the model weights is insufficient to turn the current Linux execution into a predictable high-percentile timing substrate.

## CPU-affinity / isolation diagnostic

A separate exploratory diagnostic also compared no explicit competitor, a same-CPU busy competitor, a competitor on another allowed CPU, and a same-CPU low-priority (`nice +19`) competitor.

Same-CPU contention clearly creates large scheduler modes. However, on the shared host, even nominal `idle` and different-CPU runs can develop multi-millisecond tails due to activity outside the experiment's control.

Therefore this environment cannot establish that CPU affinity alone is sufficient isolation. The correct next step is a substrate with stronger scheduling guarantees, not further interpretation of shared-host percentile noise.

## Real-Time NN implication

The neural part is now comparatively clear:

```text
budget → finite physical C++ work class → ordered central execution time
```

The unresolved part is the runtime timing guarantee:

```text
finite work class + uncontrolled Linux scheduler → unstable tail
```

For a genuine real-time deployment, the runtime must control or bound interference through RT scheduling / reservation / isolation, or use an analyzable time-predictable target and a defensible WCET/probabilistic timing model.

## What this supports

1. weight-buffer residency is not enough to remove the observed multi-ms tail;
2. measured page faults are not the dominant observed mechanism in the timed regions;
3. scheduler/preemption interference remains the main supported explanation for the current tail behavior;
4. central budget/work timing remains stable while tail safety remains an OS/runtime problem.

## What this does not support

- hard real time or WCET;
- a proof that every outlier is exactly one scheduler preemption;
- a claim that CPU affinity is equivalent to RTOS isolation;
- a claim that `mlock()` is useless on an actual embedded target.
