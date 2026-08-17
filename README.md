# Resource-Conditioned Neural Computation

A falsification-oriented study toward a **Real-Time Neural Network (Real-Time NN)**: one fixed neural network whose physically executed internal computation changes with an explicit time/compute/resource budget.

## Research target

The target system is:

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

A gate/router may be used as an implementation mechanism, but **router optimization is not the research target**.

See [`REALTIME_NN_DIRECTION.md`](REALTIME_NN_DIRECTION.md).

## Strongest current result: direct budget → work → latency

The repository now contains a direct three-seed mechanism experiment in one fixed network:

[`experiments/realtime_nn_budget_execution.py`](experiments/realtime_nn_budget_execution.py)

The model has eight optional local-information-propagation blocks and one shared head. Budget values `0 / .25 / .5 / .75 / 1.0` execute `0 / 2 / 4 / 6 / 8` blocks respectively. The same weights are used at every budget.

The 9-bit-majority task is structured so deeper execution expands the effective receptive field. Across three seeds:

| budget | active blocks | linear MAC proxy | mean accuracy | hard-skip median | dense-mask median |
|---:|---:|---:|---:|---:|---:|
| 0.00 | 0 | 64 | 63.67% | 10.53 us | 409.29 us |
| 0.25 | 2 | 184,384 | 71.48% | 98.80 us | 394.08 us |
| 0.50 | 4 | 368,704 | 78.52% | 185.69 us | 385.65 us |
| 0.75 | 6 | 553,024 | 86.33% | 280.26 us | 377.99 us |
| 1.00 | 8 | 737,344 | 100.00% | 375.82 us | 364.96 us |

Key audits:

- **3/3 seeds:** hard-skip median latency is strictly increasing with budget/executed depth;
- mean full-budget / minimum-budget hard-skip latency ratio: **35.73x**;
- forward hooks confirm hard-skip executes exactly the admitted blocks;
- the matched `dense_mask` control executes all 8 blocks at every budget;
- hard-skip and dense-mask produce identical outputs for the same budget;
- reducing a logical mask without physically skipping work does **not** produce the latency reduction.

This is the first experiment in the repository that directly demonstrates the intended toy mechanism:

```text
smaller admitted budget
    → smaller physically executed internal circuit
    → less actual work
    → lower measured median latency
    → lower task quality
```

Detailed note: [`notes/realtime_nn_budget_execution.md`](notes/realtime_nn_budget_execution.md)  
Results: [`results/realtime_nn_budget_execution_results.json`](results/realtime_nn_budget_execution_results.json)

## Deadline admission prototype

The same experiment calibrates execution classes and lets a runtime choose the largest budget that fits a deadline.

Because ordinary Linux tails are unstable, this is explicitly a **P95 empirical soft/weakly-hard prototype**, not WCET.

Mean miss rates across three seeds under the tightest deadline class:

- adaptive hard-skip: **0.13%**;
- adaptive dense-mask: **100%**;
- always full-depth: **100%**.

For the next classes, adaptive hard-skip remains substantially lower-miss under tight deadlines while accepting the corresponding quality reduction.

Important negative result: raw empirical q99 execution times were **not strictly monotonic in any of the 3 seeds** during separate calibration runs. The far tail is still contaminated by ordinary Linux/PyTorch scheduling jitter.

Therefore this repository still does **not** claim hard real time or WCET.

## Current status

The direct toy mechanism is now demonstrated:

```text
budget
  → internal activation
  → physically executed work
  → measured latency
  → soft deadline behavior
```

What remains open before a stronger Real-Time NN claim:

1. replace the deliberately simple fixed budget→depth mapping with a learned budget-conditioned activation policy while preserving hard budget compliance;
2. repeat the physical-skip and latency audit under that learned policy;
3. move timing validation to a more predictable runtime/RTOS/platform or obtain a defensible WCET/static timing argument;
4. test whether the runtime can map changing machine state to safe admitted budgets without relying on unstable Linux tail estimates.

## Secondary diagnostic experiments

Earlier router/topology work remains in the repository because it documents implementation failure modes:

- direct internal-subgraph execution;
- capability forgetting / shortcut collapse;
- constrained topology discovery;
- feasibility-vs-price separation;
- contract expressiveness failures;
- non-separable route-cost failures;
- router/objective local-minimum sensitivity;
- Linux timing-tail instability.

These are now **secondary diagnostics**, not the headline result.

See [`CLAIMS_AND_LIMITS.md`](CLAIMS_AND_LIMITS.md) and `notes/`.

## Runtime / RTOS responsibility split

```text
hardware / OS state
  ├─ CPU/NPU performance
  ├─ DVFS
  ├─ contention
  ├─ temperature
  └─ timing / WCET information
          ↓
       runtime / RTOS
          ↓
 normalized admitted budget
          ↓
        same NN
          ↓
 budget-conditioned physical execution
```

The runtime owns hardware-dependent timing/admission. The NN should ideally consume a normalized budget rather than a CPU model name or raw milliseconds.

## Nonclaims

This repository does not currently claim:

- hard real-time or WCET guarantees;
- Joule-level energy savings;
- measured memory-bandwidth or resident-memory reduction;
- arbitrary hardware portability;
- universal superiority over early exit, MoE, NAS, once-for-all networks, or external schedulers;
- unconstrained architecture discovery;
- LLM-scale generalization;
- novelty of LUT neurons/networks, dynamic routing, NAS, or runtime subnetwork switching.

## Reproduce the primary experiment

```bash
python -m venv .venv
source .venv/bin/activate
pip install -r requirements.txt
python experiments/realtime_nn_budget_execution.py
```

Timing numbers are machine-dependent. The primary reproduction targets are the **physical execution trace**, budget-dependent operation count, monotonic median-latency ordering, hard-skip vs dense-mask contrast, and explicit failure of Linux q99 to serve as a hard-RT bound.

## Related work

Representative prior work and the novelty boundary are documented in [`RELATED_WORK.md`](RELATED_WORK.md).

## Repository scope

This remains a small mechanism study. Scaling to LLMs, GPUs, or large models is not required for the current research question.

## License

Apache License 2.0. See `LICENSE`.
