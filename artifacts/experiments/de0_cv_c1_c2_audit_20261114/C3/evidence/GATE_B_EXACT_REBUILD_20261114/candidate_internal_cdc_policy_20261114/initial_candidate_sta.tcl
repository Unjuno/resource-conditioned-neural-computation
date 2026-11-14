load_package sta
load_package report
project_open rtnn_c2
create_timing_netlist
read_sdc
update_timing_netlist
set out {D:/rtnn_c3_gateb_exact_rebuild_20261114_internal_cdc_sdc_candidate/candidate_sta}
file mkdir $out
report_clocks -file "$out/clocks.rpt"
report_exceptions -setup -detail path_summary -npaths 1000 -file "$out/exceptions.rpt"
set f [open "$out/crossing_counts.txt" w]
set i 0
foreach op [get_available_operating_conditions] {
 set_operating_conditions $op
 update_timing_netlist
 set a [get_timing_paths -setup -from [get_clocks {altera_reserved_tck}] -to [get_clocks {CLOCK_50}] -npaths 5000]
 set b [get_timing_paths -setup -from [get_clocks {CLOCK_50}] -to [get_clocks {altera_reserved_tck}] -npaths 5000]
 set na [get_collection_size $a]; set nb [get_collection_size $b]
 puts $f "corner=$i op=$op tck_to_sys=$na sys_to_tck=$nb"
 if {$na != 800 || $nb != 384} { error "Unaccounted cross-domain paths at $op: $na/$nb" }
 report_timing -setup -from [get_clocks {altera_reserved_tck}] -to [get_clocks {CLOCK_50}] -npaths 800 -detail summary -file "$out/tck_to_sys_${i}.rpt"
 report_timing -setup -from [get_clocks {CLOCK_50}] -to [get_clocks {altera_reserved_tck}] -npaths 384 -detail summary -file "$out/sys_to_tck_${i}.rpt"
 report_max_skew -npaths 8 -file "$out/skew_${i}.rpt"
 report_ucp -panel_name {Unconstrained Paths} -file "$out/ucp_${i}.rpt"
 incr i
}
close $f
if {$i != 4} { error "Expected 4 corners" }
project_close
