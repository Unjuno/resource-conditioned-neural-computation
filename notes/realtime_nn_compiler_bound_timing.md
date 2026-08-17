# Compiler/build identity as part of RTNN timing certification

## Question

The target-independent execution manifest identifies the neural work classes, but is that identity sufficient to reuse a timing certification after recompiling the same source with another compiler or optimization level?

No. The experiment shows that **functional identity and work-manifest identity do not imply machine-code identity**.

## Compiler matrix

The bounded-numeric, division-free Q5 core was compiled on x86_64 with:

- GCC 14.2.0;
- Clang 17.0.0;
- `-O0`, `-O1`, `-O2`, `-O3`, and `-Os`;
- `-ffreestanding -fno-builtin -fno-stack-protector`.

That gives ten builds of the same source, same generated seed-0 weights, same activation LUTs, and same target-independent RTNN manifest.

A host regression hashes both integer logits for **all 5 execution classes × all 512 task states**.

## Functional result

All ten builds produce the same output hash:

```text
b825970f0350e016
```

All ten also have:

- zero unresolved external symbols in the core object;
- zero `div`/`idiv` instructions.

Therefore the previous functional/analyzability invariants survive the compiler matrix.

## Machine-code result

Despite identical functional output, **all ten object SHA-256 values are different**.

Across the ten builds:

- object `.text` ranges from **170,005 B to 173,895 B**;
- whole-core conditional-jump counts range from **13 to 24**;
- project-local maximum stack-usage reports range from **136 B to 280 B**.

These diagnostics are compiler/ISA specific. They are not execution-time bounds. Their role is simply to falsify the assumption that a timing certification can be attached only to the neural work manifest.

## Contract consequence

The first RTNN admission contract checked only:

```text
binding.manifest_id == deployed_manifest_id
```

That is insufficient. A binary rebuilt with another compiler/flags can have the same manifest but different machine code.

The contract is therefore strengthened to require both:

```text
manifest identity
AND
certified build identity
```

`RTNNTargetTimingBinding` now contains `certified_build_id`, and admission also receives the deployed build ID. If they differ, admission returns `-1` and no neural class is executed through that binding.

The build ID is intentionally described as a **certification/build-system identifier**, not necessarily a raw object hash. A production build system could bind certification to a signed package manifest, linked-image digest, compiler/toolchain configuration digest, or another auditable deployment identity. What matters is that a timing table cannot silently survive a machine-code-changing rebuild.

## Updated property test

The synthetic admission property test now also checks:

> a timing table certified for build A must be rejected when the runtime reports deployed build B, even when the neural manifest is identical.

The original 300,000 random-deadline tests still pass for matching build IDs, while the mismatched-build case rejects.

## Why this matters for Real-Time NN

The work contract and timing contract now have three distinct layers:

```text
1. neural manifest
   exact physical work/resource metadata

2. certified deployed build
   compiler / flags / generated assets / binary identity

3. target timing binding
   upper execution-time bounds under explicit RTOS/hardware assumptions
```

Conflating these layers would make stale timing evidence possible.

## What this supports

- compiler/optimization settings materially change the compiled RTNN object even when all finite-domain outputs are identical;
- timing certification should be attached to a certified deployed build identity in addition to the target-independent neural manifest;
- fail-closed admission can enforce that identity check.

## What this does not support

- a WCET value for any of the ten host builds;
- that object size or branch count predicts execution time;
- compiler-independent timing;
- cross-ISA portability of a timing table.

The next real-time milestone is still a concrete target/RTOS binding with defensible per-class timing bounds.
