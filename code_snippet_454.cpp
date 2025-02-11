media_status_t AMediaCodec_flush(AMediaCodec *mData) {
    media_status_t status = mData->mCodec->flush();
    return translate_error(status);
}