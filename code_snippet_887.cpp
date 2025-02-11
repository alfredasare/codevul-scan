struct NntpData *mutt_newsgroup_subscribe(struct NntpServer *nserv, char *group)
{
    struct NntpData *nntp_data = NULL;

    if (!nserv ||!nserv->groups_hash ||!group ||!*group)
        return NULL;

    // Verify and sanitize the input group parameter
    const char *allowed_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789._";
    size_t i = 0;
    while (group[i]) {
        if (strchr(allowed_chars, group[i]) == NULL) {
            // Invalid character detected, return error
            return NULL;
        }
        i++;
    }

    nntp_data = nntp_data_find(nserv, group);
    nntp_data->subscribed = true;
    if (!nntp_data->newsrc_ent) {
        nntp_data->newsrc_ent = mutt_mem_calloc(1, sizeof(struct NewsrcEntry));
        nntp_data->newsrc_len = 1;
        nntp_data->newsrc_ent[0].first = 1;
        nntp_data->newsrc_ent[0].last = 0;
    }
    return nntp_data;
}