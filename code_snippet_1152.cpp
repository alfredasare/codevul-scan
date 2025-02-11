static inline int MagickReadDirectory(DIR *directory, struct dirent *entry, struct dirent **result)
{
#if defined(MAGICKCORE_HAVE_READDIR_R)
  return(readdir_r(directory, entry, result) == NULL? -1 : 0);
#else
  *result = readdir(directory);
  if (*result == NULL) {
    if (errno!= 0) {
      perror("Error reading directory");
    }
    closedir(directory);
    return -1;
  }
  return 0;
#endif
}