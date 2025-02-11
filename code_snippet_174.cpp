++
WebURLResponseExtraDataImpl* GetExtraDataFromResponse(const WebURLResponse& response) {
    WebURLResponse copyResponse = response; 
    return static_cast<WebURLResponseExtraDataImpl*>(copyResponse.extraData());
}