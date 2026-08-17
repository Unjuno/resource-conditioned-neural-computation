# Q4 bare-metal static-link audit

## Question

After the Q4 core cross-compiles into helper-free embedded objects, can it be linked with a minimal startup/probe into a self-contained firmware-shaped ELF **without libc or CRT**?

This is a link/integration boundary only. The images are not executed on hardware in this environment.

## Build

Common flags:

```text
-O2 -std=c11 -ffreestanding -fno-builtin -nostdlib -fuse-ld=lld
-Wl,--gc-sections -Wl,--build-id=none
```

A minimal probe calls:

```text
rtnn_q4_i8_init()
rtnn_q4_i8_infer(..., execution_class=4)
```

then loops forever.

For Cortex-M, a two-entry minimal vector table provides an initial stack pointer and `Reset_Handler`. For RISC-V, a minimal `_start` is used. The audit linker scripts define 256 KiB FLASH and 16 KiB RAM only to check whether the test image fits a small embedded memory model; these are not claims about a particular board.

## Result

| target | static link | undefined symbols | binary image | BSS |
|---|---:|---:|---:|---:|
| Cortex-M0 | PASS | **0** | **89,000 B** | 4,048 B |
| Cortex-M4 soft-float | PASS | **0** | **88,840 B** | 4,048 B |
| RV32IM | PASS | **0** | **87,184 B** | 4,048 B |
| RV32I | **FAIL** | `__mulsi3` | — | — |

ELF SHA-256:

- Cortex-M0: `568bb44cbc69c55a3543c8c8a1c44b133a01d9f76e79d9f5bfd8405be6c56fb1`
- Cortex-M4 soft-float: `1fe4805b1849666552432f6bdcf8c0a42267b01b98358077410e0ef7f63db31f`
- RV32IM: `8bec5a81cf84625fb4e2ecbb9dadb6c1665506e7b4e06153155b5c5bb5ecb910`

The helper-free targets therefore move one step beyond “freestanding object” into a self-contained, statically linked firmware image shape.

## RV32I negative result

The RV32I link fails with LLD reporting unresolved `__mulsi3` references from the neural core. This independently confirms the prior object-level finding.

The consequence is concrete:

> a deployment timing certificate must cover not only the NN work-class manifest and exact object identity, but also any ISA-emulation/runtime helper pulled in by the selected target/compiler configuration.

For RV32I, one could supply a chosen `__mulsi3` implementation, but then that helper becomes part of the certified executable and its timing must be included. This experiment deliberately does not silently add such a runtime.

## Memory interpretation

The simple linked images fit inside the audit's 256 KiB FLASH / 16 KiB RAM model. That is useful for feasibility, but it is not a production memory guarantee:

- the vector/startup is minimal;
- no RTOS kernel or application code is present;
- production data/BSS initialization is not implemented here;
- target linker layout and flash wait states are not modeled;
- the reported flat binary size is build-specific.

## Current RTOS boundary

The Real-Time NN implementation path is now:

```text
budget-conditioned neural work classes
        ↓
Q4 int8 / int32 freestanding core
        ↓
embedded ISA capability audit
        ↓
nostdlib bare-metal static link
        ↓
NEXT: execute under a concrete target/RTOS and certify timing
```

The remaining missing evidence is no longer whether the neural core can be separated from Python/Linux or from libc. It is **target execution and a defensible timing/scheduling argument**.

## Nonclaims

This audit does not establish:

- successful boot on a physical Cortex-M or RISC-V device;
- correctness of production startup code;
- RTOS integration;
- target latency;
- WCET;
- interrupt/bus/cache/flash interference bounds.
