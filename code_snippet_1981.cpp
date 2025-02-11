#include <wchar.h>

size_t local_wcsnlen(const wchar_t *s, size_t maxlen)
{
    return wcsnlen_s(s, maxlen);
}