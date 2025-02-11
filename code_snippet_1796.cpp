void WebURLLoaderImpl::Context::HandleDataURL() {
ResourceResponseInfo info{};
std::string data{};
int error\_code{};

if (GetInfoFromDataURL(request\_.url(), &info, &data, &error\_code)) {
OnReceivedResponse(info);
if (!data.empty())
OnReceivedData(data.data(), data.size(), 0);
}

ResourceResponseInfo info\_copy{info};
std::string data\_copy{data};
OnCompletedRequest(error\_code, false, info\_copy, base::TimeTicks::Now());
}