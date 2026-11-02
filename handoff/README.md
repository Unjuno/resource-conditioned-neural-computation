# RTNN DE0-CV / Codex handoff (2026-11-03)

**Source of truth: this dedicated handoff branch, not `main`.** This is a delivery of previously created, unmodified archives, not a claim of FPGA validation. The branch starts from main commit `ea903d3b76c4cb50732c3f9c72c8ed2084c2cb23`; main is unchanged.

## Downloads

- [RTNN_DE0CV_RV32_stage2_2026-10-31.zip](./RTNN_DE0CV_RV32_stage2_2026-10-31.zip) — 1891054 bytes; SHA-256 `7f5c666514729b0d5f776904ec5662187271beb90f30d4c33231b7b92b4c5507`
- [RTNN_Codex_FPGA_environment_handoff_2026-10-31.zip](./RTNN_Codex_FPGA_environment_handoff_2026-10-31.zip) — 1840392 bytes; SHA-256 `c81f7bd81625247712fcea5d0a954dc3a7f24d2908e82e841de7eddfe908011e`
- [RTNN_parallel_paper_eval_2026-11-02.zip](./RTNN_parallel_paper_eval_2026-11-02.zip) — 52039 bytes; SHA-256 `02ad8a83daabcef44335d58513c2f4ae0aef622089eae62026df6b2406ede137`

### Windows PowerShell (from this repo checkout)

```powershell
powershell -ExecutionPolicy Bypass -File .\handoff\download-inputs.ps1 -Destination 'C:\Users\junny\OneDrive\ドキュメント\ChatGPT\RTNN\de0cv_setup\inputs'
```

Or fetch this branch without switching from the existing branch:

```powershell
git fetch origin handoff/de0cv-stage2-2026-11-03
New-Item -ItemType Directory -Force .\inputs | Out-Null
git show 'FETCH_HEAD:handoff/RTNN_DE0CV_RV32_stage2_2026-10-31.zip' > .\inputs\RTNN_DE0CV_RV32_stage2_2026-10-31.zip
git show 'FETCH_HEAD:handoff/RTNN_Codex_FPGA_environment_handoff_2026-10-31.zip' > .\inputs\RTNN_Codex_FPGA_environment_handoff_2026-10-31.zip
git show 'FETCH_HEAD:handoff/RTNN_parallel_paper_eval_2026-11-02.zip' > .\inputs\RTNN_parallel_paper_eval_2026-11-02.zip
Get-FileHash .\inputs\*.zip -Algorithm SHA256
```

**Note:** PowerShell output redirection can alter binary data in some versions; prefer the provided download script, which saves raw response bytes and verifies SHA-256. Do not use `git show ... > file.zip` unless the shell's binary redirection is known safe.

### Linux / WSL

```bash
mkdir -p inputs
base="https://raw.githubusercontent.com/Unjuno/resource-conditioned-neural-computation/handoff/de0cv-stage2-2026-11-03/handoff"
curl -fL --retry 3 "$base/RTNN_DE0CV_RV32_stage2_2026-10-31.zip" -o "inputs/RTNN_DE0CV_RV32_stage2_2026-10-31.zip"
curl -fL --retry 3 "$base/RTNN_Codex_FPGA_environment_handoff_2026-10-31.zip" -o "inputs/RTNN_Codex_FPGA_environment_handoff_2026-10-31.zip"
curl -fL --retry 3 "$base/RTNN_parallel_paper_eval_2026-11-02.zip" -o "inputs/RTNN_parallel_paper_eval_2026-11-02.zip"
(cd inputs && sha256sum -c ../handoff/SHA256SUMS)
```

## Apply order

1. Extract the Stage 2 ZIP to an isolated working directory and run its existing host/RV32 regression tests.
2. Read the environment handoff ZIP for the pinned versions and verification gates.
3. Apply the paper-evaluation ZIP only via its included SHA-guarded overlay procedure; it is not a Stage 2 replacement.
4. Proceed with Verilator RAM/UART, pinned Ibex SoC RTL, sv2v regression, Quartus fitter/STA; report each gate separately.
5. Do not push, merge, or modify `main` automatically. Do not flash the board automatically.

These ZIPs contain previously generated host/ISA artifacts, **not** finished RTL verification, timing signoff or hardware performance data.
