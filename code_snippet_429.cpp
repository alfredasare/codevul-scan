void bpf_verifier_log_write(struct bpf_verifier_env *env, const char *fmt,...)
{
    va_list args;

    if (!bpf_verifier_log_needed(&env->log))
        return;

    va_start(args, fmt);
    char buffer[1024]; // Define a buffer size large enough to hold the formatted string
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    bpf_verifier_vlog(&env->log, buffer);
    va_end(args);
}