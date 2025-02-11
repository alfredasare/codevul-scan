int lh_char_equal(const void *k1, const void *k2)
{
    size_t length = strlen((const char*)k1);
    if (length != strlen((const char*)k2)) {
        return 0;
    }
    return !memcmp(k1, k2, length + 1);
}