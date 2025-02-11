c++
constexpr int MIN_OPENGL_ERROR_CODE = 0;
constexpr int MAX_OPENGL_ERROR_CODE = 128; // Or the actual maximum value if known

bool WebGraphicsContext3DCommandBufferImpl::isContextLost() {
  return initialize_failed_ ||
      (context_ && context_->IsCommandBufferContextLost()) ||
      (context_lost_reason_ >= MIN_OPENGL_ERROR_CODE && context_lost_reason_ <= MAX_OPENGL_ERROR_CODE && context_lost_reason_ == GL_NO_ERROR);
}