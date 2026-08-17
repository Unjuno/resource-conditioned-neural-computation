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

#### Common-deadline frontier audit

The four representative deadline regimes were replaced by a **25-point common absolute deadline sweep per seed**. Each policy admits the largest execution class fitting its own empirical P95 bound.

Among 18 learned-vs-prefix deadline points whose mean miss rates differ by at most two percentage points:

- learned activation has higher on-time-correct at **16/18** points;
- mean learned-minus-prefix advantage is **+9.62 percentage points**;
- median advantage is **+11.07 points**;
- maximum observed advantage is **+20.79 points**.

This reduces the concern that the intermediate-budget advantage was created by selecting four favorable deadlines, while retaining the boundary that very tight or loose/full-work regimes can favor simpler execution.

See [`notes/realtime_nn_common_deadline_frontier.md`](notes/realtime_nn_common_deadline_frontier.md).

### 4. Task-loss-only budget-compliant activation

The explicit relevance-supervision loss was removed. The entire model is trained from scratch from task cross-entropy only; there is no relevance auxiliary loss, capability warmup, or expert freezing.

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

The runtime hypothesis was:

```text
observed machine state
    → empirical P95 execution-class table
    → admitted budget
```

An initial run appeared positive, but an independent repeat contradicted it. The positive interpretation was rejected and the timing table itself was audited.

Two model seeds were each measured under `idle`, periodic same-core load, and continuous same-core contention. Budgets were randomly interleaved; each state was recalibrated six times.

Maximum repeated P95 coefficient of variation:

- idle: **0.321**;
- periodic load: **0.092**;
- continuous same-core busy load: **0.990**.

A larger 1,800-sample-per-budget probe exposes a **quantile cliff**:

| budget | median | P95 | fraction > 4 ms |
|---:|---:|---:|---:|
| .25 | 103 us | 381 us | 3.00% |
| .50 | 189 us | **8.38 ms** | **6.94%** |
| .75 | 279 us | 8.49 ms | 9.22% |
| 1.00 | 378 us | 8.63 ms | 11.72% |

At `B=.5`, scheduler-preempted requests cross the 5% frequency boundary, so empirical P95 jumps from the fast execution mode into the preempted mode. Small run-to-run changes in preemption probability can move P95 discontinuously even when the neural execution class is unchanged.

**Conclusion:** a coarse categorical `machine state → one empirical P95 table` is **not** established as a stable runtime contract on ordinary Linux.

See [`notes/realtime_nn_machine_state_timing_audit.md`](notes/realtime_nn_machine_state_timing_audit.md).

## Generated C++ bridge toward RTOS/analyzable inference

The trained fixed-depth model is now also exported into a small **plain C++** inference runtime. Python/PyTorch is absent during inference; the admitted budget directly limits the C++ block loop.

Seed-0 full-domain accuracy matches the Python model exactly at all execution depths.

One `g++ -O2 -std=c++17` run:

| blocks | linear MAC proxy | idle median | same-core-busy median |
|---:|---:|---:|---:|
| 0 | 64 | 0.063 us | 0.065 us |
| 2 | 184,384 | 71.4 us | 71.5 us |
| 4 | 368,704 | 143.1 us | 143.5 us |
| 6 | 553,024 | 217.5 us | 217.8 us |
| 8 | 737,344 | 294.8 us | 292.8 us |

Central timing remains strictly ordered by physical work after removing PyTorch.

The same-core busy run still develops millisecond scheduler modes; for example P99 is about **8.11 ms** at depth 2 and **8.19 ms** at depth 4.

This separates the two remaining questions:

```text
conditional NN execution: reproducible in plain C++
real-time tail guarantee: requires scheduler/interference control
```

The C++ implementation is a bridge toward an RTOS/static-timing experiment because execution-class control flow and finite work counts are explicit. It is **not** itself a WCET proof.

See [`notes/realtime_nn_generated_cpp.md`](notes/realtime_nn_generated_cpp.md).

## Timing boundary

All current deadline experiments are **soft/weakly-hard empirical prototypes** on ordinary Linux. Empirical P95/P99 is not WCET.

A hard-RT claim requires a controlled scheduling substrate and a defensible timing argument, for example RTOS CPU reservation, bounded interference assumptions, statically analyzable generated inference code, time-predictable hardware/runtime, formal/static WCET, or an accepted probabilistic real-time model with explicit assumptions.

## Current status

Supported in toy systems:

1. budget changes **physical** internal execution in one fixed NN;
2. executed work and measured median latency change with budget;
3. quality/latency trade-offs emerge from the same parameters;
4. hard runtime work caps can coexist with learned internal selection;
5. learned selection can be integrated with soft deadline admission;
6. useful budget-compliant selection can be learned from task loss alone in a supplied search space;
7. the learned intermediate-work benefit survives a denser common-deadline frontier audit;
8. the physical conditional-execution mechanism survives removal of Python/PyTorch;
9. simpler or analytic policies can still be better in some deadline regimes;
10. uncontrolled Linux machine-state timing cannot be reduced to a stable empirical P95 table.

Open:

1. move the generated conditional runtime to a controlled RTOS/time-predictable scheduling substrate;
2. derive or measure a defensible interference/WCET admission model;
3. make useful internal computation less analytically exposed than the current toy;
4. test structured finer-grained physical activation;
5. later test sequence-model applicability without making scale itself the objective.

## Secondary diagnostics

Older router/topology experiments remain as implementation diagnostics. They are secondary to:

```text
budget → activation → work → timing bound → deadline
```

## Nonclaims

This repository does not claim hard real time/WCET, production RTOS deployment, physical energy savings, arbitrary hardware portability, universal superiority over fixed/analytic schedulers, unconstrained architecture discovery, or LLM-scale generalization.

## Reproduce primary experiments

```bash
python -m venv .venv
source .venv/bin/activate
pip install -r requirements.txt
python experiments/realtime_nn_budget_execution.py
python experiments/realtime_nn_learned_budget_gate.py
python experiments/realtime_nn_learned_deadline_integration.py
python experiments/realtime_nn_deadline_frontier.py
python experiments/realtime_nn_task_only_gate.py
python experiments/realtime_nn_machine_state_timing_audit.py

python experiments/export_realtime_nn_cpp_weights.py --out /tmp/realtime_nn_weights.bin
g++ -O2 -std=c++17 experiments/realtime_nn_generated_cpp.cpp -o /tmp/realtime_nn_cpp
/tmp/realtime_nn_cpp /tmp/realtime_nn_weights.bin 5000 0 0
/tmp/realtime_nn_cpp /tmp/realtime_nn_weights.bin 3000 1 0
```

Timing numbers are machine-dependent. Reproduction should focus on physical execution traces, hard budget compliance, work/latency ordering, controller overhead, common-deadline behavior, cross-backend consistency, and timing-model stability.

## Related work

Representative prior work and the novelty boundary are documented in [`RELATED_WORK.md`](RELATED_WORK.md).

## Repository scope

This remains a small mechanism study. Scaling to LLMs, GPUs, or large models is not required for the current research question.

## License

Apache License 2.0. See `LICENSE`.
