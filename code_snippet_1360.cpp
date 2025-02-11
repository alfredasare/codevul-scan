mm_answer_bsdauthquery(int sock, Buffer *m)
{
    char *name, *infotxt;
    u_int numprompts;
    u_int *echo_on;
    char **prompts;
    u_int success;

    if (!options.kbd_interactive_authentication)
        fatal("%s: kbd-int authentication not enabled", __func__);

    success = bsdauth_query(authctxt, &name, &infotxt, &numprompts,
                            &prompts, &echo_on) < 0? 0 : 1;

    buffer_clear(m);
    buffer_put_int(m, success);

    if (success) {
        size_t max_length = 256; // Define a maximum allowed length
        if (numprompts > 0 && strlen(prompts[0]) <= max_length) {
            buffer_put_string(m, prompts[0]);
        } else {
            fatal("%s: prompt exceeds maximum allowed length", __func__);
        }

        debug3("%s: sending challenge success: %u", __func__, success);
        mm_request_send(sock, MONITOR_ANS_BSDAUTHQUERY, m);

        if (success) {
            free(name);
            free(infotxt);
            for (int i = 0; i < numprompts; i++)
                free(prompts[i]);
            free(prompts);
            free(echo_on);
        }
    }

    return (0);
}