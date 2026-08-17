# RTOS bridge status

## Current boundary

The neural side is now represented as a finite set of explicit physical execution classes suitable for target-specific timing analysis:

```text
runtime admits class j
       ↓
same fixed neural weights
       ↓
explicit static C call graph for j
       ↓
known finite neural work
```

What is **not** yet available is a defensible target-specific time bound for those work classes.

## Static execution-class contract

| class | executed blocks | linear MAC proxy | LUT activation calls |
|---:|---:|---:|---:|
| 0 | 0 | 64 | 0 |
| 1 | 2 | 184,384 | 3,456 |
| 2 | 4 | 368,704 | 6,912 |
| 3 | 6 | 553,024 | 10,368 |
| 4 | 8 | 737,344 | 13,824 |

Static implementation memory:

- model weights: **335,368 bytes** float32 const data;
- activation LUTs: **2,056 bytes**;
- caller-owned inference workspace: **8,064 bytes**;
- inference heap allocation: none;
- inference model-file I/O: none.

See [`results/realtime_nn_execution_class_manifest.json`](results/realtime_nn_execution_class_manifest.json).

## Static C implementation status

The current generated/static backend provides:

- compile-time constant weights;
- explicit finite `0/2/4/6/8` block call graphs;
- caller-owned workspace;
- no inference heap/file loading;
- LUT-based tanh/GELU with no inference-time libm activation calls.

Three independently trained seeds were exported and recompiled. All three preserve the Python model's full-domain accuracy at every execution class and preserve strict median timing order with executed work.

See:

- [`notes/realtime_nn_static_c_rtos_bridge.md`](notes/realtime_nn_static_c_rtos_bridge.md)
- [`notes/realtime_nn_static_c_lut_activation.md`](notes/realtime_nn_static_c_lut_activation.md)
- [`results/realtime_nn_static_c_multiseed_results.json`](results/realtime_nn_static_c_multiseed_results.json)

## Remaining timing problem

Ordinary Linux remains unsuitable for the hard timing argument.

The same finite C/C++ execution classes retain well-ordered central timing, but high-percentile measurements develop millisecond scheduler/preemption modes under uncontrolled host interference. Weight `mlock()` and removal of Python/PyTorch/libm activation calls do not remove that tail.

Therefore the missing runtime field is intentionally left blank:

```text
execution class j
    + target / compiler / RTOS assumptions
    + bounded interference model
        ↓
    defensible time bound T_j
```

No `T_j` in this repository should currently be interpreted as WCET.

## Next hard-real-time milestone

Run the same static execution classes on a controlled timing substrate and attach a defensible bound to each class.

Preferred target properties:

1. isolated/reserved execution resource;
2. bounded interrupt/task interference;
3. fixed compiler/runtime configuration;
4. time-predictable or analyzable memory behavior;
5. static/formal WCET or a probabilistic real-time model with explicit assumptions.

Then the RTOS admission rule becomes simple and auditable:

```text
choose max j such that T_j <= remaining_deadline
```

The NN may still choose useful computation **inside** the admitted class, but it may never exceed the class's physical work envelope.

## Nonclaim

This file does not claim that static C, LUT activations, CPU affinity, or empirical Linux percentiles are themselves sufficient for hard real time.
