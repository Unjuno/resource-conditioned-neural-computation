# Direct internal-circuit conditioning experiment

## Question

Can one fixed parameterized neural network change its **executed internal subgraph** when only the resource condition changes, while preserving the task output?

This experiment is a direct test of the architectural claim that resource condition can control the effective neural circuit. It is intentionally separate from the earlier external-looking copy-vs-compute presentation.

## Model

One `ResourceConditionedCircuitNet` contains all of the following parameters at once:

- a retrieval node (`Embedding`),
- an algorithmic stem,
- four residual compute blocks,
- one shared classifier head,
- one resource-conditioned router.

The two available internal circuits are:

1. `retrieval -> shared head`
2. `stem -> compute block 0 -> compute block 1 -> compute block 2 -> compute block 3 -> shared head`

`forward_selected()` executes only the selected circuit. A forward-hook audit checks that modules on the inactive subgraph are not called.

The two resource coordinates are proxies:

- compute proxy: approximate executed operation/MAC count;
- active-parameter-footprint proxy: parameters touched by the selected circuit.

The second coordinate is **not** resident-memory reduction. All parameters remain resident in the same model.

## Training protocol

1. Train the algorithmic circuit and shared head on the 12-bit majority task.
2. Freeze that capability and train the retrieval node to use the same shared head.
3. Freeze both capabilities.
4. Post-train only the router from resource price + runtime availability mask.
5. Train a matched 114-parameter price-blind router with identical architecture; its price features are zeroed.

The tested router does **not** observe input difficulty or task content.

## Results

Across seeds 0, 1, and 2:

- both internal circuits achieve 100% accuracy over all 4,096 task states;
- changing only the resource-price condition changes the selected internal circuit in every seed;
- the two resource conditions produce identical correct predictions over all 4,096 states in every seed;
- the declared inactive subgraph is not executed according to forward-hook counts in every seed;
- the price-aware router matches the analytic `argmin(price · cost)` oracle at all 27 tested sweep points (9 price ratios x 3 seeds);
- the same-capacity price-blind control does not adapt its route to the resource-price intervention;
- if the runtime mask exposes no execution circuit, inference is rejected rather than falling back to an unavailable route.

One explicit same-input trace uses state `1234`:

- compute-expensive condition -> `retrieval -> head`;
- footprint-proxy-expensive condition -> `stem -> block0 -> block1 -> block2 -> block3 -> head`;
- prediction remains correct in both cases.

## Interpretation

### Supported by this toy experiment

A fixed parameter set can contain multiple valid internal computation subgraphs, and a learned resource-conditioned router can change which subgraph is **actually executed** when the resource condition changes, without changing the task answer in the tested finite domain.

This is stronger than merely changing an iteration counter: the executed module sequence itself changes.

### Not established

- The internal circuits were deliberately constructed; useful circuit structure did not spontaneously self-organize.
- This does not show input-dependent reasoning depth or difficulty adaptation.
- This does not show hard real-time/WCET guarantees.
- This does not show physical memory, bandwidth, energy, or Joule savings.
- This does not show superiority to an exact external scheduler. The analytic scheduler is an oracle in this toy cost table.
- This does not establish portability to a new CPU/NPU without calibration.

## H/T/D/C/U

**H:** Resource condition can control the effective internal neural circuit inside one fixed parameterized model.

**T:** CPU-only PyTorch toy; 12-bit finite-state task; 3 seeds; exhaustive 4,096-state counterfactual check; matched router control; forward-hook execution audit.

**D:** PASS for resource-conditioned internal subgraph switching, answer preservation, inactive-subgraph non-execution, matched-control separation, and oracle agreement. FAIL/not tested for spontaneous circuit discovery, hard RT, physical resource savings, and hardware portability.

**C:** Because circuit costs are explicit and task quality is equal, a non-neural analytic scheduler can make the same choice. The value of this experiment is the neural resource-to-internal-circuit interface, not scheduler superiority.

**U:** Synthetic task, hand-constructed circuit alternatives, resource proxies, no production RTOS or accelerator measurements.
