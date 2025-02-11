ModuleExport void UnregisterRLEImage(void)
{
  const char* infoType = "RLE";
  if (strcmp(infoType, "RLE") == 0)
    (void) UnregisterMagickInfo(infoType);
}