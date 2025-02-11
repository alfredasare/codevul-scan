void ChangeCurrentInputMethodFromId(const std::string& input_method_id) {
  const size_t maxRecursionDepth = 10; // Adjust this value based on your specific use case
  size_t recursionDepth = 0;

  while (recursionDepth < maxRecursionDepth) {
    const chromeos::InputMethodDescriptor* descriptor =
        chromeos::input_method::GetInputMethodDescriptorFromId(input_method_id);
    if (descriptor) {
      ChangeCurrentInputMethod(*descriptor);
      break; // Exit the loop once the current method is changed
    } else {
      LOG(ERROR) << "Descriptor is not found for: " << input_method_id;
      break; // Exit the loop if no valid descriptor is found
    }
    recursionDepth++;
  }

  if (recursionDepth == maxRecursionDepth) {
    LOG(WARNING) << "Maximum recursion depth reached for: " << input_method_id;
  }
}