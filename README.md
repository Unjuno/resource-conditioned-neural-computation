# Resource-Conditioned Neural Computation

A falsification-oriented study toward a **Real-Time Neural Network (Real-Time NN)**: one fixed neural network whose physically executed internal computation changes under a runtime-admitted work/time budget.

## Research target

```text
RTOS / runtime
    ↓
deadline + machine state
    ↓
safe admitted work budget
    ↓
the same neural-network parameters
    ↓
budget-compliant internal activation
    ↓
actual executed work changes
    ↓
actual inference latency changes
    ↓
deadline behavior
```

The runtime owns **how much work is admissible**. The NN may learn **which admissible internal computation is useful**. A gate/controller is an implementation mechanism, not the research target.

See [`REALTIME_NN_DIRECTION.md`](REALTIME_NN_DIRECTION.md).

## Milestone 1 — direct budget → physical work → latency

One fixed network physically executes `0 / 2 / 4 / 6 / 8` optional blocks at increasing budgets.

Across three seeds, mean accuracy changes from **63.67% → 71.48% → 78.52% → 86.33% → 100%**, while hard-skip median latency changes from **10.53 → 98.80 → 185.69 → 280.26 → 375.82 us**.

Hard-skip latency is strictly monotonic in 3/3 seeds; dense logical masking executes all blocks and does not obtain the speedup.

See [`notes/realtime_nn_budget_execution.md`](notes/realtime_nn_budget_execution.md).

## Milestone 2 — learned activation under a hard runtime cap

The runtime admits exactly `k ∈ {1,2,4,8}` expert calls. A learned controller chooses **which** experts to execute, while hard top-k structurally prevents work beyond the admitted cap.

With explicit relevance auxiliary supervision, three-seed mean accuracy is:

| k | learned | fixed prefix |
|---:|---:|---:|
| 1 | 68.35% | 68.77% |
| 2 | **81.90%** | 71.43% |
| 4 | **100.00%** | 78.18% |
| 8 | 100.00% | 100.00% |

Physical budget compliance and monotonic median timing pass in 3/3 seeds; controller overhead is included.

See [`notes/realtime_nn_learned_budget_gate.md`](notes/realtime_nn_learned_budget_gate.md).

## Milestone 3 — learned activation + deadline admission

Empirical P95 timing classes include controller overhead. The runtime admits `k` from a deadline, then the NN chooses which `k` experts to physically execute.

Mean **on-time & correct** rate across three seeds:

| deadline regime | learned | fixed prefix | external relevance oracle | always full |
|---|---:|---:|---:|---:|
| tightest | 64.50% | **66.00%** | 64.25% | 0.00% |
| around learned `k=2` | **78.08%** | 70.50% | **80.29%** | 2.13% |
| around learned `k=4` | **98.46%** | 76.00% | **98.71%** | 88.29% |
| full-budget | 98.46% | **98.92%** | 97.33% | 98.46% |

Learned control is not universally better: overhead hurts at the tightest/full regimes, and an analytic relevance oracle remains a strong baseline.

See [`notes/realtime_nn_learned_deadline.md`](notes/realtime_nn_learned_deadline.md).

## Milestone 4 — task-loss-only learned activation

[`experiments/realtime_nn_task_only_gate.py`](experiments/realtime_nn_task_only_gate.py) removes the explicit relevance-supervision loss.

The task contains categorical slot keys and a global query. Exactly four slots match the query; the label is the strict majority of the matching-slot bits. The controller receives the ordinary task features but **no relevance labels**. The entire model is trained from scratch using task cross-entropy only; there is no capability warmup or expert freezing.

Three-seed mean result:

| k | task-loss learned | fixed prefix | analytic key/query oracle | selected relevance |
|---:|---:|---:|---:|---:|
| 1 | 69.04% | 67.66% | 69.09% | **100%** |
| 2 | **81.27%** | 71.37% | 81.80% | **100%** |
| 4 | **100.00%** | 78.74% | 100.00% | **100%** |
| 8 | 99.82% | 99.82% | 99.82% | 50% |

Mean hard-skip medians are **77.49 / 110.47 / 176.97 / 314.04 us** for `k=1/2/4/8`, strictly monotonic in 3/3 seeds. Dense learned execution remains around **301–310 us** because all experts physically execute.

Thus, in this supplied toy search space, **task loss alone is sufficient to learn which budget-compliant internal computations are useful**, while inference still obeys the runtime work cap.

This is not unconstrained architecture discovery. The expert search space, top-k mechanism, task structure, and analytic key/query oracle are supplied.

The task-only controller also does not universally dominate under deadline admission: tighter deadlines favor simpler/faster prefix or oracle policies. Around the learned `k≈4` regime, however, task-only learned activation reaches **98.27% on-time & correct** versus **85.13%** for prefix.

See [`notes/realtime_nn_task_only_gate.md`](notes/realtime_nn_task_only_gate.md).

## Timing boundary

All current deadline experiments are **empirical soft/weakly-hard prototypes on ordinary Linux/PyTorch**.

The fixed-depth experiment found non-monotonic q99 classes in 3/3 seeds. In the task-only learned experiment, raw learned-hard q99 is monotonic in only **1/3 seeds**. Some high-percentile samples are millisecond-scale while medians are tens to hundreds of microseconds.

None of this establishes WCET or hard real time.

Hard-RT claims require a time-predictable/RTOS target, controlled interference assumptions, statically analyzable generated code, formal/static WCET, or an equivalent accepted timing argument.

## Current status

Supported in toy systems:

1. same-network budget-conditioned physical execution;
2. actual work and measured median latency change with admitted budget;
3. quality/latency trade-offs emerge from one parameter set;
4. dense logical masking without physical skipping does not obtain the speedup;
5. hard runtime work caps can coexist with learned internal computation selection;
6. learned selection can be integrated with deadline admission;
7. useful budget-compliant activation can be learned from **task loss alone** in the supplied toy search space;
8. learned policies are beneficial only in some budget/deadline regimes and do not universally dominate simpler or analytic alternatives.

Still open:

1. make useful internal computation less analytically exposed than the current key/query toy;
2. test machine-state-aware runtime admission;
3. test finer-grained structured physical activation;
4. move to a time-predictable/RTOS target or obtain defensible WCET/static timing;
5. eventually test whether the same systems principle remains useful in larger sequence models—without making scale itself the objective.

## Secondary diagnostics

Older router/topology experiments remain because they document capability forgetting, shortcut collapse, conditional-subgraph formation, feasibility-vs-price separation, non-separable contract failures, optimization sensitivity, policy-parameterization sensitivity, and Linux timing-tail instability.

They are secondary to the direct budget→physical work→latency→deadline chain.

See [`CLAIMS_AND_LIMITS.md`](CLAIMS_AND_LIMITS.md).

## Nonclaims

This repository does not currently claim:

- hard real-time or WCET guarantees;
- a production Real-Time NN or Real-Time LM;
- Joule-level energy savings;
- measured memory-bandwidth or resident-memory reduction;
- arbitrary hardware portability;
- universal superiority over early exit, MoE, NAS, once-for-all networks, fixed policies, or external schedulers;
- general/unconstrained self-organized architecture discovery;
- LLM-scale generalization;
- novelty of LUT neurons/networks, dynamic routing, NAS, or runtime subnetwork switching.

## Reproduce primary experiments

```bash
python -m venv .venv
source .venv/bin/activate
pip install -r requirements.txt
python experiments/realtime_nn_budget_execution.py
python experiments/realtime_nn_learned_budget_gate.py
python experiments/realtime_nn_learned_deadline_integration.py
python experiments/realtime_nn_task_only_gate.py
```

Timing numbers are machine-dependent. Reproduction should focus on physical execution traces, hard budget compliance, task quality under budget, work/latency ordering, controller overhead, deadline behavior, and dense/analytic controls.

## Related work

Representative prior work and the novelty boundary are documented in [`RELATED_WORK.md`](RELATED_WORK.md).

## Repository scope

This remains a small mechanism study. Scaling to LLMs, GPUs, or large models is not required for the current research question.

## License

Apache License 2.0. See `LICENSE`.
