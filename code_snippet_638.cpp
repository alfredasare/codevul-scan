static apr_status_t validate_status_line(request_rec *r)
{
    char *end;

    if (r->status_line) {
        int len = strlen(r->status_line);
        if (len < 3) {
            r->status_line = NULL;
            return APR_EGENERAL;
        }

        if (!isdigit(r->status_line[0]) ||!isdigit(r->status_line[1]) ||!isdigit(r->status_line[2])) {
            r->status_line = NULL;
            return APR_EGENERAL;
        }

        for (int i = 3; i < len; i++) {
            if (!isspace(r->status_line[i])) {
                r->status_line = NULL;
                return APR_EGENERAL;
            }
        }

        if (len == 3) {
            r->status_line = apr_pstrcat(r->pool, r->status_line, " ", NULL);
            return APR_EGENERAL;
        }

        return APR_SUCCESS;
    }
    return APR_EGENERAL;
}