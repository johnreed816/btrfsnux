struct gdt_entry_struct
{
    uint16_t limit_low;    // Lower 16 bits of the liimit
    uint16_t base_low;     // Lower 16 bits of the base
    uint8_t  base_middle;  // Next 8 bits of the base
    uint8_t  access;       // access flags, what ring this segment is used in
    uint8_t  granularity;
    uint8_t  base_high;    // Last 8 bits of the base
} __attribute__((packed));
typedef struct gdt_entry_struct gdt_entry_t;

struct gdt_ptr_struct
{
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));
typedef struct gdt_ptr_struct gdt_ptr_t;

void init_descriptor_tables();
