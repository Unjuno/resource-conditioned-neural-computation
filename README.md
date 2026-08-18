# Resource-Conditioned Neural Computation

A falsification-oriented study toward a **Real-Time Neural Network (Real-Time NN)**: one fixed neural parameter set whose **physically executed internal computation changes under a runtime-admitted work/time budget and resource price**.

## Research target

```text
RTOS / runtime
    ↓
deadline + bounded machine/interference state
    ↓
safe admitted work region + soft resource price
    ↓
same neural-network parameters
    ↓
budget-compliant, price-conditioned internal activation
    ↓
actual executed work
    ↓
actual inference latency
    ↓
deadline behavior / task quality
```

The runtime owns **what work is admissible**. Inside that safe region, a resource price can express how expensive additional computation is, and the NN may learn **which admissible internal computation is worth executing**. Controllers/gates are implementation mechanisms, not the research target.

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

### 3. Resource price can make the same NN choose a narrower or wider physical expert set

The previous experiments give the runtime an explicit work class. A sparse-NN experiment instead gives the **same fixed NN a scalar resource price `λ`** and lets an internal width controller choose how many expensive experts to execute.

The controller is not trained from handwritten width labels. For candidate widths `k ∈ {0,1,3,4,6,8}`, training forms

\[
E_k(\lambda)=CE_k+0.55\lambda k/8
\]

and amortizes this task-loss/work frontier into the price-conditioned controller. At inference, only the selected top-`k` experts are physically called.

Three-seed forced-width quality ladder:

| experts `k` | mean accuracy |
|---:|---:|
| 0 | 49.64% |
| 1 | 81.32% |
| 3 | 87.68% |
| 4 | 91.76% |
| 6 | 95.20% |
| 8 | 96.88% |

Representative price sweep:

| price `λ` | selected `k` by seed | mean accuracy | mean hard-skip median |
|---:|---:|---:|---:|
| 0.00 | 8 / 8 / 8 | **96.88%** | **427.0 us** |
| 0.20 | 8 / 6 / 6 | 95.75% | 372.9 us |
| 0.40 | 6 / 6 / 4 | 93.84% | 321.6 us |
| 0.70 | 4 / 4 / 4 | **91.76%** | **268.4 us** |
| 1.50 | 3 / 3 / 3 | **87.68%** | **226.9 us** |
| 4.00 | 0 / 0 / 0 | 49.64% | 75.8 us |

Selected width is non-increasing with price in **3/3 seeds**. A matched price-blind controller stays at one fixed width in **3/3 seeds**. For seed 0, a dense-equivalent control that computes all eight experts has **0 prediction mismatches** against physical hard-skip over 300 input/price cases, while only hard-skip receives the latency reduction. The learned width agrees with the simple held-out `task loss + work cost` oracle at **28/33** tested seed×price points.

For the same held-out input and same weights, changing only `λ` changes the physical hook trace from `8 → 6 → 4/3 → 0` experts. Thus the intervention changes actual propagation, not just an output-side score.

This is a **soft price mechanism**, not a hard scheduling guarantee. In a real RTOS design, a hard admitted work cap should still bound the maximum safe computation; price can optimize quality/work **inside that admissible set**.

See [`notes/realtime_nn_loss_conditioned_elastic_width.md`](notes/realtime_nn_loss_conditioned_elastic_width.md).

### 4. Hard cap + soft price also works inside a transformer-like sequence stack

A small sequence model replaces the independent expert toy with **8 optional local self-attention + MLP residual blocks**. Token 0 reconstructs a 9-token binary sequence; each local-attention block expands token 0's receptive field by one token, so deeper physical execution carries genuinely more sequence information.

The runtime supplies a hard maximum depth `cap ∈ {0,2,4,6,8}`. Depths above the cap are structurally masked before controller selection. Inside the cap, the controller receives resource price `λ` and amortizes the loss/work frontier

\[
E_d(\lambda)=\overline{BCE}_d+0.7\lambda d/8.
\]

With full cap, all three seeds traverse **all five physical execution depths in the same order**:

| price | executed attention+MLP blocks | weighted sequence accuracy | mean hard median | mean dense-equivalent median |
|---:|---:|---:|---:|---:|
| 0.0 | 8 | **100%** | ~1.11 ms | ~1.08 ms |
| 0.5 | 6 | **94.83%** | ~0.85 ms | ~1.07 ms |
| 0.85 | 4 | **86.21%** | ~0.59 ms | ~1.13 ms |
| 1.0 | 2 | **74.14%** | ~0.37 ms | ~1.14 ms |
| 1.5 | 0 | **58.62%** | ~0.09 ms | ~1.04 ms |

Across three seeds:

- price-aware depth is non-increasing with price in **3/3**;
- the public sweep uses all `8→6→4→2→0` depths in **3/3**;
- analytic loss/work-oracle agreement is **27/27** tested seed×price points;
- all tested hard-cap interventions obey the cap;
- forward-hook count exactly matches physically selected depth;
- physical hard-skip vs dense-equivalent gives **0/750 prediction-vector mismatches** and maximum logit difference **0**;
- matched price-blind controllers do not change depth with price at fixed cap.

This is a **small transformer-like sequence bridge**, not an LM result: there is no autoregressive generation, no LLM-scale claim, and controller training is post-training amortization of a measured capability frontier rather than end-to-end sparse training.

See [`notes/realtime_nn_price_cap_sequence.md`](notes/realtime_nn_price_cap_sequence.md).

### 5. Learned selection inside a hard runtime cap

The runtime admits exactly `k ∈ {1,2,4,8}` expert calls. Hard top-k structurally prevents budget violation.

At `k=4`, an explicitly supervised learned selector reaches **100% accuracy** versus **78.18%** for fixed-prefix execution at the same expert-call cap. Controller overhead is included in timing.

See [`notes/realtime_nn_learned_budget_gate.md`](notes/realtime_nn_learned_budget_gate.md).

### 6. Learned selection + empirical deadline admission

At a representative intermediate deadline regime:

- learned miss rate: **1.54%**;
- fixed-prefix miss rate: **1.21%**;
- learned on-time & correct: **98.46%**;
- fixed-prefix on-time & correct: **76.00%**.

A 25-point common absolute deadline sweep reduces the concern that this was a hand-picked operating point. Among 18 learned-vs-prefix points with mean miss rates within two percentage points, learned activation has higher on-time-correct at **16/18**, with mean advantage **+9.62 percentage points**.

The loss-conditioned elastic-width model was also connected to a seed-0 empirical deadline→price admission prototype. At a 489 us deadline, price-conditioned execution gives **6.0% misses and 89.33% on-time-correct**, versus always-full **12.33% misses and 83.67% on-time-correct**. However another class misses **15.17%** despite an 8% margin over its calibration P95, reinforcing that ordinary Linux percentile admission is not a hard timing contract.

Learned control is not universally better: tight/full-budget regimes can favor simpler policies, and external analytic schedulers remain strong baselines when the quality/work table is exposed.

See [`notes/realtime_nn_learned_deadline.md`](notes/realtime_nn_learned_deadline.md), [`notes/realtime_nn_common_deadline_frontier.md`](notes/realtime_nn_common_deadline_frontier.md), and [`results/realtime_nn_loss_conditioned_deadline_results.json`](results/realtime_nn_loss_conditioned_deadline_results.json).

### 7. Useful budget-compliant selection can arise from task loss alone

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
3. a scalar resource price can move one fixed sparse NN across multiple **physically executed expert widths**;
4. hard cap + soft price can move one fixed transformer-like **sequence stack** across `8/6/4/2/0` physically executed attention+MLP depths;
5. exact executed work changes with those physical circuits;
6. a compatible backend converts reduced work into reduced central latency;
7. a general framework can fail to do so, so backend behavior is part of the mechanism;
8. quality/work trade-offs emerge from the same parameters;
9. hard runtime work caps can coexist with learned internal selection;
10. price-conditioned width/depth can be derived from task loss plus work cost rather than handwritten route labels;
11. useful budget-compliant selection can be learned from task loss alone in supplied search spaces;
12. finite-class work metadata can be separated cleanly from target/build-specific timing certification;
13. uncontrolled Linux machine-state timing cannot be reduced to a stable empirical P95 hard contract.

Open:

1. replace **prefix-depth-only sequence elasticity** with separately optional attention and MLP expert groups inside a small decoder-like block;
2. lower the hard-cap + soft-price sequence mechanism into a generated/analyzable backend;
3. attach defensible per-class upper timing bounds on a concrete RTOS/time-predictable target and certified build;
4. test autoregressive generation only after the physical sequence mechanism is stable; no scale-up is required;
5. make useful internal computation less analytically exposed than the current toy.

## Secondary diagnostics

Older router/topology experiments remain as implementation diagnostics for capability forgetting, shortcut collapse, feasibility-vs-price separation, non-separable contracts, optimization sensitivity, and timing-tail instability. They are secondary to:

```text
hard admissible work region + soft resource price
    → physical activation
    → exact work
    → certified timing bound
    → deadline / quality
```

## Nonclaims

This repository does **not** claim hard real time/WCET, production RTOS deployment, universal speedup from nominal MAC reduction, energy savings, arbitrary hardware/timing portability, universal superiority over fixed/analytic schedulers, necessity of learned price-to-width/depth control when an analytic quality/work table is available, training-time sparse execution, unconstrained architecture discovery, arbitrary neuron sparsity, autoregressive LM behavior, or LLM-scale generalization.

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
python experiments/realtime_nn_loss_conditioned_elastic_width.py --seed 0 --mode aware
python experiments/realtime_nn_loss_conditioned_elastic_width.py --seed 0 --mode blind
python experiments/realtime_nn_loss_conditioned_deadline.py --seed 0
python experiments/realtime_nn_price_cap_sequence.py --seed 0 --mode aware
python experiments/realtime_nn_price_cap_sequence.py --seed 0 --mode blind
python experiments/realtime_nn_structured_width.py --seed 0 --steps 160 --export /tmp/rtnn_structured_width.bin

g++ -O2 -std=c++17 experiments/realtime_nn_structured_width_cpp.cpp -o /tmp/rtnn_structured_width_cpp
/tmp/rtnn_structured_width_cpp /tmp/rtnn_structured_width.bin 2500
```

Timing numbers are machine-dependent. Reproduction should focus on physical execution, output-equivalent dense controls, exact work counts, hard-cap and cost/price interventions, matched price-blind controls, backend conversion of work into latency, and the explicit timing-certification boundary.

## Related work

Representative prior work and the novelty boundary are documented in [`RELATED_WORK.md`](RELATED_WORK.md).

## Repository scope

This remains a small mechanism study. Scaling to LLMs, GPUs, or large models is not required for the current research question.

## License

Apache License 2.0. See `LICENSE`.
