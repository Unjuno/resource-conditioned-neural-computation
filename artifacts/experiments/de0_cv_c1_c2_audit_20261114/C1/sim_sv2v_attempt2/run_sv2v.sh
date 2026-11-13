#!/usr/bin/env bash
cd /mnt/d/rtnn_de0cv_c1_autonomous_selftest_20261110/sim_sv2v_retry || exit 99
sv2v --version > sv2v_version.txt 2>&1; echo sv2v_version_exit=$?
verilator --version > verilator_version.txt 2>&1; echo verilator_version_exit=$?
sv2v rtnn_diag_packet_engine.sv rtnn_c1_selftest_checker.sv rtnn_c1_autonomous_selftest.sv tb_rtnn_c1_autonomous_selftest.sv > rtnn_c1_autonomous_selftest_sv2v.v 2> sv2v_convert.log
sv2v_exit=$?
echo sv2v_exit=$sv2v_exit
if [ $sv2v_exit -ne 0 ]; then exit $sv2v_exit; fi
verilator --binary --timing --top-module tb_rtnn_c1_autonomous_selftest -Wno-fatal ibex_flat.v rtnn_c1_autonomous_selftest_sv2v.v > verilator_compile.log 2>&1
compile_exit=$?
echo compile_exit=$compile_exit
printf 'warning_lines='; grep -c '^%Warning' verilator_compile.log || true
printf 'wrapper_warning_lines='; grep -cE '%Warning.*(rtnn_c1_autonomous_selftest|rtnn_c1_selftest_checker|rtnn_diag_packet_engine)' verilator_compile.log || true
if [ $compile_exit -ne 0 ]; then exit $compile_exit; fi
./obj_dir/Vtb_rtnn_c1_autonomous_selftest > verilator_run.log 2>&1
sim_exit=$?
cat verilator_run.log
echo sim_exit=$sim_exit
exit $sim_exit