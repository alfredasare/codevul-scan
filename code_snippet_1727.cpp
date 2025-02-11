status_t SoftHEVC::resetPlugin() {
    mIsInFlush = false;
    mReceivedEOS = false;
    memset(mTimeStamps, 0, sizeof(mTimeStamps));
    memset(mTimeStampsValid, 0, sizeof(mTimeStampsValid));

    struct timeval tv;
    if (gettimeofday(&tv, NULL) == -1) {
        return ERROR;
    }
    mTimeStart.tv_sec = tv.tv_sec;
    mTimeStart.tv_usec = tv.tv_usec;
    if (gettimeofday(&tv, NULL) == -1) {
        return ERROR;
    }
    mTimeEnd.tv_sec = tv.tv_sec;
    mTimeEnd.tv_usec = tv.tv_usec;

    if (mTimeStart.tv_usec > mTimeEnd.tv_usec) {
        mTimeEnd.tv_sec += 1;
        mTimeEnd.tv_usec -= 1000000;
    }

    return OK;
}