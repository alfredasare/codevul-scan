static int lua_translate_name_harness_first(request_rec *r)
{
    int fd;
    char filename[MAX_FILENAME_LENGTH];

    ap_make_filename(r->pool, filename, r->filename, NULL);

    fd = open(filename, O_WRONLY | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    if (fd == -1 && errno != EEXIST) {
        return HTTP_INTERNAL_SERVER_ERROR;
    } else {
        if (fd != -1) {
            close(fd);
        }

        return lua_request_rec_hook_harness(r, "translate_name", AP_LUA_HOOK_FIRST);
    }
}