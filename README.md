# Resource-Conditioned Neural Computation

A falsification-oriented study toward a **Real-Time Neural Network (Real-Time NN)**: one fixed neural network whose actually executed internal computation changes with an explicit time/compute/resource budget.

## Research target

The primary goal is **not** to optimize a router as an end in itself.

The intended system is:

```text
RTOS / runtime
    ↓
deadline + machine state
    ↓
safe admitted budget B
    ↓
the same neural-network parameters
    ↓
B-conditioned internal activation / effective circuit
    ↓
actual executed work changes
    ↓
actual inference latency changes
    ↓
output before the deadline when the admitted budget is feasible
```

The core hypothesis is:

> Holding the network weights and task input fixed, changing only the supplied budget/resource condition can change which internal computation is physically executed, and that execution change can produce a measurable, calibratable change in inference latency.

See [`REALTIME_NN_DIRECTION.md`](REALTIME_NN_DIRECTION.md) for the authoritative direction lock.

## Status correction — 2026-08-17

**The repository does not yet demonstrate the complete Real-Time NN chain.**

Earlier work in this repository established useful precursor mechanisms around resource-conditioned path selection, internal-subgraph execution, capability preservation, topology search, and runtime availability constraints. Those experiments remain reproducible and useful, but several later iterations over-focused on router-policy optimization and resource-proxy oracle agreement.

For the intended Real-Time NN research goal, those are **secondary diagnostics**, not the final metric.

The required chain is:

```text
budget / resource condition
    → internal activation pattern
    → physically executed compute
    → measured end-to-end latency
    → deadline behavior
```

The next primary experiments must measure that chain directly in one fixed network.

## What the core experiment must show

A Real-Time NN mechanism experiment is considered successful only if it measures, in the same implementation:

1. the **same weights** across budgets;
2. the **same input** in budget counterfactuals;
3. budget-dependent active blocks/channels/neurons/edges;
4. inactive computation is **actually skipped**, not merely zero-masked after dense execution;
5. budget-dependent executed MAC/operation count or another implementation-level compute measure;
6. budget-dependent **measured inference latency distribution**;
7. task quality under each budget;
8. a monotonic or otherwise calibratable budget → work → latency relation;
9. a runtime mapping from deadline/machine state to an admitted budget;
10. deadline-miss measurements under that runtime policy.

The first target is not a hard-real-time guarantee. The first target is a reproducible relationship of the form:

```text
smaller admitted budget
    → smaller executed internal circuit
    → less actual work
    → lower measured latency
```

with one fixed neural network.

See [`EXPERIMENT_PLAN_REALTIME_NN.md`](EXPERIMENT_PLAN_REALTIME_NN.md).

## What has already been established

The existing experiments provide several precursor facts:

- one fixed parameterized network can execute different internal subgraphs when only the resource condition changes;
- forward-hook audits have verified cases where inactive modules are not executed;
- resource-conditioned execution can preserve task output in finite toy domains;
- runtime availability can override neural execution choices by construction;
- ordinary Linux/PyTorch timing is too jittery to treat empirical P99 measurements as WCET;
- simple normalized resource contracts work only under limited cost structures, and non-separable route/stage effects expose failures;
- learned routing/allocation can be highly optimization- and parameterization-sensitive.

These are **supporting results**. They do not replace the missing direct budget → activation → measured-latency experiment.

## Secondary diagnostic experiments

The repository intentionally retains the router/topology work because it documents real failure modes that may matter when implementing a Real-Time NN:

- lookup-vs-compute price-conditioned routing;
- direct internal-circuit execution;
- three-circuit contract interpolation;
- capability-preserving joint training;
- constrained subgraph discovery;
- parity curriculum and sampled routing;
- search-space / non-separable cost falsification;
- router-parameterization sensitivity;
- timing-calibration failures under ordinary Linux contention.

These experiments should be read as **implementation diagnostics**, not as the primary research objective.

Detailed evidence is in `notes/`, `results/`, and [`CLAIMS_AND_LIMITS.md`](CLAIMS_AND_LIMITS.md).

## Runtime / RTOS responsibility split

The target interface is:

```text
hardware / OS state
  ├─ CPU/NPU performance
  ├─ DVFS
  ├─ contention
  ├─ temperature
  └─ timing calibration / WCET information
          ↓
       runtime / RTOS
          ↓
 normalized safe budget / execution contract
          ↓
        same NN
          ↓
 budget-conditioned internal execution
```

The runtime owns hardware-dependent timing information. The neural network should ideally consume a normalized budget/resource contract rather than a CPU model name or raw milliseconds.

For strict hard-real-time claims, ordinary Linux/PyTorch measurement is insufficient. Formal/static WCET, time-predictable hardware, scheduler/runtime isolation, or another defensible timing guarantee would be required.

## Resource proxies

Some precursor experiments use normalized compute and parameter-footprint proxies. The parameter-footprint coordinate is **not** measured runtime memory traffic, bandwidth, cache pressure, reduced resident memory, or energy.

For the Real-Time NN line, **actual executed work and actual latency now take priority over proxy-optimal route agreement**.

## Related work / novelty boundary

Not claimed as novel: LUT neurons/networks, differentiable logic networks, dynamic routing, neural architecture search, once-for-all subnetworks, early exit, or runtime subnetwork switching.

Representative prior work and the explicit novelty boundary are documented in [`RELATED_WORK.md`](RELATED_WORK.md).

## Reproduce existing precursor experiments

Python 3.10+ is recommended.

```bash
python -m venv .venv
source .venv/bin/activate
pip install -r requirements.txt

python experiments/internal_circuit_conditioning.py
python experiments/multicircuit_contract_transfer.py
python experiments/joint_self_specialization.py
python experiments/topology_search_discovery.py --suite
python experiments/joint_parity_correlated_curriculum.py --suite
python experiments/sampled_joint_parity_policy.py
python experiments/searchspace_robustness.py --suite --out results/searchspace_robustness_full.json
python experiments/router_parameterization_sensitivity.py
```

The next authoritative reproduction target will be the direct Real-Time NN budget/activation/latency experiment described in [`EXPERIMENT_PLAN_REALTIME_NN.md`](EXPERIMENT_PLAN_REALTIME_NN.md).

## Repository scope

This remains a small mechanism study. No scaling to LLMs, GPUs, or large models is required to establish the core mechanism.

## License

Apache License 2.0. See `LICENSE`.
