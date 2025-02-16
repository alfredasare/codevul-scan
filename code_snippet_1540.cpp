static void TIFFWarnings(const char *module, const char *format, va_list warning)
{
  char message[MagickPathExtent];

  ExceptionInfo *exception;

#if defined(MAGICKCORE_HAVE_VSNPRINTF_S)
  vsnprintf_s(message, MagickPathExtent, _TRUNCATE, format, warning);
#else
  vsnprintf(message, MagickPathExtent, format, warning);
#endif

  message[MaxTextExtent - 2] = '\0';
  (void) ConcatenateMagickString(message, ".", MagickPathExtent);

  exception = (ExceptionInfo *) GetMagickThreadValue(tiff_exception);
  if (exception != (ExceptionInfo *) NULL)
    (void) ThrowMagickException(exception, GetMagickModule(), CoderWarning,
      message, "`%s'");
}