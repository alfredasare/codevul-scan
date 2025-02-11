static bool is_good_origin(const char *origin, const char *require)
{
    size_t origin_len  = strnlen(origin, SIZE_MAX);
    size_t require_len = strnlen(require, SIZE_MAX);
    if (origin_len < require_len)
        return false;
    if (strncmp(origin + (origin_len - require_len), require, require_len)!= 0)
        return false;
    return true;
}