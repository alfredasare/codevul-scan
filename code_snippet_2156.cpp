static bool VerifyNumber(const uint8* buffer,
                         int buffer_size,
                         int* offset,
                         int max_digits) {
  RCHECK(*offset < buffer_size);

  while (isspace(buffer[*offset])) {
    ++(*offset);
    RCHECK(*offset < buffer_size);
  }

  int numSeen = 0;
  while (--max_digits >= 0 && *offset < buffer_size && isdigit(buffer[*offset])) {
    ++numSeen;
    ++(*offset);
  }

  return (numSeen > 0);
}