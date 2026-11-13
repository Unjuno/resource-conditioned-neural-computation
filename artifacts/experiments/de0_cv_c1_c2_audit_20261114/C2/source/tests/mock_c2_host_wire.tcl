# Host regression only. Wire fixtures are generated independently in Python.
# No vendor package, USB device, or board is accessed.
lassign $argv runner cases out sof experiment fixture selection scenario
set ::wire_scenario $scenario
set ::wire_trace [open [file join $out mock_transport.log] w]
fconfigure $::wire_trace -buffering line
set f [open $fixture r]
set ::wire_rows [split [string trim [read $f]] "\n"]
close $f
set ::wire_index -1
set ::wire_ir 0
set ::wire_active 0
package provide ::quartus::jtag 1.0
proc get_hardware_names {} {
  if {$::wire_scenario eq "no_hardware"} {return {}}
  if {$::wire_scenario eq "ambiguous_hardware"} {
    return [list {USB-Blaster [USB-0]} {USB-Blaster [USB-1]}]
  }
  return [list {USB-Blaster [USB-0]}]
}
proc get_device_names {args} {return [list {1) 5CEBA4F23C7 Cyclone V}]}
proc open_device {args} {puts $::wire_trace OPEN}
proc close_device {} {puts $::wire_trace CLOSE}
proc device_lock {args} {}
proc device_unlock {} {}
proc after {args} {}
proc device_virtual_ir_shift {args} {
  set ::wire_ir [lindex $args [expr {[lsearch -exact $args -ir_value]+1}]]
}
proc device_virtual_dr_shift {args} {
  if {$::wire_ir == 4} {
    if {$::wire_scenario eq "bad_build"} {return deadbeef}
    return 43324a32
  }
  if {$::wire_ir == 3} {
    if {!$::wire_active} {return 08}
    if {$::wire_scenario eq "timeout"} {return 18}
    set ::wire_active 0
    return 48
  }
  if {$::wire_ir == 1} {
    incr ::wire_index
    if {$::wire_index >= [llength $::wire_rows]} {error "extra request"}
    lassign [split [lindex $::wire_rows $::wire_index] |] seq request response
    set got [lindex $args [expr {[lsearch -exact $args -dr_value]+1}]]
    if {$got ne $request} {error "wire payload does not match selected frozen sequence $seq"}
    set ::wire_response $response
    set ::wire_active 1
    puts $::wire_trace "REQUEST $seq"
    return 0
  }
  if {$::wire_ir == 2} {
    puts $::wire_trace "RESPONSE $::wire_response"
    return $::wire_response
  }
  error "unexpected IR $::wire_ir"
}
set argv [list $cases $out $sof $experiment]
if {$selection ne "ALL"} {lappend argv $selection}
set argc [llength $argv]
set code [catch {source $runner} msg opts]
close $::wire_trace
if {$code} {puts stderr $msg; exit 1}
exit 0
