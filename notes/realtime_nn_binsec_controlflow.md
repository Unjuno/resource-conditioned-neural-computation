# BINSEC cross-check of fixed-class RTNN control-flow noninterference

## H

For the exact RV32 ELF already used in the pinned Ibex RTL timing experiment, neural input does not influence machine-code control flow when the maximum execution class is fixed.

This experiment is intentionally narrower than generic constant-time analysis. The deployed Q15 kernels contain input-indexed exp/GELU LUT reads. Under the pinned Simple System target those addresses have deterministic address-independent RAM latency, but generic constant-time tools correctly regard secret-dependent memory addresses as a separate leakage property.

## T

The audit uses third-party BINSEC directly on the exact retained RTL-tested ELF:

- ELF SHA-256: `234a7f46cf227a11f5d97f3c778cbb0c4ed4f7067f8994bcca86c4b08ff4e742`
- binary SHA-256: `266ecb70c723b2164f6fe9039f27d4cb49c4d7271d4aca0cf69f2692cdfdf7a1`
- `rtnn_fixed_certify_class` entry: `0x1018f4`
- all 64 neural input bytes are marked secret
- return address, stack/workspace/output addresses, and finite class are public/concrete
- BINSEC Docker image pinned to `sha256:2a51e455f055874d71cbf030a778e8be19455876bcd57c1845c163fed6fc482f`
- BINSEC version: `dfe4739`

The final all-class run uses:

```text
-sse -checkct
-checkct-features control-flow
-checkct-no-cv
-checkct-no-relse
-sse-depth 3000000
-sse-timeout 600
```

Thus the leak decision is the BINSEC taint/control-flow engine over a complete SSE path, without chosen-value or relational checkct engines. Path feasibility still uses BINSEC SSE/SMT machinery.

Workflow run: `32221229732`.

## D

**PASS_WITH_SCOPE.**

All seven finite classes complete exactly one path with:

- `Program status: secure`;
- pending paths: `0`;
- discontinued paths: `0`;
- control-flow leak sites: `0`;
- all reported control-flow checks passing.

| class | unrolled instructions | branching points | control-flow checks |
|---:|---:|---:|---:|
| 0 | 21,756 | 1,669 | 1,982 / 1,982 |
| 1 | 472,944 | 29,810 | 47,971 / 47,971 |
| 2 | 924,131 | 57,951 | 93,960 / 93,960 |
| 3 | 1,375,318 | 86,092 | 139,949 / 139,949 |
| 4 | 1,826,505 | 114,233 | 185,938 / 185,938 |
| 5 | 2,277,692 | 142,374 | 231,927 / 231,927 |
| 6 | 2,277,693 | 142,373 | 231,926 / 231,926 |

Aggregate:

- classes passed: **7 / 7**;
- unrolled instructions explored: **9,176,039**;
- branching points: **574,502**;
- control-flow checks: **933,653 / 933,653**;
- pending paths: **0**;
- control-flow leak sites: **0**.

This independently corroborates the custom exact-binary audit in `results/realtime_nn_rv32_noninterference_results.json`.

## Full constant-time negative/resource boundary

The first smoke run intentionally enabled generic full `checkct` on classes 0 and 1.

- class 0: complete and `secure`; all control-flow and memory-access checks pass.
- class 1: process exits `137` after about 60 seconds while relational memory-address analysis is active.

This is **not** evidence that class 1 has a control-flow leak. The same exact class-1 ELF path later completes under control-flow-only analysis and passes **47,971 / 47,971** control-flow checks.

The resource failure is nevertheless kept as a negative boundary: generic relational constant-time memory analysis over the LUT-heavy network does not fit the supplied GitHub runner configuration.

The known exp/GELU input-indexed LUT addresses remain covered only by the separate exact-binary localization/range audit plus the pinned target's deterministic address-independent RAM assumption. They are not declared globally constant-time.

## C

For the exact fixed-class RV32 artifact, the strongest supported software-side statement is now:

> Two independent binary-level analyses find no neural-input-dependent control flow in any finite fixed execution class, and third-party BINSEC completes every fixed-class path with all 933,653 control-flow checks secure.

Combined with the pinned Ibex RTL observation that each fixed class has identical cycle counts across three distinct held-out inputs, this materially strengthens the explanation for fixed-class timing stability.

It still does not prove a production WCET: a timing proof must additionally bind memory latency, processor/RTL behavior, interrupts/interference, and physical implementation as applicable.

## U

- The final all-class BINSEC run is control-flow-only; it deliberately does not claim memory-address independence.
- BINSEC itself is an external analyzer, not a formal proof of the Ibex hardware timing model.
- The retained exact ELF was obtained from a GitHub Actions evidence artifact; hashes are recorded to prevent silent substitution.
- Generic full relational memory checking for class 1 exceeded runner resources.
- FPGA/ASIC/silicon timing remains a later target-specific validation step.
