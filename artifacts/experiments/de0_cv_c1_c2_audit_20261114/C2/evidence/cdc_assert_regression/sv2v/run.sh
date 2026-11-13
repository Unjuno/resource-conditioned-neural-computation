#!/usr/bin/env bash
set -uo pipefail
cd /mnt/d/rtnn_c2_soc_resetfix_sv2v_cdcassert_20261113
export PATH=/opt/rtnn-tools/bin:/opt/rtnn-tools/verilator-5.020/bin:/usr/bin:/bin
verilator --version > verilator.version
sha256sum rtnn_c2_soc_flat.v tb_rtnn_c2_soc_42.sv > input_hashes.txt
verilator --binary --build-jobs 2 --timing -Wall -Wno-fatal -D"RTNN_C2_BUILD_ID=32'h43324a32" --Mdir obj_dir_buildidfix --top-module tb_rtnn_c2_soc_42 rtnn_c2_soc_flat.v tb_rtnn_c2_soc_42.sv > compile.log 2>&1
rc=$?
echo "$rc" > compile.exitcode
if [ "$rc" -ne 0 ]; then exit "$rc"; fi
./obj_dir_buildidfix/Vtb_rtnn_c2_soc_42 > run.log 2>&1
rc=$?
echo "$rc" > run.exitcode
exit "$rc"