class SocketStreamEvent {
 public:
  // ...
  explicit SocketStreamEvent(EventType type,
                             SocketStream* socket_stream,
                             int num,
                             const std::string& str,
                             AuthChallengeInfo* auth_challenge_info,
                             int error);
  // ...

 private:
  // ...
  static constexpr int kMaxNumber = 100;  // Set an appropriate maximum value.
  int number;
  std::string data;
  // ...
};

SocketStreamEvent::SocketStreamEvent(EventType type,
                                     SocketStream* socket_stream,
                                     int num,
                                     const std::string& str,
                                     AuthChallengeInfo* auth_challenge_info,
                                     int error)
  : event_type(type), socket(socket_stream),
    number(std::clamp(num, 0, kMaxNumber)),
    data(str), auth_info(auth_challenge_info), error_code(error) {}