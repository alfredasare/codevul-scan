void dec_ucount(struct ucounts *ucounts, enum ucount_type type)
{
    struct ucounts *iter;
    for (iter = ucounts; iter; iter = iter->ns->ucounts) {
        int dec = atomic_dec_if_positive(&iter->ucount[type]);
        WARN_ON_ONCE(dec < 0);
        iter = iter->ns->ucounts; // Update iter to point to the next ucounts
    }
    put_ucounts(ucounts);
}