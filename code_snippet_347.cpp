AtomicString PerformanceNavigationTiming::GetNavigationType(
NavigationType type,
const Document* document) {
if (document && std::find(valid_navigation_types.begin(), valid_navigation_types.end(), type) != valid_navigation_types.end()) {
if (document->GetPageVisibilityState() == mojom::PageVisibilityState::kPrerender) {
return "prerender";
}
switch (type) {
case kNavigationTypeReload:
return "reload";
case kNavigationTypeBackForward:
return "back\_forward";
case kNavigationTypeLinkClicked:
return "navigate";
case kNavigationTypeFormSubmitted:
return "navigate";
case kNavigationTypeFormResubmitted:
return "navigate";
case kNavigationTypeOther:
return "navigate";
}
}
NOTREACHED();
return "navigate";
}

std::initializer_list<NavigationType> valid_navigation_types = {
kNavigationTypeReload,
kNavigationTypeBackForward,
kNavigationTypeLinkClicked,
kNavigationTypeFormSubmitted,
kNavigationTypeFormResubmitted,
kNavigationTypeOther
};