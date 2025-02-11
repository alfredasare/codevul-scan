MPEG4Source::~MPEG4Source() {
if (mStarted) {
stop();
}

if (mCurrentSampleInfoSizes != nullptr) {
free(mCurrentSampleInfoSizes);
mCurrentSampleInfoSizes = nullptr;
}

if (mCurrentSampleInfoOffsets != nullptr) {
free(mCurrentSampleInfoOffsets);
mCurrentSampleInfoOffsets = nullptr;
}
}