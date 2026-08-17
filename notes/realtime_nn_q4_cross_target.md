# Q4 freestanding cross-target compile audit

## Question

The Q4 int8 Real-Time NN core is freestanding on the host compiler. Does the same source lower into self-contained embedded ISA objects, or are hidden runtime helpers reintroduced when the target changes?

This audit tests the **porting boundary**, not execution time and not RTOS deployment.

## Setup

Seed-0 Q4 generated parameters are compiled with Clang 17.0.0 using common flags:

```text
-O2 -std=c11 -ffreestanding -fno-builtin
```

Targets:

1. Cortex-M0: `armv6m-none-eabi`, `-mcpu=cortex-m0 -mthumb`
2. Cortex-M4 soft-float: `armv7em-none-eabi`, `-mcpu=cortex-m4 -mthumb -mfloat-abi=soft`
3. RV32IM: `riscv32-unknown-elf`, `-march=rv32im -mabi=ilp32`
4. RV32I negative control: same RISC-V target but `-march=rv32i`

Each target is compiled twice from identical generated input to audit object determinism in this environment.

## Result

| target | undefined externals | text bytes | float-pattern instructions | div/rem patterns | repeated object |
|---|---:|---:|---:|---:|---:|
| Cortex-M0 | **0** | 88,860 | 0 | 0 | byte-identical |
| Cortex-M4 soft-float | **0** | 88,682 | 0 | 0 | byte-identical |
| RV32IM | **0** | 87,056 | 0 | 0 | byte-identical |
| RV32I | **`__mulsi3`** | 87,212 | 0 | 0 | byte-identical |

SHA-256 of the repeated helper-free objects:

- Cortex-M0: `60f6726422dfcff1e9e41989a05c4c2225f8151767d3b01be89fe073472166bc`
- Cortex-M4 soft-float: `598e5152901f38c4d94b6b57ae99c3a23683327e0b12852042e00fda0df0fd8d`
- RV32IM: `99cbcc08ec5b712eb53a146bf9ffd40da9e76c18b3cd2c7215993b1bad4b9288`

## Negative boundary: multiplication is part of the target contract

The neural numeric path contains integer MACs. On RV32IM, the `M` extension supplies integer multiply and the object has no unresolved external symbols.

On RV32I, which omits the multiply extension, Clang lowers multiplication through:

```text
U __mulsi3
```

Therefore the current target-independent execution-class manifest is not sufficient by itself. The deployment contract must also state either:

- a native integer-multiply capability compatible with the certified build; or
- a specific multiply helper/runtime implementation whose code and timing are included in certification.

The same source does compile helper-free for Cortex-M0, despite the much smaller core, because its ISA includes the required integer multiply operation and the Q4 numeric path contains no division.

## What this establishes

It strengthens the RTOS integration boundary:

```text
finite neural work class
      ↓
freestanding integer core
      ↓
target ISA capability check
      ↓
exact deployed object identity
      ↓
target/RTOS timing certification
```

The compiler matrix already showed that timing evidence must be bound to a concrete deployed build. This experiment adds that the **ISA capability set itself is part of that build contract**.

## What it does not establish

The objects were not executed on Cortex-M or RISC-V hardware/emulation in this environment. Therefore this does not prove:

- target functional execution;
- RTOS integration or boot;
- target-specific latency;
- WCET;
- cache/bus/flash timing behavior;
- arbitrary compiler/toolchain portability.

The next true runtime milestone remains execution on a concrete controlled target with explicit scheduling and memory assumptions.
