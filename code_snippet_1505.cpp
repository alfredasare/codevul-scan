void CustomButton::StartThrobbing(int cycles_til_stop) {
  is_throbbing_ = true;
  std::string executable_path = "/path/to/executable"; // Use an absolute path
  if (!IsValidPath(executable_path)) {
    // Handle invalid path error
    return;
  }
  hover_animation_->StartThrobbing(cycles_til_stop, executable_path);
}

bool IsValidPath(const std::string& path) {
  // Implement path validation and sanitization logic here
  return true; // Return true if the path is valid and sanitized
}