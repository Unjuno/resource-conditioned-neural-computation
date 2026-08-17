# Experiment plan: direct Real-Time NN mechanism

## Objective

Test the intended mechanism directly:

> With one fixed neural network, a runtime-admitted work/time budget constrains physical execution, the NN learns which admissible internal computation is useful, and the resulting work/quality/latency relation supports deadline-aware behavior.

A controller/gate is an implementation mechanism, not the research target.

## Progress

- **Physical budget-conditioned block execution:** PASS.
- **Learned module selection under a hard runtime cap:** PASS.
- **Learned activation + empirical deadline admission:** PASS as soft/weakly-hard.
- **Task-loss-only selection without relevance labels:** PASS in the supplied key/query toy.
- **Less analytically exposed useful-computation task:** NEXT MODEL-SIDE FALSIFICATION.
- **Machine-state-aware runtime admission:** OPEN.
- **Finer-grained structured physical activation:** OPEN.
- **Hard timing guarantee / WCET:** OPEN.

## Completed mechanism chain

The current toy experiments now cover:

```text
runtime deadline/budget
    → hard physical work cap
    → learned budget-compliant activation
    → executed work
    → measured latency
    → task quality / on-time quality
```

Task-loss-only training demonstrates that the selection signal does not have to be supplied as an explicit relevance label in the current fixed search space.

## Current task-only result

Eight slots carry categorical keys and values; a global query identifies the useful slots only through ordinary task features. No relevance targets are used during training.

At `k=4`:

- learned accuracy: **100%**;
- fixed-prefix accuracy: **78.74%**;
- analytic key/query oracle: **100%**;
- selected useful-slot fraction: **100%**.

Physical hard-skip timing remains monotonic in 3/3 seeds.

The task is still analytically simple enough that an external key/query oracle exists. Therefore the next model-side experiment should make useful computation less directly exposed rather than merely making the controller larger.

## Next model-side falsification

Construct a task where the value of an internal computation is **latent or interaction-dependent**, while keeping the same systems contract:

```text
runtime admits k
NN chooses ≤ k physical modules
selection trained from task loss
```

Candidate requirements:

1. no direct relevance flag or simple key==query oracle at the controller input;
2. useful modules depend on learned intermediate representation or interactions;
3. hard work cap remains structural;
4. physical execution and timing audits remain unchanged;
5. a strong external baseline is retained when one can be defined;
6. negative collapse is reported rather than repaired by unrelated router optimization.

Do not scale model size for its own sake.

## Next runtime-side falsification

Add a machine-state variable that changes actual execution timing while leaving model weights fixed.

Runtime question:

> Can the runtime remap deadline + observed machine state to a conservative admitted work budget without retraining the NN?

This should be tested first under controlled CPU-frequency/load states if available, while explicitly retaining the Linux tail limitation.

A stronger follow-up should move to an RTOS/time-predictable target.

## Finer physical activation — OPEN

Test channel/neuron/sub-block groups only when inactive work is **physically skipped**. Dense zero masks do not count as compute reduction.

Measure controller overhead, work reduction, latency, quality, and variance.

## Hard timing guarantee boundary — OPEN

Ordinary Linux/PyTorch timing is not WCET.

Current experiments repeatedly show unstable/non-monotonic high-percentile timing even when medians are well ordered.

A hard-real-time experiment requires statically analyzable generated inference code, a time-predictable target, controlled RTOS interference assumptions, formal/static WCET, or an accepted equivalent.

## Direction rule

Do not expand router/NAS experiments unless they solve a concrete failure in:

```text
budget → physical activation → work → latency → deadline
```
