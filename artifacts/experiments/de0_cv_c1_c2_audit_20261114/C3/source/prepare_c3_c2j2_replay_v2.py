#!/usr/bin/env python3
"""Rebind the preserved C2J2 42 physical cases to C3 measurement build 43334531.

Only the request build ID and the corresponding 32-byte header CRC are changed.
Frozen pixels, pixel CRC, case order, model, expected prediction/Exit/cap, and
label are independently checked against the pinned Q15 host table/dataset.
"""
from __future__ import annotations

import argparse
import csv
import hashlib
import json
import struct
import zlib
from pathlib import Path

BUILD = "43334531"
MODEL = "52544e4e"
CAMPAIGN = "d6c98f59c0c0afe32d0877c01c8411fba8bf3e2a5c8058c5a85371f7f648a8dc"
CASES_SHA = "52b7fdae7c465fd4b6409876e258e00fbaad5656e93ad3b9fb79f2f8741aec5d"
DATASET_SHA = "eeba9000a918bcba911007e78905c5052fc743422f95cb314a0fc9f4ecdfb14c"
HOST_SHA = "1f9b08987a9d7368b663f604eb1dce6e077073e099552532468509c846d6bdc8"
ORACLE_SHA = "4e1a3ddcabe1884b1607c77d19b10da8a86d53da3f4c060c30d7449635ec3cf4"
FIELDS = ["seq","case_kind","slot","test_index","input_id","mode","parameter_index","fixed_exit","budget_q16","expected_admitted","expected_executed","expected_prediction","expected_label","expected_stop","legacy_prediction","legacy_exit","legacy_admitted","legacy_cycles_not_fpga","request_frame_hex","pixels_u8_64_hex","payload_crc32","jtag_request_100b_hex","jtag_request_bytes","jtag_request_bits","model_id","build_id","deadline_cycles","binding_id"]

def sha_bytes(b: bytes) -> str:
    return hashlib.sha256(b).hexdigest()

def sha_file(p: Path) -> str:
    return sha_bytes(p.read_bytes())

def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--cases", type=Path, required=True)
    ap.add_argument("--dataset", type=Path, required=True)
    ap.add_argument("--host-q15", type=Path, required=True)
    ap.add_argument("--out", type=Path, required=True)
    a = ap.parse_args()
    if a.out.exists():
        raise SystemExit(f"refuse existing output: {a.out}")
    if sha_file(a.cases) != CASES_SHA or sha_file(a.dataset) != DATASET_SHA or sha_file(a.host_q15) != HOST_SHA:
        raise SystemExit("frozen C2J2/dataset/Q15 SHA mismatch")
    dataset = json.loads(a.dataset.read_text(encoding="utf-8"))
    inputs = {int(x["input_id"]): x for x in dataset["records"]}
    host_rows = list(csv.DictReader(a.host_q15.open(newline="", encoding="utf-8-sig")))
    host = {(int(x["input_id"]), int(x["mode"]), int(x["param"])): x for x in host_rows}
    rows = list(csv.DictReader(a.cases.open(newline="", encoding="utf-8-sig")))
    if len(rows) != 42 or {int(x["input_id"]) for x in rows} != {0,24,57}:
        raise SystemExit("frozen C2J2 case count/input set mismatch")
    outrows = []
    schedule = []
    for expected_seq, src in enumerate(rows, 1):
        seq, iid, mode = int(src["seq"]), int(src["input_id"]), int(src["mode"])
        if seq != expected_seq or src["build_id"].lower() != "43324a32" or src["model_id"].lower() != MODEL:
            raise SystemExit(f"source sequence/build/model mismatch at {seq}")
        pixels = bytes.fromhex(src["pixels_u8_64_hex"])
        payload = bytearray.fromhex(src["jtag_request_100b_hex"])
        if len(pixels) != 64 or len(payload) != 100 or payload[:4] != b"RTNQ" or payload[4] != 1:
            raise SystemExit(f"invalid frozen request structure at seq={seq}")
        if payload[32:96] != pixels or struct.unpack_from("<I", payload, 96)[0] != zlib.crc32(pixels):
            raise SystemExit(f"frozen pixels/pixel CRC mismatch at seq={seq}")
        if pixels != bytes(inputs[iid]["pixels_u8_64"]):
            raise SystemExit(f"dataset input mismatch at seq={seq}")
        param = int(src["parameter_index"])
        ref = host[(iid, mode, param)]
        expected = (int(ref["admitted_exit"]), int(ref["executed_exit"]), int(ref["prediction"]), int(inputs[iid]["label"]), int(ref["stop_reason"]))
        got = tuple(int(src[k]) for k in ("expected_admitted","expected_executed","expected_prediction","expected_label","expected_stop"))
        if got != expected:
            raise SystemExit(f"frozen expected result disagrees with pinned Q15 table at seq={seq}: {got} != {expected}")
        if mode == 1 and (int(src["fixed_exit"]) != param or int(src["budget_q16"]) != 65535):
            raise SystemExit(f"fixed case parameter mismatch at seq={seq}")
        struct.pack_into("<I", payload, 24, int(BUILD, 16))
        struct.pack_into("<I", payload, 28, zlib.crc32(payload[:28]))
        frame = bytes(payload[:32])
        if frame[32-4:32] != payload[28:32]:
            raise SystemExit(f"request header CRC write failed at seq={seq}")
        r = dict(src)
        r.update({"case_kind":"C2J2_FROZEN_REPLAY_REBOUND","request_frame_hex":frame.hex(),"jtag_request_100b_hex":payload.hex(),"jtag_request_bytes":"100","jtag_request_bits":"800","model_id":MODEL,"build_id":BUILD,"binding_id":BUILD})
        outrows.append(r)
        schedule.append({k:(int(r[k]) if k in {"seq","input_id","mode","parameter_index","fixed_exit","budget_q16","expected_admitted","expected_executed","expected_prediction","expected_label","expected_stop"} else r[k]) for k in ("seq","input_id","mode","parameter_index","fixed_exit","budget_q16","expected_admitted","expected_executed","expected_prediction","expected_label","expected_stop")})
    schedule_sha = sha_bytes(json.dumps(schedule, sort_keys=True, separators=(",",":"), ensure_ascii=False).encode())
    a.out.mkdir(parents=True)
    csv_path = a.out / "cases.csv"
    with csv_path.open("w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=FIELDS, lineterminator="\n")
        w.writeheader(); w.writerows(outrows)
    schedule_path = a.out / "c2j2_replay_v2_schedule.json"
    schedule_path.write_text(json.dumps({"schema":"rtnn-c2j2-replay-v2-schedule-v1","source_cases_sha256":CASES_SHA,"rows":schedule}, indent=2)+"\n", encoding="utf-8")
    manifest = {"schema":"rtnn-c3-c2j2-replay-v2-preparation-v1","status":"PASS_REBOUND_CASES_HOST_ONLY","source_cases_sha256":CASES_SHA,"dataset_sha256":DATASET_SHA,"oracle_sha256":ORACLE_SHA,"host_q15_sha256":HOST_SHA,"campaign_canonical_sha256":CAMPAIGN,"source_build_id":"43324a32","target_build_id":BUILD,"model_id":MODEL,"case_count":42,"input_ids":[0,24,57],"mode_counts":{"fixed":21,"adaptive":21},"rebind_scope":"Only RTNQ build_id bytes 24..27 and header CRC bytes 28..31 changed. Input bytes, pixel CRC, sequence/order, modes, budgets, frozen expected values unchanged.","schedule_id":"C2J2_REPLAY_V2","schedule_canonical_sha256":schedule_sha,"case_csv_sha256":sha_file(csv_path),"schedule_file_sha256":sha_file(schedule_path),"sof_sha256":"85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d","timing_classification":"EMPIRICAL_ONLY","wcet_or_hard_deadline_claimed":False,"physical_run":"NOT_RUN"}
    (a.out/"preparation_manifest.json").write_text(json.dumps(manifest, indent=2)+"\n", encoding="utf-8")
    binding = {"schema":"rtnn-c3-measurement-v2-host-binding-v1","binding_id":BUILD,"session_id":"C2J2_REPLAY_V2","purpose":"EXISTING_C2J2_42_REPLAY_ON_C3_V2_BUILD","record_count":42,"full_schedule_record_count":42,"selected_schedule_sequences":list(range(1,43)),"session_scope":"FULL_C2J2_REPLAY_SET_NOT_A_360_CAMPAIGN_SCHEDULE","schedule_file":"c2j2_replay_v2_schedule.json","schedule_canonical_sha256":schedule_sha,"campaign_canonical_sha256":CAMPAIGN,"campaign_file_sha256":"3d97a1cd87395e294299cacb617474367c89a9295355cd25fb1b4fa67464c936","dataset_file_sha256":DATASET_SHA,"oracle_file_sha256":ORACLE_SHA,"host_q15_file_sha256":HOST_SHA,"sof_sha256":manifest["sof_sha256"],"sof_binding_status":"C3_V2_SOF_SHA_BOUND_NOT_YET_PROGRAMMED","firmware_elf_sha256":"9cbf537bd9440deaf5c78abf6b204da9cbcd2fe3795acf444d733dbd581002b6","build_id":BUILD,"model_id":MODEL,"response_protocol_version":2,"response_bytes":60,"binding_id_field":BUILD,"case_csv_sha256":manifest["case_csv_sha256"],"frozen_schedule_modified":False,"source_cases_sha256":CASES_SHA,"rebind_manifest_sha256":sha_file(a.out/"preparation_manifest.json"),"timing_classification":"EMPIRICAL_ONLY","wcet_or_hard_deadline_claimed":False,"measurement_eligible":True}
    binding_path = a.out/"binding.json"
    binding_path.write_text(json.dumps(binding, indent=2)+"\n", encoding="utf-8")
    print(json.dumps({"status":"PASS_REBOUND_CASES_HOST_ONLY","count":42,"schedule_sha256":schedule_sha,"cases_sha256":manifest["case_csv_sha256"],"binding_sha256":sha_file(binding_path),"physical_run":"NOT_RUN"}, indent=2))
    return 0

if __name__ == "__main__":
    raise SystemExit(main())
