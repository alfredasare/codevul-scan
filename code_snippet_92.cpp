c++
void DrawingBuffer::ClearFramebuffers(GLbitfield clear_mask) {
  ScopedStateRestorer scoped_state_restorer(this);
  
  constexpr GLbitfield kValidClearMaskMax = GL_DEPTH_BUFFER_BIT;
  if (clear_mask > 0 && clear_mask <= kValidClearMaskMax) {
    ClearFramebuffersInternal(clear_mask);
  } else {
    LOG(ERROR) << "Invalid clear_mask value: " << clear_mask;
  }
}