static struct ifsock *find_iface(struct sockaddr *sa)
{
    struct ifsock *ifs;
    struct sockaddr_in *addr = (struct sockaddr_in *)sa;
    struct ifsock *tmp;

    if (!sa)
        return NULL;

    LIST_FOREACH_SAFE(ifs, &il, link, tmp) {
        if (ifs->addr.sin_addr.s_addr == addr->sin_addr.s_addr)
            return ifs;
    }

    return NULL;
}