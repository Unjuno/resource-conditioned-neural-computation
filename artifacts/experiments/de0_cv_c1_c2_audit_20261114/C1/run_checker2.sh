#!/usr/bin/env bash
cd /mnt/c/Users/junny/OneDrive/ドキュメント/ChatGPT/RTNN/de0cv_setup/stage3_experiments/ibex_csa_2026-11-03/c1_autonomous_selftest_20261110
verilator --binary --timing --top-module rtnn_c1_selftest_checker_tb -Wno-fatal rtnn_c1_selftest_checker.sv rtnn_c1_selftest_checker_tb.sv --Mdir /tmp/rtnn_checker_obj > checker_compile2.log 2>&1
result=$?
echo compile_exit=$result
printf 'warning_lines='; grep -c '^%Warning' checker_compile2.log || true
if [ $result -eq 0 ]; then
  /tmp/rtnn_checker_obj/Vrtnn_c1_selftest_checker_tb > checker_run2.log 2>&1
  result=$?
  cat checker_run2.log
  echo checker_exit=$result
fi
exit $result