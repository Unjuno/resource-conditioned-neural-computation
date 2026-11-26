# New dynamic-pixel JTAG runner. This file is not the C3 v2 campaign runner.
# It only uses Virtual-JTAG IR/DR operations; it has no Programmer/Flash path.
set ::rtnn_runner_script [file normalize [info script]]
proc xscan {ir bits value} {
  device_virtual_ir_shift -instance_index 0 -ir_value $ir -no_captured_ir_value
  if {$value eq ""} {return [device_virtual_dr_shift -instance_index 0 -length $bits -value_in_hex]}
  return [device_virtual_dr_shift -instance_index 0 -length $bits -dr_value $value -value_in_hex]
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
proc xpack {bytes} {set h ""; foreach b [lreverse $bytes] {append h [format %02x $b]}; return $h}
proc xget {b o n} {set v 0; for {set i 0} {$i<$n} {incr i} {set v [expr {$v|([lindex $b [expr {$o+$i}]]<<(8*$i))}]}; return $v}
proc xcrc {bytes} {
  set c 0xffffffff; foreach b $bytes {
    set c [expr {$c^($b&255)}]
    for {set i 0} {$i<8} {incr i} {if {$c&1} {set c [expr {(($c>>1)^0xedb88320)&0xffffffff]} } else {set c [expr {($c>>1)&0xffffffff}]}}
  }; return [expr {(~$c)&0xffffffff}]
}
proc xput {bytesVar n count} {upvar 1 $bytesVar b; for {set i 0} {$i<$count} {incr i} {lappend b [expr {($n>>(8*$i))&255}]}}
proc xreadcsv {path} {
  set f [open $path r]; set header [gets $f]; set expected "experiment_id,session_id,sequence,input_id,mode,pixels_hex,pixels_sha256,teacher_label,expected_prediction,expected_admitted_exit,expected_executed_exit,expected_stop_reason,payload_crc32,model_id,build_id,binding_id"
  if {$header ne $expected} {close $f; error "case header mismatch"}
  set rows {}; while {[gets $f l]>=0} {if {$l eq ""} continue; set v [split $l ,]; if {[llength $v]!=16} {close $f; error "bad case field count"}; lappend rows $v}; close $f; return $rows
}
proc xmain {} {
  global argc argv
  if {$argc!=3} {error "usage: quartus_stp -t run_external_validation.tcl cases.csv output_dir binding.json"}
  lassign $argv cases out bindingfile
  # Check primary's pilot evidence before loading the JTAG package or calling
  # any hardware discovery/open API. Missing Python/gate fails closed.
  set verifier [file normalize [file join [file dirname $::rtnn_runner_script] .. safety_gates_v1_20261122 pilot_gate.py]]
  if {[catch {exec python $verifier --verify-binding $bindingfile --cases $cases} gateerr]} {error "pilot gate preflight failed before JTAG access: $gateerr"}
  package require ::quartus::jtag
  if {[file exists $out]} {error "refusing existing output directory"}
  set bind [open $bindingfile r]; set bt [read $bind]; close $bind
  if {![regexp {"status"\s*:\s*"PHYSICAL_ELIGIBLE"} $bt] || ![regexp {"sof_sha256"\s*:\s*"([0-9a-f]{64})"} $bt -> sof] || ![regexp {"build_id"\s*:\s*"45585631"} $bt] || ![regexp {"model_id"\s*:\s*"52544e4e"} $bt] || ![regexp {"binding_id"\s*:\s*"45585632"} $bt]} {error "binding is not physical-eligible or identity invalid"}
  set rows [xreadcsv $cases]; if {[llength $rows]==0} {error "empty case file"}
  set exp [lindex [lindex $rows 0] 0]; set session [lindex [lindex $rows 0] 1]; set seen {}
  foreach row $rows {
    lassign $row e s seq iid mode pixhex pixsha label pred admitted executed stop pcrc model build bindid
    if {$e ne $exp || $s ne $session || [dict exists $seen $seq]} {error "mixed experiment/session or duplicate sequence"}; dict set seen $seq 1
    if {![regexp {^[1-9][0-9]*$} $seq] || $iid<1 || $iid>3823 || [string length $pixhex]!=128 || ![regexp {^[0-9a-f]{128}$} $pixhex]} {error "invalid input row $seq"}
    if {$mode ni {fixed2 adaptive} || $label<0 || $label>9 || $pred<0 || $pred>9} {error "invalid mode/label/reference in $seq"}
    if {$model ne "52544e4e" || $build ne "45585631" || $bindid ne "45585632"} {error "case identity mismatch"}
  }
  file mkdir $out; set rf [open [file join $out raw_jtag.log] w]; set cf [open [file join $out physical_results.csv] w]
  fconfigure $rf -buffering line; fconfigure $cf -buffering line
  puts $cf "experiment_id,session_id,sequence,input_id,mode,teacher_label,reference_prediction,prediction,expected_admitted_exit,admitted_exit,expected_executed_exit,executed_exit,expected_stop_reason,stop_reason,cycles_start,cycles_end,cycles,payload_crc32,request_crc_ok,response_crc_ok,model_id,build_id,binding_id,sof_sha256,status,error"
  set locked 0; set opened 0; set status "ERROR"; set error ""; set complete 0
  set rc [catch {
    set hwlist {}; foreach h [get_hardware_names] {if {[string match "USB-Blaster*" $h]} {lappend hwlist $h}}
    if {[llength $hwlist]!=1} {error "expected one USB-Blaster; found $hwlist"}
    set hw [lindex $hwlist 0]; set ds {}; foreach d [get_device_names -hardware_name $hw] {if {[string match "*5CE*" $d]} {lappend ds $d}}
    if {[llength $ds]!=1} {error "expected one Cyclone V; found $ds"}; set dev [lindex $ds 0]
    puts $rf "hardware=$hw device=$dev experiment=$exp session=$session sof_sha256=$sof uart=false flash_written=false sof_programming=false"
    open_device -hardware_name $hw -device_name $dev; set opened 1; device_lock -timeout 10000; set locked 1
    set buildbytes [xbytes [xscan 4 32 ""] 4]; set buildid [xget $buildbytes 0 4]
    if {$buildid!=0x45585631} {error [format "JTAG build ID mismatch 0x%08x" $buildid]}
    set st [lindex [xbytes [xscan 3 8 ""] 1] 0]
    if {$st&0x80 || !($st&0x08)} {error [format "mailbox not READY: 0x%02x" $st]}
    foreach row $rows {
      lassign $row e s seq iid mode pixhex pixsha label pred admitted executed stop pcrc model build bindid
      set px {}; for {set i 0} {$i<64} {incr i} {scan [string range $pixhex [expr {$i*2}] [expr {$i*2+1}]] %x b; if {$b>16} {error "pixel out of range at seq=$seq"}; lappend px $b}
      set payloadcrc [xcrc $px]; if {$payloadcrc!=$pcrc} {error "case payload CRC mismatch seq=$seq"}
      set md [expr {$mode eq "fixed2"?1:3}]; set fx [expr {$mode eq "fixed2"?2:0}]
      set req {82 84 78 81 2}; lappend req $md $fx 0; xput req $seq 4; xput req $iid 2; xput req 65535 2; xput req 0 4; xput req 0x52544e4e 4; xput req 0x45585631 4
      set requestcrc [xcrc $req]; xput req $requestcrc 4; foreach b $px {lappend req $b}; xput req $payloadcrc 4
      if {[llength $req]!=100 || [xcrc [lrange $req 0 27]]!=$requestcrc} {error "request construction error seq=$seq"}
      puts $rf "request seq=$seq input_id=$iid mode=$mode request_lsb_hex=[xpack $req]"
      xscan 1 800 [xpack $req]; set done 0
      for {set poll 0} {$poll<60000} {incr poll} {set st [lindex [xbytes [xscan 3 8 ""] 1] 0]; if {$st&0x40} {set done 1; break}; after 1}
      if {!$done} {error "timeout seq=$seq status=[format 0x%02x $st]"}; if {$st&0x80} {error "mailbox error seq=$seq"}
      set rawrsp [xscan 2 480 [string repeat 0 96]]; puts $rf "response seq=$seq raw_lsb_hex=$rawrsp"; set rb [xbytes $rawrsp 60]
      set rspcrc [xget $rb 56 4]; set crcok [expr {$rspcrc==[xcrc [lrange $rb 0 55]]}]
      set rseq [xget $rb 8 4]; set riid [xget $rb 12 2]; set rpayload [xget $rb 16 4]
      set rmodel [xget $rb 40 4]; set rbuild [xget $rb 44 4]; set rbind [xget $rb 48 4]
      set start [xget $rb 24 8]; set end [xget $rb 32 8]; set cycles [expr {$end-$start}]
      set rmode [lindex $rb 6]; set radm [lindex $rb 20]; set rexe [lindex $rb 21]; set rpred [lindex $rb 22]; set rlabel [lindex $rb 23]; if {$rlabel>=128} {set rlabel [expr {$rlabel-256}]}
      set rstop [lindex $rb 7]; set rspstatus [lindex $rb 5]; set expectedmode $md; set expstop [expr {$mode eq "fixed2"?0:($stop eq "entropy"?1:2)}]
      if {!$crcok || $rspstatus!=0 || $rseq!=$seq || $riid!=$iid || $rmode!=$expectedmode || $rpayload!=$payloadcrc || $rmodel!=0x52544e4e || $rbuild!=0x45585631 || $rbind!=0x45585632 || $rlabel!=-1 || $rpred!=$pred || $radm!=$admitted || $rexe!=$executed || $rstop!=$expstop || $start==0 || $end<=$start || [lindex $rb 52]!=1} {error "response validation failed seq=$seq"}
      puts $cf "$e,$s,$seq,$iid,$mode,$label,$pred,$rpred,$admitted,$radm,$executed,$rexe,$stop,$rstop,$start,$end,$cycles,$payloadcrc,1,$crcok,52544e4e,45585631,45585632,$sof,PASS,"
      incr complete
    }
    set status "COMPLETE"
  } error]
  if {$rc} {set error $error; puts $rf "RUN_ERROR=$error completed=$complete expected=[llength $rows]"; puts $cf "$exp,$session,[expr {$complete+1}],,,,,,,,,,,,,,,,,,,,,,$sof,FAIL,[string map {, _} $error]"}
  if {$locked} {catch {device_unlock}}; if {$opened} {catch {close_device}}
  puts $rf "status=$status completed=$complete expected=[llength $rows]"
  close $rf; close $cf
  set jf [open [file join $out run_status.json] w]; puts $jf "{\"schema\":\"rtnn-external-validation-physical-v1\",\"status\":\"$status\",\"run_source\":\"quartus_stp_virtual_jtag\",\"mock\":false,\"hardware_opened\":[expr {$opened ? \"true\" : \"false\"}],\"cycles_source\":\"Ibex_mcycle\",\"experiment_id\":\"$exp\",\"session_id\":\"$session\",\"sof_sha256\":\"$sof\",\"build_id\":\"45585631\",\"model_id\":\"52544e4e\",\"binding_id\":\"45585632\",\"uart_used\":false,\"flash_written\":false,\"sof_programming_performed\":false,\"completed_cases\":$complete,\"expected_cases\":[llength $rows],\"error\":\"[string map {\\ \\\\ \" \\\"} $error]\"}"; close $jf
  if {$rc} {error $error}
}
if {[catch {xmain} err opts]} {puts stderr "EXTERNAL_VALIDATION_RUN_FAILED: $err"; exit 2}
