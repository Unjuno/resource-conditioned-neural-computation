"""Run the v2 Tcl protocol against an isolated Quartus Tcl mock (never hardware)."""
import csv
import json
import os
import shutil
import subprocess
import tempfile
import unittest
from pathlib import Path

PKG = Path(__file__).resolve().parents[1]
STP = Path(os.environ.get(
    "QUARTUS_STP_TCL",
    r"C:\altera_lite\25.1std\quartus\bin64\quartus_stp_tcl.exe",
))

MOCK = r'''package require ::quartus::jtag
rename get_hardware_names real_get_hardware_names
proc get_hardware_names {} {return [list {USB-Blaster [USB-0]}]}
rename get_device_names real_get_device_names
proc get_device_names {args} {return [list {@1: 5CE(BA4|FA4) (0x02B050DD)}]}
rename open_device real_open_device
proc open_device {args} {return}
rename close_device real_close_device
proc close_device {} {return}
rename device_lock real_device_lock
proc device_lock {args} {return}
rename device_unlock real_device_unlock
proc device_unlock {} {return}
rename device_virtual_ir_shift real_device_virtual_ir_shift
proc device_virtual_ir_shift {args} {
  set i [lsearch -exact $args -ir_value]
  set ::mock_ir [lindex $args [expr {$i+1}]]
}
proc mock_put {name offset width value} {
  upvar 1 $name b
  for {set i 0} {$i<$width} {incr i} {
    lset b [expr {$offset+$i}] [expr {($value>>(8*$i))&255}]
  }
}
rename device_virtual_dr_shift real_device_virtual_dr_shift
proc device_virtual_dr_shift {args} {
  set wi [lsearch -exact $args -dr_value]
  if {$wi>=0} {
    set value [lindex $args [expr {$wi+1}]]
    set li [lsearch -exact $args -length]
    set bits [lindex $args [expr {$li+1}]]
    if {$::mock_ir==2 && $bits==480 && [string length $value]==120} {set ::mock_started 0; return [xpack $::mock_response]}
    if {$::mock_ir!=1 || $bits!=800 || [string length $value]!=200} {error "bad mocked request width ir=$::mock_ir bits=$bits hex_length=[string length $value]"}
    set req [xbytes $value 100]
    if {[xget $req 28 4] != [xcrc [lrange $req 0 27]] || [xget $req 96 4] != [xcrc [lrange $req 32 95]]} {error "mock request CRC mismatch"}
    set seq [xget $req 8 4]
    set fields [dict get $::mock_cases $seq]
    set mode [lindex $fields 4]
    set stop [lindex $fields 11]
    set b [lrepeat 60 0]
    foreach {i v} {0 82 1 84 2 78 3 82 4 3 5 0 23 255 52 1} {lset b $i $v}
    mock_put b 6 1 [expr {$mode eq "fixed2" ? 1 : 3}]
    mock_put b 7 1 [dict get {none 0 entropy 1 budget 2} $stop]
    mock_put b 8 4 $seq
    mock_put b 12 2 [xget $req 12 2]
    mock_put b 14 2 65535
    mock_put b 16 4 [xget $req 96 4]
    mock_put b 20 1 [lindex $fields 9]
    mock_put b 21 1 [lindex $fields 10]
    mock_put b 22 1 [lindex $fields 8]
    mock_put b 24 8 [expr {1000000+$seq*1000}]
    mock_put b 32 8 [expr {1000100+$seq*1000}]
    mock_put b 40 4 0x52544e4e
    mock_put b 44 4 0x45585631
    mock_put b 48 4 0x45585632
    mock_put b 56 4 [xcrc [lrange $b 0 55]]
    set ::mock_response $b
    set ::mock_started 1
    return ""
  }
  set li [lsearch -exact $args -length]
  set bits [lindex $args [expr {$li+1}]]
  if {$::mock_ir==4 && $bits==32} {return "45585631"}
  if {$::mock_ir==3 && $bits==8} {return [expr {$::mock_started ? "40" : "08"}]}
  if {$::mock_ir==2 && $bits==480} {
    set ::mock_started 0
    return [xpack $::mock_response]
  }
  error "unexpected mocked scan IR=$::mock_ir bits=$bits"
}
set f [open [lindex $::argv 0] r]
gets $f
set ::mock_cases [dict create]
while {[gets $f line]>=0} {if {$line ne ""} {set row [split $line ,]; dict set ::mock_cases [lindex $row 2] $row}}
close $f
set ::mock_started 0
set cases [lindex $::argv 0]
set out [lindex $::argv 1]
set binding [lindex $::argv 2]
set runner [lindex $::argv 3]
set ::argv [list $cases $out $binding]
set ::argc 3
source $runner
'''


class MockRuntime(unittest.TestCase):
    @unittest.skipUnless(STP.is_file(), "Quartus STP Tcl not installed")
    def test_twenty_request_protocol_and_fixture_rejection(self):
        with tempfile.TemporaryDirectory(prefix="rtnn_extval_v2_mock_") as td:
            root = Path(td)
            (root / "host").mkdir()
            (root / "safety_gates_v1_20261122").mkdir()
            cases = PKG / "build" / "physical_pilot_RUN2_preparation_attempt2" / "case_set" / "cases.csv"
            binding = PKG / "build" / "physical_pilot_RUN2_preparation_attempt2" / "binding.json"
            shutil.copy2(PKG / "host_v2_20261126" / "run_external_validation.tcl", root / "host" / "run_external_validation.tcl")
            # Test-only copy is explicitly marked mock so production audit rejects it.
            runner = root / "host" / "run_external_validation.tcl"
            text = runner.read_text(encoding="utf-8")
            runner.write_text(text.replace('"mock":false', '"mock":true'), encoding="utf-8")
            shutil.copy2(PKG / "safety_gates_v1_20261122" / "pilot_gate.py", root / "safety_gates_v1_20261122" / "pilot_gate.py")
            shutil.copy2(cases, root / "cases.csv")
            shutil.copy2(binding, root / "binding.json")
            wrapper = root / "mock.tcl"
            wrapper.write_text(MOCK, encoding="ascii")
            p = subprocess.run(
                [str(STP), "-t", str(wrapper), str(root / "cases.csv"), str(root / "out"), str(root / "binding.json"), str(runner)],
                capture_output=True, text=True, encoding="utf-8", errors="replace", timeout=90,
            )
            self.assertEqual(p.returncode, 0, p.stdout + p.stderr)
            run = root / "out"
            status = json.loads((run / "run_status.json").read_text(encoding="utf-8"))
            self.assertEqual(status["status"], "COMPLETE")
            self.assertTrue(status["mock"])
            self.assertEqual(status["completed_cases"], 20)
            self.assertEqual(status["expected_cases"], 20)
            with (run / "physical_results.csv").open(encoding="utf-8", newline="") as f:
                rows = list(csv.DictReader(f))
            self.assertEqual(len(rows), 20)
            self.assertTrue(all(r["status"] == "PASS" and int(r["cycles"]) == 100 for r in rows))
            raw = (run / "raw_jtag.log").read_text(encoding="utf-8")
            self.assertEqual(sum(x.startswith("request seq=") for x in raw.splitlines()), 20)
            self.assertEqual(sum(x.startswith("response seq=") for x in raw.splitlines()), 20)
            # A synthetic COMPLETE run must remain in Temp and be rejected by production pilot audit.
            self.assertTrue(root.is_relative_to(Path(tempfile.gettempdir())))
            self.assertFalse((PKG / "build" / "physical_pilot_RUN3").exists())
            self.assertTrue(status["mock"])
            code = "import sys; from pathlib import Path; sys.path.insert(0, r'%s'); from audit_and_analyze import load_run; load_run(Path(r'%s'), 'pilot')" % (PKG / "scripts", run)
            p = subprocess.run(["python", "-c", code], capture_output=True, text=True, encoding="utf-8", errors="replace")
            self.assertNotEqual(p.returncode, 0)
            self.assertIn("actual USB-Blaster", p.stderr)


if __name__ == "__main__":
    unittest.main(verbosity=2)
