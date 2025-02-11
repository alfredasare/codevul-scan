ZEND_API int zend\_eval\_string\_ex(char \*str, zval \*retval\_ptr, char \*string\_name, int handle\_exceptions) /* {{{ */
{
int i, j;
size\_t len;
int is\_allowed = 1;

// Check if the string only contains allowed characters
for (i = 0; str[i] != '\0'; i++) {
if (!isalnum((unsigned char)str[i]) && str[i] != '\_' && str[i] != '(' && str[i] != ')') {
is\_allowed = 0;
break;
}
}

// Check if the string contains only allowed functions
if (is_allowed) {