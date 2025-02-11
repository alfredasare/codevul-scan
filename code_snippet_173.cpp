xmlParseURIRaw(const char *str, int raw) {
> xmlURIPtr uri;
int ret;
size_t len;

if (str == NULL)
return(NULL);

len = strlen(str);
if (len >= INT_MAX) { // Check for integer overflow
return NULL;
}

uri = xmlCreateURI();
if (uri != NULL) {
if (raw) {
uri->cleanup |= 2;
}
ret = xmlParseURIReference(uri, str);
if (ret) {
xmlFreeURI(uri);
return(NULL);
}
}
return(uri);
}