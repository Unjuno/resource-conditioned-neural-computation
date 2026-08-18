# Hard-cap + price-conditioned attention/MLP suboperation selection

## Question

Can the price-conditioned sequence mechanism move beyond prefix depth and change **which kind of computation** is executed inside decoder-like blocks?

This toy contains four blocks, each split into two separately skippable physical suboperations:

```text
A0 M0  A1 M1  A2 M2  A3 M3
```

`A` is a local-attention transport sublayer and `M` is a tokenwise MLP sublayer. Attention and MLP each count as one work unit in the experiment; there is no cost discount that would trivially encourage dropping MLP first.

The runtime supplies:

- a **hard cap** = maximum number of active suboperations;
- a **soft price** `λ` = marginal cost of each executed suboperation.

Only selected suboperations are physically called.

## Task

The input is a five-token binary sequence. Token 0 must output its own bit plus four pairwise XOR targets `x0 XOR xj`.

Local attention transports remote token information toward token 0. MLP sublayers provide nonlinear processing useful for XOR-like decoding. The task therefore gives attention and MLP different marginal roles.

## Training

Capability weights are trained under randomly sampled suboperation masks, with the full mask regularly included.

After capability training, all 256 masks are evaluated on the complete 32-state domain. For mask `m`:

\[
E_m(\lambda)=CE_m+\lambda\frac{|m|}{8}.
\]

The internal price/cap controller is post-trained to amortize the exact finite-mask frontier. Masks whose active-operation count exceeds the runtime cap are structurally disallowed at inference.

This is not end-to-end sparse training and is not a claim that a learned controller is necessary when the complete finite loss/work table is externally available.

## Three-seed result

Full-mask weighted accuracy is approximately:

- seed 0: **91.45%**;
- seed 1: **91.45%**;
- seed 2: **84.79%**.

The weaker seed 2 is an explicit capability-stability limitation.

Despite that difference, all three seeds show the same qualitative allocation order:

> **MLP work is reduced before attention work is substantially reduced.**

Representative aggregate price points:

| price | physical composition by seed | mean weighted accuracy | hard median | dense-equivalent median |
|---:|---|---:|---:|---:|
| 0.00 | A4M3 / A4M3 / A4M3 | 89.23% | ~696 us | ~766 us |
| 0.10 | A4M2 / A4M2 / A3M1 | 89.04% | ~563 us | ~752 us |
| 0.20 | A4M1 / A4M1 / A3M1 | 89.04% | ~518 us | ~768 us |
| 0.30 | A4M0 / A4M1 / A3M0 | 89.04% | ~480 us | ~772 us |
| 0.50 | A4M0 / A4M0 / A3M0 | 88.40% | ~459 us | ~777 us |
| 0.80 | A1M0 / A2M0 / A2M0 | 74.34% | ~246 us | ~781 us |
| 1.50 | A0M0 / A0M0 / A0M0 | 55.26% | ~40 us | ~807 us |

Seed 0 is especially clear: weighted accuracy remains **91.45%** while the controller moves from `A4M3` to `A4M2` to `A4M1` to `A4M0`, with median physical latency falling from roughly **690 us to 481 us**. Only at higher price does attention transport itself shrink.

This is qualitatively different from prefix-depth elasticity: the model can preserve attention propagation while dropping MLP refinement first.

## Physical-skip audit

Across all three aware seeds:

- hard-cap violations: **0** in all tested cap/price cases;
- physical vs dense-equivalent prediction mismatches: **0**;
- maximum physical-vs-dense logit difference: **0**.

Dense-equivalent execution computes all eight suboperations and conditionally accepts their updates. Its median stays around full-compute timing while physical execution becomes shorter with fewer active suboperations.

Forward hooks on a fixed input record only the selected attention/MLP modules, confirming inactive suboperations are not called.

## Price-blind control

The matched controller architecture receives the same hard cap but its price coordinate is zeroed.

Across three seeds, the physical composition is constant for every tested price at a fixed cap:

- seed 0: `A1M0`;
- seed 1: `A2M0`;
- seed 2: `A2M0`.

Thus the price-conditioned composition changes are not produced merely by controller capacity or capability training.

## Oracle boundary

The learned controller agrees with the exact finite-mask loss/work oracle on **24/27** public seed×price points.

The remaining three disagreements are near frontier transitions and are not promoted as a separate controller-optimization contribution. This experiment is evidence for **physical suboperation composition adaptation**, not optimal neural scheduling.

## Interpretation

### Supported

> In this supplied decoder-like toy, one fixed NN can obey a hard maximum-work cap while a scalar resource price changes the physical composition of internal computation. Across three seeds, MLP sublayers are reduced before attention propagation is reduced, and the resulting physical skip changes measured central latency.

### Not supported

- hard real time or WCET;
- optimal subgraph discovery;
- autoregressive language modeling;
- LLM-scale behavior;
- end-to-end sparse training;
- universal ordering that MLP should always be dropped before attention on other tasks/models.

## Next step

Use the same **hard cap + soft price + physically separate attention/MLP** interface in a small causal/autoregressive sequence task. The next question is whether variable computation can reduce per-token generation latency while degrading predictive quality in a controlled way, without scaling the model.
