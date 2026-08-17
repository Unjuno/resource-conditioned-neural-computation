# Resource-Conditioned Neural Computation — Readiness Report

## Current status

The repository has now passed four toy-system mechanism gates for the intended Real-Time NN direction:

1. direct budget-conditioned physical execution;
2. learned selection of admissible work under a hard runtime cap;
3. learned activation integrated with empirical deadline admission;
4. useful admissible activation learned from **task loss alone**, without explicit relevance labels.

The demonstrated toy chain is:

```text
deadline / admitted work budget
  → budget-compliant learned internal activation
  → physically executed work
  → measured latency
  → task quality / on-time quality
```

**Hard-real-time readiness is still not reached.** Current timing is ordinary Linux/PyTorch and remains empirical rather than WCET.

## New milestone — task-loss-only selection

`experiments/realtime_nn_task_only_gate.py` uses an 8-slot key/query task. Exactly four slots match a global query; the label is the strict majority of matching-slot bits.

The controller receives ordinary task features but no relevance targets. Training uses task cross-entropy only, with no relevance auxiliary loss, capability warmup, or expert freezing.

Three-seed mean result:

| k | learned | prefix | analytic oracle | learned relevance fraction |
|---:|---:|---:|---:|---:|
| 1 | 69.04% | 67.66% | 69.09% | 100% |
| 2 | **81.27%** | 71.37% | 81.80% | 100% |
| 4 | **100.00%** | 78.74% | 100.00% | 100% |
| 8 | 99.82% | 99.82% | 99.82% | 50% |

Hard budget compliance passes in 3/3 seeds. Learned hard-skip median latency is strictly monotonic in 3/3 seeds:

**77.49 / 110.47 / 176.97 / 314.04 us** for `k=1/2/4/8`.

Thus the current supplied search space no longer requires an explicit relevance-teaching signal for useful physical conditional computation to emerge.

This is still not unconstrained self-organized architecture discovery: the primitive experts, hard top-k mechanism, and task structure are supplied, and an analytic key/query oracle exists.

## Deadline boundary

The task-only controller is not universally superior under deadline admission.

Mean on-time & correct:

| target class | learned | prefix | oracle | always full |
|---:|---:|---:|---:|---:|
| 1 | 67.60% | 76.93% | **79.47%** | 31.20% |
| 2 | 75.93% | 82.27% | **89.73%** | 72.87% |
| 4 | **98.27%** | 85.13% | 97.47% | 91.40% |
| 8 | 96.53% | 85.13% | **98.13%** | 95.93% |

The learned benefit is strongest in the intermediate `k≈4` regime. Under tight deadlines, controller overhead lets simpler/faster policies admit more work and win.

## Timing boundary

The fixed-depth experiment has non-monotonic q99 timing in 3/3 seeds. Task-only learned-hard q99 is monotonic in only **1/3 seeds**, with high-percentile outliers far above the median.

All deadline results remain **empirical soft/weakly-hard**. WCET/hard real time is not established.

## What remains before a stronger claim

1. make useful internal computation less analytically exposed than the current key/query task;
2. add machine-state-aware budget admission;
3. test structured finer-grained physical activation;
4. move to an RTOS/time-predictable target or obtain defensible static/formal WCET;
5. later test the mechanism in sequence models without making scale itself the goal.

## Readiness labels

- **Direct physical budget execution:** PASS.
- **Learned budget-compliant physical activation:** PASS.
- **Learned activation + soft deadline admission:** PASS with empirical-timing caveat.
- **Task-loss-only useful-computation selection:** PASS in the supplied toy search space.
- **General/unconstrained self-organized circuit discovery:** NOT ESTABLISHED.
- **Machine-state-aware admission:** OPEN.
- **Hard real time / WCET:** NOT ESTABLISHED.
- **Real-Time LM / LLM-scale generalization:** NOT TESTED.

## Recommended framing

**Real-Time Neural Computation: Budget-Conditioned Internal Activation for Predictable Inference Time**

“Predictable” currently means observed/calibratable central timing behavior, not a formal WCET guarantee.
