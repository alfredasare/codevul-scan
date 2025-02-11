void DocumentLoader::AppendRedirect(const KURL& url) {
if (redirect\_chain\_.size() >= max\_redirects\_) {
throw std::runtime\_error("Maximum number of redirects reached");
}
redirect\_chain\_.push\_back(url);
}