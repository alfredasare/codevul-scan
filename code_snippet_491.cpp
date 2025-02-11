SPL_METHOD(DirectoryIterator, current)
{
    if (zend_parse_parameters_none() == FAILURE) {
        return;
    }
    if (Z_TYPE_P(getThis())!= IS_OBJECT) {
        return;
    }
    zval *retval = &retval_ptr;
    ZVAL_COPY_VALUE(retval, getThis());
    RETURN_ZVAL(retval, 1, 0);
}