void GLManager::SetupBaseContext() {
  if (use_count_) {
    #if defined(OS_ANDROID)
    base_share_group_ =
        new scoped_refptr<gl::GLShareGroup>(new gl::GLShareGroup);
    gfx::Size size(4, 4);
    base_surface_ = new scoped_refptr<gl::GLSurface>(
        gl::init::CreateOffscreenGLSurface(size));
    base_context_ = new scoped_refptr<gl::GLContext>(gl::init::CreateGLContext(
        base_share_group_->get(), base_surface_->get(),
        gl::GLContextAttribs()));
    if (!g_gpu_feature_info.ApplyToGLContext(base_context_->get())) {
      LOG(WARNING) << "Error applying GPU features";
    } else {
      LOG(INFO) << "GPU features applied successfully";
    }
    #endif
  }
  ++use_count_;
}