code:


static wchar_t *ConvertUTF8ToUTF16(const unsigned char *source, size_t *length)
{
    wchar_t *utf16;

    *length = UTF8ToUTF16(source, NULL);
    if (*length == 0)
    {
        size_t len;
        len = wcslen((wchar_t *)source);
        if (len == 0)
        {
            *length = strlen((const char *)source);
            utf16 = (wchar_t *)malloc((*length + 1) * sizeof(*utf16));
            if (utf16 == NULL)
                return NULL;
            for (size_t i = 0; i < len; i++)
                utf16[i] = source[i];
            utf16[len] = L'\0';
            return utf16;
        }
    }
    utf16 = (wchar_t *)malloc((*length + 1) * sizeof(*utf16));
    if (utf16 == NULL)
        return NULL;
    *length = UTF8ToUTF16(source, utf16);
    return utf16;
}