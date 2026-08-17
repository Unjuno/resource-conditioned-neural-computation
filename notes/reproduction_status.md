# Reproduction status

The cleaned repository scripts were rerun from the repository layout after the audit fixes.

## Audit fixes included

- price-aware and price-blind routers now have identical architecture and parameter count (114 each);
- the price-blind control is trained against the same sampled price distribution but receives zeroed price features;
- the second resource coordinate is explicitly named a `parameter_footprint_proxy` rather than runtime memory cost;
- an empty runtime safe set returns `admitted: false` rather than forcing a route;
- the continuous sweep records an analytic `argmin(price · cost)` oracle baseline.

## Result

- `experiments/price_mask_conformal_multiseed.py`: completed successfully across three seeds and regenerated `results/price_mask_conformal_multiseed_results.json`.
- `experiments/price_negative_control.py`: completed successfully and regenerated `results/price_negative_control_results.json`.
- Both experts remained at task accuracy 1.0 in the final mechanism setting.
- In the footprint-proxy-expensive, both-safe setting, the price-aware policy selected the algorithmic path and preserved accuracy 1.0 while using the lower normalized proxy objective; the matched price-blind control selected lookup.
- Across all 27 continuous-sweep points, the learned price-aware route matched the analytic oracle; tested mean oracle regret was 0.
- Swapping the price signal reversed the selected path and worsened the actual proxy objective in the expected direction.
- A direct no-safe-route test returned `admitted: false` and executed no fallback route.

Exact latency and miss-rate values vary across reruns because these are ordinary Linux/PyTorch timing measurements, not WCET measurements. The routing/resource mechanism, not absolute microsecond values, is the reproducibility target.
