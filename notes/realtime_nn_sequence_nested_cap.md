# Continuous-budget nested routing on an autoregressive sequence task

## Research question

Can the main Real-Time NN mechanism move from the independent-expert toy into a causal residual sequence model without falling back to fixed prefix depth?

The experiment uses a six-block local-attention + MLP residual stack. A five-bit prompt contains one mode bit and four data bits. Mode 0 generates the reversed four data bits; mode 1 generates four cyclic adjacent XORs. All 32 prompts are exhaustively evaluated under autoregressive rollout.

The control contract is deliberately split into two parts:

1. an input-dependent but budget-independent ranking of the six residual blocks;
2. a runtime work control that maps the admitted budget to a finite execution class.

Selected blocks are physically called only when active and always execute in canonical block order. No relevance/path teacher is used.

## Experiment E — learned nested non-prefix routing

### Hypothesis

At the same exact work class, input-dependent nested top-k block selection should outperform both fixed prefix depth and a global learned ordering at intermediate work, while preserving the full-work endpoint and exact physical call caps.

### Protocol

- classes: `0 / 2 / 4 / 6` executed blocks;
- five training seeds;
- 400 optimizer updates;
- all four execution classes trained on every update;
- task loss only;
- policies: fixed prefix, global learned ordering, input-dependent learned ordering;
- single-sample hard-path hook audit for exact physical calls;
- exhaustive generation over all 32 prompts.

### Result

Five-seed mean generation quality:

| blocks | prefix token | global token | input-dependent token | prefix exact | input-dependent exact |
|---:|---:|---:|---:|---:|---:|
| 0 | 56.25% | 56.25% | 56.25% | 12.50% | 12.50% |
| 2 | 59.69% | 59.69% | **74.06%** | 15.63% | **44.38%** |
| 4 | 83.28% | 74.84% | **94.53%** | 53.75% | **85.63%** |
| 6 | 95.94% | 96.25% | **96.09%** | 86.25% | 85.63% |

At intermediate work, input-dependent routing beats prefix by:

- `k=2`: **+14.38 pp token**, **+28.75 pp exact sequence**;
- `k=4`: **+11.25 pp token**, **+31.88 pp exact sequence**.

Against the global learned ordering, the `k=4` token advantage is **+19.69 pp**.

The input-dependent policy uses on average **6.6 distinct routes at k=2** and **8.4 at k=4** across the 32 prompts. Nested-set violations are **0** and all exact hard-cap checks pass.

**Decision: PASS.** The useful effect is not merely a globally better block permutation; the prompt-conditioned route matters.

### Negative result: exact work is not utility-monotone

The stronger claim that forcing more executed blocks always improves task quality is false on this sequence task. Exact-k input-dependent routing is token-accuracy monotone in only **3/5 seeds**. Mean maximum adjacent regression is **0.625 pp** and the worst observed regression is **1.5625 pp**.

Increasing training from 400 to 800 steps removed the regression in one problematic seed but not another, so this is not explained by simple undertraining alone. Increasing the full-depth loss weight restored monotonicity in the tested problematic seed but materially reduced the useful intermediate-work frontier. That intervention is therefore not adopted as the primary solution.

## Experiment F — budget is a cap, not an obligation to consume work

The exact-k failure exposes a semantic error in the earlier control interface: a runtime budget is normally a **maximum admissible work**, not a command to consume all of it.

Each prompt therefore receives an input-specific preferred computation level `r(x)`. At runtime, the effective physical work is the preferred level truncated by the admitted cap. The preferred-compute controller is post-trained from the per-input task cross-entropy of the already learned exact paths. It receives no relevance or path labels.

### Protocol

- same five backbone/ranking seeds and `0/2/4/6` hard classes;
- backbone/ranking: 400 joint exact-class updates;
- preferred-compute controller: 1,200 updates on per-input task CE;
- exhaustive 32-prompt autoregressive evaluation;
- structural cap/count monotonicity and path nesting audit.

### Result

Five-seed mean cap-conditioned generation:

| cap | token accuracy | exact sequence | mean executed blocks |
|---:|---:|---:|---:|
| 0 | 56.25% | 12.50% | 0.000 |
| 2 | 74.06% | 44.38% | 2.000 |
| 4 | 94.53% | 85.63% | 4.000 |
| 6 | **98.59%** | **95.00%** | **5.013** |

Compared with forcing exact `k=6`, the cap policy changes the full-cap endpoint by:

- token accuracy: **+2.50 pp**;
- exact sequence rate: **+9.375 pp**;
- mean physical work: **-0.9875 blocks**.

Both token accuracy and exact sequence rate are non-decreasing with cap in **5/5 seeds**. Nested-path violations are **0**, cap/count-monotonicity violations are **0**, and hard physical call checks pass.

**Decision: PASS.** The correct runtime abstraction for this RTNN family is `budget as cap + learned preferred compute`, not `budget as exact required work`.

## Experiment G — finer finite execution classes

The cap policy was then retrained with all seven finite block-count classes `0..6` to test whether a more continuous control surface can be exposed without losing the finite execution contract.

Five-seed mean results:

| cap | token accuracy | exact sequence | mean executed blocks |
|---:|---:|---:|---:|
| 0 | 56.25% | 11.88% | 0.000 |
| 1 | 69.69% | 30.00% | 1.000 |
| 2 | 77.03% | 46.25% | 2.000 |
| 3 | 85.31% | 67.50% | 3.000 |
| 4 | 92.81% | 82.50% | 3.956 |
| 5 | 96.88% | 91.25% | 4.494 |
| 6 | **98.13%** | **93.75%** | **4.738** |

Relative to the four-class cap policy at full cap, seven-class control reduces mean executed work by another **0.275 blocks**, with a **0.469 pp token** and **1.25 pp exact-sequence** reduction. Both quality metrics remain cap-monotone in **5/5 seeds**, with zero nesting/cap violations.

**Decision: PASS under the preregistered tradeoff bound**: finer granularity reduces work while keeping full-cap token loss within 1 pp and exact-sequence loss within 2 pp.

## Interpretation

The sequence experiment changes the preferred RTNN interface:

```text
continuous budget / remaining deadline
        -> finite admissible work cap
        -> input-specific preferred compute
        -> cap truncation
        -> input-specific nested block ranking
        -> physical residual-block subset
```

This preserves a finite static work-class surface for later timing certification while allowing the NN to decline harmful or unnecessary extra computation.

The preferred-compute controller is currently post-trained from the finite per-input task-loss table. This is a diagnostic and deployable finite-policy construction, but it is not yet the final end-to-end training method. A next experiment should compare this construction with direct policy-gradient / straight-through stop training and test whether the same cap semantics survive on real data.

## Environment and nonclaims

Recorded runs used:

- x86-64 Linux container;
- AMD EPYC 7763 64-Core Processor virtual CPU;
- Python 3.13.5;
- PyTorch 2.10.0+cpu;
- one PyTorch intra-op thread.

Python compilation and short end-to-end smoke runs pass. Docker definitions are supplied, but Docker itself is unavailable inside the current execution container, so the image is not built in-session.

No WCET, hard-real-time, RTOS deployment, energy, or general language-model claim is made.
