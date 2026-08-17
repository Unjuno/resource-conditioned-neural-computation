# Target-independent RTNN execution contract and target timing binding

## Question

How should an RTOS use finite Real-Time NN work classes without confusing:

1. target-independent neural work;
2. the exact deployed binary/build;
3. target-specific execution-time certification?

The contract now treats these as three distinct layers.

```text
neural execution-class manifest
        ↓
certified deployed build identity
        ↓
target/compiler/RTOS timing bounds
        ↓
remaining deadline
        ↓
highest explicitly certified class that fits
```

Linux P95/P99 values are deliberately absent from the static manifest.

## 1. Target-independent manifest

`results/realtime_nn_execution_class_manifest.json` records only neural implementation properties:

- five finite classes (`0/2/4/6/8` blocks);
- exact physical linear MACs;
- activation-LUT calls;
- residual multiply/shift operations;
- linear-output counts;
- model/LUT/workspace storage;
- finite-domain quality for this toy.

It explicitly contains:

```json
"target_timing_bounds": null
```

Canonical manifest SHA-256:

```text
c497a83885b3c2912c6b589dfded58f6fe0230cd83395df37f81ae6743f248d5
```

The embedded interface uses the first 64 bits as an integration fingerprint. This is a mismatch guard, not a cryptographic-security protocol.

## 2. Certified build identity

A compiler-matrix audit later showed that the same source/manifest and identical finite-domain outputs can compile into different machine-code objects under different compilers and optimization flags.

Therefore manifest identity alone is insufficient for timing certification.

`RTNNTargetTimingBinding` now also contains:

```c
uint64_t certified_build_id;
```

and admission receives the deployed build ID. A mismatch returns `-1`.

A production `build_id` could come from a signed certification package, linked-image digest, compiler/toolchain configuration digest, or another auditable deployment identity. The important invariant is that timing evidence cannot silently survive a machine-code-changing rebuild.

See `notes/realtime_nn_compiler_bound_timing.md`.

## 3. Target-specific timing binding

The binding additionally contains:

- runtime overhead in target-defined `uint32` ticks;
- one explicit upper bound per execution class.

`UINT32_MAX` means:

> this execution class has no defensible timing bound in this target/build configuration.

The runtime must not infer a missing bound from MAC count, neighboring classes, Linux timing, or a different machine/build.

Admission returns the highest class whose certified upper bound fits the remaining deadline after runtime overhead. It returns `-1` when:

- the binding is null;
- manifest identity mismatches;
- deployed build identity mismatches;
- runtime overhead already exceeds the deadline;
- no explicitly certified class fits.

## Property test

Three synthetic timing bindings exercise the interface only:

1. synthetic fast build/target;
2. synthetic slower build/target;
3. partial certification where only classes 0 and 1 are bounded.

For each matching binding, **100,000 random deadlines** are tested in C.

Across 300,000 random cases:

- admitted class always fits its explicit bound;
- admitted class is always the highest explicitly certified fitting class;
- uncertified classes are never admitted even for very large deadlines;
- wrong manifest ID rejects;
- wrong build ID rejects;
- null binding rejects.

The contract object itself remains freestanding with zero unresolved external symbols.

## Why partial certification matters

Even if class 4 has a known static work count of 729,152 linear MACs, a target binding that only certifies classes 0 and 1 will **never** admit classes 2–4.

This enforces:

> **known neural work is not known execution time.**

## Why build identity matters

The compiler audit gives the complementary rule:

> **known neural manifest is not known machine code.**

Both identity checks are therefore required before a target timing table is accepted.

## Synthetic bindings are not timing evidence

The example `upper_ticks[]` arrays are arbitrary test values. They are not measurements or WCET estimates.

A real certification should identify at least:

- processor/accelerator;
- generated weights/LUTs and NN source revision;
- compiler and optimization/configuration;
- linked/deployed build identity;
- memory/cache assumptions;
- RTOS scheduling policy and task priority;
- interrupt/interference assumptions;
- timing-analysis method.

Only then should target timing upper bounds be populated.

## Reproduce

```bash
gcc -O2 -std=c11 -ffreestanding -fno-builtin \
  -c experiments/realtime_nn_execution_contract.c -o /tmp/rtnn_contract.o
nm -u /tmp/rtnn_contract.o

gcc -O2 -std=c11 -Iexperiments \
  experiments/realtime_nn_execution_contract_test.c /tmp/rtnn_contract.o \
  -o /tmp/rtnn_contract_test
/tmp/rtnn_contract_test
```

Expected output includes:

```text
property_deadlines_per_binding=100000
all_admission_properties_pass=1
uncertified_classes_never_admitted=1
wrong_manifest_rejected=1
wrong_build_id_rejected=1
```

## Current boundary

This closes the **interface** path from deadline to certified finite work class. It does not provide the actual timing certification. A concrete target/RTOS with defensible per-class upper bounds remains the primary missing real-time experiment.
