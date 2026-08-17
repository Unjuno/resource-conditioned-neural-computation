# Static C bounded-cost activation experiment

## Question

The static C Real-Time NN bridge still called `tanhf` and `erff` inside inference. Those external math-library calls are target-dependent and complicate WCET/static timing analysis.

Can they be replaced by an explicitly bounded activation implementation without changing the neural execution behavior?

This experiment uses small generated lookup tables. The point is **timing analyzability**, not novelty of LUT-based neural computation.

## Activation implementation

Two float32 tables are generated offline:

- `tanh(x)`;
- exact reference GELU `0.5*x*(1+erf(x/sqrt(2)))`.

Each table has **257 uniformly spaced points over [-8,8]**.

Inference uses:

1. two bound checks;
2. one table index calculation;
3. two adjacent table reads;
4. linear interpolation.

The two tables occupy **2,056 bytes** of float32 data.

The runtime binary is compiled without `-lm`; `nm -u` shows no unresolved `tanh`, `erf`, `exp`, or `pow` symbols.

## Is the LUT domain actually sufficient?

All 512 task states were propagated through all eight exact-activation blocks and every activation input was recorded.

Observed global ranges:

- first `tanh` input: **[-2.7204, 1.8624]**;
- GELU input: **[-1.6276, 2.3467]**;
- second `tanh` input: **[-0.99995, 0.99580]**.

Therefore the chosen `[-8,8]` table domain comfortably contains every observed activation input in this finite task.

Over a dense numerical grid covering `[-2.8,2.5]`, the maximum linear-interpolation error is approximately:

- tanh: **3.75e-4**;
- GELU: **3.97e-4**.

## Neural-output audit

The LUT implementation is compared with the exact-activation Python model over all 512 states and all five execution depths.

| depth | prediction agreement | max absolute logit difference | accuracy |
|---:|---:|---:|---:|
| 0 | 100% | 0 | 63.671875% |
| 2 | 100% | 0.00676 | 71.484375% |
| 4 | 100% | 0.00318 | 78.515625% |
| 6 | 100% | 0.00567 | 86.328125% |
| 8 | 100% | 0.00602 | 100% |

Thus the bounded-cost activation approximation preserves every classification decision in the complete finite task.

## Idle timing example

One static-C run:

| blocks | median | P95 | P99 |
|---:|---:|---:|---:|
| 0 | 0.059 us | 0.061 us | 0.078 us |
| 2 | 41.53 us | 45.01 us | 74.72 us |
| 4 | 84.45 us | 132.97 us | 238.95 us |
| 6 | 129.08 us | 197.55 us | 407.58 us |
| 8 | 171.44 us | 247.12 us | 470.46 us |

The LUT implementation is faster on this host than the libm version, but speedup is not the main claim. The important property is that each activation follows a small explicit bounded operation sequence.

## Same-core interference example

With a continuous same-CPU competitor:

| blocks | median | P95 | P99 |
|---:|---:|---:|---:|
| 0 | 0.058 us | 0.060 us | 0.087 us |
| 2 | 41.53 us | 99.11 us | **4.17 ms** |
| 4 | 84.73 us | 438.85 us | **4.17 ms** |
| 6 | 128.77 us | **4.12 ms** | 4.20 ms |
| 8 | 172.23 us | **4.16 ms** | 4.31 ms |

Removing `libm` activation calls therefore does **not** remove the scheduler/preemption tail. This is another separation of neural compute from OS timing interference.

## Why this matters for an RTOS target

The inference implementation now has:

- compile-time constant model weights;
- explicit finite 0/2/4/6/8-block execution classes;
- one fixed caller-owned workspace;
- no inference heap allocation;
- no model file I/O;
- no runtime `tanhf`/`erff` dependency;
- fixed-size activation tables and bounded interpolation logic.

This is substantially closer to a target that can undergo static memory and execution-time analysis.

A future embedded version may prefer fixed-point arithmetic or integer LUTs, depending on the target. That should be treated as an implementation/timing decision, not as a novel LUT-neural-network contribution.

## Remaining hard-real-time work

Even after making the neural execution path more bounded, the shared Linux host still produces millisecond scheduler modes.

The next hard-RT step therefore remains target/runtime specific:

- isolate or reserve the execution resource;
- define interrupt/interference assumptions;
- compile the bounded execution classes for a time-predictable target;
- obtain WCET or another defensible bound for each class;
- use those bounds for runtime admission.

## What this supports

1. target-defined bounded-cost activation can replace external math-library calls in the tested network;
2. the complete finite-task predictions are preserved;
3. the static execution classes remain ordered in central timing;
4. scheduler interference remains the dominant unresolved tail issue.

## What this does not support

- hard real time or WCET;
- universal accuracy preservation for arbitrary models/tasks;
- novelty of LUT neural computation;
- general hardware portability;
- energy savings.
