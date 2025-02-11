ModuleExport void UnregisterPNMImage(void)
{
  const char* allowed_directories[] = {"/path/to/allowed/directories", NULL};
  const char* input_string = "PAM"; // or any other input string

  // Validate the input string
  char* sanitized_input = NULL;
  size_t len;
  if (strchr(input_string, '/')!= NULL) {
    // If the input string contains a '/', it's likely a path
    // Restrict the input string to only allow valid file paths
    sanitized_input = strndup(input_string, strchr(input_string, '/') - input_string);
    len = strlen(sanitized_input);
  } else {
    sanitized_input = strdup(input_string);
    len = strlen(sanitized_input);
  }

  // Sanitize the sanitized_input string
  char* dir = NULL;
  for (int i = 0; allowed_directories[i]!= NULL; i++) {
    if (strncmp(sanitized_input, allowed_directories[i], len) == 0) {
      dir = allowed_directories[i];
      break;
    }
  }

  if (dir!= NULL) {
    // Call UnregisterMagickInfo with the sanitized directory
    (void) UnregisterMagickInfo(dir);
  } else {
    // Handle the error case where the input string is not a valid file path
  }

  free(sanitized_input);
}