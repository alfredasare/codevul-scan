void DocumentLoader::WillCommitNavigation() {
  std::scoped_lock<std::mutex> lock(will_commit_navigation_mutex_);
  if (GetFrameLoader().StateMachine()->CreatingInitialEmptyDocument())
    return;
  probe::willCommitLoad(frame_, this);
  frame_->GetIdlenessDetector()->WillCommitLoad();
}