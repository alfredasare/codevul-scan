function validate_path($path) {
    return preg_match('/^[a-zA-Z0-9\/\._-]+$/', $path) === 1;
}

SPL_METHOD(SplObjectStorage, getInfo)
{
    spl_SplObjectStorageElement *element;
    spl_SplObjectStorage *intern = Z_SPLOBJSTORAGE_P(getThis());

    if (zend_parse_parameters_none() == FAILURE) {
        return;
    }

    if ((element = zend_hash_get_current_data_ptr_ex(&intern->storage, &intern->pos)) == NULL) {
        return;
    }

    if (!validate_path(Z_TYPE_P(&element->inf) == IS_STRING? Z_STRVAL_P(&element->inf) : "")) {
        return;
    }
    ZVAL_COPY(return_value, &element->inf);
}