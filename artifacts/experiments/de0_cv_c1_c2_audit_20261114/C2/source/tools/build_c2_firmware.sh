#!/usr/bin/env bash
# Build an isolated C2 RV32 image from the frozen Stage 2 Q15 core.
set -euo pipefail
if (($# < 3 || $# > 4)); then
  echo 'usage: build_c2_firmware.sh STAGE2_ROOT PINNED_MODEL_REPO NEW_OUTPUT_DIR [8_HEX_BUILD_ID]' >&2
  exit 2
fi
stage2=$(cd "$1" && pwd)
repo=$(cd "$2" && pwd)
out=$3
build_id=${4:-43324a31}
[[ "$build_id" =~ ^[0-9a-fA-F]{8}$ ]] || { echo 'build ID must be exactly 8 hex digits' >&2; exit 2; }
build_id=$(printf '%s' "$build_id" | tr 'A-F' 'a-f')
[[ ! -e "$out" ]] || { echo "Refusing existing output destination: $out" >&2; exit 2; }
objcopy_tool=llvm-objcopy
if ! command -v "$objcopy_tool" >/dev/null; then
  objcopy_tool=llvm-objcopy-18
fi
for tool in clang ld.lld "$objcopy_tool" readelf git unzip sha256sum python3; do
  command -v "$tool" >/dev/null || { echo "Missing tool $tool" >&2; exit 2; }
done
model="$repo/experiments"
[[ "$(git -C "$repo" hash-object "$model/realtime_nn_real_sequence_fixed_core.c")" == '3f52ac6dd50f0cbaa2ff8ce9553020ebdb45718a' ]] || { echo 'frozen Q15 C source blob mismatch' >&2; exit 2; }
[[ "$(git -C "$repo" hash-object "$model/realtime_nn_real_sequence_fixed_core.h")" == 'ac185458e21b956db01cb18504bdb507c0c69618' ]] || { echo 'frozen Q15 header blob mismatch' >&2; exit 2; }
board="$stage2/fpga/de0_cv"
here=$(cd "$(dirname "$0")/.." && pwd)
mkdir -p "$out"
weights="$out/realtime_nn_real_sequence_fixed_weights_generated.h"
unzip -p "$board/artifacts/rtnn_ibex_rtl_exact.zip" rtnn/realtime_nn_real_sequence_fixed_weights_generated.h > "$weights"
want=961a76b7e220bf2f665e7c04ab62063600aa2e7eccf3403d80ea730bc993ad9f
[[ "$(sha256sum "$weights" | cut -d' ' -f1)" == "$want" ]] || { echo 'frozen Q15 weights hash mismatch' >&2; exit 2; }
flags=(--target=riscv32-unknown-elf -march=rv32im_zicsr -mabi=ilp32 -O2 -std=c11
       -ffreestanding -fno-builtin -fno-pic -fno-pie -fuse-ld=lld -nostdlib
       -Wl,--no-relax -Wl,-T,"$board/firmware/rtnn_experiment.ld")
clang "${flags[@]}" "-DC2_BUILD_ID=0x${build_id}" -I"$model" -I"$board/generated" -I"$out" -I"$board/firmware" \
  "$board/firmware/rtnn_experiment_start.S" \
  "$model/realtime_nn_real_sequence_fixed_core.c" \
  "$board/firmware/rtnn_experiment_wire.c" \
  "$board/firmware/rtnn_experiment_runner.c" \
  "$here/firmware/rtnn_c2_main.c" \
  "$board/firmware/rtnn_freestanding_mem.c" \
  -o "$out/rtnn_c2_experiment.elf" 2>&1 | tee "$out/compiler.log"
"$objcopy_tool" -O binary "$out/rtnn_c2_experiment.elf" "$out/rtnn_c2_experiment.bin"
python3 "$board/tools/build_b_image.py" --elf "$out/rtnn_c2_experiment.elf" \
  --bin "$out/rtnn_c2_experiment.bin" --out-dir "$out"
 C2_SOURCE_DIR="$here" STAGE2_BOARD_DIR="$board" MODEL_REPO="$repo" python3 - "$out/rtnn_ram_words.hex" "$out" "$build_id" <<'PY'
import hashlib, json, os, subprocess, sys
from pathlib import Path
words=Path(sys.argv[1]).read_text().splitlines()
if len(words)!=65536 or any(len(w)!=8 for w in words):
    raise SystemExit('unexpected 256KiB word image layout')
out=Path(sys.argv[2])
lanes=[bytearray() for _ in range(4)]
for w in words:
    value=int(w,16)
    for lane in range(4): lanes[lane].append((value>>(8*lane))&255)
for lane,data in enumerate(lanes):
    (out/f'rtnn_ram_lane{lane}.hex').write_text(''.join(f'{b:02x}\n' for b in data),encoding='ascii')
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
src=Path(os.environ['C2_SOURCE_DIR']); board=Path(os.environ['STAGE2_BOARD_DIR']); repo=Path(os.environ['MODEL_REPO'])
# A vendored source directory can inherit an unrelated ancestor .git directory.
# Only describe a model-repository commit when MODEL_REPO is that Git root.
root_probe=subprocess.run(['git','-C',str(repo),'rev-parse','--show-toplevel'],text=True,encoding='utf-8',capture_output=True)
model_is_git_root=root_probe.returncode==0 and Path(root_probe.stdout.strip()).resolve()==repo.resolve()
model_commit=(subprocess.check_output(['git','-C',str(repo),'rev-parse','HEAD'],text=True,encoding='utf-8').strip()
              if model_is_git_root else None)
source_files={
 'firmware/rtnn_c2_main.c':src/'firmware/rtnn_c2_main.c',
 'firmware/rtnn_experiment_runner.c':board/'firmware/rtnn_experiment_runner.c',
 'firmware/rtnn_experiment_runner.h':board/'firmware/rtnn_experiment_runner.h',
 'firmware/rtnn_experiment_wire.c':board/'firmware/rtnn_experiment_wire.c',
 'firmware/rtnn_experiment_wire.h':board/'firmware/rtnn_experiment_wire.h',
 'firmware/rtnn_experiment_start.S':board/'firmware/rtnn_experiment_start.S',
 'firmware/rtnn_experiment.ld':board/'firmware/rtnn_experiment.ld',
 'firmware/rtnn_freestanding_mem.c':board/'firmware/rtnn_freestanding_mem.c',
 'generated/heldout360.h':board/'generated/heldout360.h',
 'frozen_weights.h':out/'realtime_nn_real_sequence_fixed_weights_generated.h',
 'upstream/realtime_nn_real_sequence_fixed_core.c':repo/'experiments/realtime_nn_real_sequence_fixed_core.c',
 'upstream/realtime_nn_real_sequence_fixed_core.h':repo/'experiments/realtime_nn_real_sequence_fixed_core.h',
}
manifest={
 'schema':'rtnn-c2-uart-free-jtag-firmware-v1',
 'status':'RV32_IMAGE_BUILT_NOT_SIMULATED',
 'build_id':sys.argv[3],'model_id':'52544e4e',
 'elf_sha256':sha(out/'rtnn_c2_experiment.elf'),
 'bin_sha256':sha(out/'rtnn_c2_experiment.bin'),
 'compiler':subprocess.check_output(['clang','--version'],text=True).splitlines()[0],
 'linker':subprocess.check_output(['ld.lld','--version'],text=True).splitlines()[0],
 'model_repo_commit':model_commit,
 'model_source_identity':'git_root_and_file_hashes' if model_is_git_root else 'vendored_file_hashes_only',
 'source_sha256':{name:sha(path) for name,path in source_files.items()},
 'word_hex_sha256':sha(out/'rtnn_ram_words.hex'),
 'lane_sha256':{f'rtnn_ram_lane{i}.hex':sha(out/f'rtnn_ram_lane{i}.hex') for i in range(4)},
 'payload':'100-byte RTNQ frame + pixels + CRC; UART-free MMIO mailbox',
 'nonclaims':['not simulated in Ibex','not synthesized or timed','not programmed to FPGA']}
(out/'c2_firmware_manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
print('C2_RV32_IMAGE_BUILT_NOT_SIMULATED',manifest['elf_sha256'])
PY
