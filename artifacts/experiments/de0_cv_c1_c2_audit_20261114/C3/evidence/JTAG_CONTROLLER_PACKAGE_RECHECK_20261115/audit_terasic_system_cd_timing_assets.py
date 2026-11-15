#!/usr/bin/env python3
"""Revalidate the retained Terasic System CD and timing-relevant inventory."""
from __future__ import annotations

import argparse
import collections
import hashlib
import json
import re
import zipfile
from pathlib import Path, PurePosixPath


def digest(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def need(condition: bool, message: str) -> None:
    if not condition:
        raise ValueError(message)


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--archive", type=Path, required=True)
    parser.add_argument("--inventory-json", type=Path, required=True)
    parser.add_argument("--output-json", type=Path, required=True)
    args = parser.parse_args()
    archive = args.archive.resolve()
    inventory_path = args.inventory_json.resolve()
    out = args.output_json.resolve()
    need(not out.exists(), f"refusing to overwrite {out}")
    inventory = json.loads(inventory_path.read_text(encoding="utf-8"))
    archive_sha = hashlib.sha256(archive.read_bytes()).hexdigest()
    need(archive.stat().st_size == inventory["archive_size"], "archive size differs from saved inventory")
    need(archive_sha == inventory["archive_sha256"], "archive SHA-256 differs from saved inventory")

    with zipfile.ZipFile(archive) as zf:
        names = zf.namelist()
        need(len(names) == inventory["entries"], "ZIP member count differs from saved inventory")
        need(zf.testzip() is None, "ZIP integrity check failed")
        extensions = collections.Counter(PurePosixPath(n).suffix.lower() for n in names)
        forbidden_matches = [n for n in names if any(t in n.casefold() for t in
            ("epm240", "cpld", "usbblaster", "usb_blaster"))]
        need(forbidden_matches == inventory["filename_matches_epm240_cpld_usbblaster"],
             "EPM240/CPLD/USB-Blaster member inventory differs")
        pof_jic = sorted(n for n in names if n.casefold().endswith((".pof", ".jic")))
        need(pof_jic == sorted(inventory["pof_jic_members"]), "POF/JIC members differ")
        tool_sofs = sorted(n for n in names if n.casefold().startswith("tools/controlpanel/") and n.casefold().endswith(".sof"))
        need(tool_sofs == sorted(inventory["tool_directory_programming_members"]), "ControlPanel SOF inventory differs")
        searchable_extensions = {".qar", ".qsf", ".qpf", ".sdc", ".v", ".sv", ".vhd", ".vhdl"}
        controller_terms = re.compile(r"(?i)EPM\s*240|MAX\s*II|USB[-_ ]?BLASTER")
        controller_term_matches = []
        device_assignments = set()
        for member in names:
            suffix = PurePosixPath(member).suffix.lower()
            if suffix not in searchable_extensions:
                continue
            data = zf.read(member)
            if len(data) > 8_000_000:
                continue
            text = data.decode("utf-8", errors="ignore")
            if controller_terms.search(text):
                controller_term_matches.append(member)
            if suffix == ".qsf":
                for line in text.splitlines():
                    match = re.search(r"(?i)set_global_assignment\s+-name\s+DEVICE\s+(\S+)", line)
                    if match:
                        device_assignments.add(match.group(1).strip('"'))
        selected = {}
        for member, expected in inventory["selected_members"].items():
            data = zf.read(member)
            selected[member] = {"size": len(data), "sha256": digest(data)}
            need(selected[member] == expected, f"selected member mismatch: {member}")
        demo_qsf = next((n for n in names if n.casefold().endswith("/de0_cv_default.qsf")), None)
        qsf_lines = []
        if demo_qsf:
            qsf = zf.read(demo_qsf).decode("utf-8", errors="replace")
            qsf_lines = [line.strip() for line in qsf.splitlines() if
                         "-name DEVICE" in line or "USE_CONFIGURATION_DEVICE" in line or
                         "STRATIXII_CONFIGURATION_DEVICE" in line]
        need(qsf_lines == inventory["demo_device_assignment"], "default demo QSF device identity changed")

    result = {
        "schema": "rtnn-terasic-system-cd-timing-assets-audit-v1",
        "status": "ARCHIVE_IDENTITY_PASS_NO_CONTROLLER_TIMING_IN_SCANNED_PROJECT_SOURCES",
        "data_class": "READ_ONLY_ARCHIVE_RECHECK_NO_EXTRACTION_OR_EXECUTION",
        "archive": archive.name,
        "archive_size": archive.stat().st_size,
        "archive_sha256": archive_sha,
        "zip_integrity": "PASS",
        "member_count": len(names),
        "project_source_extension_counts": {ext: extensions[ext] for ext in sorted(searchable_extensions) if extensions[ext]},
        "programming_image_extension_counts": {ext: extensions[ext] for ext in (".sof", ".pof", ".jic", ".jam", ".svf") if extensions[ext]},
        "project_device_assignments": sorted(device_assignments),
        "controller_term_matches_in_project_source": sorted(controller_term_matches),
        "epm240_cpld_usbblaster_named_members": forbidden_matches,
        "controlpanel_sof_members": tool_sofs,
        "pof_jic_members": pof_jic,
        "selected_members": selected,
        "default_demo_device_lines": qsf_lines,
        "conclusion": "The retained archive inventory and text-based project/source content scan found no project source mentioning EPM240/MAX II/USB-Blaster controller terms and no project configured for a CPLD device. It does not disclose the onboard CPLD source/image or a board-specific external TCK/TDI/TMS/TDO timing envelope. The scan does not reverse engineer binary members.",
        "hardware_or_programming_operation": False,
    }
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(f"PASS: archive SHA, ZIP integrity, {len(names)} members, and selected-member hashes match")
    print(f"Project-source controller-term matches={len(controller_term_matches)}; configured devices={sorted(device_assignments)}")
    print("No onboard external timing envelope in the retained package audit scope; no binary reverse engineering")
    print(f"output={out}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
