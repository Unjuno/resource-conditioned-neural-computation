# Claims and limits

## Core Real-Time NN claim now supported in a toy mechanism experiment

The strongest supported statement is now:

> In the supplied toy architecture, one fixed neural network can receive different admitted budgets, physically execute different amounts of its internal computation, and thereby produce a reproducible budget/quality/median-latency trade-off.

The direct experiment measures the complete mechanism chain in one implementation:

```text
budget
  → internal activation depth
  → physically executed blocks / MAC proxy
  → measured end-to-end latency
  → soft deadline behavior
```

This is **not** yet a hard-real-time claim.

## Direct evidence

Across three seeds in `experiments/realtime_nn_budget_execution.py`:

1. all budgets use the same parameter set;
2. budget values `0 / .25 / .5 / .75 / 1.0` execute `0 / 2 / 4 / 6 / 8` optional blocks;
3. forward hooks verify inactive blocks are not called by the hard-skip implementation;
4. a matched dense-mask control executes all eight blocks at every budget;
5. hard-skip and dense-mask produce identical outputs for the same budget;
6. linear MAC proxy increases from 64 at minimum budget to 737,344 at full budget;
7. mean task accuracy increases from **63.67% → 71.48% → 78.52% → 86.33% → 100%**;
8. mean hard-skip median latency increases from **10.53 → 98.80 → 185.69 → 280.26 → 375.82 us**;
9. hard-skip median latency is strictly monotonic in all 3/3 seeds;
10. full-budget/minimum-budget hard-skip latency ratio averages **35.73x**;
11. dense-mask latency remains roughly full-compute latency at every logical budget;
12. under the tightest P95-calibrated soft deadline class, adaptive hard-skip averages **0.13% misses**, while adaptive dense-mask and always-full-depth both average **100% misses**.

This directly establishes that **physical conditional execution**, not a logical mask alone, is responsible for the observed latency reduction in this toy.

See `notes/realtime_nn_budget_execution.md` and `results/realtime_nn_budget_execution_results.json`.

## Timing boundary

The same experiment also produces a negative result that prevents a hard-real-time interpretation:

- raw empirical q99 execution times are not strictly monotonic in any of the three seeds during separate calibration runs;
- ordinary Linux/PyTorch scheduler/preemption jitter contaminates the far tail;
- the deadline admission experiment therefore uses empirical P95 execution classes and is explicitly soft/weakly-hard.

A hard-real-time claim still requires a defensible WCET/static timing argument, time-predictable hardware/runtime, or equivalent evidence.

## What remains open

The current budget-to-depth mapping is deliberately simple and fixed so the physical mechanism can be isolated.

Next-line questions are:

1. can a **learned** budget-conditioned activation policy preserve the same physical budget compliance and latency ordering?
2. can the runtime adapt admitted budgets to changing machine state without relying on unstable Linux tails?
3. can the mechanism be implemented on an RTOS/time-predictable target with analyzable timing?
4. can finer-grained block/channel activation preserve useful quality/latency trade-offs without dense execution overhead?

## Secondary precursor / diagnostic evidence

Earlier experiments still support narrower implementation facts:

- resource conditions can change internal subgraph execution;
- fallback capabilities can be forgotten under naive joint training;
- capability readiness and feasibility-vs-price separation matter;
- supplied primitive supernets can form different hard subgraphs;
- non-separable route/stage cost changes can break simple resource contracts;
- learned allocation can be sensitive to objective and router parameterization;
- empirical Linux tail timing is unstable.

Those experiments remain useful, but they are secondary to the direct budget/work/latency result.

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
budget-conditioned physical execution
```

The runtime owns hardware-specific timing knowledge and feasibility. The NN consumes an admitted budget and changes its execution accordingly.

## Resource proxies

The direct experiment uses an executed linear-MAC proxy plus measured latency. Some older experiments also use a parameter-footprint proxy.

Parameter footprint is **not** measured runtime memory traffic, bandwidth, cache pressure, reduced resident memory, or energy.

## Explicitly not claimed

1. Hard real-time guarantees or WCET bounds.
2. A production Real-Time NN or Real-Time LM.
3. Joule-level energy savings.
4. Measured memory-bandwidth savings or reduced total resident memory.
5. A learned/self-organized budget gate in the direct timing experiment.
6. Input-difficulty-dependent adaptive computation in the direct timing experiment.
7. Universal superiority over early exit, MoE, NAS, once-for-all subnetworks, or external schedulers.
8. Necessity of a learned controller when execution costs are analytically known.
9. General/unconstrained architecture discovery.
10. Arbitrary hardware portability.
11. LLM-scale generalization.
12. Novelty of LUT neurons/networks, dynamic routing, NAS, or runtime subnetwork switching.

## Direction lock

Before promoting a new main-line experiment, ask:

> Does it test whether changing the budget of the **same neural network** changes **actual internal activation**, **actual executed work**, **actual inference time**, or **deadline behavior**?

If not, it belongs under secondary diagnostics.
