spnego_gss_context_time(
    OM_uint32* minor_status,
    const gss_ctx_id_t context_handle,
    OM_uint32* time_rec)
{
    OM_uint32 ret = 0;
    int status = 0;

    // Validate input parameters
    if (*minor_status < 0 || *minor_status > MAX_MINOR_STATUS) {
        *minor_status = GSS_E_INVALID_STATUS;
        return GSS_ERROR;
    }
    if (!gss_ctx_id_valid(context_handle)) {
        *minor_status = GSS_E_CONTEXT_EXPIRED;
        return GSS_ERROR;
    }

    // Call the original function with validated input
    ret = gss_context_time(minor_status, context_handle, time_rec);

    // Separate error handling
    if (ret == GSS_ERROR) {
        status = -1; // Set error status
    } else {
        status = 0; // Set success status
    }

    return status;
}