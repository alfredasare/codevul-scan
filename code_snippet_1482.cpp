R_API void r_config_hold_free(RConfigHold *h) {
    if (h) {
        if (h->list_num) {
            r_list_free(h->list_num);
        }
        if (h->list_char) {
            r_list_free(h->list_char);
        }
        R_FREE(h);
    }
}