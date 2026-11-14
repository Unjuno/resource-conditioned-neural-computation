#!/usr/bin/env bash
set -uo pipefail
cd "$(dirname "$0")" || exit 90
verilator --version > verilator.version
verilator --binary --build-jobs 2 --timing -Wall -Wno-fatal -DSYNTHESIS \
  -D"RTNN_C2_BUILD_ID=32'h43334531" --Mdir obj_v2_42 \
  --top-module tb_rtnn_c2_soc_42 rtnn_c3_measurement_v2_quartus_flat.v \
  tb_rtnn_c2_soc_42.sv > compile_v2_42.log 2>&1
rc=$?; echo "$rc" > compile_v2_42.exitcode
if [[ $rc -ne 0 ]]; then echo NOT_RUN > run_v2_42.exitcode; exit "$rc"; fi
./obj_v2_42/Vtb_rtnn_c2_soc_42 > run_v2_42.log 2>&1
rc=$?; echo "$rc" > run_v2_42.exitcode
if [[ $rc -ne 0 ]]; then exit "$rc"; fi
verilator --binary --build-jobs 2 --timing -Wall -Wno-fatal -DSYNTHESIS \
  -D"RTNN_C2_BUILD_ID=32'h43334531" --Mdir obj_v2_guard \
  --top-module tb_rtnn_c2_response_write_guard rtnn_c3_measurement_v2_quartus_flat.v \
  tb_rtnn_c2_response_write_guard.sv > compile_v2_guard.log 2>&1
rc=$?; echo "$rc" > compile_v2_guard.exitcode
if [[ $rc -ne 0 ]]; then echo NOT_RUN > run_v2_guard.exitcode; exit "$rc"; fi
./obj_v2_guard/Vtb_rtnn_c2_response_write_guard > run_v2_guard.log 2>&1
rc=$?; echo "$rc" > run_v2_guard.exitcode
exit "$rc"
