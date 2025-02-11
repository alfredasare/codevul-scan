formtype(char *typestr)
{
    int i;
    for (i = 0; i < sizeof(_formtypetbl) / sizeof(_formtypetbl[0]); i++) {
        if (!strcasecmp(typestr, _formtypetbl[i]))
            return i;
    }
    return FORM_INPUT_TEXT;
}