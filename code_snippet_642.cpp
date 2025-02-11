bool WebLocalFrameImpl::IsProvisional() const {
    try {
        return frame_->IsProvisional();
    } catch (const std::exception& e) {
        LOG_ERROR("Error in IsProvisional(): ");
        return false;
    }
}