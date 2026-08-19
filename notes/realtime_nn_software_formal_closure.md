# RTNN software/formal closure before physical target

## H

Before moving to the physical FPGA target, the current seed-63 Q15 RTNN can close the major **software-side** gaps in the chain:

```text
continuous budget
  -> finite physical cap
  -> deployed C control
  -> compiled RV32 control flow
  -> selected target memory response
  -> exact-build RTL timing
  -> durable certification identity
```

without relabeling target-specific evidence as a universal WCET theorem.

## T

Minimum closure conditions:

1. actual deployed finite control is proved over its represented finite domains;
2. exact compiled fixed-class binary has no neural-input-dependent branch/indirect-control path;
3. remaining input-indexed memory loads are explicitly analyzed on the selected memory integration;
4. the exact machine artifact used by the timing evidence is retained durably;
5. CI can recheck artifact identity and derived board-free test vectors without the original Actions artifact;
6. the next physical target has a preregistered new timing experiment rather than inheriting the current timing table.

## D

**PASS_WITH_SCOPE for software/formal closure before the physical target.**

Evidence currently satisfies the six conditions:

- CBMC finite runtime contract: PASS_WITH_SCOPE;
- CBMC mechanically extracted deployed control: PASS_WITH_SCOPE;
- custom exact-RV32 fixed-class input/control-flow audit: PASS_WITH_SCOPE;
- independent BINSEC fixed-class control-flow cross-check: 7/7 classes, 933,653/933,653 control checks, pending 0, leak sites 0;
- pinned Simple-System LUT-memory timing: PASS_WITH_SCOPE, 12,290/12,290 legal LUT words uniquely decode to RAM and response-valid control has zero address fan-in;
- pinned Ibex exact-build fixed-class cycle measurements: 21 cases, prediction mismatch 0, cycle range 0 per class;
- exact certification package frozen in Git under `artifacts/certification/ibex_simple_system/`;
- frozen package identity is rechecked by CI and the DE0-CV board-free vectors are derived from it;
- next physical experiment is explicitly defined in `notes/realtime_nn_de0_cv_next_stage.md`.

The correct project state is therefore **not** "software proves hard real time." The correct state is:

> the finite source-control, compiled fixed-class control-flow, selected Simple-System memory-timing, exact artifact identity, and measured pinned-RTL timing layers are now mutually connected strongly enough that the next major unknown is the physical target/whole-target timing boundary.

## C

If a future processor-level formal/WCET method contradicts the measured pinned-RTL table or reveals another timing-dependent path, the result must reopen the relevant layer rather than being hidden behind a margin.

Likewise, a DE0-CV implementation is a **new target**. Its RAM, bus, clock, synthesis result, bitstream, and processor configuration must be rebound. The current Simple-System memory/cycle evidence is a reference methodology, not a portable timing certificate.

## U

Still unresolved:

- formal proof of the complete processor pipeline/whole physical implementation;
- compiler-preservation proof for every source-level property;
- physical DE0-CV implementation and timing;
- interrupt/DMA/multiple-master/cache/SDRAM interference;
- production certification methodology;
- chronological/nonstationary model generalization.

## ERROR CHECK

- The frozen package is the exact package containing ELF SHA `234a7f46cf227a11f5d97f3c778cbb0c4ed4f7067f8994bcca86c4b08ff4e742` and BIN SHA `266ecb70c723b2164f6fe9039f27d4cb49c4d7271d4aca0cf69f2692cdfdf7a1`.
- The DE0-CV preflight reference intentionally contains **no Simple-System cycle table**.
- BINSEC generic full relational-memory analysis is **not** recorded as PASS; the LUT-heavy class hit the supplied runner resource limit.
- CBMC is not described as a whole-processor timing proof.
- The pinned Ibex cycle table is not described as DE0-CV timing or universal WCET.
