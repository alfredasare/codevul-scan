SocketStreamEvent(EventType type,
                  SocketStream* socket_stream,
                  int num,
                  const std::string& str,
                  AuthChallengeInfo* auth_challenge_info,
                  int error)
  : event_type(type), socket(socket_stream), number(num), data(str),
    auth_info(auth_challenge_info)
{
  if (error < 0 || error > 255) {
    error_code = -1; // or throw an exception, etc.
  } else {
    error_code = error;
  }
}