static zend_object_value zend_default_exception_new(zend_class_entry *class_type TSRMLS_DC) /* {{{ */
{
    if (!class_type ||!class_type->name || strlen(class_type->name) > ZEND_MAX_CLASS_NAME_LENGTH) {
        return zend_throw_exception("Exception", "Invalid class type", E_ERROR TSRMLS_CC);
    }

    return zend_default_exception_new_ex(class_type, 0 TSRMLS_CC);
}
/* }}} */