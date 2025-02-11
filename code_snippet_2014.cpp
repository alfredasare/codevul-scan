#include <libxml/parserInternals.h>
#include <libxml/xmlIO.h>

static xmlParserCtxtPtr context = NULL;

CURLcode Curl_nss_connect_nonblocking(struct connectdata *conn,
                                      int sockindex, bool *done)
{
  xmlSubstituteEntitiesDefault(1);
  xmlKeepBlanksDefault(0);

  context = xmlCreatePushParserCtxt(&error_handler, NULL, "", 0, NULL);

  if (context == NULL) {
    *done = TRUE;
    return CURLE_OUT_OF_MEMORY;
  }

  // Assuming xmlString is an input string containing XML data.
  int result = xmlCtxtUseOptions(context, XML_PARSE_NOENT | XML_PARSE_NONET);

  if (result != 0) {
    *done = TRUE;
    xmlFreeParserCtxt(context);
    context = NULL;
    return CURLE_FAILED_INIT;
  }

  result = xmlParseDocument(context, (xmlChar *)xmlString);

  if (result != 0) {
    *done = TRUE;
    xmlFreeParserCtxt(context);
    context = NULL;
    return CURLE_FAILED_INIT;
  }

  *done = TRUE;
  xmlFreeParserCtxt(context);
  context = NULL;
  return CURLE_OK;
}