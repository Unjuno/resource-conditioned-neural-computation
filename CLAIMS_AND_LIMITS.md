# Claims and limits

## Strongest supported mechanism statement

> In supplied toy architectures, one fixed neural parameter set can receive a runtime-admitted work budget and physically execute different internal computation classes. The tested classes vary both depth and structured active channel width, produce reproducible quality/work trade-offs, and can produce lower measured central latency when the backend actually reduces the executed loops/matrix dimensions.

This is **not** a hard-real-time/WCET claim.

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

### Learned selection under a hard work cap

The runtime admits `k ∈ {1,2,4,8}` expert calls. Hard top-k structurally prevents budget violation.

At `k=4`, the explicitly supervised learned controller reaches **100%** accuracy versus **78.18%** for fixed prefix. Controller overhead is included in timing.

With empirical P95 deadline admission, an intermediate `k≈4` regime gives learned on-time-correct **98.46%** versus **76.00%** for prefix at similar miss rates. A 25-point common-deadline audit reduces concern that this benefit came from selecting only favorable deadlines.

Learned control is not universally better: tight/full-budget regimes can favor simpler policies, and an external analytic relevance oracle remains a strong baseline.

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

1. On a controlled RTOS/time-predictable target, can explicit target/build-specific upper bounds be attached to the validated execution classes?
2. Can useful internal computation be made less analytically exposed than the current toy?
3. Can finer sub-block/neuron activation beyond structured prefix width remain physically cheap on a suitable backend?
4. Later, does the same systems principle transfer to sequence models without making scale itself the objective?

## Secondary diagnostics

Older router/topology experiments remain useful for capability forgetting, shortcut collapse, feasibility-vs-price separation, non-separable resource-contract failures, optimization sensitivity, and timing-tail instability. They are secondary to:

```text
budget → physical activation → exact work → certified timing bound → deadline
```

## Explicitly not claimed

1. Hard real-time guarantees or WCET bounds.
2. A production Real-Time NN or Real-Time LM.
3. Stable machine-state→P95 admission on ordinary Linux.
4. Universal latency benefit from nominal MAC reduction; PyTorch provides a direct counterexample in the structured-width experiment.
5. Joule-level energy savings or measured memory-bandwidth reduction.
6. Universal learned-policy superiority over fixed policies or external schedulers.
7. Necessity of a learned controller when useful-computation information is analytically available.
8. General/unconstrained self-organized architecture discovery or arbitrary neuron sparsity.
9. Arbitrary hardware/timing portability.
10. LLM-scale generalization.
11. Novelty of LUT neurons/networks, dynamic routing, NAS, or runtime subnetwork switching.

## Direction lock

Before promoting a new main-line experiment, ask:

> Does it test the physical chain `budget → activation → work → timing bound → deadline`, or a concrete implementation/runtime condition required to make that chain real-time safe?

If not, it belongs under secondary diagnostics.
