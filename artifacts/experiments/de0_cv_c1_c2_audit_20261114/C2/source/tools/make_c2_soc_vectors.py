#!/usr/bin/env python3
"""Export frozen C2 host cases to Verilator $readmemh vectors."""
import csv
import hashlib
import json
import struct
import argparse
from pathlib import Path

BASE = Path(__file__).resolve().parents[1]
parser = argparse.ArgumentParser()
parser.add_argument("--cases", type=Path, default=BASE / "host/c2_cases.csv")
parser.add_argument("--outdir", type=Path, default=BASE / "sim_vectors_20261112")
args = parser.parse_args()
OUT = args.outdir
OUT.mkdir(parents=True, exist_ok=False)
rows = list(csv.DictReader(args.cases.open(newline="", encoding="utf-8")))
if len(rows) != 42:
    raise SystemExit(f"expected 42 fixed cases, got {len(rows)}")
requests=[]; expected=[]
for row in rows:
    payload=bytes.fromhex(row["jtag_request_100b_hex"])
    if len(payload)!=100:
        raise SystemExit(f"sequence {row['seq']} has request length {len(payload)}")
    # `$readmemh` loads the most-significant textual hex digit into vector MSB;
    # reversing the byte string makes vector bit 0 the first RTNQ serial bit.
    requests.append(payload[::-1].hex())
    values=(int(row["seq"]),int(row["input_id"]),int(row["mode"]),
            int(row["expected_admitted"]),int(row["expected_executed"]),
            int(row["expected_prediction"]),int(row["expected_label"]),
            int(row["budget_q16"]),int(row["expected_stop"]))
    expected.append(struct.pack("<9I",*values)[::-1].hex())
(OUT/"c2_requests.hex").write_text("\n".join(requests)+"\n",encoding="ascii")
(OUT/"c2_expected.hex").write_text("\n".join(expected)+"\n",encoding="ascii")
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
build_ids={row["build_id"] for row in rows}
if len(build_ids) != 1 or any(row["model_id"] != "52544e4e" for row in rows):
    raise SystemExit("case table has mixed build IDs or an unexpected model ID")
manifest={"status":"C2_SIM_VECTORS_FROM_FROZEN_CASES","count":len(rows),
          "build_id":next(iter(build_ids)),
          "cases_sha256":sha(args.cases),
          "requests_sha256":sha(OUT/"c2_requests.hex"),
          "expected_sha256":sha(OUT/"c2_expected.hex"),
          "nonclaims":["expected cycles are not present; RTL response cycles are validated nonzero only",
                       "not FPGA measurements"]}
(OUT/"c2_sim_vectors_manifest.json").write_text(json.dumps(manifest,indent=2)+"\n")
print("C2_SOC_VECTORS_READY",len(rows),manifest["requests_sha256"],manifest["expected_sha256"])
