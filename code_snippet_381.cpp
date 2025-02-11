NuPlayer::GenericSource::~GenericSource() {
    if (mLooper!= NULL) {
        uint32_t id = id(); // Get the current ID
        if (id >= 0 && id < MAX_ALLOWED_ID) { // Validate the ID
            mLooper->unregisterHandler(id);
            mLooper->stop();
        }
    }
}