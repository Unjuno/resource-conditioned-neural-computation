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
proc c2_u64 {bytes offset} {
  set v 0
  for {set i 0} {$i < 8} {incr i} {set v [expr {$v | ([lindex $bytes [expr {$offset+$i}]] << (8*$i))}]}
  return $v
}
proc c3_sha256_file {path} {
  if {$::tcl_platform(platform) eq "windows"} {
    set raw [exec certutil -hashfile $path SHA256]
    if {![regexp -nocase {([0-9a-f]{64})} $raw -> digest]} {error "certutil did not return SHA-256 for $path"}
    return [string tolower $digest]
  }
  set raw [exec sha256sum $path]
  if {![regexp -nocase {^([0-9a-f]{64})} $raw -> digest]} {error "sha256sum did not return SHA-256 for $path"}
  return [string tolower $digest]
}
proc c3_json_scalar {json field} {
  set key "\"$field\""
  set at [string first $key $json]
  if {$at < 0} {error "JSON field $field missing"}
  set at [expr {$at + [string length $key]}]
  set tail [string trimleft [string range $json $at end]]
  if {[string index $tail 0] ne ":"} {error "JSON field $field has no colon"}
  set tail [string trimleft [string range $tail 1 end]]
  if {[string index $tail 0] eq "\""} {
    set end [string first "\"" $tail 1]
    if {$end < 0} {error "JSON field $field has unterminated string"}
    return [string range $tail 1 [expr {$end - 1}]]
  }
  set end [string first "," $tail]
  set brace [string first "\}" $tail]
  if {$end < 0 || ($brace >= 0 && $brace < $end)} {set end $brace}
  if {$end < 0} {set end [string length $tail]}
  return [string trim [string range $tail 0 [expr {$end - 1}]]]
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
  foreach key {expected_prediction expected_admitted expected_executed response_seq response_input_id response_mode response_label cycles_start cycles_end response_model_id response_build_id response_binding_id response_flags reported_cycles} {
    set value [dict get $row $key]
    if {$key in {response_model_id response_build_id response_binding_id}} {
      if {$value eq ""} {set encoded null} else {set encoded [c2_json_quote $value]}
    } else {
      set encoded [c2_json_number $value]
    }
    append base [format {,"%s":%s} $key $encoded]
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
  set result {}
  foreach seq [split $value ,] {
    if {![regexp {^[1-9][0-9]*$} $seq] || $seq > 24840} {error "pilot sequence must be in 1 through 24840"}
    if {[lsearch -exact $result $seq] >= 0} {error "duplicate sequence selection $seq"}
    lappend result $seq
  }
  return $result
}

proc c3_binding_selection {selection binding_text} {
  if {![regexp {"record_count"\s*:\s*([0-9]+)} $binding_text -> record_count] ||
      ![regexp {"full_schedule_record_count"\s*:\s*([0-9]+)} $binding_text -> full_count] ||
      ![regexp {"session_scope"\s*:\s*"([A-Z0-9_]+)"} $binding_text -> session_scope] ||
      ![regexp {"selected_schedule_sequences"\s*:\s*\[([^\]]*)\]} $binding_text -> sequence_text]} {
    error "binding JSON is missing schedule row scope or sequence fields"
  }
  if {![regexp {^[0-9,\s]*$} $sequence_text]} {error "binding selected sequence list is malformed"}
  set binding_sequences [regexp -all -inline {[0-9]+} $sequence_text]
  if {[llength $binding_sequences] != $record_count || $record_count < 1 || $record_count > $full_count} {
    error "binding sequence count does not match its row counts"
  }
  set prior 0
  foreach seq $binding_sequences {
    if {$seq <= $prior || $seq > 24840} {error "binding sequences must be unique, increasing and in range"}
    set prior $seq
  }
  if {$session_scope eq "FULL_FROZEN_SCHEDULE"} {
    if {$record_count != $full_count} {error "full-schedule binding row counts differ"}
    for {set i 0} {$i < $record_count} {incr i} {
      if {[lindex $binding_sequences $i] != $i+1} {error "full-schedule binding sequence list is not complete"}
    }
    set output_scope full_schedule
  } elseif {$session_scope eq "FROZEN_SCHEDULE_SUBSET_NOT_COUNTED_AS_COMPLETE_SESSION"} {
    if {$record_count >= $full_count} {error "subset binding unexpectedly contains a full schedule"}
    set output_scope frozen_schedule_subset
  } else {
    error "unknown binding session_scope: $session_scope"
  }
  if {$selection eq "ALL"} {
    if {$session_scope ne "FULL_FROZEN_SCHEDULE"} {error "ALL is permitted only for a complete frozen schedule binding"}
    set requested $binding_sequences
  } else {
    set requested [c2_sequences $selection]
    if {$requested ne $binding_sequences} {error "selection list does not equal the versioned case binding"}
  }
  return [list $requested $output_scope $record_count $binding_sequences]
}

proc c3_require_reset_replay_gate {gate_path sof_sha build_id} {
  if {$gate_path eq "" || ![file isfile $gate_path]} {
    error "primary schedule blocked: independently audited KEY-reset replay gate JSON is required"
  }
  set f [open $gate_path r]; set gate [read $f]; close $f
  foreach {field expected} [list schema rtnn-c3-key-reset-replay-gate-v1 status PASS audit_status PASS reset_action KEY0_PRESS_RELEASE user_attested true sof_sha256 [string tolower $sof_sha] build_id $build_id response_count 20] {
    if {[catch {c3_json_scalar $gate $field} got] || [string tolower $got] ne [string tolower $expected]} {
      error "primary schedule blocked: reset gate field $field missing or mismatched"
    }
  }
  if {![regexp {"result_json_sha256"\s*:\s*"[0-9a-fA-F]{64}"} $gate] ||
      ![regexp {"audit_report_sha256"\s*:\s*"[0-9a-fA-F]{64}"} $gate] ||
      ![regexp {"result_json_path"\s*:\s*"([^"]+)"} $gate -> result_path] ||
      ![regexp {"audit_report_path"\s*:\s*"([^"]+)"} $gate -> audit_path] ||
      ![regexp {"experiment_id"\s*:\s*"(C3V2_TENINPUT_KEY_RESET_REPLAY_[A-Za-z0-9_-]+)"} $gate -> reset_experiment_id] ||
      ![regexp {"selected_sequences"\s*:\s*\[\s*49\s*,\s*50\s*,\s*141\s*,\s*142\s*,\s*209\s*,\s*210\s*,\s*277\s*,\s*278\s*,\s*325\s*,\s*326\s*,\s*379\s*,\s*380\s*,\s*431\s*,\s*432\s*,\s*487\s*,\s*488\s*,\s*559\s*,\s*560\s*,\s*719\s*,\s*720\s*\]} $gate]} {
    error "primary schedule blocked: reset gate evidence identity or 20-sequence list is incomplete"
  }
  if {[file pathtype $result_path] ne "absolute"} {set result_path [file normalize [file join [file dirname $gate_path] $result_path]]}
  if {[file pathtype $audit_path] ne "absolute"} {set audit_path [file normalize [file join [file dirname $gate_path] $audit_path]]}
  if {![file isfile $result_path] || ![file isfile $audit_path]} {error "primary schedule blocked: reset replay result/audit file missing"}
  set result_sha [c3_sha256_file $result_path]
  set audit_sha [c3_sha256_file $audit_path]
  if {![regexp {"result_json_sha256"\s*:\s*"([0-9a-fA-F]{64})"} $gate -> expected_result_sha] || [string tolower $result_sha] ne [string tolower $expected_result_sha] ||
      ![regexp {"audit_report_sha256"\s*:\s*"([0-9a-fA-F]{64})"} $gate -> expected_audit_sha] || [string tolower $audit_sha] ne [string tolower $expected_audit_sha]} {
    error "primary schedule blocked: reset replay result/audit SHA-256 mismatch"
  }
  set f [open $result_path r]; set result [read $f]; close $f
  foreach {field expected} [list schema rtnn-c3-jtag-results-v2 status PASS experiment_id $reset_experiment_id sof_sha256 [string tolower $sof_sha] build_id $build_id count 20 completed_count 20 expected_count 20] {
    if {[catch {c3_json_scalar $result $field} got] || [string tolower $got] ne [string tolower $expected]} {
      error "primary schedule blocked: reset replay result field $field mismatch"
    }
  }
  if {![regexp {"selected_sequences"\s*:\s*\[\s*49\s*,\s*50\s*,\s*141\s*,\s*142\s*,\s*209\s*,\s*210\s*,\s*277\s*,\s*278\s*,\s*325\s*,\s*326\s*,\s*379\s*,\s*380\s*,\s*431\s*,\s*432\s*,\s*487\s*,\s*488\s*,\s*559\s*,\s*560\s*,\s*719\s*,\s*720\s*\]} $result]} {
    error "primary schedule blocked: reset replay result sequence list mismatch"
  }
  set f [open $audit_path r]; set audit [read $f]; close $f
  foreach {field expected} [list schema rtnn-c3-v2-jtag-post-audit-v1 status PASS experiment_id $reset_experiment_id sof_sha256 [string tolower $sof_sha] build_id $build_id response_count 20] {
    if {[catch {c3_json_scalar $audit $field} got] || [string tolower $got] ne [string tolower $expected]} {
      error "primary schedule blocked: reset replay audit field $field mismatch (got='$got' expected='$expected')"
    }
  }
  return [c3_sha256_file $gate_path]
}

proc c3_validate_case_sequences {rows binding_sequences expected_count} {
  if {[llength $rows] != $expected_count} {error "case CSV row count does not match the versioned binding"}
  set csv_sequences {}
  foreach row $rows {lappend csv_sequences [lindex $row 0]}
  if {$csv_sequences ne $binding_sequences} {error "case CSV sequence list does not match the versioned binding"}
  return 1
}

proc c2_csv_row {experiment_id sof_sha build_id binding_id binding_sha session_id schedule_sha row} {
  set fields [list $experiment_id [string tolower $sof_sha] $build_id $binding_id $binding_sha d6c98f59c0c0afe32d0877c01c8411fba8bf3e2a5c8058c5a85371f7f648a8dc $session_id $schedule_sha]
  foreach key {seq input_id mode prediction reference_label admitted_exit executed_exit cycles} {
    lappend fields [dict get $row $key]
  }
  lappend fields [expr {[dict get $row cycles] eq "" ? 0 : 1}]
  foreach key {expected_prediction expected_admitted expected_executed response_seq response_input_id response_mode response_label cycles_start cycles_end response_model_id response_build_id response_binding_id response_flags reported_cycles response_crc_valid response_lsb_hex} {
    lappend fields [dict get $row $key]
  }
  lappend fields Ibex_mcycle_delta [dict get $row counter_status] [dict get $row case_status] [c2_csv_quote [dict get $row error]]
  return [join $fields ,]
}

proc c2_json_quote {value} {
  set value [string map [list "\\" "\\\\" "\"" "\\\"" "
" "\
" "\r" "\\r" "\t" "\\t"] $value]
  return "\"$value\""
}

proc c2_csv_quote {value} {
  return "\"[string map [list \" \"\"] $value]\""
}

proc c2_json_header {experiment_id sof_sha build_id binding_id binding_sha session_id schedule_sha run_status recorded completed sequences scope} {
  return [format "%c\"schema\":\"rtnn-c3-jtag-results-v2\",\"experiment_id\":\"%s\",\"sof_sha256\":\"%s\",\"build_id\":\"%08x\",\"binding_id\":\"%08x\",\"binding_sha256\":\"%s\",\"campaign_canonical_sha256\":\"d6c98f59c0c0afe32d0877c01c8411fba8bf3e2a5c8058c5a85371f7f648a8dc\",\"schedule_id\":\"%s\",\"schedule_canonical_sha256\":\"%s\",\"cycle_source\":\"64-bit Ibex mcycle start/end read from FPGA via Virtual-JTAG\",\"uart\":false,\"flash_written\":false,\"status\":\"%s\",\"count\":%d,\"completed_count\":%d,\"expected_count\":%d,\"selected_sequences\":%c%s%c,\"scope\":\"%s\",\"timing_classification\":\"EMPIRICAL_ONLY\",\"wcet_or_hard_deadline_claimed\":false,\"cases\":%c" 123 $experiment_id [string tolower $sof_sha] $build_id $binding_id $binding_sha $session_id $schedule_sha $run_status $recorded $completed [llength $sequences] 91 [join $sequences ,] 93 $scope 91]
}

proc c2_run {} {
  global argv argc
  if {$argc ni {6 7}} {error "usage: quartus_stp -t run_c3_campaign_v2.tcl CASES.csv BINDING.json OUT_DIR SOF_SHA256 EXPERIMENT_ID SEQ,SEQ,... [KEY_RESET_GATE.json for primary schedules]"}
  lassign $argv cases_path binding_path out_dir sof_sha experiment_id selection reset_gate_path
  if {![file isfile $binding_path]} {error "versioned C3 build binding JSON is required"}
  set bf [open $binding_path r]; set binding_text [read $bf]; close $bf
  foreach {field expected} {schema rtnn-c3-measurement-v2-host-binding-v1 campaign_canonical_sha256 d6c98f59c0c0afe32d0877c01c8411fba8bf3e2a5c8058c5a85371f7f648a8dc campaign_file_sha256 3d97a1cd87395e294299cacb617474367c89a9295355cd25fb1b4fa67464c936 dataset_file_sha256 eeba9000a918bcba911007e78905c5052fc743422f95cb314a0fc9f4ecdfb14c oracle_file_sha256 4e1a3ddcabe1884b1607c77d19b10da8a86d53da3f4c060c30d7449635ec3cf4 host_q15_file_sha256 1f9b08987a9d7368b663f604eb1dce6e077073e099552532468509c846d6bdc8 firmware_elf_sha256 9cbf537bd9440deaf5c78abf6b204da9cbcd2fe3795acf444d733dbd581002b6 build_id 43334531 binding_id 43334531 model_id 52544e4e} {
    if {![regexp [format {"%s"\s*:\s*"([^"]+)"} $field] $binding_text -> got] || [string tolower $got] ne $expected} {error "binding JSON $field mismatch"}
  }
  if {![regexp {"session_id"\s*:\s*"([a-z0-9_]+)"} $binding_text -> session_id]} {error "binding JSON session_id missing"}
  set reset_gate_sha ""
  set schedule_table [dict create \
    diagnostic_fixed 576edecefe232a4cf619bf3f995223b8c26016fb9c8495f50c15e9cff6bee42b \
    diagnostic_adaptive 8f3ab2f69217689114727b6b7fb4eae371e5cccae6e31adb3bc5d1fa8117ce20 \
    diagnostic_capped f0a0ddae3e33ac6debdb1e6317a07c67331509b97cb86f1edbfe535432b65928 \
    primary_01 73d37a9bf03a263a01663f5bf2d74695b93493c0660309ac39ad9dba97b414c9 \
    primary_02 e96669a29f4d188827daa1007ec1362b77b0c55869491abb1263680cd5c61118 \
    primary_03 223873b4a126e03497e71dbcbf791079976bad854efc1b583d75645ab55df54b \
    primary_04 6d39de778ff9ecae838a430824194d4f9ee83a5416d3d2f2e2d1bd4dbd7e4196 \
    primary_05 54a5e172d695cf3ba4bd38e378aac2e0a4743d0adcffcf29d4ab7aa45ef58365 \
    primary_06 335958e0cde52b7c56fc50eb09d385f1f9ddff870e87991e74e72390567b9587 \
    primary_07 b7f358e18ba9798722226656919a87a8d6615dad6c4e538c6a3c3b9a04ec582b \
    primary_08 3fb696eff4783ef4ff1d0f2186208501d1821cd233b05e675a2ff88b6d306fab \
    primary_09 738ff472ffa1a98547ce0ab89384439a071a79eda1dbb0292c425a372f15564a \
    primary_10 db154943ab73fab850993cd4cfd76be922642b13d6f9bfa2b50b440128186022]
  if {![dict exists $schedule_table $session_id] || ![regexp {"schedule_canonical_sha256"\s*:\s*"([0-9a-fA-F]{64})"} $binding_text -> schedule_sha] || [string tolower $schedule_sha] ne [dict get $schedule_table $session_id]} {error "binding JSON schedule identity mismatch"}
  if {![regexp {"frozen_schedule_modified"\s*:\s*false} $binding_text] || ![regexp {"timing_classification"\s*:\s*"EMPIRICAL_ONLY"} $binding_text] || ![regexp {"wcet_or_hard_deadline_claimed"\s*:\s*false} $binding_text]} {error "binding JSON scope/nonclaim mismatch"}
  if {![regexp {"response_bytes"\s*:\s*60} $binding_text] || ![regexp {"response_protocol_version"\s*:\s*2} $binding_text]} {error "binding JSON response protocol mismatch"}
  if {![regexp {"sof_sha256"\s*:\s*"([0-9a-fA-F]{64})"} $binding_text -> bound_sof] || [string tolower $bound_sof] ne [string tolower $sof_sha]} {error "SOF SHA does not match a completed C3 binding"}
  set case_sha [c3_sha256_file $cases_path]
  if {![regexp {"case_csv_sha256"\s*:\s*"([0-9a-fA-F]{64})"} $binding_text -> bound_cases] || [string tolower $bound_cases] ne $case_sha} {error "case CSV SHA does not match C3 binding"}
  if {![regexp {"measurement_eligible"\s*:\s*true} $binding_text]} {error "binding is not marked measurement eligible"}
  set binding_sha [c3_sha256_file $binding_path]
  lassign [c3_binding_selection $selection $binding_text] selected_sequences output_scope expected_count binding_sequences
  if {$output_scope eq "full_schedule"} {
    set reset_gate_sha [c3_require_reset_replay_gate $reset_gate_path $sof_sha 43334531]
  }
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
  puts $csvout "experiment_id,sof_sha256,build_id,binding_id,binding_sha256,campaign_canonical_sha256,schedule_id,schedule_canonical_sha256,seq,input_id,mode,prediction,reference_label,admitted_exit,executed_exit,cycles,cycle_valid,expected_prediction,expected_admitted,expected_executed,response_seq,response_input_id,response_mode,response_label,cycles_start,cycles_end,response_model_id,response_build_id,response_binding_id,response_flags,reported_cycles,response_crc_valid,response_lsb_hex,cycle_source,counter_status,case_status,error"
  puts $rawout "experiment_id=$experiment_id sof_sha256=[string tolower $sof_sha] build_id=43334531 binding_id=43334531 binding_sha256=$binding_sha campaign_canonical_sha256=d6c98f59c0c0afe32d0877c01c8411fba8bf3e2a5c8058c5a85371f7f648a8dc schedule_id=$session_id schedule_sha256=$schedule_sha interface=USB-Blaster/Virtual-JTAG uart=none flash=untouched timing_classification=EMPIRICAL_ONLY scope=$output_scope key_reset_gate_sha256=$reset_gate_sha"
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
      if {[llength $f] != 28} {error "bad CSV field count at row [expr {[llength $input_rows]+2}]"}
      set row_build_id [string tolower [lindex $f 25]]
      if {![regexp {^[0-9a-f]{8}$} $row_build_id]} {error "invalid build ID in row [expr {[llength $input_rows]+2}]"}
      if {$expected_build_id eq ""} {set expected_build_id $row_build_id}
      if {$row_build_id ne $expected_build_id} {error "mixed build IDs in case CSV"}
      set seq [lindex $f 0]
      if {![regexp {^[1-9][0-9]*$} $seq] || $seq > 24840 || [dict exists $rows_by_seq $seq]} {
        error "case CSV sequence must be unique in 1 through 24840"
      }
      dict set rows_by_seq $seq $f
      lappend input_rows $f
    }
    close $cf
    set cf ""
    if {[catch {c3_validate_case_sequences $input_rows $binding_sequences $expected_count} message]} {
      error "$message: expected $expected_count rows, found [llength $input_rows]"
    }
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
      set binding_id [string tolower [lindex $f 27]]
      if {$model_id ne "52544e4e" || [string tolower $build_id] ne $expected_build_id || $expected_build_id ne "43334531" || $binding_id ne "43334531"} {error "sequence $seq frozen model/build/binding ID mismatch"}
      set current_row [dict create seq $seq input_id $input_id mode $mode prediction "" \
        reference_label $expected_label admitted_exit "" executed_exit "" \
        expected_prediction $expected_prediction expected_admitted $expected_admitted expected_executed $expected_executed \
        response_seq "" response_input_id "" response_mode "" response_label "" \
        cycles_start "" cycles_end "" response_model_id "" response_build_id "" response_binding_id "" response_flags "" \
        reported_cycles "" response_crc_valid "" response_lsb_hex "" \
        cycles "" counter_status NOT_READ case_status PENDING error ""]
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
      set response_hex [c2_scan 2 480 [string repeat 0 120]]
      # Retain the original bytes before parsing or rejecting any response.
      dict set current_row response_lsb_hex $response_hex
      puts $rawout "RESPONSE seq=$seq status=[format 0x%02x $status] response_lsb_hex=$response_hex"
      set r [c2_unpack_lsb $response_hex 60]
      dict set current_row response_seq [c2_u32 $r 8]
      dict set current_row response_input_id [c2_u16 $r 12]
      dict set current_row response_mode [lindex $r 6]
      dict set current_row response_label [lindex $r 23]
      dict set current_row prediction [lindex $r 22]
      dict set current_row admitted_exit [lindex $r 20]
      dict set current_row executed_exit [lindex $r 21]
      dict set current_row cycles_start [c2_u64 $r 24]
      dict set current_row cycles_end [c2_u64 $r 32]
      dict set current_row response_model_id [format %08x [c2_u32 $r 40]]
      dict set current_row response_build_id [format %08x [c2_u32 $r 44]]
      dict set current_row response_binding_id [format %08x [c2_u32 $r 48]]
      dict set current_row response_flags [c2_u32 $r 52]
      set crc_ok [expr {[c2_u32 $r 56] == [c2_crc32 [lrange $r 0 55]]}]
      dict set current_row response_crc_valid $crc_ok
      if {!$crc_ok} {error "seq=$seq response CRC mismatch"}
      if {[lrange $r 0 3] ne {82 84 78 82}} {error "seq=$seq bad RTNR magic"}
      if {[lindex $r 4] != 2 || [lindex $r 6] != $mode} {error "seq=$seq response version/mode mismatch"}
      dict set current_row counter_status [lindex $r 5]
      if {[lindex $r 5] != 0} {error "seq=$seq firmware response status=[lindex $r 5]"}
      if {[c2_u32 $r 8] != $seq || [c2_u16 $r 12] != $input_id} {error "seq=$seq response identity mismatch"}
      if {[c2_u16 $r 14] != $budget || [c2_u32 $r 16] != $deadline} {error "seq=$seq budget/deadline mismatch"}
      if {[lindex $r 20] != $expected_admitted || [lindex $r 21] != $expected_executed ||
          [lindex $r 22] != $expected_prediction || [lindex $r 23] != $expected_label ||
          [lindex $r 7] != $expected_stop} {error "seq=$seq frozen output/exit mismatch"}
      if {[lrange $r 40 43] ne {78 78 84 82} || [c2_u32 $r 44] != $expected_build || [c2_u32 $r 48] != $expected_build} {
        error "seq=$seq model/build response identity mismatch"
      }
      if {[c2_u32 $r 52] != 1} {error "seq=$seq invalid cycle flags=[c2_u32 $r 52]"}
      set cycle_start [c2_u64 $r 24]; set cycle_end [c2_u64 $r 32]
      if {$cycle_start == 0 || $cycle_end <= $cycle_start} {error "seq=$seq zero, reset or regressed mcycle interval"}
      set cycles_candidate [expr {$cycle_end - $cycle_start}]
      dict set current_row reported_cycles $cycles_candidate
      if {[lindex $r 21] > [lindex $r 20]} {error "seq=$seq cap violation"}
      dict set current_row cycles $cycles_candidate
      dict set current_row case_status PASS
      lappend cases $current_row
      puts $csvout [c2_csv_row $experiment_id $sof_sha $expected_build_id $binding_id $binding_sha $session_id $schedule_sha $current_row]
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
    puts $csvout [c2_csv_row $experiment_id $sof_sha $expected_build_id $binding_id $binding_sha $session_id $schedule_sha $current_row]
  }
  set run_status [expr {$rc ? "FAIL" : ($n == $expected_count ? "PASS" : "INCOMPLETE")}]
  if {$opened} {catch {close_device}}
  if {$expected_build_id eq ""} {set expected_build 0}
  puts $jsonout [c2_json_header $experiment_id $sof_sha $expected_build $expected_build $binding_sha $session_id $schedule_sha $run_status [llength $cases] $n $selected_sequences $output_scope]
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
  if {$n != $expected_count} {error "C3 JTAG run incomplete: $n/$expected_count"}
  puts [format "C3_JTAG_RUN_PASS scope=%s count=%d experiment_id=%s build_id=%08x" $output_scope $n $experiment_id $expected_build]
}

if {[catch {c2_run} message options]} {
  puts stderr "C3_JTAG_PILOT_FAIL: $message"
  error $message
}


