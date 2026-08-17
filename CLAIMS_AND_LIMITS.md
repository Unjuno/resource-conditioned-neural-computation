# Claims and limits

## Supported by the included experiments

1. Resource price can act as a continuous neural execution-control signal.
2. A fixed parameter set can select different effective computation strategies as resource prices change.
3. Functionally equivalent lookup/copy and algorithmic/compute strategies can be switched while preserving task accuracy in the tested synthetic task.
4. An independent runtime availability mask can override resource-price routing, separating statistical timing safety from within-safe-set resource optimization.
5. Deliberately corrupting the resource-price signal changes the selected path in the expected wrong direction and increases the actual resource objective.

## Explicitly not claimed

1. Hard real-time guarantees or WCET bounds.
2. Joule-level energy savings.
3. Universal superiority over adaptive routing, mixture-of-experts, early exit, or external schedulers.
4. Generalization to LLMs or large neural networks.
5. Automatic self-organization of useful circuits under arbitrary architectures or objectives.
6. Hardware-independent timing guarantees.

## Important negative results retained

- Weak price penalties may be ignored.
- Strong fixed penalties may collapse to a cheap policy.
- Joint expert specialization can cause fallback-capability forgetting.
- Simple linear compute+memory timing models did not capture end-to-end tail latency on Linux/PyTorch.
- Runtime-load distribution shift breaks calibration unless the timing model is recalibrated or conditioned on state.
- Additional resource-vector dimensions can be redundant or harmful.
- Resource-conditioned routing did not automatically dominate a strong input-only adaptive-routing baseline on quality-compute Pareto efficiency.
