# Continuous-budget learned ordering audit

## Question

Can one fixed NN accept a continuous runtime budget control while exposing finite physical execution classes whose per-input paths are nested as budget increases, without losing the quality benefit of learned input-dependent selection?

This experiment is intentionally narrower than an RTOS/WCET claim. It tests the neural execution mechanism that would sit below runtime admission.

## Hypothesis H1: nested ordering versus free reordering

**H.** A per-input learned ordering that is independent of budget can use `top-k` prefixes to guarantee nested physical paths, while preserving nearly all quality of a budget-conditioned free-ranking policy and beating a fixed prefix at intermediate work.

**T.** Three training seeds. Eight optional experts. Runtime control `beta in [0,1]` is mapped to one of eight finite expert-call classes. Training samples `beta ~ Uniform(0,1)` and uses task loss only; there are no relevance labels. The nested policy scores expert identity/query compatibility from the input only; the free policy also receives `beta`. Single-sample forward hooks audit exact physical expert calls. Unseen beta values are evaluated separately.

**D. PASS iff** all nested paths have zero set-inclusion violations; all hook audits execute exactly the admitted `k`; the mean free-minus-nested accuracy gap is at most 2 percentage points; and nested beats fixed prefix by at least 5 points at `k=4`.

**C.** If free reordering materially outperforms nested ordering, nestedness is too restrictive. If hooks exceed `k`, the policy is only masking outputs rather than constraining physical work.

**U.** Main uncertainties are seed sensitivity, finite training steps, PyTorch/backend overhead, and the synthetic task. Timing values are empirical Linux/container measurements, not WCET.

## Result H1

Three-seed aggregate at 800 optimization steps:

| k | nested accuracy | free accuracy | fixed prefix |
|---:|---:|---:|---:|
| 1 | 68.62% | 68.92% | 67.10% |
| 2 | 80.40% | 81.08% | 69.08% |
| 3 | 83.00% | 82.30% | 73.93% |
| 4 | **100.00%** | **100.00%** | **77.55%** |
| 5 | 100.00% | 99.97% | 80.97% |
| 6 | 99.87% | 99.83% | 85.60% |
| 7 | 99.17% | 99.23% | 89.85% |
| 8 | 98.12% | 98.33% | 98.12% |

Additional checks:

- nested path set-inclusion violations: **0** across all audited seed/sample/class comparisons;
- free-policy violations: **273** total, showing that budget-conditioned scores can genuinely reorder paths;
- hard-cap hook checks: **all pass**;
- mean free-minus-nested accuracy gap across classes: **+0.06 percentage points**;
- nested `k=4` minus prefix: **+22.45 percentage points**;
- mean accuracy on unseen continuous budget points: nested **91.15%**, free **91.20%**;
- with only 5 timing repetitions per class, strict nested median-latency ordering holds in **1/3 seeds**; this low-sample container timing is deliberately not used as evidence for a timing contract.

**Decision: PASS for H1.** On this task, nested learned ordering obtains essentially the same quality as free budget-conditioned reordering while giving a much cleaner execution contract.

## Hypothesis H2: more admitted work implies non-decreasing task quality

**H.** Because nested execution only adds experts, task accuracy should be non-decreasing as `k` increases.

**T.** Use the same three 800-step nested models and inspect all adjacent class transitions.

**D. PASS iff** accuracy is non-decreasing across all eight classes in all three seeds.

## Result H2

This hypothesis is **falsified**.

- strict non-decreasing seeds: **0/3**;
- seed 0: maximum adjacent drop **0.45 pt**, `k=4 -> 8` drop **0.80 pt**;
- seed 1: maximum adjacent drop **1.50 pt**, `k=4 -> 8` drop **2.05 pt**;
- seed 2: maximum adjacent drop **1.40 pt**, `k=4 -> 8` drop **2.80 pt**;
- mean `k=4 -> 8` drop: **1.88 pt**.

The earlier 400-step run was much worse, with mean class-8 quality only about 80.6%, while 800 steps raised it to about 98.1%. Therefore part of the failure is optimization/convergence, but exact monotonic quality still does not follow from nested physical execution.

**Decision: FAIL for H2.** Set inclusion of compute paths is not a sufficient condition for monotone utility. Additional computation can perturb the representation and hurt the final decision.

## Interpretation

This separates two properties that must not be conflated:

1. **execution monotonicity:** larger budget physically contains the smaller-budget path; this experiment achieves it by construction;
2. **utility monotonicity:** larger budget never reduces task quality; this experiment does not guarantee it.

The next experiment should target utility monotonicity explicitly, for example with incremental residual corrections plus a cross-budget consistency/ranking objective, while preserving the exact same hard-cap and hook audits.

## Reproduction

The experiment is runnable directly in a Python environment with PyTorch 2.10 CPU, or through the repository CPU container definition:

```bash
docker build -f container/Dockerfile.cpu -t rtnn-continuous-budget .
docker run --rm -v "$PWD/results:/workspace/results" rtnn-continuous-budget
```

The ChatGPT execution environment used for the recorded result was itself a Linux container on x86-64 AMD EPYC 7763 virtual CPUs, Python 3.13.5, PyTorch 2.10.0+cpu; the experiment forces one PyTorch intra-op thread. Docker was not available inside that container, so the Dockerfile was syntax-reviewed but not image-built there.

## Nonclaims

This experiment does not establish WCET, hard real-time behavior, RTOS integration, energy reduction, hardware portability, or generalization beyond the supplied synthetic task.
