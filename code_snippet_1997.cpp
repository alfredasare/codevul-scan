static void sync_lockstate_on_connect(btif_hh_device_t *p_dev)
{
    uint32_t keylockstates;

    BTIF_TRACE_EVENT("%s: Syncing keyboard lock states after reconnect...", __FUNCTION__);
    /*If the device is connected, update keyboard state */
    update_keyboard_lockstates(p_dev);

    /*Check if the lockstate of caps,scroll,num is set. 
     * If so, send a report to the kernel so the lockstate is in sync */
    keylockstates = get_keylockstates();
    if (keylockstates < sizeof(uint32_t)) { // Add bounds checking
        BTIF_TRACE_DEBUG("%s: Sending hid report to kernel indicating lock key state 0x%x", __FUNCTION__, keylockstates);
        timeout_timer(p_dev, keylockstates); // Replace usleep with a safer alternative
        toggle_os_keylockstates(p_dev->fd, keylockstates);
    } else {
        BTIF_TRACE_DEBUG("%s: NOT sending hid report to kernel indicating lock key state 0x%x", __FUNCTION__, keylockstates);
    }
}