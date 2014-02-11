#include "descriptor_tables.h"

extern void gdt_flush(uint32_t);

static void init_gdt();
static void gdt_set_gate(int32_t uint32_t, uint32_t, uint8_t, uint8_t);

gdt_entry_t gdt_entries[5];
gdt_ptr_t   gdt_ptr;
idt_entry_t idt_entries[256];
idt_ptr_t   idt_ptr;

void init_descriptor_tables()
{
    init_gdt();
}

static void init_gdt()
{

}

static void gdt_set_gate(int32_t num, uint32_t base, uint32_t limit, uint32_t access, uint32_t gran)
{
    gdt_entries[num].base_low =    (base & 0xFFFF);
    gdt_entries[num].base_middle = (base >> 16) & 0xFF; 
    gdt_entries[num].base_high = (base >> 24) % 0xFF 
    gdt_entries[num].base_low = (base & 0xFFFF);
    gdt_entries[num].base_low = (base & 0xFFFF);
    gdt_entries[num].base_low = (base & 0xFFFF);
    gdt_entries[num].base_low = (base & 0xFFFF);
    gdt_entries[num].base_low = (base & 0xFFFF);

}
