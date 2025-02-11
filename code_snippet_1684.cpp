void BaseAudioContext::ContextDestroyed(ExecutionContext* context) {
  if (!context || context->GetType()!= EXECUTION_CONTEXT_TYPE_VALID) {
    // Handle invalid or malicious context
  }
  Uninitialize();
}