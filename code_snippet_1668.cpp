status_t NuPlayer::GenericSource::setDataSource(const sp<DataSource>& source) {
    if (source == nullptr) {
        return ERROR_BAD_VALUE;
    }

    // Limit the size of the data source to prevent buffer overflow
    // Adjust the maximum size value as needed for your specific use case
    size_t max_size = 1000000;
    if (source->size() > max_size) {
        return ERROR_BUFFER_OVERFLOW;
    }

    resetDataSource();
    mDataSource = source;
    return OK;
}