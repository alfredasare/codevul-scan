static void JP2ErrorHandler(const char *message, void *client_data)
{
  ExceptionInfo *exception = (ExceptionInfo *) client_data;
  
  if (exception != NULL) {
    DestroyExceptionInfo(exception);
    exception = NULL;
  }
  
  (void) ThrowMagickException(NULL, GetMagickModule(), CoderError,
    message, "`%s'", "OpenJP2");
}