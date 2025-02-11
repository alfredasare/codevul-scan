static char *get_next_cgroup_dir(const char *taskcg, const char *querycg)
{
    char *start, *end;
    size_t querycg_len = strlen(querycg);

    if (querycg_len >= strlen(taskcg)) {
        fprintf(stderr, "%s: I was fed bad input\n", __func__);
        return NULL;
    }

    // Validate querycg string
    if (strchr(querycg, '/') || strchr(querycg, '\\')) {
        fprintf(stderr, "%s: Invalid querycg string\n", __func__);
        return NULL;
    }

    if (strcmp(querycg, "/") == 0)
        start = strdup(taskcg + 1);
    else
        start = strdup(taskcg + strlen(querycg) + 1);
    if (!start)
        return NULL;

    end = strchr(start, '/');
    if (end)
        *end = '\0';
    return start;
}