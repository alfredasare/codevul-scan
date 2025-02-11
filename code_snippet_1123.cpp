#define MAX_DOMAIN_LENGTH 256 // Adjust this value based on your requirements

evdns_base_search_add(struct evdns_base *base, const char *domain) {
    EVDNS_LOCK(base);

    if (domain == NULL || strlen(domain) >= MAX_DOMAIN_LENGTH) {
        // Handle error condition, e.g., return an error code or log an error message
        EVDNS_UNLOCK(base);
        return;
    }

    // Copy the string with proper bounds checking
    search_postfix_add(base, strncpy(malloc(MAX_DOMAIN_LENGTH), domain, MAX_DOMAIN_LENGTH - 1));

    EVDNS_UNLOCK(base);
}