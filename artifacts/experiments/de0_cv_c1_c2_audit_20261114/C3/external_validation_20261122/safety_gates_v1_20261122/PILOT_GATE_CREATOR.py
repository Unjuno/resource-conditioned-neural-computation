#!/usr/bin/env python3
"""Production CLI for recomputing and writing a pilot evidence gate."""
import sys
from pathlib import Path
sys.path.insert(0,str(Path(__file__).resolve().parent))
from pilot_gate import main
if __name__=="__main__":
    if "--create" not in sys.argv: sys.argv.insert(1,"--create")
    raise SystemExit(main())
