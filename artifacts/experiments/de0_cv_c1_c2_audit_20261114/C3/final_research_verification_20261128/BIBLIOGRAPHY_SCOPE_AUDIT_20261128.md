# Bibliography and related-work scope audit — 2026-11-28

## Purpose and method

This is a source-level audit of the references used to characterize adaptive inference and the UCI Optdigits dataset in `MANUSCRIPT_EN_DRAFT_20261128B.md`. It does not establish novelty, exhaustively review the literature, or change any experimental result. Publisher, conference, institutional, or dataset-provider records were preferred. Accessed 2026-11-28.

## Findings

| Ref. | Source checked | Supported bibliographic/scope point | Manuscript action |
|---|---|---|---|
| [1] | IEEE Xplore, `https://ieeexplore.ieee.org/abstract/document/7900006/authors` | BranchyNet is a multi-branch deep-network method that lets sufficiently confident test samples exit early; the record lists Teerapittayanon, McDanel, and Kung and ICPR 2016. | Retained as early-exit prior art. |
| [2] | `https://arxiv.org/abs/1703.09844` | MSDNet is a multi-scale dense network for resource-efficient image classification. | Retained as related adaptive/resource-efficient network work; no novelty claim is attached to it. |
| [3] | Springer ECCV 2018 proceedings, `https://link.springer.com/book/10.1007/978-3-030-01261-8` | Proceedings list SkipNet: Learning Dynamic Routing in Convolutional Networks. | Retained as dynamic-routing prior art. |
| [5] | CVF WACV 2024 open-access proceedings, `https://openaccess.thecvf.com/content/WACV2024/papers/Ilhan_Adaptive_Deep_Neural_Network_Inference_Optimization_With_EENet_WACV_2024_paper.pdf` | EENet optimizes a multi-exit scheduling policy under an average per-sample inference budget. | Retained as budgeted early-exit/scheduling prior art. |
| [6] | Author institutional postprint, `https://liu.diva-portal.org/smash/get/diva2%3A1709087/FULLTEXT02.pdf`; DOI `10.1007/978-3-031-19983-7_6` | Kong and Núñez-Yáñez study entropy-based early exit in a quantized low-precision FPGA neural network. | Retained as directly related FPGA early-exit work. |
| [7] | Publisher article, `https://www.mdpi.com/2079-9292/9/11/1765`; related-work discussion in `https://www.mdpi.com/2079-9292/10/20/2551` | Kwan and Núñez-Yáñez adapt the processing rate of FPGA-based video frames using entropy. The source describes frame-rate adaptation, not selecting an exit separately within one image inference. | Corrected the draft to identify [7] as system-level/frame-processing context and explicitly distinguish it from sample-wise early exit. |
| [8] | DOI `10.1109/TCAD.2024.3519055`; institutional record `https://eprints.soton.ac.uk/499024/` | The cited work concerns realization of early-exit dynamic neural networks on reconfigurable hardware. | Retained as FPGA/reconfigurable-hardware implementation prior art. |
| [11] | Scikit-learn API documentation, `https://scikit-learn.org/stable/modules/generated/sklearn.datasets.load_digits.html` | `load_digits` is documented as a copy of the UCI test dataset. | The manuscript keeps legacy `load_digits` analyses separate from `optdigits.tra`; it does not count them as external-primary images. |
| [12] | UCI dataset record, `https://doi.org/10.24432/C50P49` | UCI describes 3,823 training-side and 1,797 test-side samples, 64 integer features in 0–16, and 30 training writers disjoint from 13 test writers. | The manuscript limits this to pool-level provenance. It preserves `WRITER_CLUSTER_UNKNOWN` because row-level writer IDs are absent. |

## Scope correction

The wording in the manuscript now separates (i) early exits, budgeted inference, and dynamic routing [1–5], (ii) entropy-based early exit for a quantized FPGA network [6], (iii) entropy-driven adaptive video-frame processing [7], and (iv) reconfigurable-hardware early-exit realization [8]. The correction narrows the description of [7]; it does not change the prototype's novelty status or support a “first” claim.

## Limits

This check verifies the cited sources and the specific scope distinction above. It is not a systematic review. It does not show that the manuscript has cited every relevant method, validate all claims in each cited paper, resolve authorship, or establish novelty. The dataset-provider writer split is between the published train/test pools; it does not provide per-row writer labels for `optdigits.tra` and does not clear unrecorded prior use of those images.

## Reproduction

The source links above are stable citation targets. The manuscript edit is in `MANUSCRIPT_EN_DRAFT_20261128B.md`. No dataset, model, SOF, ELF, physical record, or frozen schedule was changed for this audit.
