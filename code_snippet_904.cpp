void OMXNodeInstance::onMessages(std::list<omx_message> &messages) {
  try {
    for (std::list<omx_message>::iterator it = messages.begin(); it!= messages.end(); ) {
      if (handleMessage(*it)) {
        messages.erase(it++);
      } else {
        ++it;
      }
    }
  } catch (...) {
    // Log the error and handle it internally
    LOG_ERROR("Error handling message");
  }

  if (!messages.empty()) {
    mObserver->onMessages(messages);
  }
}