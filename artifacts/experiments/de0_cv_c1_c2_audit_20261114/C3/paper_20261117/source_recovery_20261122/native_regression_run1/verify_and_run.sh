#!/usr/bin/env bash
set -euo pipefail
if ! sha256sum -c source_manifest_exact.sha256 > source_hash_check.log 2>&1; then
  echo FAIL > source_hash_check.status
  exit 98
fi
echo PASS > source_hash_check.status
if bash ./run_native_v2_regression.sh; then rc=0; else rc=$?; fi
echo "$rc" > overall.exitcode
exit "$rc"