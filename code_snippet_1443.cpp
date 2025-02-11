FFmpegVideoDecodeEngine::FFmpegVideoDecodeEngine(const std::string& codec_context)
    : codec_context_(NULL),
      event_handler_(NULL),
      frame_rate_numerator_(0),
      frame_rate_denominator_(0),
      pending_input_buffers_(0),
      pending_output_buffers_(0),
      output_eos_reached_(false),
      flush_pending_(false) {
    // Validate and sanitize the codec_context input
    if (!isValidCodecContext(codec_context)) {
        throw std::invalid_argument("Invalid codec context");
    }
    codec_context_ = sanitizeCodecContext(codec_context);
}

bool FFmpegVideoDecodeEngine::isValidCodecContext(const std::string& codec_context) {
    // Implement a whitelist approach to validate allowed characters and paths
    const std::set<char> allowed_chars = {'a', 'b', 'c',...}; // Define allowed characters
    for (char c : codec_context) {
        if (!allowed_chars.count(c)) {
            return false; // Invalid character found
        }
    }
    return true;
}

std::string FFmpegVideoDecodeEngine::sanitizeCodecContext(const std::string& codec_context) {
    // Implement a sanitization mechanism to remove invalid or malicious characters
    std::string sanitized_context;
    for (char c : codec_context) {
        if (isalnum(c) || c == '.') { // Allow alphanumeric characters and periods
            sanitized_context += c;
        }
    }
    return sanitized_context;
}