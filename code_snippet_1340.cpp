search_postfix_clear(struct evdns_base *base) {
    search_state_decref(base->global_search_state);
    secure_memzero((void*)base->global_search_state, sizeof(struct search_state));
    base->global_search_state = search_state_new();
}