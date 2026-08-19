.section .vectors,"ax",@progbits
.globl _trap
_trap:
  li t0, 0x20008
  li t1, 1
  sw t1, 0(t0)
1: j 1b

.section .text.start,"ax",@progbits
.globl _start
_start:
  li sp, 0x1fffc0
  la t0, __bss_start
  la t1, __bss_end
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
3: j 3b
