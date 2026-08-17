# Resource-Conditioned Neural Computation

A small, falsification-oriented mechanism study of neural execution-path selection under explicit resource prices and runtime safety masks.

## Status

**Public mechanism note / reproduction package. Not a hard-real-time claim.**

The narrow result supported by the included experiments is:

> A fixed-parameter neural system can learn to select between functionally equivalent but resource-distinct execution paths using a continuous resource-price signal, while an independent runtime mask constrains the selectable execution classes for statistical deadline safety.

The package deliberately includes negative results and does **not** claim WCET guarantees, universal Pareto superiority, energy savings in joules, or generalization to LLMs.

## Constructive example

Two strategies solve the same 12-bit majority task at 100% accuracy:

- **Lookup / copy path:** memory-heavy, compute-light.
- **Algorithmic MLP path:** memory-light, compute-heavy.

A small router observes a two-dimensional resource-price signal. With both paths available, changing only the compute-to-memory price ratio changes which path is selected. The included sweep shows a transition from algorithmic computation to lookup/copy while accuracy remains 100%.

A separate runtime mask can disable execution classes based on held-out timing calibration. The learned resource-price policy cannot override this mask.

## Main observations

- Across three seeds, compute-expensive conditions route to lookup/copy while preserving task accuracy.
- Memory-expensive conditions route predominantly to algorithmic computation.
- A continuous price-ratio sweep produces a continuous routing transition rather than a single discrete label lookup.
- Under a shared runtime safe set, price-aware routing reduces the tested normalized resource objective at identical task accuracy.
- Corrupting the price signal reverses the routing decision and worsens the actual resource objective, providing a negative control for fixed-route preference.

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

Latency measurements depend strongly on OS/runtime state. The scripts set one PyTorch thread and attempt CPU affinity, but ordinary Linux/PyTorch measurements are **not WCET measurements**. Do not interpret the statistical mask as a hard-real-time guarantee.

## What would falsify the useful interpretation?

Useful criticism includes evidence that:

1. the resource-price signal is not causally used by the router;
2. an equivalent price-blind policy reproduces the same resource adaptation under matched conditions;
3. the timing-mask result is an artifact of calibration leakage;
4. the result disappears under a clean reimplementation;
5. a materially identical prior method already establishes the same mechanism and separation of responsibilities.

Please open an issue using the critique/reproduction templates.

## Repository scope

This repository intentionally stays small. It is not a scaling project and does not currently target LLMs, GPUs, or production RTOS deployment.

## License

Licensed under the Apache License 2.0. See `LICENSE` in the repository root.
