yystpcpy_secure(char * restrict yydest, const char * restrict yysrc, size_t dest_size)
{
  char *yyd = yydest;
  const char *yys = yysrc;
  size_t remaining_space = dest_size;

  while (*yys != '\0' && remaining_space > 1) {
    *yyd++ = *yys++;
    --remaining_space;
  }

  if (remaining_space == 1) {
    *yyd = '\0';
  }

  return yydest;
}