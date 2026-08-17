# Resource-Conditioned Neural Computation

A falsification-oriented study toward a **Real-Time Neural Network (Real-Time NN)**: one fixed neural parameter set whose physically executed internal computation changes under a runtime-admitted work/time budget.

## Research target

```text
RTOS / runtime
    ↓
deadline + bounded machine/interference state
    ↓
safe admitted work budget
    ↓
same neural-network parameters
    ↓
budget-compliant internal activation
    ↓
actual executed work
    ↓
actual inference latency
    ↓
deadline behavior
```

The runtime owns **how much work is admissible**. The NN may learn **which admissible internal computation is useful**. Controllers/gates are implementation mechanisms, not the research target.

See [`REALTIME_NN_DIRECTION.md`](REALTIME_NN_DIRECTION.md).

## Primary mechanism evidence

### 1. Budget changes physical work and measured latency

One fixed network physically executes `0 / 2 / 4 / 6 / 8` optional blocks at increasing budgets.

Across three seeds:

- mean accuracy: **63.67% → 71.48% → 78.52% → 86.33% → 100%**;
- hard-skip median latency: **10.53 → 98.80 → 185.69 → 280.26 → 375.82 us**;
- median latency is strictly monotonic in **3/3 seeds**;
- a dense-mask control executes all blocks and does not obtain the speedup.

See [`notes/realtime_nn_budget_execution.md`](notes/realtime_nn_budget_execution.md).

### 2. Learned selection inside a hard runtime cap

The runtime admits exactly `k ∈ {1,2,4,8}` expert calls. Hard top-k structurally prevents the NN from exceeding the admitted work cap.

With an explicitly supervised controller, `k=4` reaches **100% accuracy** versus **78.18%** for fixed-prefix execution at the same expert-call cap. Controller overhead is included in timing.

See [`notes/realtime_nn_learned_budget_gate.md`](notes/realtime_nn_learned_budget_gate.md).

### 3. Learned selection + empirical deadline admission

Policy-specific empirical P95 timing classes include controller overhead. All policies are evaluated on the same absolute deadline within each seed.

At an intermediate `k≈4` regime:

- learned miss rate: **1.54%**;
- fixed-prefix miss rate: **1.21%**;
- learned on-time & correct: **98.46%**;
- fixed-prefix on-time & correct: **76.00%**.

Learned control is **not universally better**: tight/full-budget regimes can favor the simpler prefix policy, and an external analytic relevance oracle remains a strong baseline.

See [`notes/realtime_nn_learned_deadline.md`](notes/realtime_nn_learned_deadline.md).

### 4. Task-loss-only budget-compliant activation

The explicit relevance-supervision loss was then removed. The entire model is trained from scratch from task cross-entropy only; there is no relevance auxiliary loss, capability warmup, or expert freezing.

Three-seed mean result:

| k | task-loss learned | fixed prefix | analytic oracle | selected useful fraction |
|---:|---:|---:|---:|---:|
| 1 | 69.04% | 67.66% | 69.09% | 100% |
| 2 | **81.27%** | 71.37% | 81.80% | 100% |
| 4 | **100.00%** | 78.74% | 100.00% | 100% |
| 8 | 99.82% | 99.82% | 99.82% | 50% |

Learned hard-skip medians are **77.49 / 110.47 / 176.97 / 314.04 us** for `k=1/2/4/8`, strictly monotonic in **3/3 seeds**. Dense learned execution stays near full-compute latency because all experts physically execute.

This supports task-loss-only useful-computation selection **inside the supplied hard-cap search space**. It is not a claim of unconstrained architecture discovery, and an analytic key/query oracle exists for this synthetic task.

See [`notes/realtime_nn_task_only_gate.md`](notes/realtime_nn_task_only_gate.md).

## Runtime machine-state falsification: empirical P95 tables are not stable on ordinary Linux

The next runtime hypothesis was:

```text
observed machine state
    → empirical P95 execution-class table
    → admitted budget
```

An initial run appeared positive, but an independent repeat contradicted it. The positive interpretation was therefore rejected and the timing table itself was audited.

Two model seeds were each measured under `idle`, periodic same-core load, and continuous same-core contention. Budgets were randomly interleaved; each state was recalibrated six times.

Maximum repeated P95 coefficient of variation:

- idle: **0.321**;
- periodic load: **0.092**;
- continuous same-core busy load: **0.990**.

Under continuous busy load, nominally identical repeated calibrations can move an execution-class P95 by several milliseconds. For example:

- seed 0, `B=.5`: **551 us → 4.30 ms**;
- seed 1, `B=.25`: **233 us → 4.16 ms**;
- seed 1, `B=.5`: **561 us → 4.29 ms**.

A larger 1,800-sample-per-budget probe exposes a **quantile cliff**:

| budget | median | P95 | fraction > 4 ms |
|---:|---:|---:|---:|
| .25 | 103 us | 381 us | 3.00% |
| .50 | 189 us | **8.38 ms** | **6.94%** |
| .75 | 279 us | 8.49 ms | 9.22% |
| 1.00 | 378 us | 8.63 ms | 11.72% |

At `B=.5`, scheduler-preempted requests cross the 5% frequency boundary, so empirical P95 jumps from the fast execution mode into the preempted mode. Small run-to-run changes in preemption probability can therefore move P95 discontinuously even when the neural execution class is unchanged.

**Conclusion:** a coarse categorical `machine state → one empirical P95 table` is **not** established as a stable runtime contract on ordinary Linux.

Lower neural budgets still reduce nominal execution time and the observed exposure window for scheduler interference, but the NN cannot provide hard timing guarantees without scheduler/runtime control.

See [`notes/realtime_nn_machine_state_timing_audit.md`](notes/realtime_nn_machine_state_timing_audit.md).

## Timing boundary

All current deadline experiments are **soft/weakly-hard empirical prototypes** on ordinary Linux/PyTorch.

The evidence repeatedly shows that central latency can be well ordered while high-percentile timing is contaminated by preemption/outlier modes. Empirical P95/P99 is not WCET.

A hard-RT claim requires a controlled scheduling substrate and a defensible timing argument, for example:

- RTOS CPU reservation / bounded interference assumptions;
- statically analyzable generated inference code;
- time-predictable hardware/runtime;
- formal/static WCET or an accepted probabilistic real-time model with explicit assumptions.

## Current status

Supported in toy systems:

1. budget changes **physical** internal execution in one fixed NN;
2. executed work and measured median latency change with budget;
3. quality/latency trade-offs emerge from the same parameters;
4. hard runtime work caps can coexist with learned internal selection;
5. learned selection can be integrated with soft deadline admission;
6. useful budget-compliant selection can be learned from task loss alone in a supplied search space;
7. simpler or analytic policies can still be better in some deadline regimes;
8. uncontrolled Linux machine-state timing cannot be reduced to a stable empirical P95 table.

Open:

1. move the runtime experiment to a controlled RTOS/time-predictable scheduling substrate;
2. derive or measure a defensible interference/WCET admission model;
3. make useful internal computation less analytically exposed than the current toy;
4. test structured finer-grained physical activation;
5. later test sequence-model applicability without making scale itself the objective.

## Secondary diagnostics

Older router/topology experiments remain as implementation diagnostics for capability forgetting, shortcut collapse, feasibility-vs-price separation, non-separable contract failures, optimization sensitivity, and timing-tail instability. They are secondary to the physical chain:

```text
budget → activation → work → latency → deadline
```

## Nonclaims

This repository does not claim:

- hard real-time or WCET guarantees;
- a production Real-Time NN or Real-Time LM;
- Joule-level energy savings or measured memory-bandwidth reduction;
- arbitrary hardware portability;
- universal superiority over fixed policies or external schedulers;
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
python experiments/realtime_nn_machine_state_timing_audit.py
```

Timing numbers are machine-dependent. Reproduction should focus on physical execution traces, hard budget compliance, work/latency ordering, controller overhead, deadline behavior, and the stability or instability of the timing model itself.

## Related work

Representative prior work and the novelty boundary are documented in [`RELATED_WORK.md`](RELATED_WORK.md).

## Repository scope

This remains a small mechanism study. Scaling to LLMs, GPUs, or large models is not required for the current research question.

## License

Apache License 2.0. See `LICENSE`.
