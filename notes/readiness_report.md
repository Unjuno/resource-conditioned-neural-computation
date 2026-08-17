# Resource-Conditioned Neural Computation — Readiness Report

## Current status

The model-side toy mechanism has passed four gates:

1. direct budget-conditioned physical execution;
2. learned selection under a hard runtime work cap;
3. learned selection integrated with empirical soft deadline admission;
4. useful admissible activation learned from task loss alone in a supplied search space.

The demonstrated model-side chain is:

```text
admitted work budget
  → budget-compliant internal activation
  → physically executed work
  → measured central latency
  → task quality
```

The newest runtime-side audit adds an important **negative boundary**:

> a coarse machine-state label does not provide a stable empirical P95 execution-class table under uncontrolled same-core Linux interference.

Therefore **hard-real-time readiness is not reached**.

## Model-side readiness

### Direct physical execution — PASS

One fixed network physically executes different numbers of optional blocks as budget changes. Hard-skip median timing is monotonic in 3/3 seeds; dense masking without physical skipping does not obtain the speedup.

### Learned hard-budget selection — PASS

Hard top-k structurally enforces the admitted work cap. Learned selection improves quality over fixed prefix in useful intermediate regimes, with controller overhead included.

### Task-loss-only useful-computation selection — PASS in supplied toy search space

Without relevance labels, relevance auxiliary loss, capability warmup, or expert freezing:

- `k=2`: learned **81.27%** vs prefix 71.37%;
- `k=4`: learned **100%** vs prefix 78.74%;
- learned useful-slot selection is 100% for `k<=4` across 3/3 seeds;
- hard-cap compliance and monotonic median timing pass in 3/3 seeds.

This does not establish unconstrained architecture discovery; an analytic key/query oracle exists.

## Runtime machine-state audit — FAIL for simple Linux P95 recalibration

The proposed runtime abstraction was:

```text
observed coarse machine state
    → empirical P95 timing table
    → admitted NN budget
```

An initial experiment appeared to show that recalibration under load reduced misses. An independent repeat contradicted it, so the positive conclusion was withdrawn.

The follow-up repeatedly calibrates the same execution classes under idle, periodic same-core load, and continuous same-core busy load.

Across two model seeds, six repeated calibrations per state show maximum empirical-P95 coefficient of variation of:

- idle: **0.321**;
- periodic: **0.092**;
- continuous busy: **0.990**.

Under continuous busy load, the same execution class can switch between sub-millisecond P95 and multi-millisecond P95 across repetitions.

A larger probe explains the discontinuity:

| budget | median | P95 | >4 ms fraction |
|---:|---:|---:|---:|
| .25 | 103 us | 381 us | 3.00% |
| .50 | 189 us | **8.38 ms** | **6.94%** |
| .75 | 279 us | 8.49 ms | 9.22% |
| 1.00 | 378 us | 8.63 ms | 11.72% |

When scheduler-preempted samples cross the 5% frequency boundary, empirical P95 jumps from the normal execution mode into the preempted mode. This **quantile cliff** makes simple state→P95 admission unstable.

See `notes/realtime_nn_machine_state_timing_audit.md`.

## Consequence for the Real-Time NN architecture

The separation of responsibility becomes sharper:

```text
NN:
  obey admitted work cap
  choose useful computation inside that cap

RTOS/runtime:
  provide bounded scheduling/interference conditions
  derive a defensible admissible work budget
```

The NN can reduce its nominal execution window and thereby reduce exposure to interference, but it cannot turn an uncontrolled Linux scheduler into a hard-real-time substrate.

## Next required runtime milestone

Do **not** keep tuning empirical Linux percentiles.

The next runtime-side test should use a controlled scheduling substrate, for example:

- CPU reservation / isolated real-time scheduling;
- a real RTOS or time-predictable embedded target;
- generated analyzable inference code;
- or a formal/probabilistic interference model with explicit assumptions.

Then test:

```text
deadline + bounded interference
       ↓
defensible admitted work budget
       ↓
same Real-Time NN
```

## Readiness labels

- **Direct physical budget execution:** PASS.
- **Learned budget-compliant physical activation:** PASS.
- **Task-loss-only useful-computation selection:** PASS in supplied toy search space.
- **Soft deadline-admission mechanism:** PASS only under empirical central-timing assumptions.
- **Coarse machine-state→P95 admission on ordinary Linux:** FAIL / NOT STABLE.
- **Controlled RTOS/interference-aware admission:** OPEN.
- **Hard real time / WCET:** NOT ESTABLISHED.
- **General self-organized circuit discovery:** NOT ESTABLISHED.
- **Real-Time LM / LLM-scale generalization:** NOT TESTED.

## Recommended framing

**Real-Time Neural Computation: Budget-Conditioned Physical Execution under Runtime Admission**

Any use of “predictable” must distinguish central empirical latency from a formal timing guarantee.
