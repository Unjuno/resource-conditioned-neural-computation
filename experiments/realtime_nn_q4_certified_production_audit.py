import argparse
import json
import re
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

import realtime_nn_q4_baremetal_link_audit as bare
import realtime_nn_q4_branchless_audit as branch_audit

ROOT = Path(__file__).resolve().parents[1]
EXP = ROOT / "experiments"


def run(cmd, check=True):
    return subprocess.run(cmd, check=check, text=True, capture_output=True)


def parse_certificate_header(text):
    def value(name):
        m = re.search(rf"#define {name} \(?(-?\d+)\)?", text)
        if not m:
            raise ValueError(f"missing {name}")
        return int(m.group(1))
    return {
        "certified": "#define RTNN_Q_LUT_RANGE_CERTIFIED 1" in text,
        "effective_input_bits": value("RTNN_Q_CERT_EFFECTIVE_INPUT_BITS"),
        "effective_input_states": value("RTNN_Q_CERT_EFFECTIVE_INPUT_STATES"),
        "tanh_pre": [value("RTNN_Q_CERT_TANH_PRE_MIN"), value("RTNN_Q_CERT_TANH_PRE_MAX")],
        "gelu_pre": [value("RTNN_Q_CERT_GELU_PRE_MIN"), value("RTNN_Q_CERT_GELU_PRE_MAX")],
        "residual_tanh_pre": [value("RTNN_Q_CERT_RESIDUAL_PRE_MIN"), value("RTNN_Q_CERT_RESIDUAL_PRE_MAX")],
    }


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--out", default=str(ROOT / "results" / "realtime_nn_q4_certified_production_results.json"))
    args = ap.parse_args()

    gcc = shutil.which("gcc")
    clang = shutil.which("clang")
    objdump = shutil.which("llvm-objdump")
    objcopy = shutil.which("llvm-objcopy")
    nm = shutil.which("nm")
    size_tool = shutil.which("llvm-size") or shutil.which("size")
    if not all((gcc, clang, objdump, objcopy, nm, size_tool)):
        raise SystemExit("requires gcc, clang, llvm-objdump, llvm-objcopy, nm, and size")

    with tempfile.TemporaryDirectory(prefix="rtnn_q4_prod_cert_") as td0:
        td = Path(td0)
        (td / "check.c").write_text(branch_audit.CHECK_C)
        (td / "probe.c").write_text(bare.PROBE)
        (td / "arm.ld").write_text(bare.ARM_LD)
        (td / "rv.ld").write_text(bare.RV_LD)

        seed_rows = []
        for seed in range(3):
            generated = td / "realtime_nn_q4_i8_generated.h"
            export_run = run([
                sys.executable, str(EXP / "export_realtime_nn_q4_i8_header.py"),
                "--seed", str(seed), "--out", str(generated)
            ])
            certificate = parse_certificate_header(generated.read_text())
            obj = td / f"prod_{seed}.o"
            exe = td / f"prod_{seed}"
            run([gcc, "-O2", "-std=c11", "-ffreestanding", "-fno-builtin", f"-I{td}", f"-I{EXP}", "-c", str(EXP / "realtime_nn_q4_i8_core.c"), "-o", str(obj)])
            run([gcc, "-O2", "-std=c11", f"-I{td}", f"-I{EXP}", str(td / "check.c"), str(obj), "-o", str(exe)])
            seed_rows.append({
                "seed": seed,
                "export_stdout": export_run.stdout.strip(),
                "certificate": certificate,
                "host_check": run([str(exe)]).stdout.strip().splitlines(),
                "undefined_symbol_count": len([x for x in run([nm, "-u", str(obj)], check=False).stdout.splitlines() if x.strip()]),
            })

        # Compile-negative: production core must not accept a legacy/non-certified header.
        generated = td / "realtime_nn_q4_i8_generated.h"
        text = generated.read_text()
        stripped = "\n".join(
            line for line in text.splitlines()
            if "RTNN_Q_LUT_RANGE_CERTIFIED" not in line and "RTNN_Q_CERT_" not in line
        ) + "\n"
        generated.write_text(stripped)
        legacy_obj = td / "legacy_should_fail.o"
        legacy_compile = run([
            gcc, "-O2", "-std=c11", "-ffreestanding", "-fno-builtin",
            f"-I{td}", f"-I{EXP}", "-c", str(EXP / "realtime_nn_q4_i8_core.c"),
            "-o", str(legacy_obj)
        ], check=False)
        legacy_rejected = legacy_compile.returncode != 0

        # Restore a normal production-generated certified header for target audits.
        run([sys.executable, str(EXP / "export_realtime_nn_q4_i8_header.py"), "--seed", "0", "--out", str(generated)])
        targets = {}
        for target, flags in branch_audit.TARGETS.items():
            obj = td / f"{target}.o"
            run([clang, *flags, "-O2", "-std=c11", "-ffreestanding", "-fno-builtin", f"-I{td}", f"-I{EXP}", "-c", str(EXP / "realtime_nn_q4_i8_core.c"), "-o", str(obj)])
            dis = run([objdump, "-d", str(obj)]).stdout
            pat = branch_audit.RV_BRANCH if target == "rv32im" else branch_audit.ARM_BRANCH
            fields = run([size_tool, str(obj)]).stdout.splitlines()[-1].split()
            targets[target] = {
                "conditional_branch_sites": len(pat.findall(dis)),
                "text_bytes": int(fields[0]),
                "undefined_symbol_count": len([x for x in run([nm, "-u", str(obj)], check=False).stdout.splitlines() if x.strip()]),
            }

        baremetal = {}
        for target, (flags, ldname) in bare.TARGETS.items():
            elf = td / f"{target}.elf"
            proc = run([
                clang, *flags, "-O2", "-std=c11", "-ffreestanding", "-fno-builtin",
                "-nostdlib", "-fuse-ld=lld", f"-I{td}", f"-I{EXP}",
                str(EXP / "realtime_nn_q4_i8_core.c"), str(td / "probe.c"),
                f"-Wl,-T,{td / ldname}", "-Wl,--gc-sections", "-Wl,--build-id=none",
                "-o", str(elf)
            ], check=False)
            if proc.returncode:
                baremetal[target] = {"link_ok": False, "requires_mul_helper": "__mulsi3" in proc.stderr}
                continue
            raw = td / f"{target}.bin"
            run([objcopy, "-O", "binary", str(elf), str(raw)])
            fields = run([size_tool, str(elf)]).stdout.splitlines()[-1].split()
            baremetal[target] = {
                "link_ok": True,
                "undefined_symbol_count": len([x for x in run([nm, "-u", str(elf)], check=False).stdout.splitlines() if x.strip()]),
                "binary_bytes": raw.stat().st_size,
                "bss_bytes": int(fields[2]),
            }

        out = {
            "setup": {
                "production_exporter": "export_realtime_nn_q4_i8_header.py",
                "production_core": "realtime_nn_q4_i8_core.c",
                "seeds": 3,
                "hard_realtime_claim": False,
            },
            "seed_audit": seed_rows,
            "legacy_header_compile_negative": {
                "rejected": legacy_rejected,
                "stderr_contains_certificate_error": "certificate" in legacy_compile.stderr.lower(),
            },
            "targets": targets,
            "baremetal": baremetal,
            "aggregate": {
                "all_exported_headers_certified": all(x["certificate"]["certified"] for x in seed_rows),
                "all_host_objects_helper_free": all(x["undefined_symbol_count"] == 0 for x in seed_rows),
                "legacy_header_rejected": legacy_rejected,
                "embedded_helper_free": all(v["undefined_symbol_count"] == 0 for v in targets.values()),
                "m0_m4_rv32im_baremetal_pass": all(baremetal[t]["link_ok"] for t in ("cortex_m0", "cortex_m4_soft", "rv32im")),
                "rv32i_negative_boundary_preserved": (not baremetal["rv32i_negative"].get("link_ok")) and baremetal["rv32i_negative"].get("requires_mul_helper", False),
            },
            "interpretation": {
                "supported": "The ordinary Q4 production export/build path now requires an exhaustive finite-domain LUT-range certificate before compiling the direct-index production core; three seeds preserve the tested neural outputs and the prior embedded helper/link capability boundaries.",
                "not_supported": ["WCET", "hardware execution", "RTOS timing guarantee", "general range analysis for arbitrary inputs/models"],
            },
        }
        Path(args.out).write_text(json.dumps(out, indent=2))
        print(json.dumps(out["aggregate"], indent=2))


if __name__ == "__main__":
    main()
