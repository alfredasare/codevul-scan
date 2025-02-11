error::Error GLES2DecoderImpl::HandleDrawArraysInstancedANGLE(
uint32_t immediate_data_size, const gles2::DrawArraysInstancedANGLE& c) {
if (!feature_info_->feature_flags().angle_instanced_arrays) {
SetGLError(GL_INVALID_OPERATION,
"glDrawArraysInstancedANGLE", "function not available");
return error::kNoError;
}

constexpr uint32_t kMaximumValidImmediateDataSize = 1024; // Adjust as needed
if (immediate_data_size > kMaximumValidImmediateDataSize) {
SetGLError(GL_INVALID_VALUE, "glDrawArraysInstancedANGLE",
"immediate_data_size exceeds maximum valid value");
return error::kNoError;
}

return DoDrawArrays("glDrawArraysIntancedANGLE",
true,
static_cast<GLenum>(c.mode),
static_cast<GLint>(c.first),
static_cast<GLsizei>(c.count),
static_cast<GLsizei>(c.primcount));
}