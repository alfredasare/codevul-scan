static void check_guest_throttling(void)
{
    int64_t t1;

    if (!mig_throttle_on) {
        return;
    }

    t1 = qemu_clock_get_ns(QEMU_CLOCK_REALTIME);

    /* If it has been more than 40 ms since the last time the guest
     * was throttled then do it again.
     */
    if (40 < (t1 - qemu_clock_get_ns(QEMU_CLOCK_REALTIME))/1000000) {
        mig_throttle_guest_down();
    }
}