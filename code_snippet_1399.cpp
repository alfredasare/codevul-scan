static void TIFFWarnings(const char *module, const char *format, va_list warning) {
  char
    message[MagickPathExtent];

  ExceptionInfo
    *exception;

  // Use snprintf instead of vsnprintf/vsprintf
  (void) snprintf(message, sizeof(message) - 1, format, warning);
  message[MaxTextExtent - 2] = '\0';

  // Validate and sanitize the format string
  if (strchr(format, '%')!= NULL) {
    // Sanitize the format string by removing any potentially malicious characters
    char sanitized_format[MagickPathExtent];
    strcpy(sanitized_format, format);
    sanitized_format[strcspn(sanitized_format, "%cspduoxX") - sanitized_format] = '\0';
    format = sanitized_format;
  }

  //... (rest of the function remains the same)
}