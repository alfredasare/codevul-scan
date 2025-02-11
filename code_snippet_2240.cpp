void val_del_sec_ctx_args(
    OM_uint32 *minor_status,
    gss_ctx_id_t *context_handle,
    gss_buffer_t output_token)
{
    /* Initialize outputs. */

    if (minor_status!= NULL)
	*minor_status = 0;

    /* Validate arguments. */

    if (minor_status == NULL)
	return (GSS_S_CALL_INACCESSIBLE_WRITE);

    if (context_handle == NULL || *context_handle == GSS_C_NO_CONTEXT)
	return (GSS_S_CALL_INACCESSIBLE_WRITE | GSS_S_NO_CONTEXT);

    if (output_token!= GSS_C_NO_BUFFER) {
	output_token->length = 0;
    }

    return (GSS_S_COMPLETE);
}