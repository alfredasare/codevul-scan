void CancelHandwriting(int n_strokes) {
  std::unique_ptr<IBusInputContext> context(GetInputContext(input_context_path_, ibus_));
  if (!context) {
    return;
  }
  context->ibus_input_context_cancel_hand_writing(n_strokes);
}