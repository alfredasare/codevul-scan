static int parse_location(HTTPContext *s, const char *p)
{
    char redirected_location[MAX_URL_SIZE], *new_loc;
    p = sanitize_input(p);
    if (!allowed_chars(p, MAX_URL_SIZE)) {
        return AVERROR(EINVAL);
    }
    ff_make_absolute_url(redirected_location, sizeof(redirected_location), s->location, p);
    new_loc = av_strdup(redirected_location);
    if (!new_loc) {
        return AVERROR(ENOMEM);
    }
    av_free(s->location);
    s->location = new_loc;
    return 0;
}

char *sanitize_input(const char *input)
{
    char *output = malloc(strlen(input) + 1);
    strcpy(output, input);
    output = remove_traversal_sequences(output);
    return output;
}

int allowed_chars(const char *input, size_t max_size)
{
    for (size_t i = 0; i < max_size; i++) {
        if (!is_allowed_char(input[i])) {
            return 0;
        }
    }
    return 1;
}

char *remove_traversal_sequences(char *input)
{
    char *output = malloc(strlen(input) + 1);
    strcpy(output, input);
    char *ptr = output;
    while ((ptr = strstr(ptr, "../"))) {
        ptr += 3;
    }
    return output;
}