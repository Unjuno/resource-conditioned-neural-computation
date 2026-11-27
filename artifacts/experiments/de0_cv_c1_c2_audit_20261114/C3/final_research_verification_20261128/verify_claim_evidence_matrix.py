#!/usr/bin/env python3
"""Fail-closed existence and containment check for CLAIM_EVIDENCE_MATRIX.csv."""

from __future__ import annotations

import argparse
import csv
from pathlib import Path


EXPECTED_STATUS = {"C6": "NOT_RUN", "C7": "INELIGIBLE", "C8": "BLOCKED"}
REQUIRED_COLUMNS = {
    "claim_id", "claim", "evidence", "status", "allowed_wording", "not_supported"
}


def validate(matrix_path: Path, repo_root: Path) -> list[str]:
    repo_root = repo_root.resolve(strict=True)
    c3_root = matrix_path.resolve(strict=True).parent.parent
    matrix_root = matrix_path.resolve(strict=True).parent
    errors: list[str] = []
    with matrix_path.open("r", encoding="utf-8-sig", newline="") as stream:
        reader = csv.DictReader(stream)
        if not reader.fieldnames or not REQUIRED_COLUMNS.issubset(reader.fieldnames):
            raise ValueError("claim matrix is missing required columns")
        for row_number, row in enumerate(reader, start=2):
            claim_id = (row.get("claim_id") or "").strip()
            evidence = (row.get("evidence") or "").strip()
            if not claim_id or not evidence:
                errors.append(f"row {row_number}: empty claim_id or evidence")
                continue
            expected = EXPECTED_STATUS.get(claim_id)
            if expected and row.get("status", "").strip() != expected:
                errors.append(
                    f"row {row_number} {claim_id}: status must remain {expected}"
                )
            for raw_path in evidence.split(";"):
                raw_path = raw_path.strip().strip("`")
                candidate = Path(raw_path)
                if not raw_path or candidate.is_absolute() or ":" in raw_path:
                    errors.append(f"row {row_number} {claim_id}: not a repo-relative path: {raw_path!r}")
                    continue
                if ".." in candidate.parts:
                    errors.append(f"row {row_number} {claim_id}: evidence escapes repository: {raw_path}")
                    continue
                roots = (repo_root, c3_root, matrix_root)
                targets = []
                for base in roots:
                    target = (base / candidate).resolve(strict=False)
                    try:
                        target.relative_to(repo_root)
                    except ValueError:
                        continue
                    targets.append(target)
                if not any(target.is_file() for target in targets):
                    errors.append(f"row {row_number} {claim_id}: evidence file missing: {raw_path}")
    return errors


def main() -> int:
    here = Path(__file__).resolve().parent
    repo_root = here.parents[4]
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--matrix", type=Path, default=here / "CLAIM_EVIDENCE_MATRIX.csv"
    )
    args = parser.parse_args()
    errors = validate(args.matrix, repo_root)
    if errors:
        for error in errors:
            print(f"FAIL: {error}")
        return 1
    with args.matrix.open("r", encoding="utf-8-sig", newline="") as stream:
        count = sum(1 for _ in csv.DictReader(stream))
    print(f"PASS: {count} claims; all evidence entries resolve within repository")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
