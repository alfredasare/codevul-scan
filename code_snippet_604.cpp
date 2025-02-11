const char* DownloadItemImpl::DebugDownloadStateString(DownloadInternalState state) {
  if (state < INITIAL_INTERNAL || state > MAX_DOWNLOAD_INTERNAL_STATE) {
    return "unknown";
  }

  switch (state) {
    case INITIAL_INTERNAL:
      return "INITIAL";
    case TARGET_PENDING_INTERNAL:
      return "TARGET_PENDING";
    case INTERRUPTED_TARGET_PENDING_INTERNAL:
      return "INTERRUPTED_TARGET_PENDING";
    case TARGET_RESOLVED_INTERNAL:
      return "TARGET_RESOLVED";
    case IN_PROGRESS_INTERNAL:
      return "IN_PROGRESS";
    case COMPLETING_INTERNAL:
      return "COMPLETING";
    case COMPLETE_INTERNAL:
      return "COMPLETE";
    case CANCELLED_INTERNAL:
      return "CANCELLED";
    case INTERRUPTED_INTERNAL:
      return "INTERRUPTED";
    case RESUMING_INTERNAL:
      return "RESUMING";
    case MAX_DOWNLOAD_INTERNAL_STATE:
      break;
  }
  return "unknown";
}