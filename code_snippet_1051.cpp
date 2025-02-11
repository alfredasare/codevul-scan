PHP\_FUNCTION(openssl\_get\_md\_methods)
{
zend\_bool aliases = 0;
zval *input\_aliases = NULL;

if (zend\_parse\_parameters(ZEND\_NUM\_ARGS() TSRMLS\_CC, "|z", &input\_aliases) == FAILURE) {
return;
}

array\_init(return\_value);

if (input\_aliases) {
aliases = Z\_BVAL\_P(input\_aliases);
}

OBJ\_NAME\_do\_all\_sorted(OBJ\_NAME\_TYPE\_MD\_METH,
aliases ? openssl\_add\_method\_or\_alias : openssl\_add\_method,
return\_value);
}