# C2J2 to C3 v2 cycle-offset audit

> **2026-11-22 addendum:** A later static disassembly audit became possible with Ubuntu LLVM 18.1.3. It confirms that C3 v2 stores the sampled 64-bit start counter inside the measured interval, making that extra work a plausible contributor. It does **not** prove that this change causes exactly +5 cycles; causal attribution remains unresolved. See `CYCLE_OFFSET_DISASSEMBLY_ADDENDUM_20261122.md`. The tooling-unavailable paragraph below records the earlier audit state and is retained as historical context.

## Pairwise observation

Existing independent primary-data reanalysis matched 7,200 old/new rows by schedule, sequence, input ID, and mode. Old build `43324a32` (SOF SHA-256 `5aa5be2e7387e22e43db6a322e1572cceacd3266231af4dbc2de01ee649c37e6`) and new build `43334531` (SOF SHA-256 `85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d`) have matching frozen model identity. All 7,200 cycle differences are exactly +5 cycles in the new build; prediction, admitted exit and executed exit are unchanged. This is an observed cross-build offset, not a correction factor.

| Artifact | C2J2 / old | C3 v2 / new |
|---|---|---|
| Build ID | `43324a32` | `43334531` |
| ELF SHA-256 | `625daf8cc194f1bc7d48eefff0f07939c5e0988bb07fc8a3e7efad7e613a15fd` | `9cbf537bd9440deaf5c78abf6b204da9cbcd2fe3795acf444d733dbd581002b6` |
| Q15 weight header SHA-256 | `961a76b7e220bf2f665e7c04ab62063600aa2e7eccf3403d80ea730bc993ad9f` | same frozen weight identity |
| `rtnn_experiment_runner.c` SHA-256 | `d68f8b9dfe5eddbea43e68f840cbe19543f6c450e0711bb40efab4e82a56082e` | `bd535c9caaabcbe5c45b68a27fbb2c54c8ea82c42c3b7905a00827c507566d88` |
| `rtnn_c2_main.c` SHA-256 | `a6964666d08695bdc447f2315b1683c90a08750a76db1188cb8d8669428cc917` | `fc08bd04460135655e067143ef4cfdfe01a08f64539e2612201e20ad19f826ef` |
| `rtnn_experiment_start.S` SHA-256 | `ba4ec0e60fdd0b3bdf39417eeb6067dbae1dca89fe988e7a6e71eebe133a2c1d` | same |

## Source-level difference and explanation status

The old runner samples a start counter, runs admission/inference/argmax, samples again, and returns a 32-bit elapsed value. It does not write the start sample to the response object inside the measured interval. The new runner writes `out->cycles_start = before` immediately after sampling the start counter, executes the same modeled inference path, then records a 64-bit end sample after argmax. The wire response also grew from 48 to 60 bytes, while the response commit address and build/binding identities changed.

The extra start-value store is inside the stated measurement interval and is therefore a plausible explanation for a small constant increment. It is not proven to account for precisely five cycles. We could not perform the disassembly comparison requested by the audit: Windows has no RISC-V objdump/LLVM objdump in PATH; the available WSL Ubuntu-22.04 launches timed out before a shell prompt; the bundled Quartus objdump is Nios II-specific and is not a RISC-V disassembler. No firmware binary was modified or rebuilt for this audit.

**Verdict: OBSERVED_OFFSET_PASS; CAUSAL_ATTRIBUTION_UNRESOLVED.** The +5 is reproducible in the archived paired rows; its instruction-level cause remains unverified. Do not subtract five cycles from either build or claim the difference is exclusively caused by the new start-store without a compiler-matched RISC-V disassembly/trace.

## Reproduction and evidence references

- Primary comparison: `generated_run1/analysis.json` and `generated_run1/input_level.csv`.
- Old firmware source recovery: `../source/recovered_c2_firmware_43324a32_20261115/`.
- New firmware source: `../source/measurement_protocol_v2_43334531_20261115/`.
- Old ELF manifest: `../../C2/evidence/candidate_firmware_build/c2_firmware_manifest.json`.
- New ELF manifest: `../evidence/C3_MEASUREMENT_V2_RV32_BUILD_20261115/build_manifest.json`.
