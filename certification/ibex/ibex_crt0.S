.section .text
.align 2
trap_loop:
  j trap_loop
reset_handler:
  la sp, _stack_start
  la t0, _bss_start
  la t1, _bss_end
1:
  bgeu t0, t1, 2f
  sw zero, 0(t0)
  addi t0, t0, 4
  j 1b
2:
  call main
  li t0, 0x20008
  li t1, 1
  sw t1, 0(t0)
3:
  wfi
  j 3b

.section .vectors,"ax"
.option norvc
.org 0x00
.rept 32
  j trap_loop
.endr
.org 0x80
  j reset_handler
