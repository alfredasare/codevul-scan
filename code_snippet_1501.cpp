static MagickBooleanType IsMPC(const unsigned char *magick, const size_t length)
{
  if (length < 14)
    return(MagickFalse);
  if (length >= 14 && LocaleNCompare((const char *) magick,"id=MagickCache",14) == 0)
    return(MagickTrue);
  return(MagickFalse);
}