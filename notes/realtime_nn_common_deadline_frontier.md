# Common-deadline frontier audit

## Question

The learned-deadline experiment originally used four representative execution-class deadlines. Does the learned mid-budget advantage persist across a denser set of **common absolute deadlines**, or was it an artifact of those four points?

## Method

For each of three seeds:

- calibrate each policy with its own empirical monotone P95 execution-class bounds;
- sweep 25 common absolute deadline points;
- at each deadline, each policy admits the largest `k` fitting its own P95 bound;
- evaluate `on_time_correct_rate` on the same absolute deadline;
- call learned-vs-prefix points matched when mean miss rates differ by at most two percentage points.

Policies are learned hard-skip, fixed-prefix hard-skip, external relevance oracle, dense learned control, and always-full execution.

## Result

Across three seeds:

- **18** common deadline points satisfy the matched-miss rule;
- learned activation has higher on-time-correct at **16/18** of them;
- mean learned-minus-prefix difference is **+9.62 percentage points**;
- median difference is **+11.07 points**;
- maximum is **+20.79 points**;
- minimum is **-1.44 points**.

Representative points:

| mean deadline | learned miss | prefix miss | learned on-time-correct | prefix on-time-correct |
|---:|---:|---:|---:|---:|
| 588 us | 1.25% | 1.40% | **80.10%** | 68.75% |
| 1.217 ms | 0.86% | 1.63% | **94.19%** | 73.40% |
| 1.558 ms | 1.83% | 2.98% | **93.22%** | 79.68% |
| 1.998 ms | 1.00% | 1.14% | **94.05%** | 81.24% |

## Interpretation

The intermediate-work advantage is not confined to the original four deadline points. When learned and prefix miss rates are approximately matched, learned internal selection usually converts the admitted work into more on-time correct answers.

This is still **not universal dominance**. At very tight deadlines controller overhead can make a simpler policy better; at loose/full-work deadlines selection may provide no quality benefit. The analytic relevance oracle also remains a strong external baseline because the synthetic task exposes equivalent relevance information.

## Timing boundary

The sweep uses empirical P95 admission on ordinary Linux/PyTorch, so it is a **soft/weakly-hard comparison**, not WCET or a hard-real-time result.

The separate machine-state timing audit remains authoritative for runtime interference: repeated same-state Linux P95 tables can exhibit scheduler/preemption quantile cliffs and are not stable enough for a hard admission contract. See `notes/realtime_nn_machine_state_timing_audit.md`.
