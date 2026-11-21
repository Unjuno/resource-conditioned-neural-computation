# C2J2/C3 v2 cycle-offset disassembly addendum

Date: 2026-11-22
Scope: static comparison of the preserved old and new RV32 firmware ELFs. This addendum supersedes only the earlier statement that a RISC-V disassembler was unavailable; it does not change the measured data or establish a causal cycle model.

## Artifact identity

The preserved ELF files were hashed before disassembly and match their build manifests:

| Build | ELF | SHA-256 | Build record |
|---|---|---|---|
| C2J2 old, `43324a32` | `C3/evidence/C2_SOURCE_RECOVERY_REBUILD_20261115/rtnn_c2_experiment.elf` | `625daf8cc194f1bc7d48eefff0f07939c5e0988bb07fc8a3e7efad7e613a15fd` | `c2_firmware_manifest.json` |
| C3 v2 new, `43334531` | `C3/evidence/C3_MEASUREMENT_V2_RV32_BUILD_20261115/rtnn_c3_measurement_v2.elf` | `9cbf537bd9440deaf5c78abf6b204da9cbcd2fe3795acf444d733dbd581002b6` | `build_manifest.json` |

Both headers identify ELF32 little-endian RISC-V. The C3 v2 build manifest reports Ubuntu Clang/LLD 18.1.3. The disassembler was Ubuntu LLVM `llvm-objdump` 18.1.3 with RISC-V target support. Captured disassemblies, symbol tables, ELF headers, tool version, and hashes are in `cycle_offset_disasm_audit_20261122/`; `SHA256SUMS.txt` covers those files. No ELF was changed or rebuilt.

## Static findings

The old and new source-level measurement paths both sample `mcycle` immediately before budget/admission/inference work and sample again after inference and `argmax`. The old path returns a 32-bit elapsed count. The new path stores the 64-bit start sample in `out->cycles_start`, stores a 64-bit end sample, and validates monotonicity and nonzero span.

The compiler-generated `machine_cycles` functions in both ELFs have the same five-instruction high-low-high sampling loop (with different addresses): read `mcycleh`, read `mcycle`, read `mcycleh`, retry if the high halves differ, return. The source-level assembly helper `rtnn_experiment_start.S` also has the same SHA-256 in both builds (`ba4ec0e60fdd0b3bdf39417eeb6067dbae1dca89fe988e7a6e71eebe133a2c1d`).

In the new `rtnn_fw_execute` path, immediately after the start-counter callback returns, the disassembly stores the returned low and high words to the response object (`sw` at offsets `0x18` and `0x1c`). The old path has no corresponding response start-sample stores. This confirms that the new build has extra in-boundary work associated with recording the start value.

The two complete ELFs are not otherwise instruction-identical: `rtnn_fw_execute` differs in size and generated instructions, the response structure and validation changed, and the build/source identities differ. Static instruction inspection alone does not model Ibex stalls, RAM wait states, or all executed branches. Therefore it cannot show that the two stores cost exactly five cycles or that they are the sole cause of the observed offset.

## Conclusion

The paired empirical observation remains **7,200/7,200 matched rows at exactly +5 cycles in C3 v2**, with matching predictions and exits. The static audit makes the in-boundary 64-bit start-sample stores a concrete plausible contributor. The causal attribution remains **UNRESOLVED**; do not subtract five cycles or present it as a proven store cost. Establishing exact causality would require a validated cycle-accurate trace or controlled compiler-matched build comparison under the same RTL/memory timing and measurement conditions.

## Reproduction

From WSL with Ubuntu LLVM 18.1.3 installed, run from the repository root (paths are relative to this root):

```sh
llvm-readelf -h artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/evidence/C2_SOURCE_RECOVERY_REBUILD_20261115/rtnn_c2_experiment.elf
llvm-readelf -h artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/evidence/C3_MEASUREMENT_V2_RV32_BUILD_20261115/rtnn_c3_measurement_v2.elf
llvm-readelf -s artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/evidence/C2_SOURCE_RECOVERY_REBUILD_20261115/rtnn_c2_experiment.elf
llvm-readelf -s artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/evidence/C3_MEASUREMENT_V2_RV32_BUILD_20261115/rtnn_c3_measurement_v2.elf
llvm-objdump -d artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/evidence/C2_SOURCE_RECOVERY_REBUILD_20261115/rtnn_c2_experiment.elf
llvm-objdump -d artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/evidence/C3_MEASUREMENT_V2_RV32_BUILD_20261115/rtnn_c3_measurement_v2.elf
```

Compare `rtnn_fw_execute`, `machine_cycles`, and the source files listed in `CYCLE_OFFSET_AUDIT.md`. The captured disassembly is retained so review does not depend on re-running the tool.
