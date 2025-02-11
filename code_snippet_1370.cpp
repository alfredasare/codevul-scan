const char* MetadataRetrieverClient::extractMetadata(int keyCode)
{
    static const int MIN_KEY_CODE = 0;
    static const int MAX_KEY_CODE = 100; // Adjust this value according to your actual key code range

    ALOGV("extractMetadata");
    Mutex::Autolock lock(mLock);
    if (mRetriever == NULL) {
        ALOGE("retriever is not initialized");
        return NULL;
    }

    if (keyCode < MIN_KEY_CODE || keyCode > MAX_KEY_CODE) {
        ALOGE("Key code is out of bounds: %d", keyCode);
        return NULL;
    }

    return mRetriever->extractMetadata(keyCode);
}