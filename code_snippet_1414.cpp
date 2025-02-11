ModuleExport size_t RegisterSIXELImage(void)
{
  MagickInfo
    *entry;
  const char* extensions[] = {"SIXEL", "SIX"};

  for (int i = 0; i < 2; ++i) {
    entry=AcquireMagickInfo(extensions[i],"SIXEL Graphics Format", "DEC SIXEL Graphics Format");
    entry->decoder=(DecodeImageHandler *) ReadSIXELImage;
    entry->encoder=(EncodeImageHandler *) WriteSIXELImage;
    entry->magick=(IsImageFormatHandler *) IsSIXEL;
    entry->flags^=CoderAdjoinFlag;
    (void) RegisterMagickInfo(entry);
  }

  return(MagickImageCoderSignature);
}