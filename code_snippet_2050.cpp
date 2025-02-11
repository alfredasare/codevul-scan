static const char *cache_id(const char *id)
{
  static char clean[SHORT_STRING];
  if (strlen(id) >= sizeof(clean) - 1) {
    // Handle truncation or error
  }
  strncpy(clean, id, sizeof(clean) - 1);
  clean[sizeof(clean) - 1] = '\0';
  return clean;
}