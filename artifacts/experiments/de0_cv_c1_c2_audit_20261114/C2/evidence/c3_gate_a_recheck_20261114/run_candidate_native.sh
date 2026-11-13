#!/usr/bin/env bash
set -u
HERE="$(cd -- "$(dirname -- "$0")" && pwd)"
ROOT="/mnt/c/Users/junny/OneDrive/ドキュメント/ChatGPT/resource-conditioned-neural-computation-audit-20261114"
BUILD="/mnt/c/Users/junny/AppData/Local/Temp/rtnn_c3_gateA_native_20261114"
mkdir -p "$BUILD/obj_dir"
mapfile -t rtl_sources < <(sed 's/\r$//' "$HERE/candidate_native_source_list.txt")
printf 'source_count=%s\n' "${#rtl_sources[@]}" > "$HERE/native_source_count.txt"
for src in "${rtl_sources[@]}"; do
  if [[ ! -f "$src" ]]; then printf 'MISSING_SOURCE=%s\n' "$src" >> "$HERE/native_source_presence.log"; fi
done
if [[ -f "$HERE/native_source_presence.log" ]]; then echo 2 > "$HERE/native_source_presence.exitcode"; exit 2; fi
echo 0 > "$HERE/native_source_presence.exitcode"
git -C /opt/rtnn-tools/ibex rev-parse HEAD > "$HERE/ibex_git_commit.txt" 2>&1
git -C /opt/rtnn-tools/ibex status --porcelain=v1 > "$HERE/ibex_git_status.txt" 2>&1
sha256sum "${rtl_sources[@]}" > "$HERE/native_source_sha256.txt"
verilator --version > "$HERE/native_verilator_version.txt" 2>&1
cd "$HERE" || exit 90
verilator --binary --build-jobs 2 --timing -Wall -Wno-fatal \
  -D"RTNN_C2_BUILD_ID=32'h43324a32" \
  -I/opt/rtnn-tools/ibex/rtl \
  -I/opt/rtnn-tools/ibex/vendor/lowrisc_ip/dv/sv/dv_utils \
  -I/opt/rtnn-tools/ibex/vendor/lowrisc_ip/ip/prim/rtl \
  -I/opt/rtnn-tools/ibex/vendor/lowrisc_ip/ip/prim_generic/rtl \
  --Mdir "$BUILD/obj_dir" --top-module tb_rtnn_c2_soc_42 \
  "${rtl_sources[@]}" "$HERE/tb_rtnn_c2_soc_42.sv" > "$HERE/native_compile.log" 2>&1
compile_rc=$?
printf '%s\n' "$compile_rc" > "$HERE/native_compile.exitcode"
if [[ "$compile_rc" -ne 0 ]]; then echo NOT_RUN > "$HERE/native_run.exitcode"; exit "$compile_rc"; fi
"$BUILD/obj_dir/Vtb_rtnn_c2_soc_42" > "$HERE/native_run.log" 2>&1
run_rc=$?
printf '%s\n' "$run_rc" > "$HERE/native_run.exitcode"
python3 "$ROOT/artifacts/experiments/de0_cv_c1_c2_audit_20261114/C2/source/tools/audit_c2_soc_sim_log.py" \
  --log "$HERE/native_run.log" \
  --cases "$ROOT/artifacts/experiments/de0_cv_c1_c2_audit_20261114/C2/vectors/c2j2_cases.csv" \
  --out "$HERE/native_audit" > "$HERE/native_audit.log" 2>&1
audit_rc=$?
printf '%s\n' "$audit_rc" > "$HERE/native_audit.exitcode"
if [[ "$run_rc" -ne 0 ]]; then exit "$run_rc"; fi
exit "$audit_rc"
