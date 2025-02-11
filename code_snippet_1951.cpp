UNCURL_EXPORT void uncurl_set_header_str(struct uncurl_conn *ucc, char *name, char *value)
{
    struct http_out *hout = ucc->hout;
    ucc->hout = http_set_header(hout, name, HTTP_STRING, value);
    if (hout!= NULL) {
        http_free_out(hout);
    }
}