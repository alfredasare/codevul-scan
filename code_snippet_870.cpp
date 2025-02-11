php
static PHP_INI_MH(OnUpdateSerializer) /* {{{ */
{
    const ps_serializer *tmp;
    SESSION_CHECK_ACTIVE_STATE;

    tmp = _php_find_ps_serializer(new_value TSRMLS_CC);

    if (zend_ini_get('modules_activated', 'int') &&!tmp) {
        int err_type;

        if (stage == ZEND_INI_STAGE_RUNTIME) {
            err_type = E_WARNING;
        } else {
            err_type = E_ERROR;
        }

        /* Do not output error when restoring ini options. */
        if (stage!= ZEND_INI_STAGE_DEACTIVATE) {
            php_error_docref(NULL TSRMLS_CC, err_type, "Cannot find serialization handler '%s'", new_value);
        }
        return FAILURE;
    }
    PS(serializer) = tmp;

    return SUCCESS;
}
/* }}} */