#!/usr/bin/env python3
"""Extract the named mailbox module verbatim from the retained Quartus-flat RTL."""
from __future__ import annotations

import argparse
from pathlib import Path


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--flat-rtl", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    source = args.flat_rtl.read_text(encoding="utf-8")
    marker = "module rtnn_c2_vjtag_mailbox ("
    if source.count(marker) != 1:
        raise SystemExit(f"expected one {marker!r}, found {source.count(marker)}")
    start = source.index(marker)
    end_marker = "endmodule"
    end = source.find(end_marker, start)
    if end < 0:
        raise SystemExit("mailbox module has no endmodule")
    module = source[start : end + len(end_marker)] + "\n"
    if "req_capture_pending_sys_q" not in module or "rsp_capture_pending_tck_q" not in module:
        raise SystemExit("flat mailbox is missing capture-pending state")
    if args.output.exists():
        raise SystemExit(f"refusing to overwrite {args.output}")
    args.output.write_text(module, encoding="utf-8", newline="\n")
    print(f"PASS_EXTRACTED {marker} bytes={len(module.encode('utf-8'))}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
