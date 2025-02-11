size_t yystpcpy(char *yydest, const char *yysrc)
{
    size_t dest_len = strlen(yydest);
    size_t src_len = strlen(yysrc);

    if (dest_len >= src_len) {
        memcpy(yydest, yysrc, src_len);
    } else {
        /* Handle error or truncate the source string */
    }

    return yydest + src_len;
}