if {$argc != 3} {error "usage: quartus_stp_tcl -t test_c3_campaign_runner.tcl RUNNER_TCL TEST_FILE BINDING_ROOT"}
lassign $argv runner_path test_path binding_root
set f [open $runner_path r]; set src [read $f]; close $f
set src [string map [list "package require ::quartus::jtag" ""] $src]
set marker "\nif \{\[catch \{c2_run\}"
set bottom [string first $marker $src]
if {$bottom < 0} {error "could not locate runner entry point"}
set src [string range $src 0 [expr {$bottom - 1}]]
if {[catch {eval $src} message options]} {puts stderr $message; return -options $options $message}
if {[c2_u64 {16 0 0 0 1 0 0 0} 0] != 4294967312} {error "little-endian u64 decode failed"}
if {[c2_u64 {0 0 0 0 0 0 0 128} 0] != 9223372036854775808} {error "high-bit u64 decode failed"}
if {[c2_crc32 {49 50 51 52 53 54 55 56 57}] != 3421780262} {error "CRC32 known-answer failed"}
set full_header [c2_json_header full_exp [string repeat a 64] 0x43334531 0x43334531 [string repeat b 64] primary_01 [string repeat c 64] PASS 3 3 {1 2 3} full_schedule]
if {[string first {"scope":"full_schedule"} $full_header] < 0 || [string first {"expected_count":3} $full_header] < 0} {error "full-schedule result JSON scope/count mismatch"}
set subset_header [c2_json_header subset_exp [string repeat a 64] 0x43334531 0x43334531 [string repeat b 64] primary_01 [string repeat c 64] PASS 2 2 {49 50} frozen_schedule_subset]
if {[string first {"scope":"frozen_schedule_subset"} $subset_header] < 0 || [string first {"expected_count":2} $subset_header] < 0} {error "subset result JSON scope/count mismatch"}
set full_binding {"record_count":3,"full_schedule_record_count":3,"session_scope":"FULL_FROZEN_SCHEDULE","selected_schedule_sequences":[1,2,3]}
lassign [c3_binding_selection ALL $full_binding] full_seq full_scope full_count full_bound_seq
if {$full_seq ne {1 2 3} || $full_bound_seq ne {1 2 3} || $full_scope ne "full_schedule" || $full_count != 3} {error "ALL did not resolve the exact full-schedule binding"}
lassign [c3_binding_selection 1,2,3 $full_binding] explicit_seq explicit_scope explicit_count explicit_bound_seq
if {$explicit_seq ne {1 2 3} || $explicit_scope ne "full_schedule" || $explicit_count != 3} {error "explicit full schedule selection mismatch"}
set subset_binding {"record_count":2,"full_schedule_record_count":3,"session_scope":"FROZEN_SCHEDULE_SUBSET_NOT_COUNTED_AS_COMPLETE_SESSION","selected_schedule_sequences":[2,3]}
lassign [c3_binding_selection 2,3 $subset_binding] subset_seq subset_scope subset_count subset_bound_seq
if {$subset_seq ne {2 3} || $subset_bound_seq ne {2 3} || $subset_scope ne "frozen_schedule_subset" || $subset_count != 2} {error "subset selection mismatch"}
if {![catch {c3_binding_selection ALL $subset_binding}]} {error "ALL incorrectly accepted a subset binding"}
if {![catch {c3_binding_selection 1,3 $subset_binding}]} {error "sequence selection mismatch was accepted"}
if {![catch {c3_binding_selection 2,2 $subset_binding}]} {error "duplicate sequence selection was accepted"}
if {![catch {c3_require_reset_replay_gate "" [string repeat a 64] 43334531}]} {error "reset gate accepted a missing audit"}
set temp_channel [file tempfile temp_base]
close $temp_channel
file delete $temp_base
set gate_dir ${temp_base}.reset_gate_fixture
file mkdir $gate_dir
set reset_id C3V2_TENINPUT_KEY_RESET_REPLAY_TEST
set seq_json {49,50,141,142,209,210,277,278,325,326,379,380,431,432,487,488,559,560,719,720}
set result_path [file join $gate_dir result.json]
set audit_path [file join $gate_dir audit.json]
set f [open $result_path w]; puts -nonewline $f "{\"schema\":\"rtnn-c3-jtag-results-v2\",\"experiment_id\":\"$reset_id\",\"status\":\"PASS\",\"count\":20,\"completed_count\":20,\"expected_count\":20,\"sof_sha256\":\"[string repeat a 64]\",\"build_id\":\"43334531\",\"selected_sequences\":\[$seq_json\]}"; close $f
set f [open $audit_path w]; puts -nonewline $f "{\"schema\":\"rtnn-c3-v2-jtag-post-audit-v1\",\"status\":\"PASS\",\"experiment_id\":\"$reset_id\",\"sof_sha256\":\"[string repeat a 64]\",\"build_id\":\"43334531\",\"response_count\":20}"; close $f
set gate_path [file join $gate_dir gate.json]
set f [open $gate_path w]
puts -nonewline $f "{\"schema\":\"rtnn-c3-key-reset-replay-gate-v1\",\"status\":\"PASS\",\"audit_status\":\"PASS\",\"reset_action\":\"KEY0_PRESS_RELEASE\",\"user_attested\":true,\"sof_sha256\":\"[string repeat a 64]\",\"build_id\":\"43334531\",\"response_count\":20,\"experiment_id\":\"$reset_id\",\"selected_sequences\":\[$seq_json\],\"result_json_path\":\"$result_path\",\"audit_report_path\":\"$audit_path\",\"result_json_sha256\":\"[c3_sha256_file $result_path]\",\"audit_report_sha256\":\"[c3_sha256_file $audit_path]\"}"
close $f
if {[catch {c3_require_reset_replay_gate $gate_path [string repeat a 64] 43334531} gate_sha]} {error "complete reset gate fixture rejected: $gate_sha"}
set f [open $result_path a]; puts -nonewline $f " "; close $f
if {![catch {c3_require_reset_replay_gate $gate_path [string repeat a 64] 43334531}]} {error "modified reset gate file passed its evidence SHA check"}
file delete $result_path $audit_path $gate_path
file delete $gate_dir
set p_binding [file join $binding_root campaign_sof_bound_v2 primary_01 binding.json]
set p_cases [file join $binding_root campaign_sof_bound_v2 primary_01 cases.csv]
set saved_argv $argv; set saved_argc $argc
set argv [list $p_cases $p_binding [file join $temp_base must_not_open_jtag] 85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d RESET_GATE_NEGATIVE_TEST ALL]
set argc 6
if {![catch {c2_run} gate_error] || [string first "KEY-reset replay gate" $gate_error] < 0} {error "primary physical run did not fail closed before JTAG without reset gate: $gate_error"}
set d_binding [file join $binding_root campaign_sof_bound_v2 diagnostic_fixed binding.json]
set d_cases [file join $binding_root campaign_sof_bound_v2 diagnostic_fixed cases.csv]
set argv [list $d_cases $d_binding [file join $temp_base must_not_open_diagnostic_jtag] 85c5fd086cf83c5a897f3de1bba1d3dd0c0a5c06a53eb492a23e5160fb3f1f2d RESET_GATE_DIAGNOSTIC_NEGATIVE_TEST ALL]
if {![catch {c2_run} gate_error] || [string first "KEY-reset replay gate" $gate_error] < 0} {error "diagnostic full schedule did not fail closed before JTAG without reset gate: $gate_error"}
set argv $saved_argv; set argc $saved_argc
if {[catch {c3_validate_case_sequences {{2 row} {3 row}} {2 3} 2} message]} {error "matching case/binding sequences were rejected: $message"}
if {![catch {c3_validate_case_sequences {{2 row} {4 row}} {2 3} 2}]} {error "case/binding sequence mismatch was accepted"}
if {![catch {c3_validate_case_sequences {{2 row}} {2 3} 2}]} {error "case/binding row-count mismatch was accepted"}
set expected_sessions [list diagnostic_fixed 2520 diagnostic_adaptive 7560 diagnostic_capped 7560 primary_01 720 primary_02 720 primary_03 720 primary_04 720 primary_05 720 primary_06 720 primary_07 720 primary_08 720 primary_09 720 primary_10 720]
foreach {session expected_rows} $expected_sessions {
  set bp [file join $binding_root campaign_sof_bound_v2 $session binding.json]
  set cp [file join $binding_root campaign_sof_bound_v2 $session cases.csv]
  set bf [open $bp r]; set binding_text [read $bf]; close $bf
  lassign [c3_binding_selection ALL $binding_text] selected scope count binding_seq
  if {$scope ne "full_schedule" || $count != $expected_rows || [llength $selected] != $expected_rows} {error "full binding resolution failed for $session"}
  set cf [open $cp r]; gets $cf
  set case_rows {}
  while {[gets $cf line] >= 0} {
    if {$line eq ""} continue
    set seq [lindex [split $line ,] 0]
    lappend case_rows [list $seq]
  }
  close $cf
  if {![c3_validate_case_sequences $case_rows $binding_seq $expected_rows]} {error "case CSV audit failed for $session"}
  if {[lindex $selected 0] != 1 || [lindex $selected end] != $expected_rows} {error "full binding sequence boundaries mismatch for $session"}
}
set subset_base [file join $binding_root ten_input_pilot_primary_01]
set sbf [open [file join $subset_base binding.json] r]; set subset_text [read $sbf]; close $sbf
regexp {"selected_schedule_sequences"\s*:\s*\[([^\]]*)\]} $subset_text -> subset_seq_text
set subset_seq [regexp -all -inline {[0-9]+} $subset_seq_text]
lassign [c3_binding_selection [join $subset_seq ,] $subset_text] resolved_subset subset_scope subset_count subset_bound
if {$subset_scope ne "frozen_schedule_subset" || $subset_count != 20 || $resolved_subset ne $subset_bound} {error "real pilot subset binding resolution failed"}
set scf [open [file join $subset_base cases.csv] r]; gets $scf
set subset_rows {}
while {[gets $scf line] >= 0} {if {$line ne ""} {lappend subset_rows [list [lindex [split $line ,] 0]]}}
close $scf
if {![c3_validate_case_sequences $subset_rows $subset_bound 20]} {error "real pilot case CSV audit failed"}
set fixture [dict create cycles 42 seq 7 input_id 24 mode 3 prediction 4 reference_label 4 admitted_exit 3 executed_exit 3 expected_prediction 4 expected_admitted 3 expected_executed 3 response_seq 7 response_input_id 24 response_mode 3 response_label 4 cycles_start 100 cycles_end 142 response_model_id 52544e4e response_build_id 43334531 response_binding_id 43334531 response_flags 1 reported_cycles 42 response_crc_valid 1 response_lsb_hex abcd case_status PASS error ""]
set fixture_json [c2_json_row $fixture]
foreach field_value {{response_model_id 52544e4e} {response_build_id 43334531} {response_binding_id 43334531}} {
  lassign $field_value field value
  if {[string first [format {"%s":"%s"} $field $value] $fixture_json] < 0} {error "$field must be a quoted JSON string"}
}
set path [file normalize $test_path]
set actual [c3_sha256_file $path]
if {![regexp {^[0-9a-f]{64}$} $actual]} {error "SHA256 parser failed"}
puts "C3_CAMPAIGN_TCL_PROTOCOL_PASS u64=2 crc32=1 sha256=1 hex_id_json_strings=3 full_scope_json=1 subset_scope_json=1 frozen_bindings=13 rows=24840 full_all=1 pilot_subset=20 sequence_negative=4 reset_gate=valid_invalid_sha primary_and_diagnostic_fail_closed_before_jtag=1"
