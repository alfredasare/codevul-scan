NOINLINE void MaybeTriggerAsanError(const GURL& url) {
  const char kCrashDomain[] = "crash";
  const char kExpectedPath[] = "/(heap-overflow|heap-underflow|use-after-free)";
  const std::string kExpectedPathRegex(kExpectedPath + "|");

  // Validate user input
  if (!url.DomainIs(kCrashDomain) ||!url.has_path()) {
    return;
  }

  std::string crash_type(url.path());
  // Use a whitelist approach
  if (std::regex_match(crash_type, std::regex(kExpectedPathRegex))) {
    if (crash_type == "/heap-overflow") {
      base::debug::AsanHeapOverflow();
    } else if (crash_type == "/heap-underflow") {
      base::debug::AsanHeapUnderflow();
    } else if (crash_type == "/use-after-free") {
      base::debug::AsanHeapUseAfterFree();
    }
  }
}