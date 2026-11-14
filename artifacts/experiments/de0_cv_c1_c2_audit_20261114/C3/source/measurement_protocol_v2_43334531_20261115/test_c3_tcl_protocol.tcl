if {$argc != 2} {error "usage: tclsh test_c3_tcl_protocol.tcl RUNNER_TCL TEST_FILE"}
lassign $argv runner_path test_path
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
set fixture [dict create cycles 42 seq 7 input_id 24 mode 3 prediction 4 reference_label 4 admitted_exit 3 executed_exit 3 expected_prediction 4 expected_admitted 3 expected_executed 3 response_seq 7 response_input_id 24 response_mode 3 response_label 4 cycles_start 100 cycles_end 142 response_model_id 52544e4e response_build_id 43334531 response_binding_id 43334531 response_flags 1 reported_cycles 42 response_crc_valid 1 response_lsb_hex abcd case_status PASS error ""]
set fixture_json [c2_json_row $fixture]
foreach field_value {{response_model_id 52544e4e} {response_build_id 43334531} {response_binding_id 43334531}} {
  lassign $field_value field value
  if {[string first [format {"%s":"%s"} $field $value] $fixture_json] < 0} {error "$field must be a quoted JSON string"}
}
set path [file normalize $test_path]
set actual [c3_sha256_file $path]
if {![regexp {^[0-9a-f]{64}$} $actual]} {error "SHA256 parser failed"}
puts "C3_TCL_PROTOCOL_PASS u64=2 crc32=1 sha256=1 hex_id_json_strings=3"
