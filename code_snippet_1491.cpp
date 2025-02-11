bool TraceEventTestFixture::FindNonMatchingValue(const char* key,
                                             const char* value) {
  JsonKeyValue key_values[] = {
    {std::getenv("KEY"), std::getenv("VALUE"), IS_NOT_EQUAL},
    {0, 0, IS_EQUAL}
  };
  return FindMatchingTraceEntry(key_values);
}