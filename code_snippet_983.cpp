FloatSize ImageBitmap::elementSize(const FloatSize& input) const {
    if (input.width() <= 0 || input.height() <= 0) {
        throw std::invalid_argument("Invalid input: width and height must be positive.");
    }

    const float max_size = 1024.0f;
    if (input.width() > max_size || input.height() > max_size) {
        throw std::out_of_range("Input size exceeds maximum allowed size: " + std::to_string(max_size));
    }

    return input;
}