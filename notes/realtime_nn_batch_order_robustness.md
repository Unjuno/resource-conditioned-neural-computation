# Joint execution-class training: minibatch-order robustness audit

## Question

The previous joint-training audit left a 0.05 percentage-point high-budget regression in one of three seeds. Is that residual failure stable under data-order changes, or is joint all-class training robust when model initialization and minibatch order are varied independently?

## H / T / D / C / U

**H:** joint all-class training is robust to minibatch order on the supplied nested-execution task.

**T:** Cartesian grid of 3 model initialization seeds (`0,1,2`) × 3 independent minibatch-stream seeds (`100,101,102`) = **9 runs**. Each run uses 800 optimizer updates and averages task cross-entropy across all 8 execution classes on every update. Architecture is the shared hidden-state baseline.

**D:** PASS if at least 80% of runs are strictly non-decreasing in accuracy across classes, mean maximum adjacent regression is at most 0.1 pp, mean `k=4` accuracy is at least 98%, nested violations are zero, and all hard-cap hook audits pass.

**C:** if results vary materially with minibatch order, the apparent monotonic frontier is an optimization artifact and cannot yet be treated as a stable model property.

**U:** only 9 seed combinations and one synthetic task/hyperparameter setting are tested. Batch-order robustness here does not imply architecture/task/domain robustness.

## Result

All **9/9** initialization × minibatch-order runs are strictly non-decreasing.

- strict-monotonic fraction: **100%**;
- mean maximum adjacent accuracy drop: **0.000 pp**;
- worst observed adjacent drop: **0.000 pp**;
- mean `k=4..8` accuracy: **100% at every class**;
- nested violations: **0**;
- hard-cap hook checks: **all PASS**.

**Decision: PASS.**

This strengthens the interpretation that joint all-class training can remove the large high-budget regressions seen with sampled-budget training on this supplied task. It does **not** prove formal utility monotonicity: a different task, optimizer, network, data stream, or larger seed sweep can still falsify it.

## Relation to the incremental-refinement negative result

The two audits should be read together:

1. joint training is robust across the tested minibatch streams;
2. additive logit refinement does not improve the already-strong shared-state baseline.

Therefore the simplest supported design remains **nested learned ordering + joint all-class task-loss training**, without an additional output-refinement mechanism.

## Environment

Recorded run: x86-64 Linux container, AMD EPYC 7763 virtual CPU, Python 3.13.5, PyTorch 2.10.0+cpu, one PyTorch intra-op thread. No timing/WCET/hard-real-time claim.
