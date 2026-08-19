ENTRY(_start)
MEMORY {
  RAM (rwx) : ORIGIN = 0x00100000, LENGTH = 0x00100000
}
SECTIONS {
  .vectors 0x00100000 : {
    KEEP(*(.vectors))
  } > RAM
  .text 0x00100080 : {
    KEEP(*(.start))
    *(.text .text.*)
  } > RAM
  .rodata : ALIGN(16) {
    *(.rodata .rodata.*)
  } > RAM
  .data : ALIGN(16) {
    *(.data .data.*)
  } > RAM
  .bss : ALIGN(16) {
    __bss_start = .;
    *(.bss .bss.* COMMON)
    __bss_end = .;
  } > RAM
  . = ALIGN(16);
  __image_end = .;
  __stack_top = ORIGIN(RAM) + LENGTH(RAM) - 16;
  /DISCARD/ : { *(.comment) *(.note*) *(.eh_frame*) }
}
