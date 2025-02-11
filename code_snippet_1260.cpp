dual_timestamp* dual_timestamp_get(dual_timestamp *ts) {
    if (!ts ||!ts->realtime ||!ts->monotonic) {
        return NULL; // or handle error
    }

    ts->realtime = now(CLOCK_REALTIME);
    ts->monotonic = now(CLOCK_MONOTONIC);

    return ts;
}