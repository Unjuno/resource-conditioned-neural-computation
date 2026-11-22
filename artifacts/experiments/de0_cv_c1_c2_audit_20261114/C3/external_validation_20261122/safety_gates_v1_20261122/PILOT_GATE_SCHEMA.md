# Pilot gate schema v1

`rtnn-extval-pilot-gate-v1` is generated only by `PILOT_GATE_CREATOR.py` after the saved run has 20 complete cases. It is a record-consistency gate, not a cryptographic attestation of physical hardware.

Required content includes: completed run identity; exactly 10 frozen pilot input IDs × `{fixed2, adaptive}`; build `45585631`, binding `45585632`, model `52544e4e`; SOF/ELF identity; CPU oracle; frozen pilot and primary manifests; result CSV; raw JTAG log; SHA-256 for each input artifact; and separate `operator_authorization` versus `pilot_attempt_recorded` fields.

The verifier reopens the underlying files, verifies their hashes, parses all 20 raw request/response pairs, recomputes CRCs, checks protocol IDs/mode/label sentinel/counter boundaries, joins source-row IDs to the oracle's manifest-order IDs, and rechecks prediction/Exit against both the CPU oracle and case CSV. A hand-written `audit=PILOT_AUDIT_PASS` cannot pass without the source evidence files.

The gate does not establish timing signoff, cold boot, absence of fabrication, or physical acquisition beyond internally consistent recorded evidence. Fixtures are rejected by production mode.

Generate after a real pilot run and independent manual review:

```powershell
python .\safety_gates_v1_20261122\PILOT_GATE_CREATOR.py `
  --run-dir .\build\physical_pilot_RUN1 `
  --oracle .\build\cpu_oracle_attempt1\oracle_pilot.csv `
  --pilot-manifest .\data\pilot_manifest.csv `
  --primary-manifest .\data\primary_manifest.csv `
  --operator-authorization recorded `
  --out .\build\pilot_gate_RUN1.json
```

No gate is generated in this offline preparation because there is no physical pilot run.
