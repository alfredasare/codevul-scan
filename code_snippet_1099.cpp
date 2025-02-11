ModuleExport void UnregisterINLINEImage(void)
{
  UnregisterMagickInfo("INLINE"); // Get before free
  (void) UnregisterMagickInfo("INLINE"); // Free
  UnregisterMagickInfo("DATA"); // Get before free
  (void) UnregisterMagickInfo("DATA"); // Free
}