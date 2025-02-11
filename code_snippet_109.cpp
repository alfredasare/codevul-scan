std::pair<GURL, UrlData::CORSMode> UrlData::key() const {
  std::lock_guard<std::mutex> lock(thread_checker_mutex_);
  DCHECK(thread_checker_.IsValidThread());
  return std::make_pair(url(), cors_mode());
}