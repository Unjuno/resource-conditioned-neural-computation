# Results

Authoritative compact summaries for the current public reproduction include:

- `realtime_nn_budget_execution_results.json` — **primary current Real-Time NN mechanism result**: same-network budget-conditioned physical block execution, measured latency/quality trade-off, dense-mask control, and soft P95 deadline-admission prototype.
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
- `searchspace_robustness_results.json` — search-space/cost-structure diagnostics.
- `nonseparable_contract_diagnostic_results.json` — route-local calibration diagnostic.
- `router_parameterization_sensitivity_results.json` — policy-parameterization sensitivity audit.

The corresponding scripts in `experiments/` regenerate fuller traces. The committed JSONs may be compact summaries rather than every intermediate timing sample.

For the primary Real-Time NN result, machine-specific microsecond values are not the main cross-machine reproduction target. The main targets are:

- physical hard-skip trace changes with budget;
- executed-work count changes with budget;
- hard-skip median latency is ordered with executed work;
- dense logical masking without physical skipping does not obtain the same latency reduction;
- task quality changes with budget;
- high empirical Linux timing percentiles are not interpreted as WCET.

Earlier exploratory files with obsolete architecture counts or ambiguous `memory cost` terminology remain excluded; relevant conclusions are retained in the notes with the corrected **parameter-footprint proxy** wording.
