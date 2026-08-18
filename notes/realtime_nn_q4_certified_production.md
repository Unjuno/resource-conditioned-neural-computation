# Certified Q4 production path

## Change

The Q4 deployment candidate now treats the finite-domain LUT-range certificate as a **required build artifact**, not an optional audit.

The ordinary production command remains:

```bash
python experiments/export_realtime_nn_q4_i8_header.py --seed 0 \
  --out /tmp/realtime_nn_q4_i8_generated.h
```

but that exporter now delegates to the exhaustive finite-domain certificate before emitting the generated header.

The production C core requires the resulting certificate macros at compile time. A legacy/non-certified header is rejected rather than silently falling back to unchecked direct indexing.

## Runtime consequence

For certified generated weights, the production numeric path uses:

- Q4 int8 weights/hidden/LUT storage;
- int32 MAC accumulation;
- branch-reduced signed Q4 rounding;
- direct activation-LUT indexing with **no runtime clamp**;
- the same finite runtime work classes.

Correct linear-MAC class totals are:

| class | blocks | linear MACs | LUT calls |
|---:|---:|---:|---:|
| 0 | 0 | 64 | 0 |
| 1 | 2 | 182,336 | 3,456 |
| 2 | 4 | 364,608 | 6,912 |
| 3 | 6 | 546,880 | 10,368 |
| 4 | 8 | 729,152 | 13,824 |

## Production regression

The ordinary exporter was rerun independently for seeds 0, 1, and 2.

All three generated headers contain the range certificate, and the production core preserves the previous all-512-state outputs at every execution class.

Class accuracies remain:

```text
63.671875% / 71.484375% / 78.515625% / 86.328125% / 100%
```

Aggregate integer-logit checksums:

- seed 0: `131328 / -12928 / 2288 / 500 / -12769`;
- seed 1: `-80128 / 36160 / 31216 / 28272 / 33649`;
- seed 2: `8704 / 2624 / -2016 / 5104 / 14721`.

All three host freestanding objects have zero undefined external symbols.

## Fail closed on a missing certificate

A generated header was deliberately stripped of `RTNN_Q_LUT_RANGE_CERTIFIED` and all `RTNN_Q_CERT_*` macros.

The production core then fails compilation with the explicit certificate requirement.

Therefore the runtime cannot accidentally deploy the unchecked direct-index path merely because a legacy exporter/header was used.

## Embedded build boundary

With the certified production path and Clang 17 `-O2 -ffreestanding -fno-builtin`:

| target | conditional branch sites | text bytes | undefined symbols |
|---|---:|---:|---:|
| Cortex-M0 | 19 | 88,408 | 0 |
| Cortex-M4 soft-float | 18 | 88,534 | 0 |
| RV32IM | 27 | 86,928 | 0 |

The same `-nostdlib` bare-metal audit remains helper-free for Cortex-M0, Cortex-M4 soft-float, and RV32IM. RV32I still fails on `__mulsi3`; that ISA capability boundary is unchanged.

## Historical audit reproducibility

Changing the production core would otherwise make the earlier branchless/clamp experiments impossible to reproduce. The pre-certificate clamped core is therefore retained as:

`experiments/realtime_nn_q4_i8_clamped_reference_core.c`

It is an **audit fixture**, not the deployment candidate.

The branchless and finite-domain certificate audit scripts are pinned to this historical source when they need the old production baseline.

## Why this is relevant to Real-Time NN

This change moves defensive numeric work from inference time into the deployment pipeline:

```text
fixed trained artifact
      ↓
exhaustive finite-domain range certificate
      ↓
certificate-bound generated Q4 header
      ↓
smaller / less data-dependent production numeric path
      ↓
target/compiler/RTOS timing certification
```

For this toy, the build system can prove a defensive clamp is unreachable and reject artifacts for which that proof is false.

## Limits

This is still **not** a hard-real-time result.

The finite-domain certificate is possible because the deployed toy consumes only nine effective input bits. Larger or continuous-input systems require another sound range-analysis method.

Still open:

- actual target execution;
- RTOS scheduling/interference control;
- per-build timing certificates or WCET bounds;
- generalization of range certification beyond exhaustive finite domains.
