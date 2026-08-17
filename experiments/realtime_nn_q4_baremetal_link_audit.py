import argparse
import hashlib
import json
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
EXP = ROOT / "experiments"

PROBE = r'''#include <stdint.h>
#include "realtime_nn_q4_i8_core.h"
static RTNNQ4I8Workspace W;
volatile int32_t RTNN_PROBE_SINK;
void rtnn_probe_run(void) {
    if (!rtnn_q4_i8_init()) { RTNN_PROBE_SINK = -1; return; }
    RTNNQ4I8Result r = rtnn_q4_i8_infer(&W, 0x155u, 4);
    RTNN_PROBE_SINK = r.logit0 ^ r.logit1;
}
#if defined(__arm__) || defined(__thumb__)
void Reset_Handler(void) { rtnn_probe_run(); for (;;) { __asm volatile("nop"); } }
__attribute__((section(".isr_vector"), used))
const uintptr_t vectors[] = { 0x20004000u, (uintptr_t)&Reset_Handler };
#else
void _start(void) { rtnn_probe_run(); for (;;) { __asm volatile("nop"); } }
#endif
'''

ARM_LD = r'''ENTRY(Reset_Handler)
MEMORY {
 FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 256K
 RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 16K
}
SECTIONS {
 .isr_vector : { KEEP(*(.isr_vector)) } > FLASH
 .text : { *(.text*) *(.rodata*) } > FLASH
 .data : { *(.data*) } > RAM AT>FLASH
 .bss (NOLOAD) : { *(.bss*) *(COMMON) } > RAM
}
'''

RV_LD = r'''ENTRY(_start)
MEMORY {
 FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 256K
 RAM (rwx) : ORIGIN = 0x20000000, LENGTH = 16K
}
SECTIONS {
 .text : { *(.text*) *(.rodata*) } > FLASH
 .data : { *(.data*) } > RAM AT>FLASH
 .bss (NOLOAD) : { *(.bss*) *(COMMON) } > RAM
}
'''

TARGETS = {
    "cortex_m0": (["--target=armv6m-none-eabi", "-mcpu=cortex-m0", "-mthumb"], "arm.ld"),
    "cortex_m4_soft": (["--target=armv7em-none-eabi", "-mcpu=cortex-m4", "-mthumb", "-mfloat-abi=soft"], "arm.ld"),
    "rv32im": (["--target=riscv32-unknown-elf", "-march=rv32im", "-mabi=ilp32"], "rv.ld"),
    "rv32i_negative": (["--target=riscv32-unknown-elf", "-march=rv32i", "-mabi=ilp32"], "rv.ld"),
}


def run(cmd, check=True):
    return subprocess.run(cmd, check=check, text=True, capture_output=True)


def sha256(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--seed", type=int, default=0)
    ap.add_argument("--out", default=str(ROOT / "results" / "realtime_nn_q4_baremetal_link_results.json"))
    args = ap.parse_args()
    clang = shutil.which("clang")
    objcopy = shutil.which("llvm-objcopy")
    size_tool = shutil.which("llvm-size") or shutil.which("size")
    if not clang or not objcopy or not shutil.which("nm") or not size_tool:
        raise SystemExit("requires clang, llvm-objcopy, nm, and size/llvm-size")

    with tempfile.TemporaryDirectory(prefix="rtnn_bare_") as td0:
        td = Path(td0)
        generated = td / "realtime_nn_q4_i8_generated.h"
        run([sys.executable, str(EXP / "export_realtime_nn_q4_i8_header.py"), "--seed", str(args.seed), "--out", str(generated)])
        (td / "probe.c").write_text(PROBE)
        (td / "arm.ld").write_text(ARM_LD)
        (td / "rv.ld").write_text(RV_LD)

        rows = {}
        for name, (flags, ldname) in TARGETS.items():
            elf = td / f"{name}.elf"
            cmd = [clang, *flags, "-O2", "-std=c11", "-ffreestanding", "-fno-builtin", "-nostdlib", "-fuse-ld=lld", f"-I{td}", f"-I{EXP}", str(EXP / "realtime_nn_q4_i8_core.c"), str(td / "probe.c"), f"-Wl,-T,{td / ldname}", "-Wl,--gc-sections", "-Wl,--build-id=none", "-o", str(elf)]
            proc = run(cmd, check=False)
            if proc.returncode != 0:
                rows[name] = {"link_ok": False, "stderr": proc.stderr.strip(), "requires_mul_helper": "__mulsi3" in proc.stderr}
                continue
            undef = [x.strip() for x in run(["nm", "-u", str(elf)], check=False).stdout.splitlines() if x.strip()]
            raw = td / f"{name}.bin"
            run([objcopy, "-O", "binary", str(elf), str(raw)])
            size_lines = run([size_tool, str(elf)]).stdout.strip().splitlines()
            fields = size_lines[-1].split()
            rows[name] = {
                "link_ok": True,
                "undefined_symbols": undef,
                "undefined_symbol_count": len(undef),
                "elf_sha256": sha256(elf),
                "binary_bytes": raw.stat().st_size,
                "sections_bytes": {"text": int(fields[0]), "data": int(fields[1]), "bss": int(fields[2])},
            }

        out = {
            "setup": {
                "seed": args.seed,
                "compiler": run([clang, "--version"]).stdout.splitlines()[0],
                "linker": "LLD via -fuse-ld=lld",
                "common": ["-O2", "-std=c11", "-ffreestanding", "-fno-builtin", "-nostdlib", "--gc-sections", "--build-id=none"],
                "linker_memory_model": {"flash_bytes": 262144, "ram_bytes": 16384},
                "runtime_execution_claim": False,
            },
            "targets": rows,
            "aggregate": {
                "linked_helper_free": [k for k, v in rows.items() if v.get("link_ok") and v.get("undefined_symbol_count") == 0],
                "rv32i_link_fails_on_mul_helper": (not rows["rv32i_negative"].get("link_ok")) and rows["rv32i_negative"].get("requires_mul_helper", False),
            },
            "interpretation": {
                "supported": "The Q4 core and a minimal startup/probe can be statically linked without libc/crt into bare-metal ELF images for Cortex-M0, Cortex-M4 soft-float, and RV32IM under the tested Clang/LLD setup. RV32I fails to link because __mulsi3 is unresolved.",
                "not_supported": ["hardware execution", "correct startup/data initialization on a production board", "RTOS integration", "target latency or WCET"],
            },
        }
        Path(args.out).write_text(json.dumps(out, indent=2))
        print(json.dumps(out["aggregate"], indent=2))


if __name__ == "__main__":
    main()
