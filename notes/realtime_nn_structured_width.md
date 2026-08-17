# Structured channel-width activation under a Real-Time NN budget

## Question

The direct Real-Time NN experiment already shows that budget can change **depth** and therefore physical work. Can the same fixed parameter set also change a finer internal dimension — the number of physically active hidden channels — while preserving the budget/quality relation?

This experiment uses no learned router. The runtime class directly determines a structured `(depth, active width)` pair.

## One maximum-width parameter set

Maximum hidden width is 32, with the same eight local propagation blocks as the direct Real-Time NN toy.

The five budget classes are jointly trained from scratch:

| class | depth | active hidden width |
|---:|---:|---:|
| 0 | 0 | 8 |
| 1 | 2 | 8 |
| 2 | 4 | 16 |
| 3 | 6 | 24 |
| 4 | 8 | 32 |

All classes use prefixes of the **same maximum-size embedding, block matrices, and classifier weights**. There is no model swap.

For a width `w`, the slim path slices the actual operands before each linear operation:

```text
hidden: first w channels
FF expansion: first 4w channels
weight matrices: corresponding w / 4w rows and columns
```

The inactive channels are therefore not merely multiplied and masked afterward.

## Exact linear work

For one block at width `w`, the physical linear MAC count is:

```text
self     9 * w * w
neighbor 8 * w * w
FF1      9 * 4w * w
FF2      9 * w * 4w
-------------------
         89 * w^2
```

The head contributes `2w` MACs.

| class | depth | width | slim MACs | same-depth dense-width MACs | ratio |
|---:|---:|---:|---:|---:|---:|
| 0 | 0 | 8 | 16 | 64 | 25.0% |
| 1 | 2 | 8 | **11,408** | 182,336 | **6.26%** |
| 2 | 4 | 16 | **91,168** | 364,608 | **25.00%** |
| 3 | 6 | 24 | **307,632** | 546,880 | **56.25%** |
| 4 | 8 | 32 | 729,152 | 729,152 | 100% |

## Quality result

At 160 joint-training steps, all three tested seeds reproduce the same complete-domain quality ladder:

```text
63.671875% -> 71.484375% -> 78.515625% -> 86.328125% -> 100%
```

Thus the narrower internal circuits did not sacrifice additional quality beyond the information/receptive-field limit already associated with the depth classes on this toy.

This is a supplied structured prefix-width search space, not arbitrary neuron-subset discovery.

## Dense-mask control

A matched control computes the **maximum 32 hidden / 128 FF channels** at the same depth, but sets channels beyond the admitted width back to zero after each stage.

The control is intentionally wasteful. It asks whether a logical channel mask is enough, or whether the backend must actually shrink the computation.

Across the complete 512-state domain, the slim and dense-mask C++ paths have **zero output difference for all five classes in all three seeds**.

Therefore their timing difference is not caused by a different task function.

## PyTorch negative result

On PyTorch batch-size-1 CPU execution, physical tensor slicing dramatically reduces nominal MACs but **does not translate into a proportional latency reduction**.

Seed-0 examples:

| class | work ratio slim/dense | slim p50 | dense-mask p50 |
|---:|---:|---:|---:|
| 1 | 6.26% | 112.5 us | **108.9 us** |
| 2 | 25.00% | 215.5 us | **203.5 us** |
| 3 | 56.25% | 310.0 us | **305.6 us** |

The slim path is actually slightly slower here.

This is an important systems falsification:

> **fewer neural MACs do not automatically mean lower wall-clock latency in a general framework/backend.**

Small-GEMM efficiency, slicing/dispatch overhead, memory layout, and kernel selection matter.

## Plain C++ physical-loop result

The same trained weights were exported to a plain C++ implementation. The slim path reduces the actual loop/matrix dimensions, while the dense control computes full dimensions and zeros inactive channels.

Three-seed central timing:

| class | mean slim p50 | mean dense-mask p50 | mean ratio slim/dense |
|---:|---:|---:|---:|
| 0 | 0.154 us | 0.351 us | 0.435 |
| 1 | **10.10 us** | 77.73 us | **0.130** |
| 2 | **60.48 us** | 167.80 us | **0.363** |
| 3 | **162.72 us** | 260.64 us | **0.622** |
| 4 | 375.28 us | 378.90 us | 0.993 |

The result follows the expected qualitative pattern:

- narrow classes obtain substantial speedup when the backend truly executes fewer channels;
- full-width class 4 has no meaningful difference because both paths execute the same work.

The speedup is not expected to equal the MAC ratio exactly because loop overhead, activation functions, cache behavior, compiler optimization, and memory traffic remain.

## Interpretation

This strengthens the original Real-Time NN mechanism:

```text
runtime budget
    ↓
same maximum-size NN weights
    ↓
depth + active channel width change
    ↓
physical matrix dimensions change
    ↓
actual executed work changes
    ↓
backend-dependent latency changes
```

The most important new systems lesson is that there are **two contracts**, not one:

1. the NN must expose a smaller physical circuit/work class;
2. the execution backend must map that smaller circuit to genuinely cheaper kernels/loops.

A dense logical mask satisfies neither a real-time work contract nor a latency guarantee.

## What this supports

- same weights can support multiple structured width/depth physical circuits;
- all tested circuits preserve the expected quality ladder in 3/3 seeds;
- physically reducing channel-loop dimensions gives substantial central-latency reduction in the tested C++ backend;
- logical dense masking can produce the same output without obtaining the work reduction;
- general framework timing can hide the benefit even when physical operation count is much smaller.

## What this does not support

- hard real-time or WCET;
- arbitrary unstructured neuron sparsity;
- universal speedup for all compilers/backends/hardware;
- energy savings;
- LLM-scale generalization.

## Reproduce

Train/export one seed:

```bash
python experiments/realtime_nn_structured_width.py \
  --seed 0 --steps 160 --export /tmp/rtnn_structured_width.bin

g++ -O2 -std=c++17 experiments/realtime_nn_structured_width_cpp.cpp \
  -o /tmp/rtnn_structured_width_cpp

/tmp/rtnn_structured_width_cpp /tmp/rtnn_structured_width.bin 2500
```

The C++ output should report equal slim/dense-mask predictions and the timing of both physical execution strategies.
