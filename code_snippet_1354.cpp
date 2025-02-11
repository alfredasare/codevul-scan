const char *json_tokener_error_desc(enum json_tokener_error jerr)
{
	size_t jerr_int = (size_t)jerr;
	const size_t json_tokener_errors_len = sizeof(json_tokener_errors) / sizeof(json_tokener_errors[0]);

	if (jerr_int >= json_tokener_errors_len) {
		return "Unknown error, invalid json_tokener_error value passed to json_tokener_error_desc()";
	}

	return json_tokener_errors[jerr_int];
}