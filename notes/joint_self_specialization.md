# Joint resource specialization from scratch

## Question

Can resource-conditioned specialization emerge while the candidate circuits and router are trained together from scratch, without capability pretraining or freezing, and without losing fallback capability?

The candidate circuit topologies are still deliberately constructed. This experiment does **not** test spontaneous topology discovery.

## Setup

One fixed `SuperNet` contains three resource-distinct internal circuits with a shared classifier head:

1. `retrieval` — compute-light, active-parameter-footprint-heavy;
2. `shallow_compute` — intermediate compute and footprint;
3. `tied_deep_compute` — compute-heavy, low active-parameter-footprint proxy due repeated use of tied weights.

Task: 8-bit majority over the complete finite domain of 256 inputs.

All circuit parameters and the router start from scratch in the same training run. No circuit is pretrained and no capability parameters are frozen.

The router sees a runtime availability mask plus a two-coordinate resource-price signal. For the main condition, log prices are centered per sample so multiplying both prices by the same positive constant does not change the router input. Only seven discrete price-ratio anchors are used during training:

`[0.02, 0.08, 0.25, 1, 4, 12.5, 50]`

Evaluation includes held-out dense continuous ratios and random price/mask contracts.

## Training conditions

### Naive joint

Only the currently selected circuit receives the primary task loss, together with the resource objective.

### Capability-preserving joint

Same joint objective, plus an auxiliary task loss on **every** circuit each step. This prevents a rarely selected execution path from silently losing task capability.

### Capability-preserving price-blind

Same architecture and all-circuit capability supervision, but resource-price features are zeroed.

### Raw-log-price ablation

Same as capability-preserving joint, except the router sees raw log prices instead of centered relative log prices.

### Gradient-decoupled diagnostic

Circuit capabilities are trained with all-circuit task losses while the router is optimized separately against the resource objective. This tests whether complete gradient separation is necessary once capability is preserved.

## Five-seed results

| mode | forced route accuracy | held-out dense oracle agreement | random contract oracle agreement | random regret | uses all 3 routes |
|---|---:|---:|---:|---:|---:|
| naive joint | retrieval 71.95% avg; other two 100% | 59.95% | 68.33% | 0.10254 | 0/5 seeds |
| capability-preserving joint | 100% / 100% / 100% | **98.15%** | **97.36%** | **0.00055** | **5/5 seeds** |
| capability-preserving price-blind | 100% / 100% / 100% | 34.91% | 58.10% | 0.11039 | 0/5 seeds |
| raw-log-price ablation | 100% / 100% / 100% | 97.96% | 79.56% | 0.05484 | 5/5 seeds |
| gradient-decoupled diagnostic | 100% / 100% / 100% | 97.51% | 96.17% | 0.00184 | 5/5 seeds |

The naive joint run forgets the retrieval route: its forced full-domain accuracy averages 71.95% and falls as low as 67.19%. That route is then never used in the dense sweep.

With capability-preserving supervision, all three circuits remain 100% correct in all five seeds and all three are actually selected. For the same fixed input, the three price regimes select:

- footprint expensive -> `tied_deep_compute`;
- balanced -> `shallow_compute`;
- compute expensive -> `retrieval`.

This happens even though the joint model saw only seven ratio anchors during training; dense continuous ratios are held out.

## Scale-invariance result

For this two-resource linear objective, multiplying every price coordinate by the same positive scalar cannot change the analytic optimum. The router should therefore not need absolute price scale.

The raw-log-price ablation retains 97.96% agreement on the fixed-scale dense sweep, but drops to 79.56% on random contracts that vary common scale. Centering log prices recovers 97.36% random-contract agreement.

This supports representing the resource contract in **relative scarcity coordinates** when only price ratios affect the decision.

## Gradient-separation result

Complete separation of capability and allocation gradients is not required in this toy. The gradient-decoupled diagnostic reaches 97.51% held-out dense agreement, slightly below the ordinary capability-preserving joint result at 98.15%.

The more important intervention is preserving capability on all potentially admissible circuits. This removes the fallback-forgetting failure while still allowing specialization to emerge under the joint objective.

## What this supports

A stronger narrow statement is now supported:

> Given deliberately constructed resource-distinct candidate circuits, a fixed neural system can jointly learn their task capabilities and a resource-conditioned allocation policy from scratch, without capability pretraining or freezing, provided training explicitly preserves capability on circuits that may later be required as fallbacks.

The learned allocation generalizes from seven discrete price-ratio anchors to held-out continuous ratios in the tested finite-domain toy.

## What this does not support

- spontaneous discovery of the candidate circuit topologies;
- unconstrained self-organization under a single undifferentiated objective;
- input-difficulty-dependent routing;
- hard real-time/WCET guarantees;
- physical memory, bandwidth, or Joule savings;
- large-model or LLM generalization;
- superiority over an exact analytic scheduler when the route-cost table is known;
- arbitrary hardware portability.

The key negative result remains important: naive joint resource optimization can destroy fallback capability even when other routes solve the task perfectly.
