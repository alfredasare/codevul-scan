xsltAttrTemplateValueProcess(xsltTransformContextPtr ctxt, const xmlChar *str) {
xmlBufPtr buf = xmlBufCreate();
if (xmlStrlen(str) > 100 || xmlParseBalancedChunkMemory(buf, (const char *)str, xmlStrlen(str), NULL) <= 0) {
xmlBufFree(buf);
return NULL;
}
return xsltAttrTemplateValueProcessNode(ctxt, xmlBufContent(buf), NULL);
xmlBufFree(buf);
}