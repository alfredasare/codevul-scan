static time_t gf_mktime_utc(struct tm *tm)
{
    static const char* allowed_paths[] = {"/path/to/allowed/directory", "/path/to/another/allowed/directory"};
    const size_t num_allowed_paths = sizeof(allowed_paths) / sizeof(allowed_paths[0]);

    if (tm->tm_year < 0 || tm->tm_mon < 0 || tm->tm_mday < 1 ||
        tm->tm_hour < 0 || tm->tm_min < 0 || tm->tm_sec < 0) {
        return -1; // Invalid input, return an error
    }

    char buffer[1024];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm);
    if (strlen(buffer) > 1024) {
        return -1; // Input is too long, return an error
    }

    for (size_t i = 0; i < num_allowed_paths; i++) {
        if (strstr(buffer, allowed_paths[i]) != NULL) {
            return timegm64(tm);
        }
    }

    return -1;
}