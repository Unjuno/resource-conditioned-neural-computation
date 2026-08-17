# Static C execution classes as an RTOS integration bridge

## Question

Can the direct budget-conditioned neural execution mechanism be represented in a form that is closer to static embedded/RTOS analysis than a dynamic Python/PyTorch or file-loading C++ process?

The objective here is not to claim WCET. It is to make the execution classes and memory layout explicit enough that a later target-specific timing analysis has a clear object to analyze.

## Generated structure

The trained seed-0 fixed-depth model is exported in two steps:

```bash
python experiments/export_realtime_nn_cpp_weights.py --out /tmp/realtime_nn_weights.bin
python experiments/export_realtime_nn_c_header.py /tmp/realtime_nn_weights.bin --out /tmp/realtime_nn_weights_generated.h
```

The generated C header contains **83,842 float32 weights = 335,368 bytes** as `static const` data.

The header is generated locally rather than committed.

The C runtime has:

- no weight-file I/O during inference;
- no heap allocation in the inference path;
- one caller-owned fixed `Scratch` workspace of **8,064 bytes**;
- five explicit execution-class functions for `0/2/4/6/8` optional blocks;
- one `switch` that maps the admitted budget class to those finite call graphs.

In source form:

```text
budget class 0 → infer_d0
budget class 1 → infer_d2
budget class 2 → infer_d4
budget class 3 → infer_d6
budget class 4 → infer_d8
```

Each function calls only the blocks belonging to that class. There is no dense post-hoc mask standing in for skipped work.

## Functional equivalence

Full-domain accuracy matches the original trained Python model exactly:

| blocks | accuracy |
|---:|---:|
| 0 | 63.671875% |
| 2 | 71.484375% |
| 4 | 78.515625% |
| 6 | 86.328125% |
| 8 | 100% |

Thus the static C representation preserves the same learned computation and budget/quality levels.

## Explicit memory / stack accounting

`Scratch` contains all intermediate activation buffers and is **8,064 bytes**.

It is caller-owned/static in the benchmark rather than allocated on every inference call. This allows an RTOS integration to reserve one workspace per task or inference context explicitly.

A GCC `-fstack-usage` build reports project-local stack usage of approximately:

- `infer_class`: **16 bytes**;
- `run_block`: **368 bytes**;
- benchmark `main`: **176 bytes**.

This report does **not** include stack used inside external `libm` / libc routines such as `tanhf` and `erff`; a target-specific WCET/memory analysis must include those or replace them with analyzable implementations.

The example executable has no undefined `malloc`/`free` symbols. The benchmark harness still uses `clock_gettime`, `qsort`, and stdio; the neural inference path itself uses the static model/workspace plus `tanhf`/`erff`.

## Idle timing example

One shared-Linux run:

| blocks | MAC proxy | median | P95 | P99 |
|---:|---:|---:|---:|---:|
| 0 | 64 | 0.059 us | 0.061 us | 0.087 us |
| 2 | 184,384 | 71.37 us | 80.77 us | 98.69 us |
| 4 | 368,704 | 143.09 us | 205.46 us | 392.82 us |
| 6 | 553,024 | 217.05 us | 298.08 us | 594.71 us |
| 8 | 737,344 | 292.24 us | 391.68 us | 731.32 us |

Central timing is strictly ordered by finite physical work class.

These are example Linux measurements, not portable bounds.

## Same-core interference example

With a continuous competitor on the same CPU:

| blocks | median | P95 | P99 |
|---:|---:|---:|---:|
| 0 | 0.058 us | 0.060 us | 0.087 us |
| 2 | 71.49 us | 112.61 us | **8.10 ms** |
| 4 | 143.25 us | 421.96 us | **8.18 ms** |
| 6 | 217.37 us | **8.24 ms** | 8.29 ms |
| 8 | 292.68 us | **8.32 ms** | 8.41 ms |

Again, the neural work classes remain visible in the median while scheduler interference dominates high-percentile timing.

## Why this is useful

The static C form sharpens the remaining systems problem.

The neural side can now be expressed as a finite set of explicit work classes with:

- fixed weights;
- fixed workspace;
- fixed block call graphs;
- known linear-MAC counts;
- no runtime model swap;
- no heap/file-I/O dependency in inference.

That is much closer to what an RTOS admission/WCET analysis would need than an unconstrained dynamic framework graph.

The remaining hard-real-time question is therefore not “does budget actually change neural work?” It is:

> Under a specific compiler, target processor, cache/memory model, math implementation, interrupt model, and RTOS scheduling assumptions, what defensible upper execution-time bound corresponds to each finite neural work class?

## Important limitation: math-library calls

The current C implementation still calls `tanhf` and `erff` (for GELU). Those library routines may have data-dependent and target-dependent timing and are not automatically suitable for WCET analysis.

A logical next implementation step is to replace them with a target-defined bounded-cost activation implementation, for example an explicitly bounded polynomial/fixed-point/LUT approximation, and quantify the induced accuracy error.

That step should be motivated by timing analyzability, not by claiming LUT computation itself is novel.

## What this supports

1. one trained NN can be compiled into explicit finite budget execution classes;
2. model data and intermediate memory requirements can be made static and explicit;
3. the original budget/quality behavior is preserved;
4. central timing remains ordered by work in static C;
5. the remaining hard-RT work is target/runtime timing analysis, not proof of conditional execution.

## What this does not support

- WCET or hard-real-time guarantees;
- fully static analysis of `libm` activation calls;
- general compiler/hardware portability;
- energy savings;
- a production RTOS integration.
