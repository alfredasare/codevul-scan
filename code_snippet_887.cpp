constexpr unsigned int MAX_WIDTH = 4096;
constexpr unsigned int MAX_HEIGHT = 4096;

bool JPEGImageDecoder::setSize(unsigned width, unsigned height)
{
    if (width > MAX_WIDTH || height > MAX_HEIGHT)
        return false;

    return ImageDecoder::setSize(width, height) && prepareScaleDataIfNecessary();
}