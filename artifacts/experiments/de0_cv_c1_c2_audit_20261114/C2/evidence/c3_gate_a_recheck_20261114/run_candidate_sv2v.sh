#!/usr/bin/env bash
set -u
HERE="$(cd -- "$(dirname -- "$0")" && pwd)"
ROOT="/mnt/c/Users/junny/OneDrive/ドキュメント/ChatGPT/resource-conditioned-neural-computation-audit-20261114"
BUILD="/mnt/c/Users/junny/AppData/Local/Temp/rtnn_c3_gateA_sv2v_20261114"
mkdir -p "$BUILD/obj_dir"
mapfile -t rtl_sources < <(sed 's/\r$//' "$HERE/candidate_native_source_list.txt")
printf 'source_count=%s\n' "${#rtl_sources[@]}" > "$HERE/sv2v_source_count.txt"
for src in "${rtl_sources[@]}"; do
  if [[ ! -f "$src" ]]; then printf 'MISSING_SOURCE=%s\n' "$src" >> "$HERE/sv2v_source_presence.log"; fi
done
if [[ -f "$HERE/sv2v_source_presence.log" ]]; then echo 2 > "$HERE/sv2v_source_presence.exitcode"; exit 2; fi
echo 0 > "$HERE/sv2v_source_presence.exitcode"
sha256sum "${rtl_sources[@]}" > "$HERE/sv2v_source_sha256.txt"
verilator --version > "$HERE/sv2v_verilator_version.txt" 2>&1
sv2v --version > "$HERE/sv2v_version.txt" 2>&1
sv2v -D "RTNN_C2_BUILD_ID=32'h43324a32" \
  -I/opt/rtnn-tools/ibex/rtl \
  -I/opt/rtnn-tools/ibex/vendor/lowrisc_ip/dv/sv/dv_utils \
  -I/opt/rtnn-tools/ibex/vendor/lowrisc_ip/ip/prim/rtl \
  -I/opt/rtnn-tools/ibex/vendor/lowrisc_ip/ip/prim_generic/rtl \
  "${rtl_sources[@]}" > "$HERE/candidate_full_sv2v.v" 2> "$HERE/sv2v_convert.log"
convert_rc=$?
printf '%s\n' "$convert_rc" > "$HERE/sv2v_convert.exitcode"
if [[ "$convert_rc" -ne 0 ]]; then echo NOT_RUN > "$HERE/sv2v_compile.exitcode"; echo NOT_RUN > "$HERE/sv2v_run.exitcode"; exit "$convert_rc"; fi
sha256sum "$HERE/candidate_full_sv2v.v" > "$HERE/candidate_full_sv2v.sha256"
cd "$HERE" || exit 90
verilator --binary --build-jobs 2 --timing -Wall -Wno-fatal \
  -D"RTNN_C2_BUILD_ID=32'h43324a32" \
  --Mdir "$BUILD/obj_dir" --top-module tb_rtnn_c2_soc_42 \
  "$HERE/candidate_full_sv2v.v" "$HERE/tb_rtnn_c2_soc_42.sv" > "$HERE/sv2v_compile.log" 2>&1
compile_rc=$?
printf '%s\n' "$compile_rc" > "$HERE/sv2v_compile.exitcode"
if [[ "$compile_rc" -ne 0 ]]; then echo NOT_RUN > "$HERE/sv2v_run.exitcode"; exit "$compile_rc"; fi
"$BUILD/obj_dir/Vtb_rtnn_c2_soc_42" > "$HERE/sv2v_run.log" 2>&1
run_rc=$?
printf '%s\n' "$run_rc" > "$HERE/sv2v_run.exitcode"
python3 "$ROOT/artifacts/experiments/de0_cv_c1_c2_audit_20261114/C2/source/tools/audit_c2_soc_sim_log.py" \
  --log "$HERE/sv2v_run.log" \
  --cases "$ROOT/artifacts/experiments/de0_cv_c1_c2_audit_20261114/C2/vectors/c2j2_cases.csv" \
  --out "$HERE/sv2v_audit" > "$HERE/sv2v_audit.log" 2>&1
audit_rc=$?
printf '%s\n' "$audit_rc" > "$HERE/sv2v_audit.exitcode"
if [[ "$run_rc" -ne 0 ]]; then exit "$run_rc"; fi
exit "$audit_rc"
