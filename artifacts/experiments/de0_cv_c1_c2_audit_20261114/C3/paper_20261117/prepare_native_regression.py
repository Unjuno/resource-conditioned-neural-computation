#!/usr/bin/env python3
"""Prepare an exact source-mapped C3 v2 Verilator run in a clean clone."""

from __future__ import annotations

import argparse
import hashlib
import json
import re
import shutil
from pathlib import Path

PINNED_IBEX = "7b5df75a041affe56e8c235260f98a09b3319008"
IBEX_PREFIX = "/opt/rtnn-tools/ibex/"
EVIDENCE_REL = Path(
    "artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/evidence/"
    "C3_MEASUREMENT_V2_RTL_REPRODUCE_20261115"
)
PAPER_REL = Path(
    "artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/paper_20261117"
)

RUNTIME_INPUTS = (
    "c2_expected.hex",
    "c2_requests.hex",
    "rtnn_ram_lane0.hex",
    "rtnn_ram_lane1.hex",
    "rtnn_ram_lane2.hex",
    "rtnn_ram_lane3.hex",
    "tb_rtnn_c2_response_write_guard.sv",
    "tb_rtnn_c2_soc_42.sv",
    "run_native_v2_regression.sh",
    "verify_and_run.sh",
)


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for chunk in iter(lambda: stream.read(1 << 20), b""):
            digest.update(chunk)
    return digest.hexdigest()


def run() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--repo-root", type=Path, required=True)
    parser.add_argument("--ibex-root", type=Path, required=True)
    parser.add_argument("--output-dir", type=Path, required=True)
    args = parser.parse_args()

    repo = args.repo_root.resolve()
    ibex = args.ibex_root.resolve()
    output = args.output_dir.resolve()
    paper = repo / PAPER_REL
    evidence = repo / EVIDENCE_REL
    archive = paper / "source_recovery_20261122"
    seed_run = archive / "native_regression_run1"
    if output.exists():
        raise SystemExit(f"refusing to overwrite existing output: {output}")
    if not (ibex / ".git").exists():
        raise SystemExit(f"Ibex checkout missing: {ibex}")
    import subprocess

    head = subprocess.check_output(
        ["git", "-C", str(ibex), "rev-parse", "HEAD"], text=True
    ).strip()
    if head != PINNED_IBEX:
        raise SystemExit(f"Ibex commit mismatch: {head}")

    source_list = evidence / "native_sources_v2.txt"
    source_manifest = evidence / "ibex_source_manifest.sha256"
    sources = source_list.read_text(encoding="utf-8").splitlines()
    manifest = source_manifest.read_text(encoding="utf-8").splitlines()
    if len(sources) != 146 or len(manifest) != 146:
        raise SystemExit("expected the frozen 146-entry native source graph")
    if sha256(source_list) != "61636721b1ccbd669b52f5ee2db57e600f6c8bbe00208ae2d92725dd050ac17f":
        raise SystemExit("frozen source-list SHA-256 mismatch")

    resolved: list[tuple[str, Path, str]] = []
    for index, (original, item) in enumerate(zip(sources, manifest), 1):
        match = re.fullmatch(r"([a-f0-9]{64})  (.+)", item)
        if not match or match.group(2) != original:
            raise SystemExit(f"frozen source manifest/path mismatch at {index}")
        expected = match.group(1)
        if original.startswith(IBEX_PREFIX):
            path = ibex / original[len(IBEX_PREFIX):]
            kind = "pinned_ibex"
        else:
            path = archive / Path(original).name
            kind = "recovered_project_source"
        if not path.is_file() or sha256(path) != expected:
            raise SystemExit(f"source SHA mismatch at {index}: {path}")
        resolved.append((expected, path, kind))

    output.mkdir(parents=True)
    for name in RUNTIME_INPUTS:
        shutil.copy2(seed_run / name, output / name)
    shutil.copy2(source_list, output / "native_sources_v2_frozen.txt")
    shutil.copy2(source_manifest, output / "ibex_source_manifest.sha256")

    mapped_sources = [path.as_posix() for _, path, _ in resolved]
    (output / "native_sources_v2.txt").write_text(
        "\n".join(mapped_sources) + "\n", encoding="utf-8", newline="\n"
    )
    (output / "source_manifest_exact.sha256").write_text(
        "\n".join(f"{digest}  {path}" for (digest, path, _) in resolved) + "\n",
        encoding="utf-8",
        newline="\n",
    )
    runner = (output / "run_native_v2_regression.sh").read_text(encoding="utf-8")
    runner = runner.replace(IBEX_PREFIX.rstrip("/"), ibex.as_posix())
    (output / "run_native_v2_regression.sh").write_text(
        runner, encoding="utf-8", newline="\n"
    )
    mapping = {
        "schema": "rtnn-c3v2-clean-clone-regression-map-v1",
        "repo_head": subprocess.check_output(
            ["git", "-C", str(repo), "rev-parse", "HEAD"], text=True
        ).strip(),
        "ibex_head": head,
        "source_count": len(resolved),
        "counts": {
            "pinned_ibex": sum(kind == "pinned_ibex" for _, _, kind in resolved),
            "recovered_project_source": sum(kind == "recovered_project_source" for _, _, kind in resolved),
        },
        "frozen_source_list_sha256": sha256(source_list),
        "entries": [
            {
                "sha256": digest,
                "resolved_path": str(path),
                "kind": kind,
            }
            for digest, path, kind in resolved
        ],
    }
    (output / "SOURCE_MAP.json").write_text(
        json.dumps(mapping, ensure_ascii=False, indent=2, sort_keys=True) + "\n",
        encoding="utf-8",
    )
    (output / ".gitignore").write_text(
        "obj_v2_42/\nobj_v2_guard/\n", encoding="ascii", newline="\n"
    )
    print(
        f"PREPARED: {len(resolved)} sources; "
        f"{mapping['counts']['pinned_ibex']} pinned Ibex + "
        f"{mapping['counts']['recovered_project_source']} recovered project sources"
    )


if __name__ == "__main__":
    run()
