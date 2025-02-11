~BufferMeta() {
    if (mBackup!= nullptr) {
        delete[] mBackup;
        mBackup = nullptr;
    }
}