# RTNN DE0-CV / Codex handoff (2026-11-03)

**Source of truth: this dedicated handoff branch, not `main`.** This is a delivery of previously created, unmodified archives, not a claim of FPGA validation. The branch starts from main commit `ea903d3b76c4cb50732c3f9c72c8ed2084c2cb23`; main is unchanged.

## Downloads

- [RTNN_DE0CV_RV32_stage2_2026-10-31.zip](./RTNN_DE0CV_RV32_stage2_2026-10-31.zip) — 1891054 bytes; SHA-256 `7f5c666514729b0d5f776904ec5662187271beb90f30d4c33231b7b92b4c5507`
- [RTNN_Codex_FPGA_environment_handoff_2026-10-31.zip](./RTNN_Codex_FPGA_environment_handoff_2026-10-31.zip) — 1840392 bytes; SHA-256 `c81f7bd81625247712fcea5d0a954dc3a7f24d2908e82e841de7eddfe908011e`
- [RTNN_parallel_paper_eval_2026-11-02.zip](./RTNN_parallel_paper_eval_2026-11-02.zip) — 52039 bytes; SHA-256 `02ad8a83daabcef44335d58513c2f4ae0aef622089eae62026df6b2406ede137`

### Windows PowerShell (safe binary downloads)

From your existing repository checkout, fetch this handoff branch without switching branches; extract only the text download script, review it, then run it:

```powershell
git fetch origin handoff/de0cv-stage2-2026-11-03
git show 'FETCH_HEAD:handoff/download-inputs.ps1' | Set-Content -Encoding UTF8 (Join-Path $env:TEMP 'rtnn-download-inputs.ps1')
Get-Content (Join-Path $env:TEMP 'rtnn-download-inputs.ps1')
& (Join-Path $env:TEMP 'rtnn-download-inputs.ps1') -Destination 'C:\Users\junny\OneDrive\ドキュメント\ChatGPT\RTNN\de0cv_setup\inputs'
```

The script writes binary ZIP files using `Invoke-WebRequest -OutFile`, checks SHA-256, and refuses to overwrite an existing file with a different hash. **Do not** use PowerShell `git show ... > file.zip`: Windows PowerShell may corrupt binary redirects.

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
