# CBMC verification of the RTNN finite runtime contract

## H

For the finite RTNN runtime boundary, the continuous Q0.16 budget lowering, deadline admission, partial-certification fail-closed behavior, effective execution ceiling, and Q15 LUT index safety can be checked bit-precisely over their complete integer domains rather than by sampled tests.

## T

CBMC 6.10.0 is run on Ubuntu 24.04. The proof harness is `experiments/realtime_nn_cbmc_runtime_contract.c` and directly links the repository's deployed deadline-admission implementation:

- `experiments/realtime_nn_real_sequence_fixed_timing_contract.c`
- `experiments/realtime_nn_real_sequence_fixed_timing_contract.h`

The timing values used by the proof are the pinned-Ibex RTL measured admission+adaptive binding:

`29,843 / 657,454 / 1,285,058 / 1,912,662 / 2,540,266 / 3,167,870 / 3,167,870 cycles`.

The external compute coordinate remains Q0.16 lowering of continuous `b in [0,1]`; finite class selection is an implementation/certification boundary, not a claim of continuous machine instructions.

### Proof 1: continuous budget lowering

For arbitrary `uint16_t b0,b1` with `b0 <= b1`, prove:

- lowered class is always in `0..6`;
- lowering is monotone;
- `class/6 <= b/65535`, checked by exact cross multiplication;
- the next finite class does not fit, so the selected class is greatest-fit.

### Proof 2: actual deadline admission

For arbitrary `uint32_t deadline`, call the real `rtnn_fixed_admit_total_cycles()` implementation and prove:

- wrong model ID fails closed;
- wrong build ID fails closed;
- null binding fails closed;
- admitted class is in `0..6`;
- its bound is `<= deadline`;
- no larger finite class also fits;
- if admission returns `-1`, class zero does not fit.

### Proof 3: arbitrary partial certification

For an arbitrary seven-entry `uint32_t` timing table, arbitrary deadline, and arbitrary probe class `k in 0..6`, prove:

- no admission implies arbitrary certified `k` does not fit;
- an admitted class is not `UINT32_MAX` (the invalid/un-certified marker);
- an admitted class fits the deadline;
- arbitrary higher certified `k` cannot also fit.

The symbolic probe class is universal over the finite class index while avoiding an unnecessary second assertion loop.

### Proof 4: effective execution

For every Q0.16 budget, every 32-bit deadline, and every preferred exit `0..5`, prove that effective execution never exceeds:

- budget ceiling;
- deadline-admitted ceiling;
- preferred compute;
- deployed policy maximum.

If admission succeeds, also prove that the committed RTL timing binding of the executed class is no larger than the admitted binding and remains within the deadline.

### Proof 5: Q15 LUT index safety

For arbitrary signed 32-bit inputs to the exact post-clamp exp/GELU index arithmetic, prove:

- exp interpolation high index is at most 8192 for `fx_exp_lut[8193]`;
- GELU interpolation high index is at most 4096 for `fx_gelu_lut[4097]`;
- CBMC's signed-overflow instrumentation finds no reachable overflow in the clamp-to-index subtraction.

All bounded loops use unwinding assertions. Bounds, pointer, signed-overflow, and divide-by-zero checks are enabled.

## D

**PASS_WITH_SCOPE.**

Workflow run `32221590675`, job `95972930266`, CBMC 6.10.0:

- continuous budget lowering: `VERIFICATION SUCCESSFUL`;
- actual deadline admission: `VERIFICATION SUCCESSFUL`;
- arbitrary partial certification: `VERIFICATION SUCCESSFUL`;
- effective execution safety: `VERIFICATION SUCCESSFUL`;
- Q15 LUT index bounds: `VERIFICATION SUCCESSFUL`.

The evidence artifact is `9354096082`, ZIP SHA-256 `0010ff32c270dcaef429631a9c0b90d3bd71b4b85b02db0ec52163fb46a4722b`.

## C

This closes a different gap from the pinned RTL experiment and the exact-binary taint audit:

```text
pinned RTL measurement
    -> target/build timing evidence
exact-RV32 taint audit
    -> fixed-class neural input does not reach branch/indirect control
CBMC
    -> finite software admission/cap/LUT contract holds for complete integer domains
```

The three evidence sources are complementary. CBMC does not make the custom taint interpreter formally verified, and the RTL measurement does not become a silicon WCET theorem.

## U

Remaining uncertainty is concentrated above and below the proved software contract:

1. The complete neural arithmetic implementation is not model-checked by CBMC.
2. The budget lowering formula is represented exactly in the proof harness, but the full generated-weight neural core is not linked into CBMC.
3. Compiler preservation of all source-level noninterference properties is not proved; the separate exact-RV32 binary taint audit addresses the compiled artifact empirically/structurally.
4. The Ibex RTL pipeline and memory implementation are measured under one pinned configuration, not formally proved here.
5. FPGA/ASIC/silicon WCET remains outside this software-only proof.

The appropriate next software-only target is therefore a stronger mechanically checkable statement about the exact compiled RV32 fixed-class control flow, rather than more Linux timing samples or more neural router tuning.
