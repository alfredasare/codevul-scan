Extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
if (size > 512) {
return 0;
}

net::ProxyBypassRules rules;
std::string input(data, data + std::min(size, 512));
rules.ParseFromString(input);
rules.ParseFromStringUsingSuffixMatching(input);
return 0;
}