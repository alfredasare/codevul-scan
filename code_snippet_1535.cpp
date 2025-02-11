#include <libxml/parserInternals.h>

xmlCtxtPtr xmlCtxtReadFile(xmlParserCtxtPtr ctxt, const char *filename,
                           const char *encoding, int options)
{
    xmlParserInputPtr stream;

    if (filename == NULL)
        return (NULL);
    if (ctxt == NULL)
        return (NULL);

    xmlInitParser();

    xmlCtxtReset(ctxt);

    stream = xmlLoadExternalEntity(filename, NULL, ctxt);
    if (stream == NULL) {
        return (NULL);
    }

    inputPush(ctxt, stream);

    // Disable DTD processing to prevent external entity references
    ctxt->sax2.externalSubset = NULL;

    return (xmlDoRead(ctxt, NULL, encoding, options | XML_PARSE_NOENT | XML_PARSE_NSCLEAN | XML_PARSE_NONET, 1));
}