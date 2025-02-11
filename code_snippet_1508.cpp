static int global_template_search(const char *key, void *data, void *privdata)
{
    template_iter_t *iter = privdata;
    default_template_t *def_t = data;
    size_t key_len = strlen(key);

    if (def_t->flags == iter->level && key_len < sizeof(iter->res))
    {
        char *res_buf = malloc(key_len + 1);
        if (res_buf!= NULL)
        {
            memcpy(res_buf, key, key_len);
            res_buf[key_len] = '\0';
            iter->res = res_buf;
        }
        else
        {
            return -1;
        }
    }

    return 0;
}