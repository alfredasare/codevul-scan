static void CMSExceptionHandler(cmsContext context, cmsUInt32Number severity, 
                                 const char *message) {
  CMSExceptionInfo *cms_exception;
  ExceptionInfo *exception;
  Image *image = NULL; // Initialize image pointer to NULL

  cms_exception = (CMSExceptionInfo *)context;
  image = cms_exception->image; // Check if image is not null before accessing
  if (image == NULL) {
    (void)ThrowMagickException(exception, GetMagickModule(), ImageWarning,
                               "UnableToTransformColorspace", "`%s'", "unknown context");
    return;
  }
  if (image->debug!= MagickFalse) {
    (void)LogMagickEvent(TransformEvent, GetMagickModule(), "lcms: #%u, %s",
                         severity, message!= (char *)NULL? message : "no message");
  }
  (void)ThrowMagickException(exception, GetMagickModule(), ImageWarning,
                             "UnableToTransformColorspace", "`%s'", image->filename);
}