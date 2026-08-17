# Results

Authoritative compact summaries for the current public reproduction include:

- `realtime_nn_budget_execution_results.json` — direct same-network physical budget execution and soft P95 deadline admission.
- `realtime_nn_learned_budget_gate_results.json` — learned internal activation under a hard runtime expert-call cap with explicit relevance supervision.
- `realtime_nn_learned_deadline_results.json` — learned activation integrated with empirical P95 deadline admission.
- `realtime_nn_task_only_gate_results.json` — task-loss-only learned selection with no relevance labels/warmup, physical hard-budget audit, timing, dense control, oracle baseline, and deadline diagnostic.
- `price_mask_conformal_multiseed_results.json`
- `price_negative_control_results.json`
- `internal_circuit_conditioning_results.json`
- `multicircuit_contract_transfer_results.json`
- `multicircuit_runtime_state_calibration_results.json`
- `joint_self_specialization_results.json`
- `topology_search_discovery_results.json`
- `topology_tie_aware_metric_audit_results.json`
- `router_stabilization_audit_results.json`
- `joint_parity_correlated_curriculum_results.json`
- `capability_gate_threshold_sweep.json`
- `sampled_joint_parity_policy_results.json`
- `searchspace_robustness_results.json`
- `nonseparable_contract_diagnostic_results.json`
- `router_parameterization_sensitivity_results.json`

For the Real-Time NN line, machine-specific microsecond values are not the primary cross-machine reproduction target. Reproduction should focus on:

- physical hard-skip traces;
- hard budget compliance;
- task quality under budget;
- work/median-latency ordering;
- controller overhead;
- task-loss-only selection behavior;
- dense-mask and analytic-oracle controls;
- on-time & correct behavior under empirical deadlines;
- explicit refusal to interpret Linux high-percentile timing as WCET.

The corresponding scripts in `experiments/` regenerate fuller traces. The committed JSONs may be compact summaries rather than every intermediate timing sample.
