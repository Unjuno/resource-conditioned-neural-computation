ENTRY(_start)
MEMORY { RAM (rwx) : ORIGIN = 0x00100000, LENGTH = 0x00040000 }
/* Explicit one-segment FPGA RAM load image for Clang/LLD and GNU ld. */
PHDRS { ram PT_LOAD FLAGS(7); }
SECTIONS {
  .vectors 0x00100000 : { KEEP(*(.vectors)) } > RAM :ram
  .text 0x00100080 : { KEEP(*(.start)) *(.text .text.*) } > RAM :ram
  .rodata : ALIGN(16) { *(.rodata .rodata.*) } > RAM :ram
  .data : ALIGN(16) { *(.data .data.*) } > RAM :ram
  .bss : ALIGN(16) {
    __bss_start = .;
    *(.bss .bss.* COMMON)
    __bss_end = .;
  } > RAM :ram
  . = ALIGN(16);
  __image_end = .;
  __stack_top = 0x0013fff0;
  ASSERT(__image_end <= 0x00138000, "B firmware overlaps 32 KiB reserved stack")
  /DISCARD/ : { *(.comment) *(.note*) *(.eh_frame*) }
}
