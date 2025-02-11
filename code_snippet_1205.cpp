const char* MetadataRetrieverClient::extractMetadata(int keyCode)
{
    ALOGV("extractMetadata");
    Mutex::Autolock lock(mLock);
    if (keyCode < 0 || keyCode >= MAX_VALID_KEY_CODE) {
        ALOGE("Invalid keyCode: %d", keyCode);
        return NULL;
    }
    if (mRetriever == NULL) {
        ALOGE("retriever is not initialized");
        return NULL;
    }
    return mRetriever->extractMetadata(keyCode);
}