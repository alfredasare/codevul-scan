void ProfilingProcessHost::SetMode(Mode mode) {
  if (!IsValidMode(mode)) { // validate and sanitize input
    throw std::invalid_argument("Invalid mode");
  }

  mode_.reset(new Mode(mode)); // use smart pointer for memory management
}