# Resource-Conditioned Neural Computation

A small, falsification-oriented mechanism study of neural execution-path selection under explicit resource prices and runtime safety masks.

## Status

**Public mechanism note / reproduction package. Not a hard-real-time claim.**

The narrow result supported by the included experiments is:

> A fixed-parameter neural system can learn to select between functionally equivalent but resource-distinct execution paths using a continuous resource-price signal, while an independent runtime mask constrains the selectable execution classes for statistical deadline safety.

The package deliberately includes negative results and does **not** claim WCET guarantees, universal Pareto superiority, energy savings in joules, or generalization to LLMs.

## Constructive example

Two strategies solve the same 12-bit majority task at 100% accuracy:

- **Lookup / copy path:** parameter-footprint-heavy, compute-light.
- **Algorithmic MLP path:** lower parameter footprint, compute-heavy.

In the current reproduction script, the lookup expert has 8,192 parameters and an approximately 2-operation lookup proxy, while the MLP has 4,706 parameters and 4,544 linear MACs. The second resource coordinate is therefore a **normalized parameter-footprint proxy**. It is **not** a measurement of runtime memory traffic, bandwidth, resident-memory reduction, or energy.

A small router observes two resource prices: one for the compute proxy and one for the parameter-footprint proxy. With both paths available, changing only their price ratio changes the selected path while task accuracy remains 100%. The routing probabilities vary smoothly with the continuous price ratio and cross a learned decision boundary.

A separate runtime mask can disable execution classes based on held-out timing calibration. The learned resource-price policy cannot override this mask. If the runtime declares no execution class safe, the public implementation returns **not admitted** rather than executing an uncertified fallback route.

## Related work / novelty boundary

**LUT-based neural computation is not claimed as novel here.** Prior work already includes differentiable logic-gate networks, interconnected lookup-table networks, neural sub-networks synthesized into LUTs, LUT-neuron Vision Transformers, and fully trainable deep LUT networks.

The lookup path here is only a clean constructive example of one execution regime. The narrower question is whether a model can use an explicit resource-price signal to choose among already-valid, resource-distinct execution regimes while an independent runtime mask constrains feasibility.

See [`RELATED_WORK.md`](RELATED_WORK.md) for specific prior work including DWN, NeuraLUT, LL-ViT, differentiable logic-gate networks, and recent trainable LUT-network work.

## Main observations

- Across three seeds, compute-expensive conditions route to lookup/copy while preserving task accuracy.
- Parameter-footprint-proxy-expensive conditions route to algorithmic computation.
- A continuous price-ratio sweep changes the routing distribution while preserving 100% accuracy at every tested point.
- The price-aware and price-blind controls use the **same router architecture and parameter count (114 parameters)**; the control receives zeroed price features and is trained against the same price distribution.
- On the tested two-route objective, the learned price-aware router matches the analytic external scheduler `argmin_j price · cost_j` at all 27 sweep points (9 ratios × 3 seeds). This repository therefore does **not** claim that learning is superior to an analytic scheduler when the route-cost table is known exactly.
- Under a shared runtime safe set, price-aware routing reduces the tested normalized resource objective at identical task accuracy in the footprint-proxy-expensive condition.
- Corrupting the price signal reverses the routing decision and worsens the actual resource objective, providing an intervention-based negative control for fixed-route preference.

See [`notes/readiness_report.md`](notes/readiness_report.md) for exact claims, limitations, and prior falsification results.

## Reproduce

Python 3.10+ is recommended.

```bash
python -m venv .venv
source .venv/bin/activate
pip install -r requirements.txt
python experiments/price_mask_conformal_multiseed.py
python experiments/price_negative_control.py
```

Generated JSON is written to `results/`.

### Timing caveat

Latency measurements depend strongly on OS/runtime state. The scripts set one PyTorch thread and attempt CPU affinity, but ordinary Linux/PyTorch measurements are **not WCET measurements**. The timing mask is based on held-out empirical order statistics under the measured runtime state; do not interpret it as a hard-real-time guarantee.

## What would falsify the useful interpretation?

Useful criticism includes evidence that:

1. interventions on the resource-price input do not actually control routing;
2. an equivalent price-blind policy reproduces the same resource adaptation under matched conditions;
3. the timing-mask result is an artifact of calibration leakage;
4. the result disappears under a clean reimplementation;
5. a materially identical prior method already establishes the same narrow mechanism and runtime/model responsibility split.

Please open an issue using the critique/reproduction templates.

## Repository scope

This repository intentionally stays small. It is not a scaling project and does not currently target LLMs, GPUs, or production RTOS deployment.

## License

Licensed under the Apache License 2.0. See `LICENSE` in the repository root.