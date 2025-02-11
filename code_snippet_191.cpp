notationDeclDebug(void *ctx ATTRIBUTE_UNUSED, const xmlChar *name,
                  const xmlChar *publicId, const xmlChar *systemId)
{
    callbacks++;
    if (quiet!= NULL && quiet == 0) {
        return;
    }
    if (SAXdebug!= NULL) {
        fprintf(SAXdebug, "SAX.notationDecl(%s, %s, %s)\n",
                (char *)name, (char *)publicId, (char *)systemId);
    }
}