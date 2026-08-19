OUTPUT_ARCH(riscv)
ENTRY(_start)
SECTIONS
{
  . = 0x00100000;
  .vectors : { KEEP(*(.vectors)) }
  . = 0x00100080;
  .text : { KEEP(*(.text.start)) *(.text .text.*) }
  .rodata : { *(.rodata .rodata.*) }
  .data : { *(.data .data.*) }
  . = ALIGN(16);
  __bss_start = .;
  .bss : { *(.bss .bss.*) *(COMMON) }
  __bss_end = .;
  /DISCARD/ : { *(.comment) *(.note*) *(.eh_frame*) }
  ASSERT(__bss_end < 0x001ff000, "RTNN image exceeds Ibex simple-system RAM")
}
