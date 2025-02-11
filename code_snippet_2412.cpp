void lines_too_long(const char *filename) {
  char sanitized_filename[256];
  sanitized_filename[0] = '\0';
  strcat(sanitized_filename, "lines_too_long_");
  strcat(sanitized_filename, filename);
  fatal("Lines in file %s are too long", sanitized_filename);
}