static void port_outb(const struct si_sm_io *io, unsigned int offset, unsigned char b) {
    unsigned int addr = io->addr_data;
    unsigned int calculated_addr = addr + (offset * io->regspacing);

    if ((offset > io->max_offset) || (offset < io->min_offset)) {
        // Handle invalid offset
    }

    outb(b, calculated_addr);
}