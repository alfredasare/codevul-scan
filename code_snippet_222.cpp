ready_callback_key_compare_only_active (gconstpointer a, gconstpointer b)
{
    const ReadyCallback *callback_a = a, *callback_b = b;

    /* Check if both inputs are valid and non-NULL */
    if (!callback_a || !callback_b)
    {
        return -1;
    }

    /* Non active callbacks never match */
    if (!callback_a->active || !callback_b->active)
    {
        return -1;
    }

    return ready_callback_key_compare (a, b);
}