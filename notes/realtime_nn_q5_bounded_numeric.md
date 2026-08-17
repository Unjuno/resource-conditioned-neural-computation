# Bounded numeric-path audit for the Q5 Real-Time NN core

## Question

Can the integer Real-Time NN core reduce **data-dependent numeric control flow** while retaining exactly the same finite execution classes and task behavior, and can its accumulator width be justified from static weight/LUT bounds rather than only observed test values?

This is an analyzability experiment. It is not WCET evidence.

## 1. Source-level numeric-path simplification

The previous Q5 core still used conditionals for:

- sign-aware rounding;
- int16 saturation;
- LUT-domain clamping.

The new helpers express those operations with comparisons, integer masks/arithmetic, multiply, and shifts. Execution-class selection and fixed loop control remain; the target is specifically to remove **activation-value-dependent source branches** from the numeric helpers.

The residual coefficient is already division-free (`51/256`).

## Functional audit

For three independently trained seeds, all 512 input states and all five execution classes were compared against the previous division-free Q5 core.

**Integer logits are bit-identical in every tested case.**

The execution-class accuracies therefore remain:

| blocks | accuracy |
|---:|---:|
| 0 | 63.671875% |
| 2 | 71.484375% |
| 4 | 78.515625% |
| 6 | 86.328125% |
| 8 | 100% |

Invalid class values continue to fail closed to class 0.

## GCC/Clang code-generation audit

Seed 0, `-O2 -ffreestanding -fno-builtin`:

| diagnostic | previous Q5 division-free | bounded numeric core |
|---|---:|---:|
| GCC conditional jumps in whole core object | 63 | **23** |
| GCC `div/idiv` instructions | 0 | **0** |
| GCC undefined external symbols | 0 | **0** |
| GCC object `.text` | 170,988 B | **170,789 B** |
| Clang conditional jumps | — | **23** |
| Clang `div/idiv` | — | **0** |
| Clang undefined external symbols | — | **0** |

The whole-object jump count is **compiler/ISA specific** and includes fixed loop/class control, so it is not a target-independent operation count. On the tested GCC build, LUT clamping is lowered to conditional-move style code rather than value-dependent jumps.

## 2. Static linear-overflow bound

The previous exhaustive-domain audit observed small accumulators, but an observed maximum is not itself a static guarantee.

For each quantized linear row we instead compute the conservative bound

```text
|acc| <= |bias| * 32 + sum_i |weight_i| * input_abs_bound
```

where `input_abs_bound` is determined without enumerating task inputs:

- first-block state input: maximum absolute quantized embedding value;
- later hidden-state inputs: maximum absolute tanh-LUT output;
- FF1 input: tanh-LUT bound;
- FF2 input: GELU-LUT bound.

This includes every product in the accumulator regardless of cancellation.

### Three-seed result

| seed | worst linear accumulator bound | worst post-shift linear bound |
|---:|---:|---:|
| 0 | 99,904 | 3,122 |
| 1 | **107,552** | **3,361** |
| 2 | 100,896 | 3,153 |

The worst tested static accumulator bound is only about **0.0050% of signed int32 capacity**. The worst post-shift bound is about **10.3% of signed int16 capacity**.

This is materially stronger than the earlier observed maximum accumulator (19,357): for these generated weights and LUT ranges, the linear arithmetic cannot approach integer overflow even under the conservative independent-magnitude bound.

The repository script `experiments/audit_realtime_nn_q5_static_bounds.py` recomputes these bounds from generated Q5 headers.

This is still **model-family specific**. Generating arbitrary new weights requires rerunning the bound audit; the result is not a theorem that any Q5 neural network fits these types.

## Central-latency diagnostic

Seed 0, five alternating host runs, median of p50 values:

| class | previous division-free | bounded numeric | ratio |
|---:|---:|---:|---:|
| 0 | 0.145 us | 0.199 us | 1.37x |
| 1 | 19.221 us | 28.094 us | 1.46x |
| 2 | 65.075 us | **56.683 us** | 0.87x |
| 3 | 112.864 us | **85.191 us** | 0.75x |
| 4 | 146.307 us | **113.448 us** | 0.78x |

The mixed result is useful: removing source-level value branches is not simply a speed optimization. Tiny classes become slower while deeper classes are faster in this particular x86 build. No cross-target latency claim is made.

Independent 1000-repetition runs for all three seeds preserve strict p50 ordering with execution class.

## Reproduce

Generate Q5 headers for one or more seeds, build the core, and run the static bound audit:

```bash
mkdir -p /tmp/rtnn-q5-s0
python experiments/export_realtime_nn_fixed_q5.py --seed 0 --out-dir /tmp/rtnn-q5-s0
python experiments/audit_realtime_nn_q5_static_bounds.py \
  /tmp/rtnn-q5-s0/realtime_nn_fixed_q5_generated.h

gcc -O2 -std=c11 -ffreestanding -fno-builtin \
  -I/tmp/rtnn-q5-s0 -Iexperiments \
  -c experiments/realtime_nn_fixed_q5_core.c -o /tmp/rtnn-q5-s0/core.o

nm -u /tmp/rtnn-q5-s0/core.o
objdump -d /tmp/rtnn-q5-s0/core.o | grep -E '\\b(idiv|div)[a-z]*\\b' || true
```

## Interpretation

The integer implementation now has a clearer split:

```text
runtime execution-class control
        ↓
fixed loops / finite physical work class
        ↓
numeric inner path without source-level value branches
        ↓
static integer-range bound from weights + LUT ranges
```

This improves the suitability of the core for later target-specific WCET/static analysis. The unresolved step remains the same: compile for a concrete processor/RTOS, define interference assumptions, and attach a defensible execution-time bound to each finite class.
