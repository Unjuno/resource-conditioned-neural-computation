# Claims and limits

## Strongest supported mechanism statement

> In supplied toy architectures, one fixed neural parameter set can receive a runtime-admitted work budget and/or a scalar resource price and physically execute different internal computation classes. The tested classes vary depth, structured active channel width, sparse expert width, and transformer-like attention+MLP depth; they produce reproducible quality/work trade-offs and can produce lower measured central latency when the backend actually avoids inactive computation.

This is **not** a hard-real-time/WCET claim. A soft resource price does not replace a hard runtime admission bound.

## Supported direct evidence

### Physical budget execution by depth

Across three seeds:

- one fixed NN physically executes `0/2/4/6/8` optional blocks as budget increases;
- hooks verify inactive blocks are not called;
- mean accuracy increases **63.67% → 71.48% → 78.52% → 86.33% → 100%**;
- hard-skip median latency is strictly monotonic in 3/3 seeds;
- a dense logical mask executes all blocks and does not obtain the speedup.

### Structured channel-width + depth activation

A second toy uses one maximum-width `C=32` parameter set jointly across five classes:

| class | depth | active width | exact slim linear MACs |
|---:|---:|---:|---:|
| 0 | 0 | 8 | 16 |
| 1 | 2 | 8 | 11,408 |
| 2 | 4 | 16 | 91,168 |
| 3 | 6 | 24 | 307,632 |
| 4 | 8 | 32 | 729,152 |

All three seeds preserve the same complete-domain quality ladder **63.67% / 71.48% / 78.52% / 86.33% / 100%**.

The slim path slices actual operands/weights before the matrix operation. A matched dense-width-mask control computes maximum width and zeros inactive channels afterward. In plain C++, slim and dense-mask outputs are identical over all 512 states and all tested classes/seeds.

Three-seed mean central-latency ratios `slim / dense-mask` in the C++ backend are approximately:

- class 1: **0.130**;
- class 2: **0.363**;
- class 3: **0.622**;
- class 4/full width: **0.993**.

This supports structured physical channel activation in the supplied prefix-width architecture.

**Important negative:** on PyTorch CPU batch-1, the same large MAC reductions do not make the slim classes faster; intermediate slim classes are slightly slower than the dense-mask control. Therefore nominal operation reduction alone is not a wall-clock result. The backend/kernel must actually convert the smaller circuit into cheaper execution.

### Loss-conditioned elastic sparse expert width

A third toy gives one fixed sparse NN a scalar resource price `λ`. The internal width controller chooses `k ∈ {0,1,3,4,6,8}` and only the selected top-`k` expensive experts are physically executed.

There are no handwritten price→width labels. For each candidate width the training objective forms

\[
E_k(\lambda)=CE_k+0.55\lambda k/8,
\]

and trains the internal controller to amortize this task-loss/work frontier.

Three-seed forced-width quality ladder:

| executed experts | mean accuracy |
|---:|---:|
| 0 | 49.64% |
| 1 | 81.32% |
| 3 | 87.68% |
| 4 | 91.76% |
| 6 | 95.20% |
| 8 | 96.88% |

Across all three seeds, selected width is non-increasing with increasing price. Representative means:

- `λ=0.00`: `k=8/8/8`, **96.88%**, ~**427 us** hard-skip median;
- `λ=0.70`: `k=4/4/4`, **91.76%**, ~**268 us**;
- `λ=1.50`: `k=3/3/3`, **87.68%**, ~**227 us**;
- `λ=4.00`: `k=0/0/0`, **49.64%**, ~**76 us**.

Matched evidence:

- price-blind controllers remain at one fixed width in **3/3 seeds**;
- seed-0 physical hard-skip and dense-equivalent execution have **0 prediction mismatches** over 300 input/price cases and maximum logit difference `4.77e-7`;
- forward hooks verify that inactive experts are not called;
- one fixed input changes physical trace from 8→6→3→0 executed experts as only price changes;
- the learned controller agrees with a simple held-out `task loss + work cost` width oracle at **28/33** tested seed×price points.

This supports the intended **price → physical propagation → quality/latency** mechanism in a supplied sparse-NN toy.

Important limits:

- the training surrogate evaluates all candidate widths/experts; training-time sparse compute is not demonstrated;
- the toy exposes a simple loss/work table, so an external analytic scheduler can compute an equivalent argmin and remains a strong baseline;
- a soft price is not a hard execution guarantee. For a real-time system, a hard admitted work region should be supplied separately by the runtime.

### Hard cap + soft price in a transformer-like sequence stack

A 9-token local-attention sequence toy contains eight optional self-attention + MLP residual blocks in one parameter set. Each block expands token-0 receptive field by one token.

The runtime provides a hard max-depth cap `0/2/4/6/8`. Disallowed depths are structurally removed from controller choice. A scalar resource price then chooses among the allowed physical depths according to an amortized loss/work objective

\[
E_d(\lambda)=\overline{BCE}_d+0.7\lambda d/8.
\]

Three-seed fixed-depth weighted sequence quality:

| blocks | weighted bit accuracy |
|---:|---:|
| 0 | 58.62% |
| 2 | 74.14% |
| 4 | 86.21% |
| 6 | 94.83% |
| 8 | 100% |

With full cap, **3/3 seeds** use all five execution classes in the same price order: `8 → 6 → 4 → 2 → 0` blocks. Representative mean physical medians are approximately **1.11 ms → 0.85 ms → 0.59 ms → 0.37 ms → 0.09 ms**, while dense-equivalent execution remains near full-depth timing.

Matched evidence:

- hard cap is respected for all tested seed×cap×price points;
- hook execution count matches selected depth in all tested seeds;
- physical hard-skip vs dense-equivalent has **0/750 prediction-vector mismatches** and maximum logit difference **0**;
- full-cap loss/work-oracle agreement is **27/27** tested seed×price points;
- price-blind controls do not change depth with price at fixed cap.

This supports **hard admissibility + soft price-conditioned physical sequence computation** in a supplied transformer-like toy.

Important limits:

- this is not autoregressive language generation;
- capability parameters are trained across all depths and the controller is post-trained from the capability frontier; end-to-end sparse training is not demonstrated;
- the current variable graph is prefix-depth only, not arbitrary attention-head/MLP-expert selection;
- an external analytic scheduler remains a strong baseline when the complete loss/work frontier is available.

### Learned selection under a hard work cap

The runtime admits `k ∈ {1,2,4,8}` expert calls. Hard top-k structurally prevents budget violation.

At `k=4`, the explicitly supervised learned controller reaches **100%** accuracy versus **78.18%** for fixed prefix. Controller overhead is included in timing.

With empirical P95 deadline admission, an intermediate `k≈4` regime gives learned on-time-correct **98.46%** versus **76.00%** for prefix at similar miss rates. A 25-point common-deadline audit reduces concern that this benefit came from selecting only favorable deadlines.

The loss-conditioned elastic-width model has a preliminary seed-0 soft deadline audit as well: at a 489 us deadline, price-conditioned execution gives **89.33% on-time-correct** versus always-full **83.67%**. Another class misses **15.17%** despite an 8% P95 margin, so this does not change the Linux timing boundary below.

Learned control is not universally better: tight/full-budget regimes can favor simpler policies, and external analytic schedulers remain strong baselines when quality/work information is analytically available.

### Task-loss-only selection

Without relevance labels, relevance auxiliary loss, capability warmup, or expert freezing, a supplied hard-cap toy learns useful selection from task loss alone.

Three-seed mean:

| k | task-loss learned | fixed prefix | analytic oracle |
|---:|---:|---:|---:|
| 1 | 69.04% | 67.66% | 69.09% |
| 2 | **81.27%** | 71.37% | 81.80% |
| 4 | **100.00%** | 78.74% | 100.00% |
| 8 | 99.82% | 99.82% | 99.82% |

This supports task-loss-only useful-computation selection **inside a supplied fixed search space**. It does not establish unconstrained self-organized architecture discovery.

## RTOS / implementation evidence

The direct mechanism has been progressively lowered from PyTorch into generated C++ and a freestanding finite-class C core.

Supported implementation facts include:

- exact physical work counts derived from actual control flow and checked by instrumentation;
- freestanding core with no unresolved external symbols;
- fixed caller-owned workspace and no inference heap/file I/O;
- Q5 int16 weights/workspace with int32 accumulators preserving all tested class predictions across three seeds;
- bounded LUT activations and division-free integer residual scaling;
- conservative static integer-range bounds for the tested generated weights;
- target-independent execution manifest separated from target timing certification;
- timing certification interface fails closed for uncertified classes, wrong neural manifest, or wrong deployed-build identity;
- compiler/optimization audit shows identical neural outputs can compile to distinct machine-code objects, so timing evidence must be build-specific.

None of these facts supplies an actual WCET value.

## Runtime machine-state timing boundary

The hypothesis

```text
coarse machine state → one empirical P95 timing table → admitted budget
```

is **not supported on ordinary Linux**.

Same-core scheduler interference creates a fast/preempted mixture. When the preempted fraction crosses the chosen percentile, empirical P95 can jump from sub-millisecond timing into an ~8 ms mode even though the neural execution class is unchanged.

The initial exploratory result suggesting reliable load-specific P95 rescue did not reproduce and is not promoted.

Empirical Linux P95/P99 is not WCET.

## Current open questions

1. Can the sequence result move beyond prefix-depth elasticity to **separately optional attention and MLP expert groups** inside decoder-like blocks while preserving physical skip?
2. Can the hard-cap + soft-price sequence mechanism be lowered to a generated/analyzable backend with explicit finite work classes?
3. On a controlled RTOS/time-predictable target, can target/build-specific upper bounds be attached to those classes?
4. Does the mechanism survive a small autoregressive-generation task before any LLM-scale experiment?
5. Can useful internal computation be made less analytically exposed than the current toy?

## Secondary diagnostics

Older router/topology experiments remain useful for capability forgetting, shortcut collapse, feasibility-vs-price separation, non-separable resource-contract failures, optimization sensitivity, and timing-tail instability. They are secondary to:

```text
hard admissible work region + soft resource price
    → physical activation
    → exact work
    → certified timing bound
    → deadline / quality
```

## Explicitly not claimed

1. Hard real-time guarantees or WCET bounds.
2. A production Real-Time NN or Real-Time LM.
3. Stable machine-state→P95 admission on ordinary Linux.
4. Universal latency benefit from nominal MAC reduction; PyTorch provides a direct counterexample in the structured-width experiment.
5. Joule-level energy savings or measured memory-bandwidth reduction.
6. Universal learned-policy superiority over fixed policies or external schedulers.
7. Necessity of learned price-to-width/depth control when an external quality/work table is analytically available.
8. Training-time sparse execution in the loss-conditioned/sequence experiments.
9. General/unconstrained self-organized architecture discovery or arbitrary neuron sparsity.
10. Arbitrary hardware/timing portability.
11. Autoregressive LM behavior or LLM-scale generalization.
12. Novelty of LUT neurons/networks, dynamic routing, NAS, or runtime subnetwork switching.

## Direction lock

Before promoting a new main-line experiment, ask:

> Does it test the physical chain `hard admissible work + resource price → activation → work → timing bound → deadline/quality`, or a concrete implementation/runtime condition required to make that chain real-time safe?

If not, it belongs under secondary diagnostics.
