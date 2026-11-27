# Resource-Conditioned Neural Inference with Finite Work Classes: Software Proofs, Pinned-Target RTL Measurements, and a Limited FPGA Integration Pilot

**Integrated evidence-bounded draft — 28 November 2026.** This draft combines separately identified evidence tiers. It is not a report of the unrun external primary campaign, and it does not claim physical WCET or formal board timing sign-off.

## Abstract

Resource-conditioned inference can grant a neural classifier a maximum computation budget while allowing it to stop earlier when additional work is not useful. This paper studies a fixed-parameter, multi-exit handwritten-digit classifier whose continuous normalized budget is lowered fail-closed to one of seven finite work ceilings. Optional blocks are physically skipped, and the same Q15 weights are used across execution classes. The evidence is deliberately separated by artifact and target. Source-level CBMC checks cover finite budget, deadline-class, and execution-control properties under stated abstractions. Binary analyses and cycle measurements cover one exact RV32 Q15 artifact on a pinned Ibex Simple-System configuration; the measured fixed-class cycle counts range from 29,620 to 2,959,381 cycles, with no input-dependent cycle variation in the tested class/input pairs. A separate DE0-CV integration build accepted dynamically supplied 64-pixel inputs: its saved engineering pilot contains 20 requests over ten preselected images in fixed-Exit-2 and adaptive modes, with responses reported to match the CPU Q15 oracle. This pilot is functional evidence, not a population or performance study. An exploratory offline reanalysis of an existing 360-image `sklearn.load_digits` heldout set found equal accuracy for frozen entropy stopping and fixed Exit 2 (339/360 each), while entropy used a mean 1.358 optional blocks rather than 2.000. Its image-bootstrap interval did not establish one-point noninferiority and is not the locked primary test; optional-block counts are not cycles. Exit-wise analysis also found 12/360 images that were correct at a shallower exit and incorrect at a later one. The new UCI external primary campaign has not been run. Data exposure, writer clustering, preregistration chronology, independent cold boots, and DE0-CV external-JTAG timing remain unresolved. Accordingly, the results support a bounded research prototype and exact-configuration observations, not general speed superiority, population noninferiority, hard deadlines, or WCET.

**Keywords:** resource-conditioned inference; conditional computation; early exit; Q15; Ibex; FPGA; formal verification; empirical cycle accounting.

## 1. Introduction

Neural early exits and conditional computation can reduce work for inputs that do not benefit from executing every layer. They do not, by themselves, establish predictable physical latency: model operations, processor cycles, I/O transfer, implementation timing, and a worst-case execution-time (WCET) guarantee are distinct quantities. We present an evidence-bounded case study of a resource-conditioned neural inference prototype and preserve those distinctions throughout.

The interface accepts a normalized resource grant $b\in[0,1]$. A backend maps that grant to the greatest supported finite class not exceeding it, $q_j\in\{0,1/6,2/6,3/6,4/6,5/6,1\}$. The grant is a maximum permission, not a requirement to consume the full amount. An input-dependent preferred stopping decision can further reduce execution, and inactive neural blocks are skipped rather than zero-masked. Conceptually, effective work is bounded by the minimum of admitted budget, preferred work, deadline class, and policy cap.

Here, $b$ is a dimensionless normalized grant over $[0,1]$, and $q_j$ is a dimensionless supported work class over $j\in\{0,1,\ldots,6\}$. They represent ceilings, not a physical unit of time. The cycle values reported below are discrete counts of processor clock cycles; no conversion to seconds is made without a calibrated clock.

The contributions are intentionally limited:

1. A same-model Q15 implementation with a finite, fail-closed resource-class interface and an explicit separation between admitted and executed work.
2. Source-level control proofs and exact-artifact analyses whose assumptions and coverage are documented, alongside a measured cycle binding for a pinned Ibex RTL configuration.
3. A separately versioned DE0-CV pilot demonstrating a dynamic input protocol on ten engineering images, without treating it as a generalization or speed experiment.
4. An exploratory offline analysis that compares frozen entropy stopping with fixed Exit 2 and records counterexamples to monotonic “deeper is always better” assumptions.

Early-exit classifiers, budgeted inference, entropy stopping, and FPGA early-exit implementations are prior art. We make no “first” or general algorithmic novelty claim. Our contribution is the evidence-linked implementation and scoped verification of this prototype. Relevant prior work includes BranchyNet, MSDNet, SkipNet, EENet, entropy-based low-precision FPGA inference, and dynamic early-exit FPGA implementations [1–8]. Real-time neural-network compilation and FPGA CNN timing analyses are related but address stronger timing assurance than the physical-board evidence available here [9,10].

## 2. System and artifact separation

The classifier uses a 16-dimensional embedding, six optional two-head self-attention/MLP blocks (MLP width 32), and seven classifier exits (0–6). The evaluated Q15 weights are frozen. Each result below is attached to its own data, firmware, and target; values from distinct builds are not pooled.

| Evidence set | Identity and scope | What was measured or checked |
|---|---|---|
| Software/formal and pinned RTL evidence | Q15 RV32 artifact; ELF SHA-256 `234a7f46cf227a11f5d97f3c778cbb0c4ed4f7067f8994bcca86c4b08ff4e742`; BIN SHA-256 `266ecb70c723b2164f6fe9039f27d4cb49c4d7271d4aca0cf69f2692cdfdf7a1`; Ibex commit `7b5df75a041affe56e8c235260f98a09b3319008` | CBMC control properties, binary control-flow checks, and cycle measurements in the pinned Simple-System setup. |
| Historical C3 v2 campaign | Separate frozen build and campaign, documented in the 17 November paper draft | 24,840 older-build requests on 360 `load_digits` inputs, including 7,200 primary rows. Not evidence for the newer external-input firmware. |
| New external-input integration pilot | Build `45585631`, binding `45585632`, model `52544e4e`; SOF SHA-256 `5e333e9377b7188a394d04b93b98833d91afb2cd53eca8d976e6aa715dfa00c4`; ELF SHA-256 `4673f6a8b90493c15c327ed3be1167e0fcf3ff2be60292dcb12a1391124a0c2e` | Saved RUN4: ten frozen pilot images × two modes = 20 requests; limited dynamic-input functional check against the CPU Q15 oracle. |
| Offline stopping-rule reanalysis | Frozen Q15 core SHA-256 `a6b2807bd4a60534c250fca3005322cf14ba0a92f6b16e28241109385efc6809`; weight-header SHA-256 `961a76b7e220bf2f665e7c04ab62063600aa2e7eccf3403d80ea730bc993ad9f` | Recomputed exit metrics on the old 359-image validation and 360-image `load_digits` heldout data; no FPGA interaction. |

The historical C3 v2 campaign is retained as an earlier artifact-specific study and is not silently substituted for the new firmware. Its original detailed manuscript remains available at `artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/paper_20261117/MANUSCRIPT_DRAFT_EN.md`; that draft’s C3 v2 quantitative claims do not describe the new external-input build.

## 3. Methods and evidence tiers

### 3.1 Resource contract and software proofs

The runtime distinguishes the budget ceiling, policy cap, model-preferred stopping point, and actual executed blocks. Invalid identities and partial certification fail closed. CBMC checks finite integer-domain properties of the represented C control contract, including monotone/greatest-fit Q0.16 lowering, deadline-class admission, effective execution below its ceilings, and selected fixed-point lookup-table arithmetic bounds. A complementary proof extracts deployed control bodies and abstracts the neural entropy result nondeterministically, so all continue/stop outcomes are considered for the control-order and cap properties.

These are source-level statements about specified C functions and abstractions. They do not prove the complete neural arithmetic, compiler-to-machine equivalence, processor timing, FPGA timing, or physical WCET. The exact proof entry points, logs, and assumptions are listed in the repository’s formal evidence map.

### 3.2 Binary and pinned Ibex RTL evidence

The exact Q15 RV32 artifact was analyzed on pinned upstream Ibex commit `7b5df75a041affe56e8c235260f98a09b3319008` with the documented Simple-System configuration: two-stage execution, no instruction cache or branch predictor, deterministic one-cycle internal RAM, one host, and no interfering master in the validation harness. The complete setup is build-specific. Fixed-class cycle counts were measured in RTL for classes 0–6 on three heldout inputs with preferred exits 1, 3, and 5. The adaptive path was also exercised in a finite 21-case RTL set. Prediction, executed-exit, admission, and committed runtime-binding checks are reported in the source evidence.

Two compiled control-flow analyses cover the exact retained ELF’s fixed-class paths. The custom taint interpreter reports no input-dependent conditional branches, indirect-control targets, or store addresses on those paths; four input-dependent LUT load sites remain. BINSEC independently reports all seven fixed classes secure for the analyzed control-flow property. Generic relational memory noninterference is not claimed. A separate pinned Simple-System memory audit checks 12,290 legal LUT word addresses and the response-valid logic for the exact RAM/bus integration.

### 3.3 DE0-CV dynamic-input pilot

The new external-input firmware uses request protocol v2 and response protocol v3. The pilot evidence is the saved `physical_pilot_RUN4_complete_20261126` record: ten preselected engineering images, each run once in fixed Exit 2 and once adaptively, for 20 requests. The saved raw JTAG records and independent audit report response agreement with the CPU Q15 oracle and protocol identity checks. This supports only a limited integration statement: the tested build accepted those supplied pixel arrays and returned the expected oracle outputs under the recorded run conditions.

The pilot was not designed as a representative sample. Its ten images are excluded from the 3,813-image primary candidate set. It estimates neither external-dataset accuracy nor cycle superiority, cold-boot variability, or population-level noninferiority. Build identity and host SOF hash records do not constitute a bit-for-bit physical SOF readback. External USB-Blaster timing sign-off remains blocked.

### 3.4 Exploratory offline comparison of stopping rules

The new Q15 reanalysis used the frozen classifier and the existing scikit-learn handwritten-digit validation (359 images) and heldout (360 images) splits [4,11]. It recomputed all exits with an analysis-only helper; it did not alter weights, firmware, SOF, or physical measurements. Fixed Exit 2 and frozen entropy stopping are compared directly. Max-softmax and top-two-margin thresholds were selected on validation and are exploratory analysis-only rules, not deployed firmware. A label-informed first-correct-exit oracle is included only as an unattainable retrospective reference.

For paired accuracy, the report uses a 20,000-replicate image-level bootstrap with seed `20261128`. It treats image rows as resampling units and does not account for unknown writer clusters. Therefore these intervals are descriptive conditional intervals, not a writer-population guarantee. Optional-block counts are counts of neural blocks, not CPU cycles, wall time, energy, or deadline execution time.

### 3.5 Unrun external primary campaign

The UCI Optical Recognition of Handwritten Digits `optdigits.tra` primary campaign is not run [12]. The locked protocol specifies 3,813 candidate images × two modes in each of three planned sessions (22,878 requests total), with fixed Exit 2 versus adaptive execution at `budget_q16=65535` and `deadline_cycles=0`. Its H1 numerical gate is a one-sided paired Clopper–Pearson/Bonferroni lower bound for the accuracy difference exceeding −1 percentage point; its H2 gate requires a point reduction of at least 5% and a 10,000-replicate input-paired bootstrap 95% lower bound above 5%. Neither gate has been evaluated on new UCI primary results. A proposed one-session exploratory amendment exists separately and is not approved or applied. The prepared 7,626-row file is an offline schedule template for one image-pair session; it contains no physical results. No output from that template is used in the results below. UCI metadata states that the 30 writers contributing to the training side differ from the 13 writers contributing to the test side [12]. The tracked RTNN training and evaluation scripts use `sklearn.load_digits`, and the saved dataset audit verifies that this loader matches the UCI `optdigits.tes` pixel/label arrays [4,11,12]. This documents writer-pool separation between the tracked legacy data and the proposed `optdigits.tra` candidate; it does not rule out unrecorded prior use of `optdigits.tra`. The row-level writer IDs are not provided, so clustering within the 30-writer training pool cannot be estimated or used for cluster-aware intervals. The former preregistration timeline also cannot be independently anchored to the first model-output inspection. Thus prior-exposure and population-level confirmatory eligibility remain unresolved.

## 4. Results

### 4.1 Finite-class cycle binding on pinned Ibex RTL

| Maximum-work class | Measured RTL cycles |
|---:|---:|
| 0/6 | 29,620 |
| 1/6 | 615,569 |
| 2/6 | 1,201,521 |
| 3/6 | 1,787,473 |
| 4/6 | 2,373,425 |
| 5/6 | 2,959,377 |
| 6/6 | 2,959,381 |

Across the 21 fixed-class input/class cases, prediction mismatches against the native integer reference were zero, and within-class cycle range across the three tested inputs was zero. In 21 adaptive RTL cases, the recorded prediction and executed exit matched the reference and no unsafe admission or committed binding exceedance was reported. These are finite measurements for the specified exact binary and simulated Simple-System RTL. They are not DE0-CV FPGA cycles and do not establish a portable timing equation or WCET.

### 4.2 Frozen-Q15 offline stopping comparison

| Rule | Correct on heldout 360 | Accuracy | Mean optional blocks | Mean decision checks |
|---|---:|---:|---:|---:|
| Fixed Exit 2 | 339 | 94.17% | 2.000 | 0 |
| Frozen entropy | 339 | 94.17% | 1.358 | 2.339 |
| Validation-selected max-softmax | 338 | 93.89% | 1.253 | 2.242 |
| Validation-selected top-two margin | 337 | 93.61% | 1.225 | 2.219 |
| Retrospective first-correct-exit oracle | 344 | 95.56% | 0.750 | Not applicable |

Against fixed Exit 2, exploratory paired image-bootstrap 95% accuracy-difference intervals were −1.39 to +1.39 percentage points for entropy, −1.67 to +1.11 points for max-softmax, and −1.94 to +0.83 points for top-two margin. All include zero, and their lower bounds do not meet the one-point margin. These are not the locked primary H1 Clopper–Pearson/Bonferroni calculations. Entropy used 0.642 fewer optional blocks per image on average than fixed Exit 2 in this heldout set. Its number of wrong predictions exclusive of fixed Exit 2 was three, and fixed Exit 2 had three exclusive errors; both were wrong on 18 images and both correct on 336.

The frozen entropy rule exited at class 1 on 263 images, class 2 on 81, class 3 on 7, class 4 on 2, and class 5 on 7. Exit correctness was not monotonic: 12/360 images were correct at at least one earlier exit and wrong at a deeper exit. For adjacent transitions, error-to-correct/correct-to-error counts were 158/1 (0→1), 14/3 (1→2), 3/4 (2→3), 0/2 (3→4), 1/1 (4→5), and 0/3 (5→6). Exit 6 is diagnostic and exceeds the adaptive policy’s Exit-5 ceiling. These examples falsify a blanket assumption that deeper computation always improves an individual prediction. They do not establish a general causal explanation for the errors.

The threshold variants were selected after observing the validation split and were not deployed. The retrospective oracle uses the true label and is not implementable at inference. These comparisons are exploratory and use the legacy `load_digits` heldout set; they are not results on new UCI images.

### 4.3 Dynamic-input FPGA pilot

The saved DE0-CV RUN4 record contains 20/20 completed pilot requests and reports CPU-oracle agreement for all tested image/mode pairs. In the saved descriptive reaggregation, each mode classified 10/10 pilot images correctly against teacher labels; adaptive cycles were lower for eight images and higher for two. Fixed-Exit-2 and adaptive median cycles were 943,906 and 565,923, respectively; their means were 943,905.6 and 667,031.9. The ratio-of-sums descriptive reduction was 29.33%. These values describe only the selected ten-image pilot in one recorded power epoch. They are not an inferential estimate and do not support a general speed claim. They do not replace the unrun 3,813-image external primary campaign.

### 4.4 Historical C3 v2 FPGA campaign (separate build)

The earlier C3 v2 campaign is reported separately from the dynamic-input pilot and pinned-Ibex RTL measurements. It used Build/Binding ID `43334531`, SOF SHA-256 `85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d`, and ELF SHA-256 `9cbf537bd9440deaf5c78abf6b204da9cbcd2fe3795acf444d733dbd581002b6`. The archived campaign comprises 24,840 requests in 13 schedules; its primary portion contains 7,200 requests forming 3,600 fixed-Exit-2/adaptive pairs over 360 distinct `load_digits` inputs. The ten primary schedules are repeated measurements, not 3,600 new inputs per schedule.

In that exact-build dataset, fixed Exit 2 averaged 943,929.77 cycles and adaptive execution averaged 746,327.99 cycles, a descriptive difference of 197,601.77 cycles or 20.934% relative to fixed Exit 2. Adaptive used fewer cycles on 263 of 360 inputs and more on 97. An input-ID resampling analysis reported a conditional 95% interval of 16.804%–24.903% for the mean reduction. Both modes classified 339/360 inputs correctly; the paired accuracy-difference interval was −1.389 to +1.389 percentage points and does not establish the prespecified one-point noninferiority condition. The ten primary schedules had identical per-input/per-mode cycle counts, so those repeats do not estimate independent power-session variation.

This is an empirical result for a fixed comparator selected with prior test results known, at full budget `65535` and with no deadline. It does not establish general speed superiority, confirmatory population inference, calibrated elapsed time, WCET, or formal DE0-CV timing. The data are not pooled with the newer Build `45585631` pilot (SOF SHA-256 `5e333e9377b7188a394d04b93b98833d91afb2cd53eca8d976e6aa715dfa00c4`) or the pinned-Ibex RTL results. Source-level reports for the historical values and limitations are linked in the reproducibility map.

## 5. Discussion

The evidence establishes different things at different layers. The finite budget and execution-control properties are supported by bounded source-level proofs. The cycle table and control-flow analyses concern one exact RV32 artifact in one pinned simulated Ibex system. The DE0-CV pilot shows limited dynamic-input functional integration for one newer build. The offline Q15 comparison characterizes optional-block use and prediction behavior on a legacy heldout set. No single layer should be used to imply a result from another layer.

The exit-transition counterexamples matter to policy design: confidence or entropy-based stopping can save blocks on some inputs, but a shallower correct output can later become incorrect. A stopping rule must therefore be evaluated as a complete policy on heldout data, with its validation and selection procedure disclosed. The current margin and max-softmax rules are candidates for future controlled study, not supported replacements for the frozen entropy implementation.

The historical C3 v2 board campaign provides a bounded empirical comparison on its fixed 360-image set. Its quantitative results are stated separately above and are not pooled with the external-input pilot or pinned-Ibex RTL measurements. The old C3 v2 fixed2 comparator was not test-blind, independent cold boots were not verified, and board-level JTAG timing/CDC sign-off remained incomplete. Accordingly, it is an exact-build observation, not confirmatory population evidence.

## 6. Limitations and claim boundaries

The following statuses remain unresolved: `DATA_EXPOSURE_UNCERTAIN`, `WRITER_CLUSTER_UNKNOWN`, `PREREGISTRATION_TIMELINE_UNVERIFIED`, `COLD_BOOT_UNVERIFIED`, and `FORMAL_TIMING_SIGNOFF_BLOCKED`. In addition, the external UCI primary run is `NOT_RUN`. UCI documents writer-disjoint train/test pools, and the tracked `load_digits` arrays come from its test side; however, row-level writer IDs within `optdigits.tra` are unavailable and repository history cannot rule out every unrecorded prior use. The small engineering pilot is not representative. The 360-image bootstrap does not model writer clustering. The oscillator was not calibrated to support high-accuracy absolute time. External JTAG timing assumptions and complete board timing constraints are unavailable. The pinned Ibex measurements use a simulated processor system, not the DE0-CV implementation. None of these data establish hard deadline feasibility, silicon/FPGA WCET, energy efficiency, or a universal speed advantage.

The strongest defensible statement is that this repository contains a resource-conditioned same-model Q15 prototype, selected source-level control proofs, an exact-build measured RTL binding on pinned Ibex, a 20-request dynamic-input DE0-CV integration pilot, and an exploratory legacy-heldout analysis showing both reduced optional-block use and non-monotonic exit correctness. Accuracy noninferiority and external primary performance remain unestablished.

## 7. Conclusion

Resource-conditioned inference can enforce a finite maximum-work contract while permitting a frozen policy to stop earlier. In the analyzed implementation, control properties are supported within the stated formal abstractions, pinned-Ibex RTL has an exact-build finite cycle binding, and a separate DE0-CV pilot exercised a new dynamic input path. Offline exit analysis shows that entropy stopping used fewer optional blocks than fixed Exit 2 on average in a legacy heldout set, while also exposing later-exit regressions and inconclusive accuracy comparison. This evidence is useful for a bounded engineering case study. It does not establish external-dataset generalization, accuracy noninferiority, population-level speed superiority, physical WCET, or formal DE0-CV timing. The next empirical step is the separately approved and audited external primary campaign; it cannot be represented by the current offline schedule template.

## Reproducibility and evidence map

The Japanese final status, formal evidence map, Q15 stopping analysis, pilot run record, per-input CSVs, tests, and SHA manifests are stored beside this draft under `artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/final_research_verification_20261128/`. The historical C3 v2 values in Section 4.4 are supported by `artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/paper_20261117/generated_run1/analysis.json`, the archived per-schedule results and manifests in `artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/paper_20261117/generated_run1/`, and the detailed historical manuscript at `artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/paper_20261117/MANUSCRIPT_DRAFT_EN.md`. This integrated draft retains the literature scope but awaits final bibliographic and coauthor review before submission.

| Claim/evidence area | Repository evidence |
|---|---|
| Source-level CBMC and formal boundaries | `CLAIMS_AND_LIMITS.md`; `artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/final_research_verification_20261128/FORMAL_EVIDENCE_MAP_JA.md` |
| Pinned Ibex RTL cycle binding and exact binary analyses | `artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/final_research_verification_20261128/FORMAL_EVIDENCE_MAP_JA.md`; referenced `notes/realtime_nn_ibex_rtl_validation.md` and `results/realtime_nn_ibex_rtl_validation_results.json` |
| New-build DE0-CV pilot | `artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/external_validation_20261122/build/physical_pilot_RUN4_complete_20261126/`; `artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/final_research_verification_20261128/PILOT_DESCRIPTIVE_REANALYSIS.json` |
| Offline stopping comparison and non-monotonic-exit cases | `artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/final_research_verification_20261128/Q15_STOPPING_ANALYSIS_JA.md`; `q15_stopping_comparison_RUN8_20261128/`; `exit_counterexamples_RUN2_20261128/` |
| Historical C3 v2 empirical campaign (separate build) | `artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/paper_20261117/MANUSCRIPT_DRAFT_EN.md` and its linked campaign evidence |
| UCI external primary status | `artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/final_research_verification_20261128/FINAL_RESEARCH_STATUS_JA.md`; `primary_schedule_OFFLINE_TEMPLATE.metadata.json` |

### References

1. S. Teerapittayanon, B. McDanel, and H. T. Kung. “BranchyNet: Fast Inference via Early Exiting from Deep Neural Networks.” ICPR, 2016. [DOI](https://doi.org/10.1109/ICPR.2016.7900006).
2. G. Huang et al. “Multi-Scale Dense Networks for Resource Efficient Image Classification.” ICLR, 2018. [arXiv:1703.09844](https://arxiv.org/abs/1703.09844).
3. X. Wang et al. “SkipNet: Learning Dynamic Routing in Convolutional Networks.” ECCV, 2018. [arXiv:1711.09485](https://arxiv.org/abs/1711.09485).
4. F. Pedregosa et al. “Scikit-learn: Machine Learning in Python.” JMLR 12(85), 2011. [Paper](https://www.jmlr.org/papers/v12/pedregosa11a.html).
5. F. Ilhan et al. “Adaptive Deep Neural Network Inference Optimization with EENet.” WACV, 2024. [DOI](https://doi.org/10.1109/WACV57701.2024.00140).
6. M. Kong and J. L. Nunez-Yanez. “Entropy-Based Early-Exit in a FPGA-Based Low-Precision Neural Network.” Applied Reconfigurable Computing, 2022. [DOI](https://doi.org/10.1007/978-3-031-19983-7_6).
7. E. Y. L. Kwan and J. Nunez-Yanez. “Entropy-Driven Adaptive Filtering for High-Accuracy and Resource-Efficient FPGA-Based Neural Network Systems.” Electronics 9(11), 1765, 2020. [DOI](https://doi.org/10.3390/electronics9111765).
8. A. Dimitriou et al. “Realization of Early-Exit Dynamic Neural Networks on Reconfigurable Hardware.” IEEE TCAD 44(6), 2025. [DOI](https://doi.org/10.1109/TCAD.2024.3519055).
9. H. Pearce et al. “Designing Neural Networks for Real-Time Systems.” IEEE Embedded Systems Letters 13(3), 2021. [DOI](https://doi.org/10.1109/LES.2020.3009910).
10. W. Zhang et al. “WCET Estimation for CNN Inference on FPGA SoC With Multi-DPU Engines.” IEEE TPDS 36(6), 2025. [DOI](https://doi.org/10.1109/TPDS.2025.3555968).
11. Scikit-learn developers. “Optical recognition of handwritten digits dataset (`load_digits`).” [Dataset documentation](https://scikit-learn.org/stable/modules/generated/sklearn.datasets.load_digits.html); the loader describes a copy of the UCI test data.
12. E. Alpaydin and C. Kaynak. “Optical Recognition of Handwritten Digits.” UCI Machine Learning Repository, 1998. [DOI](https://doi.org/10.24432/C50P49); [CC BY 4.0](https://creativecommons.org/licenses/by/4.0/).

**Review status:** Integrated technical draft for review. It is not submission-ready until all internal artifact links, references, authorship, and interpretation are reviewed. No result in this manuscript substitutes for the unrun external primary campaign or blocked formal timing sign-off.
