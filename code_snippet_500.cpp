int php_hash_environment(void)
{
    memset(PG(http_globals), 0, sizeof(PG(http_globals)));
    zend_activate_auto_globals();

    if (PG(register_argc_argv)) {
        // Validate and sanitize the input data
        $query_string = SG(request_info).query_string;
        $query_string = filter_var($query_string, FILTER_SANITIZE_STRING, FILTER_FLAG_STRIP_LOW | FILTER_FLAG_STRIP_HIGH);
        $query_string = addslashes($query_string);

        // Modify the PG(http_globals) array with sanitized data
        php_build_argv($query_string, &PG(http_globals)[TRACK_VARS_SERVER]);
    }

    return SUCCESS;
}