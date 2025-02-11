PHP_FUNCTION(snmp_set_enum_print)
{
	char input[32]; // adjusted buffer size
	long a1;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &a1) == FAILURE) {
		RETURN_FALSE;
	}

	if (a1 < 0 || a1 > 1) { // validate input
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid input. Expected 0 or 1.");
		RETURN_FALSE;
	}

	snprintf(input, sizeof(input), "%ld", a1); // sanitize input
	netsnmp_ds_set_boolean(NETSNMP_DS_LIBRARY_ID, NETSNMP_DS_LIB_PRINT_NUMERIC_ENUM, (int) a1);
	RETURN_TRUE;
}