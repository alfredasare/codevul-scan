void Performance::AddResourceTiming(const WebResourceTimingInfo& info,
                                   const AtomicString& initiator_type) {
  try {
    if (IsResourceTimingBufferFull() &&
      !HasObserverFor(PerformanceEntry::kResource)) {
      return;
    }

    PerformanceEntry* entry =
        PerformanceResourceTiming::Create(info, time_origin_, initiator_type);
    NotifyObserversOfEntry(*entry);
    if (!IsResourceTimingBufferFull()) {
      AddResourceTimingBuffer(*entry);
    }
  } catch (const std::exception& e) {
    LOG(ERROR) << "Error adding resource timing";
  }
}