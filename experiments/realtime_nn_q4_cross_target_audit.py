import argparse
import hashlib
import json
import re
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
EXP = ROOT / "experiments"

TARGETS = {
    "cortex_m0": ["--target=armv6m-none-eabi", "-mcpu=cortex-m0", "-mthumb"],
    "cortex_m4_soft": ["--target=armv7em-none-eabi", "-mcpu=cortex-m4", "-mthumb", "-mfloat-abi=soft"],
    "rv32im": ["--target=riscv32-unknown-elf", "-march=rv32im", "-mabi=ilp32"],
    "rv32i_negative": ["--target=riscv32-unknown-elf", "-march=rv32i", "-mabi=ilp32"],
}

FLOAT_RE = re.compile(r"\b(?:v(?:add|sub|mul|div|ldr|str|mov|cvt)|f(?:add|sub|mul|div|lw|sw|mv|cvt))", re.I)
DIV_RE = re.compile(r"\b(?:sdiv|udiv|div|divu|rem|remu)\b", re.I)


def run(cmd, cwd=None, check=True):
    return subprocess.run(cmd, cwd=cwd, check=check, text=True, capture_output=True)


def sha256(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def nm_undefined(path):
    proc = run(["nm", "-u", str(path)], check=False)
    return [line.strip() for line in proc.stdout.splitlines() if line.strip()]


def object_size(path):
    tool = shutil.which("llvm-size") or shutil.which("size")
    if not tool:
        return None
    proc = run([tool, str(path)])
    lines = [x for x in proc.stdout.splitlines() if x.strip()]
    if len(lines) < 2:
        return None
    fields = lines[-1].split()
    return {"text": int(fields[0]), "data": int(fields[1]), "bss": int(fields[2])}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--seed", type=int, default=0)
    ap.add_argument("--out", default=str(ROOT / "results" / "realtime_nn_q4_cross_target_results.json"))
    args = ap.parse_args()

    clang = shutil.which("clang")
    objdump = shutil.which("llvm-objdump")
    if not clang or not objdump or not shutil.which("nm"):
        raise SystemExit("requires clang, llvm-objdump, and nm")

    with tempfile.TemporaryDirectory(prefix="rtnn_cross_") as td:
        td = Path(td)
        generated = td / "realtime_nn_q4_i8_generated.h"
        run([sys.executable, str(EXP / "export_realtime_nn_q4_i8_header.py"), "--seed", str(args.seed), "--out", str(generated)])

        rows = {}
        for name, target_flags in TARGETS.items():
            objects = []
            for rep in (1, 2):
                obj = td / f"{name}_{rep}.o"
                cmd = [clang, *target_flags, "-O2", "-std=c11", "-ffreestanding", "-fno-builtin", f"-I{td}", f"-I{EXP}", "-c", str(EXP / "realtime_nn_q4_i8_core.c"), "-o", str(obj)]
                run(cmd)
                objects.append(obj)

            dis = run([objdump, "-d", str(objects[0])]).stdout
            undefined = nm_undefined(objects[0])
            rows[name] = {
                "target_flags": target_flags,
                "sha256": sha256(objects[0]),
                "repeat_compile_byte_identical": objects[0].read_bytes() == objects[1].read_bytes(),
                "undefined_symbols": undefined,
                "undefined_symbol_count": len(undefined),
                "object_sections_bytes": object_size(objects[0]),
                "float_instruction_pattern_count": len(FLOAT_RE.findall(dis)),
                "div_rem_instruction_pattern_count": len(DIV_RE.findall(dis)),
            }

        out = {
            "setup": {
                "seed": args.seed,
                "compiler": run([clang, "--version"]).stdout.splitlines()[0],
                "source": "experiments/realtime_nn_q4_i8_core.c",
                "compile_common": ["-O2", "-std=c11", "-ffreestanding", "-fno-builtin"],
                "timing_claim": False,
            },
            "targets": rows,
            "aggregate": {
                "helper_free_targets": [k for k, v in rows.items() if v["undefined_symbol_count"] == 0],
                "rv32i_requires_mul_helper": any("__mulsi3" in x for x in rows["rv32i_negative"]["undefined_symbols"]),
                "all_helper_free_targets_repeat_compile_byte_identical": all(v["repeat_compile_byte_identical"] for k, v in rows.items() if k != "rv32i_negative"),
                "all_helper_free_targets_no_float_instruction_patterns": all(v["float_instruction_pattern_count"] == 0 for k, v in rows.items() if k != "rv32i_negative"),
                "all_helper_free_targets_no_div_rem_instruction_patterns": all(v["div_rem_instruction_pattern_count"] == 0 for k, v in rows.items() if k != "rv32i_negative"),
            },
            "interpretation": {
                "supported": "The Q4 integer inference core cross-compiles as a self-contained freestanding object for Cortex-M0, Cortex-M4 soft-float, and RV32IM with this Clang build. RV32I without the M extension introduces an external __mulsi3 dependency, exposing a target capability boundary.",
                "not_supported": ["successful linking/booting on a real RTOS target", "target WCET", "cross-target functional execution", "universal compiler portability"],
            },
        }
        Path(args.out).write_text(json.dumps(out, indent=2))
        print(json.dumps(out["aggregate"], indent=2))


if __name__ == "__main__":
    main()
