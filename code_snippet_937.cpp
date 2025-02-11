#include <limits.h>

#define DNS_OPTION_FLAGS_MAX 0x000000FF

void evdns_resolv_set_defaults(struct evdns_base *base, int flags) {
    if (flags > DNS_OPTION_FLAGS_MAX) {
        return;
    }
    ASSERT_LOCKED(base);
    if (flags & DNS_OPTION_SEARCH) search_set_from_hostname(base);
    if (flags & DNS_OPTION_NAMESERVERS) evdns_base_nameserver_ip_add(base, "127.0.0.1");
}