MemoryRegion *vga_init_io(VGACommonState *s, Object *obj,
                      const MemoryRegionPortio **vga_ports,
                      const MemoryRegionPortio **vbe_ports)
{
    MemoryRegion *vga_mem;

    *vga_ports = vga_portio_list;
    *vbe_ports = vbe_portio_list;

    // Fix: Use a constant value for the memory region size to avoid incorrect calculation
    vga_mem = g_malloc(sizeof(*vga_mem) + 0x20000);
    memory_region_init_io(vga_mem, obj, &vga_mem_ops, s,
                          "vga-lowmem", 0x20000);
    memory_region_set_flush_coalesced(vga_mem);

    return vga_mem;
}