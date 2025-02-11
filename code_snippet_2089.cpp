size_t local_wcsnlen(const wchar_t *s, size_t maxlen)
{
  const wchar_t *ptr = s;
  while (*ptr != L'\0' && maxlen-- > 0) {
    ptr++;
  }
  return ptr - s;
}