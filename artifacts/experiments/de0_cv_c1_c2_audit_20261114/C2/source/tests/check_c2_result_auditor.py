#!/usr/bin/env python3
"""Regression of independent artifact audit, including deliberately corrupted copies."""
import argparse
import csv
import hashlib
import json
from pathlib import Path
import shutil
import subprocess
import sys


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--fixtures", type=Path, required=True)
    ap.add_argument("--cases", type=Path, required=True)
    ap.add_argument("--out", type=Path, required=True)
    args = ap.parse_args()
    args.out.mkdir(parents=True, exist_ok=False)
    auditor = Path(__file__).resolve().parents[1] / "tools/audit_c2_jtag_results.py"
    checks = []
    jobs = [("all_42", "all_42", "ALL", True),
            ("single", "single_frozen_2", "2", True),
            ("subset", "fixed_and_adaptive", "2,27,34", True),
            ("failed_response", "wrong_prediction", "ALL", False),
            ("forged_cycles", "all_42", "ALL", False),
            ("corrupt_wire_crc", "all_42", "ALL", False),
            ("missing_csv_row", "all_42", "ALL", False),
            ("missing_raw_response", "all_42", "ALL", False),
            ("wrong_experiment", "all_42", "ALL", False),
            ("wrong_sof", "all_42", "ALL", False),
            ("subset_claimed_full", "fixed_and_adaptive", "2,27,34", False)]
    for name, source, selection, should_pass in jobs:
        dest = args.out / name
        shutil.copytree(args.fixtures / source, dest)
        jp = dest / "c2_jtag_results.json"
        cp = dest / "c2_jtag_results.csv"
        rp = dest / "c2_jtag_raw.log"
        j = json.loads(jp.read_text())
        with cp.open(newline="") as f:
            reader = csv.DictReader(f)
            fields = reader.fieldnames
            rows = list(reader)
        if name == "forged_cycles":
            j["cases"][0]["cycles"] += 10
            rows[0]["cycles"] = str(j["cases"][0]["cycles"])
        elif name == "corrupt_wire_crc":
            old = j["cases"][0]["response_lsb_hex"]
            new = f"{int(old, 16) ^ (1 << (8*22)):096x}"
            j["cases"][0]["response_lsb_hex"] = new
            rows[0]["response_lsb_hex"] = new
            rp.write_text(rp.read_text().replace(old, new))
        elif name == "missing_csv_row":
            rows.pop()
        elif name == "missing_raw_response":
            lines = rp.read_text().splitlines()
            rp.write_text("\n".join(x for x in lines if not x.startswith("RESPONSE seq=1 ")) + "\n")
        elif name == "wrong_experiment":
            j["experiment_id"] = "WRONG"
        elif name == "wrong_sof":
            j["sof_sha256"] = "b" * 64
        elif name == "subset_claimed_full":
            j["scope"] = "all_frozen_42"
        jp.write_text(json.dumps(j), encoding="utf-8")
        with cp.open("w", newline="") as f:
            writer = csv.DictWriter(f, fieldnames=fields)
            writer.writeheader()
            writer.writerows(rows)
        command = [sys.executable, str(auditor), "--cases", str(args.cases),
                   "--expected-cases-sha256", hashlib.sha256(args.cases.read_bytes()).hexdigest(),
                   "--results", str(dest), "--sof-sha256", "a" * 64,
                   "--experiment-id", "HOST_MOCK_" + source, "--sequences", selection,
                   "--out", str(dest / "audit.json")]
        proc = subprocess.run(command, capture_output=True, text=True, timeout=15)
        (dest / "audit_stdout.log").write_text(proc.stdout)
        (dest / "audit_stderr.log").write_text(proc.stderr)
        good = (proc.returncode == 0) == should_pass
        receipt = json.loads((dest / "audit.json").read_text())
        good = good and receipt["hardware_provenance_verified_by_this_checker"] is False
        checks.append({"name": name, "status": "PASS" if good else "FAIL",
                       "auditor_exit_code": proc.returncode, "audit": receipt})
        print(f"{'PASS' if good else 'FAIL'} {name} audit_exit={proc.returncode}")
    (args.out / "summary.json").write_text(json.dumps(
        {"physical_jtag": False, "results": checks}, indent=2) + "\n", encoding="utf-8")
    return int(any(c["status"] != "PASS" for c in checks))


if __name__ == "__main__":
    raise SystemExit(main())
