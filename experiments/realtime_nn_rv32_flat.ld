ENTRY(rtnn_fixed_certify_class)
SECTIONS {
  . = 0x00010000;
  .text : { *(.text .text.*) }
  .rodata : ALIGN(16) { *(.rodata .rodata.*) }
  .data : ALIGN(16) { *(.data .data.*) }
  .bss : ALIGN(16) { *(.bss .bss.* COMMON) }
}
