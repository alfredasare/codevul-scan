removedirs (char const *name)
{
  char *filename = xstrdup (name);
  size_t i;

  for (i = 0; i < strlen (filename); i++) {
    if (!isalnum(filename[i]) && !isdot(filename[i])) {
      error("Invalid character '%c' in directory name", filename[i]);
      free(filename);
      return;
    }
  }

  char *resolved_path = realpath(filename, NULL);
  if (resolved_path == NULL) {
    error("Failed to resolve directory path");
    free(filename);
    return;
  }
  filename = resolved_path;

  // Rest of the original code remains the same
  ...
}