extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
  if (size > 512) {
    return 1;
  }

  std::string input;
  if (size <= 512) {
    input.assign((char*)data, size);
  } else {
    // Handle oversized input
    return 1;
  }

  net::ProxyBypassRules rules;
  rules.ParseFromString(input);
  rules.ParseFromStringUsingSuffixMatching(input);
  return 0;
}