# Pilot Tcl runner hotfix v2 — 2026-11-26

The first physical runner attempt stopped before sending any request. It exposed two defects in the original Tcl runner:

1. `xcrc` had a mismatched `}`/`]` in the reflected CRC32 update expression, causing `missing close-bracket` on the first image payload.
2. The error-path `run_status.json` writer escaped quotes inside a braced Tcl `expr`, so the secondary error masked the first error and left an empty status file.

This version is a copy of the existing runner with those fixes. It preserves the same JTAG request/response validation, Build/Binding/Model IDs, and measurement boundary. The RTL, SOF, ELF, Q15 model, and frozen pilot inputs are unchanged. `RUN_ERROR_INFO` is now kept in the raw log, and status JSON is assembled with a safe boolean and escaped error field.

The original runner remains available at `../host/run_external_validation.tcl` and is not changed. Original SHA-256: `cc3ee76878ec0611685426751bb8daba89c8554d411484d55fd0d41649feb4a9`.

Quartus 25.1 STP Tcl failed when its script path was under the Japanese OneDrive path, while the same read-only identity script succeeded from an ASCII-only Temp path. For the pilot, stage byte-identical runner/binding/cases/validator copies to an ASCII-only Temp directory and verify their hashes before launch. Preserve final evidence in the repository using the wrapper's output and then copy the complete run directory without changing files.

Before any new physical request, use a new experiment ID and output directory. The failed RUN1 evidence is preserved separately and is not eligible to produce a pilot gate.
