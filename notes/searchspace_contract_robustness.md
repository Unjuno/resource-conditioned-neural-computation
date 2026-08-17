# Search-space robustness and non-separable runtime-contract diagnostic

## Question

Do the capability-readiness / correlated-allocation results survive modest changes to the supplied supernet, and can the same simple global resource-price contract survive stage-local hardware cost changes?

This follow-up stays on the 4-bit-parity finite-domain toy. It is deliberately a **robustness / falsification** experiment, not a scaling experiment.

## 1. Search-space robustness

A capability-gated autoregressive router is evaluated over five seeds. All single-primitive probes remain 100% accurate in every condition, so failures below are allocation failures rather than missing task capability.

| configuration | mean hard accuracy | mean tie-aware min-cost rate | worst seed | mean regret |
|---|---:|---:|---:|---:|
| 3-stage homogeneous costs | 100% | 87.70% | 53.00% | 0.00711 |
| 4-stage homogeneous costs | 100% | **98.10%** | **91.25%** | 0.00106 |
| 4-stage, heterogeneous op availability only | 100% | 90.00% | 50.25% | 0.03173 |
| 4-stage, stage-dependent costs only | 100% | **33.00%** | **0.00%** | 0.00971 |
| 4-stage, heterogeneous availability + costs | 100% | **41.65%** | **22.00%** | 0.02562 |

Increasing depth from three to four stages does **not** itself break the mechanism. The dominant failure appears when the same operation has different resource costs at different stages.

### Dense price anchors do not repair stage-dependent costs

For the `stage-dependent costs only` condition, increasing training from seven price-ratio anchors to 21 log-spaced anchors produces only **21.20% mean tie-aware optimality** (worst seed 0%) across five seeds. Therefore the failure is not explained by coarse price interpolation alone.

The cost-heterogeneous oracle frontier contains multiple stage/op regimes as the price ratio changes. The global two-coordinate price signal is sufficient to define the objective mathematically, but the learned router does not reliably recover the resulting multi-regime policy.

## 2. Route-local runtime calibration diagnostic

The next diagnostic asks whether the runtime can expose more information when hardware changes route costs non-uniformly.

A four-stage profile assigns a separate multiplicative `[compute, parameter-footprint]` calibration to every stage. Each resource column is normalized to geometric mean one, so the profile describes **relative route-local hardware effects**, not a new global price scale.

Capability is deliberately trained once and frozen for this interface diagnostic. An analytic scheduler with the exact route-cost table remains the oracle.

The calibration-aware flat policy receives:

- centered log global resource price;
- centered log stage-local calibration values.

The matched blind policy has the same architecture and input width but receives zeros for the calibration coordinates.

### Held-out hardware profiles

With 256 training profiles and 20 disjoint held-out profiles, three router seeds give:

- calibration-aware: **73.10% mean** tie-aware min-cost rate, worst seed **70.05%**, mean regret **0.00209**;
- matched calibration-blind: **24.99% mean**, mean regret **0.01869**;
- swapping the calibration profile at inference: **25.63% mean**.

Thus the route-local calibration input has a real intervention effect and substantially improves the resource objective, but it does **not** recover the analytic oracle.

For one fixed router initialization, increasing training-profile coverage from 8 to 256 profiles changes held-out optimality as follows:

`28.43% -> 66.38% -> 57.63% -> 70.18% -> 76.45%`

for `8, 32, 64, 128, 256` training profiles. The trend improves overall but is not monotonic, showing residual optimization variance.

### Correlated autoregressive diagnostic remains difficult

A calibration-aware autoregressive router trained from 256 profiles with mini-batch exact route expectations collapses to one route in the tested seed. At 1200 steps it reaches only **5.25%** held-out min-cost optimality despite 100% task accuracy.

Therefore richer contract information alone is not sufficient; router parameterization/optimization remains a separate problem.

## Interpretation

The earlier portability idea needs a sharper boundary:

> A small normalized global scarcity vector works when hardware/resource changes are approximately separable across execution paths. Route- or stage-dependent hardware effects are not reliably absorbed by that simple contract in these experiments.

For non-separable route costs, at least one of the following is needed:

1. a richer runtime contract carrying route-/operation-local calibration or cost information;
2. a more robust policy architecture/optimizer that can use that information;
3. or an external analytic/runtime scheduler when exact route costs are already known.

The present experiments support (1) only partially: route-local calibration clearly matters, but the learned policies remain below oracle performance. They do not establish a general hardware-portable neural router.

## What this does not claim

- arbitrary hardware portability;
- superiority over an external scheduler with known costs;
- a scalable NAS method;
- physical memory, bandwidth, or energy savings;
- hard-real-time/WCET guarantees;
- generalization beyond the supplied tiny finite-domain search spaces.
