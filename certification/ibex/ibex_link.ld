OUTPUT_ARCH(riscv)
MEMORY {
  ram   : ORIGIN = 0x00100000, LENGTH = 0x30000
  stack : ORIGIN = 0x00130000, LENGTH = 0x8000
}
_stack_start = ORIGIN(stack) + LENGTH(stack);
_entry_point = _vectors_start + 0x80;
ENTRY(_entry_point)
SECTIONS {
 .vectors : { . = ALIGN(4); _vectors_start = .; KEEP(*(.vectors)) } > ram
 .text : { . = ALIGN(4); *(.text) *(.text.*) } > ram
 .rodata : { . = ALIGN(4); *(.srodata) *(.srodata.*) *(.rodata) *(.rodata.*) } > ram
 .data : { . = ALIGN(4); *(.sdata) *(.sdata.*) *(.data) *(.data.*) } > ram
 .bss : { . = ALIGN(4); _bss_start = .; *(.sbss) *(.sbss.*) *(.bss) *(.bss.*) *(COMMON) _bss_end = .; } > ram
}
