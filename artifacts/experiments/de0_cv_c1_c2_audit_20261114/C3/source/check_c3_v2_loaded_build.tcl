# Read-only USB-Blaster/Virtual-JTAG identity check for the C3 v2 reset replay.
# This file has no Programmer, configuration, flash, erase, or user-DR write call.
package require ::quartus::jtag

proc c3_lsb_bytes {hex n} {
  set h [string tolower [string trim $hex]]
  regsub -all {^(0x|0X)} $h {} h
  if {![regexp {^[0-9a-f]+$} $h]} {error "invalid JTAG hex value: $h"}
  if {[string length $h] % 2} {set h "0$h"}
  if {[string length $h] > 2*$n} {error "too many JTAG bytes"}
  set h [string repeat 0 [expr {2*$n-[string length $h]}]]$h
  set bytes {}
  for {set i [expr {[string length $h]-2}]} {$i >= 0} {incr i -2} {
    scan [string range $h $i [expr {$i+1}]] %x b
    lappend bytes $b
  }
  return $bytes
}
proc c3_u32 {bytes} {
  set v 0
  for {set i 0} {$i < 4} {incr i} {set v [expr {$v | ([lindex $bytes $i] << (8*$i))}]}
  return $v
}
proc c3_scan_read {instance ir bits} {
  device_virtual_ir_shift -instance_index $instance -ir_value $ir -no_captured_ir_value
  return [device_virtual_dr_shift -instance_index $instance -length $bits -value_in_hex]
}
proc c3_identity_selftest {} {
  set b [c3_lsb_bytes 43334531 4]
  if {[c3_u32 $b] != 0x43334531} {error "build ID little-endian decode failed"}
  if {[lindex [c3_lsb_bytes 08 1] 0] != 0x08} {error "READY mask decode failed"}
  puts "PASS C3V2_IDENTITY_TCL_SELFTEST; no JTAG commands issued"
}

if {$argc == 1 && [lindex $argv 0] eq "--self-test"} {
  c3_identity_selftest
  return
}
if {$argc != 0} {error "usage: quartus_stp_tcl.exe -t check_c3_v2_loaded_build.tcl [--self-test]"}

set hardware {}
foreach h [get_hardware_names] {if {[string match "USB-Blaster*" $h]} {lappend hardware $h}}
if {[llength $hardware] != 1} {error "expected exactly one USB-Blaster; found: $hardware"}
set hw [lindex $hardware 0]
set devices {}
foreach d [get_device_names -hardware_name $hw] {if {[string match "*5CE*" $d]} {lappend devices $d}}
if {[llength $devices] != 1} {error "expected exactly one Cyclone V; found: $devices"}
set dev [lindex $devices 0]
if {![regexp -nocase {0x02b050dd} $dev]} {error "unexpected DE0-CV JTAG IDCODE: $dev"}
set opened 0
set locked 0
set rc [catch {
  open_device -hardware_name $hw -device_name $dev
  set opened 1
  device_lock -timeout 10000
  set locked 1
  set build [c3_u32 [c3_lsb_bytes [c3_scan_read 0 4 32] 4]]
  set status [lindex [c3_lsb_bytes [c3_scan_read 0 3 8] 1] 0]
  if {$build != 0x43334531} {error [format "C3 v2 build mismatch: got 0x%08x expected 0x43334531" $build]}
  if {$status & 0x80} {error "mailbox ERROR status is set"}
  if {!($status & 0x08)} {error [format "mailbox not READY: status=0x%02x" $status]}
  puts [format "PASS READ_ONLY_IDENTITY hardware=%s device=%s build_id=0x%08x status=0x%02x" $hw $dev $build $status]
} message options]
if {$locked} {catch {device_unlock}}
if {$opened} {catch {close_device}}
if {$rc} {return -options $options $message}
