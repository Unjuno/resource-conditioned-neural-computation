import json
import re
import sys
from pathlib import Path

STATIC_CERT = [21980, 549571, 1077159, 1604747, 2132335, 2659924, 2659924]
pat = re.compile(r"RTNN n=(\d) c=(\d) cyc=([0-9a-fA-F]{8}) pred=(\d)")
rows = []
for line in Path(sys.argv[1]).read_text(errors="replace").splitlines():
    m = pat.search(line)
    if m:
        rows.append({"input": int(m.group(1)), "class": int(m.group(2)), "cycles": int(m.group(3), 16), "pred": int(m.group(4))})
if len(rows) != 14:
    raise SystemExit(f"expected 14 RTNN rows, got {len(rows)}")
by_class = []
data_independent = True
for cls in range(7):
    rr = sorted((r for r in rows if r["class"] == cls), key=lambda x: x["input"])
    if len(rr) != 2:
        raise SystemExit(f"class {cls}: expected two inputs, got {len(rr)}")
    equal = rr[0]["cycles"] == rr[1]["cycles"]
    data_independent &= equal
    rtl = max(r["cycles"] for r in rr)
    static = STATIC_CERT[cls]
    by_class.append({
        "class": cls,
        "fraction": cls / 6.0,
        "cycles_by_input": [r["cycles"] for r in rr],
        "same_cycles_across_inputs": equal,
        "rtl_max_cycles": rtl,
        "conditional_static_cycles": static,
        "rtl_minus_static": rtl - static,
        "rtl_over_static": rtl / static,
        "static_bound_exceeded": rtl > static,
        "predictions": [r["pred"] for r in rr],
    })
out = {
    "ibex_commit": "7b5df75a041affe56e8c235260f98a09b3319008",
    "rtl_patch": "ibex_core.sv DataIndTiming localparam forced to 1 while SecureIbex remains 0",
    "configuration": {
        "RV32M": "RV32MSingleCycle",
        "RV32ZC": "RV32ZCNone",
        "RV32B": "RV32BNone",
        "ICache": 0,
        "BranchTargetALU": 0,
        "WritebackStage": 0,
        "SecureIbex": 0,
    },
    "measured_region": "rtnn_fixed_certify_class only, using mcycle before/after",
    "two_inputs_cycle_identical_all_classes": data_independent,
    "classes": by_class,
    "conditional_static_table_validated_without_exceedance": all(not x["static_bound_exceeded"] for x in by_class),
}
Path("ibex_rtl_validation.json").write_text(json.dumps(out, indent=2) + "\n")
print(json.dumps(out, indent=2))
# Malformed or input-dependent RTL timing is a CI failure. A static-bound exceedance is
# deliberately reported as research evidence rather than hiding it behind a failed job.
if not data_independent:
    raise SystemExit("RTL cycle count varies across the two fixed inputs")
