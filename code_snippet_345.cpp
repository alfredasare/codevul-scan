static int php_zip_status_sys(struct zip *za TSRMLS_DC) /* {{{ */
{
    int zep, syp;
    int status; /* New variable to hold the required information */

    zip_error_get(za, &zep, &syp);
    status = syp; /* Only expose the required information */
    return status;
}
/* }}} */