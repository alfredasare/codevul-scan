VaapiDecodeSurface::~VaapiDecodeSurface() {
    if (decodeSurface != nullptr) {
        vaapi_function_to_destroy_resource(decodeSurface);
    }
}