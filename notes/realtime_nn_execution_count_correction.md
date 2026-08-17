# Physical execution-count correction

## Why this audit was run

The Real-Time NN runtime contract increasingly uses finite execution classes as physical work units. That makes the static work count part of the systems interface, not merely an illustrative model-complexity number.

The previously published tables used **92,160 linear MACs per block**. A direct source/control-flow audit found that value was a conservative proxy, not the exact physical count.

## Source-level cause

For each of the 9 spatial positions, every block executes the self, FF1, and FF2 linear transforms. The neighbor transform is different at the right boundary:

```c
if (p < L - 1)
    linear(neigh_weight, neigh_bias, h[p + 1], ...);
else
    copy(neigh, neigh_bias);
```

Therefore the `32 x 32` neighbor matvec is executed at **8 positions**, not 9.

Exact per-block linear MACs are:

| operation | count |
|---|---:|
| self | `9 * 32 * 32 = 9,216` |
| neighbor | `8 * 32 * 32 = 8,192` |
| FF1 | `9 * 128 * 32 = 36,864` |
| FF2 | `9 * 32 * 128 = 36,864` |
| **total** | **91,136** |

The previous proxy was high by **1,024 MACs per block**.

## Instrumentation cross-check

A debug build instrumented the actual Q5 execution path:

- every `lin()` call adds `out * in` to a MAC counter;
- every activation LUT call increments a LUT counter;
- every residual-scale element increments a residual-operation counter.

One inference was run for each fixed execution class. Because the class call graph does not depend on task input, the operation counts are input-independent for a fixed class.

Observed counts:

| class | blocks | exact linear MACs | LUT calls | residual-scale ops | linear outputs |
|---:|---:|---:|---:|---:|---:|
| 0 | 0 | 64 | 0 | 0 | 2 |
| 1 | 2 | **182,336** | 3,456 | 576 | 3,970 |
| 2 | 4 | **364,608** | 6,912 | 1,152 | 7,938 |
| 3 | 6 | **546,880** | 10,368 | 1,728 | 11,906 |
| 4 | 8 | **729,152** | 13,824 | 2,304 | 15,874 |

The counters exactly match the static derivation.

## What changes

The RTOS-facing static work metadata should use the values above. Source constants, class tables, notes, and compact result JSONs that contained the older MAC proxy are corrected.

## What does not change

This audit does **not** change:

- the trained weights;
- model predictions or quality results;
- the block call graph;
- measured timing samples;
- the qualitative conclusion that larger admitted classes execute more neural work.

The correction is strictly about accurate work accounting.

## Why the correction matters

An illustrative MAC proxy can be harmless in a model-comparison plot. It is not good enough once the same number is used as an RTOS/runtime execution-class contract.

For Real-Time NN work, the preferred rule is now:

> **If a work number is exposed to the runtime contract, derive it from the actual physical control flow and cross-check it with execution instrumentation.**

This correction therefore strengthens, rather than weakens, the main direction: the runtime should reason about finite, physically executed work classes rather than nominal dense-model complexity.
