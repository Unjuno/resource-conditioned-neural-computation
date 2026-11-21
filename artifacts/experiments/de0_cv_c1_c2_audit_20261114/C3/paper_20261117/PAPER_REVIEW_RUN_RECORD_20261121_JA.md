# 論文準備レビュー実行記録（2026-11-21）

## 対象と保全

- Repository: `https://github.com/Unjuno/resource-conditioned-neural-computation.git`
- Isolated worktree: `C:\Users\junny\OneDrive\ドキュメント\ChatGPT\resource-conditioned-neural-computation-c3-paper`
- Branch: `codex/c3v2-paper-evidence-20261117`
- HEAD at review: `9b0098818728ee00b3e77567ba7f0a11f4e35763`
- `origin`: correct Unjuno repository (fetch/push URL)
- Original worktree `resource-conditioned-neural-computation-audit-20261114` and wrong legacy kardaneh repository were not modified.
- No commit, push, PR, merge, board access, JTAG, SOF write, Quartus run, or external inquiry occurred.

## Commands and results

1. `git status --short; git branch --show-current; git rev-parse HEAD; git remote -v` — repository identity confirmed; initial paper worktree had prior reviewer edits and Pareto outputs, retained in place.
2. `python -m pytest -q test_reanalyze_c3v2_primary.py test_budget_diagnostics.py` — **15 passed** (0.38 s), Python test runner invoked in current Windows environment.
3. `python reanalyze_c3v2_primary.py --out-dir generated_final_20261121_run1` — **PASS**; 13/13 schedules, 24,840 rows, 360 IDs × 10 primary schedules, and 7,200 old/new build pairs. The primary means were 943,929.7667 fixed2 and 746,327.9944 adaptive cycles; saving 197,601.7722 cycles (20.93395%), input-ID bootstrap 95% interval 16.80384–24.90345%. Accuracy paired counts: 336 both correct, 3 fixed-only, 3 adaptive-only, 18 both wrong. All ten repeats have identical per-input/mode cycles.
4. `python analyze_pareto_frontier.py --help` — CLI help inspected.
5. `python analyze_pareto_frontier.py --out-dir pareto_final_run3` — **PASS**; `raw_rows=17640`, `conditions=49`, `frontier_unique=3`, `build=43334531`, `input_ids=360`.
6. The output `SHA256SUMS.txt` for `pareto_final_run3` matched the independent recorded outputs in `pareto_final_run1` and `pareto_final_run2`: JSON `8b5a4c86bdd3b4e2618bc8d362f9b630878c75cca7d874b50b1aaa22c292f1e9`, SVG `37b574cb55b94197e6ab19469a057e87f16ee07f32e93a79ae3374a8aa714db8`, CSV `aeb3f501c6c0e5b3b4e6964c2e672062bd9ad308bcfe20dd274b96edd8acc968`.
7. Windows-generated text outputs were normalized to LF, and their `SHA256SUMS.txt` was regenerated. The five primary output files now match `generated_run1/` byte-for-byte and the output manifests match. The numeric analysis was unchanged by newline normalization.

Pareto output coordinates (post-hoc, descriptive):

| Frozen condition | Accuracy | Mean `mcycle` |
|---|---:|---:|
| Fixed Exit 0 | 47.500% | 20,152.911 |
| Fixed Exit 1 | 91.111% | 482,039.636 |
| Adaptive, Q0.16 budgets 22,937 / 26,214 / 29,491 | 94.444% | 691,343.072 |

The three adaptive budget values have identical coordinates on this saved sample and are grouped at one point. The plot is not an inferential comparison, and does not replace the maximum-budget fixed2 primary comparison.

## Corrections and preserved failures

The first Pareto run failed because the raw CSV does not carry fixed-exit/budget values; those values are in the frozen `cases.csv` manifest. The analyzer was revised to join requests against that manifest and validate sequence/input identity, CRC, build/SOF/binding, counter interval and expected labels. No frozen input, schedule, raw result or model file was changed. Output directories from initial iterations (`pareto_run1/`, `pareto_run2/`) are preserved as superseded intermediate artifacts; final plotted outputs are `pareto_final_run1/` through `pareto_final_run3/`.

The WSL launch used for RISC-V disassembly did not return a shell within its 10-second probe and was interrupted. No distro files were modified. Windows had no RISC-V objdump/LLVM objdump available in PATH; bundled Quartus objdump was Nios-II specific. Thus the +5 cycle observation is confirmed, but causal attribution is unresolved.

## External methods reviewed

The targeted primary-source bibliography was updated in the manuscript and `PRIOR_ART_COMPARISON.md`. Prior work includes BranchyNet, MSDNet, SkipNet, EENet, entropy-based low-precision FPGA early exit, entropy-driven FPGA filtering, 2025 FPGA dynamic early exit, and static WCET work for time-predictable processors/FPGA DPU systems. This is a focused review, not a systematic literature search.

## Exact limits

- Saved C3 v2 data: 24,840/24,840 requests and 13/13 schedules; reanalysis only, not a new experiment.
- The 360 IDs are the unique input units; repeats across schedules are not extra independent images or boot sessions.
- 20.934% is a descriptive maximum-budget adaptive vs previously inspected fixed Exit 2 contrast for one board/build/session.
- Accuracy noninferiority at 1 pp remains INCONCLUSIVE; independent cold-boot variability UNCERTAIN.
- `B-EMPIRICAL=PASS_LIMITED`; `B-SIGNOFF=BLOCKED_EXTERNAL_BOARD_TIMING`; exact 146-source graph remains 145/146 and blocked; WCET/hard deadline NOT_ESTABLISHED.
- The paper draft is not publication-ready until all references, dataset/model licensing, venue format, and author approvals are checked.

## Reproduction

From this directory, with Python 3 installed:

```powershell
python -m pytest -q test_reanalyze_c3v2_primary.py test_budget_diagnostics.py
python analyze_pareto_frontier.py --out-dir pareto_reproduction_new
```

The output directory must be new. Verify `pareto_reproduction_new/SHA256SUMS.txt` against `pareto_final_run3/SHA256SUMS.txt` for deterministic regeneration. Inputs are read from the archived frozen campaign and remain untouched.
