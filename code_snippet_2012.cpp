MagickExport size_t GetMagickVersion(char buffer[], size_t bufferSize, size_t *version)
{
  size_t length = strlen(MagickVersion);

  if (version != NULL)
    *version = MagickLibVersion;

  if (length + 1 > bufferSize) // +1 for null terminator
    return 0;

  strncpy(buffer, MagickVersion, bufferSize);
  buffer[bufferSize - 1] = '\0'; // Ensure null termination
  return length;
}