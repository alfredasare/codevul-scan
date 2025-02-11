void BaseAudioContext::ContextDestroyed(ExecutionContext* context) {
  if (context == nullptr) {
    // Handle null input scenario appropriately, e.g., logging an error or throwing an exception.
    return;
  }

  // Additional checks can be added here to validate the context object if required.

  Uninitialize();
}

// In the class definition
std::unique_ptr<ExecutionContext> context_;

// In the constructor
context_ = std::make_unique<ExecutionContext>();

// In the destructor
void BaseAudioContext::ContextDestroyed() {
  context_.reset();
  Uninitialize();
}