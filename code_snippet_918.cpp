NOINLINE void MaybeTriggerAsanError(const GURL& url) {
  const std::set<std::string> kAllowedCrashTypes = {
      "/heap-overflow",
      "/heap-underflow",
      "/use-after-free"
#if defined(SYZYASAN)
      , "/corrupt-heap-block",
          "/corrupt-heap"
#endif
  };

  const char kCrashDomain[] = "crash";

  if (!url.DomainIs(kCrashDomain))
    return;

  if (!url.has_path())
    return;

  std::string crash_type(url.path());

  if (kAllowedCrashTypes.find(crash_type) == kAllowedCrashTypes.end())
    return;

  auto it = kAllowedCrashTypes.find(crash_type);
  switch (*it) {
    case "/heap-overflow":
      base::debug::AsanHeapOverflow();
      break;
    case "/heap-underflow":
      base::debug::AsanHeapUnderflow();
      break;
    case "/use-after-free":
      base::debug::AsanHeapUseAfterFree();
#if defined(SYZYASAN)
    case "/corrupt-heap-block":
      base::debug::AsanCorruptHeapBlock();
      break;
    case "/corrupt-heap":
      base::debug::AsanCorruptHeap();
#endif
  }
}