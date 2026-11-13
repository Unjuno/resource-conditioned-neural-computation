#!/usr/bin/env bash
cd /mnt/c/Users/junny/OneDrive/ドキュメント/ChatGPT/RTNN/de0cv_setup/stage3_experiments/ibex_csa_2026-11-03/c1_autonomous_selftest_20261110
/tmp/rtnn_checker_obj/Vrtnn_c1_selftest_checker_tb > checker_run.log 2>&1
result=$?
cat checker_run.log
echo run_exit=$result
exit $result