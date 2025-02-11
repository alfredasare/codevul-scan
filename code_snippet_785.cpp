static apr_status_t validate_status_line(request_rec *r)
{
    char *end;

    if (r->status_line) {
        int len = strlen(r->status_line);

        /* Check for proper format: HTTP status code followed by space and reason phrase */
        if (len < 8
            || strncmp(r->status_line, "HTTP/", 5) != 0
            || !isdigit(r->status_line[5])
            || r->status_line[6] != ' '
            || apr_strtoi64(r->status_line + 7, &end, 10) != r->status
            || (end - r->status_line) != (7 + strlen(AprHttpStatusText(r->status)))
            || strcmp(end, AprHttpStatusText(r->status)) != 0) {
            r->status_line = NULL;
            return APR_EGENERAL;
        }

        /* Since we passed the above check, we know that length three
         * is equivalent to only a 3 digit numeric http status.
         * RFC2616 mandates a trailing space, let's add it.
         */
        if (len == 8 + strlen(AprHttpStatusText(r->status))) {
            r->status_line = apr_pstrcat(r->pool, r->status_line, " ", NULL);
            return APR_EGENERAL;
        }
        return APR_SUCCESS;
    }
    return APR_EGENERAL;
}