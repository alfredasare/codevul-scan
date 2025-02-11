GLSurfaceEGLOzoneX11::~GLSurfaceEGLOzoneX11() {
  try {
    Destroy();
  } catch (const std::exception& e) {
    // Log the error and take appropriate action, such as cleaning up any remaining resources.
  }
}