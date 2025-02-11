#define MAX_LEN 256 // Define the maximum allowed length for the input string

stringprep_utf8_nfkc_normalize (const char *str, ssize_t len)
{
  if (len > MAX_LEN) {
    return -1;
  }

  gchar *normalized_str = g_utf8_normalize_string(str, len, G_NORMALIZE_NFKC);

  // Process the normalized string and remember to free the memory
  // ...

  g_free(normalized_str);

  return 0; // Return a success code
}