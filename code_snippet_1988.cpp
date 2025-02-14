static ssize_t pages_volatile_show(struct kobject *kobj,
                           struct kobj_attribute *attr, char *buf)
{
        long ksm_pages_volatile, max_value;

        /* Calculate the maximum possible value without overflow */
        max_value = LONG_MAX - ksm_pages_shared - ksm_pages_sharing;
        if (ksm_rmap_items > max_value)
                return -EINVAL;

        ksm_pages_volatile = ksm_rmap_items - ksm_pages_shared
                - ksm_pages_sharing - ksm_pages_unshared;

        /*
         * It was not worth any locking to calculate that statistic,
         * but it might therefore sometimes be negative: conceal that.
         */
        if (ksm_pages_volatile < 0)
                ksm_pages_volatile = 0;

        return sprintf(buf, "%ld\n", ksm_pages_volatile);
}