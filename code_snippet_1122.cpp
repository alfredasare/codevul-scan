PHP\_FUNCTION(mcrypt\_list\_algorithms)
{
 char **modules;
 const char *lib\_dir = "/usr/local/lib/mcrypt"; /* Default path */
 int lib\_dir\_len = strlen(lib\_dir);
 int i, count;

 if (zend\_parse\_parameters(ZEND\_NUM\_ARGS() TSRMLS\_CC, "|s",
 &lib\_dir, &lib\_dir\_len) == FAILURE) {
 return;
 }

 /* Validate the input before using it */
 if (lib\_dir != NULL && lib\_dir\_len > 0) {
 lib\_dir\_len = strlen(lib\_dir);
 if (lib\_dir\_len >= PATH\_MAX) {
 php\_error\_docref(NULL TSRMLS\_CC, E\_WARNING, "Invalid path, too long");
 return;
 }
 }
 array\_init(return\_value);
 modules = mcrypt\_list\_algorithms(lib\_dir, &count);

 if (count == 0) {
 php\_error\_docref(NULL TSRMLS\_CC, E\_WARNING, "No algorithms found in module dir");
 }
 for (i = 0; i < count; i++) {
 add\_index\_string(return\_value, i, modules[i], 1);
 }
 mcrypt\_free\_p(modules, count);
}