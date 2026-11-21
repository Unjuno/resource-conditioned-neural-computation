#!/usr/bin/env bash
set -euo pipefail
here=$(cd "$(dirname "$0")/.." && pwd)
out=${1:?usage: run_cpu_oracle.sh OUTPUT_DIRECTORY}
[[ ! -e "$out" ]] || { echo "refusing existing output: $out" >&2; exit 2; }
mkdir -p "$out"
clang -O2 -std=c11 -Wall -Wextra -Werror \
  -I"$here/firmware/model" \
  "$here/firmware/model/realtime_nn_real_sequence_fixed_core.c" \
  "$here/firmware/src/rtnn_external_oracle_cli.c" -o "$out/rtnn_cpu_oracle"
"$out/rtnn_cpu_oracle" < "$here/data/pilot_inputs.bin" > "$out/oracle_pilot.csv"
"$out/rtnn_cpu_oracle" < "$here/data/primary_inputs.bin" > "$out/oracle_primary.csv"
sha256sum "$out/rtnn_cpu_oracle" "$out/oracle_pilot.csv" "$out/oracle_primary.csv" > "$out/SHA256SUMS.txt"
printf 'CPU_ORACLE_COMPLETE_NOT_PHYSICAL\n'
