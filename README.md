# Resource-Conditioned Neural Computation

A falsification-oriented study toward a **Real-Time Neural Network (Real-Time NN)**: one fixed neural parameter set whose **physically executed internal computation changes under a runtime-admitted work/time budget**.

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

### 1. Budget changes physical depth, work, quality, and measured latency

One fixed network physically executes `0 / 2 / 4 / 6 / 8` optional blocks at increasing budgets.

Across three seeds:

- mean accuracy: **63.67% → 71.48% → 78.52% → 86.33% → 100%**;
- hard-skip median latency is strictly monotonic in **3/3 seeds**;
- hooks verify inactive blocks are not executed;
- a dense-mask control executes all blocks and does not obtain the speedup.

See [`notes/realtime_nn_budget_execution.md`](notes/realtime_nn_budget_execution.md).

### 2. Budget also changes structured active channel width in the same weights

A second experiment jointly trains one maximum-width `C=32` network for five physical classes:

| class | depth | active width | exact slim linear MACs |
|---:|---:|---:|---:|
| 0 | 0 | 8 | 16 |
| 1 | 2 | 8 | **11,408** |
| 2 | 4 | 16 | **91,168** |
| 3 | 6 | 24 | **307,632** |
| 4 | 8 | 32 | **729,152** |

All three seeds preserve the complete-domain quality ladder **63.67% / 71.48% / 78.52% / 86.33% / 100%**.

The slim path slices actual hidden/FF operands and weight matrices **before** the linear operations. A matched dense-width-mask control computes maximum width and zeros inactive channels afterward. Across all 512 states and all three seeds, the plain-C++ slim and dense-mask paths have identical outputs.

Three-seed mean C++ median ratios `slim / dense-mask`:

| class | work ratio | latency ratio |
|---:|---:|---:|
| 1 | 0.0626 | **0.130** |
| 2 | 0.2500 | **0.363** |
| 3 | 0.5625 | **0.622** |
| 4 | 1.0000 | 0.993 |

This directly supports the intended mechanism beyond iteration/depth count: **the same maximum-size parameter set can change the physically active internal width under budget.**

Important negative control: on PyTorch batch-size-1 CPU execution, the same large MAC reductions do **not** make the intermediate slim classes faster; they are slightly slower than the dense-mask control. Therefore:

> **a smaller neural circuit is not sufficient by itself — the backend must convert it into cheaper physical execution.**

See [`notes/realtime_nn_structured_width.md`](notes/realtime_nn_structured_width.md).

### 3. Learned selection inside a hard runtime cap

The runtime admits exactly `k ∈ {1,2,4,8}` expert calls. Hard top-k structurally prevents the NN from exceeding the admitted work cap.

At `k=4`, an explicitly supervised learned selector reaches **100% accuracy** versus **78.18%** for fixed-prefix execution at the same expert-call cap. Controller overhead is included in timing.

See [`notes/realtime_nn_learned_budget_gate.md`](notes/realtime_nn_learned_budget_gate.md).

### 4. Learned selection + empirical deadline admission

At a representative intermediate deadline regime:

- learned miss rate: **1.54%**;
- fixed-prefix miss rate: **1.21%**;
- learned on-time & correct: **98.46%**;
- fixed-prefix on-time & correct: **76.00%**.

A 25-point common absolute deadline sweep reduces the concern that this was a hand-picked operating point. Among 18 learned-vs-prefix points with mean miss rates within two percentage points, learned activation has higher on-time-correct at **16/18**, with mean advantage **+9.62 percentage points**.

Learned control is not universally better: tight/full-budget regimes can favor simpler policies, and an external analytic relevance oracle remains a strong baseline.

See [`notes/realtime_nn_learned_deadline.md`](notes/realtime_nn_learned_deadline.md) and [`notes/realtime_nn_common_deadline_frontier.md`](notes/realtime_nn_common_deadline_frontier.md).

### 5. Useful budget-compliant selection can arise from task loss alone

Removing relevance labels, auxiliary relevance loss, capability warmup, and expert freezing still gives the following three-seed mean result:

| k | task-loss learned | fixed prefix | analytic oracle |
|---:|---:|---:|---:|
| 1 | 69.04% | 67.66% | 69.09% |
| 2 | **81.27%** | 71.37% | 81.80% |
| 4 | **100.00%** | 78.74% | 100.00% |
| 8 | 99.82% | 99.82% | 99.82% |

This supports task-loss-only useful-computation selection **inside the supplied hard-cap search space**. It is not a claim of unconstrained architecture discovery.

See [`notes/realtime_nn_task_only_gate.md`](notes/realtime_nn_task_only_gate.md).

## RTOS / analyzable implementation bridge

The direct mechanism has been lowered from PyTorch to generated C++, static C, and a freestanding/fixed-point finite-class core.

Current implementation evidence includes:

- exact physical work counts derived from actual control flow and cross-checked by instrumentation;
- exact main depth-class linear MACs: **64 / 182,336 / 364,608 / 546,880 / 729,152**;
- freestanding core with no unresolved external symbols in tested builds;
- Q5 `int16` weights/workspace + `int32` accumulators preserving all tested class predictions across three seeds;
- model weights **335,368 B → 167,684 B** and workspace **8,064 B → 4,032 B** in the Q5 implementation;
- bounded LUT activation path and division-free residual scaling;
- conservative static numeric-range bounds for the tested generated weights;
- target-independent execution manifest separated from target timing certification;
- admission fails closed for uncertified classes, wrong neural manifest, or wrong deployed-build identity.

A GCC/Clang × optimization-level audit produced ten functionally identical builds with **ten distinct object hashes**, confirming that timing certification must be attached to the certified deployed build rather than only the neural manifest.

See [`notes/realtime_nn_freestanding_core.md`](notes/realtime_nn_freestanding_core.md), [`notes/realtime_nn_fixed_q5.md`](notes/realtime_nn_fixed_q5.md), [`notes/realtime_nn_q5_bounded_numeric.md`](notes/realtime_nn_q5_bounded_numeric.md), [`notes/realtime_nn_execution_contract.md`](notes/realtime_nn_execution_contract.md), and [`notes/realtime_nn_compiler_bound_timing.md`](notes/realtime_nn_compiler_bound_timing.md).

## Runtime falsification: ordinary Linux percentiles are not a stable timing contract

A simple hypothesis was:

```text
observed machine state
    → empirical P95 execution-class table
    → admitted budget
```

An initial positive run did not reproduce. Repeated same-core Linux measurements instead expose scheduler/preemption mixture modes and **quantile cliffs**.

One high-sample continuous-load probe:

| budget | median | P95 | fraction > 4 ms |
|---:|---:|---:|---:|
| .25 | 103 us | 381 us | 3.00% |
| .50 | 189 us | **8.38 ms** | **6.94%** |
| .75 | 279 us | 8.49 ms | 9.22% |
| 1.00 | 378 us | 8.63 ms | 11.72% |

When preempted samples cross the 5% frequency boundary, P95 jumps into the preempted mode even though the NN execution class is unchanged.

**Conclusion:** ordinary Linux empirical P95/P99 is not WCET and is not established as a stable hard-admission contract.

See [`notes/realtime_nn_machine_state_timing_audit.md`](notes/realtime_nn_machine_state_timing_audit.md).

## Current status

Supported in supplied toy systems:

1. budget changes **physical depth** in one fixed NN;
2. budget can also change **structured active channel width** in one maximum-size parameter set;
3. exact executed work changes with those physical circuits;
4. a compatible generated backend converts reduced work into reduced central latency;
5. a general framework can fail to do so, so backend behavior is part of the mechanism;
6. quality/work trade-offs emerge from the same parameters;
7. hard runtime work caps can coexist with learned internal selection;
8. useful budget-compliant selection can be learned from task loss alone in a supplied search space;
9. finite-class work metadata can be separated cleanly from target/build-specific timing certification;
10. uncontrolled Linux machine-state timing cannot be reduced to a stable empirical P95 hard contract.

Open:

1. attach defensible per-class upper timing bounds on a concrete RTOS/time-predictable target and certified build;
2. make useful internal computation less analytically exposed than the current toy;
3. test sub-block/arbitrary channel groups only where the backend physically skips them;
4. later test sequence-model applicability without making scale itself the objective.

## Secondary diagnostics

Older router/topology experiments remain as implementation diagnostics for capability forgetting, shortcut collapse, feasibility-vs-price separation, non-separable contracts, optimization sensitivity, and timing-tail instability. They are secondary to:

```text
budget → physical activation → exact work → certified timing bound → deadline
```

## Nonclaims

This repository does **not** claim hard real time/WCET, production RTOS deployment, universal speedup from nominal MAC reduction, energy savings, arbitrary hardware/timing portability, universal superiority over fixed/analytic schedulers, unconstrained architecture discovery, arbitrary neuron sparsity, or LLM-scale generalization.

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
python experiments/realtime_nn_structured_width.py --seed 0 --steps 160 --export /tmp/rtnn_structured_width.bin

g++ -O2 -std=c++17 experiments/realtime_nn_structured_width_cpp.cpp -o /tmp/rtnn_structured_width_cpp
/tmp/rtnn_structured_width_cpp /tmp/rtnn_structured_width.bin 2500
```

Timing numbers are machine-dependent. Reproduction should focus on physical execution, output-equivalent dense controls, exact work counts, backend conversion of work into latency, hard-cap compliance, and the explicit timing-certification boundary.

## Related work

Representative prior work and the novelty boundary are documented in [`RELATED_WORK.md`](RELATED_WORK.md).

## Repository scope

This remains a small mechanism study. Scaling to LLMs, GPUs, or large models is not required for the current research question.

## License

Apache License 2.0. See `LICENSE`.
