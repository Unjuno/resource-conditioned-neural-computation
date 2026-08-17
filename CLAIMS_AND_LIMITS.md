# Claims and limits

## Core Real-Time NN mechanism supported in toy experiments

The strongest supported statement is now:

> In supplied toy architectures, one fixed neural network can receive a runtime-admitted work budget, physically execute only budget-compliant internal computation, and produce a reproducible quality/work/median-latency trade-off. Useful admissible internal computation can be selected by a learned controller, including a tested case trained from **task loss alone** without explicit relevance labels.

This is **not** a hard-real-time/WCET claim.

## Direct physical budget execution

Across three seeds in `realtime_nn_budget_execution.py`:

- budgets `0 / .25 / .5 / .75 / 1.0` physically execute `0 / 2 / 4 / 6 / 8` optional blocks using the same parameters;
- hooks verify inactive blocks are not called;
- hard-skip median latency is strictly monotonic in 3/3 seeds;
- mean accuracy increases from **63.67% to 100%**;
- mean median latency increases from **10.53 us to 375.82 us**;
- dense logical masking executes all blocks and does not obtain the same speedup.

## Learned selection under a hard runtime cap

The runtime admits exactly `k ∈ {1,2,4,8}` expert calls. Hard top-k structurally prevents the learned controller from exceeding the cap.

The explicitly supervised controller reaches 100% accuracy at `k=4` versus 78.18% for fixed prefix, while controller overhead is retained in timing.

A deadline integration uses policy-specific empirical P95 timing classes and common absolute deadlines. At the clean `k≈4` regime, learned and prefix miss rates are similar (**1.54% vs 1.21%**) while on-time-correct is **98.46% vs 76.00%**.

Learned control is not universally better: tight/full-budget regimes can favor a simpler prefix policy, and an external analytic relevance oracle remains a strong baseline.

## Task-loss-only learned activation

`experiments/realtime_nn_task_only_gate.py` removes the explicit relevance loss and capability warmup.

Task structure:

- eight slots with categorical keys;
- one global query;
- exactly four key-query matches;
- label is the strict majority of matching-slot bits.

The controller receives normal task features but no relevance labels. The whole model is trained from scratch with task cross-entropy using a straight-through hard-top-k surrogate.

Three-seed mean result:

| k | task-loss learned | fixed prefix | analytic oracle | selected relevance |
|---:|---:|---:|---:|---:|
| 1 | 69.04% | 67.66% | 69.09% | **100%** |
| 2 | **81.27%** | 71.37% | 81.80% | **100%** |
| 4 | **100.00%** | 78.74% | 100.00% | **100%** |
| 8 | 99.82% | 99.82% | 99.82% | 50% |

Physical timing:

- learned median: **77.49 / 110.47 / 176.97 / 314.04 us** for `k=1/2/4/8`;
- median latency is strictly monotonic in 3/3 seeds;
- hard cap compliance passes in 3/3 seeds;
- dense learned execution stays near full-compute latency because all eight experts run.

This supports the narrow statement:

> Within a supplied fixed search space and a structural runtime work cap, useful budget-compliant internal computation can be learned from task loss alone while preserving physical skipping and a measured budget/latency relation.

It does **not** establish general self-organized architecture discovery.

## Deadline boundary for the task-only controller

The task-only learned controller is also not universally best under soft deadline admission.

Mean on-time & correct rate:

| target class | learned | prefix | analytic oracle | always full |
|---:|---:|---:|---:|---:|
| 1 | 67.60% | 76.93% | **79.47%** | 31.20% |
| 2 | 75.93% | 82.27% | **89.73%** | 72.87% |
| 4 | **98.27%** | 85.13% | 97.47% | 91.40% |
| 8 | 96.53% | 85.13% | **98.13%** | 95.93% |

Controller overhead and noisy empirical admission allow simpler/oracle policies to win under some deadlines. The learned benefit is strongest near the intermediate `k≈4` regime.

## Timing boundary

All current deadline results are empirical P95 soft/weakly-hard prototypes on ordinary Linux/PyTorch.

- the fixed-depth experiment has non-monotonic q99 classes in 3/3 seeds;
- task-only learned-hard q99 is monotonic in only **1/3 seeds**;
- millisecond-scale high-percentile outliers occur while medians remain tens/hundreds of microseconds.

A hard-real-time claim requires defensible WCET/static timing, a time-predictable runtime/platform, controlled RTOS interference assumptions, or equivalent evidence.

## What remains open

1. make useful internal computation less analytically exposed than the current key/query task;
2. test machine-state-aware runtime admission;
3. test finer-grained structured physical activation;
4. move to an RTOS/time-predictable target or obtain defensible WCET/static timing;
5. later test sequence-model/LM applicability without making scale itself the objective.

## Secondary diagnostic evidence

Earlier router/topology experiments remain useful for capability forgetting, shortcut collapse, conditional-subgraph formation, feasibility-vs-price separation, non-separable contract failures, optimization sensitivity, policy-parameterization sensitivity, and Linux tail-timing instability.

They are secondary to the direct budget/work/latency/deadline chain.

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

The runtime owns hardware-specific feasibility. The NN chooses computation only inside the admitted envelope.

## Explicitly not claimed

1. Hard real-time guarantees or WCET bounds.
2. A production Real-Time NN or Real-Time LM.
3. Joule-level energy savings or measured memory-bandwidth reduction.
4. Universal superiority over fixed policies or analytic schedulers.
5. Necessity of a learned controller when exact useful-computation information is analytically available.
6. General/unconstrained self-organized architecture discovery.
7. Arbitrary hardware portability.
8. LLM-scale generalization.
9. Novelty of LUT neurons/networks, dynamic routing, NAS, or runtime subnetwork switching.

## Direction lock

Before promoting a new main-line experiment, ask:

> Does it test whether changing the admitted budget of the **same neural network** changes **actual internal activation**, **actual executed work**, **actual inference time**, **quality**, or **deadline behavior**?

If not, it belongs under secondary diagnostics.
