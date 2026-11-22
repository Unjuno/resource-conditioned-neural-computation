# Power session evidence schema v1

Schema: `rtnn-extval-power-session-evidence-v1`.

Allowed `event_kind` values:

* `LOGICAL_KEY_RESET_ONLY`
* `SOF_RECONFIGURATION_ONLY`
* `OPERATOR_ATTESTED_POWER_CYCLE_RAIL_UNVERIFIED`
* `FULL_RAIL_POWER_CYCLE_EVIDENCE_VERIFIED`
* `POWER_SESSION_UNKNOWN`

Required identity and audit fields: experiment/session ID, board identity, build ID, binding ID, model ID, SOF SHA, previous-session relationship, event kind, UTC operation and record timestamps (record time not earlier than operation), operator action, power target, `all_power_inputs_enumerated`, `power_path_inventory`, USB-Blaster/USB-power status, before/after identity reads (matching JTAG IDCODE/build/binding/model/SOF identity), per-rail CSV path and SHA, power-state measurement method, measurement uncertainty, and an explicit `unknown_items` array. The validator requires these fields before classifying a full-rail event.

`FULL_RAIL_POWER_CYCLE_EVIDENCE_VERIFIED` requires distinct records for at least three sessions; ordered session relationship; matching board/build/SOF identity and experiment; unique record and instrument-file SHA values; all power sources and FPGA rails explicitly covered by the enumerated inventory; USB-Blaster physically isolated during rail decay; stable read-only identity before and after; and oscilloscope CSV traces with monotonic `time_s,voltage_v` samples showing ≥0.5 V before the first drop to ≤0.1 V and then ≤0.1 V for at least 1 s on every declared rail. Merely declared min/max values are ignored. A scope trace is still evidence with uncertainty; it is not a formal hardware guarantee.

Any missing rail, unknown USB path, reused evidence, logical reset, SOF reload, or operator statement alone yields `COLD_BOOT_UNVERIFIED`. Functional results remain independently analysable with that status.

The current evidence set contains no verified rail traces. Do not create records for prior operations from memory; record them only if contemporaneous evidence exists.
