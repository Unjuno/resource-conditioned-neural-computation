# Experiment plan: direct Real-Time NN mechanism

## Objective

Test the intended mechanism directly:

> With one fixed neural network, changing an admitted compute/time/resource budget changes which internal computation is physically executed, and this changes measured inference latency in a predictable direction while the NN may choose which admissible computation is useful.

A controller/gate is an implementation mechanism, not the research target.

## Progress

- **Phase 1 — budget-conditioned physical block execution:** PASS.
- **Phase 2a — learned module selection under a hard runtime work cap:** PASS with explicit relevance supervision.
- **Phase 2b — finer-grained channel/neuron/sub-block activation:** OPEN.
- **Phase 3a — deadline-to-budget runtime with fixed execution classes:** PARTIAL PASS as empirical P95 soft/weakly-hard.
- **Phase 3b — learned activation + deadline admission:** NEXT PRIMARY EXPERIMENT.
- **Phase 4 — hard timing guarantee / WCET:** OPEN; not established.

See:

- `notes/realtime_nn_budget_execution.md`
- `notes/realtime_nn_learned_budget_gate.md`

## Phase 1 — Budget-conditioned block execution — PASS

One fixed network uses budgets `0 / .25 / .5 / .75 / 1.0` to physically execute `0 / 2 / 4 / 6 / 8` optional blocks.

Across three seeds:

- hard-skip hooks match admitted depth;
- dense-mask executes all blocks;
- hard-skip median latency is strictly monotonic;
- accuracy and latency form a reproducible trade-off;
- dense logical masking without physical skipping does not obtain the speedup.

## Phase 2a — Learned activation under a hard cap — PASS

A second network contains eight optional expert modules.

The runtime admits exactly `k ∈ {1,2,4,8}` expert calls. A learned controller chooses which experts to execute, but hard top-k prevents execution beyond the cap.

The controller currently uses explicit relevance auxiliary supervision. Therefore this is a controlled learned-activation result, not autonomous self-organization.

Across three seeds:

- hard budget compliance passes at every k;
- learned median latency is strictly monotonic in every seed;
- dense-mask executes all eight experts at every budget;
- at `k=4`, learned activation reaches **100%** accuracy versus **78.18%** for fixed prefix;
- controller overhead is retained in end-to-end timing.

This supports:

```text
RTOS/runtime: how much work may execute
NN:           which admissible internal work is useful
```

## Phase 2b — Finer physical activation — OPEN

Test structured groups only when inactive work is physically skipped:

- channel groups;
- neuron groups;
- residual sub-blocks;
- optional module groups.

Measure controller overhead, work reduction, latency, quality, and timing variance.

Do not use zero masks that leave the dense kernel unchanged.

## Phase 3a — Deadline-to-budget runtime — PARTIAL PASS

The fixed-depth experiment maps deadlines to empirical P95 execution classes.

Under tight deadlines, adaptive hard-skip materially reduces misses compared with always-full execution and dense-mask execution.

This remains a **soft/weakly-hard** demonstration because ordinary Linux tails are unstable.

## Phase 3b — Learned activation + deadline admission — NEXT

Calibrate timing classes including learned-controller overhead.

For each request:

```text
deadline D + machine state S
          ↓
runtime admits expert/block budget k
          ↓
NN chooses which k admissible modules to execute
          ↓
physical execution
```

Required comparisons:

1. learned selection at admitted k;
2. fixed-prefix execution at the same k;
3. dense-mask learned selection;
4. always-full execution;
5. external scheduler where exact relevance/cost is analytically available.

Primary metrics:

- quality at matched deadline-miss rate;
- miss rate at matched quality;
- controller/runtime overhead;
- physical budget compliance;
- timing-class stability.

## Phase 4 — Timing guarantee boundary — OPEN

Ordinary Linux/PyTorch timing is not WCET.

Raw empirical q99 timing is already known to be unstable/nonmonotonic in the fixed-depth calibration experiment.

A stronger hard-real-time experiment requires one of:

- statically analyzable generated inference code;
- a time-predictable embedded target;
- controlled RTOS scheduling/interference assumptions;
- formal/static WCET or an accepted equivalent.

Do not infer WCET from median/P95/P99 Linux measurements.

## Next autonomy step

After learned activation + deadline admission works, reduce or remove explicit relevance supervision.

The controller should then learn useful admissible activation from task loss and budget constraints while preserving:

- hard runtime work cap;
- physical skipping;
- measurable latency ordering;
- task capability.

This is the point where prior routing/topology diagnostics may become useful again—but only to solve concrete failures in the physical timing chain.

## Direction rule

Do not expand router/NAS experiments unless they answer a concrete failure in:

```text
budget → physical activation → work → latency → deadline
```
