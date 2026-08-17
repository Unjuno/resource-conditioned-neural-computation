# Related work and novelty boundary

This repository does **not** claim that lookup-table (LUT) neurons, LUT-based neural networks, logic-gate networks, or FPGA-oriented LUT synthesis are new.

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

## What this repository is testing instead

The lookup path in this repository is a deliberately simple constructive example. The narrow question is not:

> Can a neural network be implemented with LUTs?

That is already well established by the work above.

The narrow question tested here is:

> Given two or more already-valid execution strategies with different resource profiles, can a fixed-parameter neural system use an explicit resource-price signal to choose among them, while an independent runtime availability mask restricts the selectable execution classes?

In the current toy experiment, the two strategies are:

- a lookup/copy path with high parameter-footprint proxy and low compute proxy;
- an algorithmic MLP path with lower parameter-footprint proxy and higher compute proxy.

The contribution under test is therefore **resource-conditioned selection between execution regimes**, not the invention of LUT neurons or LUT networks.

## Important boundary

The current experiments do **not** show that this routing mechanism improves DWN, NeuraLUT, LL-ViT, differentiable logic networks, or other LUT-based models. Those architectures are better viewed as plausible future execution regimes that a resource-conditioned runtime/model interface could choose among.

If prior work already demonstrates the same combination of:

1. multiple functionally valid but resource-distinct neural execution regimes,
2. an explicit continuous resource-price/control signal used by the model to choose among them, and
3. an independent runtime safety/availability mask that can override that choice,

please open a critique/prior-art issue.