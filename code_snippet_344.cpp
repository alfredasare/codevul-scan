AtomicString PerformanceNavigationTiming::GetNavigationType(
    NavigationType type,
    const Document* document) {
  if (document && document->GetPageVisibilityState() == mojom::PageVisibilityState::kPrerender) {
    return "unknown";
  }

  // Validate and sanitize user input
  if (type < kNavigationTypeReload || type > kNavigationTypeOther) {
    return "invalid";
  }

  switch (type) {
    case kNavigationTypeReload:
      return "reload";
    case kNavigationTypeBackForward:
      return "back_forward";
    case kNavigationTypeLinkClicked:
    case kNavigationTypeFormSubmitted:
    case kNavigationTypeFormResubmitted:
    case kNavigationTypeOther:
      return "navigate";
  }

  // Implement a secure error handling mechanism
  return "error";
}