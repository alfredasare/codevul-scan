mm_answer_sessid(int sock, Buffer *m)
{
	int i;

	debug3("%s entering", __func__);

	if (buffer_len(m) > 16) {
		error("%s: ssh1 session id too long", __func__);
		return (-1);
	}
	buffer_copy_bytes(session_id, buffer_ptr(m), buffer_len(m));

	/* Turn on permissions for getpwnam */
	monitor_permit(mon_dispatch, MONITOR_REQ_PWNAM, 1);

	return (0);
}