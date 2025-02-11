PHP_FUNCTION(xml_error_string)
{
	long code;
	char str[XML_ERROR_STRING_SIZE]; // Use a constant to define the buffer size

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &code) == FAILURE) {
		return;
	}

	if (code < XML_ERROR_NONE || code > XML_ERROR_LAST) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid error code: %ld", code);
		RETURN_FALSE;
	}

	strncpy(str, XML_ErrorString((int)code), sizeof(str)); // Use strncpy() and specify the buffer size
	str[sizeof(str) - 1] = '\0'; // Ensure null termination
	RETVAL_STRING(str, 1);
}