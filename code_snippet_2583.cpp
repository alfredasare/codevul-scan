void lines_too_long(const char *filename) {
  char message[1024];
  snprintf(message, sizeof(message), "Lines in file %s are too long", filename);
  fatal(message);
}