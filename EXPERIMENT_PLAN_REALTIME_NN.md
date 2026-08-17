# Experiment plan: direct Real-Time NN mechanism

## Objective

Test the intended system directly:

> A runtime admits a bounded amount of neural work; one fixed NN physically executes only admissible computation and may learn which admissible computation is useful; the runtime must derive that budget from a defensible timing/interference model.

## Progress

### Model side

- **Physical budget-conditioned depth execution:** PASS.
- **Structured channel-width + depth physical activation:** PASS in the supplied prefix-width toy.
- **Learned selection under a hard runtime cap:** PASS.
- **Task-loss-only useful-computation selection:** PASS in the supplied toy search space.
- **Learned selection + empirical soft deadline admission:** PASS with caveats.
- **Execution-class granularity / capability co-design:** PASS as a toy audit.
- **Less analytically exposed useful-computation task:** OPEN.
- **Arbitrary neuron/sub-block physical activation:** OPEN; structured prefix width is not arbitrary sparsity.

### Runtime / implementation side

- **Empirical central-latency execution classes on ordinary Linux:** usable only as toy soft/weakly-hard evidence.
- **Coarse machine-state → empirical P95 timing table:** FAIL / unstable under uncontrolled same-core Linux interference.
- **Generated C++ physical conditional execution:** PASS as an implementation bridge.
- **Freestanding/fixed-point finite-class core:** PASS as an RTOS integration boundary.
- **Exact physical work accounting:** PASS; runtime-facing work values are derived from control flow and instrumentation.
- **Target-independent work manifest + target timing binding:** PASS as an interface/property-test result; no real timing bounds embedded.
- **Timing certification bound to deployed build identity:** PASS as an interface requirement after compiler-matrix falsification.
- **Controlled RTOS/interference-aware timing certification:** NEXT PRIMARY RUNTIME MILESTONE.
- **Hard timing guarantee / WCET:** OPEN.

## Structured width result

One maximum-width `C=32` network is jointly trained for five classes:

| class | depth | active width | exact slim linear MACs |
|---:|---:|---:|---:|
| 0 | 0 | 8 | 16 |
| 1 | 2 | 8 | 11,408 |
| 2 | 4 | 16 | 91,168 |
| 3 | 6 | 24 | 307,632 |
| 4 | 8 | 32 | 729,152 |

All three seeds preserve the complete-domain quality ladder `63.67 / 71.48 / 78.52 / 86.33 / 100%`.

A matched dense-width-mask control computes maximum width but zeros inactive channels afterward. In plain C++, slim and dense-mask outputs are identical over all 512 states, while three-seed mean p50 ratios `slim/dense` are approximately:

```text
class 1: 0.130
class 2: 0.363
class 3: 0.622
class 4: 0.993
```

The PyTorch batch-1 control is an important negative: despite large MAC reductions, slim tensor slicing is not faster there for the intermediate classes. Therefore the Real-Time NN mechanism requires both:

1. a network that exposes a smaller physical circuit; and
2. a backend that maps the smaller circuit to genuinely cheaper execution.

See `notes/realtime_nn_structured_width.md`.

## Execution-class rule

A runtime-admissible class is valid only after:

1. **capability validation** under training/evaluation;
2. **exact physical-work accounting** from the actual implementation;
3. **Pareto screening** for useful quality/work/timing trade-offs;
4. for deadline admission, an explicit target/build-specific timing certification.

Post-hoc interpolation between valid classes is not assumed safe.

## Runtime contract rule

Keep these separate:

```text
neural manifest
  exact physical work/resource metadata

certified deployed build
  compiler / flags / generated assets / binary identity

target timing binding
  per-class upper execution-time bounds under explicit scheduling assumptions
```

A class with known MACs but no target timing bound remains uncertified and must not be admitted from the timing contract.

## Next primary runtime experiment

Do not keep tuning uncontrolled Linux percentiles.

Use a **controlled scheduling/interference substrate**:

1. compile the freestanding/fixed-point conditional core for a concrete target;
2. identify the exact certified build;
3. define memory/cache/interrupt/scheduler assumptions;
4. obtain defensible upper bounds for validated execution classes;
5. bind those bounds to the matching manifest + build ID;
6. test deadline admission and fail-closed behavior on the target.

If no RTOS target is available, do not manufacture a WCET result from host P95/P99.

## Next model-side falsification

The next useful model-side tests are narrower, not larger:

- make useful computation less analytically exposed than the current toy;
- test sub-block/channel groups beyond simple prefix width only if the backend physically skips them;
- retain matched dense controls and exact output/function comparisons;
- measure controller/backend overhead rather than reporting nominal MAC reduction alone.

Do not increase model scale unless the mechanism requires it.

## Direction rule

Do not return to route-score/NAS optimization unless it fixes a concrete problem in:

```text
budget → physical activation → work → timing bound → deadline
```
