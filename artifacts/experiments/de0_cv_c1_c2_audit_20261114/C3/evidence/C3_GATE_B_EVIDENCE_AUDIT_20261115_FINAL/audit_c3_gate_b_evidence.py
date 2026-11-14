#!/usr/bin/env python3
"""Read-only consistency audit for the preserved C3 v2 timing evidence."""
from __future__ import annotations

import argparse
import hashlib
import json
import re
import sys
from pathlib import Path


EXPECTED_SETUP_NS = [1.803, 1.887, 10.027, 11.154]
EXPECTED_HOLD_NS = [0.259, 0.242, 0.134, 0.124]


def sha256(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            h.update(block)
    return h.hexdigest()


def read(path: Path) -> str:
    return path.read_text(encoding="utf-8", errors="replace")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--repo", type=Path, required=True, help="verified research repository root")
    parser.add_argument("--output", type=Path, required=True, help="new evidence output directory")
    args = parser.parse_args()

    repo = args.repo.resolve()
    out = args.output.resolve()
    if out.exists():
        raise SystemExit(f"refusing to overwrite existing output: {out}")
    c3 = repo / "artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3"
    build = c3 / "evidence/C3_MEASUREMENT_V2_QUARTUS_RETRY02_20261115"
    sta = c3 / "evidence/C3_MEASUREMENT_V2_STA_RETRY03_20261115"
    rv32 = c3 / "evidence/C3_MEASUREMENT_V2_RV32_BUILD_20261115"
    model_header = repo / "artifacts/experiments/de0_cv_c1_c2_audit_20261114/C2/evidence/candidate_firmware_build/realtime_nn_real_sequence_fixed_weights_generated.h"
    frozen = c3 / "frozen_inputs"
    bound = c3 / "evidence/C3_MEASUREMENT_V2_PHYSICAL_PREP_20261115/campaign_sof_bound_v2"
    source = c3 / "source/measurement_protocol_v2_43334531_20261115"
    sessions = ["diagnostic_fixed", "diagnostic_adaptive", "diagnostic_capped"] + [f"primary_{i:02}" for i in range(1, 11)]

    evidence_paths = [
        build / name
        for name in (
            "rtnn_c3_measurement_v2.qsf",
            "rtnn_c3_measurement_v2.sdc",
            "rtnn_c3_measurement_v2.sof",
            "rtnn_c3_measurement_v2_quartus_flat.v",
            "rtnn_c2_global_buf.v",
            "rtnn_ram_lane0.hex",
            "rtnn_ram_lane1.hex",
            "rtnn_ram_lane2.hex",
            "rtnn_ram_lane3.hex",
            "quartus_compile.log",
            "quartus_compile.exitcode",
            "quartus_drc_postfit.log",
            "quartus_drc_postfit.exitcode",
            "rtnn_c3_measurement_v2.fit.summary",
            "rtnn_c3_measurement_v2.sta.summary",
            "rtnn_c3_measurement_v2.drc.rpt",
            "rtnn_c3_measurement_v2.asm.rpt",
            "warning_counts.txt",
        )
    ] + [
        rv32 / name
        for name in (
            "rtnn_c3_measurement_v2.elf",
            "rtnn_c3_measurement_v2.bin",
            "build_manifest.json",
            "fpga_b_image_manifest.json",
        )
    ] + [
        frozen / name
        for name in (
            "paper/campaign/campaign.json",
            "generated/heldout360.json",
            "generated/frozen_q15_oracle.json",
            "evidence/native_q15_firmware/host_actual_q15_firmware.csv",
            "evidence/native_q15_firmware/native_firmware_verdict.json",
        )
    ] + [model_header] + [
        bound / session / "binding.json" for session in sessions
    ] + [
        source / name
        for name in ("rtnn_c2_vjtag_mailbox.sv", "rtnn_de0_cv_soc_c2.sv",
                     "rtnn_de0_cv_c2_top.sv", "native_source_list_baseline.txt")
    ] + [
        sta / name
        for name in (
            "run_c3_v2_allcorners_sta_retry03.tcl",
            "quartus_sta.log",
            "exitcode.txt",
            "c3_v2_retry03_clocks.rpt",
            "c3_v2_retry03_unconstrained_paths.rpt",
            "cdc_bus_path_delay_summary.txt",
        )
    ] + [
        sta / f"c3_v2_retry03_{kind}_{corner}.rpt"
        for kind in ("setup", "hold")
        for corner in range(4)
    ]

    missing = [str(path) for path in evidence_paths if not path.is_file()]
    if missing:
        raise SystemExit("missing evidence inputs:\n" + "\n".join(missing))

    build_manifest = json.loads(read(rv32 / "build_manifest.json"))
    actual_sof_sha = sha256(build / "rtnn_c3_measurement_v2.sof")
    actual_elf_sha = sha256(rv32 / "rtnn_c3_measurement_v2.elf")
    actual_bin_sha = sha256(rv32 / "rtnn_c3_measurement_v2.bin")
    actual_model_sha = sha256(model_header)
    actual_host_sha = sha256(frozen / "evidence/native_q15_firmware/host_actual_q15_firmware.csv")
    rtl_hashes = {name: sha256(source / name) for name in (
        "rtnn_c2_vjtag_mailbox.sv", "rtnn_de0_cv_soc_c2.sv", "rtnn_de0_cv_c2_top.sv")}
    source_list_sha = sha256(source / "native_source_list_baseline.txt")
    assert rtl_hashes == {
        "rtnn_c2_vjtag_mailbox.sv": "7cc0cb69bfddf4309f3b95370ce7c0e06b99e235eb8204b40816f40ff0f719d1",
        "rtnn_de0_cv_soc_c2.sv": "0902a2b9db68fbc27c4aa155b5fb43025a46529b519850c78e7386694d6d19af",
        "rtnn_de0_cv_c2_top.sv": "c6d602e252f8e4f472cd79237f241becc9bdecb535d4ceba88d8bfbcecfe3265",
    }
    assert source_list_sha == "4bddc5bd5e37cbd24015189d49e4a21677d570e5cb1c0a7c9dd503da30e6bfba"
    expected_lanes = build_manifest["ram_lane_sha256"]
    assert actual_sof_sha == "85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d"
    assert actual_elf_sha == "9cbf537bd9440deaf5c78abf6b204da9cbcd2fe3795acf444d733dbd581002b6"
    assert actual_bin_sha == "d55d2db36d835825b1e23d385f9e4c7555c9200c2f2656bbc4ec649530b2ae53"
    assert actual_model_sha == "961a76b7e220bf2f665e7c04ab62063600aa2e7eccf3403d80ea730bc993ad9f"
    assert actual_host_sha == "1f9b08987a9d7368b663f604eb1dce6e077073e099552532468509c846d6bdc8"
    assert build_manifest["build_id"] == "43334531" and build_manifest["elf_sha256"] == actual_elf_sha
    assert build_manifest["bin_sha256"] == actual_bin_sha
    assert {name: sha256(rv32 / name) for name in expected_lanes} == expected_lanes
    campaign = json.loads(read(frozen / "paper/campaign/campaign.json"))
    assert len(campaign["schedules"]) == 13
    assert campaign["model_seed"] == 63 and f"{campaign['model_id']:08x}" == "52544e4e"
    assert campaign["unique_accuracy_inputs"] == 360 and campaign["q15_predictions_sha256"] == "03eb958cfa8b4fd2f71a95fb47dbca512820c237c281473817bba685b92c743e"
    expected_schedules = {item["session_id"]: item for item in campaign["schedules"]}
    assert set(expected_schedules) == set(sessions)
    assert sha256(frozen / "paper/campaign/campaign.json") == "3d97a1cd87395e294299cacb617474367c89a9295355cd25fb1b4fa67464c936"
    assert sha256(frozen / "generated/heldout360.json") == "eeba9000a918bcba911007e78905c5052fc743422f95cb314a0fc9f4ecdfb14c"
    assert sha256(frozen / "generated/frozen_q15_oracle.json") == "4e1a3ddcabe1884b1607c77d19b10da8a86d53da3f4c060c30d7449635ec3cf4"
    q15_verdict = json.loads(read(frozen / "evidence/native_q15_firmware/native_firmware_verdict.json"))
    assert q15_verdict["status"] == "NATIVE_Q15_FIRMWARE_MATCHES_PINNED_MODEL"
    assert q15_verdict["q15_predictions_sha256"] == "03eb958cfa8b4fd2f71a95fb47dbca512820c237c281473817bba685b92c743e"
    binding_identities = []
    for session in sessions:
        binding = json.loads(read(bound / session / "binding.json"))
        expected_schedule = expected_schedules[session]
        assert binding["session_id"] == session
        assert binding["schedule_canonical_sha256"] == expected_schedule["schedule_sha256"]
        assert binding["record_count"] == expected_schedule["record_count"]
        assert binding["campaign_canonical_sha256"] == "d6c98f59c0c0afe32d0877c01c8411fba8bf3e2a5c8058c5a85371f7f648a8dc"
        assert binding["campaign_file_sha256"] == "3d97a1cd87395e294299cacb617474367c89a9295355cd25fb1b4fa67464c936"
        assert binding["dataset_file_sha256"] == "eeba9000a918bcba911007e78905c5052fc743422f95cb314a0fc9f4ecdfb14c"
        assert binding["oracle_file_sha256"] == "4e1a3ddcabe1884b1607c77d19b10da8a86d53da3f4c060c30d7449635ec3cf4"
        assert binding["host_q15_file_sha256"] == actual_host_sha
        assert binding["sof_sha256"] == actual_sof_sha and binding["firmware_elf_sha256"] == actual_elf_sha
        assert binding["ram_lane_sha256"] == expected_lanes
        assert binding["rtl_snapshot_sha256"] == {
            "mailbox": rtl_hashes["rtnn_c2_vjtag_mailbox.sv"],
            "soc": rtl_hashes["rtnn_de0_cv_soc_c2.sv"],
            "wrapper": rtl_hashes["rtnn_de0_cv_c2_top.sv"],
        }
        assert binding["native_source_list_sha256"] == source_list_sha
        assert binding["model_id"] == "52544e4e" and binding["build_id"] == "43334531"
        assert binding["frozen_schedule_modified"] is False and binding["timing_classification"] == "EMPIRICAL_ONLY"
        assert binding["wcet_or_hard_deadline_claimed"] is False
        assert binding["measurement_eligible"] is True
        binding_identities.append({"session_id": session, "record_count": binding["record_count"],
                                  "binding_sha256": sha256(bound / session / "binding.json")})
    assert sum(x["record_count"] for x in binding_identities) == 24840

    sdc = read(build / "rtnn_c3_measurement_v2.sdc")
    false_paths = [line.strip() for line in sdc.splitlines() if line.strip().startswith("set_false_path")]
    net_delays = [line.strip() for line in sdc.splitlines() if line.strip().startswith("set_net_delay")]
    assert "create_clock -name CLOCK_50 -period 20.000" in sdc
    assert len(false_paths) == 2 and all("KEY[0]" in line for line in false_paths)
    assert len(net_delays) == 2 and all("-max 16.000" in line for line in net_delays)
    assert all("req_hold_tck_q" in line or "response_words_q" in line for line in net_delays)
    assert all("req_bus_sync1_sys_q" in line or "rsp_bus_sync1_tck_q" in line for line in net_delays)

    timing_reports = []
    for corner in range(4):
        for kind, expected in (("setup", EXPECTED_SETUP_NS[corner]), ("hold", EXPECTED_HOLD_NS[corner])):
            path = sta / f"c3_v2_retry03_{kind}_{corner}.rpt"
            match = re.search(
                rf"Report Timing: Found (\d+) {kind} paths \((\d+) violated\)\.\s*Worst case slack is ([0-9.]+)",
                read(path),
            )
            assert match, f"unrecognized {kind} report header: {path.name}"
            count, violated, slack = int(match[1]), int(match[2]), float(match[3])
            assert count == 20 and violated == 0 and abs(slack - expected) < 1e-9
            timing_reports.append({"corner_index": corner, "kind": kind, "reported_paths": count,
                                   "violated_paths": violated, "worst_slack_ns": slack})

    unconstrained = read(sta / "c3_v2_retry03_unconstrained_paths.rpt")
    for row, expected in (("Unconstrained Input Ports", 2), ("Unconstrained Input Port Paths", 41),
                          ("Unconstrained Output Ports", 4), ("Unconstrained Output Port Paths", 8)):
        match = re.search(rf"{re.escape(row)}\s*;\s*(\d+)\s*;\s*(\d+)\s*;", unconstrained)
        assert match and int(match[1]) == expected and int(match[2]) == expected, f"unexpected {row}"
    for port in ("altera_reserved_tdi", "altera_reserved_tms", "altera_reserved_tdo", "LEDR[0]", "LEDR[1]", "LEDR[3]"):
        assert port in unconstrained, f"unconstrained port not named in report: {port}"

    clocks = read(sta / "c3_v2_retry03_clocks.rpt")
    assert re.search(r"altera_reserved_tck\s*;\s*Base\s*;\s*33\.333\s*;\s*30\.0 MHz", clocks)
    assert re.search(r"CLOCK_50\s*;\s*Base\s*;\s*20\.000\s*;\s*50\.0 MHz", clocks)

    cdc_text = read(sta / "cdc_bus_path_delay_summary.txt")
    cdc = []
    for line in cdc_text.splitlines():
        match = re.fullmatch(r"corner=(\d+) bus=(req|rsp) n=(\d+) min_ns=([0-9.]+) max_ns=([0-9.]+) spread_ns=([0-9.]+)", line.strip())
        if match:
            corner, bus, count = int(match[1]), match[2], int(match[3])
            max_ns = float(match[5])
            assert max_ns <= 16.000
            assert count == (800 if bus == "req" else 480)
            cdc.append({"corner_index": corner, "bus": bus, "path_count": count,
                        "min_ns": float(match[4]), "max_ns": max_ns, "spread_ns": float(match[6])})
    assert len(cdc) == 8

    drc = read(build / "rtnn_c3_measurement_v2.drc.rpt")
    assert "Found 16 asynchronous clock domain interface structure(s) related to this rule." in drc
    assert "Rule D102" in drc
    assert (build / "quartus_compile.exitcode").read_text(encoding="ascii").strip() == "0"
    assert (sta / "exitcode.txt").read_text(encoding="ascii").strip() == "0"

    out.mkdir(parents=True)
    result = {
        "schema": "rtnn-c3-gate-b-evidence-audit-v1",
        "classification": {
            "B_SIGNOFF": "BLOCKED_EXTERNAL_JTAG_TIMING_AND_UNCONSTRAINED_IO",
            "internal_sta": "PASS_FOR_REPORTED_CONSTRAINED_PATHS_ONLY",
            "cdc": "16_D102_WARNINGS_RETAINED; 16NS_INTERNAL_SCREEN_WITHIN_LIMIT",
            "B_EMPIRICAL": "PASS_LIMITED_NOT_A_TIMING_WCET_OR_DEADLINE_GUARANTEE",
        },
        "device": "Cyclone V 5CEBA4F23C7N",
        "build_id": "43334531",
        "sof_sha256": actual_sof_sha,
        "elf_sha256": actual_elf_sha,
        "bin_sha256": actual_bin_sha,
        "q15_weights_header_sha256": actual_model_sha,
        "host_q15_reference_sha256": actual_host_sha,
        "q15_prediction_digest": q15_verdict["q15_predictions_sha256"],
        "rtl_snapshot_sha256": rtl_hashes,
        "native_source_list_sha256": source_list_sha,
        "campaign_schedule_bindings": {"count": len(binding_identities), "record_count_total": sum(x["record_count"] for x in binding_identities),
                                       "identities": binding_identities},
        "timing_reports": timing_reports,
        "unconstrained": {
            "input_ports": 2, "input_paths": 41,
            "output_ports": 4, "output_paths": 8,
            "ports": ["altera_reserved_tdi", "altera_reserved_tms", "altera_reserved_tdo",
                      "LEDR[0]", "LEDR[1]", "LEDR[3]"],
        },
        "clock_models": {"CLOCK_50_period_ns": 20.0,
                          "altera_reserved_tck_period_ns": 33.333,
                          "note": "Quartus generated clock model; not a measurement of the physical onboard USB-Blaster."},
        "sdc_exceptions": false_paths,
        "bundled_data_screen": {"limit_ns": 16.0, "paths": cdc},
        "d102_unwaived_structure_count": 16,
        "source_evidence_sha256": {str(p.relative_to(repo)).replace("\\", "/"): sha256(p)
                                    for p in evidence_paths},
        "evidence_file_count": len(evidence_paths),
        "quartus_compile_exit": 0,
        "timequest_script_exit": 0,
        "scope_limit": "This consistency audit validates preserved report values and file identity. It does not repair missing external timing constraints, prove CDC metastability/MTBF, or establish board timing signoff.",
    }
    result_path = out / "gate_b_audit.json"
    result_path.write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    (out / "SHA256SUMS.txt").write_text(f"{sha256(result_path)}  gate_b_audit.json\n", encoding="ascii")
    print(f"PASS: {len(evidence_paths)} inputs hashed; 13 campaign bindings identity-matched; 4 setup/hold corners parsed; 16 CDC structures retained")
    print(f"B-SIGNOFF=BLOCKED; B-EMPIRICAL=PASS_LIMITED")
    print(f"output={result_path}")
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except AssertionError as exc:
        print(f"FAIL: {exc}", file=sys.stderr)
        raise SystemExit(1)
