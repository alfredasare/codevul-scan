hook_hsignal (struct t_weechat_plugin *plugin, const char *signal,
              t_hook_callback_hsignal *callback, void *callback_data)
{
    struct t_hook *new_hook;
    struct t_hook_hsignal *new_hook_hsignal;
    int priority;
    const char *ptr_signal;

    if (!signal || strlen(signal) == 0 || !callback)
        return NULL;

    static const char *allowed_signals[] = {"signal1", "signal2",...};
    int i;
    for (i = 0; i < sizeof(allowed_signals) / sizeof(*allowed_signals); i++) {
        if (strcmp(signal, allowed_signals[i]) == 0) {
            break;
        }
    }
    if (i == sizeof(allowed_signals) / sizeof(*allowed_signals)) {
        error("Invalid signal: %s", signal);
        return NULL;
    }

    //...
}