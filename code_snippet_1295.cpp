void InputEngine::GetRulebasedKeypressCountForTesting(GetRulebasedKeypressCountForTestingCallback callback) {
  auto& context = channel_receivers_.current_context();
  auto& engine = context.get()->engine;

  if (!std::is_pointer_v<std::decay_t<decltype(callback)>> ||!callback) {
    throw std::runtime_error("Invalid callback object");
  }

  std::function<void(int)> wrapped_callback = [callback](int result) { callback(result); };
  wrapped_callback.Run(engine? engine->process_key_count() : -1);
}