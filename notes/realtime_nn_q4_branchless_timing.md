# Q4 branchless timing-predictability audit

## Question

The Q4 core already has finite budget classes, fixed-size loops, no libc/libm dependency, and helper-free objects on Cortex-M0, Cortex-M4 soft-float, and RV32IM. However, two hot helper operations still branch on **neural activation values**:

- signed Q4 rounding (`x >= 0`);
- LUT domain clamp (`x <= lo`, `x >= hi`).

Can these data-dependent branches be removed without changing the neural function?

This is a timing-analyzability audit. It is not a cycle or WCET result.

## Variant

`realtime_nn_q4_i8_branchless_core.c` keeps the model, weights, execution classes, loops, and LUTs unchanged. It replaces only:

1. signed Q4 rounding with a two's-complement magnitude/mask implementation;
2. LUT lower/upper clamp with mask-based integer selection.

The remaining conditional control flow is associated with finite loop structure, the known right-boundary position, and the runtime-selected execution class rather than activation sign or LUT saturation state at the C source level.

## Functional result

For seeds 0, 1, and 2, original and branchless cores were separately compiled against the same generated Q4 header and evaluated over all 512 states at all five execution classes.

- **3/3 seeds:** class accuracies match;
- **3/3 seeds:** aggregate integer logit checksums match exactly at every class.

The tested class accuracies remain:

`63.671875% / 71.484375% / 78.515625% / 86.328125% / 100%`.

Thus the branchless transformation did not alter tested finite-domain outputs.

## Cross-target compiled branch sites

Clang 17 `-O2 -ffreestanding -fno-builtin`:

| target | original conditional branch sites | branchless | reduction | original text | branchless text |
|---|---:|---:|---:|---:|---:|
| Cortex-M0 | 69 | **59** | 10 (14.5%) | 88,784 B | 88,500 B |
| Cortex-M4 soft-float | 39 | **18** | 21 (53.8%) | 88,604 B | 88,332 B |
| RV32IM | 40 | **33** | 7 (17.5%) | 86,984 B | 86,960 B |

Both variants remain **0 undefined symbols** on all three targets.

The exact static branch-site count is compiler/version/optimization dependent. A lower site count does not itself prove a lower WCET.

## Interpretation

This removes a concrete source of activation-dependent control flow while preserving the finite neural function in the exhaustive toy domain.

It strengthens the implementation direction:

```text
runtime-admitted finite work class
        ↓
fixed Q4 integer neural loops
        ↓
less activation-dependent control flow
        ↓
target-specific timing analysis
```

The remaining timing problem is still target-specific. Flash wait states, pipeline behavior, branch cost, bus contention, interrupts, RTOS scheduling, and compiler lowering must be included in any defensible timing certificate.

## Important contemporaneous correction

The audit also exposed an independent work-manifest accounting bug in the current Q4 core: the right-boundary neighbor matvec is skipped, so the exact block count is **91,136 linear MACs**, not 92,160. That correction was isolated and merged separately before this branchless audit.

Correct execution-class MAC totals are:

- 0 blocks: 64;
- 2 blocks: 182,336;
- 4 blocks: 364,608;
- 6 blocks: 546,880;
- 8 blocks: 729,152.

## Nonclaims

This audit does not establish:

- constant cycle count;
- branch-free machine code overall;
- WCET;
- hardware execution;
- RTOS integration;
- universal behavior across compilers or optimization settings.
