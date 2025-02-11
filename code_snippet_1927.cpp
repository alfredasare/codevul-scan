bool DocumentLoader::IsCreatingInitialEmptyDocument() {
  return GetFrameLoader().StateMachine()->CreatingInitialEmptyDocument();
}

void DocumentLoader::ProbeWillCommitLoad(frame_) {
  probe::willCommitLoad(frame_, this);
}

void FrameIdlenessDetector::WillCommitLoad(frame_) {
  frame_->GetIdlenessDetector()->WillCommitLoad();
}

void DocumentLoader::WillCommitNavigation() {
  if (IsCreatingInitialEmptyDocument()) {
    return;
  }
  ProbeWillCommitLoad(frame_);
  FrameIdlenessDetector::WillCommitLoad(frame_);
}