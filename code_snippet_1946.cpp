bool WebGraphicsContext3DCommandBufferImpl::isContextLost() {
  if (!validateContext(context_)) {
    return true; // or throw an exception, depending on your requirements
  }
  return initialize_failed_ ||
      (context_ && context_->IsCommandBufferContextLost()) ||
      context_lost_reason_!= GL_NO_ERROR;
}

bool WebGraphicsContext3DCommandBufferImpl::validateContext(GraphicsContext* context) {
  if (!context ||!context->isValid()) {
    return false;
  }
  return true;
}