base::ThreadLocalStorage::Slot& SafePatternTLS() {
  base::NoDestructor<base::ThreadLocalStorage::Slot> safe_pattern_tls(&OnThreadTermination);
  return *safe_pattern_tls.Get();
}