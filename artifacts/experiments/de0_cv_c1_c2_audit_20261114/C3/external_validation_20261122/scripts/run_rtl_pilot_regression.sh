#!/usr/bin/env bash
set -euo pipefail
base=$(cd "$(dirname "$0")/.." && pwd)
proj="$base/build/quartus_external_attempt1"
attempt="${1:-rtl_pilot_attempt1}"
sim="$proj/$attempt"
[[ ! -e "$sim" ]] || { echo "refusing existing simulation output: $sim" >&2; exit 2; }
python3 "$base/scripts/generate_verilator_vectors.py" "$base/build/host_cases_pilot_attempt2" "$sim/vectors"
for lane in 0 1 2 3; do cp "$proj/rtnn_ram_lane${lane}.hex" "$sim/vectors/"; done
cd "$proj"
verilator --binary --timing -j 2 --Mdir "$sim/obj_dir" --top-module tb_rtnn_external_soc \
  -Wno-fatal -DRTNN_C2_BUILD_ID=32\'h45585631 \
  "$base/rtl/tb_rtnn_external_soc.sv" rtnn_c3_measurement_v2_quartus_flat.v \
  > "$sim/verilator_build.log" 2>&1
(cd "$sim/vectors" && "$sim/obj_dir/Vtb_rtnn_external_soc") > "$sim/verilator_run.log" 2>&1
verilator --binary --timing -j 2 --Mdir "$sim/commit_guard_obj" --top-module tb_rtnn_mailbox_commit_guard \
  -Wno-fatal rtnn_c3_measurement_v2_quartus_flat.v "$base/rtl/tb_rtnn_mailbox_commit_guard.sv" \
  > "$sim/commit_guard_build.log" 2>&1
(cd "$sim/vectors" && "$sim/commit_guard_obj/Vtb_rtnn_mailbox_commit_guard") > "$sim/commit_guard_run.log" 2>&1
printf 'VERILATOR_EXTERNAL_DYNAMIC_PILOT_PASS\n'
