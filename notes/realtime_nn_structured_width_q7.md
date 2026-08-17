# Freestanding Q7 core for structured depth/width Real-Time NN classes

## Question

Can the structured-width Real-Time NN result be lowered from the plain-C++ mechanism test into the same kind of freestanding integer execution core used by the RTOS bridge?

The required property is stronger than preserving accuracy alone:

> the integer core should preserve the **same per-state class predictions** while retaining explicit physical `(depth,width)` loop bounds.

## Quantization sweep

The three structured-width float models were exported after 160 joint-class training steps and quantized with one uniform fixed-point format.

Full-width class-4 accuracy:

| format | seed 0 | seed 1 | seed 2 |
|---|---:|---:|---:|
| Q5 | 100% | 100% | **99.8047%** |
| Q6 | 100% | 100% | **99.6094%** |
| Q7 | **100%** | **100%** | **100%** |
| Q8 | 100% | 100% | 100% |

Therefore the existing depth-only Q5 choice is **not** automatically sufficient for the structured-width model family. Q7 is the minimum tested precision that restores the full-class quality in all three seeds.

The public structured-width integer bridge consequently uses Q7 rather than pretending one quantization format is universal.

## Prediction-equivalence audit

For Q7, every execution class and every state was compared against the corresponding float structured-width path:

```text
3 seeds × 5 classes × 512 states
```

Prediction mismatches are **zero in every seed/class**.

The preserved class accuracies are:

```text
63.671875% / 71.484375% / 78.515625% / 86.328125% / 100%
```

## Physical classes remain explicit

The integer core retains the same supplied structured classes:

| class | depth | width | exact linear MACs |
|---:|---:|---:|---:|
| 0 | 0 | 8 | 16 |
| 1 | 2 | 8 | 11,408 |
| 2 | 4 | 16 | 91,168 |
| 3 | 6 | 24 | 307,632 |
| 4 | 8 | 32 | 729,152 |

The active width controls the loop bounds of the integer matrix operations; inactive channels are not computed and then masked.

Invalid execution-class values fail closed to class 0.

## Numeric representation

The core uses:

- `int16_t` weights and workspace;
- `int32_t` linear accumulators;
- Q7 scale = 128;
- 257-entry integer tanh/GELU LUTs over `[-8,8]`;
- division-free `51/256` residual scaling;
- branch-reduced numeric saturation/LUT-bound helpers.

Static payload sizes remain:

- weights: **167,684 B**;
- activation LUTs: **1,028 B**;
- caller-owned workspace: **4,032 B**.

## Static numeric-range audit

A conservative bound was computed from quantized weight absolute sums and finite embedding/LUT output ranges, without depending on the observed runtime maximum.

| seed | worst linear accumulator bound | worst post-shift bound |
|---:|---:|---:|
| 0 | **1,598,720** | **12,490** |
| 1 | 1,479,808 | 11,561 |
| 2 | 1,413,248 | 11,041 |

The worst accumulator is about **0.074% of signed int32 capacity**. The worst post-shift value is about **38.1% of signed int16 capacity**.

These are safe bounds for the tested generated models, not a universal fixed-point theorem.

## Freestanding audit

For all three seed-specific generated headers:

- GCC `-ffreestanding -fno-builtin` core objects have **zero unresolved external symbols**;
- `objdump` reports **zero div/idiv instructions**;
- invalid class values fail closed;
- all five class accuracies are preserved.

## Host central-latency diagnostic

One 1,200-repetition host run per seed gives p50 values:

| seed | c0 | c1 | c2 | c3 | c4 |
|---:|---:|---:|---:|---:|---:|
| 0 | 0.066 us | 7.728 us | 51.672 us | 135.958 us | 372.381 us |
| 1 | 0.060 us | 7.133 us | 47.767 us | 134.835 us | 304.737 us |
| 2 | 0.060 us | 6.993 us | 47.458 us | 134.819 us | 304.923 us |

Median timing is strictly ordered with class in **3/3 seeds**. These are ordinary host measurements, not bounds or WCET evidence.

## Interpretation

The structured-width mechanism now has a direct implementation chain:

```text
one maximum-width trained NN
        ↓
budget class chooses physical depth + width
        ↓
plain C++ confirms work-to-latency effect
        ↓
Q7 freestanding integer core preserves every tested prediction
        ↓
RTOS integration / target timing analysis boundary
```

The Q5/Q6 failure is itself useful: the numeric representation is part of the execution-class capability contract and must be validated rather than assumed portable from another architecture.

## What this supports

- structured physical width classes survive freestanding integer lowering;
- all tested float predictions are preserved at Q7 across three seeds;
- width remains a physical loop bound, not a logical dense mask;
- the integer core retains the RTOS-friendly finite-class/fail-closed structure.

## What this does not support

- Q5 sufficiency for arbitrary Real-Time NN variants;
- hard real time or WCET;
- arbitrary/unstructured neuron sparsity;
- target-independent timing or energy savings.
