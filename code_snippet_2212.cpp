const char *c_strnstr(const char *s, const char *find, size_t slen) {
  size_t find_length = strlen(find);
  size_t i;

  if (slen < find_length) {
    return NULL;
  }

  for (i = 0; i <= slen - find_length; i++) {
    if (strncmp(&s[i], find, find_length) == 0) {
      return &s[i];
    }
  }

  return NULL;
}