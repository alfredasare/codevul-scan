mtree_bid(struct archive_read *a, int best_bid)
{
    const char *signature = "#mtree";
    const char *p;
    const char *allowed_paths[] = {"/path/to/allowed/directory", "/path/to/another/allowed/directory"}; // Whitelist allowed directories

    (void)best_bid; /* UNUSED */

    p = __archive_read_ahead(a, strlen(signature), NULL);
    if (p == NULL ||!is_allowed_path(p, allowed_paths)) {
        return (-1);
    }

    if (memcmp(p, signature, strlen(signature)) == 0)
        return (8 * (int)strlen(signature));

    return (detect_form(a, NULL));
}

bool is_allowed_path(const char *path, const char *allowed_paths[])
{
    for (int i = 0; allowed_paths[i]!= NULL; i++) {
        if (strcmp(path, allowed_paths[i]) == 0) {
            return true;
        }
    }
    return false;
}