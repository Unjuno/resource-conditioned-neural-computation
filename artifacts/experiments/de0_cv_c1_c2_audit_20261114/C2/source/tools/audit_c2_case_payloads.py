#!/usr/bin/env python3
"""Validate the frozen 42-case CSV and its exact 100-byte JTAG request payloads."""
import csv
import json
import struct
import zlib
import argparse
from pathlib import Path

HERE = Path(__file__).resolve().parent
BASE = HERE.parent
parser = argparse.ArgumentParser()
parser.add_argument("--csv", type=Path, default=BASE / "host" / "c2_cases.csv")
parser.add_argument("--manifest", type=Path, default=None)
parser.add_argument("--build-id", type=lambda value:int(value,0), default=0x43324a31)
args = parser.parse_args()
CSV_PATH = args.csv
MANIFEST_PATH = args.manifest or CSV_PATH.with_name("c2_case_manifest.json")

rows = list(csv.DictReader(CSV_PATH.open(newline="", encoding="utf-8")))
assert len(rows) == 42, len(rows)
assert sum(r["case_kind"] == "CERT" for r in rows) == 21
assert sum(r["case_kind"] == "E2E" for r in rows) == 21
seen_seq = set()
legacy_admission_differences = []
for row in rows:
    seq = int(row["seq"])
    iid = int(row["input_id"])
    assert seq not in seen_seq
    seen_seq.add(seq)
    wire = bytes.fromhex(row["jtag_request_100b_hex"])
    assert len(wire) == 100
    req, pixels, payload_crc = wire[:32], wire[32:96], wire[96:100]
    assert len(bytes.fromhex(row["pixels_u8_64_hex"])) == 64
    assert pixels.hex() == row["pixels_u8_64_hex"]
    assert req[:8] == bytes((ord("R"), ord("T"), ord("N"), ord("Q"), 1,
                             int(row["mode"]), int(row["fixed_exit"]), 0))
    assert struct.unpack_from("<I", req, 8)[0] == seq
    assert struct.unpack_from("<H", req, 12)[0] == iid
    assert struct.unpack_from("<H", req, 14)[0] == int(row["budget_q16"])
    assert struct.unpack_from("<I", req, 20)[0] == 0x52544E4E
    assert struct.unpack_from("<I", req, 24)[0] == args.build_id
    assert int(row["build_id"], 16) == args.build_id
    assert struct.unpack_from("<I", req, 28)[0] == zlib.crc32(req[:28])
    assert struct.unpack("<I", payload_crc)[0] == zlib.crc32(pixels)
    assert row["payload_crc32"] == f"{struct.unpack('<I', payload_crc)[0]:08x}"
    assert int(row["expected_executed"]) <= int(row["expected_admitted"])
    assert int(row["expected_prediction"]) == int(row["legacy_prediction"])
    if row["case_kind"] == "E2E":
        assert int(row["expected_executed"]) == int(row["legacy_exit"]), (
            f"adaptive executed exit differs from frozen transcript at seq={seq}"
        )
        if int(row["legacy_admitted"]) != int(row["expected_admitted"]):
            legacy_admission_differences.append(seq)
manifest = json.loads(MANIFEST_PATH.read_text(encoding="utf-8"))
assert manifest["count"] == 42
assert manifest["legacy_cycles_used_as_fpga_expectation"] is False
print("C2_CASE_PAYLOAD_AUDIT_PASS cases=42 bytes_each=100 bits_each=800 unique_seq=42 "
      f"adaptive_legacy_admission_differences={legacy_admission_differences}")
