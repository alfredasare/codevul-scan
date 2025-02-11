void CameraClient::handleGenericData(int32_t msgType, const sp<IMemory>& dataPtr, camera_frame_metadata_t *metadata) {
    sp<ICameraClient> c = mRemoteCallback;
    mLock.unlock();
    if (c!= 0) {
        size_t metadataSize = sizeof(camera_frame_metadata_t);
        if (dataPtr->size() <= metadataSize) {
            c->dataCallback(msgType, dataPtr, metadata);
        } else {
            // Handle the case where the data is too large for the metadata buffer
            LOGE("Data exceeds metadata buffer size");
        }
    }
}