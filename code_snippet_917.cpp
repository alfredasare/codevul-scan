PHP_FUNCTION(parse\_str)
{
	char *arg;
	zval *arrayArg = NULL;
	char *res = NULL;
	size\_t arglen;

	if (zend\_parse\_parameters(ZEND\_NUM\_ARGS(), "s|z/", &arg, &arglen, &arrayArg) == FAILURE) {
		return;
	}

	res = estrndup(arg, arglen);

	if (arrayArg == NULL) {
		zval tmp;
		zend\_array *symbol\_table = zend\_rebuild\_symbol\_table();

		ZVAL\_ARR(&tmp, symbol\_table);
		// Use htmlspecialchars to encode the output
		sapi\_module.treat\_data(PARSE\_STRING, htmlspecialchars(res, ENT\_QUOTES | ENT\_SUBSTITUTE, "UTF-8"), &tmp);
	} else 	{
		zval ret;

		/* Clear out the array that was passed in. */
		zval\_dtor(arrayArg);
		array\_init(&ret);
		// Use htmlspecialchars to encode the output
		sapi\_module.treat\_data(PARSE\_STRING, htmlspecialchars(res, ENT\_QUOTES | ENT\_SUBSTITUTE, "UTF-8"), &ret);
		ZVAL\_COPY\_VALUE(arrayArg, &ret);
	}
}