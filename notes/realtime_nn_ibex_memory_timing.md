# Pinned Ibex memory timing for RTNN LUT accesses

## H

The four neural-input-indexed memory-load sites remaining in the exact RV32 RTNN binary do not create input-dependent memory response latency when the certified target is the pinned one-host Ibex Simple System with its deterministic on-chip `ram_2p` memory.

## T

The audit binds the exact RTNN artifact and exact upstream memory RTL:

- RTNN ELF SHA-256: `234a7f46cf227a11f5d97f3c778cbb0c4ed4f7067f8994bcca86c4b08ff4e742`
- RTNN binary SHA-256: `266ecb70c723b2164f6fe9039f27d4cb49c4d7271d4aca0cf69f2692cdfdf7a1`
- Ibex commit: `7b5df75a041affe56e8c235260f98a09b3319008`
- `bus.sv` SHA-256: `b24c2cbe36cee25230c61d533258a66707ee03c7c3857cc97494c8d95a2a2953`
- `ibex_simple_system.sv` SHA-256: `0e8d45f70096302e77bc0f83dc56a4a2c3c35cf46adab82a75cc4bb8092fed11`
- `ram_2p.sv` SHA-256: `c479f3814048706cdeea24138c465d7cc4d3129326568deaa3590c66df0465a5`

### Exact binary / LUT placement

The four input-indexed sites from the exact-binary noninterference audit remain 32-bit RV32 `LW` instructions:

- `0x001002ec`
- `0x001002f0`
- `0x0010152c`
- `0x00101530`

There are no input-indexed store sites.

The exact ELF places:

- `fx_gelu_lut`: `0x00102308..0x0010630b`, 4,097 words;
- `fx_exp_lut`: `0x0010630c..0x0010e30f`, 8,193 words.

Both tables are word-aligned and fully contained in the pinned Simple System RAM window `0x00100000..0x001fffff`.

### Exhaustive bus decode

The Simple System has one data host and three devices:

- RAM: base `0x00100000`, mask `0xfff00000`;
- SimCtrl: base `0x00020000`, mask `0xfffffc00`;
- Timer: base `0x00030000`, mask `0xfffffc00`.

Every legal LUT word address was enumerated:

`4,097 + 8,193 = 12,290` addresses.

All `12,290/12,290` decode uniquely to RAM. None decodes to SimCtrl or Timer.

### Pinned `ram_2p` control netlist

The actual pinned `ram_2p.sv` is synthesized with Yosys. Only the primitive RAM's **data values** are stubbed; the `ram_2p` response-valid control is retained unchanged.

For `a_rvalid_o`, the generated control netlist has:

- one `$adff` driver;
- D input exactly `a_req_i`;
- clock exactly `clk_i`;
- async reset exactly `rst_ni`;
- reset value 0;
- primary-input fan-in exactly `a_req_i`, `clk_i`, `rst_ni`;
- **no address signal in the transitive fan-in**.

This matches the upstream RTL's documented one-cycle read/write delay and statement `a_rvalid_o <= a_req_i`.

### Bus/RAM composition

For the LUT address domain:

1. the single data host request/address is combinationally forwarded to the uniquely selected RAM;
2. the bus registers device/host selection for the response cycle;
3. the RAM registers `a_rvalid_o` from the request with no address dependence;
4. the bus returns the selected device's `rvalid` to the only host.

Therefore the composed data read response latency for legal LUT accesses is **one cycle and address-independent** in this exact Simple System memory model.

## D

**PASS_WITH_SCOPE.**

Final successful workflow run: `32225250507`.
Job: `95983544767`.
Evidence artifact: `9355305985`.
Artifact ZIP SHA-256: `68082d41bad4da1b4fd7a40a495b79b6a133d956796987d0e7e89af91d11b03a`.

Observed proof/audit results:

- exact RTNN ELF/bin identity: PASS;
- exact upstream memory RTL identity: PASS;
- four input-indexed load sites still `LW`: PASS;
- input-indexed stores: 0;
- LUT word addresses exhaustively checked: 12,290;
- unique RAM decodes: 12,290;
- decode failures: 0;
- `a_rvalid_o` D exactly request: PASS;
- address bits in response-valid fan-in: 0;
- composed legal-LUT read response latency: 1 cycle.

## C

This closes the specific memory-timing gap left by the custom taint audit and BINSEC fixed-class control-flow result **for the pinned Simple System memory model**.

Previously, the exact compiled binary had four neural-input-dependent load addresses, so a generic statement such as "all memory addresses are secret-independent" was false. BINSEC's full relational memory analysis also exceeded the supplied runner resources for a LUT-heavy class.

The relevant hard-real-time question is narrower: do those varying addresses change response latency on the selected certification memory? For the pinned Simple System RAM, the answer is no under the audited RTL composition. The addresses select different LUT values but do not select a different memory device or a different response-valid timing path.

This means the generic constant-memory-address property is **not required for this target-specific timing argument**. It would become relevant again for a cache, SDRAM controller, banked/interleaved memory, contention, or another address-sensitive implementation.

## U

The following remain outside this result:

1. FPGA/DE0-CV memory timing. The DE0-CV implementation must use its own memory map, RAM inference/primitive, clock, synthesis/place-and-route, and timing evidence.
2. Caches, external SDRAM, DMA, multiple competing masters, and arbitration.
3. A universal all-Ibex memory theorem; this result pins one upstream commit and one Simple System integration.
4. A silicon WCET certificate.
5. Formal proof of the complete Ibex processor pipeline. The processor execution-time table remains pinned-RTL measured evidence, complemented by BINSEC/CBMC software proofs.

An earlier sequential SAT harness was discarded because clock transformation made the model unsuitable for interpreting its counterexample. The accepted result uses direct exact-RTL structural/netlist evidence instead of weakening the timing claim or adding a safety margin.
