static int parse_location(HTTPContext *s, const char *p)
{
    size_t len = strlen(s->location) + strlen(p) + MAX_URL_SIZE;
    char *redirected_location = av_malloc(len);
    if (!redirected_location)
        return AVERROR(ENOMEM);

    ff_make_absolute_url(redirected_location, len, s->location, p);
    if (strlen(redirected_location) >= len) {
        av_free(redirected_location);
        return AVERROR(EOVERFLOW);
    }

    char *new_loc = av_strdup(redirected_location);
    av_free(redirected_location);
    if (!new_loc)
        return AVERROR(ENOMEM);

    av_free(s->location);
    s->location = new_loc;
    return 0;
}