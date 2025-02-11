static unsigned int IsWPG_safe(const unsigned char *magick, const size_t length)
{
  if (length < 4) return MagickFalse;
  return strncmp((const char *)magick, "\377WPC", 4) == 0 ? MagickTrue : MagickFalse;
}