create_attr_list(gpointer name, gpointer value, gpointer data)
{
    const char *filt_str[] = FILTER_STR;

    CRM_CHECK(name != NULL, return);

    /* filtering automatic attributes */
    size_t name_len = strlen(name);
    for (int i = 0; filt_str[i] != NULL; i++) {
        size_t filt_len = strlen(filt_str[i]);
        if (filt_len > name_len && strncmp(filt_str[i], name, filt_len) == 0) {
            return;
        }
    }

    attr_list = g_list_insert_sorted(attr_list, name, compare_attribute);
}