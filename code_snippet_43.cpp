void Performance::AddResourceTiming(const WebResourceTimingInfo& info,
                                const AtomicString& initiator\_type) {
if (IsResourceTimingBufferFull() &&
!HasObserverFor(PerformanceEntry::kResource))
return;

// Validate and sanitize initiator\_type
if (!initiator\_type.IsEmpty() && initiator\_type != "script" && initiator\_type != "link") {
initiator\_type = "other";
}

PerformanceEntry* entry =
PerformanceResourceTiming::Create(info, time\_origin_, initiator\_type);
NotifyObserversOfEntry(*entry);
if (!IsResourceTimingBufferFull())
AddResourceTimingBuffer(*entry);
}