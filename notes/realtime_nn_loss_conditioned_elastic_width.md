# Loss-conditioned elastic-width sparse NN

## Question

Can one fixed neural network receive a scalar compute/resource price and learn to change **how much internal computation is physically executed**, so that the same parameters expose a quality/latency trade-off?

This experiment targets the intended Real-Time NN mechanism more directly than a fixed external work class:

```text
resource price λ
      ↓
same NN parameters
      ↓
internal width controller chooses k
      ↓
input-dependent selector chooses which k experts
      ↓
only those experts are physically executed
      ↓
quality / work / measured latency trade-off
```

The controller is a mechanism, not the research objective. The research question is whether `λ` changes physical propagation in the same NN and therefore changes actual inference time and quality.

## Task

Each input has eight candidate evidence slots.

- The **importance magnitude** of each slot is cheap metadata visible to the selector.
- The **sign/content** of the evidence is not visible to the selector and is only processed when that expert executes.
- The binary label is the sign of the sum of all eight weighted evidence values.

The importance template is approximately:

```text
2.0, 1.4, 1.0, 0.7, 0.5, 0.35, 0.25, 0.18
```

with per-example permutation and small jitter.

Reading only the most important subset therefore gives progressively better information, while reading all experts gives the best quality.

## Architecture

One fixed network contains eight expensive experts, one cheap selector, one cost-conditioned width controller, and one shared head.

Allowed physical widths are:

```text
k ∈ {0, 1, 3, 4, 6, 8}
```

At inference:

1. the width controller receives resource price `λ` and chooses `k`;
2. the selector ranks the eight candidate experts using only cheap importance metadata;
3. only the top-`k` experts are executed;
4. unselected experts are not called.

The physical inference path is therefore a narrow/elastic MoE-like execution path.

## Loss-derived width supervision

There is **no handwritten width label** such as “price 0.7 must use four experts.”

During training, all candidate widths are evaluated and each obtains task cross-entropy `CE_k`. A work-priced loss is formed:

\[
E_k(\lambda)=\operatorname{CE}_k + \alpha\lambda\frac{k}{8},
\qquad \alpha=0.55.
\]

A softmin of this loss becomes the training target for the internal width controller.

Thus the mapping

```text
price → physical execution width
```

is amortized from **task loss + resource cost**, rather than assigned by a route label.

All widths also receive task supervision so that low-work fallback classes remain capable.

Important boundary: the training surrogate evaluates all experts/all candidate widths. The demonstrated sparsity is an **inference-time physical execution result**, not a training-time sparse-compute result.

## Three-seed quality ladder

Mean held-out accuracy when each width is forced:

| executed experts | mean accuracy |
|---:|---:|
| 0 | 49.64% |
| 1 | 81.32% |
| 3 | 87.68% |
| 4 | 91.76% |
| 6 | 95.20% |
| 8 | 96.88% |

This establishes the desired same-parameter quality/work frontier before asking the price controller to move along it.

## Resource-price sweep

Across three independently trained seeds, selected width is non-increasing with price in **3/3 seeds**.

Representative common price points:

| price | selected `k` by seed | mean accuracy | mean physical hard-skip median |
|---:|---:|---:|---:|
| 0.00 | 8 / 8 / 8 | **96.88%** | **427.0 us** |
| 0.20 | 8 / 6 / 6 | 95.75% | 372.9 us |
| 0.40 | 6 / 6 / 4 | 93.84% | 321.6 us |
| 0.70 | 4 / 4 / 4 | **91.76%** | **268.4 us** |
| 1.50 | 3 / 3 / 3 | **87.68%** | **226.9 us** |
| 2.50 | 0 / 1 / 0 | 59.72% | 98.0 us |
| 4.00 | 0 / 0 / 0 | 49.64% | 75.8 us |

So increasing the supplied resource price causes the same NN to narrow its physically executed expert set, reduce measured central latency, and accept lower task quality.

This is the intended qualitative behavior for a future Real-Time LM:

```text
more available time / cheaper compute
    → wider internal computation
    → higher quality, longer inference

less available time / expensive compute
    → narrower internal computation
    → lower quality, earlier response
```

## Dense-mask falsification

A matched dense-equivalent path computes all eight experts and applies the same selected mask only afterward.

For seed 0, over 300 input/price cases:

- prediction mismatches between physical hard-skip and dense-equivalent: **0**;
- maximum absolute logit difference: **4.77e-7**.

The dense path stays around full-compute latency while the physical path shortens as `k` decreases. Therefore the speed change is attributable to **not executing inactive experts**, not merely to changing logical mask values.

## Same-input counterfactual

For one fixed held-out input in seed 0, changing only the resource price produces the following physical traces:

| price | k | executed expert IDs |
|---:|---:|---|
| 0.0 | 8 | 0, 5, 6, 2, 7, 3, 1, 4 |
| 0.5 | 6 | 0, 5, 6, 2, 7, 3 |
| 0.8 | 3 | 0, 5, 6 |
| 1.8 | 0 | none |

Forward hooks match the selected IDs exactly; inactive experts are not executed.

The dense price-transition scan for this model is approximately:

```text
λ < 0.3325        → k=8
0.3325..0.525     → k=6
0.525..0.805      → k=4
0.805..1.75       → k=3
λ >= 1.75         → k=0
```

## Price-blind matched control

The same width-controller architecture was trained with the price feature zeroed.

Across all tested prices:

- seed 0 stays at `k=8`;
- seed 1 stays at `k=6`;
- seed 2 stays at `k=8`.

Thus **3/3 price-blind controls use one fixed width** and do not move along the quality/work frontier when price changes.

## Loss-oracle audit

On held-out data, define the simple external oracle

\[
k^*=\arg\min_k\left(\overline{\operatorname{CE}}_k + 0.55\lambda k/8\right).
\]

The learned controller agrees with this loss oracle on **28/33 tested seed × price points = 84.85%**.

This shows that the learned controller substantially tracks the task-loss/work objective.

It also defines an important nonclaim: in this toy, an external scheduler with the complete held-out loss/work table can compute the same argmin directly. The experiment demonstrates the **neural interface/mechanism**, not necessity or superiority of a learned scheduler.

## Preliminary deadline integration

A seed-0 soft/weakly-hard experiment scans `price → k`, measures controller-inclusive timing for the reachable classes, and lets a runtime choose a price region whose empirical monotone P95 class fits a deadline.

Examples:

| deadline | admitted k | price-conditioned miss | price-conditioned on-time-correct | always-full miss | always-full on-time-correct |
|---:|---:|---:|---:|---:|---:|
| 282 us | 3 | 4.0% | **84.0%** | 100% | 0% |
| 489 us | 6 | 6.0% | **89.33%** | 12.33% | 83.67% |
| 534 us | 8 | 6.5% | 89.33% | 8.0% | 87.67% |

However, the `k=4` class misses **15.17%** at a deadline set 8% above its calibration P95. This is another direct reminder that ordinary Linux empirical P95 is not a stable hard-real-time contract.

Therefore the deadline experiment is supporting soft evidence only. A real RTOS/runtime must derive a **hard admitted work bound** from a controlled timing substrate; the NN can then use resource price inside that safe region.

## Interpretation

### Supported

> In this supplied sparse-NN toy, one fixed parameter set can receive a scalar resource price, learn a width policy from task loss plus work cost, physically execute a narrower or wider expert subset, and expose a reproducible accuracy/latency trade-off.

This is substantially closer to the intended Real-Time NN/LM concept than an experiment where an external runtime directly selects a named route.

### Not supported

- hard real-time or WCET;
- LLM/sequence-model generalization;
- training-time sparse compute;
- arbitrary unstructured neuron sparsity;
- superiority or necessity of learned width control when an external analytic scheduler has the complete loss/work table;
- hardware-independent mapping from resource price to milliseconds.

## Next experiment

The next model-side step should retain this loss-conditioned width mechanism but make the computation structurally closer to a transformer:

- several optional attention/MLP blocks or experts inside one small sequence model;
- runtime supplies a hard admissible work cap plus a soft resource price;
- the model chooses which attention/MLP computation to execute inside that cap;
- physical skip and actual latency are audited on the generated backend.

Scale is not required; the mechanism should be established on a small sequence model first.
