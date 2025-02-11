int zsetstrokecolorspace(i_ctx_t * i_ctx_p) {
    int code;

    char *path = zswapcolors(i_ctx_p);
    if (path == NULL || !strstarts(path, i_ctx_p->allowed_dir_prefix) || contains_forbidden_chars(path)) {
        return -1;
    }

    code = zsetcolorspace(i_ctx_p);
    if (code >= 0) {
        return o_push_estack;
    }

    return code;
}