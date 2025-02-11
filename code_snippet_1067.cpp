xmlParseVersionInfo(xmlParserCtxtPtr ctxt) {
xmlChar *version = NULL;

if (CMP7(CUR_PTR, 'v', 'e', 'r', 's', 'i', 'o', 'n')) {
SKIP(7);
SKIP_BLANKS;
if (RAW != '=') {
xmlFatalErr(ctxt, XML_ERR_EQUAL_REQUIRED, NULL);
return(NULL);
}
NEXT;
SKIP_BLANKS;
if (RAW == '"' || RAW == '\'') {
char quote = RAW;
NEXT;
version = xmlParseVersionNum(ctxt);
while (CUR_PTR[0] != quote || CUR_PTR[-1] != '\n') {
if (*CUR_PTR == 0) {
xmlFatalErr(ctxt, XML_ERR_STRING_NOT_CLOSED, NULL);
return NULL;
}
NEXT;
}
NEXT;
} else {
xmlFatalErr(ctxt, XML_ERR_STRING_NOT_STARTED, NULL);
}
}
return(version);
}