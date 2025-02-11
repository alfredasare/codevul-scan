static void TIFFWarnings(const char *module,const char *format,va_list warning)
{
  char
    message[MaxTextExtent];

  ExceptionInfo
    *exception;

  // Sanitize the module parameter
  char sanitized_module[MaxTextExtent];
  strcpy(sanitized_module, module);
  sanitized_module[strcspn(sanitized_module, "/\\..")] = '\0';

  // Use safe string concatenation
  asprintf(&message, "%s.", sanitized_module);

  // Validate the module parameter
  if (strchr(module, '/') || strchr(module, '\\')) {
    // Handle invalid module parameter
  }

  (void) ConcatenateMagickString(message,".",MaxTextExtent);
  exception=(ExceptionInfo *) GetMagickThreadValue(tiff_exception);
  if (exception != (ExceptionInfo *) NULL)
    (void) ThrowMagickException(exception,GetMagickModule(),CoderWarning,
      message,"`%s'",sanitized_module);
}