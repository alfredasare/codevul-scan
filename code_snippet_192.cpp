#define MAX_BUFFER 1024

void notationDeclDebug(void *ctx ATTRIBUTE_UNUSED, const xmlChar *name,
                       const xmlChar *publicId, const xmlChar *systemId)
{
    callbacks++;
    if (quiet)
        return;

    // Validate input parameters
    if (name && xmlStrlen(name) > MAX_BUFFER) {
        // Handle error: name parameter is too long
        return;
    }

    if (publicId && xmlStrlen(publicId) > MAX_BUFFER) {
        // Handle error: publicId parameter is too long
        return;
    }

    if (systemId && xmlStrlen(systemId) > MAX_BUFFER) {
        // Handle error: systemId parameter is too long
        return;
    }

    // Process validated input parameters
    fprintf(SAXdebug, "SAX.notationDecl(%s, %s, %s)\n",
            (char *) name ? (char *) xmlMemSprintf("%.*s", MAX_BUFFER, name) : "",
            (char *) publicId ? (char *) xmlMemSprintf("%.*s", MAX_BUFFER, publicId) : "",
            (char *) systemId ? (char *) xmlMemSprintf("%.*s", MAX_BUFFER, systemId) : "");
}