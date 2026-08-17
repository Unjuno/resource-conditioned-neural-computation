# Claims and limits

## Core Real-Time NN mechanism supported in toy experiments

The strongest supported statement is now:

> In supplied toy architectures, one fixed neural network can receive a runtime-admitted work budget, physically execute only budget-compliant internal computation, and produce a reproducible quality/work/median-latency trade-off. A learned internal controller can choose **which** admissible computation to execute, and an empirical runtime can combine that selection with deadline-based work admission.

This is **not** a hard-real-time/WCET claim.

## Direct budget → physical work → latency evidence

Across three seeds in `experiments/realtime_nn_budget_execution.py`:

- the same parameter set is used at all budgets;
- budgets `0 / .25 / .5 / .75 / 1.0` physically execute `0 / 2 / 4 / 6 / 8` optional blocks;
- hooks verify inactive blocks are not called;
- a dense-mask control executes all eight blocks at every logical budget;
- mean accuracy is **63.67% → 71.48% → 78.52% → 86.33% → 100%**;
- mean hard-skip median latency is **10.53 → 98.80 → 185.69 → 280.26 → 375.82 us**;
- median latency is strictly monotonic in **3/3 seeds**;
- full/minimum-budget median-latency ratio averages **35.73x**.

This establishes:

```text
budget → physical activation → work → measured median latency → quality
```

## Learned activation under a hard runtime cap

`experiments/realtime_nn_learned_budget_gate.py` lets the runtime admit exactly `k ∈ {1,2,4,8}` expert calls. A learned relevance controller chooses which experts to execute, while hard top-k structurally prevents execution beyond the admitted cap.

The controller uses explicit relevance supervision; this is not claimed as spontaneous/self-organized routing.

Across three seeds:

- hard budget compliance passes at every k;
- learned median latency is strictly monotonic in **3/3 seeds**;
- at `k=2`, learned accuracy is **81.90%** versus **71.43%** for fixed prefix;
- at `k=4`, learned accuracy is **100%** versus **78.18%** for fixed prefix;
- controller overhead is measurable and included in the reported end-to-end timing.

This supports:

```text
runtime / RTOS: how much work is admissible
NN:             which admissible internal work is useful
```

## Learned activation + deadline admission

`experiments/realtime_nn_learned_deadline_integration.py` calibrates policy-specific empirical P95 execution classes including controller overhead. All policies are evaluated on the same absolute deadline within each seed.

A faster policy is allowed to admit a larger `k`; equal work is not forced artificially.

Main combined metric: **on-time & correct rate**.

Three-seed aggregate:

| deadline regime | learned hard | fixed prefix | external relevance oracle | always full |
|---|---:|---:|---:|---:|
| tightest | 64.50% | **66.00%** | 64.25% | 0.00% |
| around learned `k=2` | **78.08%** | 70.50% | **80.29%** | 2.13% |
| around learned `k=4` | **98.46%** | 76.00% | **98.71%** | 88.29% |
| full-budget | 98.46% | **98.92%** | 97.33% | 98.46% |

At the `k≈4` regime:

- learned miss rate: **1.54%**;
- fixed-prefix miss rate: **1.21%**;
- learned on-time-correct: **98.46%**;
- fixed-prefix on-time-correct: **76.00%**.

At the `k≈2` regime, learned selection reaches **78.08%** on-time-correct versus **70.50%** for prefix, even though prefix admits an average **2.67 experts** versus learned `k=2` because prefix avoids controller overhead.

This is the strongest current systems result for learned internal selection under a deadline.

## Important negative / boundary results

Learned activation is **not universally dominant**:

1. at the tightest deadline, fixed prefix slightly wins on-time-correct (**66.00% vs 64.50%**) because controller overhead prevents the learned policy from admitting as much work;
2. at full budget, fixed prefix is slightly better because all experts execute and selection adds only overhead;
3. an external relevance oracle slightly outperforms learned selection in the middle regimes because the synthetic task directly exposes the relevance mask;
4. therefore the current experiment does **not** show that a learned controller is necessary or superior when equivalent selection information is analytically available.

The useful learned regime is the intermediate budget/deadline range where selective internal computation improves quality enough to compensate for controller overhead.

## Timing boundary

Deadline admission uses empirical P95 timing classes on ordinary Linux/PyTorch.

The fixed-depth experiment shows raw q99 execution-class timing is non-monotonic in all three calibration seeds. The learned experiments also exhibit large high-percentile outliers relative to median timing.

A hard-real-time claim still requires defensible WCET/static timing, a time-predictable runtime/platform, controlled RTOS interference assumptions, or equivalent evidence.

## What remains open

1. remove explicit relevance supervision and learn useful admissible activation from task loss while preserving the hard work cap;
2. test a task where useful computation is not exposed as an analytic relevance mask;
3. adapt admitted budgets to machine state without relying on unstable Linux tails;
4. test finer-grained structured physical activation;
5. move to an RTOS/time-predictable target or obtain a defensible WCET/static timing argument.

## Secondary diagnostic evidence

Earlier router/topology experiments remain useful for capability forgetting, shortcut collapse, conditional-subgraph formation, feasibility-vs-price separation, non-separable resource-contract failures, objective/local-minimum sensitivity, policy-parameterization sensitivity, and Linux tail-timing instability.

They are secondary to the direct budget/work/latency/deadline results.

## Runtime / RTOS responsibility split

```text
hardware / OS state
    ↓
runtime / RTOS timing/admission model
    ↓
safe admitted work budget
    ↓
same neural network
    ↓
budget-compliant learned physical execution
```

The runtime owns hardware-specific timing knowledge and feasibility. The NN chooses computation only inside the admitted work envelope.

## Resource proxies

The direct experiments use executed expert/block counts, linear-MAC proxies, and measured latency. Older experiments may also use a parameter-footprint proxy.

Parameter footprint is **not** measured runtime memory traffic, bandwidth, cache pressure, reduced resident memory, or energy.

## Explicitly not claimed

1. Hard real-time guarantees or WCET bounds.
2. A production Real-Time NN or Real-Time LM.
3. Joule-level energy savings.
4. Measured memory-bandwidth savings or reduced total resident memory.
5. Autonomous/self-organized relevance discovery in the current learned-controller task.
6. Universal superiority over fixed-prefix execution or external analytic scheduling.
7. Necessity of a learned controller when exact relevance/cost information is available.
8. General/unconstrained architecture discovery.
9. Arbitrary hardware portability.
10. LLM-scale generalization.
11. Novelty of LUT neurons/networks, dynamic routing, NAS, or runtime subnetwork switching.

## Direction lock

Before promoting a new main-line experiment, ask:

> Does it test whether changing the admitted budget of the **same neural network** changes **actual internal activation**, **actual executed work**, **actual inference time**, **quality**, or **deadline behavior**?

If not, it belongs under secondary diagnostics.
