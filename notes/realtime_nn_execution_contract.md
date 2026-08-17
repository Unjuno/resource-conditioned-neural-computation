# Target-independent RTNN execution contract and target timing binding

## Question

Now that the Real-Time NN has finite physical execution classes with exact work counts, how should an RTOS use them **without confusing target-independent neural work with target-specific execution time**?

The intended split is:

```text
static NN execution-class manifest
        +
target/compiler/RTOS timing certification
        ↓
remaining deadline
        ↓
highest explicitly certified class that fits
        ↓
freestanding NN core
```

The experiment deliberately does **not** put Linux P95/P99 values into the static manifest.

## Target-independent manifest

The committed manifest records only properties of the neural implementation:

- five finite classes (`0/2/4/6/8` blocks);
- exact physically executed linear MACs;
- activation-LUT calls;
- residual multiply/shift operations;
- linear output counts;
- model/LUT/workspace storage;
- finite-domain quality for this toy.

It explicitly stores:

```json
"target_timing_bounds": null
```

Canonical JSON SHA-256 for the tested manifest is:

```text
c497a83885b3c2912c6b589dfded58f6fe0230cd83395df37f81ae6743f248d5
```

The small embedded C interface uses the first 64 bits as a manifest fingerprint. This is an integration guard, not a cryptographic security protocol.

## Target binding

`RTNNTargetTimingBinding` contains:

- the expected manifest fingerprint;
- runtime overhead in target-defined ticks;
- one explicit upper-bound value per execution class.

`UINT32_MAX` means:

> this class has **no defensible timing bound in this target configuration**.

The runtime is forbidden from inferring a missing time bound from MAC count, adjacent classes, Linux timing, or a different machine.

The admission function returns the highest class whose explicit certified bound fits the remaining deadline after runtime overhead. It returns `-1` if:

- the binding is null;
- the manifest fingerprint is wrong;
- the deadline is smaller than runtime overhead;
- no explicitly bounded class fits.

## Property test

Three synthetic timing bindings were used only to exercise the interface:

1. a synthetic fast target;
2. a synthetic slower target;
3. a partial-certification target where only classes 0 and 1 have timing bounds.

For each binding, **100,000 random deadlines** were tested in C.

Across 300,000 random cases:

- the selected class always fits its explicit bound;
- it is always the highest explicitly certified class that fits;
- uncertified classes are never admitted, even for arbitrarily large deadlines;
- a wrong manifest fingerprint is rejected;
- a null binding is rejected.

The contract object itself compiles with:

```bash
gcc -O2 -std=c11 -ffreestanding -fno-builtin -c \
  experiments/realtime_nn_execution_contract.c -o contract.o
```

and `nm -u contract.o` is empty.

## Why the partial-certification test matters

Suppose classes 0 and 1 have target-specific bounds, while classes 2–4 do not.

Even if the static manifest knows that class 4 executes 729,152 linear MACs, and even if the caller supplies a very large deadline, the runtime still refuses to admit classes 2–4.

This enforces a systems boundary:

> **known neural work is not the same thing as known execution time.**

The target-specific timing argument must be attached explicitly.

## Synthetic bindings are not evidence

The example bound arrays in the host test are arbitrary values chosen to exercise deadline transitions. They are not measurements, WCET estimates, or evidence that the same timing relationship transfers between hardware platforms.

The real future binding must identify a concrete:

- processor/accelerator;
- compiler and flags;
- memory/cache assumptions;
- RTOS scheduling policy and task priority;
- interrupt/interference assumptions;
- timing-analysis method.

Only then should the `upper_ticks[]` array be populated.

## Interpretation

This experiment closes an interface-design gap:

```text
NN side:
  finite physical work classes
  exact static work/resource metadata

RTOS/target side:
  explicit timing certification for some/all classes

admission:
  deadline -> highest certified class that fits
```

It does **not** close the remaining real-time proof gap. The most important next experiment remains a concrete target binding with defensible timing bounds.

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
```
