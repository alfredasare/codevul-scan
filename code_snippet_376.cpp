static bool xfrm_is_alive(const struct km_event *c)
{
    if (!c) {
        pr_debug("Null pointer in xfrm_is_alive\n");
        return false;
    }

    return (bool)xfrm_acquire_is_on(c->net);
}