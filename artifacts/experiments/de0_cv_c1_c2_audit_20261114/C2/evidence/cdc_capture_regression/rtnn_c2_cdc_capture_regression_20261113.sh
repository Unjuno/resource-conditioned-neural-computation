#!/usr/bin/env bash
set -u
ROOT=/mnt/c/Users/junny/OneDrive/ドキュメント/ChatGPT/RTNN/de0cv_setup/stage3_experiments/ibex_csa_2026-11-03/c2_jtag_measurement_20261111
BASE_NATIVE=/mnt/d/rtnn_c2_soc_resetfix_native_cdcassert_20261113
BASE_SV2V=/mnt/d/rtnn_c2_soc_resetfix_sv2v_cdcassert_20261113
WORK=/mnt/d/rtnn_c2_cdc_capture_regression_20261113
VERILATOR=/opt/rtnn-tools/verilator-5.020/bin/verilator
IBEX=/opt/rtnn-tools/ibex
mkdir -p "$WORK/native" "$WORK/sv2v"
for dst in "$WORK/native" "$WORK/sv2v"; do
  cp "$BASE_NATIVE"/c2_expected.hex "$BASE_NATIVE"/c2_requests.hex "$BASE_NATIVE"/rtnn_ram_lane*.hex "$dst"/
  cp "$ROOT/tests/tb_rtnn_c2_soc_42.sv" "$dst/"
done
cp "$BASE_SV2V/rtnn_c2_soc_flat.v" "$WORK/sv2v/"
sha256sum "$ROOT/tests/tb_rtnn_c2_soc_42.sv" "$BASE_SV2V/rtnn_c2_soc_flat.v" > "$WORK/input_hashes.txt"
source_list="$ROOT/rtl/ibex_fusesoc_sources_c2.txt"
mapfile -t rtl_sources < <(sed '/^[[:space:]]*#/d;/^[[:space:]]*$/d' "$source_list")
printf 'source_count=%s\n' "${#rtl_sources[@]}" > "$WORK/native/source_count.txt"
"$VERILATOR" --version > "$WORK/native/verilator.version"
(
 cd "$WORK/native"
 "$VERILATOR" --binary --build-jobs 2 --timing -Wall -Wno-fatal -D"RTNN_C2_BUILD_ID=32'h43324a32" -I"$IBEX/rtl" -I"$IBEX/vendor/lowrisc_ip/dv/sv/dv_utils" -I"$IBEX/vendor/lowrisc_ip/ip/prim/rtl" -I"$IBEX/vendor/lowrisc_ip/ip/prim_generic/rtl" --top-module tb_rtnn_c2_soc_42 "${rtl_sources[@]}" tb_rtnn_c2_soc_42.sv > compile.log 2>&1
 rc=$?; echo "$rc" > compile.exitcode
 if [ "$rc" -eq 0 ]; then ./obj_dir/Vtb_rtnn_c2_soc_42 > run.log 2>&1; rc=$?; echo "$rc" > run.exitcode; else echo NOT_RUN > run.exitcode; fi
)
(
 cd "$WORK/sv2v"
 "$VERILATOR" --binary --build-jobs 2 --timing -Wall -Wno-fatal -D"RTNN_C2_BUILD_ID=32'h43324a32" --Mdir obj_dir_buildidfix --top-module tb_rtnn_c2_soc_42 rtnn_c2_soc_flat.v tb_rtnn_c2_soc_42.sv > compile.log 2>&1
 rc=$?; echo "$rc" > compile.exitcode
 if [ "$rc" -eq 0 ]; then ./obj_dir_buildidfix/Vtb_rtnn_c2_soc_42 > run.log 2>&1; rc=$?; echo "$rc" > run.exitcode; else echo NOT_RUN > run.exitcode; fi
)
sha256sum "$WORK/native/tb_rtnn_c2_soc_42.sv" "$WORK/sv2v/tb_rtnn_c2_soc_42.sv" "$WORK/sv2v/rtnn_c2_soc_flat.v" > "$WORK/final_input_hashes.txt"
printf 'native_compile=%s native_run=%s sv2v_compile=%s sv2v_run=%s\n' "$(cat "$WORK/native/compile.exitcode")" "$(cat "$WORK/native/run.exitcode")" "$(cat "$WORK/sv2v/compile.exitcode")" "$(cat "$WORK/sv2v/run.exitcode")" > "$WORK/exit_summary.txt"