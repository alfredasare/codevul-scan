static MagickBooleanType IsIPL(const unsigned char *magick, size_t length)
{
  if (length < 4) {
    return MagickFalse;
  }

  if (length < 4 + 4) {
    return MagickFalse;
  }

  // Validate the input data
  if (LocaleNCompare((const char *) magick, "data", 4) != 0) {
    return MagickFalse;
  }

  return MagickTrue;
}