#!/usr/bin/env bash
set -uo pipefail
cd /mnt/d/rtnn_c2_cdc_2ff_bus_20261113_capture_delay_native
export PATH=/opt/rtnn-tools/bin:/opt/rtnn-tools/verilator-5.020/bin:/usr/bin:/bin
source_list=/mnt/d/rtnn_c2_cdc_2ff_bus_20261113_capture_delay_native/source_list.txt
mapfile -t rtl_sources < <(sed '/^[[:space:]]*#/d;/^[[:space:]]*$/d' "$source_list")
printf 'source_count=%s\n' "${#rtl_sources[@]}" > source_count.txt
verilator --version > verilator.version
verilator --binary --build-jobs 2 --timing -Wall -Wno-fatal -D"RTNN_C2_BUILD_ID=32'h43324a32" -I/opt/rtnn-tools/ibex/rtl -I/opt/rtnn-tools/ibex/vendor/lowrisc_ip/dv/sv/dv_utils -I/opt/rtnn-tools/ibex/vendor/lowrisc_ip/ip/prim/rtl -I/opt/rtnn-tools/ibex/vendor/lowrisc_ip/ip/prim_generic/rtl --top-module tb_rtnn_c2_soc_42 "${rtl_sources[@]}" tb_rtnn_c2_soc_42.sv > compile.log 2>&1
rc=$?; echo "$rc" > compile.exitcode; if [ "$rc" -ne 0 ]; then exit "$rc"; fi
./obj_dir/Vtb_rtnn_c2_soc_42 > run.log 2>&1
rc=$?; echo "$rc" > run.exitcode; exit "$rc"
