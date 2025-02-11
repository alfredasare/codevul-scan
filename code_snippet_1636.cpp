void WebURLLoaderImpl::Context::HandleDataURL() {
  ResourceResponseInfo info;
  int error_code;
  std::string data;

  if (GetInfoFromDataURL(request_.url(), &info, &data, &error_code)) {
    OnReceivedResponse(info);
    if (!data.empty()) {
      std::string received_data = data;  // Make a copy of the data
      OnReceivedData(received_data.data(), received_data.size(), 0);
    }
  }

  OnCompletedRequest(error_code, false, info.security_info, base::TimeTicks::Now());
}