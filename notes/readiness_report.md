# Resource-Conditioned Neural Computation — Readiness Report

## Current status

The Real-Time NN toy mechanism now passes five model-side gates:

1. direct budget-conditioned physical depth execution;
2. structured budget-conditioned **channel-width + depth** execution in one maximum-size parameter set;
3. learned selection under a hard runtime work cap;
4. learned selection integrated with empirical soft deadline admission;
5. useful admissible activation learned from task loss alone in a supplied search space.

The demonstrated chain is:

```text
admitted work budget
  → budget-compliant internal activation
  → physically executed depth / width
  → exact finite work class
  → measured central latency on a compatible backend
  → task quality
```

The implementation side has also progressed to a freestanding/fixed-point finite-class core and a fail-closed RTOS admission interface that separates neural work metadata from target/build-specific timing certification.

**Hard-real-time readiness is not reached.** No real target-specific WCET/timing upper bound has been established.

## Model-side readiness

### Direct physical depth execution — PASS

One fixed network physically executes different numbers of optional blocks as budget changes. Hard-skip median timing is monotonic in 3/3 seeds; dense masking without physical skipping does not obtain the speedup.

### Structured width + depth execution — PASS in supplied prefix-width toy

One maximum-width `C=32` parameter set is jointly trained for `(depth,width)` classes `(0,8)/(2,8)/(4,16)/(6,24)/(8,32)`.

All three seeds preserve the quality ladder **63.67 / 71.48 / 78.52 / 86.33 / 100%**.

A matched dense-width-mask control computes full width but zeros inactive channels. In plain C++, slim and dense-mask predictions are identical over all 512 states. Three-seed mean p50 ratios `slim/dense` are approximately **0.130 / 0.363 / 0.622 / 0.993** for classes 1–4.

**Backend boundary:** PyTorch batch-1 does not convert the large nominal work reduction into latency reduction for the intermediate slim classes. Therefore conditional neural width is only useful for real-time execution when the backend physically maps it to cheaper kernels/loops.

This does not establish arbitrary neuron sparsity or learned width discovery; the tested widths are structured prefixes supplied in advance.

### Learned hard-budget selection — PASS

Hard top-k structurally enforces the admitted work cap. Learned selection improves quality over fixed prefix in useful intermediate regimes, with controller overhead included.

### Task-loss-only useful-computation selection — PASS in supplied toy search space

Without relevance labels, auxiliary relevance loss, capability warmup, or expert freezing:

- `k=2`: learned **81.27%** vs prefix 71.37%;
- `k=4`: learned **100%** vs prefix 78.74%;
- hard-cap compliance and monotonic median timing pass in 3/3 seeds.

This does not establish unconstrained architecture discovery; an analytic key/query oracle exists.

## RTOS / implementation readiness

### Finite physical work representation — PASS

The main block-depth core has exact physical work counts derived from source control flow and checked by instrumentation. The previous conservative MAC proxy was corrected rather than retained as a runtime contract.

### Freestanding/fixed-point implementation boundary — PASS

The toy core can be compiled freestanding with static/generated parameters, fixed caller-owned workspace, bounded LUT activations, Q5 int16 storage/int32 accumulation, and no unresolved external symbols in the tested host builds.

### Admission interface — PASS as an interface/property test only

The runtime contract separates:

```text
neural manifest
certified deployed build identity
target-specific timing upper bounds
```

Uncertified classes, wrong manifest IDs, and wrong build IDs fail closed. Synthetic timing arrays only test admission logic; they are not timing evidence.

### Real target timing certification — OPEN

A compiler matrix shows functionally identical builds can have different machine code, so timing certification must be attached to the exact deployed/certified build.

The remaining primary systems experiment is a concrete target/RTOS with explicit memory/cache/scheduler/interference assumptions and defensible per-class timing upper bounds.

## Runtime machine-state audit — FAIL for simple Linux P95 recalibration

A coarse `machine state → empirical P95 table` is not stable under uncontrolled Linux interference. Scheduler-preempted samples create mixture distributions and percentile cliffs. The initial positive load-recalibration interpretation failed independent reproduction and was withdrawn.

Empirical Linux P95/P99 is not WCET.

## Readiness labels

- **Direct physical budget execution:** PASS.
- **Structured channel-width + depth physical activation:** PASS in supplied prefix-width toy.
- **Learned budget-compliant activation:** PASS.
- **Task-loss-only useful-computation selection:** PASS in supplied toy search space.
- **Soft deadline-admission mechanism:** PASS only under empirical timing assumptions.
- **Freestanding/fixed-point finite-class core:** PASS as implementation bridge.
- **Target/build-bound admission contract:** PASS as interface/property test.
- **Coarse machine-state→P95 admission on ordinary Linux:** FAIL / NOT STABLE.
- **Controlled RTOS timing certification:** OPEN.
- **Hard real time / WCET:** NOT ESTABLISHED.
- **Arbitrary/self-organized neuron-level circuits:** NOT ESTABLISHED.
- **Real-Time LM / LLM-scale generalization:** NOT TESTED.

## Recommended framing

**Real-Time Neural Computation: Budget-Conditioned Physical Execution under Runtime Admission**

The strongest current mechanism evidence includes both depth and structured-width physical execution. Any use of “predictable” must distinguish finite work structure from a formal timing guarantee.
