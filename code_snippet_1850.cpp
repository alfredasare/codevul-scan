MagickBooleanType RandomThresholdImage(Image *image, const char *thresholds, size_t thresholds_len, ExceptionInfo *exception)
{
  MagickBooleanType
    status;

  // Limit the length of the thresholds input to prevent buffer overflow.
  if (thresholds_len > MAX_THRESHOLDS_LENGTH) {
    // Handle error, e.g., return an error code or throw an exception.
    return MagickFalse;
  }

  status = RandomThresholdImageChannel(image, DefaultChannels, thresholds, exception);
  return (status);
}