# Results

Authoritative compact summaries for the current public reproduction include:

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
- `searchspace_robustness_results.json` — five-seed search-space/cost-structure ablation plus 21-anchor cost-heterogeneity diagnostic.
- `nonseparable_contract_diagnostic_results.json` — route-local hardware-calibration coverage, matched blind and calibration-swap controls, plus an autoregressive negative diagnostic.

The corresponding scripts in `experiments/` regenerate fuller traces. The committed JSONs may be compact summaries rather than every intermediate tensor/trace.

Earlier exploratory files with obsolete architecture counts or ambiguous `memory cost` terminology remain excluded; relevant conclusions are retained in the notes with the corrected **parameter-footprint proxy** wording.
