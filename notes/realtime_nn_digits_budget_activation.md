# Budget-conditioned physical activation on handwritten digits

## Question

Does budget-conditioned physical activation remain useful when the relevant computation is **not analytically exposed** as in the earlier key/query toy?

This experiment uses the scikit-learn 8x8 handwritten-digits dataset and keeps the Real-Time NN question fixed:

```text
runtime hard work cap k
        ↓
same NN parameters
        ↓
input-dependent internal activation
        ↓
physically execute exactly k experts
        ↓
quality / work / latency
```

The controller is an implementation mechanism. The result is evaluated by task quality, physical expert calls, work, latency, and common-deadline behavior—not by a routing score.

## Model and split

- dataset: `sklearn.datasets.load_digits`, 8x8 grayscale digits, 10 classes;
- fixed stratified split: 60% train / 20% validation / 20% held-out test;
- eight row-local expert MLPs, one per image row;
- budgets `k ∈ {1,2,4,8}`;
- the shared controller sees only the local row pixels, row-position one-hot, and the budget;
- training uses task cross-entropy only and a straight-through hard-top-k surrogate;
- there are no relevance labels and no analytic relevance oracle.

At inference, the hard path calls exactly `k` expert modules. A dense control computes all eight experts and applies the same learned selection only after the expert computations.

## Strong static baseline without test leakage

For each `k`, every static row subset of size `k` is evaluated on the **validation** split. The best validation subset is then frozen and evaluated on the held-out test split.

This is substantially stronger than a fixed prefix and avoids selecting a favorable static subset on the test set.

## Three-seed result

Mean held-out test accuracy:

| k | learned hard | best static, validation-selected | prefix | content-shuffled | identity-constant |
|---:|---:|---:|---:|---:|---:|
| 1 | **72.31%** | 52.04% | 20.74% | 12.22% | 8.43% |
| 2 | **86.76%** | 72.50% | 34.17% | 10.83% | 13.98% |
| 4 | **93.70%** | 90.28% | 71.48% | 10.00% | 10.83% |
| 8 | 95.93% | 95.93% | 95.93% | 9.63% | 9.72% |

The dynamic advantage is largest under the tightest work caps, narrows at `k=4`, and disappears when all experts execute.

Per-seed learned accuracy is:

- seed 0: `73.89 / 85.83 / 92.22 / 96.67%`;
- seed 1: `68.06 / 86.94 / 94.44 / 95.83%`;
- seed 2: `75.00 / 87.50 / 94.44 / 95.28%`.

## Does the controller merely encode the class in the selected expert IDs?

Two interventions test this failure mode.

### 1. Selected-content shuffle

Keep each test sample's learned expert IDs, but feed those selected experts row content from another randomly permuted test sample.

Accuracy falls to approximately chance:

- `k=1`: 12.22%;
- `k=2`: 10.83%;
- `k=4`: 10.00%;
- `k=8`: 9.63%.

### 2. Identity-constant expert outputs

Keep selected expert identities, but replace every expert's data-dependent output by that expert's fixed train-set mean feature.

Accuracy is again approximately chance: 8.43%, 13.98%, 10.83%, 9.72%.

These interventions support the narrower interpretation that **the selected physical computation content matters**; path identity alone does not explain the task result.

They are not a general causal proof for arbitrary learned conditional networks.

## Physical work and timing

Mean batch-1 Linux/PyTorch medians across three seeds:

| k | learned hard p50 | prefix p50 | dense learned p50 | learned linear-MAC proxy | dense linear-MAC proxy |
|---:|---:|---:|---:|---:|---:|
| 1 | 88.46 us | 64.19 us | 273.73 us | 12,432 | 68,880 |
| 2 | 115.90 us | 92.71 us | 274.49 us | 20,496 | 68,880 |
| 4 | 171.30 us | 149.48 us | 275.41 us | 36,624 | 68,880 |
| 8 | 267.89 us | 262.54 us | 252.78 us | 66,576 | 66,576 |

Hook audit passes in all three seeds:

- learned hard execution calls exactly `k` experts;
- prefix calls exactly `k` experts;
- dense learned execution calls all eight experts;
- learned hard median latency is strictly increasing with `k` in 3/3 seeds.

The controller has measurable overhead. At `k=8`, there is no work-selection benefit and the dense implementation can even be slightly faster on this framework. Therefore this does **not** support universal learned-policy dominance.

## Common-deadline frontier

Each policy is calibrated with its own empirical monotone P95 execution-class bounds. Within each seed, all policies are then evaluated over the same 20 absolute deadlines.

Comparing learned activation against the validation-selected static subset, and retaining relative deadline points where mean miss rates differ by at most three percentage points and neither policy is fully rejected:

- matched points: **10**;
- learned higher on-time-correct: **7/10**;
- mean learned-minus-static on-time-correct: **+3.13 percentage points**;
- median difference: **+4.17 points**.

The negative boundary is important:

- at a very tight matched point, static is **2.78 points better** because its lower control overhead permits more admitted work;
- near full-work operation the learned advantage disappears and can slightly reverse.

Thus the useful regime is the intermediate one where the value of better computation allocation exceeds its controller overhead.

## Interpretation

Supported in this small real-data experiment:

> A fixed neural system can learn from task loss alone to use an externally imposed hard work cap for input-dependent physical internal activation, and under tight/intermediate caps this can improve held-out task quality over a strong validation-selected static computation subset.

This result is materially less analytically exposed than the earlier key/query toy because there is no supplied relevance relation or analytic oracle for choosing rows.

## Limits

This does **not** establish:

- hard real time or WCET;
- universal superiority of learned activation;
- architecture discovery;
- arbitrary sparse-neuron activation;
- large-model or sequence-model transfer;
- that rows are the optimal primitive decomposition for image tasks.

The timing experiment is ordinary Linux/PyTorch batch-1 and is only a soft/weakly-hard mechanism check. The existing RTOS/freestanding Q4 work remains the relevant implementation line for timing certification.
