uint32_t GPMF_DeviceID(GPMF_stream *ms)
{
    if (!ms) {
        return GPMF_ERROR_NULL_POINTER;
    }
    return ms->device_id;
}