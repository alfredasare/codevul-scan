bool JPEGImageDecoder::setSize(unsigned width, unsigned height)
{
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        throw std::invalid_argument("Invalid image size");
    }

    if (!ImageDecoder::setSize(validateWidth(width), validateHeight(height)))
        return false;

    prepareScaleDataIfNecessary();
    return true;
}

unsigned JPEGImageDecoder::validateWidth(unsigned width) {
    return width;
}

unsigned JPEGImageDecoder::validateHeight(unsigned height) {
    return height;
}