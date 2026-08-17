# Multi-circuit contract and transfer experiment

## Purpose

The earlier direct test used two internal circuits. This follow-up asks a stronger question: can one fixed parameterized network select among **three** physically/resource-distinct internal circuits, generalize from a small set of discrete training prices to unseen continuous contracts, and reuse the same frozen router across simulated hardware calibration profiles?

This remains a toy mechanism experiment. It is not a hard-real-time, energy, or hardware-portability proof.

## One network, three circuits

All circuits live inside one `MultiCircuitNet` and share the same classifier head:

1. **retrieval**: embedding -> shared head
2. **shallow compute**: 8 -> 20 -> 8 -> shared head
3. **tied-deep compute**: 8 -> 8 -> one shared residual block executed 10 times -> shared head

The task is an 8-bit finite-domain nonlinear classification problem (XOR of two half-vector majority predicates), so all 256 possible inputs can be exhaustively checked.

Approximate active resource profiles are intentionally different:

- retrieval: high active parameter-footprint proxy, very low compute proxy;
- shallow: intermediate footprint and compute;
- tied-deep: low active parameter-footprint proxy, high repeated compute.

All parameters remain resident in one model. The footprint coordinate is not a claim of reduced resident RAM.

## Training protocol

Capabilities are trained first. The retrieval representation is then fitted against the frozen shared head. Capability parameters are frozen before router training.

The price-aware and price-blind routers have the same architecture and parameter count. The price-aware router sees two log resource-price features plus a three-entry availability mask. The price-blind router receives zeroed price features.

Router training uses only seven discrete compute/footprint price-ratio anchors:

`0.03, 0.1, 0.3, 1, 3, 10, 30`

Dense continuous ratios are held out for evaluation.

## Results

Across five seeds:

- all three circuits achieve **100% accuracy** over all 256 inputs;
- the same fixed input is routed through three distinct executed module traces as only the resource contract changes;
- forward hooks verify exclusive execution of the selected subgraph;
- all three routes are used in every seed;
- on held-out dense continuous price ratios, mean oracle-route agreement is **98.64%** (minimum seed: **98.49%**);
- a nearest-training-anchor discrete external scheduler reaches **98.25%** oracle agreement, so the interpolation advantage over this strong simple baseline is real but small;
- over 4,000 random price/mask contracts per seed, the price-aware router reaches **98.72%** mean oracle agreement versus **45.82%** for the matched price-blind router;
- mean normalized oracle regret is ~**0.00076** for price-aware routing versus ~**0.30036** for price-blind routing.

## Simulated runtime/hardware calibration transfer

A separate evaluation keeps the NN and router weights frozen. The runtime applies one of four multiplicative calibration profiles to an abstract scarcity vector before emitting the effective two-dimensional resource price. Hardware identity is not provided to the model.

Mean oracle agreement across five seeds is:

- compute-friendly: **97.85%**
- balanced: **98.07%**
- compute-scarce: **98.51%**
- footprint-scarce: **97.99%**

This supports only a narrow interface claim: under a **separable multiplicative resource-calibration model**, the same frozen neural router can consume recalibrated normalized contracts without receiving hardware identity or being retrained.

It does not establish portability across arbitrary real hardware, non-separable cost changes, compilers, accelerators, or OS timing behavior.

## Important limitations

- Candidate circuits are constructed; spontaneous circuit discovery is not shown.
- The analytic `argmin(price * cost)` scheduler remains the oracle when the cost matrix is exactly known.
- The learned router only modestly improves over a seven-bin nearest-anchor external scheduler on dense interpolation.
- The hardware-transfer test is simulated and uses separable multiplicative calibration.
- No Joules, memory bandwidth, cache traffic, WCET, or hard-real-time guarantees are measured.

## Reproduce

```bash
python experiments/multicircuit_contract_transfer.py
```

Authoritative output:

`results/multicircuit_contract_transfer_results.json`
