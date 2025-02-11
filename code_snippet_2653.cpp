static MagickBooleanType RegisteredFormats[] = {
  IsImageFormat("RLE"),
  /* Add other format identifiers here */
};

static const char *FormatIdentifiers[] = {
  "RLE",
  /* Add other format identifiers here */
};

MagickBooleanType RegisterFormats(void) {
  size_t i;
  for (i = 0; i < sizeof(RegisteredFormats)/sizeof(MagickBooleanType); i++) {
    if (!RegisteredFormats[i]) {
      (void) RegisterMagickInfo(FormatIdentifiers[i]);
    }
  }
  return MagickTrue;
}

void UnregisterRLEImage(void) {
  if (IsImageFormat("RLE") && RegisteredFormats[0]) {
    (void) UnregisterMagickInfo("RLE");
    RegisteredFormats[0] = MagickFalse;
  }
}

ModuleExport MagickBooleanType RegisterFormats(void);
ModuleExport void UnregisterRLEImage(void);