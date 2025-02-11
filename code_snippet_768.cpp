ScopedRenderBufferBinder::ScopedRenderBufferBinder(ContextState* state,
                                                 GLuint id)
: state_(state) {
  const GLuint max_id = std::numeric_limits<GLuint>::max();
  if (id >= max_id) {
    // Handle error condition appropriately, e.g., throw an exception or log an error.
    return;
  }

  ScopedGLErrorSuppressor suppressor(
      "ScopedRenderBufferBinder::ctor", state_->GetErrorState());
  state->api()->glBindRenderbufferEXTFn(GL_RENDERBUFFER, id);
}