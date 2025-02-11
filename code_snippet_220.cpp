ready_callback_key_compare_only_active (gconstpointer a,
                                        gconstpointer b)
{
    const ReadyCallback *callback_a;

    callback_a = a;

    /* Validate and sanitize input parameters */
    if (!a ||!b ||!callback_a ||!callback_a->active)
    {
        return -1;
    }

    /* Use a secure comparison function */
    return g_strcmp0 (a, b);
}