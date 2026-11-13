#!/usr/bin/env bash
set +e
cd "$(dirname "$0")" || exit 90
mapfile -t rtl_sources < <(sed '/^[[:space:]]*#/d;/^[[:space:]]*$/d' ibex_fusesoc_sources_c2_remapped.txt)
printf 'source_count=%s\n' "${#rtl_sources[@]}" > source_count.txt
for src in "${rtl_sources[@]}"; do if [ ! -f "$src" ]; then echo "MISSING_SOURCE=$src" >> source_presence.txt; fi; done
if [ -f source_presence.txt ]; then echo 2 > source_presence.exitcode; exit 2; fi
echo 0 > source_presence.exitcode
verilator --version > verilator.version 2>&1
verilator --binary --build-jobs 2 --timing -Wall -Wno-fatal -D"RTNN_C2_BUILD_ID=32'h43324a32" -I/opt/rtnn-tools/ibex/rtl -I/opt/rtnn-tools/ibex/vendor/lowrisc_ip/dv/sv/dv_utils -I/opt/rtnn-tools/ibex/vendor/lowrisc_ip/ip/prim/rtl -I/opt/rtnn-tools/ibex/vendor/lowrisc_ip/ip/prim_generic/rtl --Mdir obj_dir --top-module tb_rtnn_c2_soc_42 "${rtl_sources[@]}" tb_rtnn_c2_soc_42_capture_edge.sv > compile.log 2>&1
rc=$?
printf '%s\n' "$rc" > compile.exitcode
if [ "$rc" -eq 0 ]; then ./obj_dir/Vtb_rtnn_c2_soc_42 > run.log 2>&1; rc=$?; printf '%s\n' "$rc" > run.exitcode; else echo NOT_RUN > run.exitcode; fi
exit "$rc"