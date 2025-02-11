virtual void DoCloseFlushPendingWriteTest(SocketStreamEvent* event) {
  for (const auto& message : messages_) {
    std::vector<char> frame(message.size() + 2); // Reserve space for '\0', '\xff' and message data
    frame[0] = '\0';
    std::copy(message.begin(), message.end(), frame.begin() + 1);
    frame.back() = '\xff';
    // Validate buffer size before sending data
    EXPECT_TRUE(event->socket->SendData(&frame[0], frame.size()) && frame.size() <= event->socket->GetSendBufferSize());
  }
  event->socket->Close();
}