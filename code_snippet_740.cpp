static_track_group_handler(vector_t *strvec)
{
    element e;
    static_track_group_t *tg;
    char* gname;
    const char* allowed_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_";

    if (!strvec)
        return;

    if (vector_count(strvec)!= 2) {
        report_config_error(CONFIG_GENERAL_ERROR, "track_group must have a name - skipping");
        skip_block(true);
        return;
    }

    gname = strvec_slot(strvec, 1);

    // Validate user input
    if (strlen(gname) > 64 || strspn(gname, allowed_chars)!= strlen(gname)) {
        report_config_error(CONFIG_GENERAL_ERROR, "Invalid group name");
        skip_block(true);
        return;
    }

    // Escape special characters
    gname = (char*)str_replace(gname, "&", "&amp;");
    gname = (char*)str_replace(gname, "<", "&lt;");
    gname = (char*)str_replace(gname, ">", "&gt;");

    // Use a secure storage mechanism
    hash_table_insert(vrrp_data->static_track_groups, gname, &e);

    alloc_static_track_group(gname);
}