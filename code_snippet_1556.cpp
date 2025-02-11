static int unlazy_link(struct nameidata *nd, struct path *link, unsigned seq)
{
    char *sanitized_path = sanitize_path(link->mnt->mnt_path);
    if (unlikely(!legitimize_path(nd, sanitized_path, seq))) {
        //...
    } else if (likely(unlazy_walk(nd, NULL, 0)) == 0) {
        free(sanitized_path);
        return 0;
    }
    free(sanitized_path);
    path_put(link);
    return -ECHILD;
}

char *sanitize_path(char *path) {
    char *sanitized_path = strndup(path, strlen(path));
    return sanitized_path;
}