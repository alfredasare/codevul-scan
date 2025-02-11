SampleTable::SampleTable(const sp<DataSource> &source) {
    if (!source) {
        throw std::invalid_argument("Invalid DataSource");
    }

    if (mChunkOffsetOffset < 0 || mChunkOffsetType < 0 || mNumChunkOffsets < 0 ||
        mSampleToChunkOffset < 0 || mNumSampleToChunkOffsets < 0 ||
        mSampleSizeOffset < 0 || mSampleSizeFieldSize < 0 ||
        mDefaultSampleSize < 0 || mNumSampleSizes < 0 ||
        mTimeToSampleCount < 0 || !mTimeToSample || !mSampleTimeEntries || !mCompositionTimeDeltaEntries ||
        mNumCompositionTimeDeltaEntries < 0 ||
        mSyncSampleOffset < 0 || mNumSyncSamples < 0 || mLastSyncSampleIndex < 0) {
        throw std::invalid_argument("Invalid input parameters");
    }

    mSampleIterator = new SampleIterator(this);
}