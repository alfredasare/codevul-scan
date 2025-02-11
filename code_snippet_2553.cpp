++
GetAlternativeWebContentsToNotifyForDownload() {
#if defined(OS_ANDROID)
  return NULL;
#else