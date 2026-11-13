#!/usr/bin/env bash
set +e
cd "$(dirname "$0")" || exit 90
verilator --version > verilator.version 2>&1
verilator --binary --build-jobs 2 --timing -Wall -Wno-fatal -D"RTNN_C2_BUILD_ID=32'h43324a32" --Mdir obj_dir --top-module tb_rtnn_c2_soc_42 rtnn_c2_soc_flat.v tb_rtnn_c2_soc_42.sv > compile.log 2>&1
rc=$?
printf '%s\n' "$rc" > compile.exitcode
if [ "$rc" -eq 0 ]; then
  ./obj_dir/Vtb_rtnn_c2_soc_42 > run.log 2>&1
  rc=$?
  printf '%s\n' "$rc" > run.exitcode
else
  printf 'NOT_RUN\n' > run.exitcode
fi
exit "$rc"