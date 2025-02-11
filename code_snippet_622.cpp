void CameraClient::handleGenericData(int32_t msgType, const sp<IMemory>& dataPtr, camera\_frame\_metadata\_t \*metadata) {
 sp<ICameraClient> c = mRemoteCallback;
 if (c != 0) {
 mLock.lock(); // Acquire the lock before checking mRemoteCallback
 c->dataCallback(msgType, dataPtr, metadata);
 mLock.unlock();
 } else {
 mLock.unlock();
 }
}