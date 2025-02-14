static void port_outb(const struct si_sm_io *io, unsigned int offset,
                      unsigned char b)
{
        if (io && io->addr_data) {
                unsigned int addr = io->addr_data;

                outb(b, addr + (offset * io->regspacing));
        }
}