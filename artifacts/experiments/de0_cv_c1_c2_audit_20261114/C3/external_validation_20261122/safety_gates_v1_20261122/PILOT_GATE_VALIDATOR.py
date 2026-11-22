#!/usr/bin/env python3
"""Production CLI for independently verifying a pilot gate/binding."""
import sys
from pathlib import Path
sys.path.insert(0,str(Path(__file__).resolve().parent))
from pilot_gate import main
if __name__=="__main__":
    if not any(x in sys.argv for x in ("--verify-gate","--verify-binding")):
        print("supply --verify-gate or --verify-binding",file=sys.stderr);raise SystemExit(2)
    raise SystemExit(main())
