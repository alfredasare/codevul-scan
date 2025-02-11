static MagickBooleanType IsMPC(const unsigned char *magick, size_t length)
{
  if (length > 1024) { // arbitrary limit, adjust according to your requirements
    return MagickFalse; // or throw an exception, depending on your error handling strategy
  }
  if (strlen((const char *) magick)!= 14 || LocaleNCompare((const char *) magick, "id=MagickCache", 14)!= 0) {
    return MagickFalse;
  }
  return MagickTrue;
}