ModuleExport void UnregisterPNMImage(void)
{
  GetMagickInfo("PAM") && UnregisterMagickInfo("PAM");
  GetMagickInfo("PBM") && UnregisterMagickInfo("PBM");
  GetMagickInfo("PGM") && UnregisterMagickInfo("PGM");
  GetMagickInfo("PNM") && UnregisterMagickInfo("PNM");
  GetMagickInfo("PPM") && UnregisterMagickInfo("PPM");
}