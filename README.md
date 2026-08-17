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

[`experiments/realtime_nn_budget_execution.py`](experiments/realtime_nn_budget_execution.py) uses one fixed network with eight optional blocks. Budgets `0 / .25 / .5 / .75 / 1.0` physically execute `0 / 2 / 4 / 6 / 8` blocks with the same weights.

Across three seeds:

| budget | active blocks | mean accuracy | hard-skip median | dense-mask median |
|---:|---:|---:|---:|---:|
| 0.00 | 0 | 63.67% | 10.53 us | 409.29 us |
| 0.25 | 2 | 71.48% | 98.80 us | 394.08 us |
| 0.50 | 4 | 78.52% | 185.69 us | 385.65 us |
| 0.75 | 6 | 86.33% | 280.26 us | 377.99 us |
| 1.00 | 8 | 100.00% | 375.82 us | 364.96 us |

Audits:

- hard-skip median latency is strictly increasing in **3/3 seeds**;
- full/minimum-budget median-latency ratio averages **35.73x**;
- hooks verify inactive blocks are not called;
- dense-mask executes all eight blocks at every logical budget;
- hard-skip and dense-mask outputs match.

This directly demonstrates:

```text
smaller budget → less physical work → lower measured median latency → lower quality
```

See [`notes/realtime_nn_budget_execution.md`](notes/realtime_nn_budget_execution.md).

## Milestone 2 — learned activation under a hard runtime cap

[`experiments/realtime_nn_learned_budget_gate.py`](experiments/realtime_nn_learned_budget_gate.py) uses eight optional expert modules. The runtime admits exactly `k ∈ {1,2,4,8}` expert calls. A learned controller chooses **which** experts to execute, while hard top-k structurally prevents it from exceeding the admitted budget.

The controller is deliberately trained with an explicit relevance auxiliary target. This is a controlled mechanism experiment, not a claim of spontaneous/self-organized routing.

Three-seed result:

| k | learned accuracy | fixed-prefix accuracy | learned median | prefix median | dense-mask median |
|---:|---:|---:|---:|---:|---:|
| 1 | 68.35% | 68.77% | 74.62 us | 56.30 us | 354.21 us |
| 2 | **81.90%** | 71.43% | 114.07 us | 95.68 us | 342.64 us |
| 4 | **100.00%** | 78.18% | 195.40 us | 171.37 us | 348.23 us |
| 8 | 100.00% | 100.00% | 366.21 us | 337.42 us | 356.35 us |

Across 3/3 seeds:

- physical execution obeys the hard `k` cap at every budget;
- learned median latency is strictly increasing with `k`;
- dense-mask executes all eight experts;
- controller overhead is included in end-to-end timing.

At `k=4`, learned activation gains about **+21.8 percentage points** over fixed-prefix execution at the same expert-call cap.

See [`notes/realtime_nn_learned_budget_gate.md`](notes/realtime_nn_learned_budget_gate.md).

## Milestone 3 — learned activation + deadline admission

[`experiments/realtime_nn_learned_deadline_integration.py`](experiments/realtime_nn_learned_deadline_integration.py) calibrates empirical P95 timing classes including controller overhead. The runtime chooses the largest admissible `k` for each deadline, then the NN chooses which `k` experts to physically execute.

All policies are tested on the **same absolute deadline within each seed**. Faster policies are allowed to admit larger `k`; equal work is not artificially forced.

The main metric is **on-time & correct rate**.

| deadline regime | learned hard | fixed prefix | external relevance oracle | always full |
|---|---:|---:|---:|---:|
| tightest | 64.50% | **66.00%** | 64.25% | 0.00% |
| around learned `k=2` | **78.08%** | 70.50% | **80.29%** | 2.13% |
| around learned `k=4` | **98.46%** | 76.00% | **98.71%** | 88.29% |
| full-budget | 98.46% | **98.92%** | 97.33% | 98.46% |

Important interpretation:

- learned activation is **not universally better**;
- at the tightest deadline, fixed prefix can admit more work because it avoids controller overhead and slightly wins;
- at full budget, selection has no quality advantage and prefix remains slightly faster;
- in the middle regime, learned activation spends the admitted work on more useful computation and strongly improves on-time-correct rate;
- an external analytic relevance oracle remains slightly better than learned selection in the synthetic task, so no necessity/superiority claim is made for the learned controller.

At the clean `k≈4` regime, learned and prefix miss rates are similar (**1.54% vs 1.21%**) while on-time-correct is **98.46% vs 76.00%**.

See [`notes/realtime_nn_learned_deadline.md`](notes/realtime_nn_learned_deadline.md).

## Timing boundary

All deadline experiments are **empirical P95 soft/weakly-hard prototypes on ordinary Linux/PyTorch**.

The fixed-depth experiment found raw q99 execution classes non-monotonic in 3/3 seeds. The learned experiments also show large high-percentile outliers relative to their median timings. None of this establishes WCET or hard real time.

Hard-RT claims require a time-predictable/RTOS target, controlled interference assumptions, statically analyzable generated code, formal/static WCET, or an equivalent accepted timing argument.

## Current status

Supported in toy systems:

1. same-network budget-conditioned physical execution;
2. actual work and median latency change with admitted budget;
3. quality/latency trade-offs emerge from the same parameter set;
4. logical masking without physical skipping does not obtain the speedup;
5. a learned controller can choose more useful internal work while a hard runtime cap bounds execution;
6. deadline admission can combine runtime work limits with learned internal selection;
7. learned selection is useful mainly in intermediate budget/deadline regimes and does not universally dominate simpler or analytic policies.

Still open:

1. remove explicit relevance supervision and learn useful admissible activation from task loss while preserving the hard work cap;
2. test machine-state-aware runtime admission;
3. test finer-grained structured physical activation;
4. move to a time-predictable/RTOS target or obtain defensible WCET/static timing.

## Secondary diagnostics

Older router/topology experiments remain because they document failure modes relevant to implementation: capability forgetting, shortcut collapse, conditional-subgraph formation, feasibility-vs-price separation, non-separable contract failures, objective/local-minimum sensitivity, policy-parameterization sensitivity, and Linux timing-tail instability.

They are secondary to the direct budget→work→latency→deadline results.

See [`CLAIMS_AND_LIMITS.md`](CLAIMS_AND_LIMITS.md).

## Nonclaims

This repository does not currently claim:

- hard real-time or WCET guarantees;
- a production Real-Time NN or Real-Time LM;
- Joule-level energy savings;
- measured memory-bandwidth or resident-memory reduction;
- arbitrary hardware portability;
- universal superiority over early exit, MoE, NAS, once-for-all networks, or external schedulers;
- autonomous/self-organized relevance discovery in the current learned-controller experiment;
- unconstrained architecture discovery;
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
```

Timing numbers are machine-dependent. Reproduction should focus on physical execution traces, hard budget compliance, work/latency ordering, quality/deadline trade-offs, controller overhead, and dense-mask negative controls.

## Related work

Representative prior work and the novelty boundary are documented in [`RELATED_WORK.md`](RELATED_WORK.md).

## Repository scope

This remains a small mechanism study. Scaling to LLMs, GPUs, or large models is not required for the current research question.

## License

Apache License 2.0. See `LICENSE`.
