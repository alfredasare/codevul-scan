WebURLResponseExtraDataImpl* GetExtraDataFromResponse(const WebURLResponse& response) {
  WebURLResponseExtraDataImpl* extraDataImpl = dynamic_cast<WebURLResponseExtraDataImpl*>(response.extraData());
  if (extraDataImpl == nullptr) {
    return nullptr;
  }
  return extraDataImpl;
}