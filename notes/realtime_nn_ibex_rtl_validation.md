# Pinned Ibex RTL timing validation

## H

The same Q15 RTNN build can be executed on a pinned Ibex RTL Simple System such that finite execution classes have reproducible input-independent cycle counts, predictions match the native integer reference, and deadline admission never executes beyond the bound associated with the admitted class.

## Target configuration

Pinned upstream Ibex commit: `7b5df75a041affe56e8c235260f98a09b3319008`.

The GitHub Actions validation builds the official Ibex Simple System with:

- `SecureIbex=1`; in this Ibex revision the internal `DataIndTiming` signal is tied to `SecureIbex`;
- `RV32M=RV32MSingleCycle`;
- `BranchTargetALU=0`, `WritebackStage=0`;
- I-cache and branch predictor disabled;
- PMP/debug trigger disabled;
- `INSTR_CYCLE_DELAY=0`;
- the Simple System dual-port RAM still has a deterministic one-cycle response; zero extra instruction delay does **not** mean zero-latency SRAM;
- no external interrupt, DMA, cache, or competing bus master in the harness.

The RTNN program is compiled as freestanding RV32IM/Zicsr, with no libc, no unresolved symbols, and no hardware DIV/REM in the fixed Q15 neural core.

## Artifact identity lesson

The first CI attempt found that retraining seed 63 on a GitHub runner did not reproduce the earlier local Q15 SHA bit-for-bit. Therefore a training seed is **not** a certification identity.

We separate:

- research reproducibility: seed + training recipe, evaluated statistically;
- timing certification: exact frozen Q15 artifact + exact machine-image hash + pinned RTL configuration.

The validation workflow records the Q15 canonical/header hashes and the resulting ELF/binary hashes with every evidence artifact.

## Falsification of the arithmetic timing model

The earlier custom `RTNN-IBEX-DIT-v1` instruction arithmetic table predicted total cycles of roughly 22k to 2.66M cycles. Actual pinned RTL exceeded that model for every full-work certification class tested. The old table is therefore **FAIL** and must not be used for admission.

This is a useful negative result: instruction-category arithmetic was not a substitute for actual target-pipeline validation.

## RTL-derived binding

The stronger harness measures all seven fixed classes on three distinct held-out inputs whose deployed preferred depths are 1, 3, and 5. The fixed-class path is deliberately forced to the requested maximum class and retains entropy-evaluation overhead.

In workflow run `32214991830`, all `7 × 3 = 21` fixed-class cases matched the native integer predictions and every class had zero cycle range across the three inputs. Strengthening the harness changed every fixed-class count by exactly +1 cycle relative to the previous candidate table, demonstrating that timing evidence is exact-build-specific.

The resulting current certification counts are:

| normalized ceiling | fixed-class RTL cycles |
|---:|---:|
| 0% | 29,620 |
| 16.7% | 615,569 |
| 33.3% | 1,201,521 |
| 50% | 1,787,473 |
| 66.7% | 2,373,425 |
| 83.3% | 2,959,377 |
| 100% | 2,959,381 |

The real admission + adaptive `infer_budget` maximum-work binding used by the harness is:

| normalized ceiling | admission + adaptive RTL envelope |
|---:|---:|
| 0% | 29,843 |
| 16.7% | 657,454 |
| 33.3% | 1,285,058 |
| 50% | 1,912,662 |
| 66.7% | 2,540,266 |
| 83.3% | 3,167,870 |
| 100% | 3,167,870 |

Class 100% has the same deployed maximum-work envelope as 83.3% because this model's validated preferred maximum is exit 5/6; a 100% resource grant is a cap, not an obligation to execute a sixth block.

## Decision discipline

A binding is promoted only when a same-source-shape RTL run satisfies all of the following:

1. all seven fixed classes are tested on all three held-out inputs;
2. fixed-class predictions match the native integer reference;
3. every fixed class has identical cycle count across those three inputs;
4. all 21 admission + adaptive-inference cases have prediction mismatch 0;
5. executed-exit mismatch 0;
6. unsafe admission count 0;
7. no class exceeds the committed RTL-derived binding.

No arbitrary safety multiplier is introduced to hide a failed run. A changed binary or harness requires a new timing binding.

## Nonclaims

Even a PASS here is an **RTL-simulation validated timing binding for this exact Simple System configuration**, not a universal Ibex WCET theorem and not an FPGA/ASIC/silicon production certification. Physical implementation effects, a different memory system, interrupts, DMA, arbitration, caches, compiler changes, or another RTL configuration require a new target/build-specific analysis.
