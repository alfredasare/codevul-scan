void WaitUntilShown() {
  while (!is_visible_) {
    if (validateInput(message_loop_runner_)) {
      message_loop_runner_->Run();
    } else {
      // Handle invalid input
      // For example, log an error or throw an exception
    }
  }
}

bool validateInput(MessageLoopRunner* message_loop_runner) {
  return message_loop_runner!= nullptr && message_loop_runner->getId() > 0;
}