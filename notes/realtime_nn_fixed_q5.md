# Q5 fixed-point freestanding Real-Time NN core

## Question

Can the finite-class Real-Time NN inference core be moved from float32 to a small **fully integer fixed-point representation** without changing the task behavior of any admitted execution class?

The motivation is RTOS/time-predictable implementation. This is not a claim that fixed point itself is novel, nor a WCET claim.

## Representation

The experiment uses one uniform signed **Q5** format (`scale = 32`):

- weights and biases: `int16_t`;
- activation workspace: `int16_t`;
- linear accumulators: `int32_t`;
- tanh/GELU: 257-entry `int16_t` lookup tables over `[-8, 8]`;
- execution classes: the same fixed `0 / 2 / 4 / 6 / 8` physical block classes.

The LUT grid is especially simple in Q5: `[-8, 8]` spans integer values `[-256, 256]` and 257 points, so adjacent entries are two Q5 integer units apart.

## Three-seed functional result

Three independently trained float models are quantized and recompiled with the same integer core.

For **3/3 seeds**, every execution class has exactly the same classification accuracy as the float model over the complete 512-state domain:

| blocks | accuracy |
|---:|---:|
| 0 | 63.671875% |
| 2 | 71.484375% |
| 4 | 78.515625% |
| 6 | 86.328125% |
| 8 | 100% |

All three compiled integer core objects have zero unresolved external symbols and all three host runs preserve strict central-latency ordering with execution class.

## Numeric headroom on the complete finite domain

The entire 512-state input domain was propagated through all blocks for each of the three seeds.

Maximum values observed across all seeds:

- absolute pre-shift linear accumulator: **19,357**;
- absolute stored/post-shift activation or linear value: **605**.

For this finite toy domain, these are far below `int32_t` and `int16_t` limits respectively. This is an exhaustive-domain audit for this model/task, not a general overflow proof for arbitrary networks or inputs.

## Static memory reduction

| item | float core | Q5 core |
|---|---:|---:|
| model weight payload | 335,368 B | **167,684 B** |
| activation LUT payload | 2,056 B | **1,028 B** |
| caller-owned workspace | 8,064 B | **4,032 B** |
| GCC freestanding object `.text` in this build | 340,260 B | **170,974 B** |

The payload/workspace reductions are exactly 2x because float32 storage is replaced by int16 storage. Object-file sizes are compiler/build specific.

## Host central-latency cross-check

On the same host CPU, seed 0 float-LUT and Q5 binaries were alternated for five timing runs. Median-of-run-medians:

| class | blocks | float-LUT p50 | Q5 p50 | Q5 / float |
|---:|---:|---:|---:|---:|
| 0 | 0 | 0.058 us | 0.135 us | 2.33x |
| 1 | 2 | 57.732 us | **19.878 us** | **0.34x** |
| 2 | 4 | 115.458 us | **61.767 us** | **0.53x** |
| 3 | 6 | 173.179 us | **106.277 us** | **0.61x** |
| 4 | 8 | 248.535 us | **140.182 us** | **0.56x** |

Class 0 is so small that integer-core fixed overhead dominates. For nontrivial classes the tested Q5 implementation is faster centrally on this host, but **no target-independent speedup claim is made**. Linux tail latency is still not WCET. Short timing runs can transiently disturb adjacent-class ordering, so the committed comparison uses the longer repeated measurements above rather than a favorable smoke run.

## Compiler cross-check

Seed 0 was compiled with both GCC and Clang using `-ffreestanding -fno-builtin` for the core object.

Both builds:

- produced zero unresolved external symbols;
- reproduced all five execution-class accuracies.

This is a portability/analyzability check, not a timing guarantee.

## Reproduce

From the repository root:

```bash
mkdir -p /tmp/rtnn-q5
python experiments/export_realtime_nn_fixed_q5.py --seed 0 --out-dir /tmp/rtnn-q5

gcc -O2 -std=c11 -ffreestanding -fno-builtin \
  -I/tmp/rtnn-q5 -Iexperiments \
  -c experiments/realtime_nn_fixed_q5_core.c \
  -o /tmp/rtnn-q5/core.o

nm -u /tmp/rtnn-q5/core.o

gcc -O2 -std=c11 -D_POSIX_C_SOURCE=200809L \
  -I/tmp/rtnn-q5 -Iexperiments \
  experiments/realtime_nn_fixed_q5_host_bench.c /tmp/rtnn-q5/core.o \
  -o /tmp/rtnn-q5/host_bench

/tmp/rtnn-q5/host_bench 2000
```

Expected `nm -u` output is empty.

## Interpretation

This moves the RTOS-facing toy implementation from

```text
float static core
```

to

```text
int16 weights + int16 workspace
        ↓
int32 bounded finite-domain accumulators
        ↓
integer activation LUTs
        ↓
five finite physical execution classes
```

while preserving the complete finite-domain task behavior in all three tested seeds.

The remaining hard-real-time problem is still target/compiler/scheduler specific: each execution class needs a defensible execution-time bound under explicit hardware and interference assumptions.
