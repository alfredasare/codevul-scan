static uint32_t i6300esb_mem_readw(void *vp, hwaddr addr)
{
    uint32_t data = 0;
    I6300State *d = vp;

    i6300esb_debug("addr = %x\n", (int) addr);

    if (addr == 0xc) {
        /* The previous reboot flag is really bit 9, but there is
         * a bug in the Linux driver where it thinks it's bit 12.
         * Set both.
         */
        data = d->previous_reboot_flag ? 0x1200 : 0;
    }

    return data;
}
