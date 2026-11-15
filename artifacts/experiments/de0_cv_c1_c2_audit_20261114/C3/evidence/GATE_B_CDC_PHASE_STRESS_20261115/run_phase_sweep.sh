#!/usr/bin/env bash
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
WRAPPER_SOURCE="${WRAPPER_SOURCE_OVERRIDE:-$ROOT/timescale_wrapper.sv}"
FLAT_WRAPPER_SOURCE="${FLAT_WRAPPER_SOURCE_OVERRIDE:-$ROOT/timescale_wrapper_flat.sv}"
BUILD_DIR="${BUILD_DIR:-$ROOT/build}"
RUN_LOG="${RUN_LOG:-$ROOT/phase_sweep.log}"

mkdir -p "$BUILD_DIR/native" "$BUILD_DIR/flat"
: > "$RUN_LOG"
verilator --version | tee -a "$RUN_LOG"

for variant in native flat; do
  if [[ "$variant" == native ]]; then wrapper="$WRAPPER_SOURCE"; else wrapper="$FLAT_WRAPPER_SOURCE"; fi
  verilator --binary --timing --assert -Wall \
    --top-module tb_rtnn_c2_vjtag_mailbox_async --Mdir "$BUILD_DIR/$variant" \
    -I"$(dirname "$wrapper")" "$wrapper" 2>&1 | tee -a "$RUN_LOG"
  sim="$BUILD_DIR/$variant/Vtb_rtnn_c2_vjtag_mailbox_async"
  for pair in \
  '15000 0' '15000 5000' '15000 10000' '15000 15000' '15000 20000' '15000 25000' \
  '17500 0' '17500 5000' '17500 10000' '17500 15000' '17500 20000' '17500 25000' '17500 30000' \
  '21000 0' '21000 7000' '21000 14000' '21000 21000' '21000 28000' '21000 35000'; do
    read -r half_ps phase_ps <<< "$pair"
    "$sim" +sys_half_ps=10000 +tck_half_ps="$half_ps" +tck_phase_ps="$phase_ps" 2>&1 | tee -a "$RUN_LOG"
  done
done
