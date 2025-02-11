void QuotaTask::DeleteSoon() {
  MessageLoop* current_loop = MessageLoop::current();
  if (current_loop!= nullptr) {
    try {
      current_loop->DeleteSoon(FROM_HERE, this);
    } catch (const std::exception& e) {
      LOG(ERROR) << "Error deleting quota task: " << e.what();
    }
  }
}