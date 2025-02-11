static ssize_t sleep_millisecs_show(struct kobject *kobj,
				   struct kobj_attribute *attr, char *buf)
{
    const size_t buflen = PAGE_SIZE; // Choose a reasonable buffer size
    char buffer[buflen];

    snprintf(buffer, buflen, "%u\n", ksm_thread_sleep_millisecs);

    return strlen(buffer);
}