c++
status_t SoftHEVC::resetPlugin() {
    mIsInFlush = false;
    mReceivedEOS = false;
    static constexpr size_t kArraySize = 100; // replace with the actual size of the arrays
    std::fill_n(mTimeStamps, kArraySize, 0);
    std::fill_n(mTimeStampsValid, kArraySize, 0);

 /* Initialize both start and end times */
    gettimeofday(&mTimeStart, NULL);
    gettimeofday(&mTimeEnd, NULL);

 return OK;
}