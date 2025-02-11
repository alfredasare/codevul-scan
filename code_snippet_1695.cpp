void NotifyUpdatedActions() {
    try {
        media_controls_view_->MediaSessionActionsChanged(std::vector<MediaSessionAction>(actions_.begin(), actions_.end()));
    } catch (const std::exception& e) {
        LOG_ERROR("Error processing MediaSessionActions: {}", e.what());
    }
}