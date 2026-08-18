# Sequence preferred-compute training audit

## Question

Can the preferred-compute decision be trained concurrently with the causal sequence model, instead of first learning all execution classes and then fitting the preferred-compute controller from the frozen per-input class-loss frontier?

The runtime semantics remain unchanged:

```text
admitted maximum work class
    -> input-specific preferred work
    -> min(preferred, cap)
    -> input-specific nested physical block path
```

## H/T/D/C/U

### H

Concurrent task-loss optimization of capability and stopping can match the existing post-trained preferred-compute baseline.

### T

Matched causal sequence task and finite classes `0/2/4/6`, 5 seeds, 400 capability steps. Three formal methods:

1. **Straight-through:** hard preferred-class forward, soft straight-through policy gradient; capability and stop jointly optimized.
2. **Relaxed soft:** soft preferred-class probabilities during training, hard argmax only at inference.
3. **Online decoupled:** every step trains capability/ranking with uniform all-class task loss, then trains the stop policy once from detached current counterfactual class losses. There is no final post-training phase.

PASS requires full-cap token accuracy within 1 pp and exact-sequence rate within 2 pp of the existing post-trained baseline, mean work no more than +0.25 block, and zero nested/cap violations.

Training-time sparse execution is **not** claimed. All exact-class losses are evaluated while training.

### D

Existing post-trained baseline at full cap:

- token accuracy: **98.59375%**
- exact sequence: **95.0%**
- mean executed blocks: **5.0125**

Formal results:

| method | full-cap token | full-cap exact | mean blocks | token gap | exact gap | decision |
|---|---:|---:|---:|---:|---:|---|
| Straight-through | 78.28125% | 52.5% | 1.75 | -20.3125 pp | -42.5 pp | **FAIL** |
| Relaxed soft | 92.03125% | 80.0% | 4.00 | -6.5625 pp | -15.0 pp | **FAIL** |
| Online decoupled | 95.15625% | 86.875% | 5.05 | -3.4375 pp | -8.125 pp | **FAIL** |

All three formal methods have nested violations **0**, cap/count-monotonicity violations **0**, and physical hard-cap audit **PASS**.

Straight-through frequently collapses to `k=0` or `k=2`. Relaxed soft selects `k=4` for every input in all five seeds. Online decoupling is substantially better and seed 0 recovers input-specific `k=4/k=6`, but the five-seed frontier still misses the preregistered quality bounds.

Exploratory seed-0 controls did not rescue the result: Gumbel-ST, policy gradient, capability warmup, and an auxiliary uniform all-class coverage loss all remained below the post-trained baseline.

**Decision: FAIL.**

### C

The failure is not a hard-cap problem. Structural safety remains intact. The current evidence instead points to a **credit-assignment / co-adaptation boundary**: when stopping and capability evolve together, stopping choices become homogeneous or prematurely cheap, while the post-trained method sees a stable counterfactual frontier.

A better next mechanism is a state-based **value of additional computation** predictor. It should predict the marginal task benefit of proceeding from the current execution state, using counterfactual future-class loss during training but only current state at inference.

### U

- one synthetic causal-generation task;
- one stop-policy network family;
- five seeds for the three formal methods;
- Gumbel/REINFORCE/warmup/coverage variants are seed-0 exploratory controls, not formal multi-seed comparisons;
- no training-time sparse-compute claim;
- no real-data, WCET, or hard-real-time claim.
