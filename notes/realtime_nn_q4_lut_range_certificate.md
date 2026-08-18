# Finite-domain Q4 LUT-range certificate

## Question

The Q4 deployment core uses direct integer activation LUTs over the Q4 index domain `[-128, 128]`.

The prior branchless audit removed data-dependent C branches from rounding/clamp helpers, but a compiler can still lower the clamp arithmetic into target-dependent branches. Can the clamp be removed completely **only when the generated weights prove it is unreachable**?

This is a model-specific finite-domain deployment certificate, not a general neural range theorem.

## Why exhaustive certification is possible here

The public inference API accepts a `uint16_t`, but this toy network reads only bits 0..8:

```c
for (int p = 0; p < RTNN_L; ++p) {
    int bit = (state >> p) & 1;
    ...
}
```

Therefore every 16-bit API input aliases one of exactly:

```text
2^9 = 512
```

effective neural input states.

A host regression additionally compares every low-9-bit state against the same value with all upper seven bits set and obtains identical logits for all five execution classes.

So, for this specific core, exhaustive enumeration of 512 states covers the complete distinguishable input domain.

## Build-time certificate

`export_realtime_nn_q4_certified_header.py`:

1. trains/loads the selected toy seed using the same Q4 export path;
2. quantizes the model to the deployed int8 Q4 representation;
3. runs the Q4 integer recurrence over all 512 effective states;
4. records every pre-LUT integer value for:
   - first tanh in each block;
   - GELU in each block;
   - residual tanh in each block;
5. rejects the export if any reachable value is outside `[-128, 128]`;
6. emits the certified min/max values into the same generated header as the weights/LUTs.

The certified core refuses to compile without the certificate macros and statically checks those recorded bounds against the LUT domain.

Generated headers remain build artifacts and should still be bound to the deployed binary identity by the existing execution-contract mechanism. Manually changing generated weights after certification invalidates the certificate.

## Certified ranges

Across the three tested training seeds:

| seed | tanh pre | GELU pre | residual tanh pre |
|---:|---:|---:|---:|
| 0 | `[-75, 75]` | `[-55, 61]` | `[-66, 69]` |
| 1 | `[-71, 70]` | `[-62, 62]` | `[-74, 66]` |
| 2 | `[-69, 65]` | `[-112, 90]` | `[-64, 67]` |

All are inside `[-128, 128]`.

The closest observed bound is seed-2 GELU at `-112`, still 16 integer Q4 steps inside the lower LUT endpoint.

## Functional equivalence

Three implementations were compared over all 512 states and all five execution classes:

1. current production Q4 core with branchy clamp/rounding;
2. branchless clamp/rounding audit variant;
3. branchless rounding + **no runtime clamp**, protected by the build-time certificate.

For seeds 0/1/2, all three produce identical class accuracies and identical aggregate integer-logit checksums.

The class accuracies remain:

```text
63.671875% / 71.484375% / 78.515625% / 86.328125% / 100%
```

## Fail-closed negative test

To test that the certificate is weight-specific rather than decorative, the seed-0 quantized block-0 `ff1` bias was artificially changed to the legal int8 value `127`.

The exhaustive certificate detects:

```text
GELU pre range = [-55, 154]
```

and rejects the deployment before C compilation.

Thus an int8-valid parameter set is not automatically considered LUT-safe.

## Cross-target machine-code effect

Clang 17 `-O2 -ffreestanding -fno-builtin` conditional branch sites:

| target | production clamped | branchless clamp | certified direct |
|---|---:|---:|---:|
| Cortex-M0 | 69 | 59 | **19** |
| Cortex-M4 soft-float | 39 | **18** | **18** |
| RV32IM | 40 | 33 | **27** |

This exposes an important compiler boundary: source-level branchless clamp arithmetic was lowered back into conditional branches on Cortex-M0/RV32IM. Removing the clamp operation entirely avoids that lowering.

All certified objects remain helper-free on Cortex-M0, Cortex-M4 soft-float, and RV32IM.

## Bare-metal link boundary

The certified direct core was linked with the same `-nostdlib`/LLD audit harness and 256-KiB FLASH / 16-KiB RAM model used by the existing Q4 bare-metal audit:

- Cortex-M0: PASS, zero undefined symbols;
- Cortex-M4 soft-float: PASS, zero undefined symbols;
- RV32IM: PASS, zero undefined symbols;
- RV32I: still FAILS on `__mulsi3`.

The prior ISA capability boundary is therefore unchanged.

## Host timing — secondary evidence only

A seed-0 alternating host run (3 runs/variant, 1200 timed inferences/class/run) gives median-of-P50 values:

| class | branchless clamp | certified direct |
|---:|---:|---:|
| 0 | 0.201 us | 0.201 us |
| 1 | 18.86 us | **15.93 us** |
| 2 | 37.61 us | **31.63 us** |
| 3 | 56.36 us | **47.35 us** |
| 4 | 75.07 us | **63.10 us** |

This is consistent with removing per-activation clamp arithmetic, but it is ordinary-host timing and must **not** be treated as a portable embedded speedup or WCET result.

## Interpretation

The timing/analyzability chain can now be narrowed further:

```text
finite effective input domain
        ↓
build-time Q4 range certificate tied to generated weights
        ↓
no runtime LUT clamp
        ↓
less input-dependent / target-dependent numeric control flow
        ↓
target/compiler/RTOS timing certification
```

This is especially relevant to a Real-Time NN because the runtime should not pay unpredictable defensive work when the exact deployed neural artifact can prove that work is unreachable.

## Limits

The certificate is valid only because this toy has a finite, exhaustively enumerable effective input domain. It does not establish:

- a range proof for arbitrary continuous inputs;
- general neural interval analysis;
- constant cycles;
- WCET;
- hardware execution;
- RTOS scheduling guarantees.

For larger or continuous-input networks, analogous clamp removal would require a different sound range-analysis method rather than exhaustive enumeration.
