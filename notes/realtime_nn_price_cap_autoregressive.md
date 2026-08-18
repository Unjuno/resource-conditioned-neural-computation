# Hard-cap + price-conditioned autoregressive generation

## Question

Can the Real-Time NN mechanism change **actual autoregressive generation work per token** rather than only a parallel sequence pass?

The tested interface is:

```text
runtime hard max-depth cap
        +
soft resource price λ
        ↓
one fixed causal sequence model
        ↓
physical local-attention+MLP depth per generation step
        ↓
greedy next-token quality / per-token latency
```

The hard cap is the admissibility mechanism. Price is a soft compute-value signal inside that cap.

## Autoregressive task

The prompt is four independent bits. The model must generate the prompt in reverse order, one token at a time:

```text
prompt:  a b c d
output:  d c b a
```

All 16 possible prompts are used, so evaluation is complete over this finite toy domain.

The causal model uses local attention that can see only the current token and its immediate predecessor. Each executed block expands the last-token receptive field backward by one position. As generation progresses, later outputs require information farther back in the original prompt.

## Architecture

One fixed model contains binary token/position embeddings, six local causal attention+MLP residual blocks, a shared next-token head, and a controller receiving `(resource price, hard max depth)`.

Physical execution depths are `0 / 2 / 4 / 6` blocks. At each generated token, only the selected prefix depth is called. A dense-equivalent control runs all six blocks but reads the saved representation at the selected depth.

## Capability training

All depths are trained using **equal next-token cross-entropy over all four generated tokens**. Resource-price weighting is not used to make the capability network neglect later tokens.

Three-seed greedy quality is identical:

| depth | token accuracy | exact 4-token generation |
|---:|---:|---:|
| 0 | 62.5% | 12.5% |
| 2 | 75.0% | 25.0% |
| 4 | 87.5% | 50.0% |
| 6 | 100% | 100% |

Full depth therefore generates every prompt exactly in 3/3 seeds.

## Controller utility

For runtime allocation, the finite four-token generation horizon uses a discounted utility weighting `1.0 / 0.8 / 0.5 / 0.2`. Capability training remains equal-token NLL. The discount is used only in the allocation objective:

\[
E_d(\lambda)=CE^{discounted}_d + \lambda d/6.
\]

The controller amortizes the minimum-energy depth while structurally excluding depths above the runtime cap.

## Three-seed price result

All three seeds select the same public depth sequence as price rises:

```text
λ = 0.0–0.1  → depth 6
λ = 0.2–0.4  → depth 4
λ = 0.5–1.0  → depth 2
λ >= 1.3     → depth 0
```

Three-seed mean generation result:

| depth | token accuracy | exact sequence | physical median/token | dense-equivalent median/token |
|---:|---:|---:|---:|---:|
| 6 | 100% | 100% | ~0.76 ms | ~0.75 ms |
| 4 | 87.5% | 50% | ~0.50 ms | ~0.77 ms |
| 2 | 75% | 25% | ~0.27 ms | ~0.75 ms |
| 0 | 62.5% | 12.5% | ~0.017 ms | ~0.74 ms |

Thus the same weights exhibit the intended behavior during greedy generation:

> cheaper / more available compute → deeper propagation → better generation → longer per-token inference;
>
> expensive / constrained compute → shallower propagation → worse generation → earlier token response.

## Hard-cap audit

For caps `0/2/4/6`, tested across multiple prices and all three seeds, selected depth never exceeds the cap. Low price uses the largest useful allowed depth; higher price can voluntarily use less than the hard allowance.

This is the intended two-layer control:

```text
RTOS/runtime: maximum admissible work
NN price policy: how much of that allowance is worth spending
```

## Physical execution audit

Across three seeds and six representative prices:

- physical-vs-dense greedy-generation mismatches: **0 / 288** prompt×price cases;
- a fixed-prompt forward-hook audit records exactly `depth × 4` block calls for four generated tokens;
- inactive blocks are not called in the hard path.

Dense-equivalent execution stays near full-depth generation latency even when it returns the same tokens as a shallow physical path. The speed difference therefore comes from physical non-execution rather than only an output-side mask.

## Price-blind control

Matched controllers with the price coordinate zeroed select depth 2 for every tested price in all three seeds at full cap. The aware depth transition is therefore a response to the supplied price signal, not merely a fixed sparse operating point.

## Loss-oracle audit

For the discounted finite-horizon utility, the aware controller matches the analytic loss/work argmin on **33/33** public seed×price points.

As in earlier toys, this also defines a nonclaim: if an external scheduler owns the complete capability/work table, it can compute the argmin directly. The learned controller is an amortized internal interface, not demonstrated to be necessary or superior.

## Equal-token NLL negative result

If the allocation objective uses the same equal-token NLL as capability training, depth 4 is technically Pareto-optimal but only over an extremely narrow price interval.

Across the three seeds, the depth-4 optimal interval width is only about `0.00051–0.00065` price units, mean about **0.00059**. A practical amortized controller can therefore jump directly from depth 6 to depth 2.

This is an important systems result:

> exposing more execution classes does not guarantee that every class is useful; the quality utility and work model determine which classes lie on a meaningful runtime frontier.

The discounted finite-horizon utility is used in the main price sweep to create diminishing marginal value across generation depth. It must not be confused with standard equal-token language-model NLL.

## Interpretation

### Supported

> In this finite causal-generation toy, one fixed sequence model can obey a hard maximum-depth cap and use a scalar resource price to change physically executed work during autoregressive greedy generation, producing a reproducible per-token quality/latency trade-off.

This is the closest current experiment to the intended Real-Time LM mechanism.

### Not supported

- natural-language modeling;
- LLM-scale behavior;
- hard real-time / WCET;
- standard LM NLL automatically producing a rich execution-class frontier;
- end-to-end sparse training;
- necessity of a learned controller when the complete capability/work table is externally available.

## Next step

Combine the previous **separately skippable attention/MLP suboperations** with this causal generation task. That would test whether price changes not only generation depth but the *type* of computation spent per generated token.

The runtime-side requirement remains unchanged: a real RTOS must supply certified admissible work bounds for a concrete deployed build before price-conditioned generation can make a hard deadline claim.
