#!/usr/bin/env python3
"""Audit expected C2 bundled-data D101 inventory and paired post-fit paths.

This script inventories warnings; it does not waive them or assert CDC signoff.
"""
from __future__ import annotations

import argparse
import json
import re
from pathlib import Path

PATH_ROW = re.compile(r"^;\s*([0-9]+\.[0-9]+)\s*;\s*(.*?)\s*;\s*(.*?)\s*;\s*$")


def path_rows(path: Path) -> dict[str, tuple[str, float]]:
    rows: dict[str, tuple[str, float]] = {}
    for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
        match = PATH_ROW.match(line)
        if match:
            delay, source, destination = match.groups()
            rows[destination.strip()] = (source.strip(), float(delay))
    return rows


def audit(drc_path: Path, report_dir: Path) -> dict:
    drc = drc_path.read_text(encoding="utf-8", errors="replace")
    count_match = re.search(
        r"Found (\d+) asynchronous clock domain interface structure\(s\) related to this rule",
        drc,
    )
    if not count_match or int(count_match.group(1)) != 801:
        raise ValueError("D101 structure count changed; review the new DRC inventory")

    request_sources = {
        int(value)
        for value in re.findall(
            r'Source node\(s\) from clock "altera_reserved_tck"\s*;\s*'
            r'rtnn_c2_vjtag_mailbox:u_mailbox\|req_hold_tck_q\[(\d+)\]',
            drc,
        )
    }
    request_destinations = {
        int(value)
        for value in re.findall(
            r'Destination node\(s\) from clock "CLOCK_50"\s*;\s*'
            r'rtnn_c2_vjtag_mailbox:u_mailbox\|request_data_o\[(\d+)\]',
            drc,
        )
    }
    # The DRC prints full source/destination detail only for the first 30
    # structures, then a compact Structure N -> source-node inventory.
    compact_structures = re.findall(
        r"^;\s*Structure\s+(\d+)\s*;\s*([^;]+?)\s*;\s*$",
        drc,
        flags=re.MULTILINE,
    )
    compact_request_bits = {
        int(bit)
        for _number, node in compact_structures
        if re.search(r"req_hold_tck_q\[(\d+)\]", node)
        for bit in re.findall(r"req_hold_tck_q\[(\d+)\]", node)
    }
    request_sources |= compact_request_bits
    expected_request_bits = set(range(800))
    if request_sources != expected_request_bits:
        raise ValueError(
            "D101 request structure inventory changed: "
            f"source={len(request_sources)} (detailed={len(request_destinations)})"
        )
    detailed_pairs = set(zip(
        (int(x) for x in re.findall(
            r'Source node\(s\) from clock "altera_reserved_tck"\s*;\s*'
            r'rtnn_c2_vjtag_mailbox:u_mailbox\|req_hold_tck_q\[(\d+)\]', drc)),
        (int(x) for x in re.findall(
            r'Destination node\(s\) from clock "CLOCK_50"\s*;\s*'
            r'rtnn_c2_vjtag_mailbox:u_mailbox\|request_data_o\[(\d+)\]', drc)),
    ))
    if len(detailed_pairs) != len(request_destinations) or any(a != b for a, b in detailed_pairs):
        raise ValueError("detailed D101 request source/destination pairs are inconsistent")
    response_representatives = re.findall(
        r";\s*Structure 801\s*;\s*"
        r"(rtnn_de0_cv_soc_c2:u_soc\|response_words_q\[11\]\[31\])\s*;",
        drc,
    )
    if not response_representatives:
        raise ValueError("D101 response structure 801 representative changed")

    corners = []
    for corner in range(4):
        bundles = {}
        for bundle, width in (("req", 800), ("rsp", 384)):
            maximum = path_rows(report_dir / f"c2_allcorners_path_{bundle}_{corner}.rpt")
            minimum = path_rows(report_dir / f"c2_minpath_{bundle}_{corner}.rpt")
            if len(maximum) != width or len(minimum) != width:
                raise ValueError(
                    f"corner {corner} {bundle}: max/min path coverage "
                    f"{len(maximum)}/{len(minimum)}, expected {width}/{width}"
                )
            if maximum.keys() != minimum.keys():
                raise ValueError(f"corner {corner} {bundle}: endpoint set mismatch")
            spreads = []
            source_mismatches = 0
            for destination, (source, max_delay) in maximum.items():
                min_source, min_delay = minimum[destination]
                source_mismatches += source != min_source
                spreads.append(max_delay - min_delay)
            if source_mismatches:
                raise ValueError(f"corner {corner} {bundle}: {source_mismatches} source mismatches")
            bundles[bundle] = {
                "max_paths": len(maximum),
                "min_paths": len(minimum),
                "source_destination_mismatches": source_mismatches,
                "max_per_endpoint_data_path_spread_ns": round(max(spreads), 3),
            }
        corners.append({"corner_index": corner, **bundles})

    return {
        "status": "PASS_INVENTORY_AND_PATH_COVERAGE_ONLY",
        "d101_structure_count": 801,
        "request_d101_source_bits": 800,
        "request_d101_detailed_pairs": len(detailed_pairs),
        "request_d101_compact_source_inventory_bits": len(compact_request_bits),
        "response_d101_representative": response_representatives[0],
        "corners": corners,
        "not_a_waiver": True,
        "cdc_signoff": False,
        "limitations": [
            "D101 remains present and is not suppressed by this audit.",
            "Response D101 row is a representative node, not a count of response payload endpoints.",
            "Paired min/max data-path spread is not a capture-window proof.",
            "Unconstrained JTAG-related I/O remains a separate open timing gate.",
        ],
    }


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--drc", type=Path, required=True)
    parser.add_argument("--report-dir", type=Path, required=True)
    parser.add_argument("--out", type=Path, required=True)
    args = parser.parse_args()
    result = audit(args.drc, args.report_dir)
    args.out.write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(result, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
