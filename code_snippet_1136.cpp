mm_ssh_gssapi_server_ctx(Gssctxt **ctx, gss_OID goid)
{
	Buffer m;
	OM_uint32 major;
	size_t goid_length = goid->length;

	/* Client doesn't get to see the context */
	*ctx = NULL;

	buffer_init(&m);
	if (goid_length > buffer_capacity(&m)) {
		buffer_free(&m);
		return (GSS_S_FAILURE); // Return an error if the buffer isn't large enough
	}
	buffer_put_string(&m, goid->elements, goid_length);

	mm_request_send(pmonitor->m_recvfd, MONITOR_REQ_GSSSETUP, &m);
	mm_request_receive_expect(pmonitor->m_recvfd, MONITOR_ANS_GSSSETUP, &m);

	major = buffer_get_int(&m);

	buffer_free(&m);
	return (major);
}