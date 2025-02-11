PHP_FUNCTION(escapeshellarg)
{
	char *argument;
	size_t argument_len;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &argument, &argument_len) == FAILURE) {
		return;
	}

	if (argument) {
		char *escaped_arg = escapeshellarg(argument);
		RETVAL_STR(escaped_arg);
		efree(escaped_arg);
	}
}