ENTRY(_start)

SECTIONS
{
    /* Begin at 1 MB */
    . = 1M;
    
    /* Multiboot header and text section */
    .text BLOCK(4K) : ALIGN(4K)
    {
        *(.multiboot)
        *(.text)
    }

    /* read-only */
    .rodata BLOCK(4K) : ALIGN(4K)
    {
        *(.rodata)
    }

    /* read/write data (initialized) */
    .data BLOCK(4K) : ALIGN(4K)
    {
        *(.data)
    }

    /* read/write data (uninitialized) and the stack */
    .bss BLOCK(4K) : ALIGN(4K)
    {
        *(COMMON)
        *(.bss)
        *(.bootstrap_stack)
    }

    /* the compiler may produce other sections, by default it will put them in a segment
       with the same name. Simply add stuff here as needed. */
}
