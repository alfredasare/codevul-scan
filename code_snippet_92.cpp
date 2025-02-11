void DrawingBuffer::ClearFramebuffers(GLbitfield clear_mask) {
  if (clear_mask > (1 << (sizeof(GLbitfield) * 8))) {
    throw std::invalid_argument("Invalid clear mask value");
  }
  ScopedStateRestorer scoped_state_restorer(this);
  ClearFramebuffersInternal(clear_mask);
}