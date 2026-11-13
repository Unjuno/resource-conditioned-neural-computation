load_package jtag

proc rtnn_crc32 {bytes} {
  set crc 0xffffffff
  foreach b $bytes {
    set c [expr {$crc ^ ($b & 0xff)}]
    for {set i 0} {$i < 8} {incr i} {
      if {$c & 1} {set c [expr {(($c >> 1) ^ 0xedb88320) & 0xffffffff}]} \
      else {set c [expr {($c >> 1) & 0xffffffff}]} 
    }
    set crc $c
  }
  return [expr {(~$crc) & 0xffffffff}]
}
proc rtnn_pack_lsb_hex {bytes} {
  set out ""
  for {set i [expr {[llength $bytes]-1}]} {$i >= 0} {incr i -1} {append out [format %02x [lindex $bytes $i]]}
  return $out
}
proc rtnn_unpack_lsb_hex {hex count} {
  set hex [string trim $hex]
  regsub -all {^(0x|0X)} $hex {} hex
  if {[expr {[string length $hex] % 2}]} {set hex "0$hex"}
  set hex [string tolower $hex]
  set hex [string repeat 0 [expr {2*$count-[string length $hex]}]]$hex
  if {[string length $hex] != 2*$count} {error "unexpected scan width: $hex"}
  set out {}
  for {set i [expr {[string length $hex]-2}]} {$i >= 0} {incr i -2} {
    scan [string range $hex $i [expr {$i+1}]] %x b
    lappend out $b
  }
  return $out
}
proc rtnn_make_request {mode depth seq input_id budget_q16} {
  set b [lrepeat 32 0]
  foreach {i v} {0 0x52 1 0x54 2 0x4e 3 0x51 4 1} {lset b $i $v}
  lset b 5 $mode; lset b 6 $depth
  for {set i 0} {$i < 4} {incr i} {lset b [expr {8+$i}] [expr {($seq >> (8*$i)) & 255}]}
  lset b 12 [expr {$input_id & 255}]; lset b 13 [expr {($input_id >> 8) & 255}]
  lset b 14 [expr {$budget_q16 & 255}]; lset b 15 [expr {($budget_q16 >> 8) & 255}]
  foreach {i v} {20 0x4e 21 0x4e 22 0x54 23 0x52 24 0x32 25 0x30 26 0x56 27 0x44} {lset b $i $v}
  set crc [rtnn_crc32 [lrange $b 0 27]]
  for {set i 0} {$i < 4} {incr i} {lset b [expr {28+$i}] [expr {($crc >> (8*$i)) & 255}]}
  return $b
}
proc rtnn_jtag_scan {instance ir length value_hex} {
  device_virtual_ir_shift -instance_index $instance -ir_value $ir -no_captured_ir_value
  if {$value_hex eq ""} {return [device_virtual_dr_shift -instance_index $instance -length $length -value_in_hex]}
  return [device_virtual_dr_shift -instance_index $instance -length $length -dr_value $value_hex -value_in_hex]
}
set ::rtnn_expected_build_id 0x43324a31
if {[info exists ::env(RTNN_C2_EXPECTED_BUILD_ID)]} {
  set candidate [string tolower $::env(RTNN_C2_EXPECTED_BUILD_ID)]
  if {![regexp {^[0-9a-f]{8}$} $candidate]} {error "RTNN_C2_EXPECTED_BUILD_ID must be 8 hex digits"}
  set ::rtnn_expected_build_id [expr {0x$candidate}]
}
proc rtnn_check_build_id {instance} {
  global rtnn_expected_build_id
  set raw [rtnn_jtag_scan $instance 4 32 ""]
  set bytes [rtnn_unpack_lsb_hex $raw 4]
  set expected [list [expr {$rtnn_expected_build_id & 255}] \
    [expr {($rtnn_expected_build_id >> 8) & 255}] \
    [expr {($rtnn_expected_build_id >> 16) & 255}] \
    [expr {($rtnn_expected_build_id >> 24) & 255}]]
  if {$bytes ne $expected} {error "wrong C2 bitstream identity: got $bytes expected $expected"}
  puts [format "C2_JTAG_BUILD_ID_PASS id=%08x" $rtnn_expected_build_id]
}
proc rtnn_run_one {instance mode depth seq input_id budget_q16 expected_admit expected_exec expected_pred expected_label expected_stop} {
  set req [rtnn_make_request $mode $depth $seq $input_id $budget_q16]
  rtnn_jtag_scan $instance 1 256 [rtnn_pack_lsb_hex $req]
  set status 0
  for {set poll 0} {$poll < 20000} {incr poll} {
    set s [rtnn_jtag_scan $instance 3 8 ""]
    scan $s %x status
    if {(($status >> 5) & 1) && !(($status >> 4) & 1)} {break}
    after 1
  }
  if {(($status >> 5) & 1) == 0 || (($status >> 4) & 1) != 0 || (($status >> 6) & 3) != 0} {
    error [format "diagnostic status timeout/error: 0x%02x" $status]
  }
  set r [rtnn_unpack_lsb_hex [rtnn_jtag_scan $instance 2 384 ""] 48]
  if {[lrange $r 0 3] ne {82 84 78 82}} {error "bad RTNR magic"}
  if {[lindex $r 4] != 1 || [lindex $r 5] != 0 || [lindex $r 6] != $mode} {error "bad RTNR version/status/mode"}
  set got_seq 0; for {set i 0} {$i < 4} {incr i} {set got_seq [expr {$got_seq | ([lindex $r [expr {8+$i}]] << (8*$i))}]}
  if {$got_seq != $seq} {error "RTNR sequence mismatch"}
  set got_input [expr {[lindex $r 12] | ([lindex $r 13] << 8)}]
  set got_budget [expr {[lindex $r 14] | ([lindex $r 15] << 8)}]
  if {$got_input != $input_id || $got_budget != $budget_q16} {error "RTNR input/budget mismatch"}
  foreach {idx expected name} [list 20 $expected_admit admitted 21 $expected_exec executed 22 $expected_pred prediction 23 $expected_label label 7 $expected_stop stop] {
    if {[lindex $r $idx] != $expected} {error "$name mismatch: got [lindex $r $idx], expected $expected"}
  }
  if {[lrange $r 28 31] ne {78 78 84 82} || [lrange $r 32 35] ne {50 48 86 68}} {error "RTNR model/build identity mismatch"}
  set got_crc 0; for {set i 0} {$i < 4} {incr i} {set got_crc [expr {$got_crc | ([lindex $r [expr {44+$i}]] << (8*$i))}]}
  if {$got_crc != [rtnn_crc32 [lrange $r 0 43]]} {error "RTNR CRC mismatch"}
  set cycles 0; for {set i 0} {$i < 4} {incr i} {set cycles [expr {$cycles | ([lindex $r [expr {24+$i}]] << (8*$i))}]}
  if {$cycles == 0} {error "invalid zero mcycle delta"}
  puts [format "C2_VJTAG_Q15_PASS seq=%d mode=%d input_id=%d prediction=%d label=%d admitted=%d executed=%d stop=%d budget_q16=%d mcycle=%u crc=%08x" $seq $mode $input_id [lindex $r 22] [lindex $r 23] [lindex $r 20] [lindex $r 21] [lindex $r 7] $got_budget $cycles $got_crc]
}
proc rtnn_run {} {
  set hw ""
  foreach c [get_hardware_names] {if {[string match "USB-Blaster*" $c]} {set hw $c; break}}
  if {$hw eq ""} {error "USB-Blaster not found"}
  set dev ""
  foreach c [get_device_names -hardware_name $hw] {if {[string match "@1*" $c]} {set dev $c; break}}
  if {$dev eq ""} {error "expected first JTAG device not found"}
  set casefile [file join [file dirname [info script]] c2_cases_sim.csv]
  set f [open $casefile r]
  open_device -hardware_name $hw -device_name $dev
  set locked 0
  set rc [catch {
    device_lock -timeout 10000; set locked 1
    rtnn_check_build_id 0
    set count 0
    while {[gets $f line] >= 0} {
      if {[string trim $line] eq ""} continue
      lassign [split $line ,] mode depth seq input_id budget_q16 admitted executed prediction label stop
      foreach v [list $mode $depth $seq $input_id $budget_q16 $admitted $executed $prediction $label $stop] {
        if {![string is integer -strict $v]} {error "malformed C2 case row: $line"}
      }
      rtnn_run_one 0 $mode $depth $seq $input_id $budget_q16 $admitted $executed $prediction $label $stop
      incr count
    }
    if {$count != 42} {error "expected 42 validated C2 cases, ran $count"}
    rtnn_check_build_id 0
    puts "C2_VJTAG_Q15_CASES_PASS count=$count fixed=21 adaptive=21"
  } msg opts]
  catch {close $f}
  if {$locked} {catch {device_unlock}}
  catch {close_device}
  if {$rc} {return -options $opts $msg}
}
if {$argc > 0 && [lindex $argv 0] eq "run"} {rtnn_run}
