# Fixed-point and conditional static timing audit

## H

A same-model real-data RTNN can be transformed into a finite-class integer core whose expensive numerical kernels have fixed iteration counts and data-independent control flow, allowing a conservative class timing envelope under an explicitly specified deterministic processor/memory model.

This is deliberately weaker than claiming a physical-device WCET.

## T

The audit uses the existing held-out handwritten-digit row-token Transformer and keeps the external interface `b in [0,1]`.

### Integer lowering

- weights/activations: Q15;
- softmax probabilities: Q17;
- exp and GELU: generated integer LUTs;
- LayerNorm inverse square root: fixed 32-iteration integer square root plus fixed 64-iteration restoring division;
- attention/entropy reciprocal: fixed 64-iteration restoring division;
- no libm;
- no hardware DIV instruction;
- branchless mask/select kernels for data-dependent numerical comparisons;
- adaptive stop remains data-dependent by design, but the certification path forces execution to the admitted maximum class and therefore bounds every early-stop path inside that class.

Across seeds 60--64, the Q15 reference has 0/12,600 finite-exit prediction mismatches against the float model and 1/1,800 preferred-exit mismatches. The validation split has zero preferred-exit mismatch for all five seeds. Mean held-out policy accuracy is 93.56% at 20.22% mean compute.

Representative seed 63 is lowered to C. Over 360 held-out samples it has 0/2,520 exit prediction mismatches and 0/360 preferred-exit mismatches. Its preferred distribution remains `[0,263,81,7,2,7,0]`.

### Machine-code audit

The final integer source is compiled without an FPU for Cortex-M4 and as RV32IM. The Cortex-M4 object has:

- zero unresolved external symbols;
- zero floating-point mnemonics;
- zero `udiv`/`sdiv` mnemonics.

The RV32IM analysis ELF likewise has no DIV/REM or floating-point instructions.

An earlier version incorrectly retained one `__aeabi_uldivmod` helper because a 64-bit entropy-series division survived compilation. That version is rejected. The final version replaces it with the same fixed restoring divider used elsewhere.

### Conditional processor model: `RTNN-IBEX-DIT-v1`

The cycle table is valid only under these assumptions:

- RV32IM Ibex-style core;
- `DataIndTiming=1`;
- `RV32MSingleCycle` multiplier;
- no compressed instructions;
- aligned zero-wait instruction and data SRAM;
- no cache;
- no interrupts, DMA, debug requests, or competing bus masters;
- no memory/bus errors;
- the exact analyzed binary and generated model artifacts.

The model counts:

```text
cycles = N_inst
       + N_cond_branch
       + N_jump
       + 2*N_load
       + N_store
       + N_mul_high
       + 4
```

Interpretation:

- one base cycle per retired instruction;
- fixed-time conditional branches receive one additional cycle;
- jumps receive one conservative additional cycle;
- loads receive one LSU wait cycle plus one additional load-use allowance;
- stores receive one LSU wait cycle;
- high-half multiply operations receive one additional cycle;
- four cycles of pipeline/entry slack are added.

This is a conservative *processor-model envelope*, not a claim that these are universal Ibex timings.

The branchless certification kernel was run through a small RV32IM interpreter. Four distinct held-out inputs have identical instruction/branch/load/store/multiply counts for every class. Six representative RV32 interpreter outputs were also checked against the native integer C logits with zero mismatch.

## Cycle envelope

| External ceiling | Worst actual adaptive inference | Admission | Total conditional bound |
|---:|---:|---:|---:|
| 0% | 22,006 | 174 | 22,180 |
| 16.7% | 549,604 | 174 | 549,778 |
| 33.3% | 1,077,194 | 174 | 1,077,368 |
| 50% | 1,604,784 | 174 | 1,604,958 |
| 66.7% | 2,132,374 | 174 | 2,132,548 |
| 83.3% | 2,659,965 | 174 | 2,660,139 |
| 100% | 2,659,966 | 174 | 2,660,140 |

The 100% class has effectively the same neural work as 83.3% because the deployed validation-selected policy ceiling for seed 63 is exit 5/6. This is consistent with maximum-work semantics: admitting 100% does not require consuming it.

The admission success path itself is constant at 174 model cycles across the tested deadline regions. Wrong identity rejects earlier.

## End-to-end property test

Using the conditional cycle table:

- 360 held-out samples;
- 21 continuous-budget points;
- 7 deadline classes;
- 52,920 total cases.

Results:

- admission mismatch: 0;
- executed-exit mismatch: 0;
- prediction mismatch: 0;
- budget/deadline cap violation: 0;
- partial certification fails closed;
- wrong model identity rejects;
- wrong build identity rejects.

## D

### Integer time-predictable lowering: **PASS**

The same real-data model can be expressed as a fixed-iteration integer core while preserving its held-out prediction frontier and, for representative seed 63, its exact stopping decisions.

### Conditional static timing under `RTNN-IBEX-DIT-v1`: **PASS under explicit assumptions**

Finite class bounds can be generated from the exact RV32 binary when the processor/memory timing model is explicitly fixed as above.

### Physical target / production hard-real-time certification: **UNCERTAIN**

No Ibex RTL simulation or physical time-predictable board was available in the active environment. The conditional bounds therefore must not be promoted to physical-device WCET. The next required experiment is to run the exact linked build on a matching RTL/FPGA/ASIC or another target with an accepted WCET/static timing method and compare/replace the conditional model table with target-certified `T_j` values.

## C

If RTL/physical validation exceeds these bounds, then at least one target-model assumption is false or incomplete. Likely candidates are memory response latency, fetch stalls, pipeline hazards not captured by the conservative formula, or integration-level interference. The response is to revise the target binding, not to widen Linux empirical margins.

## U

- only seed 63 has the full integer C + machine-code timing audit;
- the five-seed integer reference has one preferred-exit mismatch in 1,800 held-out decisions;
- the custom RV32 interpreter is a research audit tool, not an ISA-formal model;
- the processor model has not been validated against Ibex RTL in-session;
- nonstationary temporal distribution shift remains an independent ML-side open problem.
