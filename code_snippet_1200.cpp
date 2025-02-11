void Plugin::UrlDidOpenForStreamAsFile(int32_t pp_error,
                                       FileDownloader*& url_downloader,
                                       PP_CompletionCallback callback) {
  constexpr size_t kMaxUrlLength = 4096; // Adjust this value based on your requirements
  std::string truncated_url = url_downloader->url_to_open();
  truncated_url.resize(ValidateAndTruncateUrl(&truncated_url, kMaxUrlLength));
  url_fd_map_[truncated_url] = file_desc;

  PLUGIN_PRINTF(("Plugin::UrlDidOpen (pp_error=%"NACL_PRId32
                 ", url_downloader=%p)\n", pp_error,
                 static_cast<void*>(url_downloader)));
  url_downloaders_.erase(url_downloader);
  nacl::scoped_ptr<FileDownloader> scoped_url_downloader(url_downloader);
  int32_t file_desc = scoped_url_downloader->GetPOSIXFileDescriptor();

  if (pp_error != PP_OK) {
    PP_RunCompletionCallback(&callback, pp_error);
  } else if (file_desc > NACL_NO_FILE_DESC) {
    url_fd_map_[truncated_url] = file_desc;
    PP_RunCompletionCallback(&callback, PP_OK);
  } else {
    PP_RunCompletionCallback(&callback, PP_ERROR_FAILED);
  }
}

size_t ValidateAndTruncateUrl(std::string* url, size_t max_length) {
  if (url->length() > max_length) {
    url->resize(max_length);
  }
  return url->length();
}