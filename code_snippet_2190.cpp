static MagickBooleanType IsITUFaxImage(const Image *image)
{
  const StringInfo *profile;
  const unsigned char *datum;

  profile = GetImageProfile(image, "8bim");
  if (profile == (const StringInfo *) NULL)
    return (MagickFalse);

  // Validate input profile string
  if (GetStringInfoLength(profile) > MAX_PROFILE_LENGTH || !isValidProfileChars(profile)) {
    return (MagickFalse);
  }

  datum = GetStringInfoDatum(profile);
  // Validate magic number using a regular expression or whitelist
  if (!isValidMagicNumber(datum)) {
    return (MagickFalse);
  }

  return (MagickTrue);
}

bool isValidProfileChars(const StringInfo *profile) {
  const char *str = GetStringInfoString(profile);
  for (int i = 0; i < GetStringInfoLength(profile); i++) {
    if (str[i] < 0x20 || str[i] > 0x7E) { // Only allow printable ASCII characters
      return false;
    }
  }
  return true;
}

bool isValidMagicNumber(const unsigned char *datum) {
  return memcmp(datum, "\x47\x33\x46\x41\x58", 5) == 0; // Compare magic number securely
}