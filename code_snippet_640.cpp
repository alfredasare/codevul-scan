status_t ESDS::getCodecSpecificInfo(const void **data, size_t *size) const {
    if (mInitCheck!= OK) {
        return mInitCheck;
    }

    ssize_t decoderSpecificLength = mDecoderSpecificLength; 
    if (decoderSpecificLength < 0) {
        return ERROR_INVALID_LENGTH;
    }

    *data = &mData[mDecoderSpecificOffset];
    *size = decoderSpecificLength;

    return OK;
}