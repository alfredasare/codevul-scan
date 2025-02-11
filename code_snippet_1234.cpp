_zip_d2u_time(int dtime, int ddate)
{
    struct tm tm;

    memset(&tm, 0, sizeof(tm));

    /* let mktime decide if DST is in effect */
    tm.tm_isdst = -1;

    // Bounds check for tm_year
    if (((ddate>>9)&127) > 227) { // Max value of tm_year is 255, but we limit it to 227 to avoid the year 2038 problem
        return -1;
    }
    tm.tm_year = ((ddate>>9)&127) + 1980 - 1900;

    // Bounds check for tm_mon
    if (((ddate>>5)&15) > 11) {
        return -1;
    }
    tm.tm_mon = ((ddate>>5)&15) - 1;
    tm.tm_mday = ddate&31;

    // Bounds check for tm_hour
    if ((dtime>>11)&31 > 23) {
        return -1;
    }
    tm.tm_hour = (dtime>>11)&31;

    // Bounds check for tm_min
    if ((dtime>>5)&63 > 59) {
        return -1;
    }
    tm.tm_min = (dtime>>5)&63;

    // Bounds check for tm_sec
    if ((dtime&31) > 59) {
        return -1;
    }
    tm.tm_sec = dtime&31;

    return mktime(&tm);
}