# Next stage: DE0-CV physical validation of the RTNN contract

Status: **PLANNED / NOT YET EXECUTED**.

This note deliberately separates the completed software/formal evidence from the next physical-target experiment. No Simple-System cycle number is transferred to the FPGA by assumption.

## H — falsifiable hypothesis

The **same seed-63 Q15/freestanding seven-class RTNN contract**, rebuilt for a DE0-CV-hosted deterministic target, can preserve prediction/work-cap behavior while obtaining a new target-specific finite-class cycle/time binding that supports deadline admission.

The neural parameters and public resource semantics remain the same:

\[
b\in[0,1],\qquad e=\min(b,p(x,s)).
\]

The external budget remains continuous. It is lowered fail-closed to finite physical classes. A full grant remains permission to use up to the maximum useful class; it does not force useless extra work.

## Exact experiment to run

> Run the same seed-63 Q15/freestanding RTNN on **DE0-CV**, initially using an **Ibex softcore plus controlled on-chip RAM and a fixed clock**, derive a **new FPGA-specific seven-class timing table**, and then test deadline admission against that table.

If the DE0-CV integration cannot preserve the chosen Ibex configuration or deterministic on-chip-memory path, assign a new target/configuration identity and analyze that target rather than reusing the Simple-System assumptions.

## Variables

| symbol | meaning | unit | definition / domain |
|---|---|---:|---|
| \(b\) | runtime normalized compute budget | dimensionless | continuous, \([0,1]\) |
| \(q_j\) | finite normalized physical class | dimensionless | \(\{0,1/6,2/6,3/6,4/6,5/6,1\}\) |
| \(p(x,s)\) | model-preferred normalized compute | dimensionless | \([0,1]\) |
| \(N_j\) | certified/accepted cycle upper bound for class \(j\) | cycles | DE0-CV target/build-specific |
| \(f_{clk}\) | fixed FPGA clock | Hz | synthesis/STA-bound build parameter |
| \(T_j\) | class timing bound | s | \(T_j=N_j/f_{clk}\) |
| \(D\) | remaining inference deadline | s | runtime input to admission |
| \(j^*\) | largest admitted class | index | \(\max\{j:T_j\le D\}\) |

Unit check:

\[
T_j=\frac{N_j\;[\mathrm{cycles}]}{f_{clk}\;[\mathrm{cycles/s}]}=[\mathrm{s}].
\]

## Target contract to pin before measurement

The physical experiment must record at least:

- RTNN neural/manifest identity;
- exact generated Q15 assets;
- compiler/linker version and flags;
- Ibex RTL revision and configuration;
- FPGA project/tool version and relevant options;
- fixed clock constraint and achieved static timing result;
- code/data/LUT placement;
- exact on-chip-memory implementation or inferred primitive identity;
- interrupt policy;
- DMA policy;
- competing-master/arbitration policy;
- bitstream/build hash or another immutable deployed-build identity.

Initial certification configuration should intentionally be simple:

- no cache in the certification path;
- no external SDRAM in the RTNN code/data/LUT path;
- no DMA or competing bus master during certification;
- interrupts disabled during the bounded inference interval;
- one fixed clock;
- LUTs and relevant RTNN state in controlled on-chip RAM.

These are experiment assumptions, not claims about every later deployment.

## T0 — board-free preparation that can be completed before hardware

Prepare frozen machine-readable expectations for the board harness:

1. held-out input vectors including cases whose preferred exits are 1, 3, and 5;
2. expected prediction for every fixed class;
3. expected preferred and actually executed class for representative continuous budgets;
4. exact physical optional-block count;
5. fail-closed cases for invalid build/manifest/deadline binding;
6. a stable output-record schema.

Recommended per-run record:

```text
build_id,input_id,budget_q16,deadline_cycles,
admitted_class,preferred_class,executed_class,
prediction,cycles,cap_violation
```

The board result must be comparable to the frozen Q15 software reference without manual interpretation.

## T1 — fixed-class physical validation

For all seven finite classes and multiple frozen held-out inputs:

1. invoke the fixed certification path rather than the adaptive path;
2. record prediction and executed optional-block count;
3. record processor cycles with a target-local counter or equivalent RTL counter;
4. verify the certification code/LUT traffic stays on the controlled memory path;
5. repeat enough times to detect reset/boot/state mistakes, while keeping the target assumptions fixed.

### D1 candidate PASS boundary

- prediction mismatch: 0;
- executed-class / physical-call-count mismatch: 0;
- cap violation: 0;
- uncontrolled external-memory access: 0;
- build identity mismatch accepted by runtime: 0.

If a fixed class is intended to be cycle deterministic, require observed input-to-input cycle range 0 and explain it structurally. If cycles vary, **do not average the variation away**; identify the source and derive a defensible upper bound or change the target configuration.

## T2 — synthesized memory-path validation

The existing Simple-System result proves only that target's `ram_2p` response timing. DE0-CV needs a new memory argument.

Check the synthesized/inferred implementation for:

- actual LUT placement in controlled on-chip memory;
- request/response latency as implemented after synthesis;
- absence of cache/external-SDRAM/arbitration detours;
- absence of address-dependent stall behavior over the legal LUT address range;
- absence of another master that can extend response latency under the certification assumptions.

If RAM inference is ambiguous, instantiate an explicit target RAM primitive or wrapper and analyze that implementation instead of relying on inference folklore.

## T3 — clock and static timing

Choose a fixed target clock and require static timing analysis to close for the exact deployed build.

Static timing analysis establishes that each synchronous cycle meets the chosen clock period; it does **not by itself** establish neural inference WCET. The intended composition is:

```text
bounded processor cycles N_j
        +
fixed clock period from closed STA
        ->
T_j = N_j / f_clk
```

Do not repair failed timing closure by multiplying empirical runtime samples by an arbitrary safety factor. Lower the clock, change the implementation, or derive a valid bound.

## T4 — adaptive deadline admission on the board

After a new DE0-CV timing table exists, perform runtime admission:

\[
j^*=\max\{j:T_j\le D\}.
\]

Then pass the corresponding normalized maximum-work permission to the same RTNN. The NN may stop earlier according to its preferred compute, but physical execution must never exceed the admitted class.

Audit each case for:

- admitted class;
- preferred class;
- executed class / physical call count;
- prediction;
- elapsed cycles;
- relevant \(N_j\) / \(T_j\);
- deadline slack;
- fail-closed identity behavior.

Compare at minimum with always-full execution using **on-time correct** as a system-level utility metric.

## Overall D — proposed PASS criteria

A DE0-CV physical-validation PASS requires all of the following under the declared target assumptions:

1. 0 prediction mismatches versus the frozen Q15 reference for the certification vectors;
2. 0 executed-class / physical-call-count mismatches;
3. 0 budget/deadline cap violations;
4. RTNN code/data/LUT traffic remains on the declared controlled memory path;
5. static timing closes at the declared fixed clock;
6. no observed or proven class execution exceeds the accepted class cycle bound;
7. deadline admission never chooses a class whose accepted bound exceeds the supplied deadline;
8. wrong/stale build or timing-binding identity fails closed;
9. exact FPGA build/bitstream identity is recorded.

If \(N_j\) is only an empirical observed maximum, label the result **empirical bound**, not a hard-real-time certificate. A hard claim requires a defensible upper-bound argument for the target implementation.

## C — failure interpretations

- **Prediction mismatch:** implementation/lowering problem, not a timing result.
- **Executed-count mismatch:** physical control-contract failure.
- **Input-dependent fixed-class cycles:** hidden processor/memory/measurement state remains; isolate it rather than adding margin.
- **LUTs mapped to external/address-sensitive memory:** target memory contract changed; force controlled memory or re-certify it.
- **STA failure:** physical implementation cannot sustain the chosen clock; change clock/implementation.
- **Admission violation with correct table:** runtime binding/control bug.
- **Different Ibex/RTL configuration required:** establish a new target identity and timing table.

## U — explicit nonclaims

Until this experiment is actually run, the repository does **not** claim:

- DE0-CV timing has been measured;
- the Simple-System cycle table applies to DE0-CV;
- the current Simple-System memory proof applies to FPGA RAM;
- an FPGA/ASIC/silicon WCET certificate;
- cache/SDRAM/DMA/multi-master/interrupt tolerance;
- timing portability across compiler, FPGA tool, bitstream, clock, processor, or memory changes.

## Order after DE0-CV

Only after the controlled single-core/on-chip-memory target is understood should the project add harder system effects such as interrupts, competing masters, mixed criticality, or external memory. Larger neural/LM-scale work is downstream of proving that the deadline contract survives a real physical target.
