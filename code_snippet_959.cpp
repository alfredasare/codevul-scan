mm_answer_sessid(int sock, Buffer *m)
{
    int i;
    size_t len;

    debug3("%s entering", __func__);

    len = buffer_len(m);
    if (len!= 16)
        fatal("%s: bad ssh1 session id", __func__);

    if (len > 16)
        fatal("%s: buffer overflow", __func__);

    for (i = 0; i < 16 && i < len; i++)
        session_id[i] = buffer_get_char(m);

    /* Turn on permissions for getpwnam */
    monitor_permit(mon_dispatch, MONITOR_REQ_PWNAM, 1);

    return (0);
}