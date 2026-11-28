lassign $argv verifier binding cases
if {[catch {exec python $verifier --verify-binding $binding --cases $cases} err]} {puts stderr "GATE_ERROR=$err"; exit 9}
puts "GATE_PREFLIGHT_OK"
if {[catch {package require ::quartus::jtag} err]} {puts stderr "PACKAGE_ERROR=$err"; exit 8}
puts "JTAG_PACKAGE_LOAD_OK"
exit 0
