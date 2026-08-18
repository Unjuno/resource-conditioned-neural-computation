# Hard-cap + price-conditioned local-attention sequence model

## Question

Can the Real-Time NN mechanism survive a step toward transformer-like sequence computation?

The target interface is:

```text
runtime hard max-work cap
        +
soft resource price λ
        ↓
one fixed sequence model
        ↓
price/cap-conditioned physical attention+MLP depth
        ↓
sequence quality / measured latency
```

The hard cap is the safety/admission mechanism. Price is only a soft quality/work signal inside the allowed region.

## Sequence task

The input is a 9-token binary sequence. Token 0 must reconstruct all nine token bits through a stack of local attention+MLP blocks.

Each attention block lets a position attend only to itself and its immediate right neighbor. Therefore the representation at token 0 can receive information from only one additional token per executed block. This makes executed attention depth a real information/receptive-field constraint rather than an arbitrary route label.

The output is nine binary logits from token 0. Target-bit losses are weighted more heavily for nearby positions so that the marginal value of extra depth decreases gradually.

## Architecture

One parameter set contains:

- token embedding + positional embedding;
- 8 optional local self-attention + MLP residual blocks;
- shared 9-bit output head;
- a small controller that receives `(resource price, hard max depth)`.

Physical execution classes are:

```text
0 / 2 / 4 / 6 / 8 attention+MLP blocks
```

At inference, depths above the runtime cap are structurally masked out before the controller argmax. The selected depth is then executed with a real Python control-flow loop; blocks beyond it are not called.

## Training

Capability parameters are trained across all five depths. The controller is then trained from the measured full-domain capability frontier.

For depth `d` and price `λ`:

\[
E_d(\lambda)=\overline{BCE}_d + 0.7\lambda d/8.
\]

For every training price/cap pair, disallowed depths (`d > cap`) receive effectively infinite cost and the minimum-energy allowed depth becomes the controller target.

This target is derived from task loss + work cost. It is not a handwritten statement such as “price 0.85 uses four blocks.”

Important limitation: this is capability training followed by controller amortization, not an end-to-end sparse-training result. An external analytic scheduler with the complete loss/work table remains a strong baseline.

## Fixed-depth quality frontier

Three seeds give the same sequence-quality ladder:

| executed blocks | bit accuracy | weighted bit accuracy |
|---:|---:|---:|
| 0 | 55.56% | 58.62% |
| 2 | 66.67% | 74.14% |
| 4 | 77.78% | 86.21% |
| 6 | 88.89% | 94.83% |
| 8 | 100% | 100% |

The ladder follows the expanding local-attention receptive field.

## Full-cap price sweep

With hard cap = 8, all three seeds choose the same physical depth sequence:

```text
price 0.0–0.3 → 8 blocks
price 0.5     → 6 blocks
price 0.85    → 4 blocks
price 1.0     → 2 blocks
price >=1.5   → 0 blocks
```

Representative three-seed means:

| price | blocks | weighted accuracy | physical median | dense-equivalent median |
|---:|---:|---:|---:|---:|
| 0.0 | 8 | 100% | ~1.11 ms | ~1.08 ms |
| 0.5 | 6 | 94.83% | ~0.85 ms | ~1.07 ms |
| 0.85 | 4 | 86.21% | ~0.59 ms | ~1.13 ms |
| 1.0 | 2 | 74.14% | ~0.37 ms | ~1.14 ms |
| 1.5 | 0 | 58.62% | ~0.09 ms | ~1.04 ms |

Thus the same sequence-model weights expose a multi-stage quality/latency trade-off when only resource price changes.

## Hard-cap intervention

The runtime cap is independently varied over `0/2/4/6/8`.

Across all tested seed × cap × price cases:

- selected depth never exceeds the cap;
- hook count exactly equals selected physical depth;
- tightening the cap forces a smaller execution graph even at a low price;
- within a nontrivial cap, increasing price can choose an even smaller graph.

For example, in seed 0:

```text
cap=8, low price → 8 blocks
cap=6, low price → 6 blocks
cap=4, low price → 4 blocks
cap=4, higher price → 2 or 0 blocks
cap=2 → never more than 2 blocks
cap=0 → no optional block executes
```

This is the intended separation:

> runtime decides what is possible; the NN decides how much of that allowance is worth using.

## Dense-equivalent falsification

The matched dense path executes all eight attention+MLP blocks but discards updates after the selected depth.

Across three seeds:

- 750 physical-vs-dense cases tested;
- prediction-vector mismatches: **0**;
- maximum logit difference: **0**.

Dense execution stays near full-depth latency, whereas the hard path falls with selected depth. The speedup therefore comes from physically not executing the inactive blocks.

## Price-blind control

The controller architecture is unchanged but the price coordinate is zeroed. It can still observe the hard cap.

For each fixed cap, changing price does not change selected depth in **3/3 seeds**. Thus the price-aware adaptation is not merely a side effect of controller capacity or capability training.

## Loss-oracle audit

At the public full-cap price points, the controller agrees with the analytic loss/work argmin on **27/27 seed × price points**.

This is useful as an implementation check but also a nonclaim: the experiment does not show that the neural controller is necessary when an external scheduler already owns the complete loss/work frontier.

## Interpretation

### Supported

> In this supplied local-attention sequence toy, one fixed sequence model can obey a runtime hard max-depth cap while a scalar resource price moves it across physically executed attention+MLP depths, producing a reproducible quality/latency trade-off.

This is closer to the eventual Real-Time LM architecture than the earlier non-sequence toys because the variable computation is now inside a transformer-like sequence stack.

### Not supported

- hard real-time / WCET;
- autoregressive language generation;
- LLM-scale behavior;
- arbitrary attention-head/MLP-expert discovery;
- necessity/superiority of learned control over an analytic scheduler;
- end-to-end sparse training.

## Next step

Keep the same hard-cap + soft-price interface, but replace depth-only elasticity with a small decoder-like block containing separately optional attention and MLP expert groups. The model should choose *which* expensive subcomputation to execute inside the cap, not only how many prefix blocks to run. Physical skip and backend timing remain mandatory.
