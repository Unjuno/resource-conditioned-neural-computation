# Results

Authoritative compact summaries for the current public reproduction include:

- `realtime_nn_budget_execution_results.json` — direct same-network physical budget execution and soft P95 deadline admission.
- `realtime_nn_learned_budget_gate_results.json` — learned internal activation under a hard runtime expert-call cap with explicit relevance supervision.
- `realtime_nn_learned_deadline_results.json` — learned activation integrated with empirical P95 deadline admission.
- `realtime_nn_common_deadline_frontier_results.json` — dense common-deadline learned-vs-prefix frontier audit.
- `realtime_nn_task_only_gate_results.json` — task-loss-only learned selection with hard-budget/timing/deadline audits.
- `realtime_nn_digits_budget_gate_results.json` — task-loss-only input-dependent hard-budget activation on held-out 8x8 handwritten digits, with validation-selected static controls and content/identity falsification interventions.
- `realtime_nn_digits_deadline_frontier_results.json` — common-deadline learned-vs-validation-selected-static frontier for the digits experiment; records both intermediate-budget gains and tight/full-budget negative boundaries.
- `realtime_nn_structured_width_results.json` — structured channel-width/depth activation audit: one maximum-width NN, exact sliced work counts, matched dense-mask control, PyTorch backend negative, and plain-C++ physical-width speedup across three seeds.
- `realtime_nn_structured_width_q7_results.json` — freestanding Q7 lowering of the structured-width classes: Q5/Q6 precision failure boundary, 3-seed float-prediction equivalence at Q7, static numeric bounds, and explicit physical width loop bounds.
- `realtime_nn_machine_state_timing_audit_results.json` — repeated idle/load P95 calibration stability audit and same-core preemption/quantile-cliff diagnostic; negative runtime result.
- `realtime_nn_generated_cpp_results.json` — generated-weight plain-C++ conditional inference; verifies the physical work/central-latency relation without PyTorch and shows scheduler tails remain under same-core contention.
- `realtime_nn_freestanding_core_results.json` — freestanding finite-class inference-core audit: zero unresolved external symbols, fixed caller-owned workspace, full-domain functional reproduction, and invalid-class fail-closed behavior.
- `realtime_nn_execution_count_audit_results.json` — physical work-count correction: source/instrumentation audit establishes 91,136 linear MACs per block and corrects the RTOS-facing class work table.
- `realtime_nn_execution_class_manifest.json` — target-independent finite-class manifest: exact physical work/resource metadata with target timing deliberately absent.
- `realtime_nn_execution_contract_results.json` — RTOS admission-contract property audit: timing evidence is separately bound to both neural manifest identity and certified deployed-build identity; missing/stale certification fails closed.
- `realtime_nn_compiler_matrix_results.json` — GCC/Clang × optimization-level audit: identical finite-domain outputs but ten distinct machine-code objects, motivating build-bound timing certification.
- `realtime_nn_fixed_q5_results.json` — Q5 integer freestanding-core audit: 3-seed full-domain behavior preservation, int16 weights/workspace with int32 accumulators, 2x storage reduction, compiler cross-check, and central-latency comparison.
- `realtime_nn_q5_bounded_numeric_results.json` — bounded numeric-path audit: bit-identical branch-reduced Q5 helpers plus conservative static int32/int16 linear-range bounds derived from weights and LUT output ranges.
- `realtime_nn_q4_i8_results.json` — Q4 int8 freestanding-core audit: Q3 negative boundary, 3-seed decision preservation at Q4, 4x weight/LUT compression versus float, int32-only bounded MACs, division-free direct LUTs, compiler cross-check, and finite-class timing order.
- `realtime_nn_q4_cross_target_results.json` — embedded-ISA compile audit of the Q4 freestanding core: helper-free Cortex-M0/M4-soft and RV32IM objects, deterministic repeated builds, and the RV32I `__mulsi3` negative capability boundary.
- `realtime_nn_q4_baremetal_link_results.json` — `nostdlib` bare-metal static-link audit: self-contained Cortex-M0/M4-soft and RV32IM firmware-shaped ELF images under a small audit memory model, with RV32I failing closed on the missing multiply helper.
- `realtime_nn_q4_branchless_results.json` — Q4 deployment-path timing-analyzability follow-up: activation-value-dependent rounding/LUT clamp branches are replaced by bitwise branchless arithmetic, preserving exact 3-seed finite-domain outputs while reducing compiled conditional-branch sites on Cortex-M0/M4-soft and RV32IM.
- `realtime_nn_q4_lut_certificate_results.json` — exhaustive finite-domain Q4 LUT-range certificate: all 512 effective inputs certify clamp-unreachable generated weights across three seeds; unsafe mutated weights are rejected, and a certified direct-index core remains bit-exact while removing runtime clamp work.
- `realtime_nn_q4_certified_production_results.json` — production adoption audit: the ordinary Q4 exporter now emits the finite-domain LUT certificate, the production core requires it and uses direct indexing, legacy non-certified headers fail compilation, and prior embedded helper/link boundaries remain intact.
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

- physical hard-skip traces / explicit loop bounds;
- hard budget compliance;
- finite executed-work classes;
- physical work counts derived from actual control flow and checked by instrumentation;
- structured depth/width activation where inactive channels are physically absent from the executed matrix dimensions;
- matched dense-mask controls that preserve output while retaining wasteful full-width computation;
- input-dependent hard-budget selection on held-out data against static subsets selected only on validation;
- content/identity interventions that test whether useful selected computation, rather than path identity alone, carries task information;
- backend sensitivity: reduced neural work must be shown to become reduced physical latency on the intended runtime;
- fixed-point precision as part of execution-class capability validation rather than assuming one Q-format transfers across architectures;
- embedded ISA capability requirements and compiler-generated helper dependencies as part of the deployed-build contract;
- bare-metal/static-link feasibility separately from actual target execution and timing certification;
- explicit separation of target-independent work metadata from target/compiler/RTOS timing certification;
- fail-closed admission when timing evidence is absent, bound to a different manifest, or certified for a different deployed build;
- compiler/optimization code-generation sensitivity even when neural outputs are identical;
- activation-value-dependent control flow in the deployed numeric path, not only source-level work counts;
- build-time range certificates before deleting defensive runtime checks from a deployed numeric path;
- capability validation for every runtime-admissible execution class;
- quality/latency Pareto usefulness of exposed classes;
- task quality under budget;
- controller overhead and task-loss-only selection behavior;
- common-deadline on-time & correct behavior;
- repeated timing-calibration stability, not just one favorable calibration;
- freestanding/fixed-point numeric and memory audits;
- explicit refusal to interpret uncontrolled Linux P95/P99 as WCET.

The corresponding scripts in `experiments/` regenerate fuller traces. Generated binary weights and generated C headers are local reproduction artifacts and are not committed.
