ImageBitmap* ImageBitmap::create(ImageData* data,
                                 Optional<IntRect> cropRect,
                                 const ImageBitmapOptions& options) {
    if (!data) {
        std::cerr << "Error: ImageData pointer is null." << std::endl;
        return nullptr;
    }
    return new ImageBitmap(data, cropRect, options);
}