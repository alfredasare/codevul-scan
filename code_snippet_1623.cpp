int yr_arena_write_string(
    YR_ARENA* arena,
    const char* string,
    char** written_string)
{
  if (!written_string || *written_string) {
    return -1;
  }

  return yr_arena_write_data(
      arena,
      (void*) string,
      strlen(string) + 1,
      &written_string);
}