# Task-loss-only budget-compliant activation

## Question

Can useful internal computation be learned **without explicit relevance supervision**, while retaining the Real-Time NN systems contract?

```text
runtime admits hard work cap k
    ↓
NN learns which k internal modules are useful from task loss
    ↓
only those k modules physically execute
    ↓
measured latency remains budget-ordered
```

The evaluation remains based on task quality, physical budget compliance, measured timing, and deadline behavior—not controller classification accuracy.

## Task

Each input contains eight slots. Every slot has:

- a binary value;
- a categorical key.

A global categorical query is also provided. Exactly four slots have `key == query`. The label is the strict majority of the bits in those four matching slots.

The controller receives key/query features but **never receives a relevance label or relevance auxiliary loss**. Ground-truth relevance is used only after training for audit and for a strong analytic oracle baseline.

## Training

One fixed network contains eight optional expert modules, a small controller, and a shared head.

Training uses only task cross-entropy across `k ∈ {1,2,4,8}`. A straight-through hard-top-k surrogate supplies gradients to the controller during training.

There is:

- no relevance-supervision loss;
- no capability warmup/pretraining stage;
- no expert freezing.

Inference uses actual hard top-k physical execution, so the runtime cap is structural.

## Three-seed quality result

| k | learned | fixed prefix | analytic relevance oracle | learned selected-relevance fraction |
|---:|---:|---:|---:|---:|
| 1 | 69.04% | 67.66% | 69.09% | **100%** |
| 2 | **81.27%** | 71.37% | 81.80% | **100%** |
| 4 | **100.00%** | 78.74% | 100.00% | **100%** |
| 8 | 99.82% | 99.82% | 99.82% | 50% |

Thus, in all three seeds, task loss alone is sufficient for the controller to recover the useful key-query matching computation in this supplied toy search space.

This is stronger than the previous explicitly supervised relevance controller, but it is still **not** unconstrained architecture discovery. The primitive experts, hard top-k execution mechanism, task structure, and search space are supplied.

## Physical timing result

Mean batch-1 medians across three seeds:

| k | learned hard | fixed prefix | analytic oracle | dense learned |
|---:|---:|---:|---:|---:|
| 1 | 77.49 us | 54.22 us | 64.02 us | 301.19 us |
| 2 | 110.47 us | 87.22 us | 98.16 us | 307.53 us |
| 4 | 176.97 us | 152.80 us | 162.61 us | 309.64 us |
| 8 | 314.04 us | 294.54 us | 301.58 us | 302.37 us |

Across 3/3 seeds:

- learned hard execution calls exactly `k` experts;
- fixed-prefix and oracle hard execution also call exactly `k`;
- dense learned execution calls all eight experts at every logical budget;
- learned hard median latency is strictly increasing with `k`.

Hard learned and dense learned outputs agree to about `1.5e-6` maximum absolute difference in the audit, attributable to floating-point summation order.

The controller adds roughly 20–25 us median latency relative to fixed prefix at the same k.

## Deadline behavior

A follow-up empirical P95 admission test uses common deadlines within each seed and policy-specific timing calibration.

Mean on-time & correct rate:

| target learned class | learned | prefix | oracle | dense learned | always full |
|---:|---:|---:|---:|---:|---:|
| 1 | 67.60% | **76.93%** | **79.47%** | 0.00% | 31.20% |
| 2 | 75.93% | **82.27%** | **89.73%** | 33.27% | 72.87% |
| 4 | **98.27%** | 85.13% | 97.47% | 33.20% | 91.40% |
| 8 | 96.53% | 85.13% | **98.13%** | 62.00% | 95.93% |

This result is deliberately interpreted conservatively.

The task-only learned controller **does not dominate** the faster prefix/oracle baselines under tight deadlines. Controller overhead lets simpler policies admit more work, which can outweigh smarter selection.

The clearest learned benefit is around the `k≈4` regime, where learned selection reaches full task quality without executing all eight experts.

The per-seed P95 admission boundaries are themselves noisy enough that high-budget admissions differ between seeds. This reinforces that ordinary Linux timing is a soft/weakly-hard prototype only.

## High-percentile negative result

Raw q99 learned-hard timing is strictly monotonic in only **1/3 seeds** in this run. Some policies show millisecond-scale outliers while medians remain in the tens-to-hundreds of microseconds.

Therefore:

- central timing classes are reproducible enough for this toy mechanism study;
- far-tail timing remains unsuitable as WCET evidence;
- no hard-real-time claim follows from the task-only controller result.

## What this supports

A stronger but still narrow mechanism statement is now supported:

> Within a supplied fixed search space and a hard runtime work cap, a neural system can learn from task loss alone which admissible internal computations are useful, physically skip the rest at inference, and preserve a budget-dependent measured-latency relation.

## What this does not support

- hard real time / WCET;
- universal learned-policy superiority;
- absence of an analytic external alternative in this synthetic task;
- general self-organized architecture discovery;
- arbitrary input-difficulty routing;
- energy or memory-bandwidth savings;
- LLM-scale generalization.

## Next step

The next useful falsification is to make the useful-computation structure less analytically exposed while keeping the same hard systems contract, or to move the current mechanism onto a time-predictable/RTOS substrate.

Do not return to optimizing route scores independently of actual physical timing.
