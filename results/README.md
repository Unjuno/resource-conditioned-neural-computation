# Results

Authoritative compact summaries for the current public reproduction include:

- `realtime_nn_budget_execution_results.json` — direct same-network physical budget execution and soft P95 deadline admission.
- `realtime_nn_learned_budget_gate_results.json` — learned internal activation under a hard runtime expert-call cap with explicit relevance supervision.
- `realtime_nn_learned_deadline_results.json` — learned activation integrated with empirical P95 deadline admission.
- `realtime_nn_common_deadline_frontier_results.json` — dense common-deadline learned-vs-prefix frontier audit.
- `realtime_nn_task_only_gate_results.json` — task-loss-only learned selection with hard-budget/timing/deadline audits.
- `realtime_nn_machine_state_timing_audit_results.json` — repeated idle/load P95 calibration stability audit and same-core preemption/quantile-cliff diagnostic; negative runtime result.
- `realtime_nn_generated_cpp_results.json` — generated-weight plain-C++ conditional inference; verifies the physical work/central-latency relation without PyTorch and shows scheduler tails remain under same-core contention.
- `realtime_nn_freestanding_core_results.json` — freestanding finite-class inference-core audit: zero unresolved external symbols, fixed caller-owned workspace, full-domain functional reproduction, and invalid-class fail-closed behavior.
- `realtime_nn_fine_grained_classes_results.json` — execution-class granularity audit: post-hoc intermediate depth classes can lose capability, while jointly trained 0..8 depth classes preserve non-decreasing quality and strictly increasing median latency; dominated classes remain off the Pareto frontier.
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

- physical hard-skip traces / explicit C++ loop bounds;
- hard budget compliance;
- finite executed-work classes;
- capability validation for every runtime-admissible execution class;
- quality/latency Pareto usefulness of exposed classes;
- task quality under budget;
- work/central-latency ordering;
- controller overhead;
- task-loss-only selection behavior;
- dense-mask and analytic-oracle controls;
- common-deadline on-time & correct behavior;
- repeated timing-calibration stability, not just one favorable calibration;
- consistency between framework and generated-C++ implementations;
- freestanding-core linkability and fail-closed execution-class handling;
- explicit refusal to interpret uncontrolled Linux P95/P99 as WCET.

The corresponding scripts in `experiments/` regenerate fuller traces. Generated binary weights and generated C headers are local reproduction artifacts and are not committed.
