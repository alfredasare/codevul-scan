formtype(const char *typestr, size_t n)
{
    int i;
    for (i = 0; i < n && _formtypetbl[i]; i++) {
        if (!strncasecmp(typestr, _formtypetbl[i], n))
            return i;
    }
    return FORM_INPUT_TEXT;
}