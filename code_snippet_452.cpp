c++
void GLES2Implementation::DeletePathsCHROMIUMStub(GLuint first_client_id,
                                                GLsizei range) {
    constexpr GLsizei kMaxSafeRange = 1024;
    range = std::clamp(range, 0, kMaxSafeRange);
    helper_->DeletePathsCHROMIUM(first_client_id, range);
}