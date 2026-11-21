# RTNN prior-art comparison (reviewed 2026-11-21)

## Scope and method

This is a targeted falsification-oriented comparison, not a claim that every related paper has been found. The comparison uses the paper records and full-text/author versions linked below. It separates a mechanism's existence from the specific board, processor, model, and measurement protocol used here.

## Primary-source comparison

| Work | Mechanism / system evidenced by the source | Relation to RTNN | Verdict for the candidate RTNN claim |
|---|---|---|---|
| BranchyNet, Teerapittayanon, McDanel, Kung (ICPR 2016), DOI 10.1109/ICPR.2016.7900006 | Intermediate classifiers permit high-confidence examples to exit before later layers. | Establishes the general multi-exit early-stopping mechanism. | `ALREADY_KNOWN`: early exit itself is not new. |
| MSDNet, Huang et al. (ICLR 2018), arXiv:1703.09844 | One multi-exit model supports anytime prediction and budgeted batch classification; computation is allocated unevenly among examples. | Directly overlaps same-model, budget-aware multi-exit execution. Its CNN training/architecture differs from the frozen Q15 implementation. | `ALREADY_KNOWN`: one model serving several resource levels is not a new concept. |
| SkipNet, Wang et al. (ECCV 2018), arXiv:1711.09485; DOI 10.1007/978-3-030-01261-8_25 | A learned gate dynamically skips residual blocks per input. | Establishes input-dependent execution paths, although it skips blocks instead of selecting RTNN exits. | `ALREADY_KNOWN`: input-dependent computation is prior art. |
| EENet, Ilhan et al. (WACV 2024), DOI 10.1109/WACV57701.2024.00140 | Learns an early-exit scheduler to optimize accuracy while meeting a per-sample average inference budget. | Directly covers budget-conditioned exit scheduling; method and neural architectures differ. | `ALREADY_KNOWN`: converting available budget into an exit policy is not new. |
| Kong and Nunez-Yanez, “Entropy-Based Early-Exit in a FPGA-Based Low-Precision Neural Network” (Applied Reconfigurable Computing 2022), DOI 10.1007/978-3-031-19983-7_6 | Entropy selects early-exit branches in a fully quantized low-complexity FPGA SoC; the paper reports measured speed/accuracy tradeoffs. | Very close to entropy-based early exit with low-precision FPGA inference. Their hardware/network differ from Ibex/Q15 on Cyclone V DE0-CV. | `ALREADY_KNOWN`: entropy-based early exit on FPGA/low precision is prior art. |
| Kwan and Nunez-Yanez, “Entropy-Driven Adaptive Filtering…” (*Electronics* 2020), DOI 10.3390/electronics9111765 | Entropy from FPGA network outputs controls an adaptive processing rate in a CPU+FPGA video classifier. | Entropy-driven FPGA system adaptation is established, though this adapts frame-processing rate rather than RTNN's per-image exit. | `ALREADY_KNOWN` for entropy-guided system adaptation; not the same control target. |
| Dimitriou et al., “Realization of Early-Exit Dynamic Neural Networks on Reconfigurable Hardware” (*IEEE TCAD* 2025), DOI 10.1109/TCAD.2024.3519055 | Implements and evaluates dynamic early-exit networks on FPGA; compares pipeline and parallel classifier designs on ZCU106. | Establishes FPGA realization and empirical accelerator evaluation before this case study. Architecture and board differ. | `ALREADY_KNOWN`: FPGA-based dynamic early exit and physical performance evaluation are not new. |
| Pearce et al., “Designing Neural Networks for Real-Time Systems” (*IEEE ESL* 2021), DOI 10.1109/LES.2020.3009910 | Converts a neural controller into analyzable C and derives WCET on time-predictable Patmos. | Provides a materially different formal timing pipeline. RTNN reports measured cycles and lacks the full board/JTAG signoff. | `ALREADY_KNOWN` for the general connection of neural inference and formal timing; RTNN does not meet this level. |
| Zhang et al., “WCET Estimation for CNN Inference on FPGA SoC With Multi-DPU Engines” (*IEEE TPDS* 2025), DOI 10.1109/TPDS.2025.3555968 | Static timing analysis models shared-bus arbitration and memory contention for FPGA CNN accelerators. | Shows FPGA CNN execution bounds are an active, specific line of work. It does not establish RTNN's external JTAG timing. | `ALREADY_KNOWN` for FPGA CNN WCET analysis; RTNN's empirical cycles are not a WCET result. |

## Comparison against the requested dimensions

| Dimension | Prior-art status | RTNN evidence | Assessment |
|---|---|---|---|
| Same weights across execution choices | Same-model/multi-exit resource adaptation is present in MSDNet and multi-exit systems. | Frozen Q15 weights are used in fixed and adaptive modes. | Useful implementation property, not a supported novelty claim. |
| Continuous budget to finite maximum-work classes | Budget-aware exit policies are established; finite implementation details vary. | Q0.16 requests map to seven exit ceilings, with actual early termination separated from admission. | Could be a concrete implementation detail; novelty is `NOVELTY_UNCERTAIN` without a broader mechanism comparison. |
| Maximum-work cap vs actual early stop | Multi-exit and budgeted work literature already separates allowed/available computation from the chosen path in substance. | The RTL/firmware records both admitted and executed exits and checks cap violations. | Strong auditability detail, not a new algorithmic principle. |
| Input-dependent execution | BranchyNet, SkipNet, MSDNet, EENet and FPGA papers establish it. | Input entropy affects RTNN's exit. | `ALREADY_KNOWN`. |
| Software/binary/RTL validation | Prior papers differ in toolchains and often focus on custom accelerators. | The mapped 146-source native graph and regression were reproduced from public branch commit `6e07b86` in a fresh clone; pinned Ibex is an external dependency. Historical SOF/ELF bit identity was not rebuilt. | `INCREMENTAL_CONTRIBUTION`; native simulation reproducibility is established for the mapped graph, while physical binary reproducibility remains unestablished. |
| Physical cycle measurement | Earlier FPGA dynamic-inference papers report physical FPGA performance. | Request-level Ibex `mcycle` is recorded for 24,840 stored requests, with a 7,200-row primary pairing. | `INCREMENTAL_CONTRIBUTION` as a specific low-cost softcore platform case study, not first FPGA measurement. |
| Formal deadline/WCET guarantee | Time-predictable ANN and FPGA-DPU WCET papers demonstrate methods for deriving bounds. | External onboard JTAG timing remains unconstrained; D102 CDC findings remain; no WCET analysis exists. | `NOT_ESTABLISHED`; no deadline claim. |
| Third-party reproducibility | Prior works provide varied artifacts. | A fresh public-branch clone plus pinned external Ibex reproduced all 146 mapped source hashes and passed native Verilator regressions; the historical Quartus/SOF/ELF chain was not independently rebuilt. | `PASS` for the mapped native graph and simulation; `BLOCKED` for bit-identical physical-build reproduction. |

## Candidate contribution statement

Defensible wording: “We provide an artifact-linked empirical case study of a frozen Q15 multi-exit classifier running on an Ibex RV32 softcore in one Cyclone V DE0-CV build. The case study records JTAG request/result identity and FPGA `mcycle` intervals and audits a 24,840-request archive, while separating observed cycle differences from incomplete source and timing signoff.”

Do not write “first,” “novel early-exit algorithm,” “first entropy-based FPGA early exit,” “general speedup,” “accuracy noninferiority established,” or “hard real-time/WCET guarantee.”

## Sources

1. [BranchyNet / IEEE DOI](https://doi.org/10.1109/ICPR.2016.7900006)
2. [MSDNet / arXiv:1703.09844](https://arxiv.org/abs/1703.09844)
3. [SkipNet / arXiv:1711.09485](https://arxiv.org/abs/1711.09485) and [ECCV 2018 author-version paper](https://openaccess.thecvf.com/content_ECCV_2018/html/Xin_Wang_SkipNet_Learning_Dynamic_ECCV_2018_paper.html)
4. [EENet / WACV 2024 paper](https://openaccess.thecvf.com/content/WACV2024/papers/Ilhan_Adaptive_Deep_Neural_Network_Inference_Optimization_With_EENet_WACV_2024_paper.pdf)
5. [Entropy-Based Early-Exit / DOI](https://doi.org/10.1007/978-3-031-19983-7_6) and [Linköping University postprint](https://liu.diva-portal.org/smash/get/diva2%3A1709087/FULLTEXT02.pdf)
6. [Entropy-Driven Adaptive Filtering / journal article](https://www.mdpi.com/2079-9292/9/11/1765)
7. [FPGA early-exit dynamic networks / University of Southampton record and accepted manuscript](https://eprints.soton.ac.uk/499024/)
8. [Designing Neural Networks for Real-Time Systems / arXiv:2008.11830](https://arxiv.org/abs/2008.11830)
9. [CNN WCET on FPGA SoC / City University of Hong Kong record](https://scholars.cityu.edu.hk/en/publications/wcet-estimation-for-cnn-inference-on-fpga-soc-with-multi-dpu-engi/)

The publication versions, title/author metadata, dates, and identifiers above were checked against the linked primary publisher, conference, arXiv, or institutional repository pages on 2026-11-21. This targeted review does not prove that no other related work exists.
