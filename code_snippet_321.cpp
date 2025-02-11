bt_status_t btif_dut_mode_configure(uint8_t enable)
{
    BTIF_TRACE_DEBUG("%s", __FUNCTION__);

    // Validate input parameter
    if (enable!= 0 && enable!= 1) {
        BTIF_TRACE_ERROR("Invalid enable value");
        return BT_STATUS_INVALID_PARAM;
    }

    if (!stack_manager_get_interface()->get_stack_is_running()) {
        BTIF_TRACE_ERROR("btif_dut_mode_configure : Bluetooth not enabled");
        return BT_STATUS_NOT_READY;
    }

    btif_dut_mode = enable;

    if (enable == 1) {
        // Use a secure method to enable test mode
        BTA_SecureEnableTestMode();
    } else {
        // Use a secure method to disable test mode
        BTA_SecureDisableTestMode();
    }

    return BT_STATUS_SUCCESS;
}