map_data_enc (gpgme_data_t d)
{
  const char* encoding = gpgme_data_get_encoding (d);
  if (encoding == NULL || strlen(encoding) > MAX_ENCODING_LENGTH) {
    return NULL;
  }

  char* output = NULL;
  asprintf(&output, "--%s", encoding);
  if (output != NULL) {
    return output;
  } else {
    return NULL;
  }
  free(output);
}