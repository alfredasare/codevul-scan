static zend_object_value zend\_default\_exception\_new(zend\_class\_entry *class\_type TSRMLS\_DC) /* {{{ */
{
	return zend\_default\_exception\_new\_ex(class\_type, 0, 0 TSRMLS\_CC);
}
/* }}} */