MPEG4Source::~MPEG4Source() {
    if (mStarted) {
        stop();
        mStarted = false;
    }

    if (mCurrentSampleInfoSizes) {
        free(mCurrentSampleInfoSizes);
        mCurrentSampleInfoSizes = nullptr;
    }

    if (mCurrentSampleInfoOffsets) {
        free(mCurrentSampleInfoOffsets);
        mCurrentSampleInfoOffsets = nullptr;
    }
}