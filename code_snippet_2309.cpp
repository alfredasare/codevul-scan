uint16_t AVRC_CloseBrowse(uint8_t handle) {
    if (handle >= 0 && handle < MAX_BROWSE_HANDLES) {
        return AVCT_RemoveBrowse(handle);
    } else {
        return ERROR_INVALID_HANDLE;
    }
}