void Plugin::UrlDidOpenForStreamAsFile(int32_t pp_error,
                                       FileDownloader*& url_downloader,
                                       PP_CompletionCallback callback) {
  PLUGIN_PRINTF(("Plugin::UrlDidOpen (pp_error=%"NACL_PRId32
                 ", url_downloader=%p)\n", pp_error,
                 static_cast<void*>(url_downloader)));

  if (pp_error!= PP_OK) {
    if (!PP_RunCompletionCallback(&callback, pp_error)) {
      LOG_ERROR("Error running completion callback");
    }
    return;
  }

  url_downloaders_.erase(url_downloader);
  nacl::scoped_ptr<FileDownloader> scoped_url_downloader(url_downloader);
  int32_t file_desc = scoped_url_downloader->GetPOSIXFileDescriptor();

  if (file_desc > NACL_NO_FILE_DESC) {
    url_fd_map_[url_downloader->url_to_open()] = file_desc;
    if (!PP_RunCompletionCallback(&callback, PP_OK)) {
      LOG_ERROR("Error running completion callback");
    }
  } else {
    if (!PP_RunCompletionCallback(&callback, PP_ERROR_FAILED)) {
      LOG_ERROR("Error running completion callback");
    }
  }
}