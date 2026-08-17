# Direct Real-Time NN budget / execution / latency experiment

## Question

Can **one fixed neural network** change the internal computation it physically executes when only an admitted budget changes, and does that produce a measurable latency/quality trade-off that a runtime can use?

This experiment is intentionally not a router benchmark. The budget-to-depth controller is a simple fixed monotone mapping so the experiment isolates the systems mechanism:

```text
budget B
  -> active internal blocks
  -> physically executed work
  -> measured inference latency
  -> task quality / deadline behavior
```

## Model and task

The model contains one embedding, eight optional local-information-propagation blocks, and one shared classifier head. All budget levels use the **same parameter set**.

The task is 9-bit majority over the complete 512-state finite domain. The classifier reads only position 0. Each optional block can propagate information by at most one position from right to left, so increasing executed depth expands the effective receptive field.

Budget levels map to executed depths:

| budget | active blocks |
|---:|---:|
| 0.00 | 0 |
| 0.25 | 2 |
| 0.50 | 4 |
| 0.75 | 6 |
| 1.00 | 8 |

The model is trained jointly at all five depths, then frozen before timing measurements.

## Physical-skip audit

Two inference implementations use exactly the same weights and produce identical logits:

- `hard_skip`: inactive blocks are never called;
- `dense_mask`: all eight blocks execute, then inactive updates are multiplied away.

Forward hooks verify, in all three seeds and all five budgets:

- `hard_skip` executes exactly `0 / 2 / 4 / 6 / 8` blocks;
- `dense_mask` executes all 8 blocks at every budget;
- hard-skip and dense-mask outputs are identical to numerical precision.

This is the key control against claiming a latency benefit from a logical mask that still performs dense computation.

## Three-seed result

All timing uses batch size 1, PyTorch CPU with one thread, process CPU affinity where available, `perf_counter_ns`, randomized timing sweep order, and three timing rounds per seed. These are ordinary Linux measurements, not WCET.

### Quality and actual latency

| budget | active blocks | linear MAC proxy | mean accuracy | hard-skip median latency | dense-mask median latency |
|---:|---:|---:|---:|---:|---:|
| 0.00 | 0 | 64 | 63.67% | 10.53 us | 409.29 us |
| 0.25 | 2 | 184,384 | 71.48% | 98.80 us | 394.08 us |
| 0.50 | 4 | 368,704 | 78.52% | 185.69 us | 385.65 us |
| 0.75 | 6 | 553,024 | 86.33% | 280.26 us | 377.99 us |
| 1.00 | 8 | 737,344 | 100.00% | 375.82 us | 364.96 us |

Across all three seeds:

- hard-skip median latency is strictly increasing with admitted budget;
- the full-budget / minimum-budget hard-skip median latency ratio averages **35.73x** (minimum seed **34.76x**);
- the dense-mask low/high median ratio is only **0.89x**, i.e. reducing the logical budget does not produce the expected speedup when all blocks still execute;
- all hook audits and hard-vs-dense output-equality audits pass.

This directly supports the intended mechanism in this toy implementation:

> smaller admitted budget -> smaller physically executed circuit -> less executed work -> lower measured median latency, with a corresponding quality reduction.

## Same-input counterfactual

For the same frozen model and the same fixed input, changing only `B` changes the actual forward-hook trace from no optional blocks through progressively deeper prefixes. No model swap or weight change occurs between the counterfactual runs.

## Deadline admission prototype

A second test treats each budget depth as an execution class. A calibration pass measures empirical timing for each class. Because ordinary Linux tails are unstable, the prototype uses an empirical **P95** bound plus a monotone conservative envelope for soft/weakly-hard admission.

The runtime chooses the largest budget whose calibrated P95 execution-class bound fits the current deadline. The admission decision itself is included in the adaptive-policy timing.

Mean deadline-miss rates across three seeds:

| target execution class | adaptive hard-skip | adaptive dense-mask | always full depth |
|---:|---:|---:|---:|
| B=0.00 | **0.13%** | 100.0% | 100.0% |
| B=0.25 | **2.00%** | 69.0% | 68.8% |
| B=0.50 | **3.67%** | 22.13% | 17.07% |
| B=0.75 | **4.60%** | 9.60% | 7.80% |
| B=1.00 | 5.47% | 7.87% | **4.07%** |

Under tight deadlines, physically skipping computation is therefore materially different from merely selecting a lower logical budget while still executing every block.

This is a **soft/weakly-hard statistical prototype**, not a hard-real-time guarantee.

## Important negative timing result

The raw empirical q99 execution times were **not strictly increasing in any of the 3 seeds** during the separate calibration runs.

That matters. Median/P95 execution classes are usable in this toy Linux process, but the far tail is contaminated by scheduler/preemption jitter. The experiment therefore does **not** establish WCET, deterministic latency, or hard-real-time safety.

This reproduces the earlier conclusion that ordinary Linux/PyTorch timing cannot be promoted into a hard-RT argument merely by taking a high empirical percentile.

## What this experiment supports

In this supplied toy architecture:

1. one fixed neural parameter set can expose multiple budget-conditioned internal execution levels;
2. changing only budget changes the modules actually called;
3. actual operation count changes with budget;
4. measured median inference latency changes monotonically with executed work across all three seeds;
5. a quality/latency trade-off is obtained from the same network;
6. a simple empirical runtime can use those execution classes to reduce deadline misses under tight soft deadlines;
7. a dense-mask control shows that physical skipping, not logical masking alone, is necessary for the measured speedup.

## What it does not support

- hard real time or WCET guarantees;
- a learned/self-organized budget gate: the budget-to-depth mapping is deliberately simple and fixed here;
- input-difficulty-dependent routing;
- arbitrary network architectures or hardware targets;
- physical energy savings;
- LLM-scale generalization;
- superiority over a hand-written external scheduler when execution costs are already known.

## Next experiment

The next primary step is to keep the same physical conditional-execution audit but replace the fixed budget-to-depth mapping with a **learned budget-conditioned activation policy constrained to respect the admitted budget**, then repeat the work/latency/deadline measurements. A separate RTOS/time-predictable target is required before making any hard-real-time claim.
