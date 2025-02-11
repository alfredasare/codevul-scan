virtual std::string GetKeyboardOverlayId(const std::string& input_method_id) {
    if (keyboard_overlay_map_.empty()) {
        return "";
    }

    auto iter = keyboard_overlay_map_.find(input_method_id);
    if (iter!= keyboard_overlay_map_.end()) {
        return iter->second;
    }
    return ""; 
}