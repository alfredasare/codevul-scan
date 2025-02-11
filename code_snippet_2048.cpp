void UrlFetcherDownloader::DoStartDownload(const GURL& url) {
  DCHECK_CALLED_ON_VALID_THREAD(thread_checker_);
  // Validate the URL
  if (!IsValidUrl(url)) {
    LOG(ERROR) << "Invalid URL: " << url;
    return;
  }
  base::PostTaskAndReply(
      FROM_HERE, kTaskTraits,
      base::BindOnce(&UrlFetcherDownloader::CreateDownloadDir,
                     base::Unretained(this)),
      base::BindOnce(&UrlFetcherDownloader::StartURLFetch,
                     base::Unretained(this), url));
}

bool IsValidUrl(const GURL& url) {
  // Use a URL validation library or a regular expression to validate the URL format
  // For simplicity, we'll use a basic check for valid URL schemes
  std::string scheme = url.scheme();
  if (scheme.empty() ||!std::all_of(scheme.begin(), scheme.end(), ::isalnum)) {
    return false;
  }
  return true;
}