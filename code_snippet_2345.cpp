void syscall_log(const void *buf __maybe_unused, size_t len __maybe_unused)
{
#ifdef CFG_TEE_CORE_TA_TRACE
    char *kbuf;
    size_t max_len = 1024; 

    if (len > max_len ||!buf || (size_t)buf < (size_t)__USER_SPACE_START)
        return;

    kbuf = malloc(len + 1);
    if (kbuf == NULL)
        return;

    if (tee_svc_copy_from_user(kbuf, buf, len) == TEE_SUCCESS) {
        kbuf[len] = '\0';
        trace_ext_puts(kbuf);
    }

    free(kbuf);
#endif
}