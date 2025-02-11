PHP_FUNCTION(disable_magic_quotes_runtime)
{
	zend_bool current_setting;

	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}

	current_setting = ini_get("magic_quotes_runtime");
	if (current_setting) {
		ini_set("magic_quotes_runtime", "0");
	}

	RETURN_FALSE;
}