# Freestanding Real-Time NN inference core

## Question

Can the fixed conditional-execution NN be separated from the Linux/POSIX timing harness into a small inference core that is directly linkable into an RTOS or bare-metal project?

This is an implementation/analyzability question, not a hard-real-time claim.

## Design

The core exposes five finite execution classes:

| class | blocks | linear-MAC proxy | activation LUT calls |
|---:|---:|---:|---:|
| 0 | 0 | 64 | 0 |
| 1 | 2 | 184,384 | 3,456 |
| 2 | 4 | 368,704 | 6,912 |
| 3 | 6 | 553,024 | 10,368 |
| 4 | 8 | 737,344 | 13,824 |

The runtime owns the admitted class. The NN core then executes only the corresponding fixed call graph.

The core uses:

- compile-time generated float32 model weights;
- compile-time generated 257-point tanh/GELU LUTs;
- one caller-owned `RTNNWorkspace` of **8,064 bytes**;
- no inference heap allocation;
- no model file I/O;
- no POSIX calls;
- no libc/libm calls in the core object.

Generated weight/LUT headers are intentionally not committed. They are produced by the repository exporters so weights remain a reproducible build artifact rather than duplicated source blobs.

## Freestanding build audit

The core was compiled with:

```bash
gcc -O2 -std=c11 -ffreestanding -fno-builtin -fstack-usage \
  -I/tmp/rtnn -Iexperiments \
  -c experiments/realtime_nn_core.c -o /tmp/rtnn/realtime_nn_core.o
```

`nm -u /tmp/rtnn/realtime_nn_core.o` produced **no undefined external symbols**.

Project-local GCC stack-usage output:

| function | bytes |
|---|---:|
| `rtnn_init` | 8 |
| `rtnn_infer` | 16 |
| `run_block` | 232 |
| `finish` | 8 |
| `rtnn_execution_classes` | 8 |

The 8,064-byte activation workspace is caller-owned and therefore does not appear as an inference-call stack allocation.

These stack numbers are compiler/build specific and are not WCET evidence.

## Functional reproduction

A host test links the same freestanding object and evaluates all 512 task states.

| class | blocks | accuracy |
|---:|---:|---:|
| 0 | 0 | 63.671875% |
| 1 | 2 | 71.484375% |
| 2 | 4 | 78.515625% |
| 3 | 6 | 86.328125% |
| 4 | 8 | 100% |

These values match the seed-0 Python model and the previous static-C backend.

## Fail-closed runtime input

The earlier prototype treated an invalid class as the maximum execution class. That is unsafe for a work-budget contract.

The public core instead defines:

```text
invalid class -> class 0
```

and the host test verifies that class `255` produces exactly the same output as class `0` over all 512 states. A malformed class value therefore cannot silently increase neural work.

## Reproduce

From the repository root:

```bash
mkdir -p /tmp/rtnn
python experiments/export_realtime_nn_cpp_weights.py --seed 0 --out /tmp/rtnn/weights.bin
python experiments/export_realtime_nn_c_header.py /tmp/rtnn/weights.bin \
  --out /tmp/rtnn/realtime_nn_weights_generated.h
python experiments/export_realtime_nn_activation_lut.py \
  --out /tmp/rtnn/realtime_nn_activation_lut_generated.h

gcc -O2 -std=c11 -ffreestanding -fno-builtin -fstack-usage \
  -I/tmp/rtnn -Iexperiments \
  -c experiments/realtime_nn_core.c -o /tmp/rtnn/realtime_nn_core.o

nm -u /tmp/rtnn/realtime_nn_core.o

gcc -O2 -std=c11 -Iexperiments \
  experiments/realtime_nn_core_host_test.c /tmp/rtnn/realtime_nn_core.o \
  -o /tmp/rtnn/host_test
/tmp/rtnn/host_test
```

Expected `nm -u` output is empty.

## Interpretation

This closes an implementation boundary:

```text
training/export environment
        ↓
generated static weights + activation LUTs
        ↓
freestanding finite-class NN core
        ↓
RTOS / bare-metal integration point
```

What remains target-specific is the real-time timing argument. The core still needs to be compiled for a concrete target/compiler and analyzed or measured under explicit scheduling/interference assumptions before any WCET or hard-real-time claim is defensible.
