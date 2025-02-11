static MagickBooleanType IsJPEG(const unsigned char *magick, const size_t length)
{
  if (length < 3)
    return(MagickFalse);
  if (length >= 3 && memcmp(magick,"\377\330\377",3) == 0)
    return(MagickTrue);
  return(MagickFalse);
}