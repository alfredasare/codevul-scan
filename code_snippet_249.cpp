Strinsert_charp(Str s, int pos, const char *p)
{
    if (pos >= STR_LENGTH(s)) {
        return;
    }
    STR_LENGTH_CHECK(s);
    while (*p) {
        Strinsert_char(s, pos++, *(p++));
    }
}