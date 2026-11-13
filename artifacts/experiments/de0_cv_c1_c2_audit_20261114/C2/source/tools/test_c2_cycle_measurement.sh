#!/usr/bin/env bash
set -euo pipefail

if (($# != 1)); then
  echo 'usage: test_c2_cycle_measurement.sh NEW_OUTPUT_DIRECTORY' >&2
  exit 2
fi
out=$1
[[ ! -e "$out" ]] || { echo "Refusing existing output directory: $out" >&2; exit 2; }
command -v clang >/dev/null
command -v unzip >/dev/null
command -v sha256sum >/dev/null

here=$(cd "$(dirname "$0")/.." && pwd)
repo=$(git -C "$here" rev-parse --show-toplevel)
board="$repo/de0cv_setup/verified_inputs_2026-11-03/stage2_work/fpga/de0_cv"
model="$board/upstream/source_repo/experiments"
weights_zip="$board/artifacts/rtnn_ibex_rtl_exact.zip"
runner="$board/firmware/rtnn_experiment_runner.c"
core="$model/realtime_nn_real_sequence_fixed_core.c"
runner_header="$board/firmware/rtnn_experiment_runner.h"
runner_header_hash=$(sha256sum "$runner_header" | cut -d' ' -f1)
runner_hash=$(sha256sum "$runner" | cut -d' ' -f1)
heldout_hash=$(sha256sum "$board/generated/heldout360.h" | cut -d' ' -f1)
test="$here/tests/test_c2_cycle_measurement.c"

[[ "$(git -C "$board/upstream/source_repo" hash-object "$core")" == \
   '3f52ac6dd50f0cbaa2ff8ce9553020ebdb45718a' ]] || {
  echo 'frozen Q15 core source blob mismatch' >&2; exit 3;
}
[[ "$(git -C "$board/upstream/source_repo" hash-object "$model/realtime_nn_real_sequence_fixed_core.h")" == \
   'ac185458e21b956db01cb18504bdb507c0c69618' ]] || {
  echo 'frozen Q15 core header blob mismatch' >&2; exit 3;
}
[[ "$runner_hash" == 'd68f8b9dfe5eddbea43e68f840cbe19543f6c450e0711bb40efab4e82a56082e' ]] || {
  echo 'C2 firmware runner source differs from the built ELF manifest' >&2; exit 3;
}
[[ "$runner_header_hash" == 'ca34dc893373873403e50996627578c85826a9f93a7ee7f392651ae488347588' ]] || {
  echo 'C2 firmware runner header differs from the built ELF manifest' >&2; exit 3;
}
[[ "$heldout_hash" == 'c9c7401f1ef38e30db9bbc2221f409d2fa1b6c8ff30d160eca8342441bb7b422' ]] || {
  echo 'frozen heldout input/label table differs from the built ELF manifest' >&2; exit 3;
}

mkdir -p "$out"
unzip -p "$weights_zip" rtnn/realtime_nn_real_sequence_fixed_weights_generated.h \
  > "$out/realtime_nn_real_sequence_fixed_weights_generated.h"
weights_sha=$(sha256sum "$out/realtime_nn_real_sequence_fixed_weights_generated.h" | cut -d' ' -f1)
[[ "$weights_sha" == '961a76b7e220bf2f665e7c04ab62063600aa2e7eccf3403d80ea730bc993ad9f' ]] || {
  echo 'frozen Q15 weights hash mismatch' >&2; exit 3;
}

clang -std=c11 -O2 -Wall -Wextra \
  -I"$model" -I"$board/generated" -I"$board/firmware" -I"$out" \
  "$test" "$runner" "$core" -o "$out/test_c2_cycle_measurement" \
  2>&1 | tee "$out/compile.log"
"$out/test_c2_cycle_measurement" | tee "$out/run.log"
printf 'frozen_core_sha256=%s\nfrozen_weights_sha256=%s\n' \
  "$(sha256sum "$core" | cut -d' ' -f1)" "$weights_sha" > "$out/source_sha256.txt"
