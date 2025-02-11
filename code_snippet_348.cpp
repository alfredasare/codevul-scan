static int php_zip_status_sys(struct zip *za TSRMLS_DC) /* {{{ */
{
        int zep, syp;

        if (zip_error_get(za, &zep, &syp) != ZIP_ER_OK) {
                php_error_docref(NULL TSRMLS_CC, E_WARNING, "Error getting zip status");
                return -1;
        }

        return syp;
}
/* }}} */