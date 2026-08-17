# Claims and limits

## Core Real-Time NN mechanism supported in toy experiments

The strongest supported statement is now:

> In supplied toy architectures, one fixed neural network can receive an admitted work budget, physically execute only budget-compliant internal computation, and produce a reproducible quality/work/median-latency trade-off. A learned internal controller can also choose **which** admissible computation to execute while the runtime enforces the hard work cap.

This is **not** a hard-real-time/WCET claim.

## Direct fixed-budget execution evidence

Across three seeds in `experiments/realtime_nn_budget_execution.py`:

- all budgets use the same parameter set;
- budgets `0 / .25 / .5 / .75 / 1.0` execute `0 / 2 / 4 / 6 / 8` optional blocks;
- hooks verify inactive blocks are not called;
- a dense-mask control executes all eight blocks at every logical budget;
- hard-skip and dense-mask outputs match;
- mean accuracy is **63.67% → 71.48% → 78.52% → 86.33% → 100%**;
- mean hard-skip median latency is **10.53 → 98.80 → 185.69 → 280.26 → 375.82 us**;
- median latency is strictly monotonic in **3/3 seeds**;
- full/minimum-budget median-latency ratio averages **35.73x**;
- under the tightest P95-calibrated soft deadline class, adaptive hard-skip averages **0.13% misses**, while dense-mask and always-full-depth both average **100% misses**.

This establishes the direct chain:

```text
budget → physical activation → work → measured median latency → soft deadline behavior
```

## Learned activation under a hard runtime cap

`experiments/realtime_nn_learned_budget_gate.py` tests a stronger responsibility split.

The runtime admits exactly `k ∈ {1,2,4,8}` expert calls. A learned relevance-scoring controller chooses which experts to execute, but hard top-k structurally prevents execution beyond the admitted cap.

The controller is trained with explicit relevance supervision; this is not claimed as spontaneous/self-organized routing.

Across three seeds:

| k | learned accuracy | fixed-prefix accuracy | learned median | fixed-prefix median |
|---:|---:|---:|---:|---:|
| 1 | 68.35% | 68.77% | 74.62 us | 56.30 us |
| 2 | **81.90%** | 71.43% | 114.07 us | 95.68 us |
| 4 | **100.00%** | 78.18% | 195.40 us | 171.37 us |
| 8 | 100.00% | 100.00% | 366.21 us | 337.42 us |

Additional audits:

- hard budget compliance passes in **3/3 seeds** at every k;
- learned median latency is strictly monotonic in **3/3 seeds**;
- learned dense-mask executes all eight experts at every budget;
- hard learned and dense learned outputs match within numerical tolerance;
- at `k=4`, learned activation gains about **+21.8 percentage points** over fixed-prefix execution at the same expert-call cap;
- controller overhead is measurable (roughly 18–29 us median versus fixed prefix) and is included in the timing.

This supports the intended responsibility split:

```text
runtime / RTOS: how much work is admissible
NN:             which admissible internal work is useful
```

## Timing boundary

The fixed-depth experiment also produces a negative result that prevents a hard-real-time interpretation:

- raw empirical q99 execution times are not strictly monotonic in any of the three calibration seeds;
- ordinary Linux/PyTorch scheduler/preemption jitter contaminates the far tail;
- deadline admission therefore uses empirical P95 execution classes and is explicitly soft/weakly-hard.

A hard-real-time claim still requires defensible WCET/static timing, a time-predictable runtime/platform, or equivalent evidence.

## What remains open

1. integrate the learned activation controller with deadline admission and compare quality at matched miss rate;
2. remove explicit relevance supervision and test more autonomous learned activation while preserving hard budget compliance;
3. adapt admitted budgets to machine state without relying on unstable Linux tails;
4. test finer-grained structured activation without losing physical skipping;
5. move to an RTOS/time-predictable target or obtain a defensible WCET/static timing argument.

## Secondary diagnostic evidence

Earlier experiments remain useful for:

- capability forgetting and shortcut collapse;
- conditional-subgraph formation;
- feasibility-vs-price separation;
- non-separable resource-contract failures;
- objective/local-minimum sensitivity;
- policy-parameterization sensitivity;
- Linux tail-timing instability.

They are secondary to the direct budget/work/latency results.

## Runtime / RTOS responsibility split

```text
hardware / OS state
    ↓
runtime / RTOS timing/admission model
    ↓
safe admitted normalized budget
    ↓
same neural network
    ↓
budget-compliant learned physical execution
```

The runtime owns hardware-specific timing knowledge and feasibility. The NN chooses computation only inside the admitted work envelope.

## Resource proxies

The direct experiments use executed expert/block counts, linear-MAC proxies, and measured latency. Older experiments may also use a parameter-footprint proxy.

Parameter footprint is **not** measured runtime memory traffic, bandwidth, cache pressure, reduced resident memory, or energy.

## Explicitly not claimed

1. Hard real-time guarantees or WCET bounds.
2. A production Real-Time NN or Real-Time LM.
3. Joule-level energy savings.
4. Measured memory-bandwidth savings or reduced total resident memory.
5. Self-organized discovery of relevance in the learned-controller experiment.
6. Input-dependent variable work beyond the hard runtime cap in the learned-controller experiment.
7. Universal superiority over early exit, MoE, NAS, once-for-all subnetworks, or external schedulers.
8. Necessity of a learned controller when exact execution costs and relevance are analytically available.
9. General/unconstrained architecture discovery.
10. Arbitrary hardware portability.
11. LLM-scale generalization.
12. Novelty of LUT neurons/networks, dynamic routing, NAS, or runtime subnetwork switching.

## Direction lock

Before promoting a new main-line experiment, ask:

> Does it test whether changing the admitted budget of the **same neural network** changes **actual internal activation**, **actual executed work**, **actual inference time**, **quality**, or **deadline behavior**?

If not, it belongs under secondary diagnostics.
