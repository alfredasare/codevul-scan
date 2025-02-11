static int cirrus_bitblt_videotovideo_copy(CirrusVGAState * s)
{
    if (!blit_is_valid_address(s->cirrus_blt_dstaddr) ||!blit_is_valid_address(s->cirrus_blt_srcaddr))
        return 0;

    if (blit_is_unsafe(s))
        return 0;

    cirrus_do_copy(s, s->cirrus_blt_dstaddr - s->vga.start_addr,
            s->cirrus_blt_srcaddr - s->vga.start_addr,
            s->cirrus_blt_width, s->cirrus_blt_height);

    return 1;
}

bool blit_is_valid_address(uintptr_t addr)
{
    static const uintptr_t allowed_addresses[] = {
        // Add allowed addresses here
    };

    for (size_t i = 0; i < ARRAY_SIZE(allowed_addresses); i++) {
        if (addr == allowed_addresses[i]) {
            return true;
        }
    }

    return false;
}