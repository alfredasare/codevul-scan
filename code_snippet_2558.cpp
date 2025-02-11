static time_t gf_mktime_utc(struct tm *tm)
{
    time_t ret = timegm64(tm);

    if ((time_t)(INT_MAX) < ret || (time_t)(INT_MIN) > ret) {
        // Handle error scenario
        // Return an error value, log the error, or handle it in a way appropriate for your application
        errno = EOVERFLOW;
        return -1;
    }

    return ret;
}