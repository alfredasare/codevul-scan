c++
explicit TextSelectionObserver(TextInputManager* text_input_manager)
  : text_input_manager_(text_input_manager) {
    if (text_input_manager_ && !text_input_manager_->HasObserver(this)) {
      text_input_manager_->AddObserver(this);
    }
  }

virtual ~TextSelectionObserver() {
  if (text_input_manager_) {
    text_input_manager_->RemoveObserver(this);
  }
}