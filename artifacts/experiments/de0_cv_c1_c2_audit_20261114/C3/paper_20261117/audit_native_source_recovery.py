#!/usr/bin/env python3
"""Verify the frozen 146-source C3 v2 graph against pinned and recovered bytes."""

from __future__ import annotations

import argparse
import hashlib
import json
import re
import subprocess
from pathlib import Path

from reanalyze_c3v2_primary import C3, require

PINNED_IBEX = "7b5df75a041affe56e8c235260f98a09b3319008"
IBEX_PREFIX = "/opt/rtnn-tools/ibex/"
PROJECT_MARKER = "artifacts/experiments/de0_cv_c1_c2_audit_20261114/"


def sha256(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as f:
        for block in iter(lambda: f.read(1 << 20), b""):
            h.update(block)
    return h.hexdigest()


def git(*args: str) -> str:
    result = subprocess.run(["git", *args], capture_output=True, text=True)
    require(result.returncode == 0, f"git {' '.join(args)} failed: {result.stderr.strip()}")
    return result.stdout.strip()


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--ibex-root", type=Path, required=True)
    parser.add_argument("--recovered-source-root", type=Path, required=True)
    parser.add_argument("--output-json", type=Path, required=True)
    args = parser.parse_args()

    ibex = args.ibex_root.resolve()
    recovered_root = args.recovered_source_root.resolve()
    require((ibex / ".git").exists(), "pinned Ibex checkout missing")
    ibex_head = git("-C", str(ibex), "rev-parse", "HEAD")
    require(ibex_head == PINNED_IBEX, "pinned Ibex commit mismatch")
    require(recovered_root.is_dir(), "recovered project-source directory missing")

    evidence = C3 / "evidence/C3_MEASUREMENT_V2_RTL_REPRODUCE_20261115"
    source_list = evidence / "native_sources_v2.txt"
    manifest = evidence / "ibex_source_manifest.sha256"
    baseline = C3 / "source/measurement_protocol_v2_43334531_20261115/native_source_list_baseline.txt"
    lines = source_list.read_text(encoding="utf-8").splitlines()
    entries = manifest.read_text(encoding="utf-8").splitlines()
    require(len(lines) == len(entries) == 146, "expected 146 source entries")
    require(sha256(source_list) == "61636721b1ccbd669b52f5ee2db57e600f6c8bbe00208ae2d92725dd050ac17f", "frozen source-list SHA mismatch")
    require(sha256(baseline) == "4bddc5bd5e37cbd24015189d49e4a21677d570e5cb1c0a7c9dd503da30e6bfba", "baseline source-list SHA mismatch")

    records = []
    for index, (source, entry) in enumerate(zip(lines, entries), start=1):
        match = re.fullmatch(r"([a-f0-9]{64})  (.+)", entry)
        require(match is not None and match.group(2) == source, f"manifest/path mismatch at {index}")
        expected = match.group(1)
        if source.startswith(IBEX_PREFIX):
            path = ibex / source[len(IBEX_PREFIX):]
            kind = "pinned_external_ibex"
        else:
            require(source.startswith("/mnt/c/") and PROJECT_MARKER in source, f"unrecognized project path at {index}")
            path = recovered_root / Path(source).name
            kind = "recovered_exact_project_variant"
        require(path.is_file(), f"missing source {index}: {path}")
        actual = sha256(path)
        records.append({
            "index": index,
            "source_path_in_frozen_list": source,
            "resolved_path": str(path),
            "source_type": kind,
            "expected_sha256": expected,
            "actual_sha256": actual,
            "hash_match": actual == expected,
        })

    counts = {
        kind: sum(record["source_type"] == kind for record in records)
        for kind in sorted({record["source_type"] for record in records})
    }
    require(counts == {
        "pinned_external_ibex": 141,
        "recovered_exact_project_variant": 5,
    }, f"unexpected graph partition: {counts}")
    mismatches = [record for record in records if not record["hash_match"]]
    output = {
        "schema": "rtnn-c3v2-native-source-recovery-audit-v1",
        "status": "PASS_SOURCE_HASHES_ONLY" if not mismatches else "BLOCKED_SOURCE_HASH_MISMATCH",
        "matched_sources": len(records) - len(mismatches),
        "source_count": len(records),
        "mismatches": mismatches,
        "counts": counts,
        "frozen_source_list_sha256": sha256(source_list),
        "frozen_manifest_sha256": sha256(manifest),
        "ibex_commit": ibex_head,
        "recovered_source_root": str(recovered_root),
        "recovered_project_source_sha256": {Path(record["source_path_in_frozen_list"]).name: record["actual_sha256"] for record in records if record["source_type"] == "recovered_exact_project_variant"},
        "files": records,
        "limitations": "This verifies source bytes only. Native RTL simulation, Quartus/SOF bit identity, and board timing are separate gates.",
    }
    require(not args.output_json.exists(), "refusing to overwrite output JSON")
    args.output_json.parent.mkdir(parents=True, exist_ok=True)
    args.output_json.write_text(json.dumps(output, ensure_ascii=False, sort_keys=True, indent=2) + "\n", encoding="utf-8")
    print(f"{output['status']}: {output['matched_sources']}/{output['source_count']} source hashes match")
    if mismatches:
        raise SystemExit(2)


if __name__ == "__main__":
    main()
