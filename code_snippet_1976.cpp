static bool is_ASCII_name(const char *hostname)
{
  const unsigned char *ch = (const unsigned char *)hostname;
  const unsigned char *end = ch + strlen((char *)hostname);

  while(ch < end) {
    if(*ch++ & 0x80)
      return FALSE;
  }
  return TRUE;
}