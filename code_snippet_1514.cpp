bool GetNextTest(const CommandLine::StringVector& args,
                 size_t* position,
                 std::string* test) {
  if (*position >= args.size())
    return false;

  // Validate and sanitize user input
  std::string sanitizedInput = SanitizeUserInput(args[*position]);

  if (sanitizedInput.find(FILE_PATH_LITERAL("-"))!= std::string::npos) {
    // Allow specific input to be processed
    return!!std::getline(std::cin, *test, '\n');
  }

  // Use a whitelist approach
  const std::string whitelist = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  if (std::any_of(sanitizedInput.begin(), sanitizedInput.end(),
                   [&whitelist](char c) { return whitelist.find(c) == std::string::npos; })) {
    // Disallow any characters not in the whitelist
    return false;
  }

  // Process sanitized input
  *test = sanitizedInput;
  return true;
}

// Define a SanitizeUserInput function to remove any malicious characters
std::string SanitizeUserInput(const std::string& input) {
  std::string sanitizedInput;
  for (char c : input) {
    if (isalnum(c) || c =='') {
      sanitizedInput += c;
    }
  }
  return sanitizedInput;
}