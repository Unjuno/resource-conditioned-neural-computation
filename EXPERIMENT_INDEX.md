# Real-Time NN experiment index

This index separates the main physical-computation chain from secondary router/topology diagnostics. The research target is not router accuracy; it is a neural network whose runtime-admitted resource budget changes **physical internal execution** while remaining compatible with finite execution classes and later timing certification.

## Main-line mechanism experiments

| Experiment | Current result | Evidence |
|---|---|---|
| Budget → physical depth | PASS | one fixed NN executes `0/2/4/6/8` optional blocks with ordered work/central latency |
| Structured active width | PASS with backend boundary | C++ slim execution becomes cheaper; PyTorch provides a negative control where MAC reduction alone does not |
| Hard-cap learned selection | PASS | task-loss-only learned selection beats fixed prefix at intermediate work while respecting exact call caps |
| Price-conditioned expert width | PASS as soft mechanism | one fixed sparse NN moves across physical expert widths; price is not a hard timing guarantee |
| Hard cap + price sequence depth | PASS | transformer-like local attention+MLP stack traverses finite physical depths under cap/price |
| Attention/MLP suboperation selection | qualified PASS | separately skippable suboperations work, with seed/capability and oracle-tracking limits retained |
| Autoregressive generation bridge | qualified | hard cap + price changes physical per-token depth; equal-token-NLL frontier exposes a negative boundary |
| Continuous budget + nested ordering | PASS | continuous control maps to finite classes; nested learned ordering loses ~0.06 pp vs free routing and strongly beats prefix at `k=4` |
| Joint all-class training | PASS | reduces sampled-budget high-class regression from ~1.88 pp to ~0.017 pp in the original 3-seed audit |
| Additive logit refinement | **FAIL / no advantage** | 10-seed matched audit: shared and additive are both 9/10 monotonic; additive residual regression is slightly worse |
| Minibatch-order robustness | PASS on supplied task | 3 initialization × 3 batch streams: 9/9 strict monotonic, zero observed adjacent regression |
| Sequence nested non-prefix routing | PASS + negative boundary | 5-seed causal generation: input-dependent routing beats prefix by +14.38 pp token at `k=2` and +11.25 pp at `k=4`; forcing exact work is quality-monotone in only 3/5 seeds |
| Budget-as-cap + preferred compute | PASS | 5/5 token/exact monotonic; full cap improves +2.50 pp token and +9.375 pp exact vs forced `k=6` while saving 0.9875 blocks on average |
| Fine-grained sequence caps | PASS under tradeoff bound | `0..6` finite caps remain 5/5 monotonic; full-cap mean work falls another 0.275 blocks for -0.469 pp token / -1.25 pp exact vs coarse caps |
| Concurrent preferred-compute training | **FAIL / credit-assignment boundary** | 5-seed ST, relaxed-soft, and online-decoupled audits all preserve hard caps but miss the post-trained frontier; best online-decoupled result is -3.44 pp token / -8.13 pp exact at nearly identical mean work |

## RTOS / analyzable implementation bridge

The repository also contains generated C/C++, freestanding integer cores, fixed work manifests, LUT/numeric-range audits, cross-ISA compile/link audits, and build-bound execution contracts. These establish an analyzable implementation boundary but **not WCET**.

The remaining hard-real-time target is to attach defensible target/compiler/RTOS/interference-specific upper bounds `T_j` to finite execution classes. The latest sequence experiments sharpen the runtime contract: the admitted class is a **maximum work cap**, and the model may choose a cheaper nested physical path inside that cap.

## Timing boundary

Ordinary Linux percentile timing has already been falsified as a stable hard-admission contract because scheduler/preemption mixture modes create quantile cliffs. Linux timing remains diagnostic only.

## Container entrypoints

See [`container/README.md`](container/README.md). Sequence nested-routing and cap-semantics audits are reproduced with `container/Dockerfile.sequence_nested.cpu`; direct preferred-compute training is audited with `container/Dockerfile.sequence_stop.cpu`.

## Next falsification priorities

1. Test a state-based **value of additional computation** predictor that learns marginal future task benefit from a stable/slowly changing capability model, while using only current execution state at inference.
2. Lower the currently strongest sequence input-dependent ranking + post-trained preferred-compute cap policy into the generated/freestanding backend and make the finite class manifest describe maximum admitted work.
3. Test cap semantics and joint all-class training on a real-data workload with sequence structure or temporal dependence.
4. After the policy/backend boundary stabilizes, attach target-specific timing bounds and RTOS admission logic.
