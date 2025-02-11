static MagickBooleanType IsIPL(const unsigned char *magick, const size_t length)
{
  if (length < 4)
    return(MagickFalse);
  if (memcmp(magick, "data", 4) == 0)
    return(MagickTrue);
  return(MagickFalse);
}