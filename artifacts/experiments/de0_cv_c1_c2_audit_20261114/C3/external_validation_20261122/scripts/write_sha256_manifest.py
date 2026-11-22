#!/usr/bin/env python3
"""Hash the external-validation package, excluding rebuildable caches only."""
from hashlib import sha256
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / "SHA256SUMS.txt"
EXCLUDED_DIRS = {"obj_dir", "db", "incremental_db", "__pycache__"}
lines = []
for path in sorted(ROOT.rglob("*")):
    if not path.is_file() or path == OUT:
        continue
    parts = path.relative_to(ROOT).parts
    if any(part in EXCLUDED_DIRS for part in parts):
        continue
    # Verilator attempt-specific auxiliary object directories are also
    # rebuildable caches (for example ``commit_guard_obj``).
    if any(part.endswith("_obj") or part.endswith("_obj_dir") for part in parts):
        continue
    digest = sha256(path.read_bytes()).hexdigest()
    lines.append(f"{digest}  {path.relative_to(ROOT).as_posix()}")
# The checked-in package manifest is intentionally stored with CRLF. Keep that
# format even when regenerating after a previous run used a different newline.
newline = "\r\n"
with OUT.open("w", encoding="ascii", newline="") as stream:
    stream.write(newline.join(lines) + newline)
print(f"SHA256_MANIFEST_WRITTEN files={len(lines)} path={OUT}")
