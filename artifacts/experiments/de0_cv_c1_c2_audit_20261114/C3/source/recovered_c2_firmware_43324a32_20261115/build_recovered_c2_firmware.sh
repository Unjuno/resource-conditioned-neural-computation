#!/usr/bin/env bash
set -euo pipefail
if (($# != 1)); then
  echo 'usage: build_recovered_c2_firmware.sh NEW_OUTPUT_DIRECTORY' >&2
  exit 2
fi
src=$(cd "$(dirname "$0")" && pwd)
out=$1
[[ ! -e "$out" ]] || { echo "Refusing existing output destination: $out" >&2; exit 2; }
for tool in clang ld.lld llvm-objcopy readelf sha256sum python3; do
  command -v "$tool" >/dev/null || { echo "Missing tool $tool" >&2; exit 2; }
done
mkdir -p "$out"

python3 - "$src/source_manifest.json" "$src" <<'PY'
import hashlib, json, sys
from pathlib import Path
m=Path(sys.argv[1]); root=Path(sys.argv[2]); obj=json.loads(m.read_text())
bad=[]
for rel,expected in obj['source_sha256'].items():
    p=root/rel
    actual=hashlib.sha256(p.read_bytes()).hexdigest() if p.is_file() else 'MISSING'
    if actual != expected: bad.append((rel,expected,actual))
if bad:
    for row in bad: print('SOURCE_SHA256_MISMATCH',*row,file=sys.stderr)
    raise SystemExit(2)
print('SOURCE_SHA256_CHECK_PASS',len(obj['source_sha256']))
PY

flags=(--target=riscv32-unknown-elf -march=rv32im_zicsr -mabi=ilp32 -O2 -std=c11
       -ffreestanding -fno-builtin -fno-pic -fno-pie -fuse-ld=lld -nostdlib
       -Wl,--no-relax -Wl,-T,"$src/firmware/rtnn_experiment.ld")
clang "${flags[@]}" -DC2_BUILD_ID=0x43324a32 \
  -I"$src/model" -I"$src/generated" -I"$src/firmware" \
  "$src/firmware/rtnn_experiment_start.S" \
  "$src/model/realtime_nn_real_sequence_fixed_core.c" \
  "$src/firmware/rtnn_experiment_wire.c" \
  "$src/firmware/rtnn_experiment_runner.c" \
  "$src/firmware/rtnn_c2_main.c" \
  "$src/firmware/rtnn_freestanding_mem.c" \
  -o "$out/rtnn_c2_experiment.elf" 2>&1 | tee "$out/compiler.log"
llvm-objcopy -O binary "$out/rtnn_c2_experiment.elf" "$out/rtnn_c2_experiment.bin"
python3 "$src/tools_build_b_image.py" --elf "$out/rtnn_c2_experiment.elf" \
  --bin "$out/rtnn_c2_experiment.bin" --out-dir "$out" 2>&1 | tee "$out/build_b_image.log"

python3 - "$out/rtnn_ram_words.hex" "$out" "$src" <<'PY'
import hashlib, json, subprocess, sys
from pathlib import Path
words=Path(sys.argv[1]).read_text().splitlines()
if len(words)!=65536 or any(len(w)!=8 for w in words):
    raise SystemExit('unexpected 256-KiB RAM image layout')
out=Path(sys.argv[2]); src=Path(sys.argv[3])
lanes=[bytearray() for _ in range(4)]
for w in words:
    value=int(w,16)
    for lane in range(4): lanes[lane].append((value>>(8*lane))&255)
for lane,data in enumerate(lanes):
    (out/f'rtnn_ram_lane{lane}.hex').write_text(''.join(f'{b:02x}\n' for b in data),encoding='ascii')
def sha(p): return hashlib.sha256(p.read_bytes()).hexdigest()
source=json.loads((src/'source_manifest.json').read_text())
manifest={
 'schema':'rtnn-c2-recovered-source-rebuild-v1',
 'status':'RV32_IMAGE_BUILT_NOT_SIMULATED',
 'build_id':'43324a32','model_id':'52544e4e',
 'source_archive_sha256':source['source_archive_sha256'],
 'elf_sha256':sha(out/'rtnn_c2_experiment.elf'),
 'bin_sha256':sha(out/'rtnn_c2_experiment.bin'),
 'compiler':subprocess.check_output(['clang','--version'],text=True).splitlines()[0],
 'linker':subprocess.check_output(['ld.lld','--version'],text=True).splitlines()[0],
 'source_sha256':source['source_sha256'],
 'word_hex_sha256':sha(out/'rtnn_ram_words.hex'),
 'lane_sha256':{f'rtnn_ram_lane{i}.hex':sha(out/f'rtnn_ram_lane{i}.hex') for i in range(4)},
 'nonclaims':['not simulated in Ibex','not synthesized or timed','not programmed to FPGA']}
(out/'c2_firmware_manifest.json').write_text(json.dumps(manifest,indent=2)+'\n',encoding='utf-8')
print('C2_RV32_IMAGE_BUILT_NOT_SIMULATED',manifest['elf_sha256'])
PY
