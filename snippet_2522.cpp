char *curl_unescape(const char *string, int length)
{
  return curl_easy_unescape(NULL, string, length, NULL);
}
