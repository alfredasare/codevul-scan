raptor_libxml_unparsedEntityDecl(void* user_data, const xmlChar *name,
                             const xmlChar *publicId, const xmlChar *systemId,
                             const xmlChar *notationName) {
  raptor_sax2* sax2 = (raptor_sax2*)user_data;
  libxml2_parserCtxt* ctxt = sax2->xc;
  
  // Disable DTD processing
  libxml2_parserCtxtSetParam(ctxt, XML_PARSE_NOENT, 0);
  libxml2_parserCtxtSetParam(ctxt, XML_PARSE_NODTD, 1);
  
  libxml2_unparsedEntityDecl(ctxt, name, publicId, systemId, notationName);
}