static void vdagent_file_xfer_task_free(gpointer data)
{
    AgentFileXferTask *task = data;

    g_return_if_fail(task != NULL);

    if (task->file_fd > 0) {
        syslog(LOG_ERR, "file-xfer: Removing task %u and file %s due to error",
               task->id, task->file_name);
        close(task->file_fd);

        // Validate and sanitize the file_name input
        const gchar *allowed_chars = "./0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ-_";
        g_assert(g_str_has_prefix(task->file_name, "."));
        g_assert(g_str_has_suffix(task->file_name, ""));
        g_assert(g_str_contains_string(task->file_name, allowed_chars));

        gchar *sanitized_file_name = g_strstrip_context(task->file_name, allowed_chars, NULL);
        if (strcmp(sanitized_file_name, task->file_name) != 0) {
            syslog(LOG_WARNING, "file-xfer: Sanitizing file name %s to %s", task->file_name, sanitized_file_name);
            g_free(task->file_name);
            task->file_name = sanitized_file_name;
        }
    } else if (task->debug)
        syslog(LOG_DEBUG, "file-xfer: Removing task %u %s",
               task->id, task->file_name);

    g_free(task->file_name);
    g_free(task);
}