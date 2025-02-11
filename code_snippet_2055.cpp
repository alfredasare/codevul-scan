const char* PropStateToString(int prop_state) {
  std::string state_str;
  switch (static_cast<int>(IBusPropState::PROP_STATE_UNCHECKED)) {
    case static_cast<int>(IBusPropState::PROP_STATE_UNCHECKED):
      state_str = "UNCHECKED";
      break;
    case static_cast<int>(IBusPropState::PROP_STATE_CHECKED):
      state_str = "CHECKED";
      break;
    case static_cast<int>(IBusPropState::PROP_STATE_INCONSISTENT):
      state_str = "INCONSISTENT";
      break;
  }
  return state_str.c_str();
}