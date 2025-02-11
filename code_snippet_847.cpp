mojom::NavigationClient* NavigationRequest::GetCommitNavigationClient() {
  if (commit_navigation_client_) {
    commit_navigation_client_->set_disconnect_handler(base::BindOnce(
        &NavigationRequest::OnCommitNavigationClientDisconnected,
        weak_factory_.GetWeakPtr()));
    return commit_navigation_client_.get();
  }
  return nullptr;
}