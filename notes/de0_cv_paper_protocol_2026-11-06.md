# RTNN DE0-CV paper-grade measurement protocol (review draft, 2026-11-06)

**State: draft integration plan; not a completed experiment, not a new frozen campaign.**
This note builds on [the existing target preregistration](realtime_nn_de0_cv_next_stage.md) and the [Stage 2 evidence ledger](de0_cv_stage2_stage3_status_2026-11-06.md). It does not authorize changing the frozen seed-63 Q15 model, test-set labels, or existing experiment schedules.

## 1. Research claim to test

**Primary system hypothesis:** Under a precisely identified, timing-closed DE0-CV/Ibex/controlled-on-chip-RAM configuration, the same Q15 neural weights plus the adaptive compute policy reduce mean *measured inference cycles* relative to fixed 2-block execution, while preserving an agreed classification-accuracy noninferiority bound and enforcing the declared physical work cap.

These are three **independent** claims: (a) numeric/control correctness, (b) latency advantage, (c) accuracy noninferiority. Passing one does not imply the others. A later **deadline-admission** study is a separate claim that requires a newly established target-specific timing upper bound.

The project mechanism is resource-conditioned physical execution: a continuous input budget is lowered fail-closed to finite permitted work classes, the same model may stop earlier based on input/state, and the physical execution must not exceed its admitted ceiling. This is *not* a router-only accuracy paper.

## 2. What we already know and must not relabel

The separately prepared 2026-11-02 paper/analysis track reported this **offline frozen-Q15 reference**, not DE0-CV inference cycles:
- 360 fixed held-out inputs; fixed2 correct **339/360**.
- Adaptive correct **339/360**; mean executed optional blocks **489/360 = 1.35833333**.
- Both correct 336; both wrong 18; fixed2-only correct 3; adaptive-only correct 3.
- Paired accuracy difference adaptive-minus-fixed2 **0.00 percentage points**.
- Reported 5,000-repetition input-unit bootstrap 95% percentile interval for that difference **[-1.3889, +1.3889] percentage points**; an intended 1-pp noninferiority margin is **INCONCLUSIVE**. McNemar two-sided p=1.0 does not prove equivalence.
- The offline paper extension was prepared in a **separate Stage 2 copy** and was **not automatically merged with the Codex working directory**.
- It reported **24,840 planned rows** in **13 frozen schedules** with unchanged schedule hashes, but a newer campaign identity. Those schedules and SHA values must be verified from the actual local overlay before use; do not infer them from this note.

The 2026-11-03 operator report later documented 98 host PASS, 720 RV32 function PASS, fixed/adaptive Ibex SoC Q15 PASS, and post-sv2v regression PASS, but **50 MHz STA failed** and physical programming did not run at the report cut-off. These are *reported* results and must be linked to raw evidence.

**No DE0-CV speedup, energy saving, accuracy equivalence, deadline guarantee, GPU improvement, or WCET certificate is established here.**

## 3. Build and protocol locking before measurement

Record immutable identifiers for:
- public repository commit and any locally reviewed overlay commit/diff;
- Q15 weights, expected-output oracle and 360 test-input SHA-256;
- ELF/BIN, RAM init, top-level RTL, sv2v outputs, QSF/SDC and post-fit SOF SHA-256;
- Ibex exact commit/configuration and tool versions (Clang/LLD/objcopy or GCC as **actually used**, not guessed);
- board type/revision/FPGA part, JTAG cable ID, UART pins/3.3-V level, clock domain, reset behaviour and memory primitive/response latency;
- build flags including optimization, ABI/ISA, stack and linker-script assumptions; cache/interrupt/DMA/arbitration policy;
- campaign ID, schedule SHA, randomization seed, measurement start/end events, exclusions and stop criteria.

Review the original 2026-11-02 local campaign files with the Codex workspace **before selecting exactly one active campaign**. In particular, do not mix old and new campaign hashes (the report mentioned different dce387... and d6c98f... prefixes). **Do not change the existing frozen 24,840-row/13-schedule plan without an explicit new version and preregistration**.

The public GitHub repository currently documents an older Ibex *Simple-System* timing table. Do not transfer that table or its deterministic-memory proof to this FPGA. Different SOF/ELF/SDC means a new target identity.

## 4. Sequential physical experiment gates

| Gate | Experiment | Required evidence | Advance only if |
|---|---|---|---|
| P0 | Import and reconcile exact Stage 2 and latest Stage 3 logs; audit SDC, warning 108 and manifests | raw logs, 50 MHz path reports, SHA, source/target map | identity consistent; each discrepancy resolved or documented |
| P1 | Post-fit 50 MHz setup **and hold** closure, I/O/CDC/exception/clock completeness, RAM synthesis review | Quartus Fitter+TimeQuest reports, resource use and exact SOF | validated constraints; no mandatory unconstrained path; WNS >= 0 at required corners |
| P2 | Small on-board bring-up (LED/reset/JTAG/clock, UART and legacy A 42 functional cases) | actual programming log, original raw UART, 42-case audit, boot IDs | 42/42 Q15 prediction/exit match, no wire/trap/reset defect |
| P3 | Fixed seven-class census: 360 frozen inputs x 7 exits = 2,520 expected logical cases | raw captures, class/execution counts, oracle identities | zero mismatch, physical cap violations, dropped unreported cases |
| P4 | Adaptive/budget census: 360 x 21 budgets = 7,560 expected logical cases | raw captures and 21-budget schedule | all correctness/cap/identity gates PASS |
| P5 | Paired fixed2 vs adaptive benchmark, using the **reviewed frozen campaign schedule** | per-input, per-boot, per-repetition cycles and order | complete paired dataset, independent boot evidence, appropriate error accounting |
| P6 | Paper-analysis audit and figure generation **after** P0-P5 | immutable complete data, analysis code, signed audit, figures | qualified claims exactly match reviewed results |
| P7 | Optional new target-specific deadline experiment | separately reviewed cycle upper bounds, new binding/ELF/SOF and boundary tests | separate empirical-vs-hard-real-time classification |

The historical runbook proposed **at least 3 independent cold boots and 10 repetitions per input/mode** for a repeated paired benchmark, with randomized/counterbalanced mode order. That is an initial design target, **not permission to rewrite an already frozen 24,840-row campaign**. If the existing schedules differ, reconcile and preregister a new campaign *before* collecting data; never retrofit replicates after reviewing outcomes.

No physical programming before valid pin/I/O/voltage preflight and an operator-authorized board session. A lower-clock exploratory SOF may be informative but **does not fulfill P1 at 50 MHz**.

## 5. Measurement and data definition

Use the processor/RTL clock counter (verified against the chosen clock) around a **fixed inference-only interval** that includes NN computation and entropy/early-stop decision, but excludes UART serialization. If end-to-end latency is also measured, label it as a separate endpoint with explicit I/O boundaries. The two modes require identical timing boundaries, firmware semantics, input representation and target assumptions. Cold boot independently; separately log reset-only trials.

Minimum machine-readable record (raw responses are archived separately):

    campaign_id,build_id,sof_sha256,elf_sha256,board_id,boot_id,session_id,
    run_id,repetition_id,request_sequence,input_id,mode,budget_q16,
    order_index,start_cycles,end_cycles,elapsed_cycles,
    predicted_label,reference_label,preferred_exit,executed_exit,
    physical_block_count,cap_violation,crc_ok,trap,error_code,
    clock_hz,measurement_boundary_id,raw_capture_sha256

Never silently drop CRC failures, timeouts, rejects, unmatched input IDs, duplicate response IDs or nonpositive/counter-wrapped intervals. Store raw request and response bytes, not just parsed CSV. Preserve record-order and cold-boot identifiers.

### Metric dictionary

| Symbol | Meaning (Japanese) | SI unit | Definition | Domain / assumptions | Type |
|---|---|---|---|---|---|
| \(i\) | 独立評価入力ID | 1 | frozen input identifier | 360 unique IDs, no test tuning | integer scalar |
| \(b\) | 独立cold-boot ID | 1 | physically distinct power-on boot | positive integer | integer scalar |
| \(r\) | 起動内の反復番号 | 1 | paired repetition ID | positive integer | integer scalar |
| \(m\) | 実行方式 | 1 | fixed2 or adaptive | categorical | categorical scalar |
| \(C_{ibr}^{(m)}\) | 計測した推論cycle数 | 1 (cycle count) | end counter - start counter for matching interval | nonnegative integer; validated wrap/reset | integer scalar |
| \(f_{\rm clk}\) | 対象FPGAクロック | Hz | measured or verified clock for same target | positive real scalar | real scalar |
| \(t_{ibr}^{(m)}\) | 推論時間 | s | \(C_{ibr}^{(m)}/f_{\rm clk}\) | single clock and accepted interval | real scalar |
| \(\Delta_C\) | 平均cycle削減量 | 1 (cycle count) | mean of paired \(C^{(fixed2)}-C^{(adaptive)}\) | matched input+boot+repetition | real scalar |
| \(R_C\) | 平均cycle削減率 | 1 | \(\Delta_C/\overline{C^{(fixed2)}}\) | positive fixed2 denominator | real scalar |
| \(A_m\) | 方式別の入力単位正答率 | 1 | correct unique inputs / total unique inputs | evaluated on 360 IDs once per method for accuracy | real scalar in [0,1] |
| \(\Delta_A\) | 適応と固定2の正答率差 | 1 | \(A_{adaptive}-A_{fixed2}\) | paired unique inputs | real scalar in [-1,1] |
| \(\delta_A\) | 事前登録する非劣性幅 | 1 | accuracy difference margin | provisional 0.01; freeze before measurement | positive real scalar |
| \(u_c\) | 合成標準不確かさ | same as measured measurand | from explicit error model, if estimable | unknown until calibrated | real scalar |
| \(k\) | 包含係数 | 1 | documented coverage factor | unspecified until methodology fixed | positive real scalar |

The following metric definitions are deterministic calculations; they are **not measured results**:

\[
\Delta_C=\operatorname{mean}_{i,b,r}\!\left(C_{ibr}^{(fixed2)}-C_{ibr}^{(adaptive)}\right),\quad
R_C=\frac{\Delta_C}{\overline{C^{(fixed2)}}},\quad
t_{ibr}^{(m)}=\frac{C_{ibr}^{(m)}}{f_{\rm clk}}.
\]

Dimensional check: cycle count is a dimensionless count; \(C/f_{\rm clk}\) has SI dimension s, \(R_C\) and \(A\) are dimensionless. Example **for unit illustration only**, 250,000 cycles / 50 MHz = 0.005 s; **250,000 is not an RTNN measured value**.

If the exact interval includes firmware serial overhead or differs by mode, do not claim an inference-only speedup. Always report raw cycle distributions as well as mean/median/P95/P99 (descriptive tails are not worst-case certificates).

## 6. Analysis, falsification and statistical decision

**Primary preregistered comparison:** paired fixed2 versus original frozen adaptive on 360 input IDs. A sensible pre-existing illustrative accuracy margin was **1 pp**, but its justification and the *active campaign version* must be confirmed before recording any new physical outcomes. The earlier offline 95% interval crosses -1 pp, so **noninferiority is presently INCONCLUSIVE** and cannot be promoted just because both modes have 339 correct.

- **Functional PASS:** 0 prediction/reference mismatches for prescribed executed exits, 0 physical optional-block cap violations, 0 silently missing/duplicate frames, exact build/campaign hashes and no traps.
- **Cycle advantage PASS:** positive paired mean-cycle reduction and a predeclared 95% paired confidence interval whose lower limit exceeds 0, with consistent direction across independently booted sessions or an explicit robustness analysis. If not, report FAIL/INCONCLUSIVE honestly.
- **Accuracy noninferiority PASS:** predeclared lower confidence bound for \(\Delta_A\) greater than \(-\delta_A\); avoid interpreting equal point estimates or McNemar p=1.0 as equivalence.
- **Paper-ready combined claim PASS:** *all* functional, cycle, and accuracy criteria above, plus immutable raw evidence and replicable scripts. A failed accuracy gate cannot be hidden by lower cycle counts.
- **Deadline guarantee:** a target-specific, defensible **upper bound** for the exact ELF/SOF/memory/clock/configuration is required. An observed maximum, percentile, or synthetic tick table is only **EMPIRICAL_EXPLORATORY_ONLY**.

Infer accuracy uncertainty from **360 unique input IDs**, not from repeated measurement rows. Use paired resampling by input; assess boot/session uncertainty separately or with a documented two-level design. Only 3 boots may inadequately characterize between-boot variation; distinguish descriptive interval from a strong generalization claim. Control test-set reuse: select policy, parameters, thresholds and code using validation/diagnostics; make one locked held-out evaluation and retain negative trials. Multiple exploratory budget/clock comparisons require multiplicity disclosure and no post-hoc promotion to the primary endpoint.

Suggested figures: paired per-input cycle differences (with zero line), cycle distributions and per-boot sensitivity, accuracy-versus-cycles Pareto view, physical exit-count histogram, exact-class cycle spread, and on-time-correct-versus-deadline **only after** the separate validated deadline campaign. Label tool-derived frequency and actual board measurements differently.

## 7. H / T / D / C / U

- **H:** For the exact controlled target, adaptive inference achieves \(R_C>0\) and \(\Delta_A>-\delta_A\), with physically enforced work ceilings.
- **T:** Preserve original 360 frozen inputs and existing campaign schedules, 42-case bring-up, 2,520 fixed-class, 7,560 budget-class logical census; independently booted paired repetitions according to the agreed locked schedule. Stop on any structural error, preserve all samples.
- **D:** PASS/FAIL/INCONCLUSIVE rules above are determined by separate functionality, timing and accuracy checks. No observed-maximum-only hard WCET PASS.
- **C:** Entropy/policy overhead exceeds saved block cost; fixed2 can be faster; clock/BRAM/bus stalls vary with input; cold-boot effects reverse the average; accuracy is not noninferior.
- **U:** Major uncertainty sources are clock accuracy, counter boundaries, RAM arbitration/latency, build-to-build variation, sample-selection bias, repeated input dependence and boot effects. Compute \(u_c\) and \(k\) only for a defined instrument/calibration error model; do not invent values.

## 8. Codex/repository integration boundary

1. Review the local paper overlay and Codex Stage 2 workspace; merge scripts only after source/diff/hash review. The GitHub main branch may not contain those local files.
2. Treat these notes as review/protocol documentation, **not** a new preregistered frozen data file or revised study identity.
3. For each accepted hardware capture, store a SHA-256 manifest linking raw frames, actual SOF and ELF, source, schedule, board and analysis, with failures and exclusions included.
4. Keep time-conditioned learned halting/GPU pilot **separate** from the primary frozen-Q15 static/adaptive claim. Run it only as a separately preregistered follow-up after real target timing is validated.
5. Publish a paper performance statement only after running the automated capture auditor and reviewer checklist against an immutable experiment package.

See [Codex execution handoff](de0_cv_codex_handoff_2026-11-06.md).
