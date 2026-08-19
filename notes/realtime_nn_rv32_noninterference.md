# Exact RV32 binary input/control-flow noninterference audit

## H

For the exact Q15 RV32 machine image already used in the pinned Ibex RTL experiment, fixing the admitted execution class removes neural-input dependence from the machine-code control-flow trace. Any remaining input-dependent memory addresses are confined to bounded LUT reads whose latency is address-independent in the pinned Simple System RAM.

This is narrower than a WCET theorem: the goal is to close the specific uncertainty that unseen neural inputs might activate hidden machine-code branches or indirect control flow inside a fixed maximum-work class.

## T

The audit operates on the exact RTL evidence artifact:

- ELF SHA-256: `234a7f46cf227a11f5d97f3c778cbb0c4ed4f7067f8994bcca86c4b08ff4e742`
- loadable binary SHA-256: `266ecb70c723b2164f6fe9039f27d4cb49c4d7271d4aca0cf69f2692cdfdf7a1`
- `rtnn_fixed_certify_class` entry: `0x1018f4`
- pinned Ibex RTL commit remains `7b5df75a041affe56e8c235260f98a09b3319008`

A custom RV32IM interpreter marks all 64 neural input bytes as tainted and propagates that taint through register and memory operations. It reports any tainted value that reaches:

1. a conditional branch condition;
2. an indirect jump target;
3. a load/store address.

The interpreter refuses a changed artifact when expected hashes are supplied. Its instruction semantics are cross-checked against the native integer reference on six embedded held-out vector/class cases, and a synthetic negative control contains a known branch on a tainted input byte to verify that the detector does fire.

The exp/GELU LUT indexing domains are additionally exhaustively enumerated over every integer value in their post-clamp Q15 domains.

The adaptive `rtnn_fixed_infer_budget` path is audited separately because its entropy early-stop branch is intentionally input-dependent.

## D

**PASS_WITH_SCOPE.**

### Fixed-class certification path

Across all seven finite classes:

- input-dependent conditional branch events: **0**;
- input-dependent indirect-control events: **0**;
- input-dependent store-address sites: **0**;
- hardware DIV/REM instructions on the fixed-class certification path: **0**.

Instruction-model steps for classes `0..6` are:

`21,754 / 472,942 / 924,129 / 1,375,316 / 1,826,503 / 2,277,690 / 2,277,691`.

The class-6 one-instruction difference reflects the deployed maximum-exit clamp logic; it does not execute a sixth neural block.

### Remaining input-dependent memory addresses

Exactly four machine-code load sites receive input-tainted addresses:

- `0x1002ec`
- `0x1002f0`
- `0x10152c`
- `0x101530`

They are the interpolated exp/GELU LUT reads. There are no input-tainted stores.

This does **not** establish address-independent timing for an arbitrary memory hierarchy. It is compatible with the pinned Ibex Simple System experiment because that target uses deterministic address-independent RAM response and no cache. A cache, external SDRAM, arbitration, or another memory implementation requires a new timing argument.

### LUT range audit

The complete post-clamp integer domains were enumerated:

- exp LUT length `8193`: every selected index is in `0..8192`;
- GELU LUT length `4097`: every selected index is in `0..4096`.

Thus the input-dependent LUT addressing remains inside the finite allocated tables for every post-clamp integer Q15 value.

### Interpreter cross-check

Six exact embedded held-out vector/class cases were re-executed in the custom interpreter and compared with the native integer host reference:

- prediction mismatches: **0/6**.

The synthetic tainted-branch negative control is detected: **PASS**.

### Adaptive path

For the three embedded held-out inputs whose preferred exits are `1`, `3`, and `5`:

- executed exits reproduced exactly: `1 / 3 / 5`;
- all input-dependent conditional-control events occur at one unique machine-code site: **`0x101848`**;
- that site is the entropy early-stop decision;
- input-dependent indirect-control events: **0**;
- input-dependent store-address sites: **0**.

The adaptive wrapper executes one hardware `DIVU` for continuous-Q16 budget lowering. The budget is a public runtime control rather than neural-input data. In the pinned Ibex configuration `SecureIbex=1` enables data-independent timing behavior; the exact pinned `ibex_multdiv_slow.sv` also disables divide early completion in data-independent timing mode. The fixed-class certification path itself contains no hardware divide.

## C

The previous three-input RTL zero-cycle-range observation is now supported by a machine-code structural explanation: for a fixed class, the audited exact binary has no detected neural-input-dependent branch or indirect-control target. The only input-dependent addresses are bounded LUT loads, and the pinned target's RAM response is address-independent.

This substantially narrows the remaining production timing problem. It does **not** turn the measured RTL table into a universal WCET theorem because the custom taint interpreter is not mechanically verified, the adaptive path intentionally varies with stopping, and physical memory/FPGA implementation assumptions remain target-specific.

## U

- The taint interpreter itself is custom software and is not formally verified.
- This is a noninterference/control-flow audit of the exact binary, not an exhaustive symbolic proof of all numerical values.
- LUT address timing relies on the pinned target's deterministic memory semantics.
- FPGA/ASIC/silicon timing, interrupts, DMA, contention, caches, or external memory are not covered.

## Reproduction

The exact ELF/bin/host reference come from the retained pinned-Ibex RTL evidence artifact identified in `results/realtime_nn_ibex_rtl_validation_results.json`.

Run:

```bash
python experiments/audit_realtime_nn_rv32_noninterference.py \
  --elf /path/to/rtnn_ibex_rtl.elf \
  --bin /path/to/rtnn_ibex_rtl.bin \
  --expected-elf-sha 234a7f46cf227a11f5d97f3c778cbb0c4ed4f7067f8994bcca86c4b08ff4e742 \
  --expected-bin-sha 266ecb70c723b2164f6fe9039f27d4cb49c4d7271d4aca0cf69f2692cdfdf7a1 \
  --host-csv /path/to/host.csv \
  --out results/realtime_nn_rv32_noninterference_results.json
```
