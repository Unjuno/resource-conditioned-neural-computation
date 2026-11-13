#!/usr/bin/env bash
cd /mnt/d/rtnn_de0cv_c1_autonomous_selftest_20261110/sim
verilator --binary --timing --top-module tb_rtnn_c1_autonomous_selftest -Wno-fatal ../ibex_flat.v ../rtnn_diag_packet_engine.sv ../rtnn_c1_selftest_checker.sv rtnn_c1_autonomous_selftest.sv tb_rtnn_c1_autonomous_selftest.sv > verilator_compile.log 2>&1
result=$?
echo compile_exit=$result
printf 'warning_lines='; grep -c '^%Warning' verilator_compile.log || true
printf 'new_rtl_warning_lines='; grep -cE '%Warning.*(rtnn_c1_autonomous_selftest|rtnn_c1_selftest_checker|rtnn_diag_packet_engine)' verilator_compile.log || true
grep -E '%Warning.*(rtnn_c1_autonomous_selftest|rtnn_c1_selftest_checker|rtnn_diag_packet_engine)' verilator_compile.log || true
if [ $result -eq 0 ]; then
  ./obj_dir/Vtb_rtnn_c1_autonomous_selftest > verilator_run.log 2>&1
  result=$?
  cat verilator_run.log
  echo sim_exit=$result
fi
exit $result