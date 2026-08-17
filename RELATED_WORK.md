# Related work and novelty boundary

This repository does **not** claim that lookup-table (LUT) neurons, LUT-based neural networks, logic-gate networks, FPGA-oriented LUT synthesis, neural architecture search, dynamic routing, or runtime subnetwork switching are new.

## LUT / logic-network prior work

Several lines of prior work already establish LUT/logic computation as a neural representation or hardware implementation strategy:

1. **Deep Differentiable Logic Gate Networks** — Petersen et al. (2022), arXiv:2210.08277.  
   Learns differentiable relaxations of logic-gate networks and discretizes them for fast inference.  
   https://arxiv.org/abs/2210.08277

2. **Differentiable Weightless Neural Networks (DWN)** — Bacellar et al., ICML 2024.  
   Builds trainable networks from interconnected lookup tables and evaluates them in edge/FPGA/microcontroller settings.  
   https://proceedings.mlr.press/v235/bacellar24a.html

3. **NeuraLUT: Hiding Neural Network Density in Boolean Synthesizable Functions** — Andronic & Constantinides, FPL 2024 / arXiv:2403.00849.  
   Maps entire neural sub-networks into Boolean LUT functions instead of enforcing a one-neuron/one-LUT boundary.  
   https://arxiv.org/abs/2403.00849

4. **LL-ViT: Edge Deployable Vision Transformers with Look Up Table Neurons** — Nag et al. (2025), arXiv:2511.00812.  
   Integrates learned LUT-neuron layers into the channel-mixer portion of a Vision Transformer for edge deployment.  
   https://arxiv.org/abs/2511.00812

5. **Fully Trainable Deep Differentiable Logic Gate Networks and Lookup Table Networks** — Mommen et al. (2026), arXiv:2607.09399.  
   Jointly trains gate/LUT contents and connection choices, and includes a trainable LUT-neuron formulation for deep LUT networks.  
   https://arxiv.org/abs/2607.09399

## Dynamic routing / architecture-search prior work

The new topology-search follow-up also overlaps conceptually with established dynamic-routing and hardware-aware NAS work. The repository therefore does **not** claim novelty for learning subgraphs, specializing subnetworks for hardware constraints, or switching among subnetworks at runtime.

Representative work includes:

6. **Deciding How to Decide: Dynamic Routing in Artificial Neural Networks** — McGill & Perona, ICML 2017.  
   Trains dynamically routed graphs of learned transformations and studies conditional paths under computational budgets.  
   https://proceedings.mlr.press/v70/mcgill17a.html

7. **Adaptive Neural Trees** — Tanno et al., ICML 2019.  
   Learns routing and adaptively grows neural-tree architectures from primitive modules.  
   https://proceedings.mlr.press/v97/tanno19a.html

8. **Once for All: Train One Network and Specialize it for Efficient Deployment** — Cai et al., ICLR 2020.  
   Trains one network supporting a very large family of depth/width/kernel/resolution subnetworks and specializes a subnetwork for a target hardware constraint without retraining.  
   https://openreview.net/forum?id=HylxE1HKwS

9. **Dynamic-OFA: Runtime DNN Architecture Switching for Performance Scaling on Heterogeneous Embedded Platforms** — Lou et al., CVPR Workshops 2021.  
   Uses a runtime manager to switch among pre-sampled OFA subnetworks as runtime hardware resources and performance requirements change.  
   https://openaccess.thecvf.com/content/CVPR2021W/ECV/html/Lou_Dynamic-OFA_Runtime_DNN_Architecture_Switching_for_Performance_Scaling_on_Heterogeneous_CVPRW_2021_paper.html

10. **HADAS: Hardware-Aware Dynamic Neural Architecture Search for Edge Performance Scaling** — Bouzidi et al. (2022), arXiv:2212.03354.  
    Jointly searches a dynamic-network backbone, early-exit behavior, and hardware/DVFS settings for edge resource efficiency.  
    https://arxiv.org/abs/2212.03354

These works make an important boundary explicit: **topology search, conditional routing, once-for-all subnetworks, and runtime architecture switching are established ideas.**

## What this repository is testing instead

The lookup path in this repository is a deliberately simple constructive example. The narrow question is not:

> Can a neural network be implemented with LUTs?

Nor is the narrow question:

> Can a supernet contain many candidate subnetworks or can a runtime select among them?

Both are already well established by prior work.

The narrower systems/mechanism question tested here is:

> Can a fixed neural system consume an explicit normalized resource-price/control signal so that its actually executed internal computation changes with current resource scarcity, while an independent runtime availability mask can restrict which execution classes are admissible?

Earlier experiments use a small hand-enumerated set of execution strategies. The topology-search follow-up relaxes that part only partially: it supplies a three-stage supernet of primitive `skip`, `lookup`, and `compute` operations, but does not supply complete route labels. The learned router then selects per-stage operations as a function of resource price.

That follow-up should be described as **resource-conditioned subgraph discovery inside a supplied search space**, not unconstrained neural architecture discovery.

## Important boundary

The current experiments do **not** show that this routing mechanism improves DWN, NeuraLUT, LL-ViT, OFA, Dynamic-OFA, HADAS, Adaptive Neural Trees, or other dynamic/NAS systems.

The topology-search result is also not globally resource-optimal across all seeds and is not robust on the harder parity stress test. It therefore does not establish a generally superior NAS method.

If prior work already demonstrates the same combination of:

1. an explicit normalized continuous resource-price/control contract supplied to the model,
2. resource-conditioned internal execution/subgraph selection inside a fixed neural system, and
3. an independent runtime safety/availability mask that can override that choice,

please open a critique/prior-art issue.
