static wchar_t *ConvertUTF8ToUTF16(const unsigned char *source, size_t source_length, size_t *length)
{
  wchar_t *utf16 = NULL;

  *length = UTF8ToUTF16((const char *)source, source_length, (wchar_t *)NULL);
  if (*length == 0)
  {
    *length = source_length;
    utf16 = (wchar_t *)AcquireQuantumMemory(*length + 1, sizeof(*utf16));
    if (utf1