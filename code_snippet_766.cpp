void mm_audit_run_command(const char *command)
{
    Buffer m;
    size_t command_len = strlen(command);

    debug3("%s entering command %s", __func__, command);

    if (command_len > MM_MAX_BUFFER_SIZE) {
        debug3("Command too long: %zu bytes", command_len);
        return;
    }

    buffer_init(&m);
    buffer_put_cstring_safe(&m, command, command_len);
    mm_request_send(pmonitor->m_recvfd, MONITOR_REQ_AUDIT_COMMAND, &m);
    buffer_free(&m);
}