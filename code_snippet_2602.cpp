SampleTable::SampleTable(const sp<DataSource>& source)
: mDataSource(source),
mChunkOffsetOffset(-1),
mChunkOffsetType(0),
mNumChunkOffsets(0),
mSampleToChunkOffset(-1),
mNumSampleToChunkOffsets(0),
mSampleSizeOffset(-1),
mSampleSizeFieldSize(0),

mDefaultSampleSize(0),
mNumSampleSizes(0),
mTimeToSampleCount(0),
mTimeToSample(nullptr),
mSampleTimeEntries(nullptr),
mCompositionTimeDeltaEntries(nullptr),
mNumCompositionTimeDeltaEntries(0),
mCompositionDeltaLookup(new CompositionDeltaLookup()),
mSyncSampleOffset(-1),
mNumSyncSamples(0),
mSyncSamples(nullptr),
mLastSyncSampleIndex(0),
mSampleToChunkEntries(nullptr) {
if (mCompositionDeltaLookup == nullptr) {
throw std::runtime_error("Error: CompositionDeltaLookup is null");
}
mSampleIterator = new SampleIterator(this);
}