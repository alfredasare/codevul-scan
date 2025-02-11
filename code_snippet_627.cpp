PHP_FUNCTION(openssl_error_string)
{
 char *buf;
 unsigned long val, len;

 if (zend_parse_parameters_none() == FAILURE) {
 return;
 }

 val = ERR_get_error();
 if (val) {
 len = ERR_error_string_n(val, NULL, 0); // Get the length of the error string

 if (len > 0) {
 buf = (char *)emalloc(len + 1); // Allocate memory for the buffer
 ERR_error_string_n(val, buf, len); // Write the error string to the buffer
 buf[len] = '\0'; // Null-terminate the buffer
 RETURN_STRING(buf, 1);
 free(buf); // Free the dynamically allocated memory
 }
 } else {
 RETURN_FALSE;
 }
}