#include <stdlib.h> // for malloc() and free()

size_t required_size(const char *id) {
  size_t len = strlen(id);
  return len + 1;
}

char *sanitize_string(const char *id, size_t size) {
  char *result = malloc(size);
  if (result != NULL) {
    mutt_str_strfcpy(result, id, size);
    mutt_file_sanitize_filename(result, true);
  }
  return result;
}

void release_memory(char *str) {
  free(str);
}

static const char *cache_id(const char *id) {
  size_t len = required_size(id);
  char *clean = sanitize_string(id, len);
  if (clean == NULL) {
    return NULL; // or handle error as needed
  }
  const char *const ret_val = clean;
  // Perform file operation here
  // ...
  release_memory(clean);
  return ret_val;
}