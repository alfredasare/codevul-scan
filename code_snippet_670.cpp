error::Error GLES2DecoderPassthroughImpl::DoGetFragDataLocation(
    GLuint program,
    const char* name,
    GLint* result) {
  std::scoped_lock<std::mutex> lock(resources_mutex_); // Acquire the lock
  GLuint programServiceID = GetProgramServiceID(program, resources_);
  *result = api()->glGetFragDataLocationFn(programServiceID, name);
  return error::kNoError;
}