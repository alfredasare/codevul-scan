enum class SafeMode {
  kMode1,
  kMode2,
  kMode3,
  // Add more safe modes as needed
};

void ProfilingProcessHost::SetMode(Mode mode) {
  if (const SafeMode safe_mode = static_cast<SafeMode>(mode);
      safe_mode >= SafeMode::kMode1 && safe_mode <= SafeMode::kMode3) {
    mode_ = safe_mode;
  } else {
    // Log an error or throw an exception to indicate invalid input
  }
}