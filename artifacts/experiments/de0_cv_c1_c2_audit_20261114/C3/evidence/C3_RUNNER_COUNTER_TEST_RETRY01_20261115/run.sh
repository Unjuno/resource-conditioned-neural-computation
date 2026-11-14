#!/usr/bin/env bash
set -uo pipefail
cd "$(dirname "$0")" || exit 90
repo=/mnt/c/Users/junny/OneDrive/ドキュメント/ChatGPT/resource-conditioned-neural-computation-audit-20261114
src="$repo/artifacts/experiments/de0_cv_c1_c2_audit_20261114/C3/source/measurement_protocol_v2_43334531_20261115"
printf 'cwd=%s\n' "$(pwd)" > command.log
gcc --version | head -1 >> command.log
gcc -std=c11 -O2 -Wall -Wextra -Werror \
  -I"$src" -I"$src/firmware" -I"$src/model" -I"$src/generated" \
  test_runner_cycles.c "$src/firmware/rtnn_experiment_runner.c" \
  "$src/model/realtime_nn_real_sequence_fixed_core.c" \
  -o test_runner_cycles >compile.log 2>&1
rc=$?; echo "$rc" > compile.exitcode
if [[ $rc -ne 0 ]]; then exit "$rc"; fi
./test_runner_cycles >run.log 2>&1
rc=$?; echo "$rc" > run.exitcode
sha256sum test_runner_cycles test_runner_cycles.c run.sh > sha256.txt
exit "$rc"
