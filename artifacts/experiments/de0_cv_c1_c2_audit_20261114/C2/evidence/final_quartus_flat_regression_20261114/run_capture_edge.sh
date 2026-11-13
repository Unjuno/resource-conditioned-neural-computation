#!/usr/bin/env bash
set +e
cd "$(dirname "$0")" || exit 90
verilator --version > verilator_capture_edge.version 2>&1
verilator --binary --build-jobs 2 --timing -Wall -Wno-fatal -D"RTNN_C2_BUILD_ID=32'h43324a32" --Mdir obj_dir_capture_edge --top-module tb_rtnn_c2_soc_42 rtnn_c2_soc_flat.v tb_rtnn_c2_soc_42_capture_edge.sv > compile_capture_edge.log 2>&1
rc=$?
printf '%s\n' "$rc" > compile_capture_edge.exitcode
if [ "$rc" -eq 0 ]; then
  ./obj_dir_capture_edge/Vtb_rtnn_c2_soc_42 > run_capture_edge.log 2>&1
  rc=$?
  printf '%s\n' "$rc" > run_capture_edge.exitcode
else
  printf 'NOT_RUN\n' > run_capture_edge.exitcode
fi
exit "$rc"