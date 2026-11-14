#!/usr/bin/env python3
"""Create a new-build JTAG pilot binding from frozen campaign rows only."""
from __future__ import annotations

import argparse
import csv
import hashlib
import json
import struct
import zlib
from pathlib import Path


EXPECTED_CAMPAIGN_FILE_SHA = "3d97a1cd87395e294299cacb617474367c89a9295355cd25fb1b4fa67464c936"
EXPECTED_CAMPAIGN_SHA = "d6c98f59c0c0afe32d0877c01c8411fba8bf3e2a5c8058c5a85371f7f648a8dc"
EXPECTED_DATASET_FILE_SHA = "eeba9000a918bcba911007e78905c5052fc743422f95cb314a0fc9f4ecdfb14c"
EXPECTED_ORACLE_SHA = "4e1a3ddcabe1884b1607c77d19b10da8a86d53da3f4c060c30d7449635ec3cf4"
EXPECTED_HOST_Q15_SHA = "1f9b08987a9d7368b663f604eb1dce6e077073e099552532468509c846d6bdc8"
EXPECTED_VERDICT_SHA = "81f35dab218a8aed82b635a85f4390ead3bf4aa3e00f0e535fce10e3f935483d"
EXPECTED_Q15_DIGEST = "03eb958cfa8b4fd2f71a95fb47dbca512820c237c281473817bba685b92c743e"
EXPECTED_SO_F_SHA = "5aa5be2e7387e22e43db6a322e1572cceacd3266231af4dbc2de01ee649c37e6"
EXPECTED_BUILD_ID = 0x43324A32
PILOT_ROW_SEQS = (1, 2, 3, 4)
FIELDNAMES = [
    "seq", "case_kind", "slot", "test_index", "input_id", "mode",
    "parameter_index", "fixed_exit", "budget_q16", "expected_admitted",
    "expected_executed", "expected_prediction", "expected_label",
    "expected_stop", "legacy_prediction", "legacy_exit", "legacy_admitted",
    "legacy_cycles_not_fpga", "request_frame_hex", "pixels_u8_64_hex",
    "payload_crc32", "jtag_request_100b_hex", "jtag_request_bytes",
    "jtag_request_bits", "model_id", "build_id", "deadline_cycles",
]


def sha(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def canonical_sha(value: object) -> str:
    return sha(json.dumps(value, sort_keys=True, separators=(",", ":"), allow_nan=False).encode())


def read_json(path: Path) -> object:
    return json.loads(path.read_text(encoding="utf-8"))


def prepare(root: Path, out: Path, sof: Path, elf: Path, firmware_manifest: Path) -> dict:
    if out.exists():
        raise ValueError(f"refusing to overwrite {out}")
    campaign_path = root / "paper/campaign/campaign.json"
    campaign_bytes = campaign_path.read_bytes()
    if sha(campaign_bytes) != EXPECTED_CAMPAIGN_FILE_SHA:
        raise ValueError("frozen campaign file SHA mismatch")
    campaign = json.loads(campaign_bytes)
    canonical_campaign = dict(campaign)
    claimed_campaign_sha = canonical_campaign.pop("campaign_sha256")
    if canonical_sha(canonical_campaign) != EXPECTED_CAMPAIGN_SHA or claimed_campaign_sha != EXPECTED_CAMPAIGN_SHA:
        raise ValueError("frozen campaign canonical SHA mismatch")
    if campaign["unique_accuracy_inputs"] != 360 or sum(s["record_count"] for s in campaign["schedules"]) != 24840:
        raise ValueError("frozen campaign size mismatch")

    for schedule_meta in campaign["schedules"]:
        schedule = read_json(root / "paper/campaign" / schedule_meta["matrix"])
        if len(schedule["rows"]) != schedule_meta["record_count"]:
            raise ValueError(f"row count mismatch: {schedule_meta['session_id']}")
        if canonical_sha(schedule["rows"]) != schedule_meta["schedule_sha256"]:
            raise ValueError(f"schedule canonical SHA mismatch: {schedule_meta['session_id']}")
    schedule = read_json(root / "paper/campaign/schedules/primary_01.json")
    frozen_rows = {int(r["seq"]): r for r in schedule["rows"]}
    rows = [frozen_rows[s] for s in PILOT_ROW_SEQS]
    if [(int(r["input_id"]), int(r["mode"]), int(r["fixed_exit"])) for r in rows] != [
        (165, 3, 0), (165, 1, 2), (271, 1, 2), (271, 3, 0)
    ]:
        raise ValueError("primary_01 pilot row sequence differs from its frozen definition")

    dataset_path = root / "generated/heldout360.json"
    if sha(dataset_path.read_bytes()) != EXPECTED_DATASET_FILE_SHA:
        raise ValueError("frozen 360-input file SHA mismatch")
    dataset = read_json(dataset_path)
    if dataset["dataset_sha256"] != campaign["dataset_sha256"] or len(dataset["records"]) != 360:
        raise ValueError("frozen dataset identity mismatch")
    inputs = {int(r["input_id"]): r for r in dataset["records"]}

    oracle_path = root / "generated/frozen_q15_oracle.json"
    host_path = root / "evidence/native_q15_firmware/host_actual_q15_firmware.csv"
    verdict_path = root / "evidence/native_q15_firmware/native_firmware_verdict.json"
    for path, expected in ((oracle_path, EXPECTED_ORACLE_SHA), (host_path, EXPECTED_HOST_Q15_SHA),
                           (verdict_path, EXPECTED_VERDICT_SHA)):
        if sha(path.read_bytes()) != expected:
            raise ValueError(f"frozen Q15 reference SHA mismatch: {path.name}")
    oracle = read_json(oracle_path)
    verdict = read_json(verdict_path)
    if oracle["dataset_sha256"] != dataset["dataset_sha256"]:
        raise ValueError("Q15 oracle and dataset digest differ")
    if verdict["status"] != "NATIVE_Q15_FIRMWARE_MATCHES_PINNED_MODEL" or verdict["q15_predictions_sha256"] != EXPECTED_Q15_DIGEST:
        raise ValueError("pinned native Q15 reference verdict not PASS")
    host_rows = list(csv.DictReader(host_path.open(newline="", encoding="utf-8")))
    host = {(int(r["input_id"]), int(r["mode"]), int(r["param"])): r for r in host_rows}

    manifest = read_json(firmware_manifest)
    if manifest["build_id"] != f"{EXPECTED_BUILD_ID:08x}" or manifest["model_id"] != "52544e4e":
        raise ValueError("candidate firmware build/model identity mismatch")
    if sha(elf.read_bytes()) != manifest["elf_sha256"]:
        raise ValueError("firmware ELF SHA does not match manifest")
    if sha(sof.read_bytes()) != EXPECTED_SO_F_SHA:
        raise ValueError("physical-run SOF SHA mismatch")

    output_rows = []
    for r in rows:
        seq, iid, mode = int(r["seq"]), int(r["input_id"]), int(r["mode"])
        pixels = bytes(inputs[iid]["pixels_u8_64"])
        if len(pixels) != 64:
            raise ValueError(f"invalid pixel width for input {iid}")
        if mode == 1:
            param, fixed_exit, budget = 2, 2, 65535
        elif mode == 3:
            param, fixed_exit, budget = 20, 0, int(r["budget_q16"])
            if budget != 65535:
                raise ValueError("pilot adaptive row must preserve frozen full-budget setting")
        else:
            raise ValueError(f"unsupported frozen pilot mode {mode}")
        ref = host[(iid, mode, param)]
        expected = {k: int(ref[k]) for k in ("admitted_exit", "executed_exit", "prediction", "stop_reason")}
        oracle_pred = oracle["predictions"][str(iid)]
        wanted_prediction = oracle_pred["predictions"][2] if mode == 1 else oracle_pred["predictions"][oracle_pred["preferred_exit"]]
        if expected["prediction"] != wanted_prediction:
            raise ValueError(f"host Q15 / oracle mismatch for input {iid}, mode {mode}")
        if mode == 3 and expected["executed_exit"] != oracle_pred["preferred_exit"]:
            raise ValueError(f"adaptive exit / oracle mismatch for input {iid}")
        if expected["executed_exit"] > expected["admitted_exit"]:
            raise ValueError("Q15 reference violates admitted cap")
        frame = bytearray(32)
        frame[:8] = bytes((ord("R"), ord("T"), ord("N"), ord("Q"), 1, mode, fixed_exit, 0))
        struct.pack_into("<IHHIII", frame, 8, seq, iid, budget, 0, 0x52544E4E, EXPECTED_BUILD_ID)
        struct.pack_into("<I", frame, 28, zlib.crc32(frame[:28]))
        payload_crc = zlib.crc32(pixels)
        request = bytes(frame) + pixels + struct.pack("<I", payload_crc)
        output_rows.append({
            "seq": seq, "case_kind": "C3_FROZEN_CAMPAIGN_PILOT", "slot": 0,
            "test_index": iid, "input_id": iid, "mode": mode,
            "parameter_index": param, "fixed_exit": fixed_exit, "budget_q16": budget,
            "expected_admitted": expected["admitted_exit"], "expected_executed": expected["executed_exit"],
            "expected_prediction": expected["prediction"], "expected_label": int(inputs[iid]["label"]),
            "expected_stop": expected["stop_reason"], "legacy_prediction": expected["prediction"],
            "legacy_exit": expected["executed_exit"], "legacy_admitted": expected["admitted_exit"],
            "legacy_cycles_not_fpga": "", "request_frame_hex": bytes(frame).hex(),
            "pixels_u8_64_hex": pixels.hex(), "payload_crc32": f"{payload_crc:08x}",
            "jtag_request_100b_hex": request.hex(), "jtag_request_bytes": 100,
            "jtag_request_bits": 800, "model_id": "52544e4e", "build_id": f"{EXPECTED_BUILD_ID:08x}",
            "deadline_cycles": 0,
        })

    out.mkdir(parents=True)
    case_path = out / "c3_pilot_cases.csv"
    with case_path.open("x", newline="", encoding="utf-8") as f:
        writer = csv.DictWriter(f, fieldnames=FIELDNAMES, lineterminator="\n")
        writer.writeheader()
        writer.writerows(output_rows)
    binding = {
        "schema": "rtnn-c3-jtag-pilot-binding-v1",
        "status": "FROZEN_INPUTS_VERIFIED_READY_FOR_EMPIRICAL_PILOT",
        "campaign_id": "existing_method_campaign_frozen_20261102",
        "campaign_canonical_sha256": EXPECTED_CAMPAIGN_SHA,
        "campaign_file_sha256": EXPECTED_CAMPAIGN_FILE_SHA,
        "session_id": "primary_01",
        "full_schedule_sha256": next(s["schedule_sha256"] for s in campaign["schedules"] if s["session_id"] == "primary_01"),
        "full_schedule_row_count": 720,
        "selected_frozen_schedule_sequences": list(PILOT_ROW_SEQS),
        "selected_rows": [{k: r[k] for k in ("seq", "input_id", "mode", "fixed_exit", "budget_q16", "deadline_cycles")} for r in rows],
        "pilot_case_csv_sha256": sha(case_path.read_bytes()),
        "dataset_sha256": dataset["dataset_sha256"],
        "dataset_file_sha256": EXPECTED_DATASET_FILE_SHA,
        "oracle_file_sha256": EXPECTED_ORACLE_SHA,
        "oracle_predictions_sha256": EXPECTED_Q15_DIGEST,
        "host_q15_reference_csv_sha256": EXPECTED_HOST_Q15_SHA,
        "host_q15_reference_verdict_sha256": EXPECTED_VERDICT_SHA,
        "model_id": "52544e4e",
        "build_id": f"{EXPECTED_BUILD_ID:08x}",
        "sof_sha256": EXPECTED_SO_F_SHA,
        "firmware_elf_sha256": manifest["elf_sha256"],
        "measurement_scope": campaign["measurement_scope"],
        "purpose": "engineering_pilot_only; not a schedule completion or paper result",
        "frozen_campaign_modified": False,
        "timing_claim": "empirical cycles only; no WCET or hard-deadline claim",
    }
    binding_path = out / "pilot_binding.json"
    binding_path.write_text(json.dumps(binding, indent=2) + "\n", encoding="utf-8")
    return {"status": "PILOT_CASES_PREPARED", "rows": len(output_rows),
            "input_ids": sorted({int(r["input_id"]) for r in output_rows}),
            "cases_sha256": binding["pilot_case_csv_sha256"],
            "binding_sha256": sha(binding_path.read_bytes()), "binding": binding}


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--frozen-root", type=Path, required=True)
    ap.add_argument("--out", type=Path, required=True)
    ap.add_argument("--sof", type=Path, required=True)
    ap.add_argument("--elf", type=Path, required=True)
    ap.add_argument("--firmware-manifest", type=Path, required=True)
    args = ap.parse_args()
    try:
        result = prepare(args.frozen_root, args.out, args.sof, args.elf, args.firmware_manifest)
    except (KeyError, OSError, TypeError, ValueError, json.JSONDecodeError) as exc:
        print(json.dumps({"status": "BLOCKED", "error": str(exc)}))
        return 2
    print(json.dumps(result))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
