static void RemapIndices(const ssize_t *map, const unsigned char *source,
                          unsigned char *target)
{
  register ssize_t
    i;

  for (i = 0; i < 16; i++)
  {
    if (map[i] == -1)
      target[i] = 3;
    else if (map[i] >= 0 && map[i] < 16)
      target[i] = source[map[i]];
    else
      target[i] = 0; // Assign a default value for the error case
  }
}