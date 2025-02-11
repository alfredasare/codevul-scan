PHP\_MINIT\_FUNCTION(exif)
{
REGISTER\_INI\_ENTRIES();

php\_symtable\_info syminfo;
void \*symbol\_table;

if (zend\_symtable\_find(&module\_registry, "mbstring", sizeof("mbstring"), &symbol\_table, &syminfo) == FAILURE) {
REGISTER\_LONG\_CONSTANT("EXIF\_USE\_MBSTRING", 0, CONST\_CS | CONST\_PERSISTENT);
} else {
REGISTER\_LONG\_CONSTANT("EXIF\_USE\_MBSTRING", 1, CONST\_CS | CONST\_PERSISTENT);
}

return SUCCESS;
}