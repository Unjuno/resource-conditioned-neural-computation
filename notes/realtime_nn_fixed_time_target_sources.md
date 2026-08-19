# Timing-model source anchors

The conditional `RTNN-IBEX-DIT-v1` timing model is based on explicit Ibex architectural assumptions rather than Linux measurements.

Primary upstream references used for the model audit:

- Ibex **Pipeline Details**: two-stage default pipeline, maximum IPC 1, load/store stall behavior, jump/branch behavior, and multiplier stall table.
- Ibex **Instruction Decode and Execute**: `RV32MSingleCycle` completes MUL in one cycle and MULH in two cycles.
- Ibex RTL `ibex_id_stage.sv`: with `DataIndTiming`, all conditional branches take two cycles regardless of the branch condition.
- Ibex **Load-Store Unit**: every load/store stalls at least one cycle waiting for the memory response.
- Ibex **Core Integration**: `RV32M` selects the single-cycle multiplier implementation.

These upstream properties do not by themselves certify this repository's cycle table. The repository additionally assumes aligned zero-wait SRAM, no cache, interrupts, DMA, debug requests, bus contention, or memory errors. RTL/physical validation of the exact linked build remains required.
