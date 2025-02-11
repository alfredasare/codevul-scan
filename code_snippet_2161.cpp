static MagickBooleanType IsJPEG(const unsigned char *magick, size_t length)
{
  if (length < 1 || length > SIZE_MAX) 
    return(MagickFalse);

  if (length < 3)
    return(MagickFalse);
  if (length > SIZE_MAX - 3)
    return(MagickFalse);
  if (memcmp(magick, "\377\330\377", 3) == 0)
    return(MagickTrue);
  return(MagickFalse);
}