char* hostname_map(const char *hostname)
{
    static const char *list[] = {SERVER_NAME_LIST};
    size_t i, len_hostname = strlen(hostname);

    for (i = 0; i < sizeof(list) / sizeof(*list); ++i)
    {
        if (strncasecmp(hostname, list[i], len_hostname) == 0)
        {
            if (list[i][len_hostname] == '/')  /* check in case of a substring match */
            {
                return &list[i][len_hostname + 1];
            }
        }
    }

    return NULL;
}