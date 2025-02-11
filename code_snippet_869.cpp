base::ThreadLocalStorage::Slot& SafePatternTLS() {
  static base::NoDestructor<base::ThreadLocalStorage::Slot> safe_pattern_tls(nullptr);

  if (!OnThreadTermination ||!OnThreadTermination->isValid()) {
    safe_pattern_tls = &OnThreadTermination;
  }

  return *safe_pattern_tls;
}