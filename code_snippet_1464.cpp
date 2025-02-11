FLACParser::~FLACParser()
{
    ALOGV("FLACParser::~FLACParser");
    if (mDecoder!= NULL) {
        std::string safeDecoderPath = getSafeFilePath(mDecoderPath);
        FLAC__stream_decoder_delete(safeDecoderPath.c_str());
        mDecoder = NULL;
    }
}

std::string getSafeFilePath(const std::string& filePath)
{
    std::string safePath;
    if (startsWith(filePath, "/path/to/trusted/directory/")) {
        safePath = filePath;
    } else {
        throw std::runtime_error("Invalid file path");
    }
    return safePath;
}