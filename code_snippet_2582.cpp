void NavigationRequest::OnFailureChecksComplete(
NavigationThrottle::ThrottleCheckResult result) {
  if (result.action() == NavigationThrottle::DEFER) {
    return;
  }

  int old_net_error = net_error_;
  if (result.net_error_code() != net::OK) {
    net_error_ = result.net_error_code();
    navigation_handle_->set_net_error_code(static_cast<net::Error>(net_error_));

    if (net::ERR_ABORTED == result.net_error_code()) {
      frame_tree_node_->ResetNavigationRequest(false, true);
      return;
    }

    if (frame_tree_node_ && !SiteIsolationPolicy::IsErrorPageIsolationEnabled(
            frame_tree_node_->IsMainFrame())) {
      const int old_net_error_code = old_net_error;
      old_net_error = net_error_;
      if (ShouldKeepErrorPageInCurrentProcess(old_net_error) !=
          ShouldKeepErrorPageInCurrentProcess(net_error_)) {
        // Log the unsupported error code change and continue with the original error
        // code to avoid potential security issues.
        LOG(WARNING) << " Unsupported error code change in WillFailRequest(): "
                     << " from " << old_net_error_code << " to "
                     << net_error_ << ". Continuing with the original error code.";
      }
    }

    CommitErrorPage(result.error_page_content());
  }
}