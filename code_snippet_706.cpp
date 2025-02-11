void BubbleManager::UpdateAllBubbleAnchors() {
  DCHECK(thread_checker_.CalledOnValidThread());
  DCHECK_NE(manager_state_, ITERATING_BUBBLES);

  ManagerState original_state = manager_state_;
  manager_state_ = ITERATING_BUBBLES;

  std::vector<std::unique_ptr<BubbleControllerInterface>> controllers_copy;
  controllers_copy.reserve(controllers_.size());
  for (const auto& controller : controllers_) {
    controllers_copy.emplace_back(controller->Clone());
  }

  for (auto& controller : controllers_copy) {
    controller->UpdateAnchorPosition();
  }

  controllers_.swap(controllers_copy);
  manager_state_ = original_state;
}