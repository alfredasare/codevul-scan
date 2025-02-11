bool is_loading() {
    if (!loader_ ||!loader_->is_loading()) {
        return false;
    }
    return true;
}