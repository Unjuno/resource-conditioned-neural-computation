#!/usr/bin/env python3
"""Exercise actual Tcl runner with independent wire fixtures; never hardware."""
from __future__ import annotations

import argparse
import csv
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import zlib

CASE_SHA = "52b7fdae7c465fd4b6409876e258e00fbaad5656e93ad3b9fb79f2f8741aec5d"


def response(row: dict[str, str], scenario: str) -> str:
    data = bytearray(48)
    data[:4] = b"RTNR"
    data[4:8] = bytes((1, 0, int(row["mode"]), int(row["expected_stop"])))
    seq = int(row["seq"])
    struct.pack_into("<IHHI", data, 8, seq, int(row["input_id"]),
                     int(row["budget_q16"]), int(row["deadline_cycles"]))
    data[20:24] = bytes(int(row[k]) for k in (
        "expected_admitted", "expected_executed", "expected_prediction", "expected_label"))
    struct.pack_into("<III", data, 24, 1000 + seq, 0x52544E4E, 0x43324A32)
    if scenario == "wrong_prediction":
        data[22] = (data[22] + 1) % 10
    if scenario == "wrong_id":
        struct.pack_into("<I", data, 8, seq + 100)
    if scenario == "zero_cycles":
        struct.pack_into("<I", data, 24, 0)
    struct.pack_into("<I", data, 44, zlib.crc32(data[:44]))
    if scenario == "bad_crc":
        data[44] ^= 1
    return data[::-1].hex()


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--tclsh", required=True)
    ap.add_argument("--runner", type=Path, required=True)
    ap.add_argument("--cases", type=Path, required=True)
    ap.add_argument("--out", type=Path, required=True)
    args = ap.parse_args()
    assert hashlib.sha256(args.cases.read_bytes()).hexdigest() == CASE_SHA
    args.out.mkdir(parents=True, exist_ok=False)
    with args.cases.open(newline="", encoding="utf-8") as f:
        rows = {int(r["seq"]): r for r in csv.DictReader(f)}
    driver = Path(__file__).with_name("mock_c2_host_wire.tcl")
    results = []
    tests = [
        ("all_42", "ALL", "normal", list(range(1, 43)), True),
        ("single_frozen_2", "2", "normal", [2], True),
        ("fixed_and_adaptive", "2,27,34", "normal", [2, 27, 34], True),
        ("wrong_prediction", "ALL", "wrong_prediction", [1], False),
        ("wrong_id", "ALL", "wrong_id", [1], False),
        ("bad_crc", "ALL", "bad_crc", [1], False),
        ("zero_cycles", "ALL", "zero_cycles", [1], False),
        ("timeout", "ALL", "timeout", [1], False),
        ("bad_build", "ALL", "bad_build", [], False),
        ("no_hardware", "ALL", "no_hardware", [], False),
        ("ambiguous_hardware", "ALL", "ambiguous_hardware", [], False),
        ("duplicate_selection", "2,2", "normal", [], False),
        ("outside_selection", "43", "normal", [], False),
        ("non_integer_selection", "2,x", "normal", [], False),
    ]
    for name, selection, scenario, requested, success in tests:
        out = args.out / name
        out.mkdir()
        fixture = out / "mock_wire_fixture.txt"
        fixture_seqs = requested or [1]
        frames = {s: response(rows[s], scenario) for s in fixture_seqs}
        fixture.write_text("\n".join(
            f"{s}|{bytes.fromhex(rows[s]['jtag_request_100b_hex'])[::-1].hex()}|{frames[s]}"
            for s in fixture_seqs) + "\n", encoding="ascii")
        command = [args.tclsh, str(driver), str(args.runner), str(args.cases),
                   str(out), "a" * 64, "HOST_MOCK_" + name, str(fixture), selection, scenario]
        p = subprocess.run(command, capture_output=True, text=True, timeout=25)
        (out / "stdout.log").write_text(p.stdout, encoding="utf-8")
        (out / "stderr.log").write_text(p.stderr, encoding="utf-8")
        (out / "command.json").write_text(json.dumps(
            {"argv": command, "cwd": str(Path.cwd()), "exit_code": p.returncode,
             "physical_jtag": False, "cycles": "synthetic"}, indent=2), encoding="utf-8")
        try:
            assert (p.returncode == 0) == success, f"unexpected exit {p.returncode}: {p.stderr}"
            trace = (out / "mock_transport.log").read_text().splitlines()
            got = [int(t.split()[1]) for t in trace if t.startswith("REQUEST ")]
            assert got == requested, f"requests {got}, wanted {requested}"
            if not requested:
                if scenario != "bad_build":
                    assert "OPEN" not in trace, "opened device for invalid selection/ambiguous target"
            else:
                report = json.loads((out / "c2_jtag_results.json").read_text())
                assert report["status"] == ("PASS" if success else "FAIL")
                with (out / "c2_jtag_results.csv").open(newline="") as f:
                    csv_rows = list(csv.DictReader(f))
                assert len(report["cases"]) == len(csv_rows) == len(requested)
                if success:
                    assert report["expected_count"] == len(requested)
                    assert report["selected_sequences"] == requested
                    assert report["scope"] == ("all_frozen_42" if selection == "ALL" else "subset")
                    for observed, s in zip(report["cases"], requested):
                        assert observed["seq"] == observed["response_seq"] == s
                        assert observed["prediction"] == int(rows[s]["expected_prediction"])
                        assert observed["cycles"] == 1000 + s and observed["cycle_valid"] is True
                        assert observed["response_lsb_hex"] == frames[s]
                else:
                    observed = report["cases"][-1]
                    assert observed["cycle_valid"] is False and observed["cycles"] is None
                    if scenario == "timeout":
                        assert observed["prediction"] is None, "unobserved prediction fabricated"
                        assert csv_rows[-1]["prediction"] == ""
                    else:
                        raw = (out / "c2_jtag_raw.log").read_text()
                        assert frames[1] in raw, "failed raw response not saved"
                        assert observed["response_lsb_hex"] == frames[1]
                        assert observed["response_crc_valid"] == (scenario != "bad_crc")
                    if scenario == "wrong_prediction":
                        assert observed["prediction"] == (int(rows[1]["expected_prediction"]) + 1) % 10
                        assert int(csv_rows[-1]["prediction"]) == observed["prediction"]
                    if scenario == "wrong_id":
                        assert observed["seq"] == 1 and observed["response_seq"] == 101
            results.append({"name": name, "status": "PASS"})
            print(f"PASS {name}")
        except (AssertionError, KeyError, ValueError, OSError) as exc:
            results.append({"name": name, "status": "FAIL", "error": str(exc)})
            print(f"FAIL {name}: {exc}")
    (args.out / "summary.json").write_text(json.dumps(
        {"physical_jtag": False, "cycle_source": "synthetic_host_fixture",
         "cases_sha256": CASE_SHA, "runner_sha256": hashlib.sha256(args.runner.read_bytes()).hexdigest(),
         "results": results}, indent=2) + "\n", encoding="utf-8")
    return int(any(r["status"] != "PASS" for r in results))


if __name__ == "__main__":
    raise SystemExit(main())
