static int override_release(char __user *release, size_t len)
{
    int ret = 0;

    if (current->personality & UNAME26) {
        const char *rest = UTS_RELEASE;
        char buf[65] = { 0 };
        int ndots = 0;
        unsigned v;
        size_t copy;

        if (strchr(release, '/') || strchr(release, '\\')) {
            return -EINVAL; // Return error if directory traversal characters found
        }

        v = ((LINUX_VERSION_CODE >> 8) & 0xff) + 40;
        copy = scnprintf(buf, sizeof(buf), "2.6.%u%s", v, rest);
        copy += 1;
        ret = copy_to_user(release, buf, copy);
    }
    return ret;
}