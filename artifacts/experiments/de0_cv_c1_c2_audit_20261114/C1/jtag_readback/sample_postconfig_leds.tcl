package require ::quartus::jtag
set hw {USB-Blaster [USB-0]}
set dev {@1: 5CE(BA4|FA4) (0x02B050DD)}
set opened 0
set locked 0
if {[catch {
  open_device -hardware_name $hw -device_name $dev
  set opened 1
  device_lock -timeout 10000
  set locked 1
  device_ir_shift -ir_value 6 -no_captured_ir_value
  set id_before [device_dr_shift -length 32 -value_in_hex]
  puts "IDCODE_BEFORE=$id_before"
  if {[string equal -nocase $id_before 02b050dd] == 0} { error "IDCODE mismatch before SAMPLE" }
  device_ir_shift -ir_value 5 -no_captured_ir_value
  set zeroes [string repeat 0 216]
  set bsr [device_dr_shift -dr_value $zeroes -length 864 -value_in_hex]
  puts "SAMPLE_BSR_HEX=$bsr"
  puts "SAMPLE_BSR_HEX_LENGTH=[string length $bsr]"
  device_ir_shift -ir_value 6 -no_captured_ir_value
  set id_after [device_dr_shift -length 32 -value_in_hex]
  puts "IDCODE_AFTER=$id_after"
  if {[string equal -nocase $id_after 02b050dd] == 0} { error "IDCODE mismatch after SAMPLE" }
} result options]} {
  puts stderr "JTAG_SAMPLE_ERROR=$result"
  if {$locked} { catch {device_unlock} }
  if {$opened} { catch {close_device} }
  return -options $options $result
}
if {$locked} { device_unlock }
if {$opened} { close_device }
puts "SAMPLE_SEQUENCE_COMPLETE=1"
