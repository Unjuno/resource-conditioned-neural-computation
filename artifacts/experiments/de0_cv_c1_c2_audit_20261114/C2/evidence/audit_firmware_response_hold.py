#!/usr/bin/env python3
"""Audit C2 response payload stability until the JTAG host consumes it."""
from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path


EXPECTED = {
    "firmware": "a6964666d08695bdc447f2315b1683c90a08750a76db1188cb8d8669428cc917",
    "soc": "9fbc58508e023f05c8dba59d085ef7cf673a04b7d9e9a6b0d6cc18dd0ca5acdc",
    "mailbox": "b4107f64666f27f798be25ba013a15a7f993c9d5bde07b7f9fa241ca498871d0",
    "flat": "fdfcdf037eb55225e3e6eef06b01fc92e608951c54ece946461408131f2e5ca7",
}


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as source:
        for block in iter(lambda: source.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest()


def require(ok: bool, detail: str) -> None:
    if not ok:
        raise ValueError(detail)


def audit(evidence: Path) -> dict:
    source_dir = evidence / "firmware_response_hold_20261114"
    build = evidence / "candidate_firmware_build"
    quartus = evidence / "quartus_d101"
    graph = evidence / "c3_gate_a_recheck_20261114"

    firmware = source_dir / "rtnn_c2_main.c"
    soc = source_dir / "rtnn_de0_cv_soc_c2.sv"
    mailbox = source_dir / "rtnn_c2_vjtag_mailbox.sv"
    flat = quartus / "rtnn_c2_soc_flat.v"
    manifest_path = build / "c2_firmware_manifest.json"
    native_hashes = (graph / "candidate_native_source_sha256.txt").read_text(encoding="utf-8")
    recovered_hashes = (graph / "C3_BUNDLED_CAPTURE_EVIDENCE_SHA256.txt").read_text(encoding="utf-8")

    actual = {"firmware": sha256(firmware), "soc": sha256(soc),
              "mailbox": sha256(mailbox), "flat": sha256(flat)}
    for name, expected in EXPECTED.items():
        require(actual[name] == expected, f"{name} SHA-256 mismatch: {actual[name]}")

    manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
    require(manifest["build_id"] == "43324a32", "firmware manifest build ID mismatch")
    require(manifest["source_sha256"]["firmware/rtnn_c2_main.c"] == EXPECTED["firmware"],
            "C2 firmware source is not the source recorded by the firmware manifest")
    require(f"{EXPECTED['soc']}  " in native_hashes and "rtnn_de0_cv_soc_c2.sv" in native_hashes,
            "SoC source hash is not present in the recovered 146-source graph manifest")
    require(f"{EXPECTED['mailbox']}  rtnn_c2_vjtag_mailbox_final_candidate.sv" in recovered_hashes,
            "mailbox source hash is not present in the Gate A recovered-artifact manifest")

    fw = firmware.read_text(encoding="utf-8")
    soc_text = soc.read_text(encoding="utf-8")
    mbx = mailbox.read_text(encoding="utf-8")
    flat_text = flat.read_text(encoding="utf-8")

    request_copy = fw.index("uint32_t w = *mmio(C2_REQ_WORDS")
    request_ack = fw.index("*mmio(C2_REQ_ACK) = 1u;")
    inference = fw.index("rtnn_fw_execute(&req, &rsp, &cfg)")
    response_store = fw.index("store_response(&rsp);")
    store_fn = fw[fw.index("static void store_response("):fw.index("static void response_error(")]
    store_words = store_fn.index("C2_RSP_WORDS + i * 4u")
    commit = store_fn.index("C2_RSP_COMMIT")
    require(request_copy < request_ack < inference < response_store,
            "firmware no longer copies request before ack and executes before response")
    require(store_words < commit and "C2_RESPONSE_BYTES / 4u" in store_fn,
            "firmware response-word writes are not followed by the final commit")

    update_start = mbx.index("if (ir_i == IR_REQUEST) begin", mbx.index("if (update_dr_i)"))
    update_end = mbx.index("req_shift_count_tck_q <= 11'b0;", update_start)
    request_gate = mbx[update_start:update_end]
    for fragment in ("!response_pending_tck_q", "!busy_sync2_tck_q",
                     "!done_sync2_tck_q", "req_hold_tck_q <= req_shift_tck_q"):
        require(fragment in request_gate, f"JTAG request gate missing {fragment}")
    consume = mbx.index("rsp_consume_toggle_tck_q <= ~rsp_consume_toggle_tck_q")
    consume_context = mbx[mbx.rfind("if (ir_i == IR_RESPONSE", 0, consume):consume]
    require("rsp_shift_count_tck_q == 11'd384" in consume_context
            and "response_pending_tck_q" in consume_context,
            "response consume is not guarded by a complete 384-bit pending scan")
    require("rsp_consume_sync2_sys_q == rsp_toggle_sys_q && done_sys_q" in mbx,
            "system side does not clear DONE after synchronized response consume")

    require("jtag_request_accept_o <= 1'b1" in soc_text
            and "response_byte_written_q" in soc_text
            and "response_commit_match" in soc_text,
            "SoC MMIO ack/response commit guard not found")
    for lane in range(4):
        name = f"rtnn_ram_lane{lane}.hex"
        expected = manifest["lane_sha256"][name]
        candidate_lane = build / name
        quartus_lane = quartus / name
        require(sha256(candidate_lane) == expected, f"firmware {name} hash mismatch")
        require(sha256(quartus_lane) == expected, f"Quartus {name} differs from firmware image")
        require(f'$readmemh("{name}"' in flat_text, f"flat RTL does not load {name}")

    return {
        "audit": "C2_FIRMWARE_RESPONSE_SOURCE_HOLD",
        "status": "PASS_STATIC_IDENTITY_AND_PROTOCOL_ORDER",
        "build_id": manifest["build_id"],
        "source_sha256": actual,
        "firmware_elf_sha256": manifest["elf_sha256"],
        "firmware_manifest_sha256": sha256(manifest_path),
        "quartus_ram_lanes_match_firmware": True,
        "protocol_findings": [
            "Firmware copies request words before acknowledging the request, then computes and writes the 48-byte response before the final commit write.",
            "The captured Gate A mailbox source matches its recovered source-manifest hash; it rejects a new request while a response is pending, busy, or done.",
            "A response consume toggle is emitted only after a pending 384-bit response scan; the system side clears DONE only after the consume toggle is synchronized.",
            "All four Quartus RAM lane images match the hashed C2 firmware build lane images loaded by the exact flat RTL.",
        ],
        "limitations": [
            "This is a static source/identity audit, not a formal proof or a metastability probability bound.",
            "The SLD hub TCK domain remains intentionally asynchronous; this static check does not provide phase-based inter-clock setup/hold or skew. External board-level JTAG I/O timing remains unclosed.",
        ],
        "gate_b_effect": "firmware response-source hold condition is supported for this build; Gate B remains BLOCKED on the board-level external JTAG timing envelope.",
    }


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--evidence", type=Path, default=Path(__file__).resolve().parent)
    parser.add_argument("--output", type=Path)
    args = parser.parse_args()
    result = audit(args.evidence.resolve())
    text = json.dumps(result, indent=2) + "\n"
    if args.output:
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_text(text, encoding="utf-8", newline="\n")
    print(text, end="")
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except (OSError, ValueError, KeyError, TypeError) as error:
        print(json.dumps({"status": "FAIL", "error": str(error)}, indent=2))
        raise SystemExit(1)
