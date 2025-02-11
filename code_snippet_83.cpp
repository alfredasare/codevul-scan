spnego_gss_context_time(
		OM_uint32	*minor_status,
		const gss_ctx_id_t context_handle,
		OM_uint32	*time_rec)
{
	OM_uint32 ret;

	// Check if input parameters are valid before using them
	if (minor_status == NULL || context_handle == GSS_C_NO_CONTEXT || time_rec == NULL) {
		*minor_status = 0; // Set *minor_status to success value (0) or an appropriate error code
		return (GSS_S_FAILURE);
	}

	ret = gss_context_time(minor_status,
			    context_handle,
			    time_rec);
	return (ret);
}