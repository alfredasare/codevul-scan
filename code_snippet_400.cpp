NuPlayer::GenericSource::~GenericSource() {
    if (mLooper != NULL) {
        mLooper->unregisterHandler(id());
    }

    if (mLooper != NULL && mLooper->isRunning()) {
        mLooper->stop();
    }
}