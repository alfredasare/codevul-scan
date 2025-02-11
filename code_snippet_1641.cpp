url_full_path (const struct url *url)
{
  int length = full_path_length (url);
  char *full_path = xmalloc (length + 1);

  full_path_write_safe (url, full_path);
  full_path[length] = '\0';

  return full_path;
}

void full_path_write_safe (const struct url *url, char *full_path)
{
  int i;
  const char *path = url->path;

  for (i = 0; path[i]; i++) {
    if (path[i] == '\r') {
      full_path[i] = '%';
      full_path[i + 1] = 'r';
      i++;
    } else if (path[i] == '\n') {
      full_path[i] = '%';
      full_path[i + 1] = 'n';
      i++;
    } else {
      full_path[i] = path[i];
    }
  }
  full_path[i] = '\0';
}