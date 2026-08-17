# Learned activation + deadline admission

## Question

Can the runtime choose **how much work is admissible** from a deadline, while the NN chooses **which admissible work is useful**, and preserve a useful quality/deadline trade-off after controller overhead is included?

This experiment integrates the learned hard-budget activation model with empirical deadline admission.

```text
deadline
   ↓
runtime P95 execution-class calibration
   ↓
admitted expert-call budget k
   ↓
NN chooses which k experts to execute
   ↓
physical hard-skip inference
```

The experiment remains an ordinary Linux/PyTorch soft/weakly-hard prototype, not WCET or hard real time.

## Policies

All policies see the **same absolute deadline** within a seed.

Each conditional policy calibrates its own empirical P95 execution-class timing and admits the largest `k ∈ {1,2,4,8}` whose monotone P95 bound fits the deadline.

Policies:

1. `learned_hard` — learned relevance controller + physical top-k execution;
2. `prefix_hard` — fixed first-k expert execution with no learned selection;
3. `oracle_hard` — external selector uses the synthetic relevance mask directly; intentionally strong upper baseline;
4. `dense_learned` — learned logical selection, but all eight experts physically execute;
5. `always_full` — always execute all eight experts.

Deadline points are defined from the learned-hard P95 class boundaries, but every policy is evaluated on the exact same resulting deadline. Faster policies may therefore admit a larger `k`; this comparison does not force equal work artificially.

## Three-seed aggregate result

The main combined metric is **on-time & correct rate**: the fraction of requests whose answer is both correct and completed before the deadline.

### Tightest class

| policy | mean admitted k | miss rate | delivered accuracy | on-time & correct |
|---|---:|---:|---:|---:|
| learned hard | 1.00 | 3.88% | 67.17% | 64.50% |
| prefix hard | 2.00 | 7.67% | 71.38% | **66.00%** |
| oracle hard | 1.00 | 4.71% | 67.17% | 64.25% |
| dense learned | none | 100% | 0% | 0% |
| always full | 8 | 100% | 100% | 0% |

The learned controller is **not universally better**. At the tightest deadline, its control overhead prevents admission of `k=2`, while the faster prefix implementation can admit two experts and slightly wins on-time-correct rate.

### Intermediate class around learned k=2

| policy | mean admitted k | miss rate | delivered accuracy | on-time & correct |
|---|---:|---:|---:|---:|
| learned hard | 2.00 | 4.63% | **81.92%** | **78.08%** |
| prefix hard | 2.67 | 3.29% | 72.71% | 70.50% |
| oracle hard | 2.00 | 1.88% | 81.92% | **80.29%** |
| dense learned | none | 100% | 0% | 0% |
| always full | 8 | 97.88% | 100% | 2.13% |

Despite prefix execution admitting an average of **2.67 experts** because it has less control overhead, learned activation still achieves substantially higher on-time-correct rate by spending its smaller admitted work budget on relevant experts.

The external oracle remains better than learned activation. This is expected because the synthetic task exposes the relevance mask directly and the learned controller is trained to recover it. The experiment therefore does **not** claim that a learned controller is necessary when equivalent relevance information is analytically available.

### Intermediate class around learned k=4

| policy | mean admitted k | miss rate | delivered accuracy | on-time & correct |
|---|---:|---:|---:|---:|
| learned hard | 4.00 | 1.54% | **100%** | **98.46%** |
| prefix hard | 4.00 | 1.21% | 76.92% | 76.00% |
| oracle hard | 4.00 | 1.29% | 100% | **98.71%** |
| dense learned | none | 100% | 0% | 0% |
| always full | 8 | 11.71% | 100% | 88.29% |

This is the cleanest current responsibility-split result. At almost the same miss rate and the same admitted expert-call count, the learned network chooses much more useful internal work than fixed prefix execution.

### Full-budget class

At the full-budget deadline, learned selection has no quality advantage because all policies execute all experts. Prefix execution is slightly faster because it avoids controller overhead:

- learned hard on-time-correct: **98.46%**;
- prefix hard: **98.92%**;
- dense learned: **98.50%**;
- always full: **98.46%**.

Again, learned activation is not claimed to dominate at every deadline.

## Physical execution audit

Across all three seeds:

- learned hard executes exactly the admitted `k` experts;
- prefix hard executes exactly `k`;
- oracle hard executes exactly `k`;
- dense learned executes all eight experts regardless of logical budget;
- learned-hard P95 execution-class bounds are monotonic after the conservative envelope.

Controller and admission overhead are included in measured request latency.

## Interpretation

The useful statement is now:

> A runtime can convert a deadline into a hard work allowance, while a learned internal controller spends that allowance on more useful neural computation. In the tested mid-range deadlines this improves the fraction of requests that are both correct and on time, without violating the physical work cap.

The learned controller's value is **conditional**, not universal:

- at very tight deadlines, controller overhead can make a simpler fixed policy better;
- at full budget, selection provides no quality advantage;
- in the middle regime, selective computation provides the strongest benefit.

This is consistent with the Real-Time NN objective: optimize useful neural computation **inside a runtime-enforced feasible work envelope**, rather than maximize a router score.

## Strong external baseline

Because the synthetic input explicitly contains a relevance mask, an external oracle can select the relevant experts directly. It slightly outperforms the learned controller while avoiding some learned-control error/overhead.

Therefore this experiment is a mechanism demonstration, **not evidence that neural selection is superior to an analytic scheduler when the required selection information is already exposed**.

A stronger future task should make useful internal computation latent rather than handing an equivalent relevance label to the runtime/controller.

## Timing boundary

Admission uses empirical P95 timing classes on ordinary Linux/PyTorch. High-percentile calibration remains empirical and machine-dependent.

The earlier fixed-depth experiment already showed q99 non-monotonicity under Linux. In this learned experiment, some q99 class measurements are monotonic but contain millisecond-scale outliers relative to hundreds-of-microseconds medians. This still does not establish WCET or hard real time.

## What this supports

1. deadline → admitted work budget → learned physical activation works in one fixed NN;
2. hard work-cap compliance is preserved;
3. controller overhead can be included in admission calibration;
4. learned selection can improve quality/on-time-correct rate at intermediate deadlines compared with a faster fixed-prefix baseline;
5. physical dense execution fails under tight deadlines even when logical selection is identical;
6. learned selection is not universally dominant, and an analytic relevance oracle remains a stronger baseline in this synthetic task.

## Next experiment

Remove the explicit relevance-supervision crutch while keeping the same systems contract:

```text
runtime admits k
NN learns which k modules are useful from task loss
physical execution may not exceed k
```

The success metrics remain quality, physical budget compliance, measured latency, and deadline behavior—not router accuracy.
