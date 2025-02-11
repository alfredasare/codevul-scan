void DisplaySourceCustomBindings::OnSessionError(int sink_id,
                                                 DisplaySourceErrorType type,
                                                 const std::string& message) {
  if (sink_id < 0 || sink_id >= DisplaySessions.size()) {
    LOG(ERROR) << "Invalid sink_id: " << sink_id;
    return;
  }
  CHECK(DisplaySessions[sink_id]);
  DispatchSessionError(sink_id, type, message);
}