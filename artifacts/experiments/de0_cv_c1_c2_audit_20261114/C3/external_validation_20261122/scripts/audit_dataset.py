#!/usr/bin/env python3
"""Audit official UCI optdigits.tra against sklearn.load_digits, then lock IDs.

Selection is based only on dataset SHA, source row, and pixel bytes. Labels and
model outputs do not affect pilot/primary selection.
"""
from __future__ import annotations

import argparse
import csv
import hashlib
import json
import struct
import sys
from collections import Counter, defaultdict
from pathlib import Path

import numpy as np
import sklearn
from sklearn.datasets import load_digits


HERE = Path(__file__).resolve().parents[1]
DEFAULT_TRA = HERE / "downloads" / "uci_package_contents" / "optdigits.tra"
DEFAULT_TES = HERE / "downloads" / "uci_package_contents" / "optdigits.tes"
OUT = HERE / "data"


def sha256(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def parse_uci(path: Path) -> tuple[list[bytes], list[int]]:
    pixels: list[bytes] = []
    labels: list[int] = []
    for line_no, raw in enumerate(path.read_text(encoding="ascii").splitlines(), 1):
        if not raw.strip():
            continue
        fields = [x.strip() for x in raw.split(",")]
        if len(fields) != 65:
            raise ValueError(f"{path}:{line_no}: expected 65 integers, got {len(fields)}")
        values = [int(x) for x in fields]
        pix, label = values[:64], values[64]
        if any(v < 0 or v > 16 for v in pix) or not 0 <= label <= 9:
            raise ValueError(f"{path}:{line_no}: pixel/label out of range")
        pixels.append(bytes(pix))
        labels.append(label)
    return pixels, labels


def write_csv(path: Path, rows: list[dict]) -> None:
    if not rows:
        path.write_text("", encoding="utf-8")
        return
    with path.open("w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=list(rows[0]))
        w.writeheader()
        w.writerows(rows)


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--tra", type=Path, default=DEFAULT_TRA)
    ap.add_argument("--tes", type=Path, default=DEFAULT_TES)
    ap.add_argument("--out", type=Path, default=OUT)
    ap.add_argument("--pilot-count", type=int, default=10)
    args = ap.parse_args()
    args.out.mkdir(parents=True, exist_ok=True)

    raw_tra = args.tra.read_bytes()
    raw_tes = args.tes.read_bytes()
    tra, tra_y = parse_uci(args.tra)
    tes, tes_y = parse_uci(args.tes)
    d = load_digits()
    sk_x = np.asarray(d.data, dtype=np.uint8)
    sk_y = np.asarray(d.target, dtype=np.uint8)
    if sk_x.shape != (1797, 64) or sk_y.shape != (1797,):
        raise ValueError(f"unexpected sklearn load_digits shape: {sk_x.shape}, {sk_y.shape}")
    sk_pixels = [row.tobytes() for row in sk_x]
    # Directly validate that the official UCI test split is the exact loader data.
    test_pixel_exact = sum(a == b for a, b in zip(tes, sk_pixels)) if len(tes) == len(sk_pixels) else -1
    test_label_exact = sum(a == int(b) for a, b in zip(tes_y, sk_y)) if len(tes_y) == len(sk_y) else -1
    if test_pixel_exact != 1797 or test_label_exact != 1797:
        raise ValueError(f"UCI test vs sklearn mismatch: pixels={test_pixel_exact}, labels={test_label_exact}")

    sk_set = set(sk_pixels)
    sk_positions: dict[bytes, list[int]] = defaultdict(list)
    for j, p in enumerate(sk_pixels):
        sk_positions[p].append(j)
    overlap_rows = [i for i, p in enumerate(tra) if p in sk_set]

    by_pixels: dict[bytes, list[int]] = defaultdict(list)
    for i, p in enumerate(tra):
        by_pixels[p].append(i)
    duplicate_rows: dict[int, str] = {}
    dup_groups = 0
    conflict_groups = 0
    for p, ids in by_pixels.items():
        if len(ids) < 2:
            continue
        dup_groups += 1
        labels = {tra_y[i] for i in ids}
        if len(labels) > 1:
            conflict_groups += 1
            for i in ids:
                duplicate_rows[i] = "duplicate_pixels_conflicting_labels"
        else:
            for i in ids[1:]:
                duplicate_rows[i] = f"duplicate_pixels_same_label_kept_row_{ids[0]+1}"

    overlap_set = set(overlap_rows)
    eligible = [i for i in range(len(tra)) if i not in overlap_set and i not in duplicate_rows]
    tra_sha = sha256(raw_tra)

    def selection_key(i: int) -> str:
        material = b"RTNN-EXTVAL-PILOT-v1\0" + bytes.fromhex(tra_sha) + struct.pack("<I", i + 1) + tra[i]
        return sha256(material)

    ordered = sorted(eligible, key=lambda i: (selection_key(i), i))
    pilot_ids = set(ordered[: args.pilot_count])
    primary_ids = [i for i in eligible if i not in pilot_ids]
    if len(pilot_ids) != args.pilot_count:
        raise ValueError(f"need {args.pilot_count} eligible pilot rows, found {len(pilot_ids)}")

    audit = {
        "schema": "rtnn-external-uci-optdigits-audit-v1",
        "download_source": "https://archive.ics.uci.edu/static/public/80/optical+recognition+of+handwritten+digits.zip",
        "sklearn_version": sklearn.__version__,
        "optdigits_tra_sha256": tra_sha,
        "optdigits_tra_bytes_sha256": sha256(raw_tra),
        "optdigits_tes_sha256": sha256(raw_tes),
        "optdigits_tra_records": len(tra),
        "optdigits_tes_records": len(tes),
        "pixel_features_per_row": 64,
        "pixel_min": min(min(p) for p in tra),
        "pixel_max": max(max(p) for p in tra),
        "tra_class_counts": {str(k): v for k, v in sorted(Counter(tra_y).items())},
        "tes_class_counts": {str(k): v for k, v in sorted(Counter(tes_y).items())},
        "sklearn_load_digits_records": len(sk_pixels),
        "official_tes_pixel_exact_matches_sklearn": test_pixel_exact,
        "official_tes_label_exact_matches_sklearn": test_label_exact,
        "tra_rows_matching_any_sklearn_pixel_image": len(overlap_rows),
        "tra_internal_duplicate_pixel_groups": dup_groups,
        "tra_internal_duplicate_rows_excluded": len(duplicate_rows),
        "tra_conflicting_label_duplicate_groups": conflict_groups,
        "eligibility_rule": "exclude every exact pixel overlap with sklearn.load_digits; for same-label internal duplicate pixels keep the lowest source row and exclude others; if duplicate pixels have conflicting labels exclude the whole group",
        "pilot_selection": "lowest SHA256(RTNN-EXTVAL-PILOT-v1\\0 || raw-tra-SHA256-bytes || uint32le(source-row-1-based) || 64-pixel-bytes); selection does not use label or inference output",
        "pilot_count": len(pilot_ids),
        "primary_candidate_count": len(primary_ids),
        "minimum_primary_gate": 3000,
        "primary_completeness_gate": "PASS" if len(primary_ids) >= 3000 else "FAIL",
        "pixel_flattened_sha256_sklearn_1797": sha256(b"".join(sk_pixels)),
        "label_bytes_sha256_sklearn_1797": sha256(bytes(int(x) for x in sk_y)),
    }
    (args.out / "dataset_audit.json").write_text(json.dumps(audit, indent=2) + "\n", encoding="utf-8")
    (args.out / "ORIGINAL_1797_PIXEL_SHA256.txt").write_text(
        f"sha256={audit['pixel_flattened_sha256_sklearn_1797']}\n"
        f"records=1797\nfeatures=64\norder=sklearn.datasets.load_digits row-major uint8 flattened\n"
        f"sklearn_version={sklearn.__version__}\n",
        encoding="utf-8",
    )

    excluded = []
    for i, reason in duplicate_rows.items():
        excluded.append({"source_row": i + 1, "label": tra_y[i], "pixel_sha256": sha256(tra[i]), "reason": reason})
    for i in overlap_rows:
        excluded.append({"source_row": i + 1, "label": tra_y[i], "pixel_sha256": sha256(tra[i]), "reason": "exact_pixel_overlap_sklearn_load_digits"})
    excluded.sort(key=lambda r: (r["source_row"], r["reason"]))
    write_csv(args.out / "excluded_rows.csv", excluded)

    all_rows = []
    for i, p in enumerate(tra):
        if i in overlap_set:
            partition, reason = "excluded", "exact_pixel_overlap_sklearn_load_digits"
        elif i in duplicate_rows:
            partition, reason = "excluded", duplicate_rows[i]
        elif i in pilot_ids:
            partition, reason = "engineering_pilot", "sha256_selection_rule"
        else:
            partition, reason = "primary_candidate", "eligible_after_overlap_and_duplicate_audit"
        all_rows.append({
            "input_id": i + 1,
            "uci_source_row": i + 1,
            "label_host_only": tra_y[i],
            "pixel_sha256": sha256(p),
            "selection_sha256": selection_key(i) if i in eligible else "",
            "partition": partition,
            "exclusion_reason": reason,
        })
    write_csv(args.out / "image_manifest_all_rows.csv", all_rows)

    pilot_rows = [r for r in all_rows if r["partition"] == "engineering_pilot"]
    pilot_rows.sort(key=lambda r: r["selection_sha256"])
    primary_rows = [r for r in all_rows if r["partition"] == "primary_candidate"]
    primary_rows.sort(key=lambda r: int(r["input_id"]))
    write_csv(args.out / "pilot_manifest.csv", pilot_rows)
    write_csv(args.out / "primary_manifest.csv", primary_rows)
    (args.out / "pilot_inputs.bin").write_bytes(b"".join(tra[int(r["uci_source_row"]) - 1] for r in pilot_rows))
    (args.out / "primary_inputs.bin").write_bytes(b"".join(tra[int(r["uci_source_row"]) - 1] for r in primary_rows))
    print(json.dumps(audit, indent=2))
    return 0 if audit["primary_completeness_gate"] == "PASS" else 3


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except Exception as exc:
        print(f"DATASET_AUDIT_FAIL: {exc}", file=sys.stderr)
        raise
