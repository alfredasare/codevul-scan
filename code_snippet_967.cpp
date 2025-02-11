void evdns_base_search_add(struct evdns_base *base, const char *domain) {
    size_t domain_len = strlen(domain);

    EVDNS_LOCK(base);
    if (domain_len > EVDNS_MAX_DOMAIN_LENGTH) {
        /* Handle error or truncate the domain if necessary */
    }
    search_postfix_add(base, domain, domain_len);
    EVDNS_UNLOCK(base);
}