#!/usr/bin/env bash
set -euo pipefail
base=$(cd "$(dirname "$0")/.." && pwd)
out="$base/build/firmware_api_attempt2"
[[ ! -e "$out" ]] || { echo "refusing existing output: $out" >&2; exit 2; }
mkdir -p "$out"
clang -O2 -std=c11 -Wall -Wextra -Werror -I"$base/firmware/model" -I"$base/firmware/src" \
  "$base/firmware/model/realtime_nn_real_sequence_fixed_core.c" \
  "$base/firmware/src/rtnn_external_wire.c" "$base/firmware/src/rtnn_external_runner.c" \
  "$base/firmware/src/test_external_dataset_runner.c" -o "$out/test_external_dataset_runner"
for split in pilot primary; do
  "$out/test_external_dataset_runner" < "$base/data/${split}_inputs.bin" > "$out/firmware_${split}.csv"
  python3 "$base/scripts/verify_firmware_vs_oracle.py" "$out/firmware_${split}.csv" "$base/build/cpu_oracle_attempt1/oracle_${split}.csv"
done
sha256sum "$out"/* > "$out/SHA256SUMS.txt"
printf 'FIRMWARE_DYNAMIC_DATASET_SOFTWARE_API_REGRESSION_PASS\n'
