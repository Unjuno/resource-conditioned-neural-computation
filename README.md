# Resource-Conditioned Neural Computation

A falsification-oriented study toward a **Real-Time Neural Network (Real-Time NN)**: one fixed neural network whose physically executed internal computation changes with an explicit time/compute/resource budget.

## Research target

```text
RTOS / runtime
    ↓
deadline + machine state
    ↓
safe admitted budget B
    ↓
the same neural-network parameters
    ↓
B-conditioned internal activation / effective circuit
    ↓
actual executed work changes
    ↓
actual inference latency changes
    ↓
output before the deadline when the admitted budget is feasible
```

The runtime owns **how much work is admissible**. The NN may learn **which admissible internal computation is useful**. A controller/gate is an implementation mechanism, not the research target.

See [`REALTIME_NN_DIRECTION.md`](REALTIME_NN_DIRECTION.md).

## Milestone 1 — direct budget → physical work → latency

[`experiments/realtime_nn_budget_execution.py`](experiments/realtime_nn_budget_execution.py) uses one fixed network with eight optional local-information-propagation blocks.

Budgets `0 / .25 / .5 / .75 / 1.0` execute `0 / 2 / 4 / 6 / 8` blocks with the same weights.

Across three seeds:

| budget | active blocks | mean accuracy | hard-skip median | dense-mask median |
|---:|---:|---:|---:|---:|
| 0.00 | 0 | 63.67% | 10.53 us | 409.29 us |
| 0.25 | 2 | 71.48% | 98.80 us | 394.08 us |
| 0.50 | 4 | 78.52% | 185.69 us | 385.65 us |
| 0.75 | 6 | 86.33% | 280.26 us | 377.99 us |
| 1.00 | 8 | 100.00% | 375.82 us | 364.96 us |

Audits:

- **3/3 seeds:** hard-skip median latency is strictly increasing with executed depth;
- mean full/minimum-budget hard-skip latency ratio: **35.73x**;
- forward hooks confirm inactive blocks are not called;
- a matched dense-mask control executes all eight blocks at every logical budget;
- hard-skip and dense-mask produce identical outputs for the same budget.

This directly demonstrates the toy mechanism:

```text
smaller budget → less physical work → lower measured median latency → lower quality
```

Detailed note: [`notes/realtime_nn_budget_execution.md`](notes/realtime_nn_budget_execution.md)

## Milestone 2 — learned activation under a hard runtime cap

[`experiments/realtime_nn_learned_budget_gate.py`](experiments/realtime_nn_learned_budget_gate.py) removes the fixed-prefix restriction.

The model contains eight optional expert modules. The runtime admits exactly `k ∈ {1,2,4,8}` expert calls. A learned controller chooses **which** experts to execute, but hard top-k structurally prevents it from exceeding the admitted budget.

The controller is deliberately trained with a relevance auxiliary target. This is a controlled mechanism experiment, not a claim of spontaneous/self-organized routing.

Three-seed result:

| expert-call budget k | learned accuracy | fixed-prefix accuracy | learned hard-skip median | fixed-prefix median | dense-mask median |
|---:|---:|---:|---:|---:|---:|
| 1 | 68.35% | 68.77% | 74.62 us | 56.30 us | 354.21 us |
| 2 | **81.90%** | 71.43% | 114.07 us | 95.68 us | 342.64 us |
| 4 | **100.00%** | 78.18% | 195.40 us | 171.37 us | 348.23 us |
| 8 | 100.00% | 100.00% | 366.21 us | 337.42 us | 356.35 us |

Across 3/3 seeds:

- hard learned execution calls exactly `k` experts at every budget;
- learned median latency is strictly increasing with `k`;
- dense-mask executes all eight experts at every budget;
- hard learned and dense learned outputs match to numerical precision;
- at `k=4`, learned activation gains about **+21.8 percentage points** over fixed-prefix execution at the same expert-call cap;
- the learned controller costs roughly **18–29 us** median overhead versus fixed prefix, and that overhead is included in the timing.

This establishes a stronger responsibility split:

```text
RTOS/runtime: how much work may execute
NN:           which admissible work to activate
```

Detailed note: [`notes/realtime_nn_learned_budget_gate.md`](notes/realtime_nn_learned_budget_gate.md)

## Deadline admission prototype

The fixed-depth experiment also calibrates execution classes and lets a runtime choose the largest budget that fits a deadline.

Because ordinary Linux tails are unstable, this is explicitly a **P95 empirical soft/weakly-hard prototype**, not WCET.

Under the tightest deadline class, mean miss rates across three seeds are:

- adaptive hard-skip: **0.13%**;
- adaptive dense-mask: **100%**;
- always full-depth: **100%**.

Important negative result: raw empirical q99 execution times were **not strictly monotonic in any of the 3 calibration seeds**. Ordinary Linux/PyTorch far-tail timing is still unsuitable as a hard-RT/WCET argument.

## Current status

Supported in toy experiments:

1. same-network budget-conditioned physical execution;
2. actual work and median latency change with admitted budget;
3. a quality/latency trade-off emerges from the same weights;
4. logical masking without physical skipping does not obtain the same speedup;
5. a learned controller can choose more useful internal work while a hard runtime cap bounds physical execution;
6. empirical soft deadline admission can exploit the execution classes.

Still open:

1. integrate the learned activation controller with deadline admission and compare quality at matched miss rate;
2. remove explicit relevance supervision and test more autonomous learned activation without losing hard budget compliance;
3. test machine-state-aware runtime admission;
4. move to a time-predictable/RTOS target or obtain a defensible WCET/static timing argument.

## Secondary diagnostics

Older router/topology experiments remain because they document failure modes relevant to implementation:

- capability forgetting and shortcut collapse;
- conditional-subgraph formation;
- feasibility-vs-price separation;
- non-separable cost/contract failures;
- objective/local-minimum sensitivity;
- policy-parameterization sensitivity;
- Linux timing-tail instability.

They are secondary to the direct budget→work→latency results.

See [`CLAIMS_AND_LIMITS.md`](CLAIMS_AND_LIMITS.md).

## Nonclaims

This repository does not currently claim:

- hard real-time or WCET guarantees;
- a production Real-Time NN or Real-Time LM;
- Joule-level energy savings;
- measured memory-bandwidth or resident-memory reduction;
- arbitrary hardware portability;
- universal superiority over early exit, MoE, NAS, once-for-all networks, or external schedulers;
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
```

Timing numbers are machine-dependent. Reproduction should focus on physical execution traces, budget compliance, work/latency ordering, quality trade-offs, and the dense-mask negative controls.

## Related work

Representative prior work and the novelty boundary are documented in [`RELATED_WORK.md`](RELATED_WORK.md).

## Repository scope

This remains a small mechanism study. Scaling to LLMs, GPUs, or large models is not required for the current research question.

## License

Apache License 2.0. See `LICENSE`.
