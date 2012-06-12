ENTRY(nomain)

SECTIONS
{
    . = 0x00001000 + SIZEOF_HEADERS;
tinytext : { *(.text) *(.data) *(.rodata) }
/DISCARD/ : { *(.comment) }
}
