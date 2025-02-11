status_t NuPlayer::GenericSource::setDataSource(const sp<DataSource>& source) {
    resetDataSource();
    if (source == nullptr) {
        return ERROR_INVALID_ARGS;
    }

    size_t dataSize = source->getSize();
    if (dataSize > kMaxBufferData) {
        return ERROR_INVALID_ARGS;
    }

    uint8_t* buffer = new uint8_t[dataSize];
    if (buffer == nullptr) {
        return ERROR_OUT_OF_MEMORY;
    }

    source->getData(buffer, dataSize);
    mDataSource = buffer;
    mDataSourceSize = dataSize;

    return OK;
}