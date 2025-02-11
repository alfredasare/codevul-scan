ScopedRenderBufferBinder::ScopedRenderBufferBinder(ContextState* state, GLuint id)
    : state_(state) {
  ScopedGLErrorSuppressor suppressor(
      "ScopedRenderBufferBinder::ctor", state_->GetErrorState());

  // Validate and sanitize the id parameter
  if (!std::all_of(std::begin(id), std::end(id), ::isalnum)) {
    std::cerr << "Invalid renderbuffer id: " << id << std::endl;
    return;
  }

  state->api()->glBindRenderbufferEXTFn(GL_RENDERBUFFER, id);
}