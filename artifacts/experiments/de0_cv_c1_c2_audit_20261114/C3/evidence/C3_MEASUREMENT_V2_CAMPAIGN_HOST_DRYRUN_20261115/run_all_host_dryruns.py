#!/usr/bin/env python3
"""Bind all unchanged frozen C3 schedules to the v2 image without claiming a SOF."""
from __future__ import annotations
import hashlib, importlib.util, json, sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
SRC = HERE.parents[1] / "source" / "prepare_c3_measurement_v2_host.py"
spec = importlib.util.spec_from_file_location("c3_prepare_v2", SRC)
module = importlib.util.module_from_spec(spec)
assert spec and spec.loader
spec.loader.exec_module(module)
base = HERE.parents[1]
campaign = json.loads((base / "frozen_inputs/paper/campaign/campaign.json").read_text())
results = []
for item in campaign["schedules"]:
    output = HERE / item["session_id"]
    result = module.run(output, item["session_id"])
    binding = json.loads((output / "binding.json").read_text())
    result.update({
        "cases_sha256": hashlib.sha256((output / "cases.csv").read_bytes()).hexdigest(),
        "binding_sha256": hashlib.sha256((output / "binding.json").read_bytes()).hexdigest(),
        "sof_sha256": binding["sof_sha256"],
        "measurement_eligible": binding["measurement_eligible"],
    })
    results.append(result)
report = {
    "status": "PASS_HOST_DRYRUN_NOT_PHYSICAL",
    "schedule_count": len(results),
    "total_rows": sum(x["rows"] for x in results),
    "campaign_canonical_sha256": module.CAMPAIGN_CANON_SHA,
    "build_id": f"{module.BUILD_ID:08x}",
    "binding_id": f"{module.BUILD_ID:08x}",
    "sof_sha256": None,
    "timing_classification": "EMPIRICAL_ONLY",
    "wcet_or_hard_deadline_claimed": False,
    "sessions": results,
}
(HERE / "host_dryrun_report.json").write_text(json.dumps(report, indent=2) + "\n")
(HERE / "host_dryrun_report.sha256").write_text(
    hashlib.sha256((HERE / "host_dryrun_report.json").read_bytes()).hexdigest() + "  host_dryrun_report.json\n"
)
print(json.dumps({k: report[k] for k in ("status", "schedule_count", "total_rows", "campaign_canonical_sha256", "build_id")}, indent=2))
