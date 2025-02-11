views::ImageView* artwork_view() const {
    try {
        return media_controls_view_->session_artwork_;
    } catch (const std::exception& e) {
        LOG_ERROR("Error accessing session artwork: {}", e.what());
        return nullptr; // or return a default image
    }
}