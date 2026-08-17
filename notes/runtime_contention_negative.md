# Runtime contention follow-up: negative result

## Question

Can the same three-circuit network use empirical runtime-state calibration to keep all circuits available when idle, but disable the expensive tied-deep circuit under same-core CPU contention while keeping lighter routes available?

The experiment pins inference to one CPU and introduces a competing busy process on the same CPU. It measures each forced execution class with ordinary Linux/PyTorch timing and constructs an empirical 99%-order-statistic availability mask.

This is not WCET analysis.

## What happened

The desired route-specific separation was **not stable**.

Across three independent invocations of the 3-repetition script during development, the number of repetitions in which contention produced the intended separation (idle: all three admissible; contended: tied-deep rejected while at least one lighter route remained admissible) was:

- invocation A: **0/3**
- invocation B: **1/3**
- invocation C: **0/3**

The observed loaded P99/order-statistic tails were often dominated by scheduler/preemption events of several milliseconds. Those events affected even the short routes, so a route-local compute difference did not reliably translate into a stable route-specific P99 mask.

The held-out miss-rate comparison also changed sign between invocations: state recalibration sometimes reduced misses and sometimes did not.

## Interpretation

This is a useful falsification of an overly simple story:

> "Measure each route under the current load, build a P99 mask, and runtime-state recalibration will reliably separate safe from unsafe neural circuits."

That statement is **not supported** on ordinary Linux under same-core contention in this experiment.

The result reinforces two boundaries:

1. OS scheduling/preemption can dominate neural execution-class timing at tail quantiles.
2. State-conditioned empirical calibration is not automatically sufficient for hard or even stable probabilistic real-time behavior; the runtime/hardware platform and timing model matter.

A time-predictable platform, stronger isolation, explicit scheduler integration, or formal/static WCET analysis would be needed for stronger claims.

## Reproduce

```bash
python experiments/multicircuit_runtime_state_calibration.py
```

Absolute values and even the route-separation outcome are intentionally expected to vary with host scheduling state. That instability is part of the reported negative result.
