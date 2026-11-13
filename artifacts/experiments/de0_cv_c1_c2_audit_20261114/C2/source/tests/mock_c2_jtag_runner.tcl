# Deterministic host-only mock for run_c2_jtag.tcl. No Quartus JTAG package or hardware is used.
if {$argc != 6} {error "usage: tclsh mock_c2_jtag_runner.tcl CASES.csv RUNNER.tcl OUT_DIR SOF_SHA256 EXPERIMENT_ID SCENARIO"}
lassign $argv cases_path runner_path out_dir sof_sha experiment_id scenario
set ::mock_scenario $scenario
package provide ::quartus::jtag 1.0
set ::mock_cases {}
set f [open $cases_path r]
gets $f
while {[gets $f line] >= 0} {if {$line ne {}} {lappend ::mock_cases [split $line ,]}}
close $f
set ::mock_index -1
set ::mock_ir 0
set ::mock_active 0
set ::mock_response {}
set ::mock_build_id [string tolower [lindex [lindex $::mock_cases 0] 25]]
proc get_hardware_names {} {
  if {$::mock_scenario eq "no_hardware"} {return {}}
  return [list {USB-Blaster [USB-0]}]
}
proc get_device_names {args} {return [list {1) 5CEBA4F23C7 Cyclone V}]}
proc open_device {args} {return {}}
proc close_device {} {return {}}
proc device_lock {args} {return {}}
proc device_unlock {} {return {}}
proc device_virtual_ir_shift {args} {
  set i [lsearch -exact $args -ir_value]
  set ::mock_ir [lindex $args [expr {$i+1}]]
  return {}
}
proc mock_put_u16 {arrName offset value} {
  upvar 1 $arrName a
  lset a $offset [expr {$value & 255}]
  lset a [expr {$offset+1}] [expr {($value >> 8) & 255}]
}
proc mock_put_u32 {arrName offset value} {
  upvar 1 $arrName a
  for {set j 0} {$j < 4} {incr j} {lset a [expr {$offset+$j}] [expr {($value >> (8*$j)) & 255}]}
}
proc mock_bytes_to_hex {bytes} {
  set s {}
  foreach b [lreverse $bytes] {append s [format %02x $b]}
  return $s
}
proc device_virtual_dr_shift {args} {
  set data_index [lsearch -exact $args -dr_value]
if {$::mock_ir == 4} {return $::mock_build_id}
  if {$::mock_ir == 3} {
    if {$::mock_active} {
      if {$::mock_scenario eq "timeout" ||
          ($::mock_scenario eq "timeout_second" && $::mock_index == 1)} {return 18}
      set ::mock_active 0
      return 48
    }
    return 08
  }
  if {$::mock_ir == 1 && $data_index >= 0} {
    incr ::mock_index
    if {$::mock_index >= [llength $::mock_cases]} {error "unexpected request beyond 42"}
    set row [lindex $::mock_cases $::mock_index]
    set expected [c2_pack_lsb_hex [lindex $row 21]]
    set got [lindex $args [expr {$data_index+1}]]
    if {$got ne $expected} {error "request wire bytes mismatch at row [expr {$::mock_index+1}]"}
    set r [lrepeat 48 0]
    foreach {i b} {0 82 1 84 2 78 3 82 4 1 5 0} {lset r $i $b}
    lset r 6 [lindex $row 5]
    lset r 7 [lindex $row 13]
    mock_put_u32 r 8 [lindex $row 0]
    mock_put_u16 r 12 [lindex $row 4]
    mock_put_u16 r 14 [lindex $row 8]
    mock_put_u32 r 16 [lindex $row 26]
    foreach {i col} {20 9 21 10 22 11 23 12} {lset r $i [lindex $row $col]}
    mock_put_u32 r 24 [expr {1000 + $::mock_index}]
    foreach {i b} {28 78 29 78 30 84 31 82} {lset r $i $b}
    scan $::mock_build_id %x mock_build_numeric
    mock_put_u32 r 32 $mock_build_numeric
    mock_put_u32 r 44 [c2_crc32 [lrange $r 0 43]]
    set ::mock_response $r
    set ::mock_active 1
    return 0
  }
  if {$::mock_ir == 2 && $data_index < 0} {return [mock_bytes_to_hex $::mock_response]}
  error "unexpected mock DR operation: IR=$::mock_ir args=$args"
}
if {$scenario eq "bad_build"} {set ::mock_build_id deadbeef}
if {$scenario eq "timeout" || $scenario eq "timeout_second"} {proc after {args} {return {}}}
set argv [list $cases_path $out_dir $sof_sha $experiment_id]
set argc 4
set source_rc [catch {source $runner_path} source_message source_options]
if {[c2_csv_quote {a,"b}] ne "\"a,\"\"b\""} {error "CSV error-field quoting failed"}
if {[c2_json_quote {a,"b}] ne "\"a,\\\"b\""} {error "JSON error-field quoting failed"}
if {$scenario eq "timeout" || $scenario eq "timeout_second"} {
  if {!$source_rc} {error "expected timeout rejection"}
  set expected_index [expr {$scenario eq "timeout" ? 0 : 1}]
  set expected_count [expr {$scenario eq "timeout" ? 1 : 2}]
  set expected_completed [expr {$scenario eq "timeout" ? 0 : 1}]
  set expected_seq [expr {$scenario eq "timeout" ? 1 : 2}]
  if {$::mock_index != $expected_index} {error "timeout occurred after unexpected request count"}
  set jf [open [file join $out_dir c2_jtag_results.json] r]
  set json [read $jf]
  close $jf
  if {![regexp "\\\"status\\\":\\\"FAIL\\\",\\\"count\\\":$expected_count,\\\"completed_count\\\":$expected_completed" $json]} {error "timeout JSON status/count incorrect"}
  set row_index [string first [format {"seq":%d,} $expected_seq] $json]
  set expected_failure [format {"cycles":null,"cycle_valid":false,"status":"TIMEOUT","error":"timeout seq=%d last_status=0x18"} $expected_seq]
  if {$row_index < 0 || [string first $expected_failure [string range $json $row_index end]] < 0} {error "timeout case row missing or malformed"}
  set cf [open [file join $out_dir c2_jtag_results.csv] r]
  set csv [split [string trim [read $cf]] "\n"]
  close $cf
  if {[llength $csv] != [expr {$expected_count+1}] || ![regexp ",TIMEOUT,\\\"timeout seq=$expected_seq last_status=0x18\\\"$" [lindex $csv end]]} {error "timeout CSV failure row missing"}
  set rf [open [file join $out_dir c2_jtag_raw.log] r]
  set raw [read $rf]
  close $rf
  if {![regexp "timeout seq=$expected_seq" $raw]} {error "timeout reason missing from raw log"}
  puts "C2_HOST_TIMEOUT_GUARD_PASS timed_out_seq=$expected_seq status=FAIL physical_jtag=NONE"
  exit 0
}
if {$scenario eq "no_hardware"} {
  if {!$source_rc} {error "expected missing-hardware rejection"}
  if {$::mock_index != -1} {error "runner attempted a JTAG request without hardware"}
  set jf [open [file join $out_dir c2_jtag_results.json] r]
  set json [read $jf]
  close $jf
  if {![regexp {"status":"FAIL","count":0,"completed_count":0} $json]} {error "missing-hardware JSON status/count incorrect"}
  set rf [open [file join $out_dir c2_jtag_raw.log] r]
  set raw [read $rf]
  close $rf
  if {![regexp {error=USB-Blaster not detected} $raw]} {error "missing-hardware reason absent from raw log"}
  puts "C2_HOST_NO_HARDWARE_GUARD_PASS requests=0 status=FAIL physical_jtag=MOCK_ONLY"
  exit 0
}
if {$scenario eq "bad_build"} {
  if {!$source_rc} {error "expected wrong-build rejection"}
  if {$::mock_index != -1} {error "host sent a request before rejecting the build"}
  set jf [open [file join $out_dir c2_jtag_results.json] r]
  set json [read $jf]
  close $jf
  if {![regexp {"status":"FAIL","count":0} $json]} {error "wrong-build JSON status/count incorrect"}
  puts "C2_HOST_BAD_BUILD_GUARD_PASS requests=0 status=FAIL physical_jtag=NONE"
  exit 0
}
if {$source_rc} {return -options $source_options $source_message}
if {$::mock_index != 41} {error "mock saw [expr {$::mock_index+1}] requests, expected 42"}
set csv_file [open [file join $out_dir c2_jtag_results.csv] r]
set csv_lines [split [string trim [read $csv_file]] "\n"]
close $csv_file
if {[llength $csv_lines] != 43} {error "CSV output row count [llength $csv_lines], expected 43 including header"}
set json_file [open [file join $out_dir c2_jtag_results.json] r]
set json [read $json_file]
close $json_file
if {![regexp {"status":"PASS","count":42,"completed_count":42} $json]} {error "JSON output lacks PASS/42 status"}
puts "C2_HOST_FULL_MOCK_PASS requests=42 csv_rows=43 json_status=PASS physical_jtag=NONE"
