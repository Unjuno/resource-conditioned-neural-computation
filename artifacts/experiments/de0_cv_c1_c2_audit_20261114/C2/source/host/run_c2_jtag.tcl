# UART-free C2 physical experiment runner. Uses only Virtual-JTAG user DR/IR;
# it contains no Programmer, Flash, erase, or device-configuration command.
package require ::quartus::jtag

proc c2_scan {ir bits value_hex} {
  device_virtual_ir_shift -instance_index 0 -ir_value $ir -no_captured_ir_value
  if {$value_hex eq ""} {
    return [device_virtual_dr_shift -instance_index 0 -length $bits -value_in_hex]
  }
  return [device_virtual_dr_shift -instance_index 0 -length $bits -dr_value $value_hex -value_in_hex]
}
proc c2_unpack_lsb {hex count} {
  set hex [string tolower [string trim $hex]]
  regsub -all {^(0x|0X)} $hex {} hex
  if {![regexp {^[0-9a-f]+$} $hex]} {error "JTAG returned invalid hex: $hex"}
  if {[expr {[string length $hex] % 2}]} {set hex "0$hex"}
  if {[string length $hex] > 2*$count} {error "JTAG returned too many bits: $hex"}
  set hex [string repeat 0 [expr {2*$count-[string length $hex]}]]$hex
  set result {}
  for {set i [expr {[string length $hex]-2}]} {$i >= 0} {incr i -2} {
    scan [string range $hex $i [expr {$i+1}]] %x b
    lappend result $b
  }
  return $result
}
proc c2_pack_lsb_hex {hex} {
  set bytes {}
  for {set i 0} {$i < [string length $hex]} {incr i 2} {
    scan [string range $hex $i [expr {$i+1}]] %x b
    lappend bytes $b
  }
  set out ""
  foreach b [lreverse $bytes] {append out [format %02x $b]}
  return $out
}
proc c2_u16 {bytes offset} {
  return [expr {[lindex $bytes $offset] | ([lindex $bytes [expr {$offset+1}]] << 8)}]
}
proc c2_u32 {bytes offset} {
  set v 0
  for {set i 0} {$i < 4} {incr i} {set v [expr {$v | ([lindex $bytes [expr {$offset+$i}]] << (8*$i))}]}
  return $v
}
proc c2_crc32 {bytes} {
  set crc 0xffffffff
  foreach b $bytes {
    set c [expr {$crc ^ ($b & 0xff)}]
    for {set i 0} {$i < 8} {incr i} {
      if {$c & 1} {set c [expr {(($c >> 1) ^ 0xedb88320) & 0xffffffff}] } \
      else {set c [expr {($c >> 1) & 0xffffffff}]}
    }
    set crc $c
  }
  return [expr {(~$crc) & 0xffffffff}]
}
proc c2_status {} {
  set s [c2_unpack_lsb [c2_scan 3 8 ""] 1]
  return [lindex $s 0]
}
proc c2_json_row {row} {
  set cycles [dict get $row cycles]
  if {$cycles eq ""} {set cycles_json null} else {set cycles_json $cycles}
  set status [c2_json_quote [dict get $row case_status]]
  set failure [c2_json_quote [dict get $row error]]
  set base [format {"seq":%d,"input_id":%d,"mode":%d,"prediction":%s,"reference_label":%d,"admitted_exit":%s,"executed_exit":%s,"cycles":%s,"cycle_valid":%s,"status":%s,"error":%s} \
    [dict get $row seq] [dict get $row input_id] [dict get $row mode] \
    [c2_json_number [dict get $row prediction]] [dict get $row reference_label] \
    [c2_json_number [dict get $row admitted_exit]] [c2_json_number [dict get $row executed_exit]] $cycles_json \
    [expr {$cycles eq "" ? "false" : "true"}] $status $failure]
  foreach key {expected_prediction expected_admitted expected_executed response_seq response_input_id response_mode response_label reported_cycles} {
    append base [format {,"%s":%s} $key [c2_json_number [dict get $row $key]]]
  }
  set crc [dict get $row response_crc_valid]
  append base [format {,"response_crc_valid":%s,"response_lsb_hex":%s} \
    [expr {$crc eq "" ? "null" : ($crc ? "true" : "false")}] \
    [c2_json_quote [dict get $row response_lsb_hex]]]
  return [format "    %c%s%c" 123 $base 125]
}

proc c2_json_number {value} {
  if {$value eq ""} {return null}
  return $value
}

proc c2_sequences {value} {
  if {$value eq "ALL"} {
    set result {}
    for {set i 1} {$i <= 42} {incr i} {lappend result $i}
    return $result
  }
  set result {}
  foreach seq [split $value ,] {
    if {![regexp {^[1-9][0-9]*$} $seq] || $seq > 42} {error "sequence selection must contain IDs 1 through 42"}
    if {[lsearch -exact $result $seq] >= 0} {error "duplicate sequence selection $seq"}
    lappend result $seq
  }
  return $result
}

proc c2_csv_row {experiment_id sof_sha build_id row} {
  set fields [list $experiment_id [string tolower $sof_sha] $build_id]
  foreach key {seq input_id mode prediction reference_label admitted_exit executed_exit cycles} {
    lappend fields [dict get $row $key]
  }
  lappend fields [expr {[dict get $row cycles] eq "" ? 0 : 1}]
  foreach key {expected_prediction expected_admitted expected_executed response_seq response_input_id response_mode response_label reported_cycles response_crc_valid response_lsb_hex} {
    lappend fields [dict get $row $key]
  }
  lappend fields Ibex_mcycle_delta [dict get $row case_status] [c2_csv_quote [dict get $row error]]
  return [join $fields ,]
}

proc c2_json_quote {value} {
  set value [string map [list "\\" "\\\\" "\"" "\\\"" "\n" "\\n" "\r" "\\r" "\t" "\\t"] $value]
  return "\"$value\""
}

proc c2_csv_quote {value} {
  return "\"[string map [list \" \"\"] $value]\""
}

proc c2_json_header {experiment_id sof_sha build_id run_status recorded completed sequences} {
  set scope [expr {$sequences eq [c2_sequences ALL] ? "all_frozen_42" : "subset"}]
  return [format "%c\"schema\":\"rtnn-c2-jtag-results-v2\",\"experiment_id\":\"%s\",\"sof_sha256\":\"%s\",\"build_id\":\"%08x\",\"cycle_source\":\"Ibex mcycle delta read from FPGA via Virtual-JTAG\",\"uart\":false,\"flash_written\":false,\"status\":\"%s\",\"count\":%d,\"completed_count\":%d,\"expected_count\":%d,\"selected_sequences\":%c%s%c,\"scope\":\"%s\",\"cases\":%c" 123 $experiment_id [string tolower $sof_sha] $build_id $run_status $recorded $completed [llength $sequences] 91 [join $sequences ,] 93 $scope 91]
}

proc c2_run {} {
  global argv argc
  if {$argc < 4 || $argc > 5} {error "usage: quartus_stp -t run_c2_jtag.tcl CASES.csv OUT_DIR SOF_SHA256 EXPERIMENT_ID ?SEQ,SEQ,...?"}
  lassign $argv cases_path out_dir sof_sha experiment_id selection
  if {$argc == 4} {set selection ALL}
  set selected_sequences [c2_sequences $selection]
  set expected_count [llength $selected_sequences]
  if {![regexp {^[0-9a-fA-F]{64}$} $sof_sha]} {error "SOF SHA-256 must be 64 hex digits"}
  if {![regexp {^[A-Za-z0-9_.-]+$} $experiment_id]} {error "invalid experiment ID"}
  foreach p [list c2_jtag_results.csv c2_jtag_results.json c2_jtag_raw.log] {
    if {[file exists [file join $out_dir $p]]} {error "refusing to overwrite [file join $out_dir $p]"}
  }
  file mkdir $out_dir
  set cf ""
  set csvout [open [file join $out_dir c2_jtag_results.csv] w]
  set jsonout [open [file join $out_dir c2_jtag_results.json] w]
  set rawout [open [file join $out_dir c2_jtag_raw.log] w]
  fconfigure $csvout -buffering line
  fconfigure $rawout -buffering line
  puts $csvout "experiment_id,sof_sha256,build_id,seq,input_id,mode,prediction,reference_label,admitted_exit,executed_exit,cycles,cycle_valid,expected_prediction,expected_admitted,expected_executed,response_seq,response_input_id,response_mode,response_label,reported_cycles,response_crc_valid,response_lsb_hex,cycle_source,case_status,error"
  puts $rawout "experiment_id=$experiment_id sof_sha256=[string tolower $sof_sha] interface=USB-Blaster/Virtual-JTAG uart=none flash=untouched"
  puts $rawout "selected_sequences=[join $selected_sequences ,] expected_count=$expected_count"

  set locked 0
  set opened 0
  set cases {}
  set input_rows {}
  set rows_by_seq {}
  set expected_build_id ""
  set expected_build 0
  set n 0
  set rc [catch {
    set cf [open $cases_path r]
    set header [gets $cf]
    if {$header eq ""} {error "empty frozen case CSV"}
    while {[gets $cf line] >= 0} {
      if {$line eq ""} continue
      set f [split $line ,]
      if {[llength $f] != 27} {error "bad CSV field count at row [expr {[llength $input_rows]+2}]"}
      set row_build_id [string tolower [lindex $f 25]]
      if {![regexp {^[0-9a-f]{8}$} $row_build_id]} {error "invalid build ID in row [expr {[llength $input_rows]+2}]"}
      if {$expected_build_id eq ""} {set expected_build_id $row_build_id}
      if {$row_build_id ne $expected_build_id} {error "mixed build IDs in case CSV"}
      set seq [lindex $f 0]
      if {![regexp {^[1-9][0-9]*$} $seq] || $seq > 42 || [dict exists $rows_by_seq $seq]} {
        error "case CSV sequence must be unique in 1 through 42"
      }
      dict set rows_by_seq $seq $f
      lappend input_rows $f
    }
    close $cf
    set cf ""
    if {[llength $input_rows] != 42} {error "expected 42 cases in CSV, found [llength $input_rows]"}
    scan $expected_build_id %x expected_build
    set hardware {}
    foreach h [get_hardware_names] {if {[string match "USB-Blaster*" $h]} {lappend hardware $h}}
    if {[llength $hardware] == 0} {error "USB-Blaster not detected"}
    if {[llength $hardware] != 1} {error "ambiguous USB-Blaster target: $hardware"}
    set hw [lindex $hardware 0]
    set devices {}
    foreach d [get_device_names -hardware_name $hw] {
      if {[string match "*5CE*" $d]} {lappend devices $d}
    }
    if {[llength $devices] == 0} {error "Cyclone V device not detected on the selected USB-Blaster chain"}
    if {[llength $devices] != 1} {error "ambiguous Cyclone V target: $devices"}
    set dev [lindex $devices 0]
    puts $rawout "hardware=$hw device=$dev"
    open_device -hardware_name $hw -device_name $dev
    set opened 1
    device_lock -timeout 10000
    set locked 1
    set build [c2_u32 [c2_unpack_lsb [c2_scan 4 32 ""] 4] 0]
    if {$build != $expected_build} {error [format "C2 build ID mismatch: got 0x%08x expected 0x%08x" $build $expected_build]}
    set status [c2_status]
    if {$status & 0x80} {error "mailbox starts in ERROR state"}
    if {!($status & 0x08)} {error [format "mailbox not READY at start: 0x%02x" $status]}
    foreach selected_seq $selected_sequences {
      set f [dict get $rows_by_seq $selected_seq]
      lassign $f seq kind slot test_index input_id mode parameter fixed_exit budget \
        expected_admitted expected_executed expected_prediction expected_label expected_stop \
        legacy_prediction legacy_exit legacy_admitted legacy_cycles request_hex pixels_hex \
        payload_crc request100 request_bytes request_bits model_id build_id deadline
      if {$request_bytes != 100 || $request_bits != 800 || [string length $request100] != 200} {
        error "sequence $seq request length mismatch"
      }
      if {$model_id ne "52544e4e" || [string tolower $build_id] ne $expected_build_id} {error "sequence $seq frozen model/build ID mismatch"}
      set current_row [dict create seq $seq input_id $input_id mode $mode prediction "" \
        reference_label $expected_label admitted_exit "" executed_exit "" \
        expected_prediction $expected_prediction expected_admitted $expected_admitted expected_executed $expected_executed \
        response_seq "" response_input_id "" response_mode "" response_label "" \
        reported_cycles "" response_crc_valid "" response_lsb_hex "" \
        cycles "" case_status PENDING error ""]
      set req [c2_pack_lsb_hex $request100]
      puts $rawout "REQUEST seq=$seq input_id=$input_id mode=$mode request_lsb_hex=$req"
      c2_scan 1 800 $req
      set done 0
      for {set poll 0} {$poll < 60000} {incr poll} {
        set status [c2_status]
        if {$status & 0x40} {set done 1; break}
        after 1
      }
      if {!$done} {error "timeout seq=$seq last_status=[format 0x%02x $status]"}
      if {$status & 0x80} {error "mailbox ERROR seq=$seq status=[format 0x%02x $status]"}
      # Shift zeros into the response DR while sampling its committed value.
      # Quartus does not issue UpdateDR for a read-only virtual DR shift;
      # the explicit value makes the mailbox consume this snapshot.
      set response_hex [c2_scan 2 384 [string repeat 0 96]]
      # Retain the original bytes before parsing or rejecting any response.
      dict set current_row response_lsb_hex $response_hex
      puts $rawout "RESPONSE seq=$seq status=[format 0x%02x $status] response_lsb_hex=$response_hex"
      set r [c2_unpack_lsb $response_hex 48]
      dict set current_row response_seq [c2_u32 $r 8]
      dict set current_row response_input_id [c2_u16 $r 12]
      dict set current_row response_mode [lindex $r 6]
      dict set current_row response_label [lindex $r 23]
      dict set current_row prediction [lindex $r 22]
      dict set current_row admitted_exit [lindex $r 20]
      dict set current_row executed_exit [lindex $r 21]
      dict set current_row reported_cycles [c2_u32 $r 24]
      set crc_ok [expr {[c2_u32 $r 44] == [c2_crc32 [lrange $r 0 43]]}]
      dict set current_row response_crc_valid $crc_ok
      if {!$crc_ok} {error "seq=$seq response CRC mismatch"}
      if {[lrange $r 0 3] ne {82 84 78 82}} {error "seq=$seq bad RTNR magic"}
      if {[lindex $r 4] != 1 || [lindex $r 5] != 0 || [lindex $r 6] != $mode} {error "seq=$seq response version/status/mode mismatch"}
      if {[c2_u32 $r 8] != $seq || [c2_u16 $r 12] != $input_id} {error "seq=$seq response identity mismatch"}
      if {[c2_u16 $r 14] != $budget || [c2_u32 $r 16] != $deadline} {error "seq=$seq budget/deadline mismatch"}
      if {[lindex $r 20] != $expected_admitted || [lindex $r 21] != $expected_executed ||
          [lindex $r 22] != $expected_prediction || [lindex $r 23] != $expected_label ||
          [lindex $r 7] != $expected_stop} {error "seq=$seq frozen output/exit mismatch"}
      if {[lrange $r 28 31] ne {78 78 84 82} || [c2_u32 $r 32] != $expected_build} {
        error "seq=$seq model/build response identity mismatch"
      }
      set cycles_candidate [c2_u32 $r 24]
      if {$cycles_candidate == 0} {error "seq=$seq zero cycle count"}
      if {[lindex $r 21] > [lindex $r 20]} {error "seq=$seq cap violation"}
      dict set current_row cycles $cycles_candidate
      dict set current_row case_status PASS
      lappend cases $current_row
      puts $csvout [c2_csv_row $experiment_id $sof_sha $expected_build_id $current_row]
      puts $rawout "PASS seq=$seq input_id=$input_id mode=$mode status=[format 0x%02x $status] response_lsb_hex=$response_hex"
      # Reading IR_RESPONSE issues UpdateDR and requests that the mailbox
      # consume this snapshot. Wait for the CDC round trip before the next
      # request; otherwise a fast host can submit while DONE is still set.
      set ready 0
      for {set poll 0} {$poll < 60000} {incr poll} {
        set ready_status [c2_status]
        if {$ready_status & 0x80} {error "mailbox entered ERROR after response seq=$seq status=[format 0x%02x $ready_status]"}
        if {$ready_status & 0x08} {set ready 1; break}
        after 1
      }
      if {!$ready} {error "mailbox did not return READY after response seq=$seq last_status=[format 0x%02x $ready_status]"}
      puts $rawout "READY_AFTER_RESPONSE seq=$seq status=[format 0x%02x $ready_status]"
      incr n
      unset current_row
    }
    if {$n != $expected_count} {error "expected $expected_count selected frozen cases; ran $n"}
  } message options]
  if {$cf ne ""} {catch {close $cf}}
  if {$locked} {catch {device_unlock}}
  if {$rc && [info exists current_row]} {
    set failed_status FAIL
    if {[string match "timeout seq=*" $message]} {set failed_status TIMEOUT}
    dict set current_row case_status $failed_status
    dict set current_row error $message
    dict set current_row cycles ""
    lappend cases $current_row
    puts $csvout [c2_csv_row $experiment_id $sof_sha $expected_build_id $current_row]
  }
  set run_status [expr {$rc ? "FAIL" : ($n == $expected_count ? "PASS" : "INCOMPLETE")}]
  if {$opened} {catch {close_device}}
  if {$expected_build_id eq ""} {set expected_build 0}
  puts $jsonout [c2_json_header $experiment_id $sof_sha $expected_build $run_status [llength $cases] $n $selected_sequences]
  for {set i 0} {$i < [llength $cases]} {incr i} {
    puts -nonewline $jsonout [c2_json_row [lindex $cases $i]]
    if {$i+1 < [llength $cases]} {puts -nonewline $jsonout ","}
    puts $jsonout ""
  }
  puts $jsonout [format "]%c" 125]
  if {$rc} {puts $rawout "error=$message"}
  puts $rawout "run_status=$run_status completed=$n"
  close $csvout; close $jsonout; close $rawout
  if {$rc} {return -options $options $message}
  if {$n != $expected_count} {error "C2 JTAG run incomplete: $n/$expected_count"}
  if {$selected_sequences eq [c2_sequences ALL]} {
    puts [format "C2_JTAG_42_CASES_PASS count=42 experiment_id=%s build_id=%08x" $experiment_id $expected_build]
  } else {
    puts [format "C2_JTAG_SUBSET_PASS count=%d sequences=%s experiment_id=%s build_id=%08x" $n [join $selected_sequences ,] $experiment_id $expected_build]
  }
}

if {[catch {c2_run} message options]} {
  puts stderr "C2_JTAG_EXPERIMENT_FAIL: $message"
  error $message
}
