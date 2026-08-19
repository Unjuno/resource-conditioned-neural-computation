# Same-model real-data RTNN lowering and deadline integration

## Research question

Can the exact real-data sequence model that passed held-out adaptive-compute evaluation be lowered into a freestanding C implementation, preserve its exit/stopping decisions, accept the continuous external budget `b in [0,1]`, and compose with deadline admission without silently upgrading empirical Linux timing into WCET?

## H1 — same-model lowering

**H:** The trained real-sequence model can be exported to a freestanding C core whose finite-exit predictions and preferred stopping decisions match PyTorch on held-out test samples.

**T:** Formal seeds 60–64 from `realtime_nn_real_sequence_generalization.py`, 360 held-out test examples, seven exits per seed. Generated static weights plus generated exp/GELU LUTs are consumed by one generic C core. LayerNorm uses a fixed-iteration inverse-square-root approximation. No model files are read at inference.

**D: PASS.**

Across five seeds:

- 12,600 exit prediction comparisons: **0 mismatches**;
- 1,800 preferred-exit comparisons: **0 mismatches**;
- all five freestanding core objects: **0 unresolved external symbols**.

For representative seed 63, the C core reproduces the exact held-out exit accuracy ladder:

`47.50 / 91.11 / 94.17 / 93.89 / 93.33 / 93.33 / 92.50 %`.

Its preferred-exit distribution is also exactly reproduced: `[0,263,81,7,2,7,0]`, with 94.17% policy accuracy and 22.64% mean maximum compute.

**C:** Prediction equality does not imply bit-identical logits for arbitrary unseen inputs. The audit establishes the tested discrete decisions on the held-out test set.

**U:** Float behavior and approximation margins should be re-audited after any compiler, architecture, quantization, LUT, or model change.

## H2 — continuous budget and same-model physical execution

External budget is represented as Q0.16 `uint16_t` while retaining the semantic coordinate `b in [0,1]`. The admitted capability exit is

`floor(6 * budget_q16 / 65535)`.

Adaptive inference does not first compute a future preferred exit and then re-run the model. It executes once, sequentially:

1. compute current exit;
2. stop if entropy is below the validation-selected threshold;
3. otherwise execute the next block only if both budget and deadline permit it.

This produces the same result as truncating the budget-independent preferred stopping decision, without executing work beyond the admitted cap.

**T:** Representative seed 63, all 360 test samples on the 21-point external budget grid.

**D: PASS.**

- 7,560 budget/sample cases;
- prediction mismatches: **0**;
- executed-exit mismatches: **0**;
- cap violations: **0**.

The generic Q0.16 lowering function was also exhaustively audited over all 65,536 budget values.

## H3 — same-model maximum-work manifest and freestanding deadline contract

The seed-63 export emits a target-independent maximum-work manifest. It records capability depth separately from the deployed validation-selected preferred-depth ceiling. For an actually reachable depth `d`, the adaptive path has maximum structural work:

- block calls: `d`;
- exit-head calls: `d + 1`;
- float MAC-like dot-product terms: `1184 + 18592*d`;
- attention exp-LUT calls: `128*d`;
- entropy exp-LUT calls: `10*d`;
- GELU LUT calls: `256*d`;
- inverse-square-root calls: `16*d`;
- caller-owned workspace: **4,608 bytes**.

The manifest intentionally has `target_timing_bounds = null`.

A separate freestanding timing binding contains manifest identity, deployed-build identity, runtime overhead, and one explicit bound per class. Missing bounds use `UINT32_MAX` and cannot be inferred.

**T:** 360 test samples × 21 budgets × seven deadline classes = **52,920** same-model end-to-end cases using a synthetic explicit timing table for contract verification.

**D: PASS as an interface/property test.**

- admitted-class mismatches: **0**;
- executed-exit mismatches: **0**;
- prediction mismatches: **0**;
- partial certification never admits uncertified classes;
- wrong build identity rejects;
- wrong manifest identity rejects;
- combined freestanding core + contract object has **0 unresolved external symbols**.

Clang freestanding compilation also passes for `armv7m-none-eabi`, `riscv32-unknown-elf`, and `aarch64-none-elf`. This is a compile audit, not timing evidence.

## H4 — target timing / WCET

**H:** A defensible hard upper bound can be established for each same-model class in the available environment.

**T:** The exact seed-63 adaptive C binary is pinned to one CPU and measured with `RDTSCP`. Multiple independent runs record finite-class timing. The first observed maximum is then treated as a calibration value and later runs are checked against multiplicative safety factors.

**D: UNCERTAIN / hard-timing hypothesis not established.**

Across 15 runs, the largest held-out/calibration observed-max ratio reaches about **12.50×**. Later maxima exceed calibration by more than `8×` for multiple classes. The environment does not provide a WCET analyzer, a time-predictable bare-metal target, or permission for `SCHED_FIFO`.

Therefore:

`observed max × arbitrary safety factor != certified WCET`.

No hard-real-time timing claim is promoted.

## H5 — empirical RTOS-style demonstrator

An x86 host demonstrator calibrates an empirical P99 envelope, binds it to the same real-data model, admits a deadline class, applies continuous budget and entropy stopping, and measures actual cycles.

This is deliberately classified as **diagnostic only**.

Across three repeats, at deadline classes 3–5 the RTNN mean on-time-correct rate is approximately 93–94%, higher than the always-full fixed-exit path in these runs and higher than fixed exit 1. At class 2, fixed exit 1 can outperform RTNN on-time-correct because the empirical timing table itself is unstable. This is useful evidence that the runtime policy changes the quality/deadline trade-off, but it is not a safe admission argument.

## Current research boundary

The previous same-model integration gap is closed:

`real held-out model -> generated artifacts -> freestanding C -> continuous budget -> preferred stopping -> maximum-work manifest -> deadline admission`.

The remaining blocker for a **hard-real-time RTNN** is external to the neural mechanism: a concrete target/toolchain/RTOS configuration with defensible per-class timing upper bounds. Nonstationary temporal-distribution-shift robustness also remains an ML-side open problem.
