#!/usr/bin/env bash
set +e
cd "$(dirname "$0")" || exit 90
mapfile -t rtl_sources < <(sed '/^[[:space:]]*#/d;/^[[:space:]]*$/d' native_sources_v2.txt)
printf '%s\n' "${#rtl_sources[@]}" > source_count.txt
for src in "${rtl_sources[@]}"; do [[ -f "$src" ]] || echo "MISSING_SOURCE=$src" >> source_presence.log; done
if [[ -f source_presence.log ]]; then echo 2 > source_presence.exitcode; exit 2; fi
echo 0 > source_presence.exitcode
sv2v --version > sv2v.version 2>&1
sv2v -I/opt/rtnn-tools/ibex/rtl -I/opt/rtnn-tools/ibex/vendor/lowrisc_ip/dv/sv/dv_utils \
  -I/opt/rtnn-tools/ibex/vendor/lowrisc_ip/ip/prim/rtl -I/opt/rtnn-tools/ibex/vendor/lowrisc_ip/ip/prim_generic/rtl \
  --top=rtnn_de0_cv_soc_c2 --top=rtnn_c2_vjtag_mailbox "${rtl_sources[@]}" > rtnn_c3_measurement_v2_soc_flat.v 2> sv2v_convert.log
rc=$?; echo "$rc" > sv2v_convert.exitcode
if [[ $rc -ne 0 ]]; then exit "$rc"; fi
sha256sum native_sources_v2.txt rtnn_c3_measurement_v2_soc_flat.v > source_and_flat.sha256
verilator --version > verilator.version 2>&1
verilator --binary --build-jobs 2 --timing -Wall -Wno-fatal -D"RTNN_C2_BUILD_ID=32'h43334531" \
  --Mdir obj_v2_42 --top-module tb_rtnn_c2_soc_42 rtnn_c3_measurement_v2_soc_flat.v tb_rtnn_c2_soc_42.sv > compile_v2_42.log 2>&1
rc=$?; echo "$rc" > compile_v2_42.exitcode
if [[ $rc -eq 0 ]]; then ./obj_v2_42/Vtb_rtnn_c2_soc_42 > run_v2_42.log 2>&1; rc=$?; echo "$rc" > run_v2_42.exitcode; else echo NOT_RUN > run_v2_42.exitcode; fi
if [[ $rc -ne 0 ]]; then exit "$rc"; fi
verilator --binary --build-jobs 2 --timing -Wall -Wno-fatal -D"RTNN_C2_BUILD_ID=32'h43334531" \
  --Mdir obj_v2_guard --top-module tb_rtnn_c2_response_write_guard rtnn_c3_measurement_v2_soc_flat.v tb_rtnn_c2_response_write_guard.sv > compile_v2_guard.log 2>&1
rc=$?; echo "$rc" > compile_v2_guard.exitcode
if [[ $rc -eq 0 ]]; then ./obj_v2_guard/Vtb_rtnn_c2_response_write_guard > run_v2_guard.log 2>&1; rc=$?; echo "$rc" > run_v2_guard.exitcode; else echo NOT_RUN > run_v2_guard.exitcode; fi
exit "$rc"
