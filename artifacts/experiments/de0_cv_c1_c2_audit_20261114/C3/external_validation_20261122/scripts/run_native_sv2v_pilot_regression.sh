#!/usr/bin/env bash
set -euo pipefail
base=$(cd "$(dirname "$0")/.." && pwd)
attempt="${1:-native_sv2v_pilot_attempt1}"
out="$base/build/$attempt"
source_graph="$base/build/native_source_graph_attempt1"
[[ ! -e "$out" ]] || { echo "refusing existing output: $out" >&2; exit 2; }
[[ -f "$source_graph/native_sources.list" ]] || { echo "native source graph is not prepared" >&2; exit 2; }
mkdir -p "$out/native" "$out/sv2v"
python3 "$base/scripts/generate_verilator_vectors.py" "$base/build/host_cases_pilot_attempt2" "$out/vectors"
for lane in 0 1 2 3; do cp "$base/build/rv32_attempt2/rtnn_ram_lane${lane}.hex" "$out/vectors/"; done
mapfile -t sources < "$source_graph/native_sources.list"
verilator --binary --timing -j 2 --Mdir "$out/native/obj_dir" --top-module tb_rtnn_external_soc \
  -Wno-fatal -DRTNN_C2_BUILD_ID=32\'h45585631 \
  -I/opt/rtnn-tools/ibex/rtl -I/opt/rtnn-tools/ibex/vendor/lowrisc_ip/dv/sv/dv_utils \
  -I/opt/rtnn-tools/ibex/vendor/lowrisc_ip/ip/prim/rtl -I/opt/rtnn-tools/ibex/vendor/lowrisc_ip/ip/prim_generic/rtl \
  "$base/rtl/tb_rtnn_external_soc.sv" "${sources[@]}" > "$out/native/build.log" 2>&1
(cd "$out/vectors" && "$out/native/obj_dir/Vtb_rtnn_external_soc") > "$out/native/run.log" 2>&1
sv2v --version > "$out/sv2v/version.txt" 2>&1
sv2v -D SYNTHESIS=1 -I/opt/rtnn-tools/ibex/rtl -I/opt/rtnn-tools/ibex/vendor/lowrisc_ip/dv/sv/dv_utils \
  -I/opt/rtnn-tools/ibex/vendor/lowrisc_ip/ip/prim/rtl -I/opt/rtnn-tools/ibex/vendor/lowrisc_ip/ip/prim_generic/rtl \
  --top=rtnn_de0_cv_soc_c2 --top=rtnn_c2_vjtag_mailbox "${sources[@]}" \
  > "$out/sv2v/rtnn_c3_external_soc_flat.v" 2> "$out/sv2v/convert.log"
verilator --binary --timing -j 2 --Mdir "$out/sv2v/obj_dir" --top-module tb_rtnn_external_soc \
  -Wno-fatal -DRTNN_C2_BUILD_ID=32\'h45585631 \
  "$base/rtl/tb_rtnn_external_soc.sv" "$out/sv2v/rtnn_c3_external_soc_flat.v" > "$out/sv2v/build.log" 2>&1
(cd "$out/vectors" && "$out/sv2v/obj_dir/Vtb_rtnn_external_soc") > "$out/sv2v/run.log" 2>&1
verilator --binary --timing -j 2 --Mdir "$out/native/commit_guard_obj" --top-module tb_rtnn_mailbox_commit_guard \
  -Wno-fatal -I/opt/rtnn-tools/ibex/rtl -I/opt/rtnn-tools/ibex/vendor/lowrisc_ip/dv/sv/dv_utils \
  -I/opt/rtnn-tools/ibex/vendor/lowrisc_ip/ip/prim/rtl -I/opt/rtnn-tools/ibex/vendor/lowrisc_ip/ip/prim_generic/rtl \
  "$base/rtl/tb_rtnn_mailbox_commit_guard.sv" "${sources[@]}" > "$out/native/commit_guard_build.log" 2>&1
(cd "$out/vectors" && "$out/native/commit_guard_obj/Vtb_rtnn_mailbox_commit_guard") > "$out/native/commit_guard_run.log" 2>&1
verilator --binary --timing -j 2 --Mdir "$out/sv2v/commit_guard_obj" --top-module tb_rtnn_mailbox_commit_guard \
  -Wno-fatal "$base/rtl/tb_rtnn_mailbox_commit_guard.sv" "$out/sv2v/rtnn_c3_external_soc_flat.v" > "$out/sv2v/commit_guard_build.log" 2>&1
(cd "$out/vectors" && "$out/sv2v/commit_guard_obj/Vtb_rtnn_mailbox_commit_guard") > "$out/sv2v/commit_guard_run.log" 2>&1
printf 'NATIVE_AND_SV2V_DYNAMIC_PILOT_PASS\n'
