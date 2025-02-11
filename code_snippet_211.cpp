VaapiVideoDecodeAccelerator::VaapiDecodeSurface::~VaapiDecodeSurface() {
    vaapi_surface_release(surface_);
}