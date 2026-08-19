# CBMC proof of the deployed RTNN control functions

## H

The source-level control behavior that enforces RTNN physical work caps can be proved on the actual deployed C function bodies, without duplicating those bodies in a separate verification model.

## T

`experiments/build_realtime_nn_cbmc_actual_control.py` mechanically extracts these functions from `experiments/realtime_nn_real_sequence_fixed_core.c`:

- `rtnn_fixed_budget_ceiling_q16`
- `rtnn_fixed_infer_budget`
- `rtnn_fixed_certify_class`

For reference workflow run `32222225890`, the extracted source identity is:

- deployed core SHA-256: `a6b2807bd4a60534c250fca3005322cf14ba0a92f6b16e28241109385efc6809`
- budget lowering function SHA-256: `dbcbc27c4e4c0e931797520e8ff33dd2ce2d65c7765e92bab9c0802a80a61744`
- adaptive inference function SHA-256: `9d9e7d5a8a5b4697d883bd6d720d610e4e6a50a0761123622b128bef63afe1ee`
- certification function SHA-256: `fc9a33dc6c5be141188c8a959c1a960d7be1bcbae37ccdb5451098bfe174a330`
- generated proof source SHA-256: `e2754972e14484a0f93648021e96446598c44be2118f7350802c9394c80dc679`

The neural numerical kernels are replaced by stubs because this proof is about control and physical optional-block calls. `entropy10()` returns an arbitrary nondeterministic signed value, so the adaptive proof includes every possible continue/stop sequence that the real entropy computation could produce. `run_block()` is instrumented to count physical optional-block calls and flag any non-canonical block order.

CBMC 6.10.0 is run with bounds, pointer, signed-overflow, and divide-by-zero checks. Adaptive and certification loops use unwinding assertions.

### Proof 1 — actual continuous-budget lowering

For all ordered `uint16_t` Q0.16 budget pairs, the extracted deployed `rtnn_fixed_budget_ceiling_q16()` body is proved to:

- return only classes `0..6`;
- be monotone in budget;
- lower fail-closed, so the selected finite fraction does not exceed the continuous admitted budget;
- return the greatest finite class that fits.

### Proof 2 — actual adaptive physical-work cap

For every `uint16_t` budget, every `uint8_t` deadline-class input, and every possible entropy continue/stop sequence, the extracted deployed `rtnn_fixed_infer_budget()` body is proved to:

- call optional blocks only in canonical nested order;
- never call `run_block()` beyond `min(budget ceiling, normalized deadline ceiling, policy max exit)`;
- report `executed` equal to the physical `run_block()` call count;
- never report an executed exit beyond the continuous-budget lowering;
- fail closed to zero optional blocks when the deadline class input is invalid (`>6`).

A second proof passes `executed == NULL` and verifies that the same physical cap and canonical order remain intact.

### Proof 3 — actual fixed-class certification work

For every possible `uint8_t` class input, the extracted deployed `rtnn_fixed_certify_class()` body is proved to:

- normalize invalid `class > 6` to class zero;
- apply the deployed policy maximum exit 5;
- call `run_block()` exactly the resulting normalized class count;
- execute blocks in canonical nested order.

## D

**PASS_WITH_SCOPE.**

Reference workflow run `32222225890`, job `95974722074`:

- actual budget lowering: `VERIFICATION SUCCESSFUL`;
- actual adaptive physical-call cap: `VERIFICATION SUCCESSFUL`;
- NULL executed-output path: `VERIFICATION SUCCESSFUL`;
- actual certification work count: `VERIFICATION SUCCESSFUL`.

Evidence artifact ID: `9354292298`.
Artifact ZIP SHA-256: `730f84744beea15c0d29108e676d8acdb5fbb8f0ceeb39a788c91950ffd8a2c0`.

## C

This removes an important modeling gap from the finite runtime-contract proof. The deadline-admission implementation is already linked directly into CBMC; this experiment mechanically extracts the deployed neural-control bodies themselves.

The software evidence hierarchy now is:

```text
actual deadline admission C
    -> directly linked into CBMC
actual budget/adaptive/certification control C
    -> exact function bodies mechanically extracted into CBMC
exact compiled RV32 fixed-class control flow
    -> custom taint audit + independent third-party BINSEC
neural numerical kernels
    -> abstracted for this source-control proof
pinned Ibex RTL
    -> measured timing binding
```

The result supports the structural claim that, regardless of how the input-dependent stopping decision behaves, the deployed source control cannot physically execute more optional blocks than the admitted ceilings allow.

The independent BINSEC result on the same exact RTL-tested RV32 ELF already strengthens the compiled fixed-class control-flow side: all seven finite classes complete as secure with no control-flow leak site. Its generic relational memory analysis hits a runner resource boundary once LUT-heavy class-1 memory accesses are included, so the remaining software/target gap is now concentrated on the timing treatment of the four input-indexed exp/GELU LUT load sites rather than on hidden fixed-class branching.

## U

This proof does not establish:

1. correctness or overflow-freedom of the complete neural numerical kernels;
2. equivalence between every source-level C operation and the exact compiled RV32 machine code;
3. generic constant-time behavior for input-indexed LUT accesses on arbitrary memory hierarchies;
4. a formal all-input timing theorem for the Ibex RTL;
5. FPGA/ASIC/silicon WCET.

The next software-side target is therefore the **memory/timing-model gap**: prove or explicitly bind the four input-indexed LUT accesses to the deterministic on-chip RAM model selected for certification.
