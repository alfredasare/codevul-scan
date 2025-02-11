AudioSourceProviderClientLockScope(HTMLMediaElement& element)
: m\_client(checkNullptr(element.audioSourceNode())) {
if (m\_client)
m\_client->lock();
}

checkNullptr(HTMLMediaElementNode* node) {
if (node == nullptr) {
logError("Null pointer returned from audioSourceNode()");
throw std::runtime_error("Null pointer returned from audioSourceNode()");
}
return node;
}