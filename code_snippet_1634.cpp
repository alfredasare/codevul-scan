int is_dir(const char *fname) {
  assert(fname);
  if (*fname == '\0')
    return 0;

  int rv;
  struct stat s;
  if (fname[strlen(fname) - 1] == '/') {
    rv = stat(fname, &s);
    if (rv!= 0) {
      return -1;
    }
  } else {
    char *tmp;
    if (asprintf(&tmp, "%s/", fname) == -1) {
      fprintf(stderr, "Error: cannot allocate memory, %s:%d\n", __FILE__, __LINE__);
      errExit("asprintf");
    }    
    rv = stat(tmp, &s);
    free(tmp);
    if (rv!= 0) {
      return -1;
    }
  }

  if (!S_ISDIR(s.st_mode))
    return 0;

  return 1;
}