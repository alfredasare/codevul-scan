static int prefixmatch(const struct in6_addr *s, const struct in6_addr *d, int prefix_len)
{
        if (prefix_len < 0 || prefix_len > 128) {
                return -1;
        }

        unsigned i;
        for (i=0; i<prefix_len && !((s->s6_addr[i/8]^d->s6_addr[i/8])&(128>>(i%8))); i++);
        return i;
}