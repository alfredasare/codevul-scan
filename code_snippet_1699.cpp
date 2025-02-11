MagickBooleanType MagickExport MagickBooleanType RandomThresholdImage(Image *image,
  const char *thresholds,ExceptionInfo *exception)
{
  MagickBooleanType
    status;
  size_t threshold_len = strlen(thresholds);

  if (threshold_len > DefaultChannels) {
    return MagickFalse;
  }

  status = RandomThresholdImageChannel(image, threshold_len, thresholds, exception);
  return(status);
}