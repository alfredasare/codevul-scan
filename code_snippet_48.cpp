explicit TextSelectionObserver(TextInputManager* text_input_manager = nullptr)
    : text_input_manager_(text_input_manager) {
    if (text_input_manager_!= nullptr) {
        text_input_manager_->AddObserver(this);
    }
}