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

## RTOS / analyzable implementation bridge

The repository also contains generated C/C++, freestanding integer cores, fixed work manifests, LUT/numeric-range audits, cross-ISA compile/link audits, and build-bound execution contracts. These establish an analyzable implementation boundary but **not WCET**.

The remaining hard-real-time target is to attach defensible target/compiler/RTOS/interference-specific upper bounds `T_j` to finite execution classes and admit the largest class satisfying the remaining deadline.

## Timing boundary

Ordinary Linux percentile timing has already been falsified as a stable hard-admission contract because scheduler/preemption mixture modes create quantile cliffs. Linux timing remains diagnostic only.

## Container entrypoints

See [`container/README.md`](container/README.md). Main new robustness audits are reproduced with `container/Dockerfile.robustness.cpu`.

## Next falsification priorities

1. Move continuous-budget/nested ordering from the synthetic expert task into the sequence/autoregressive bridge without exploding execution-class count.
2. Lower the continuous-budget learned ordering into the existing generated/freestanding backend.
3. Test joint all-class training robustness on at least one real-data task and one sequence task.
4. Only then attach target-specific timing bounds and RTOS admission logic.
