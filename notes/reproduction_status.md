# Reproduction status

The cleaned repository scripts were rerun from the repository layout after removing `/mnt/data` path dependencies.

## Result

- `experiments/price_mask_conformal_multiseed.py`: completed successfully across three seeds and regenerated `results/price_mask_conformal_multiseed_results.json`.
- `experiments/price_negative_control.py`: completed successfully and regenerated `results/price_negative_control_results.json`.
- Both experts remained at task accuracy 1.0 in the final mechanism setting.
- In the memory-expensive, both-safe setting, the price-aware policy selected the algorithmic path and preserved accuracy 1.0 while using the lower normalized resource objective; the price-blind control selected lookup.
- Swapping the price signal reversed the selected path and worsened the actual resource objective in the expected direction.

Exact latency and miss-rate values vary across reruns because these are ordinary Linux/PyTorch timing measurements, not WCET measurements. The routing/resource mechanism, not absolute microsecond values, is the reproducibility target.
