PHP_FUNCTION(time_sleep_until)
{
    double d_ts, c_ts;
    struct timeval tm;
    struct timespec php_req, php_rem;
    int err;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "d", &d_ts) == FAILURE) {
        return;
    }

    gettimeofday((struct timeval *) &tm, NULL);

    c_ts = (double)(d_ts - tm.tv_sec - tm.tv_usec / 1000000.00);
    if (c_ts < 0) {
        php_error_docref(NULL TSRMLS_CC, E_WARNING, "Sleep until to time is less than current time");
        RETURN_FALSE;
    }

    php_req.tv_sec = (time_t) c_ts;
    if (php_req.tv_sec > c_ts) {
        php_req.tv_sec--;
    }
    php_req.tv_nsec = (long) ((c_ts - php_req.tv_sec) * 1000000000.00);

    php_req.tv_sec = 0;
    php_req.tv_nsec = 0;
    php_rem.tv_sec = 0;
    php_rem.tv_nsec = 0;

    while (1) {
        err = nanosleep(&php_req, &php_rem);
        if (err == 0) {
            break; // sleep successful
        } else if (errno == EINTR) {
            // interrupted by a signal, update php_req and php_rem
            php_req.tv_sec = php_rem.tv_sec;
            php_req.tv_nsec = php_rem.tv_nsec;
        } else {
            php_error_docref(NULL TSRMLS_CC, E_ERROR, "Error sleeping: %s", strerror(err));
            RETURN_FALSE;
        }
    }

    RETURN_TRUE;
}