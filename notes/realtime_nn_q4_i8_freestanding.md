# Q4 int8 freestanding Real-Time NN core

## Question

Can the same finite budget-conditioned execution classes be implemented with a substantially smaller, simpler integer representation while preserving the tested model decisions?

The target is the Real-Time NN chain, not quantization novelty:

```text
runtime-admitted finite work class
        ↓
physically bounded NN computation
        ↓
target/compiler/RTOS timing certification later
```

## Precision boundary

A single global fixed-point scale is used for both model values and activations.

Seed 0 gives a direct negative boundary:

- Q2: full-depth accuracy **83.40%**;
- Q3: depth-6 accuracy **85.16%**, full-depth accuracy **98.63%**;
- **Q4: all predictions at every 0/2/4/6/8-block class match float**.

Q4 was then repeated for seeds 0, 1 and 2. All **15 seed/class combinations** preserve the corresponding float prediction over the complete 512-state task domain.

This is **decision equivalence on the tested finite domain**, not numeric equivalence. In particular, Q4 represents the residual coefficient `0.2` as `3/16 = 0.1875`, and logits need not match the float model.

## Integer representation

The selected backend uses:

- global Q4 (`scale = 16`);
- `int8_t` weights and biases;
- `int8_t` hidden state and activation LUT outputs;
- `int32_t` MAC accumulators and residual temporaries;
- two 257-point int8 LUTs over `[-8,8]`;
- one caller-owned fixed workspace;
- five runtime execution classes corresponding to `0/2/4/6/8` blocks.

The Q4 grid spacing is `1/16`. A 257-point LUT over `[-8,8]` has exactly the same spacing, so every integer Q4 activation input lands directly on a LUT index. Runtime interpolation is unnecessary.

## Storage

| item | float freestanding | existing Q5 int16 | Q4 int8 |
|---|---:|---:|---:|
| weight payload | 335,368 B | 167,684 B | **83,842 B** |
| activation LUTs | 2,056 B | 1,028 B | **514 B** |
| caller workspace | 8,064 B | 4,032 B | **3,776 B** |

Q4 therefore reduces weight/LUT storage by **75% versus float** and by **50% versus the existing Q5 int16 backend**. Code size is separate.

The GCC `-O2` seed-0 object is 86,826 bytes of reported text versus 170,974 bytes for the existing Q5 object on the same host toolchain family. This is a build-specific size comparison, not a target-independent ROM figure.

## Static int32 MAC bound

No int64 MAC accumulator is needed.

The storage format itself bounds every int8 weight and int8 activation by absolute value 128. The largest linear layer has 128 input terms, so the conservative raw accumulator bound is

```text
128 terms × 128 × 128 = 2,097,152
```

which is far below signed int32 maximum `2,147,483,647`.

The core contains compile-time assertions for this bound and for the residual multiply path.

The numeric path uses shifts for Q4 rescaling and direct LUT indexing. GCC and Clang `-O2` builds show no `div/idiv` instructions in the core object.

## Freestanding audit

For all three independently trained seeds, freshly generated headers were compiled with:

```bash
gcc -O2 -std=c11 -ffreestanding -fno-builtin -fstack-usage -c ...
```

Checks:

- `nm -u` is empty in 3/3 GCC builds;
- all five class accuracies match float in 3/3 seeds;
- invalid execution-class values fail closed to class 0;
- medians remain strictly ordered by work class in 3/3 host runs;
- seed 0 also passes the same functional test with Clang `-O2`;
- project-local GCC stack report is at most 72 bytes in this build because large scratch arrays are caller-owned.

## Host timing boundary

A short alternating seed-0 audit against the existing Q5 core found Q4 median central latency similar to or slightly lower for nonzero classes in that run. This is not promoted as a portable speedup: ordinary Linux timing varies, and different targets may favor different integer widths/instructions.

The important result is that integerization preserves the **ordered finite work classes**; a target-specific timing bound still has to be attached later.

## Interpretation

The implementation boundary is now:

```text
trained fixed parameter set
   ↓ export
int8 Q4 static parameters + 514-B LUTs
   ↓
3,776-B caller-owned workspace
   ↓
int32 bounded MAC loops
   ↓
finite 0/2/4/6/8-block execution classes
```

This is more suitable for embedded/RTOS integration than the float backend, but it is not a WCET result and does not establish that Q4 is sufficient for other neural networks.
