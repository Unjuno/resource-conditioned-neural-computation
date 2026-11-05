# Codex handoff: reconcile DE0-CV Stage 3, then collect paper-grade RTNN data

**As of 2026-11-06. Execution instructions, not a completed test report.**

This is the operating handoff for Codex on the **actual local Stage 2/Stage 3 working tree**. Its inputs are [reported status](de0_cv_stage2_stage3_status_2026-11-06.md), [paper measurement protocol](de0_cv_paper_protocol_2026-11-06.md), the existing [physical-stage preregistration](realtime_nn_de0_cv_next_stage.md), and local raw evidence. The public GitHub repository **does not automatically contain** the latest local Quartus builds, Stage 2 ZIP overlays or the parallel paper track.

## Codex mission

Produce a signed-off, auditable transition from:
- operator-reported 2026-11-03 host/RTL/SoC results;
- 50 MHz Fitter/STA failure (best reported HPerf seed 2: 48.29 MHz, setup slack -0.710 ns);
- no hardware data accepted at that evidence cut-off;

to:
- actual current result inventory with exact hashes and links;
- root-caused, correctly constrained 50 MHz closure or an explicit documented blocker;
- approved hardware bring-up and fixed/adaptive Q15 oracle parity;
- immutable captures sufficient for a preregistered paired cycle/accuracy comparison.

Treat local work done after 2026-11-03 as **unknown until inspected**. Do not overwrite its evidence with this older snapshot.

## Execution order

### A. Read-only inventory first

1. Locate the original STATUS_2026-11-03_JA.md and all newer STATUS, TimeQuest, Fitter, command transcripts, SOF/ELF/BIN, test logs and SHA-256 manifests. A historical relative location is:
   
       de0cv_setup/verified_inputs_2026-11-03/stage2_finalwork/fpga/de0_cv/evidence/codex_setup/codex_2026-11-03_run_02/

2. Record actual git remote, branch, HEAD, status, untracked/ignored files and upstream Ibex revision before any cleanup. Do not confuse the external lowRISC Ibex repository with the project's public RTNN repository.
3. Inspect local disk space, tools, board connectivity and supported target part. The old 3.4-GiB C-drive number is historical, not a current allocation.
4. Confirm the recorded 98 host, 720 RV32, RAM/UART, Q15 SoC, sv2v regression and 108 warnings against original commands and raw logs. Missing data => UNCERTAIN.
5. Compare the separate paper-statistics overlay with the Stage 2 Codex working tree. Preserve the existing 13 schedules / 24,840 planned rows and their hashes unless a **new preregistered campaign** is authorized.

**Output A:** a dated status matrix recording source path, build hash, command, tool version, test denominator, result, log SHA, reviewer and unresolved gaps. Existing results must be marked REPORTED_PASS until raw verification.

### B. Diagnose 50 MHz path and correct the minimum necessary cause

1. Read .sdc/.qsf and all TimeQuest/Assembler/Fitter reports; distinguish no constraints, false constraints, and actual logic/routing critical paths. Classify the 108 warnings; do not report a raw warning count without severity and acceptance reasoning.
2. Record clock targets, setup/hold WNS/TNS, all relevant process/voltage/temperature corners, unclocked and unconstrained endpoints, clock groups/CDC, asynchronous reset, pin I/O standards, RAM inference and initialization.
3. Identify precise startpoint/endpoint and logic/routing delay breakdown for worst paths. Change only justified constraints or the minimum RTL needed. Preserve functional semantics and record a diff for every attempt.
4. Re-run unit/SoC/host regression for every changed design; specifically compare RAM latency/read-during-write, UART TX/RX, reset and Q15 fixed/adaptive outputs. Preserve simulator command and seed.
5. Run Fitter/STA for the exact candidate and record both PASS seeds and failed seeds; never select a lucky seed without disclosing strategy. If 50 MHz is not achieved, explicitly mark FAIL and stop the 50-MHz signoff. A lower-frequency debug branch must use a **different identity**, not a redefinition of the goal.

**Output B:** exact passing/failing configurations, SDC audit, timing path cause, regression proof, warnings disposition, SOF hash (if built), total utilization and build scripts.

### C. Board gate, only if safe and authorized

1. Confirm board/FPGA part, VCCIO and pin constraints from official hardware references. UART must not be connected to RS-232 voltage or unsupported I/O levels. Record power/reset, JTAG and clock evidence.
2. Before flashing, require valid pin/voltage assessment, correct build identity, completed relevant timing gate and explicit operator permission.
3. Begin with separate LED/reset/JTAG/UART sanity build; then perform 42 legacy pilot cases before a large experiment. Save the actual programming log, byte-accurate UART captures, CRC/parity checks and all failed trials.
4. Audit 42/42 predictions and exits against the frozen Q15 oracle and confirm no physical block-cap or exception defect. If one failure occurs, stop and diagnose before more work.
5. Build a new fixed/adaptive measurement SOF with exact compiler, RTL, RAM and source identities. Do not reuse Simple-System certification cycles or mix pilot and paper bitstreams.

**Output C:** board bring-up report, configuration photograph/inventory references where available, programming trace, exact SOF/ELF hashes, 42-case functional audit and an explicit board-readiness PASS/FAIL/UNCERTAIN.

### D. Locked paper campaign

1. Retrieve and audit the real local paper/campaign/campaign.json, hardware_review.json, 13 schedules, 360-input oracle and all hashes. Choose **one** active campaign identity and freeze its protocol before acquisition.
2. Run exactly the chosen protocol: full seven-class, 21-budget and paired fixed2/adaptive tests as permitted by the reviewed schedule. Counterbalance order and retain distinct input, session, independent cold-boot, reset and repetition IDs. Do not silently add repetitions or exclude hard cases.
3. Measure NN+entropy inference cycles over the same counter boundaries; put UART latency in a separate experiment if measured. Store raw serial bytes and record CRC, request sequence, cycle wrap and timeouts.
4. Run a checksum-driven completeness audit against expected schedule rows; reject unscheduled/duplicated captures, log missing rows and preserve rejects. A reported 24,840 planned rows is not a verified actual count until this audit.
5. Analyze paired per-input cycle differences and separate boot effects; noninferiority is **not** established by equal 339/360 offline accuracy. The 1-pp offline bound was INCONCLUSIVE. Report confidence intervals and negative results honestly.
6. Export reproducible paper tables/plots from immutable raw records only, with analyses and figure generation scripts pinned to the same build/campaign ID.
7. Keep time-aware/learned halting, CUDA pilots, FPGA-specific deadline-admission and WCET claims out of the primary frozen-Q15 study. They require a **new versioned campaign and timing-binding evidence**.

**Output D:** raw unmodified captures; SHA-256 manifest; completeness and numeric/identity audit; analysis logs and scripts; reproducible figures/tables; explicit claim-and-nonclaim statement. Do not write a purported FPGA improvement into the paper until supported by measurements.

## Required result status vocabulary

- **PASS** — observable gate criteria satisfied, raw logs exist, input/target identity and exact denominator verified.
- **FAIL** — a real functional/structural/STA/statistical criterion has been violated.
- **INCONCLUSIVE** — experiment ran but its confidence/equivalence/noninferiority criterion was not demonstrated.
- **UNCERTAIN** — missing/contradictory evidence or unverified assumptions.
- **NOT_RUN** — the activity was not executed for this exact target.
- **EMPIRICAL_ONLY** — exploratory measured timing is not a certified hardware execution bound.

No stage may be promoted from UNCERTAIN/NOT_RUN to PASS based on a directory name, generated command, a passing host test, a published screenshot or a previous target's timing result.

## Repository boundaries and deliverables

- Work on a separate review branch, **not** directly on main. Do not make speculative firmware fixes in public Git without the actual current local tree.
- Keep existing frozen weights, Simple-System certified artifacts, oracle data, and pre-registered schedules unchanged.
- If the local Stage 2 tree contains confidential machine paths, raw cable serials or unnecessary large binaries, sanitise metadata before public publication while retaining a private immutable verification package.
- Avoid deleting/moving files, re-imaging WSL, changing external remotes, rewriting history, merging or pushing to main without explicit authorization.
- After review, submit a PR containing the new *evidence-backed* status and implementation changes, grouped by provenance. State **exactly which** gates and test cases were actually executed, and link the relevant evidence.
- If hardware is unavailable, complete source/RTL/STA audits and issue a blocked status with the fastest next physical check. Do **not** fabricate on-board data.

## Definition of done

An acceptable Codex report must include:
1. an independently checked *latest* gate table (not just the 2026-11-03 snapshot);
2. source/overlay/SOF/ELF/Q15-oracle/campaign SHA-256 mapping;
3. precise 50 MHz closure status and warning disposition;
4. board test status with program/byte-log proof or explicit NOT_RUN;
5. manuscript-supported claims and their exact measured uncertainty/status;
6. the shortest ordered set of remaining blockers.

Stop on wrong build identity, unexpected IO pin/voltage, missing clock constraints, wrong prediction, physical block-cap breach, invalid CRC, boot-state misassociation, counter anomaly or campaign-hash mismatch.

## User-facing summary format for Codex

    Stage 2 verified vs merely reported:
    Stage 3 STA current best and worst path:
    50 MHz gate (PASS/FAIL/UNCERTAIN):
    FPGA programming and 42-case pilot:
    360 fixed/adaptive campaign completion:
    Paper efficacy result (cycle/accuracy/CI):
    Separate target-specific timing/WCET status:
    Changed files, branch, raw evidence pointers:
    First blocking issue and one next task:

This handoff intentionally ends at reproducible evidence and a reviewable branch. A paper-ready conclusion must still be earned by actual measurements.
