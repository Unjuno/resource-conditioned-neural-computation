if {$argc != 1} {puts stderr "usage: checker target.tcl"; exit 2}
set f [open [lindex $argv 0] r]
set source_text [read $f]
close $f
if {![info complete $source_text]} {puts stderr "TCL_INCOMPLETE"; exit 1}
puts "TCL_INFO_COMPLETE_ONLY_PASS"
exit 0
