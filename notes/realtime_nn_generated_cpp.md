# Generated C++ conditional-execution runtime

## Question

Does the direct Real-Time NN mechanism survive after removing Python/PyTorch from inference, and does the Linux interference problem remain?

This experiment exports the trained weights from the fixed-depth budget-conditioned network and runs the same architecture in a small C++ implementation with explicit loops.

The goal is a systems cross-check:

```text
same trained weights
    ↓
plain generated-weight C++ inference
    ↓
budget controls physical block-loop bound
    ↓
operation count and measured latency
```

## Reproduce

```bash
python experiments/export_realtime_nn_cpp_weights.py --out /tmp/realtime_nn_weights.bin
g++ -O2 -std=c++17 experiments/realtime_nn_generated_cpp.cpp -o /tmp/realtime_nn_cpp
/tmp/realtime_nn_cpp /tmp/realtime_nn_weights.bin 5000 0 0
/tmp/realtime_nn_cpp /tmp/realtime_nn_weights.bin 3000 1 0
```

The generated binary weight file is intentionally not committed.

## Functional verification

Seed-0 full-domain accuracy matches the Python model exactly:

| executed blocks | accuracy |
|---:|---:|
| 0 | 63.671875% |
| 2 | 71.484375% |
| 4 | 78.515625% |
| 6 | 86.328125% |
| 8 | 100% |

The implementation therefore reproduces the same learned computation rather than a separate approximation.

## Idle C++ timing

One `g++ -O2 -std=c++17` run:

| blocks | linear MAC proxy | median | P95 | P99 |
|---:|---:|---:|---:|---:|
| 0 | 64 | 0.063 us | 0.064 us | 0.065 us |
| 2 | 184,384 | 71.4 us | 129.9 us | 288.1 us |
| 4 | 368,704 | 143.1 us | 255.0 us | 594.7 us |
| 6 | 553,024 | 217.5 us | 490.4 us | 4.29 ms |
| 8 | 737,344 | 294.8 us | 4.36 ms | 4.56 ms |

Median execution is strictly increasing with physically executed work.

The high-percentile values already contain host-scheduler outliers even though Python and PyTorch are absent.

## Same-core busy C++ timing

With a continuous competitor process pinned to the same CPU:

| blocks | median | P95 | P99 |
|---:|---:|---:|---:|
| 0 | 0.065 us | 0.067 us | 0.068 us |
| 2 | 71.5 us | 151.9 us | **8.11 ms** |
| 4 | 143.5 us | 462.5 us | **8.19 ms** |
| 6 | 217.8 us | **8.24 ms** | 8.37 ms |
| 8 | 292.8 us | **4.31 ms** | 4.46 ms |

Central timing remains ordered by neural work, while scheduler interference dominates the tail. The P95/P99 pattern is not monotonic because the fraction of requests encountering preemption determines which mixture mode a percentile lands in.

## Interpretation

Two issues are now separated.

### Neural conditional execution

```text
smaller budget → fewer physically executed blocks → fewer MACs → lower median execution time
```

survives removal of the Python/PyTorch inference framework.

### Real-time timing guarantee

The millisecond-scale tail does **not** disappear after removing PyTorch. Same-core scheduler interference remains visible in a plain C++ binary.

Therefore the unresolved hard timing problem is not merely framework overhead or dispatcher jitter. It is the scheduling/interference substrate.

## RTOS relevance

The C++ implementation is closer to an embedded/RTOS boundary because:

- conditional work is explicit control flow;
- per-budget loop structure and MAC counts are finite and visible;
- inference has no dynamic PyTorch dependency.

However, this is **not yet WCET proof**. Compiler transformations, math-library behavior, cache/memory effects, interrupts, and scheduler interference still require target-specific analysis.

The logical next step is to run the same finite execution classes under a time-predictable or isolated real-time substrate rather than continue tuning Linux percentiles.

## What this supports

1. the direct physical execution mechanism is not a PyTorch-only artifact;
2. fixed budgets map to explicit finite C++ work classes;
3. central execution time remains ordered by work;
4. uncontrolled Linux scheduler tails remain even in plain C++.

## What this does not support

- hard real time or WCET;
- general compiler/hardware portability;
- superiority over a conventional external scheduler;
- energy or memory-bandwidth savings;
- LLM-scale generalization.
