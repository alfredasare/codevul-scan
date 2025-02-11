static void vnc_write_pixels_copy(VncState *vs, void *pixels, int size)
{
    try {
        vnc_write(vs, pixels, size);
    } catch (std::exception &e) {
        vs->ReleaseResources();
        throw;
    }
}