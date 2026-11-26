package require ::quartus::jtag
proc xscan {ir bits} {
  device_virtual_ir_shift -instance_index 0 -ir_value $ir -no_captured_ir_value
  return [device_virtual_dr_shift -instance_index 0 -length $bits -value_in_hex]
}
proc xbytes {hex count} {
  set h [string tolower [string trim $hex]]; regsub -all {^0x} $h {} h
  if {![regexp {^[0-9a-f]+$} $h]} {error "invalid scan hex $h"}
  if {[string length $h] % 2} {set h "0$h"}
  if {[string length $h] > 2*$count} {error "scan exceeds expected width"}
  set h [string repeat 0 [expr {2*$count-[string length $h]}]]$h
  set out {}; for {set i [expr {[string length $h]-2}]} {$i>=0} {incr i -2} {
    scan [string range $h $i [expr {$i+1}]] %x b; lappend out $b
  }; return $out
}
proc xget {b o n} {set v 0; for {set i 0} {$i<$n} {incr i} {set v [expr {$v|([lindex $b [expr {$o+$i}]]<<(8*$i))}]}; return $v}
set hwlist {}; foreach h [get_hardware_names] {if {[string match "USB-Blaster*" $h]} {lappend hwlist $h}}
if {[llength $hwlist] != 1} {error "expected exactly one USB-Blaster; found $hwlist"}
set hw [lindex $hwlist 0]
set devs {}; foreach d [get_device_names -hardware_name $hw] {if {[string match "*5CE*" $d]} {lappend devs $d}}
if {[llength $devs] != 1} {error "expected exactly one Cyclone V; found $devs"}
set dev [lindex $devs 0]
open_device -hardware_name $hw -device_name $dev
device_lock -timeout 10000
set build [xget [xbytes [xscan 4 32] 4] 0 4]
set status [lindex [xbytes [xscan 3 8] 1] 0]
puts [format "READ_ONLY_IDENTITY hardware=%s device=%s build_id=0x%08x mailbox_status=0x%02x ready=%d busy=%d error=%d" $hw $dev $build $status [expr {($status & 0x08)!=0}] [expr {($status & 0x40)!=0}] [expr {($status & 0x80)!=0}]]
device_unlock
close_device

