# Learned budget-conditioned physical activation under a hard runtime cap

## Question

After establishing fixed budget→depth physical execution, can a **learned internal activation controller** use the same admitted work budget more intelligently while preserving:

- one fixed parameter set;
- a hard runtime-enforced execution cap;
- physical skipping of inactive modules;
- monotonic measured latency with admitted work?

This experiment is still not a router benchmark. The controller is judged by quality at the same physical budget and by actual execution-time behavior.

## Task and architecture

Each input contains eight slots. Exactly four slots are marked relevant. The label is the strict majority of the bits in the four relevant slots.

The network contains eight optional expert modules, one learned relevance-scoring controller, and one shared head.

The runtime admits exactly `k ∈ {1,2,4,8}` expert calls. The controller may choose **which** experts to execute, but hard top-k prevents it from executing more than `k`.

The controller receives slot relevance and normalized budget. It is trained with an explicit relevance auxiliary target. This is a controlled mechanism experiment, **not** a claim of spontaneous/self-organized routing.

Experts/head are trained across all budgets. All inference budgets use the same frozen parameter set.

## Baselines

1. **learned hard-skip** — learned controller chooses top-k; only those k experts are called;
2. **fixed-prefix hard-skip** — first k experts are called; same expert/head weights, no learned selection;
3. **learned dense-mask** — learned controller chooses top-k, but all eight experts are physically computed before unselected outputs are suppressed.

The dense control produces the same output as learned hard-skip to numerical precision.

## Three-seed result

### Accuracy at the same admitted expert-call budget

| expert-call budget k | learned activation | fixed prefix |
|---:|---:|---:|
| 1 | 68.35% | 68.77% |
| 2 | **81.90%** | 71.43% |
| 4 | **100.00%** | 78.18% |
| 8 | 100.00% | 100.00% |

For `k=2` and `k=4`, learned activation spends the same physical expert-call budget but selects more useful computation.

At `k=4`, the learned controller selects relevant slots with 100% precision in all three seeds and reaches 100% task accuracy.

### Measured median latency

| k | learned hard-skip | fixed-prefix hard-skip | learned dense-mask |
|---:|---:|---:|---:|
| 1 | 74.62 us | 56.30 us | 354.21 us |
| 2 | 114.07 us | 95.68 us | 342.64 us |
| 4 | 195.40 us | 171.37 us | 348.23 us |
| 8 | 366.21 us | 337.42 us | 356.35 us |

Across 3/3 seeds:

- learned hard-skip calls exactly k experts at every budget;
- fixed-prefix hard-skip also calls exactly k;
- dense-mask calls all eight experts at every budget;
- learned hard-skip median latency is strictly increasing with k;
- learned hard-skip and dense-mask outputs match within `1.2e-7` numerical tolerance.

The learned controller has measurable overhead relative to fixed-prefix execution: roughly 18–29 us in these runs. That overhead is included in the reported end-to-end timing.

At `k=4`, the controller trades about 24 us additional median latency for roughly **+21.8 percentage points** of accuracy versus the fixed-prefix policy at the same expert-call cap.

## Interpretation

This closes the next mechanism gap left by the fixed-prefix experiment:

> the runtime can enforce a hard work cap, while a learned internal controller uses the admissible work budget to choose more useful computation; physical executed work remains bounded and measured median latency remains ordered with the admitted budget.

The timing relation therefore does not require the runtime to specify the exact internal path. The runtime can specify **how much work is allowed**, while the NN chooses **which admissible work is useful**.

```text
RTOS/runtime: how much work is admissible
NN:           which admissible internal computation to activate
```

## What this does not show

- hard real-time/WCET guarantees;
- self-organized discovery of relevance without auxiliary supervision;
- that the learned controller beats every possible external scheduler;
- input-dependent variable work beyond the runtime cap (the cap fixes k exactly here);
- energy or memory-bandwidth savings;
- generalization to large models or LLMs.

## Next step

Integrate learned activation with the deadline-admission test:

1. calibrate timing classes including controller overhead;
2. let the runtime map deadline/machine state to k;
3. let the NN choose which k experts to execute;
4. compare quality at matched deadline-miss rate against fixed-prefix execution;
5. keep q99/WCET limitations explicit on ordinary Linux.
